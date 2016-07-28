package PageGuest;

import QueueHandlers.JMSPublisher;
import Util.StringHelper;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

import javax.jms.JMSException;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URI;
import java.net.URISyntaxException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

import static Util.DatetimeHelper.ConvertFromWizzairJSONStoredFormat;

/**
 * Created by Andras on 09/06/2016.
 *
 * There are some given trip, e.g. CRL-BUD, HHN-SOF, ...
 * The goal: collect every available in- and outbound trip between the airports 6 month ahead. Store them in the database.
 * The algorithm has to update this database (delete trips, update trips, add trips).
 * The WizzAirPageGuest will search the prices.
 * Questions:
 * 1. Can this algorithm work paralel with the WizzAirPageGuest?
 * 2. How will I handle the different currencies?
 *
 */
public class WizzAirPageGuestV2 extends PageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuestV2.class);

	private boolean mThreadStopped = true;

	public WizzAirPageGuestV2( boolean dummy )
	{
		super( "wizzair" );
	}

	private JMSPublisher mPublisher;

	public WizzAirPageGuestV2()
	{
		super( "wizzair" );
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread(this);
		mThread.setName("WizzAirThread2 " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();

		mPublisher = new JMSPublisher( "FlightCollector" );
		try
		{
			mPublisher.Connect();
		}
		catch( JMSException e )
		{
			mPublisher = null;
			e.printStackTrace();
		}

		System.out.println("WizzAirPageGuestV2()");
	}

	/**
	 * This search methode ignore the departure-return date, but it uses a global config called LookAheadInterval.
	 * The searching always starts from now and collect all of the flights in the given
	 * interval between the two airports, like a return trip
	 * @param aFrom
	 * @param aTo
	 * @param aDepartureDate NOT USED
	 * @param aReturnDate    NOT USED
	 */
	public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate)
	{
		synchronized (mMutex)
		{
			TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
			lTravelDataInput.mAirline = getAirline();
			lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
			lTravelDataInput.mAirportCode_GoingTo = aTo;
			lTravelDataInput.mDepartureDay = "";
			lTravelDataInput.mReturnDay = "";
			lTravelDataInput.mAdultNumber = "1";
			lTravelDataInput.mChildNumber = "0";
			lTravelDataInput.mInfantNumber = "0";
			lTravelDataInput.mReturnTicket = true;
			mSearchQueue.add(lTravelDataInput);
		}
		System.out.println("DoSearch()");
	}

	/**
	 * This search methode uses a global config called LookAheadInterval.
	 * The searching always starts from now and collect all of the flights in the given
	 * interval between the two airports, like a return trip
	 */
	public void DoSearchFromConfig()
	{
		synchronized (mMutex)
		{
			ArrayList<TravelData_INPUT> lFlightList = Util.Configuration.getInstance().getFlightList();
			for (TravelData_INPUT lTDI : lFlightList)
			{
				if (!lTDI.mAirline.equals(getAirline()))
					continue;
				mSearchQueue.add(lTDI);
			}
		}
	}

	private TravelData_RESULT.TravelData_PossibleTrip ParseFlight( JSONObject lFlightOnADay )
	{
		TravelData_RESULT.TravelData_PossibleTrip lPossibleTrip = new TravelData_RESULT.TravelData_PossibleTrip();
		// CarrierCode
		// FlightNumber
		// STD: 8:45
		// STA: 10:40
		// ArrivalStationName: Budapest
		// DepartureStationName: Brüsszel Charleroi
		// IsMACStation
		// IsAirportChange
		lPossibleTrip.mDepartureDatetime = lFlightOnADay.getString( "STD" );
		lPossibleTrip.mArrivalDatetime = lFlightOnADay.getString( "STA" );
		return lPossibleTrip;
	}

	private TravelData_RESULT ParseTripList( JSONObject lTripsOnADay )
	{
		//ArrayList<TravelData_RESULT> lResultTrip = new ArrayList<TravelData_RESULT>();
		TravelData_RESULT lTrip = new TravelData_RESULT();
		lTrip.mAirline = getAirline();
		lTrip.mAirportCode_LeavingFrom = lTripsOnADay.getString( "DepartureStationCode" );
		lTrip.mAirportCode_GoingTo = lTripsOnADay.getString( "ArrivalStationCode" );
		String lMinimumPrice = lTripsOnADay.getString( "MinimumPrice" );

		JSONArray lFligths = lTripsOnADay.getJSONArray( "Flights" );
		for( int i = 0; i < lFligths.length(); i++ )
		{
			TravelData_RESULT.TravelData_PossibleTrip lFlight = ParseFlight( lFligths.getJSONObject( i ));
			lFlight.mDepartureDatetime =
					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mDepartureDatetime );
			lFlight.mArrivalDatetime =
					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mArrivalDatetime );
			lTrip.mTrips.add( lFlight );
		}
		return lTrip;
	}

	public void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException, JMSException
	{
		LocalDate lDate = LocalDate.now();
		int lYear = lDate.getYear();
		int lMonth = lDate.getMonthValue();

		for( int i = 0; i < 6; i++ )
		{
			ArrayList<TravelData_RESULT> lResultList = FillTheForm( aTravelDataInput, lYear, lMonth + i );
			SaveMonthlyFlights( lResultList );
			if( ++lMonth == 13 )
			{
				lMonth = 1;
				lYear++;
			}
		}
	}

	private ArrayList<TravelData_RESULT> FillTheForm( TravelData_INPUT aTravelDataInput, int aYear, int aMonth ) throws URISyntaxException, IOException
	{
		// String lUrl = "https://cdn.static.wizzair.com/hu-HU/TimeTableAjax?departureIATA=CRL&arrivalIATA=BUD&year=2016&month=8";
		String lUrl = "https://cdn.static.wizzair.com/hu-HU/TimeTableAjax?departureIATA="
				+ aTravelDataInput.mAirportCode_LeavingFrom
				+ "&arrivalIATA=" + aTravelDataInput.mAirportCode_GoingTo
				+ "year=" + aYear + "&month=" + aMonth;

		String lTestJsonString = "[{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.01.\",\"Date\":\"20160801\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.02.\",\"Date\":\"20160802\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.03.\",\"Date\":\"20160803\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"39,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.04.\",\"Date\":\"20160804\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.05.\",\"Date\":\"20160805\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.06.\",\"Date\":\"20160806\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.07.\",\"Date\":\"20160807\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.08.\",\"Date\":\"20160808\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.09.\",\"Date\":\"20160809\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.10.\",\"Date\":\"20160810\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.11.\",\"Date\":\"20160811\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.12.\",\"Date\":\"20160812\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"69,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.13.\",\"Date\":\"20160813\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.14.\",\"Date\":\"20160814\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.15.\",\"Date\":\"20160815\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.16.\",\"Date\":\"20160816\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.17.\",\"Date\":\"20160817\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.18.\",\"Date\":\"20160818\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.19.\",\"Date\":\"20160819\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.20.\",\"Date\":\"20160820\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.21.\",\"Date\":\"20160821\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.22.\",\"Date\":\"20160822\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.23.\",\"Date\":\"20160823\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.24.\",\"Date\":\"20160824\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.25.\",\"Date\":\"20160825\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.26.\",\"Date\":\"20160826\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"39,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.27.\",\"Date\":\"20160827\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.28.\",\"Date\":\"20160828\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.29.\",\"Date\":\"20160829\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.30.\",\"Date\":\"20160830\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.31.\",\"Date\":\"20160831\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"14,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.01.\",\"Date\":\"20160901\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.02.\",\"Date\":\"20160902\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.03.\",\"Date\":\"20160903\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.04.\",\"Date\":\"20160904\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"19,99 €\"}]";

		URI lURI = null;
		JSONTokener lTokener = null;
		//lURI = new URI( lUrl );
		//lTokener = new JSONTokener( lURI.toURL().openStream());
		lTokener = new JSONTokener(new ByteArrayInputStream( lTestJsonString.getBytes() ));
		//JSONObject root = new JSONObject( lTokener );
		JSONArray lRoot = new JSONArray( lTokener );

		ArrayList<TravelData_RESULT> lResultList = new ArrayList<TravelData_RESULT>();
		for( int lDateIndex = 0; lDateIndex < lRoot.length(); lDateIndex++ )
		{
			TravelData_RESULT lTDR = ParseTripList( lRoot.getJSONObject( lDateIndex ));
			lTDR.mTravelDataInput = aTravelDataInput;
			lResultList.add( lTDR );
		}

		return lResultList;
	}

	public void SaveMonthlyFlights( ArrayList<TravelData_RESULT> aResultList ) throws JMSException
	{
		// todo Send everything to the activemq
//		mTravelDataResult = new TravelData_RESULT();
//		mTravelDataResult.mAirline = aTravelDataInput.mAirline;
//		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
//		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
//		mTravelDataResult.mTravelDataInput = aTravelDataInput;
//
//		for( int lTripIndex = 0; lTripIndex < lTrips.length(); lTripIndex++ )
//		{
//			ParseTrip( lTrips.getJSONObject( lTripIndex ), lCurrency );
//		}
//		ResultQueue.getInstance().push( mTravelDataResult );

		for( TravelData_RESULT lResult : aResultList )
		{
			mPublisher.Publish( lResult );
		}
	}

	public void stop()
	{
		mThreadStopped = true;
		try
		{
			mThread.join();
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
		}
		System.out.println("stop()");
	}

	public void run()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		try
		{
			System.out.println("Thread::run");

			mThreadStopped = false;
			while (!mThreadStopped)
			{
				int lSearQueueSize;
				synchronized (mMutex)
				{
					lSearQueueSize = mSearchQueue.size();
				}

				if ( lSearQueueSize == 0 )
				{
					Sleep(100);
					continue;
				}

				TravelData_INPUT lTravelDataInput = null;
				synchronized (mMutex)
				{
					lTravelDataInput = mSearchQueue.remove(0);
				}

				try
				{
					FillTheForm( lTravelDataInput );
				}
				catch( URISyntaxException e )
				{
				}
				catch( IOException e )
				{

				}

				String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
				Sleep( 1000 * Integer.parseInt( lSleep ));
			}
			System.out.println("run()");
		}
		catch( Exception aException )
		{
			mLogger.error( StringHelper.getTraceInformation( aException ) );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	// https://cdn.static.wizzair.com/hu-HU/TimeTableAjax?departureIATA=CRL&arrivalIATA=BUD&year=2016&month=8
}

