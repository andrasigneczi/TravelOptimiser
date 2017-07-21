package PageGuest;

import Configuration.Configuration;
import QueueHandlers.JMSPublisher;
import QueueHandlers.LocalStack;
import ResultFilter.ResultFilter;
import Util.HttpRequest;
import Util.StringHelper;
import Util.WizzairHelper;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import javax.jms.JMSException;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.charset.Charset;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import static Util.CurrencyHelper.ConvertFrom3Digits;

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
public class WizzAirPageGuestTimetable extends PageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzAirPageGuestTimetable.class);

	private long mTimeoutStart;
	private static String mApiTimetableUrl = "https://be.wizzair.com/5.1.4/Api/search/timetable";

	public WizzAirPageGuestTimetable( boolean dummy )
	{
		super( "wizzair" );
		if( dummy )
		{
			mThread = new Thread(this);
			mThread.setName("WizzAirTimetableThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		}
	}

	public static void InitApirURL() throws Exception
	{
		String lApiVersion = WizzairHelper.getApiVersion();
		if( lApiVersion.length() == 0 )
			throw new RuntimeException( "Wrong API version!" );

		mApiTimetableUrl = "https://be.wizzair.com/" + lApiVersion + "/Api/search/timetable";
	}

	public WizzAirPageGuestTimetable()
	{
		super( "wizzair" );
		mSearchQueue = new LocalStack<>();
		mThread = new Thread(this);
		mThread.setName("WizzAirTimetableThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();
		System.out.println("WizzAirPageGuestTimetable()");
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
			ArrayList<TravelData_INPUT> lFlightList = Configuration.getInstance().getFlightList();
			for (TravelData_INPUT lTDI : lFlightList)
			{
				if (!lTDI.mAirline.equals(getAirline()))
					continue;
				mSearchQueue.push(lTDI);
			}
		}
	}

//	private TravelData_RESULT.TravelData_PossibleTrip ParseFlight( JSONObject lFlightOnADay )
//	{
//		TravelData_RESULT.TravelData_PossibleTrip lPossibleTrip = new TravelData_RESULT.TravelData_PossibleTrip();
//		// CarrierCode
//		// FlightNumber
//		// STD: 8:45
//		// STA: 10:40
//		// ArrivalStationName: Budapest
//		// DepartureStationName: Brüsszel Charleroi
//		// IsMACStation
//		// IsAirportChange
//		lPossibleTrip.mDepartureDatetime = lFlightOnADay.getString( "STD" );
//		lPossibleTrip.mArrivalDatetime = lFlightOnADay.getString( "STA" );
//		return lPossibleTrip;
//	}
//
//	private TravelData_RESULT ParseTripList( JSONObject lTripsOnADay, ArrayList<ResultFilter> aFilters, boolean aOutbound )
//	{
//		//ArrayList<TravelData_RESULT> lResultTrip = new ArrayList<TravelData_RESULT>();
//		TravelData_RESULT lTrip = new TravelData_RESULT();
//		lTrip.mAirline = getAirline();
//		lTrip.mAirportCode_LeavingFrom = lTripsOnADay.getString( "DepartureStationCode" );
//		lTrip.mAirportCode_GoingTo = lTripsOnADay.getString( "ArrivalStationCode" );
//		Object lMinimumPrice = lTripsOnADay.get( "MinimumPrice" );
//
//		JSONArray lFligths = lTripsOnADay.getJSONArray( "Flights" );
//		for( int i = 0; i < lFligths.length(); i++ )
//		{
//			TravelData_RESULT.TravelData_PossibleTrip lFlight = ParseFlight( lFligths.getJSONObject( i ));
//			lFlight.mDepartureDatetime =
//					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mDepartureDatetime );
//			lFlight.mArrivalDatetime =
//					ConvertFromWizzairJSONStoredFormat( lTripsOnADay.getString( "Date" ) + " " +  lFlight.mArrivalDatetime );
//
//			if( aFilters != null && aFilters.size() > 0 )
//			{
//				String lDepartureDay = lFlight.mDepartureDatetime.substring( 0, 10 );
//				boolean lTestFailed = false;
//				for( ResultFilter aFilter : aFilters )
//				{
//					if( !aFilter.testADay( lDepartureDay, aOutbound ) )
//					{
//						lTestFailed = true;
//						break;
//					}
//				}
//				if( lTestFailed )
//					continue;
//			}
//
//			lTrip.mTrips.add( lFlight );
//		}
//		return lTrip;
//	}

	public void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException, JMSException,
			CloneNotSupportedException
	{
		LocalDate lDate = LocalDate.now();
		int lYear = lDate.getYear();
		int lMonth = lDate.getMonthValue();
		int lDay = lDate.getDayOfMonth();
		String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		ArrayList<TravelData_RESULT> lResultList = new ArrayList<TravelData_RESULT>();

		final int lInterval = StringHelper.parseInt( aTravelDataInput.mInterval, 6 );

		// 6 month ahead
		for( int i = 0; i < lInterval; i++ )
		{
			FillTheForm( aTravelDataInput, lYear, lMonth, lDay, lResultList );
			if( ++lMonth == 13 )
			{
				lMonth = 1;
				lYear++;
			}
			Sleep( 1000 * Integer.parseInt( lSleep ));
		}

		// Return way
//		lYear = lDate.getYear();
//		lMonth = lDate.getMonthValue();
//		TravelData_INPUT lTravelDataInput = (TravelData_INPUT)aTravelDataInput.clone();
//		lTravelDataInput.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_LeavingFrom;
//		lTravelDataInput.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_GoingTo;
//
//		for( int i = 0; i < lInterval; i++ )
//		{
//			FillTheForm( lTravelDataInput, lYear, lMonth, lDay, lResultList, false );
//			if( ++lMonth == 13 )
//			{
//				lMonth = 1;
//				lYear++;
//			}
//			Sleep( 1000 * Integer.parseInt( lSleep ));
//		}

		SaveMonthlyFlights( lResultList );
	}

	private String ParsePrice( JSONObject aPrice )
	{
		mLogger.trace( "begin, thread name: " + getThreadName() );
		Double lAmount = aPrice.getDouble( "amount" );
		String lCurrency = ConvertFrom3Digits( aPrice.getString( "currencyCode" ));
		mLogger.trace( "end, thread name: " + getThreadName());
		return lAmount + " " + lCurrency;
	}

	private void ParseDepartureDates( JSONArray aDates, String lDepartureStation, String lArrivalStation, boolean aOutbound, ArrayList<TravelData_RESULT> aResultList, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "begin, thread name: " + getThreadName() );
		ArrayList<ResultFilter> aFilters = aTravelDataInput.mFilters;
		for( int lDateIndex = 0; lDateIndex < aDates.length(); lDateIndex++ )
		{
			TravelData_RESULT lTDR = new TravelData_RESULT();
			lTDR.mAirline = getAirline();
			lTDR.mAirportCode_LeavingFrom = lDepartureStation;
			lTDR.mAirportCode_GoingTo = lArrivalStation;

			lTDR.mTravelDataInput = aTravelDataInput;

			TravelData_RESULT.TravelData_PossibleTrip lPossibleTrip = new TravelData_RESULT.TravelData_PossibleTrip();
			String date = aDates.get( lDateIndex ).toString();
			lPossibleTrip.mDepartureDatetime = date.substring( 0, 16 );


			if( aFilters != null && aFilters.size() > 0 )
			{
				String lDepartureDay = lPossibleTrip.mDepartureDatetime.substring( 0, 10 );
				boolean lTestFailed = false;
				for( ResultFilter aFilter : aFilters )
				{
					if( !aFilter.testADay( lDepartureDay, aOutbound ) )
					{
						lTestFailed = true;
						break;
					}
				}
				if( lTestFailed )
					continue;
			}

			lTDR.mTrips.add( lPossibleTrip );
			aResultList.add( lTDR );

		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void ParseFlights( JSONArray aFlights, boolean aOutbound, ArrayList<TravelData_RESULT> aResultList, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		for( int lTripIndex = 0; lTripIndex < aFlights.length(); lTripIndex++ )
		{
			JSONObject lJSONTrip = aFlights.getJSONObject( lTripIndex );
			//lTripClone.mDepartureDatetime = lJSONTrip.getString( "departureDate" );
			String lDepartureStation = lJSONTrip.getString( "departureStation" );
			String lArrivalStation = lJSONTrip.getString( "arrivalStation" );

			// the price sometimes null, moreover I don't use it
			//JSONObject lPrice = lJSONTrip.getJSONObject( "price" );
			//String lFormattedPrice = ParsePrice( lPrice );

			// {"outboundFlights":[{"departureStation":"","arrivalStation":"","departureDate":"2017-07-09T00:00:00","price":null,"priceType":"soldOut","departureDates":["2017-07-09T08:25:00"],"classOfService":null,"hasMacFlight":false},{"departureStation":"","arrivalStation":"","departureDate":"2017-07-11T00:00:00","price":null,"priceType":"soldOut","departureDates":["2017-07-11T08:50:00"],"classOfService":null,"hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-13T00:00:00","price":{"amount":209.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-13T08:50:00"],"classOfService":"D","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-15T00:00:00","price":{"amount":239.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-15T08:50:00"],"classOfService":"C","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-16T00:00:00","price":{"amount":179.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-16T08:25:00"],"classOfService":"E","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-18T00:00:00","price":{"amount":149.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-18T08:50:00"],"classOfService":"F","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-20T00:00:00","price":{"amount":129.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-20T08:50:00"],"classOfService":"G","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-22T00:00:00","price":{"amount":179.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-22T09:40:00"],"classOfService":"E","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-23T00:00:00","price":{"amount":119.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-23T08:25:00"],"classOfService":"GH","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-25T00:00:00","price":{"amount":109.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-25T09:40:00"],"classOfService":"H","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-27T00:00:00","price":{"amount":129.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-27T08:50:00"],"classOfService":"G","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-29T00:00:00","price":{"amount":119.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-29T09:40:00"],"classOfService":"GH","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-07-30T00:00:00","price":{"amount":119.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-30T08:25:00"],"classOfService":"GH","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-08-01T00:00:00","price":{"amount":79.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-01T09:40:00"],"classOfService":"IJ","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-08-03T00:00:00","price":{"amount":44.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-03T08:50:00"],"classOfService":"LB","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-08-05T00:00:00","price":{"amount":59.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-05T09:40:00"],"classOfService":"K","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-08-06T00:00:00","price":{"amount":34.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-06T08:25:00"],"classOfService":"BO","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"SOF","departureDate":"2017-08-08T00:00:00","price":{"amount":27.49,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-08T09:40:00"],"classOfService":"OP","hasMacFlight":false}],"returnFlights":[{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-11T00:00:00","price":{"amount":39.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-11T06:25:00"],"classOfService":"B","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-13T00:00:00","price":{"amount":9.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-13T06:25:00"],"classOfService":"Z","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-15T00:00:00","price":{"amount":9.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-15T06:25:00"],"classOfService":"Z","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-16T00:00:00","price":{"amount":17.49,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-16T06:00:00"],"classOfService":"RS","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-18T00:00:00","price":{"amount":9.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-18T06:25:00"],"classOfService":"Z","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-20T00:00:00","price":{"amount":14.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-20T06:25:00"],"classOfService":"S","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-22T00:00:00","price":{"amount":19.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-22T07:15:00"],"classOfService":"R","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-23T00:00:00","price":{"amount":22.49,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-23T06:00:00"],"classOfService":"PR","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-25T00:00:00","price":{"amount":14.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-25T07:15:00"],"classOfService":"S","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-27T00:00:00","price":{"amount":19.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-27T06:25:00"],"classOfService":"R","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-29T00:00:00","price":{"amount":44.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-29T07:15:00"],"classOfService":"LB","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-07-30T00:00:00","price":{"amount":54.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-07-30T06:00:00"],"classOfService":"KL","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-08-01T00:00:00","price":{"amount":22.49,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-01T07:15:00"],"classOfService":"PR","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-08-03T00:00:00","price":{"amount":44.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-03T06:25:00"],"classOfService":"LB","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-08-05T00:00:00","price":{"amount":44.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-05T07:15:00"],"classOfService":"LB","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-08-06T00:00:00","price":{"amount":54.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-06T06:00:00"],"classOfService":"KL","hasMacFlight":false},{"departureStation":"SOF","arrivalStation":"CRL","departureDate":"2017-08-08T00:00:00","price":{"amount":64.99,"currencyCode":"EUR"},"priceType":"price","departureDates":["2017-08-08T07:15:00"],"classOfService":"JK","hasMacFlight":false}]}


			JSONArray lDepartureDates = lJSONTrip.getJSONArray( "departureDates" );
			ParseDepartureDates( lDepartureDates, lDepartureStation, lArrivalStation, aOutbound, aResultList, aTravelDataInput );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	public  void ParseTheResponse( String aResponse, ArrayList<TravelData_RESULT> aResultList, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream( ("[" + aResponse + "]").getBytes(
				Charset.forName("UTF-8") ) );
		JSONTokener lTokener = new JSONTokener( byteArrayInputStream );
		JSONArray lRoot = new JSONArray( lTokener );

		for( int lDateIndex = 0; lDateIndex < lRoot.length(); lDateIndex++ )
		{
			try
			{
				JSONObject jobj = lRoot.getJSONObject( lDateIndex );
				JSONArray returnFlights = null;
				Object returnFlightsObject = jobj.get( "returnFlights" );
				if( returnFlightsObject != null && returnFlightsObject instanceof JSONArray )
					returnFlights = (JSONArray)returnFlightsObject;

				//JSONArray outboundBundles = jobj.getJSONArray( "outboundBundles" );
				//JSONArray returnBundles = jobj.getJSONArray( "returnBundles" );
				if( !jobj.isNull( "outboundFlights" ))
				{
					JSONArray outboundFlights = jobj.getJSONArray( "outboundFlights" );
					ParseFlights( outboundFlights, true, aResultList, aTravelDataInput );
				}

				if( returnFlights != null )
					ParseFlights( returnFlights, false, aResultList, aTravelDataInput );
			}
			catch (JSONException e)
			{
				mLogger.error( "Exception in ParseTheResponse: " + StringHelper.getTraceInformation( e ) );
				mLogger.error( "Response string: " + aResponse );
			}
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void FillTheForm( TravelData_INPUT aTravelDataInput, int aYear, int aMonth, int aDay, ArrayList<TravelData_RESULT> aResultList ) throws URISyntaxException, IOException
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		// JSON post
		// https://be.wizzair.com/5.1.4/Api/search/timetable
		// request payload: {"flightList":[{"departureStation":"HHN","arrivalStation":"BUD","from":"2017-06-03","to":"2017-07-02"},{"departureStation":"BUD","arrivalStation":"HHN","from":"2017-06-26","to":"2017-08-06"}],"priceType":"regular"}
		// request payload: {"flightList":[{"departureStation":"GYD","arrivalStation":"BUD","from":"2017-06-05","to":"2017-07-02"},{"departureStation":"BUD","arrivalStation":"GYD","from":"2017-06-26","to":"2017-08-06"}],"priceType":"wdc"}
		// request payload: {"flightList":[{"departureStation":"BUD","arrivalStation":"CRL","from":"2017-06-06","to":"2017-07-02"},{"departureStation":"CRL","arrivalStation":"BUD","from":"2017-06-26","to":"2017-08-06"}],"priceType":"regular"}

		// https://be.wizzair.com/6.1.0/Api/search/timetable
		// {"flightList":[{"departureStation":"BUD","arrivalStation":"CRL","from":"2017-07-13","to":"2017-08-06"},{"departureStation":"CRL","arrivalStation":"BUD","from":"2017-07-31","to":"2017-09-03"}],"priceType":"wdc"}
		// {"outboundFlights":[{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-14T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-14T06:15:00","2017-07-14T18:10:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-16T00:00:00","price":{"amount":9090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-16T06:15:00","2017-07-16T18:10:00"],"classOfService":"BW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-17T00:00:00","price":{"amount":4090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-17T06:15:00","2017-07-17T18:10:00"],"classOfService":"PW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-18T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-18T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-19T00:00:00","price":{"amount":3090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-19T06:15:00","2017-07-19T18:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-20T00:00:00","price":{"amount":3590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-20T18:10:00"],"classOfService":"PRW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-21T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-21T06:15:00","2017-07-21T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-23T00:00:00","price":{"amount":7590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-23T06:15:00","2017-07-23T18:10:00"],"classOfService":"BOW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-24T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-24T06:15:00","2017-07-24T18:10:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-25T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-25T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-26T00:00:00","price":{"amount":5090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-26T06:15:00","2017-07-26T18:10:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-27T00:00:00","price":{"amount":15090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-27T18:10:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-28T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-28T06:15:00","2017-07-28T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-30T00:00:00","price":{"amount":25090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-30T06:15:00","2017-07-30T18:10:00"],"classOfService":"IW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-31T00:00:00","price":{"amount":15090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-31T06:15:00","2017-07-31T18:10:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-01T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-01T18:10:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-02T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-02T06:15:00","2017-08-02T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-03T00:00:00","price":{"amount":7590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-03T18:10:00"],"classOfService":"BOW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-04T00:00:00","price":{"amount":5090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-04T06:15:00","2017-08-04T18:10:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-06T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-06T06:15:00","2017-08-06T18:10:00"],"classOfService":"KLW","hasMacFlight":false}],"returnFlights":[{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-07-31T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-31T08:55:00","2017-07-31T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-01T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-01T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-02T00:00:00","price":{"amount":9090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-02T08:55:00","2017-08-02T20:50:00"],"classOfService":"BW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-03T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-03T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-04T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-04T08:55:00","2017-08-04T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-06T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-06T08:55:00","2017-08-06T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-07T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-07T08:55:00","2017-08-07T20:50:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-08T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-08T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-09T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-09T08:55:00","2017-08-09T20:50:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-10T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-10T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-11T00:00:00","price":{"amount":22090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-11T08:55:00","2017-08-11T20:50:00"],"classOfService":"IJW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-13T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-13T08:55:00","2017-08-13T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-14T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-14T08:55:00","2017-08-14T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-15T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-15T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-16T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-16T08:55:00","2017-08-16T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-17T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-17T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-18T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-18T08:55:00","2017-08-18T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-20T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-20T08:55:00","2017-08-20T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-21T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-21T08:55:00","2017-08-21T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-22T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-22T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-23T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-23T08:55:00","2017-08-23T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-24T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-24T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-25T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-25T08:55:00","2017-08-25T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-27T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-27T08:55:00","2017-08-27T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-28T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-28T08:55:00","2017-08-28T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-29T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-29T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-30T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-30T08:55:00","2017-08-30T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-31T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-31T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-09-01T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-09-01T08:55:00","2017-09-01T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-09-03T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-09-03T08:55:00","2017-09-03T20:50:00"],"classOfService":"RSW","hasMacFlight":false}]}

		LocalDate localDate = LocalDate.of( aYear, aMonth, aDay );
		localDate = localDate.plusMonths( 1 );
		int lNextMonth = localDate.getMonthValue();
		int lNextYear = localDate.getYear();
		int lNextDay = localDate.getDayOfMonth();

		String lParameters = "{\"flightList\":[{\"departureStation\":\""
				+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"arrivalStation\":\""
				+ aTravelDataInput.mAirportCode_GoingTo + "\",\"from\":\""
				+ String.format( "%04d-%02d-%02d", aYear, aMonth, aDay ) + "\",\"to\":\""
				+ String.format( "%04d-%02d-%02d", lNextYear, lNextMonth, lNextDay ) + "\"},{\"departureStation\":\""
				+ aTravelDataInput.mAirportCode_GoingTo + "\",\"arrivalStation\":\""
				+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"from\":\""
				+ String.format( "%04d-%02d-%02d", aYear, aMonth, aDay ) + "\",\"to\":\""
				+ String.format( "%04d-%02d-%02d", lNextYear, lNextMonth, lNextDay ) + "\"}],\"priceType\":\"regular\"}";
		HttpRequest request = new HttpRequest();
		String strResponse;
		strResponse = request.sendPost( mApiTimetableUrl, lParameters );

		if( request.getResponseCode() != 404 && strResponse.length() > 0 )
			ParseTheResponse( strResponse, aResultList, aTravelDataInput );

		mLogger.trace( "end, thread name: " + getThreadName());
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
				// There is no return trip, so we put a one way trip
				lComposedTrips.add( lFirstItem );
			}
		}
		return lComposedTrips;
	}

	private void TimeoutTest()
	{
		Sleep( 100 );
		if( Duration.ofMillis( System.currentTimeMillis() - mTimeoutStart ).getSeconds() > 60 )
			mThreadStopped = true;
	}

	public void run()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		try
		{
			System.out.println("Thread::run");

			mThreadStopped = false;
			mTimeoutStart = System.currentTimeMillis();
			while (!mThreadStopped)
			{
				int lSearQueueSize;
				synchronized (mMutex)
				{
					lSearQueueSize = mSearchQueue.isEmpty();
				}

				if ( lSearQueueSize == 0 )
				{
					TimeoutTest();
					continue;
				}

				TravelData_INPUT lTravelDataInput = null;
				synchronized (mMutex)
				{
					lTravelDataInput = (TravelData_INPUT) mSearchQueue.pop();
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

				String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
				Sleep( 1000 * Integer.parseInt( lSleep ));
				mTimeoutStart = System.currentTimeMillis();
			}
			System.out.println("run()");
		}
		catch( Exception aException )
		{
			mLogger.error( StringHelper.getTraceInformation( aException ) );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}
}
