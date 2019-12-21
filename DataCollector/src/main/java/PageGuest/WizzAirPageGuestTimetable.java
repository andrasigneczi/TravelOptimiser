package PageGuest;

import Configuration.Configuration;
import QueueHandlers.JMSPublisher;
import QueueHandlers.LocalStack;
import ResultFilter.ResultFilter;
import Util.DCHttpClient;
import Util.DatetimeHelper;
import Util.StringHelper;
import Util.WizzairHelper;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;
import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.WebDriverWait;

import javax.jms.JMSException;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.net.http.HttpClient;
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
	//DCHttpClient dcHttpClient = new DCHttpClient();
	DCHttpClient dcHttpClient;

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
		WebDriver driver = new ChromeDriver();
		driver.get("https://wizzair.com/buildnumber");
		WebDriverWait wait = new WebDriverWait(driver, 15);
		wait.until(webDriver -> ((JavascriptExecutor) driver).executeScript("return document.readyState").toString().equals("complete"));
		Thread.sleep(4000);  // Just to be sure! May crash occur without this sleep.

		String lApiVersion = WizzairHelper.getApiVersion(driver);
		driver.close();
		if( lApiVersion.length() == 0 )
			throw new RuntimeException( "Wrong API version!" );

		mApiTimetableUrl = "https://be.wizzair.com/" + lApiVersion + "/Api/search/timetable";
	}

	private void InitHttpRequest() {

		// POST /10.2.0/Api/search/timetable HTTP/1.1
		// Host: be.wizzair.com
		// User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:70.0) Gecko/20100101 Firefox/70.0
		// Accept: application/json, text/plain, */*
		// Accept-Language: hu-HU,hu;q=0.8,en-US;q=0.5,en;q=0.3
		// Accept-Encoding: gzip, deflate, br
		// Referer: https://wizzair.com/en-gb/flights/timetable/budapest/brussels-charleroi
		// Content-Type: application/json;charset=utf-8
		// X-RequestVerificationToken: 5f62d673f0a745499cea86beed3e312c
		// Content-Length: 256
		// Origin: https://wizzair.com
		// Connection: keep-alive
		// Cookie: _abck=2964E1E7F9D09663D348822E54EFA6D2~0~YAAQ33oRAlTX1a5uAQAAspR7tgJ58mIsjXExZw/kPyf9bV8SrLeZrC2KNAjAw59BDrB211ATZXv6U4WjlGWcFkDxkLyr6z8ukTG2KtojTQW+SuSPReUiLFSuvY7QUaSZPW1UcFG5InzaRBlXVI24crRthtbNAksn3LAGg7gw0Z5lAEbj+2ls4y6riNlnA+/k6GPibXQ+PLgTUuCqITudCIv1+D1B179zr5IoTTJNKvT6OeOG+E6L5yZnCU1Vd84UhlOHHlmvNRngV8nenlqJDbmjGRw1QZu7kwcbalui7wSW7y/SmDkTPVqJTY7AzfjTGGSLyEgXkJiJIYqhDuBJmiXxpMdjAudBM0gBepqYdcYPM9v5/pnuWA==~-1~-1~-1; _fbp=fb.1.1562928852261.1103438653; _gcl_au=1.1.995924602.1562928852; _hjid=9a5e0038-d9e2-4aaa-937e-a149b4a720f0; _ga=GA1.2.321106367.1562928853; ASP.NET_SessionId=nrjod3vgzyotpfcfqtngtcm5; RequestVerificationToken=5f62d673f0a745499cea86beed3e312c; ak_bmsc=667EE3BF72261ED75A55473AC49A7843021674F42D4100001E11EE5DA13E997A~plzlQ132MUiCnFPXDjx5mq1rxiHewTaWlVjVqlROyS1GHD8One6ghSAQJ0lDKrz4LzHjAP8tmG+/9CV1BBF0mUFSH9yU2kwsp1eXpca2qJCS9rklwjwkEiNQVzZDcrRoX+OL4BQ2L84dEci/edyrL92GcA+0+DDXmPig8ef6jrY+iKFTA02ne0vroCQiIuZfoapZOUxbjp/931qZ2v8LEd8hmEGf0WVjORS5lPKJn7fy8tHnNXTK+wRPFMCg8mBtSzAhgRzcCkRW3FK9fBA0EhtG3YjRxD+HIXJcPJ51Ixk5ySaiAeKrPv5pGdLZYLXa90AxoMAkBBGi89S1i9sPsWTg==; bm_sz=59EAA9FFDDA91A1956CFABD4B2DE8486~YAAQ9HQWAmEk5spuAQAAi97y6QZRCn9LA+PjtDDYNl26hikXlIedUbXi0H5ibuxiP8iKRJwhcmqmQ3+OnNGNXmwcA7Y4ByeX1yfLgOWJQS4okY2TlJGkF496GguEe+SNcoRyqVNU8FkYIBvKNewjPhXhsegZ4Zbcmjlj762hHupGlJTWIVWOOJAehjjbpKCr; bm_mi=EEE263C37F72F1AFD4C4B8F57596996F~NHFRoMvx+f2yogmw3nm1Fwn7l8xgCyS4f+n5HnSkZoxS9EBpQKV+kLG1RCFlDLJLd2lIudt4ovJgc4u4FuBJbOPVDbqlpTPa57i3UZMLg2GaGmdoYzq6BgdGNMhuqZunVzkqSl5cH1uxv1KRbOxK6Wj4qn4xU7gBOVg9UUTXrTSYN+P0hNpKNiKLWQio36eFwSoo47kcEH5+9I/jCbPklQMGL+nA0rg744ezKzdc/oxPLDTkcBrJu2utk4DDliz6uvJGx3hRwrrJkdmqzWd6Ig==; bm_sv=EE4D814D5C66E9B371F00DA4D5856979~Bzy/9BKh7a+8k/Sk6dPVJK7OCTyMa7eyx0gSwM+LRg6B616fBOc1/l52QLxh97DvmRfJ82H5UEa4aX/FV3d2bhxCwA9DDsFkVsTBYnGGDxFqfIopZa+/v4jOEChTIyMMKbss2BPLX3yZqoBcZDhNLdLoYtwxe+bpDwGDUsHb9Ok=; _gid=GA1.2.216606102.1575884932; _gat_gtag_UA_2629375_25=1

		dcHttpClient = new DCHttpClient(HttpClient.Version.HTTP_1_1);

		dcHttpClient.addProperties( "Origin",          "https://wizzair.com" );
		dcHttpClient.addProperties( "Authority",       "be.wizzair.com" );
		dcHttpClient.addProperties( "Referer",         "https://wizzair.com/" );
		dcHttpClient.addProperties( "Accept",          "application/json, text/plain, */*" );
		dcHttpClient.addProperties( "Content-Type",    "application/json;charset=utf-8" );
		//dcHttpClient.addProperties( "X-RequestVerificationToken", "3fb6e5cabe8c40c19cad2956646fe3e8");
		try {
			dcHttpClient.sendGet("https://wizzair.com/");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public WizzAirPageGuestTimetable()
	{
		super( "wizzair" );
		mSearchQueue = new LocalStack<>();
		mThread = new Thread(this);
		mThread.setName("WizzAirTimetableThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		//InitHttpRequest();
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

	public void FillTheForm( TravelData_INPUT aTravelDataInput ) throws Exception,
			CloneNotSupportedException
	{
		LocalDate lDate = LocalDate.now();
		int lYear = lDate.getYear();
		int lMonth = lDate.getMonthValue();
		int lDay = lDate.getDayOfMonth();
		String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		ArrayList<TravelData_RESULT> lResultList = new ArrayList<TravelData_RESULT>();

		if( aTravelDataInput.mInterval.length() > 0 )
		{
			final int lInterval = StringHelper.parseInt( aTravelDataInput.mInterval, 6 );

			// 6 month ahead
			for( int i = 0; i < lInterval; i++ )
			{
				FillTheForm( aTravelDataInput, lYear, lMonth, lDay, lResultList );
				lDate = lDate.plusMonths( 1 );
				lYear = lDate.getYear();
				lMonth = lDate.getMonthValue();
				lDay = lDate.getDayOfMonth();
				Sleep( 1000 * Integer.parseInt( lSleep ) );
			}
		}
		else
		{
			ArrayList<Integer> dateItems = DatetimeHelper.getDateItems( aTravelDataInput.mMonth );
			FillTheForm( aTravelDataInput, dateItems.get( 0 ), dateItems.get( 1 ), 1, lResultList );
			Sleep( 1000 * Integer.parseInt( lSleep ) );
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

			String lpriceType = lJSONTrip.getString( "priceType" );
			if( lpriceType.equals( "soldOut" ))
				continue;

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

		JSONArray lRoot;
		try { lRoot = new JSONArray( lTokener ); } catch (JSONException e) {
			mLogger.error( "Exception in ParseTheResponse: " + StringHelper.getTraceInformation( e ) );
			mLogger.error( "Response string: " + aResponse );
			return;
		}

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

	private void FillTheForm( TravelData_INPUT aTravelDataInput, int aYear, int aMonth, int aDay, ArrayList<TravelData_RESULT> aResultList ) throws Exception
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		// JSON post
		// https://be.wizzair.com/6.1.0/Api/search/timetable
		// {"flightList":[{"departureStation":"BUD","arrivalStation":"CRL","from":"2017-07-13","to":"2017-08-06"},{"departureStation":"CRL","arrivalStation":"BUD","from":"2017-07-31","to":"2017-09-03"}],"priceType":"wdc"}
		// {"outboundFlights":[{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-14T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-14T06:15:00","2017-07-14T18:10:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-16T00:00:00","price":{"amount":9090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-16T06:15:00","2017-07-16T18:10:00"],"classOfService":"BW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-17T00:00:00","price":{"amount":4090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-17T06:15:00","2017-07-17T18:10:00"],"classOfService":"PW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-18T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-18T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-19T00:00:00","price":{"amount":3090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-19T06:15:00","2017-07-19T18:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-20T00:00:00","price":{"amount":3590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-20T18:10:00"],"classOfService":"PRW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-21T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-21T06:15:00","2017-07-21T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-23T00:00:00","price":{"amount":7590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-23T06:15:00","2017-07-23T18:10:00"],"classOfService":"BOW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-24T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-24T06:15:00","2017-07-24T18:10:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-25T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-25T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-26T00:00:00","price":{"amount":5090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-26T06:15:00","2017-07-26T18:10:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-27T00:00:00","price":{"amount":15090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-27T18:10:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-28T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-28T06:15:00","2017-07-28T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-30T00:00:00","price":{"amount":25090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-30T06:15:00","2017-07-30T18:10:00"],"classOfService":"IW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-07-31T00:00:00","price":{"amount":15090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-31T06:15:00","2017-07-31T18:10:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-01T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-01T18:10:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-02T00:00:00","price":{"amount":6090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-02T06:15:00","2017-08-02T18:10:00"],"classOfService":"OW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-03T00:00:00","price":{"amount":7590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-03T18:10:00"],"classOfService":"BOW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-04T00:00:00","price":{"amount":5090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-04T06:15:00","2017-08-04T18:10:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2017-08-06T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-06T06:15:00","2017-08-06T18:10:00"],"classOfService":"KLW","hasMacFlight":false}],"returnFlights":[{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-07-31T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-07-31T08:55:00","2017-07-31T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-01T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-01T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-02T00:00:00","price":{"amount":9090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-02T08:55:00","2017-08-02T20:50:00"],"classOfService":"BW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-03T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-03T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-04T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-04T08:55:00","2017-08-04T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-06T00:00:00","price":{"amount":12090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-06T08:55:00","2017-08-06T20:50:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-07T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-07T08:55:00","2017-08-07T20:50:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-08T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-08T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-09T00:00:00","price":{"amount":10590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-09T08:55:00","2017-08-09T20:50:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-10T00:00:00","price":{"amount":13590.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-10T20:50:00"],"classOfService":"KLW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-11T00:00:00","price":{"amount":22090.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-11T08:55:00","2017-08-11T20:50:00"],"classOfService":"IJW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-13T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-13T08:55:00","2017-08-13T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-14T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-14T08:55:00","2017-08-14T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-15T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-15T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-16T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-16T08:55:00","2017-08-16T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-17T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-17T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-18T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-18T08:55:00","2017-08-18T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-20T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-20T08:55:00","2017-08-20T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-21T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-21T08:55:00","2017-08-21T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-22T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-22T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-23T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-23T08:55:00","2017-08-23T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-24T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-24T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-25T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-25T08:55:00","2017-08-25T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-27T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-27T08:55:00","2017-08-27T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-28T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-28T08:55:00","2017-08-28T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-29T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-29T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-30T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-30T08:55:00","2017-08-30T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-08-31T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-08-31T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-09-01T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-09-01T08:55:00","2017-09-01T20:50:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2017-09-03T00:00:00","price":{"amount":2990.00,"currencyCode":"HUF"},"priceType":"price","departureDates":["2017-09-03T08:55:00","2017-09-03T20:50:00"],"classOfService":"RSW","hasMacFlight":false}]}
		// https://be.wizzair.com/10.2.0/Api/search/timetable
		// {"flightList":[{"departureStation":"BUD","arrivalStation":"CRL","from":"2019-12-09","to":"2020-01-05"},{"departureStation":"CRL","arrivalStation":"BUD","from":"2019-12-30","to":"2020-02-02"}],"priceType":"wdc","adultCount":1,"childCount":0,"infantCount":0}
		// {"outboundFlights":[{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-09T00:00:00","price":{"amount":17890.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-09T18:05:00"],"classOfService":"JKW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-10T00:00:00","price":{"amount":12990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-10T18:35:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-11T00:00:00","price":{"amount":9690.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-11T06:15:00"],"classOfService":"BW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-12T00:00:00","price":{"amount":17890.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-12T18:20:00"],"classOfService":"JKW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-13T00:00:00","price":{"amount":4890.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-13T18:05:00"],"classOfService":"PW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-14T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-14T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-15T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-15T06:15:00","2019-12-15T18:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-16T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-16T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-17T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-17T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-18T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-18T06:15:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-19T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-19T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-20T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-20T11:15:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-21T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-21T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-22T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-22T06:15:00","2019-12-22T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-23T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-23T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-24T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-24T18:05:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-25T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-25T06:15:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-26T00:00:00","price":{"amount":7990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-26T18:05:00"],"classOfService":"BOW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-27T00:00:00","price":{"amount":11390.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-27T18:05:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-28T00:00:00","price":{"amount":12990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-28T18:05:00"],"classOfService":"LW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-29T00:00:00","price":{"amount":16190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-29T06:15:00","2019-12-29T18:05:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-30T00:00:00","price":{"amount":22690.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-30T18:05:00"],"classOfService":"IJW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2019-12-31T00:00:00","price":{"amount":17890.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-31T18:05:00"],"classOfService":"JKW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2020-01-01T00:00:00","price":{"amount":16190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-01T06:15:00"],"classOfService":"KW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2020-01-02T00:00:00","price":{"amount":55190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-02T18:05:00"],"classOfService":"EW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2020-01-03T00:00:00","price":{"amount":50390.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-03T18:05:00"],"classOfService":"FEW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2020-01-04T00:00:00","price":{"amount":55190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-04T18:35:00"],"classOfService":"EW","hasMacFlight":false},{"departureStation":"BUD","arrivalStation":"CRL","departureDate":"2020-01-05T00:00:00","price":{"amount":59990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-05T18:05:00"],"classOfService":"EDW","hasMacFlight":false}],"returnFlights":[{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2019-12-30T00:00:00","price":{"amount":3990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-30T20:40:00"],"classOfService":"PRW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2019-12-31T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2019-12-31T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-01T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-01T09:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-02T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-02T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-03T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-03T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-04T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-04T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-05T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-05T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-06T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-06T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-07T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-07T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-08T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-08T09:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-09T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-09T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-10T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-10T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-11T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-11T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-12T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-12T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-13T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-13T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-14T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-14T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-15T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-15T09:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-16T00:00:00","price":{"amount":5690.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-16T20:40:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-17T00:00:00","price":{"amount":5690.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-17T20:40:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-18T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-18T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-19T00:00:00","price":{"amount":3990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-19T20:40:00"],"classOfService":"PRW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-20T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-20T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-21T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-21T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-22T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-22T09:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-23T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-23T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-24T00:00:00","price":{"amount":11390.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-24T20:40:00"],"classOfService":"LBW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-25T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-25T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-26T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-26T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-27T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-27T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-28T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-28T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-29T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-29T09:05:00"],"classOfService":"RSW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-30T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-30T20:40:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-01-31T00:00:00","price":{"amount":5690.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-01-31T20:40:00"],"classOfService":"OPW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-02-01T00:00:00","price":{"amount":3190.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-02-01T21:10:00"],"classOfService":"RW","hasMacFlight":false},{"departureStation":"CRL","arrivalStation":"BUD","departureDate":"2020-02-02T00:00:00","price":{"amount":12990.0,"currencyCode":"HUF"},"priceType":"price","departureDates":["2020-02-02T20:40:00"],"classOfService":"LW","hasMacFlight":false}]}
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
				+ String.format( "%04d-%02d-%02d", lNextYear, lNextMonth, lNextDay ) + "\"}],\"priceType\":\"regular\",\"adultCount\":1,\"childCount\":0,\"infantCount\":0}";
		String strResponse;

		InitHttpRequest();
		strResponse = dcHttpClient.sendPost( mApiTimetableUrl, lParameters );

		if( dcHttpClient.getResponseCode() != 404 && strResponse.length() > 0 )
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
				catch( Exception e )
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