/* Answer
[{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.01.","Date":"20160801","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"29,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.02.","Date":"20160802","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"29,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.03.","Date":"20160803","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"39,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.04.","Date":"20160804","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"49,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.05.","Date":"20160805","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"49,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.06.","Date":"20160806","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"29,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.07.","Date":"20160807","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"49,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.08.","Date":"20160808","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"59,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.09.","Date":"20160809","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"59,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.10.","Date":"20160810","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"59,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.11.","Date":"20160811","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"59,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.12.","Date":"20160812","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"69,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.13.","Date":"20160813","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"49,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.14.","Date":"20160814","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"24,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.15.","Date":"20160815","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"19,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.16.","Date":"20160816","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.17.","Date":"20160817","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"19,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.18.","Date":"20160818","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"24,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.19.","Date":"20160819","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"19,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.20.","Date":"20160820","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.21.","Date":"20160821","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.22.","Date":"20160822","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.23.","Date":"20160823","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.24.","Date":"20160824","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.25.","Date":"20160825","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.26.","Date":"20160826","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"39,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.27.","Date":"20160827","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.28.","Date":"20160828","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"19,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.29.","Date":"20160829","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.30.","Date":"20160830","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"9,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.08.31.","Date":"20160831","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"True","MinimumPrice":"14,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.09.01.","Date":"20160901","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"False","MinimumPrice":"24,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.09.02.","Date":"20160902","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"False","MinimumPrice":"29,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.09.03.","Date":"20160903","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"False","MinimumPrice":"19,99 €"},{"ArrivalStationCode":"BUD","CurrentDate":"2016.09.04.","Date":"20160904","DepartureStationCode":"CRL","Flights":[{"CarrierCode":"W6","FlightNumber":"2282","STD":"8:45","STA":"10:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"},{"CarrierCode":"W6","FlightNumber":"2284","STD":"20:45","STA":"22:40","ArrivalStationName":"Budapest","DepartureStationName":"Brüsszel Charleroi","IsMACStation":"True","IsAirportChange":"False"}],"HasSelection":"True","InMonth":"False","MinimumPrice":"19,99 €"}]
*/