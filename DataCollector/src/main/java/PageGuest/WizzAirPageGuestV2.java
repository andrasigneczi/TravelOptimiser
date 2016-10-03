package PageGuest;

import QueueHandlers.JMSPublisher;
import QueueHandlers.LocalStack;
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
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

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

	public WizzAirPageGuestV2()
	{
		super( "wizzair" );
		mSearchQueue = new LocalStack<TravelData_INPUT>();
		mThread = new Thread(this);
		mThread.setName("WizzAirThread2 " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();
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
			mSearchQueue.push(lTravelDataInput);
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
				mSearchQueue.push(lTDI);
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

	private TravelData_RESULT ParseTripList( JSONObject lTripsOnADay, ResultFilter aFilter, boolean aOutbound )
	{
		//ArrayList<TravelData_RESULT> lResultTrip = new ArrayList<TravelData_RESULT>();
		TravelData_RESULT lTrip = new TravelData_RESULT();
		lTrip.mAirline = getAirline();
		lTrip.mAirportCode_LeavingFrom = lTripsOnADay.getString( "DepartureStationCode" );
		lTrip.mAirportCode_GoingTo = lTripsOnADay.getString( "ArrivalStationCode" );
		Object lMinimumPrice = lTripsOnADay.get( "MinimumPrice" );

		JSONArray lFligths = lTripsOnADay.getJSONArray( "Flights" );
		for( int i = 0; i < lFligths.length(); i++ )
		{
			TravelData_RESULT.TravelData_PossibleTrip lFlight = ParseFlight( lFligths.getJSONObject( i ));
			lFlight.mDepartureDatetime =
					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mDepartureDatetime );
			lFlight.mArrivalDatetime =
					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mArrivalDatetime );

			if( aFilter != null )
			{
				if( !aFilter.testADay( lFlight.mDepartureDatetime.substring( 0, 8 ), aOutbound ))
					continue;
			}

			lTrip.mTrips.add( lFlight );
		}
		return lTrip;
	}

	public void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException, JMSException,
			CloneNotSupportedException
	{
		LocalDate lDate = LocalDate.now();
		int lYear = lDate.getYear();
		int lMonth = lDate.getMonthValue();
		String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		ArrayList<TravelData_RESULT> lResultList = new ArrayList<TravelData_RESULT>();

		// 6 month ahead
		for( int i = 0; i < 6; i++ )
		{
			FillTheForm( aTravelDataInput, lYear, lMonth, lResultList, true );
			if( ++lMonth == 13 )
			{
				lMonth = 1;
				lYear++;
			}
			Sleep( 1000 * Integer.parseInt( lSleep ));
		}

		// Return way
		lYear = lDate.getYear();
		lMonth = lDate.getMonthValue();
		TravelData_INPUT lTravelDataInput = (TravelData_INPUT)aTravelDataInput.clone();
		lTravelDataInput.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_LeavingFrom;
		lTravelDataInput.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_GoingTo;

		for( int i = 0; i < 6; i++ )
		{
			FillTheForm( lTravelDataInput, lYear, lMonth, lResultList, false );
			if( ++lMonth == 13 )
			{
				lMonth = 1;
				lYear++;
			}
			Sleep( 1000 * Integer.parseInt( lSleep ));
		}

		SaveMonthlyFlights( lResultList );
	}

	private void FillTheForm( TravelData_INPUT aTravelDataInput, int aYear, int aMonth, ArrayList<TravelData_RESULT> aResultList, boolean aOutbound ) throws URISyntaxException, IOException
	{
		// String lUrl = "https://cdn.static.wizzair.com/hu-HU/TimeTableAjax?departureIATA=CRL&arrivalIATA=BUD&year=2016&month=8";
		String lUrl = "https://cdn.static.wizzair.com/hu-HU/TimeTableAjax?departureIATA="
				+ aTravelDataInput.mAirportCode_LeavingFrom
				+ "&arrivalIATA=" + aTravelDataInput.mAirportCode_GoingTo
				+ "&year=" + aYear + "&month=" + aMonth;

		//String lTestJsonString = "[{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.01.\",\"Date\":\"20160801\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.02.\",\"Date\":\"20160802\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.03.\",\"Date\":\"20160803\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"39,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.04.\",\"Date\":\"20160804\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.05.\",\"Date\":\"20160805\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.06.\",\"Date\":\"20160806\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.07.\",\"Date\":\"20160807\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.08.\",\"Date\":\"20160808\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.09.\",\"Date\":\"20160809\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.10.\",\"Date\":\"20160810\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.11.\",\"Date\":\"20160811\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"59,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.12.\",\"Date\":\"20160812\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"69,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.13.\",\"Date\":\"20160813\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"49,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.14.\",\"Date\":\"20160814\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.15.\",\"Date\":\"20160815\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.16.\",\"Date\":\"20160816\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.17.\",\"Date\":\"20160817\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.18.\",\"Date\":\"20160818\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.19.\",\"Date\":\"20160819\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.20.\",\"Date\":\"20160820\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.21.\",\"Date\":\"20160821\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.22.\",\"Date\":\"20160822\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.23.\",\"Date\":\"20160823\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.24.\",\"Date\":\"20160824\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.25.\",\"Date\":\"20160825\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.26.\",\"Date\":\"20160826\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"39,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.27.\",\"Date\":\"20160827\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.28.\",\"Date\":\"20160828\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.29.\",\"Date\":\"20160829\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.30.\",\"Date\":\"20160830\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"9,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.08.31.\",\"Date\":\"20160831\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"True\",\"MinimumPrice\":\"14,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.01.\",\"Date\":\"20160901\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"24,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.02.\",\"Date\":\"20160902\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"29,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.03.\",\"Date\":\"20160903\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"19,99 €\"},{\"ArrivalStationCode\":\"BUD\",\"CurrentDate\":\"2016.09.04.\",\"Date\":\"20160904\",\"DepartureStationCode\":\"CRL\",\"Flights\":[{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2282\",\"STD\":\"8:45\",\"STA\":\"10:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"},{\"CarrierCode\":\"W6\",\"FlightNumber\":\"2284\",\"STD\":\"20:45\",\"STA\":\"22:40\",\"ArrivalStationName\":\"Budapest\",\"DepartureStationName\":\"Brüsszel Charleroi\",\"IsMACStation\":\"True\",\"IsAirportChange\":\"False\"}],\"HasSelection\":\"True\",\"InMonth\":\"False\",\"MinimumPrice\":\"19,99 €\"}]";

		URI lURI = null;
		JSONTokener lTokener = null;
		lURI = new URI( lUrl );
		lTokener = new JSONTokener( lURI.toURL().openStream());
		//lTokener = new JSONTokener(new ByteArrayInputStream( lTestJsonString.getBytes() ));
		//JSONObject root = new JSONObject( lTokener );
		JSONArray lRoot = new JSONArray( lTokener );

		for( int lDateIndex = 0; lDateIndex < lRoot.length(); lDateIndex++ )
		{
			TravelData_RESULT lTDR = ParseTripList( lRoot.getJSONObject( lDateIndex ), aTravelDataInput.mFilter, aOutbound );
			lTDR.mTravelDataInput = aTravelDataInput;
			aResultList.add( lTDR );
		}
	}

	/**
	 * Prepare an inputlist from the resultlist. This list will be inserted into the ActiveMQ.
	 * @param aResultList
	 * @return prepared input list
	 * @throws JMSException
	 */
	private ArrayList<TravelData_INPUT> PrepareInputList( ArrayList<TravelData_RESULT> aResultList ) throws JMSException
	{
		TravelData_INPUT lTravelData_input = null;
		ArrayList<TravelData_INPUT> lTravelDataInputs = new ArrayList<TravelData_INPUT>();

		for( TravelData_RESULT lResult : aResultList )
		{
			boolean lAirportChanged = false;
			if( lTravelData_input == null )
			{
				lTravelData_input                          = new TravelData_INPUT();
				lTravelData_input.mAirline                 = lResult.mAirline;
				lTravelData_input.mAirportCode_LeavingFrom = lResult.mAirportCode_LeavingFrom;
				lTravelData_input.mAirportCode_GoingTo     = lResult.mAirportCode_GoingTo;
				lTravelData_input.mReturnTicket            = false;
				lTravelData_input.mDepartureDay            = "";
			}
			else
			{
				lAirportChanged = !lTravelData_input.mAirportCode_LeavingFrom.equals( lResult.mAirportCode_LeavingFrom );
				lAirportChanged |= !lTravelData_input.mAirportCode_GoingTo.equals( lResult.mAirportCode_GoingTo );
			}

			for( TravelData_RESULT.TravelData_PossibleTrip lTrip : lResult.mTrips )
			{
				String lDepartureDay = lTrip.mDepartureDatetime.substring( 0, 10 ).replace( "-", "." ) + ".";
				//String lArrivalDay   = lTrip.mArrivalDatetime.substring( 0, 10 ).replace( "-", "." ) + ".";

				boolean lDepartureChanged = !lTravelData_input.mDepartureDay.equals( lDepartureDay );
				if( !lDepartureChanged && !lAirportChanged )
					continue;

				if( lDepartureChanged )
					lTravelData_input.mDepartureDay = lDepartureDay;

				if( lAirportChanged )
				{
					lTravelData_input.mAirportCode_LeavingFrom = lResult.mAirportCode_LeavingFrom;
					lTravelData_input.mAirportCode_GoingTo = lResult.mAirportCode_GoingTo;
					lAirportChanged = false;
				}

				try
				{
					TravelData_INPUT lTravelData_input_clone = (TravelData_INPUT)lTravelData_input.clone();
//					System.out.println( "collect: " + lTravelData_input_clone.mAirportCode_LeavingFrom
//							+ "->"
//							+ lTravelData_input_clone.mAirportCode_GoingTo
//							+ ": "
//							+ lTravelData_input_clone.mDepartureDay );
					lTravelDataInputs.add( lTravelData_input_clone );
				}
				catch( CloneNotSupportedException e )
				{
					mLogger.error( StringHelper.getTraceInformation( e ) );
				}
			}
		}
		return lTravelDataInputs;
	}

	/**
	 * Convert all the trips into TravelData_INPUT and send them to the ActiveMQ
	 * @param aResultList
	 * @throws JMSException
	 */
	public void SaveMonthlyFlights( ArrayList<TravelData_RESULT> aResultList ) throws JMSException
	{
		ArrayList<TravelData_INPUT> lTravelDataInputs = PrepareInputList( aResultList );

		ArrayList<TravelData_INPUT> lReturnTrips = CreateReturnTrips( lTravelDataInputs );

		JMSPublisher lPublisher = new JMSPublisher( "Wizzair" );
		try
		{
			lPublisher.Connect();
			for( TravelData_INPUT lTrip : lReturnTrips )
				lPublisher.Publish( lTrip );
		}
		catch( JMSException e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
		finally
		{
			lPublisher.Disconnect();
		}
	}

	ArrayList<TravelData_INPUT> CreateReturnTrips( ArrayList<TravelData_INPUT> lTravelDataInputs )
	{
		// előkészítés
		// 1. rendezés departureday szerint
		// 2. egyforma utak eltávolítása
		// return utak előállítása
		// 3. kiveszem a legelsőt a listából.
		// 4. keresek egy visszafelé utat a kivett elemhez.
		// 5. a) ha találok, akkor kiveszem, és összeállítom a return utat. Ugrás a 3-ra
		// 5. b) ha nem találok, akkor ony way tripkémt tárolom el az outbound utat. Ugrás a 3-ra

		// 1. rendezés departureday szerint
		TravelData_INPUT lTempReference = null;
		List<TravelData_INPUT> lSortedTDI = lTravelDataInputs.stream()
			.sorted( (s1, s2) ->
			{
				int lEquality = s1.mDepartureDay.compareTo( s2.mDepartureDay );
				if( lEquality != 0 )
					return lEquality;

				return ( s1.mAirportCode_LeavingFrom + "->" + s1.mAirportCode_GoingTo )
						.compareTo( s2.mAirportCode_LeavingFrom + "->" + s2.mAirportCode_GoingTo );
			} )
			.collect( Collectors.toList());

		// 2. egyforma utak eltávolítása
		List<TravelData_INPUT> lFilteredTDI = new ArrayList<>();
		for( TravelData_INPUT lTDI : lSortedTDI )
		{

			if( lTempReference != null )
			{
				String lS1 = lTDI.mAirportCode_LeavingFrom + "->" + lTDI.mAirportCode_GoingTo + ": " + lTDI.mDepartureDay;
				String lS2 = lTempReference.mAirportCode_LeavingFrom + "->" + lTempReference.mAirportCode_GoingTo
						+ ": " + lTempReference.mDepartureDay;
				if( lS1.equals( lS2 ))
					continue;
			}
			lTempReference = lTDI;
			lFilteredTDI.add( lTDI );
		}

		// return utak előállítása
		ArrayList<TravelData_INPUT> lComposedTrips = new ArrayList<TravelData_INPUT>();
		DateTimeFormatter lFormatter = DateTimeFormatter.ofPattern( "yyyy.MM.dd." );
		while( lFilteredTDI.size() > 0 )
		{
			// 3. kiveszem a legelsőt a listából.
			TravelData_INPUT lFirstItem = lFilteredTDI.remove( 0 );

			for( int i = 0; i < lFilteredTDI.size(); i++ )
			{
				TravelData_INPUT lReturnTrip = lFilteredTDI.get( i );
				if( !lReturnTrip.mAirportCode_LeavingFrom.equals( lFirstItem.mAirportCode_GoingTo ))
					continue;
				if( !lReturnTrip.mAirportCode_GoingTo.equals( lFirstItem.mAirportCode_LeavingFrom ))
					continue;
				// A visszafelé út a következő nap vagy később legyen
				LocalDate lDepartureDayFI = LocalDate.parse( lFirstItem.mDepartureDay, lFormatter );
				LocalDate lDepartureDayRT = LocalDate.parse( lReturnTrip.mDepartureDay, lFormatter );

				if( lDepartureDayRT.isAfter( lDepartureDayFI ) )
				{
					lFilteredTDI.remove( i );
					lFirstItem.mReturnDay = lReturnTrip.mDepartureDay;
					lFirstItem.mReturnTicket = true;
					lComposedTrips.add( lFirstItem );
					lFirstItem = null;
					break;
				}
			}

			if( lFirstItem != null )
			{
				// The is no return trip, so we put a one way trip
				lComposedTrips.add( lFirstItem );
			}
		}
		return lComposedTrips;
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
			mLogger.error( StringHelper.getTraceInformation( e ) );
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
					lSearQueueSize = mSearchQueue.isEmpty();
				}

				if ( lSearQueueSize == 0 )
				{
					Sleep(100);
					continue;
				}

				TravelData_INPUT lTravelDataInput = null;
				synchronized (mMutex)
				{
					lTravelDataInput = mSearchQueue.pop();
				}

				try
				{
					FillTheForm( lTravelDataInput );
				}
				catch( URISyntaxException e )
				{
					mLogger.error( StringHelper.getTraceInformation( e ));
				}
				catch( IOException e )
				{
					mLogger.error( StringHelper.getTraceInformation( e ));
				}

				//String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
				//Sleep( 1000 * Integer.parseInt( lSleep ));
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