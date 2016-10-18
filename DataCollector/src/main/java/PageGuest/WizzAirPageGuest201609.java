package PageGuest;

import QueueHandlers.JMSStack;
import QueueHandlers.LocalStack;
import QueueHandlers.ResultQueue;
import Util.Configuration;
import Util.HttpRequest;
import Util.StringHelper;
import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.charset.Charset;
import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static Util.CurrencyHelper.ConvertFrom3Digits;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

/**
 * Created by Andras on 02/09/2016.
 */
public class WizzAirPageGuest201609 extends PageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest201609.class);

	private boolean mThreadStopped = true;
	private long mTimeoutStart;
	private static String mApiSearchUrl = "https://be.wizzair.com/3.3.3/Api/search/search";

	public static void InitApirURL() throws Exception
	{
		//var apiUrl = "https://be.wizzair.com/3.3.3/Api";
//		HttpRequest lHttpRequest = new HttpRequest();
//		String lContent = lHttpRequest.sendGet( "https://wizzair.com", 0 );

		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		Browser lBrowser = TeamDevJxBrowser.getInstance().getJxBrowser("wwwww");
		Browser.invokeAndWaitFinishLoadingMainFrame(lBrowser, new Callback<Browser>() {
			@Override
			public void invoke(Browser browser) {
				browser.loadURL("https://wizzair.com");
			}
		});

		DOMDocument lDocument = lBrowser.getDocument();
		String lContent = lDocument.getDocumentElement().getInnerHTML();

		Pattern reg = Pattern.compile( "var apiUrl = \"(.*)\";" );
		Matcher m = reg.matcher( lContent );
		String lUrl = "";
		if( m.find() )
		{
			lUrl = m.group(1).toString().trim();
			mLogger.info( "WizzAir API URL: " + lUrl );
			mApiSearchUrl = lUrl + "/search/search";
		}
		lBrowser.dispose();
	}

	public WizzAirPageGuest201609()
	{
		super("wizzair");
		mSearchQueue = new LocalStack<>();
		mThread = new Thread(this);
		mThread.setName("WizzAirThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();
	}

	public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate)
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		DateValidity lValidity = ValidateDate(aDepartureDate, aReturnDate);

		if( lValidity == DateValidity.INVALID_COMBINATION )
		{
			mLogger.warn( "DoSearch: the departure date (" + aDepartureDate + ") and/or the return date " +
					aReturnDate + " is/are invalid!" );
			return;
		}

		TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
		lTravelDataInput.mAirline = getAirline();
		lTravelDataInput.mAdultNumber = "1";
		lTravelDataInput.mChildNumber = "0";
		lTravelDataInput.mInfantNumber = "0";

		if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
		{
			mLogger.warn(" DoSearch: the departure date (" + aDepartureDate + ") is invalid!" );

			// we will use only the return date
			lTravelDataInput.mAirportCode_LeavingFrom = aTo;
			lTravelDataInput.mAirportCode_GoingTo = aFrom;
			lTravelDataInput.mDepartureDay = aReturnDate;
			lTravelDataInput.mReturnDay = "";
			lTravelDataInput.mReturnTicket = false;
		}
		else if( lValidity == DateValidity.BOTH_OF_THEM_VALID )
		{
			lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
			lTravelDataInput.mAirportCode_GoingTo = aTo;
			lTravelDataInput.mDepartureDay = aDepartureDate;
			lTravelDataInput.mReturnDay = aReturnDate;
			//lTravelDataInput.mNearbyAirports          = false;
			if (aReturnDate.length() == 0)
				lTravelDataInput.mReturnTicket = false;
			else
				lTravelDataInput.mReturnTicket = true;
		}

		synchronized (mMutex)
		{
			mSearchQueue.push(lTravelDataInput);
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	public void DoSearchFromConfig()
	{
		synchronized (mMutex)
		{
			ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchList();
			for (TravelData_INPUT lTDI : lSearchList)
			{
				if (!lTDI.mAirline.equals(getAirline()))
					continue;

				DateValidity lValidity = ValidateDate(lTDI.mDepartureDay, lTDI.mReturnDay);

				if( lValidity == DateValidity.INVALID_COMBINATION )
				{
					mLogger.warn( "DoSearch: the departure date (" + lTDI.mDepartureDay + ") and/or the return date " +
							lTDI.mReturnDay + " is/are invalid!" );
					continue;
				}

				if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
				{
					mLogger.warn(" DoSearch: the departure date (" + lTDI.mDepartureDay + ") is invalid!" );

					// we will use only the return date
					String lTemp = lTDI.mAirportCode_LeavingFrom;
					lTDI.mAirportCode_LeavingFrom = lTDI.mAirportCode_GoingTo;
					lTDI.mAirportCode_GoingTo = lTemp;
					lTDI.mDepartureDay = lTDI.mReturnDay;
					lTDI.mReturnDay = "";
					lTDI.mReturnTicket = false;
				}
				else if( lValidity == DateValidity.BOTH_OF_THEM_VALID )
				{
					if (lTDI.mReturnDay.length() == 0)
						lTDI.mReturnTicket = false;
					else
						lTDI.mReturnTicket = true;
				}

				mSearchQueue.push(lTDI);
			}
		}
	}

	public void InitJMS()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		synchronized (mMutex)
		{
			mSearchQueue = new JMSStack<TravelData_INPUT>();
			mSearchQueue.setQueueName( getAirline() );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
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

	private String FormatDate( String aDate )
	{
		String[] lParts = aDate.split("\\.", 0 );
		return String.format( "%s-%s-%s", lParts[ 0 ], lParts[ 1 ], lParts[ 2 ] );
	}

	private void ParseBundles( JSONArray aBoundles )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
//		outboundBundles = {JSONArray@1644} "[{"code":"BASIC","ancillaryServices":[]},{"code":"PLUS","ancillaryServices":["seat-selection","wizz-flex-for-flight-changes","wizz-priority-boarding","airport-checkin","small-cabin-bag","heavy-checked-in-bag"]}]"
//		myArrayList = {ArrayList@1761}  size = 2
//		0 = {JSONObject@1763} "{"code":"BASIC","ancillaryServices":[]}"
//		map = {HashMap@1773}  size = 2
//		0 = {HashMap$Node@1776} "code" -> "BASIC"
//		1 = {HashMap$Node@1777} "ancillaryServices" -> "[]"
//		1 = {JSONObject@1764} "{"code":"PLUS","ancillaryServices":["seat-selection","wizz-flex-for-flight-changes","wizz-priority-boarding","airport-checkin","small-cabin-bag","heavy-checked-in-bag"]}"
//		map = {HashMap@1783}  size = 2
//		0 = {HashMap$Node@1786} "code" -> "PLUS"
//		key = "code"
//		value = "PLUS"
//		1 = {HashMap$Node@1787} "ancillaryServices" -> "["seat-selection","wizz-flex-for-flight-changes","wizz-priority-boarding","airport-checkin","small-cabin-bag","heavy-checked-in-bag"]"
//		key = "ancillaryServices"
//		value = {JSONArray@1791} "["seat-selection","wizz-flex-for-flight-changes","wizz-priority-boarding","airport-checkin","small-cabin-bag","heavy-checked-in-bag"]"
//		myArrayList = {ArrayList@1794}  size = 6
//		0 = "seat-selection"
//		1 = "wizz-flex-for-flight-changes"
//		2 = "wizz-priority-boarding"
//		3 = "airport-checkin"
//		4 = "small-cabin-bag"
//		5 = "heavy-checked-in-bag"
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void ParseFares( JSONArray aFares, TravelData_RESULT.TravelData_PossibleTrip aTrip )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		for( int lFaresIndex = 0; lFaresIndex < aFares.length(); lFaresIndex++ )
		{
			JSONObject lFare = aFares.getJSONObject( lFaresIndex );
			String lBundle = lFare.getString( "bundle" );
			Boolean lWdc = lFare.getBoolean( "wdc" );
			JSONObject lDiscountedPrice = lFare.getJSONObject( "discountedPrice" );
			Double lAmount = lDiscountedPrice.getDouble( "amount" );
			String lCurrency = ConvertFrom3Digits( lDiscountedPrice.getString( "currencyCode" ));

			if( lBundle.equals( "BASIC" ))
			{
				if( lWdc )
					aTrip.mPrices_BasicFare_Discount = lAmount + " " + lCurrency;
				else
					aTrip.mPrices_BasicFare_Normal = lAmount + " " + lCurrency;
			}
			else
			{
				if( lWdc )
					aTrip.mPrices_PlusFare_Discount = lAmount + " " + lCurrency;
				else
					aTrip.mPrices_PlusFare_Normal = lAmount + " " + lCurrency;
			}
		}

//		myArrayList = {ArrayList@1835}  size = 4
//		0 = {JSONObject@1837} "{"discountedPrice":{"amount":59.99,"currencyCode":"BGN"},"wdc":true,"fareSellKey":"0~OW~~OWZZC~WZZC~~1~X","bundle":"BASIC","fareDiscountType":"none","basePrice":{"amount":59.99,"currencyCode":"BGN"}}"
//		map = {HashMap@1845}  size = 6
//		0 = {HashMap$Node@1848} "discountedPrice" -> "{"amount":59.99,"currencyCode":"BGN"}"
//		key = "discountedPrice"
//		value = {JSONObject@1855} "{"amount":59.99,"currencyCode":"BGN"}"
//		map = {HashMap@1950}  size = 2
//		0 = {HashMap$Node@1953} "amount" -> "59.99"
//		1 = {HashMap$Node@1954} "currencyCode" -> "BGN"
//		1 = {HashMap$Node@1849} "wdc" -> "true"
//		2 = {HashMap$Node@1850} "fareSellKey" -> "0~OW~~OWZZC~WZZC~~1~X"
//		3 = {HashMap$Node@1851} "bundle" -> "BASIC"
//		4 = {HashMap$Node@1852} "fareDiscountType" -> "none"
//		5 = {HashMap$Node@1853} "basePrice" -> "{"amount":59.99,"currencyCode":"BGN"}"
//		key = "basePrice"
//		value = {JSONObject@1865} "{"amount":59.99,"currencyCode":"BGN"}"
//		map = {HashMap@1938}  size = 2
//		0 = {HashMap$Node@1941} "amount" -> "59.99"
//		key = "amount"
//		value = {Double@1944} "59.99"
//		1 = {HashMap$Node@1942} "currencyCode" -> "BGN"
//		1 = {JSONObject@1838} "{"discountedPrice":{"amount":134.99,"currencyCode":"BGN"},"wdc":true,"fareSellKey":"0~OW~~OWZZC~WZZC~~1~X","bundle":"PLUS","fareDiscountType":"none","basePrice":{"amount":134.99,"currencyCode":"BGN"}}"
//		map = {HashMap@1869}  size = 6
//		0 = {HashMap$Node@1872} "discountedPrice" -> "{"amount":134.99,"currencyCode":"BGN"}"
//		1 = {HashMap$Node@1873} "wdc" -> "true"
//		2 = {HashMap$Node@1874} "fareSellKey" -> "0~OW~~OWZZC~WZZC~~1~X"
//		3 = {HashMap$Node@1875} "bundle" -> "PLUS"
//		4 = {HashMap$Node@1876} "fareDiscountType" -> "none"
//		5 = {HashMap$Node@1877} "basePrice" -> "{"amount":134.99,"currencyCode":"BGN"}"
//		2 = {JSONObject@1839} "{"discountedPrice":{"amount":79.99,"currencyCode":"BGN"},"wdc":false,"fareSellKey":"0~O~~OREG~REG1~~3~X","bundle":"BASIC","fareDiscountType":"none","basePrice":{"amount":79.99,"currencyCode":"BGN"}}"
//		map = {HashMap@1891}  size = 6
//		0 = {HashMap$Node@1894} "discountedPrice" -> "{"amount":79.99,"currencyCode":"BGN"}"
//		1 = {HashMap$Node@1895} "wdc" -> "false"
//		2 = {HashMap$Node@1896} "fareSellKey" -> "0~O~~OREG~REG1~~3~X"
//		3 = {HashMap$Node@1897} "bundle" -> "BASIC"
//		4 = {HashMap$Node@1898} "fareDiscountType" -> "none"
//		5 = {HashMap$Node@1899} "basePrice" -> "{"amount":79.99,"currencyCode":"BGN"}"
//		3 = {JSONObject@1840} "{"discountedPrice":{"amount":154.99,"currencyCode":"BGN"},"wdc":false,"fareSellKey":"0~O~~OREG~REG1~~3~X","bundle":"PLUS","fareDiscountType":"none","basePrice":{"amount":154.99,"currencyCode":"BGN"}}"
//		map = {HashMap@1915}  size = 6
//		0 = {HashMap$Node@1918} "discountedPrice" -> "{"amount":154.99,"currencyCode":"BGN"}"
//		1 = {HashMap$Node@1919} "wdc" -> "false"
//		2 = {HashMap$Node@1920} "fareSellKey" -> "0~O~~OREG~REG1~~3~X"
//		3 = {HashMap$Node@1921} "bundle" -> "PLUS"
//		4 = {HashMap$Node@1922} "fareDiscountType" -> "none"
//		5 = {HashMap$Node@1923} "basePrice" -> "{"amount":154.99,"currencyCode":"BGN"}"
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void ParseFlights( JSONArray aFlights, boolean aOutbound )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());

//		0 = {HashMap$Node@1670} "infantLimitExceeded" -> "{"isBlocking":true,"limitExceeded":false}"
//		1 = {HashMap$Node@1671} "oxyLimitExceeded" -> "{"isBlocking":true,"limitExceeded":false}"
//		2 = {HashMap$Node@1672} "flightSellKey" -> "W6~4337~ ~~SOF~09/27/2016 06:30~HHN~09/27/2016 08:05~"
//		3 = {HashMap$Node@1673} "sportsEquipmentLimitExceeded" -> "{"isBlocking":false,"limitExceeded":false}"
//		4 = {HashMap$Node@1674} "carrierCode" -> "W6"
//		5 = {HashMap$Node@1675} "departureDateTime" -> "2016-09-27T06:30:00"
//		6 = {HashMap$Node@1676} "departureStation" -> "SOF"
//		7 = {HashMap$Node@1677} "arrivalDateTime" -> "2016-09-27T08:05:00"
//		8 = {HashMap$Node@1678} "arrivalStation" -> "HHN"
//		9 = {HashMap$Node@1679} "wheelchairLimitExceeded" -> "{"isBlocking":true,"limitExceeded":false}"
//		10 = {HashMap$Node@1680} "fares" -> "[{"discountedPrice":{"amount":59.99,"currencyCode":"BGN"},"wdc":true,"fareSellKey":"0~OW~~OWZZC~WZZC~~1~X","bundle":"BASIC","fareDiscountType":"none","basePrice":{"amount":59.99,"currencyCode":"BGN"}},{"discountedPrice":{"amount":134.99,"currencyCode":"BGN"},"wdc":true,"fareSellKey":"0~OW~~OWZZC~WZZC~~1~X","bundle":"PLUS","fareDiscountType":"none","basePrice":{"amount":134.99,"currencyCode":"BGN"}},{"discountedPrice":{"amount":79.99,"currencyCode":"BGN"},"wdc":false,"fareSellKey":"0~O~~OREG~REG1~~3~X","bundle":"BASIC","fareDiscountType":"none","basePrice":{"amount":79.99,"currencyCode":"BGN"}},{"discountedPrice":{"amount":154.99,"currencyCode":"BGN"},"wdc":false,"fareSellKey":"0~O~~OREG~REG1~~3~X","bundle":"PLUS","fareDiscountType":"none","basePrice":{"amount":154.99,"currencyCode":"BGN"}}]"
//		11 = {HashMap$Node@1681} "flightNumber" -> "4337"

		TravelData_RESULT.TravelData_PossibleTrip lTDRTrip = new TravelData_RESULT.TravelData_PossibleTrip();
		lTDRTrip.mOutboundTrip = aOutbound;

		for( int lTripIndex = 0; lTripIndex < aFlights.length(); lTripIndex++ )
		{
			TravelData_RESULT.TravelData_PossibleTrip lTripClone = (TravelData_RESULT.TravelData_PossibleTrip)lTDRTrip.clone();
			JSONObject lJSONTrip = aFlights.getJSONObject( lTripIndex );
			lTripClone.mDepartureDatetime = lJSONTrip.getString( "departureDateTime" );
			lTripClone.mArrivalDatetime   = lJSONTrip.getString( "arrivalDateTime" );
			JSONArray lFares = lJSONTrip.getJSONArray( "fares" );
			ParseFares( lFares, lTripClone );
			if( lTripClone.mPrices_PlusFare_Normal.length() != 0
					|| lTripClone.mPrices_PlusFare_Discount.length() != 0
					|| lTripClone.mPrices_BasicFare_Normal.length() != 0
					|| lTripClone.mPrices_BasicFare_Discount.length() != 0 )
				mTravelDataResult.mTrips.add( lTripClone );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void ParseTheResponse( String aResponse )
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
				String lCurrencyCode = jobj.getString( "currencyCode" );
				JSONArray returnFlights = null;
				Object returnFlightsObject = jobj.get( "returnFlights" );
				if( returnFlightsObject != null && returnFlightsObject instanceof JSONArray )
					returnFlights = (JSONArray)returnFlightsObject;

				//JSONArray outboundBundles = jobj.getJSONArray( "outboundBundles" );
				//JSONArray returnBundles = jobj.getJSONArray( "returnBundles" );
				JSONArray outboundFlights = jobj.getJSONArray( "outboundFlights" );

				ParseFlights( outboundFlights, true );
				if( returnFlights != null )
					ParseFlights( returnFlights, false );
			}
			catch (JSONException e)
			{
				mLogger.error( "Exception in ParseTheResponse: " + StringHelper.getTraceInformation( e ) );
			}
		}


		ResultQueue.getInstance().push( mTravelDataResult );
		mTravelDataResult = null;
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException
	{
		mLogger.trace( "begin, thread name: " + getThreadName());

		// curl "https://be.wizzair.com/3.0.4/Api/search/search" -H "origin: https://wizzair.com" -H "accept-encoding: gzip, deflate, br" -H "accept-language: hu,en-US;q=0.8,en;q=0.6,de-DE;q=0.4,de;q=0.2,fr;q=0.2" -H "user-agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36" -H "content-type: application/json" -H "accept: application/json, text/plain, */*" -H "referer: https://wizzair.com/" -H "authority: be.wizzair.com" -H "cookie: ASP.NET_SessionId=spvzv4uxq44q5y10exk2e2a5; _ga=GA1.2.1798072642.1456818314; _gat=1" --data-binary "{""flightList"":[{""departureStation"":""CRL"",""arrivalStation"":""BUD"",""departureDate"":""2016-10-07""},{""departureStation"":""BUD"",""arrivalStation"":""CRL"",""departureDate"":""2016-10-10""}],""adultCount"":1,""childCount"":0,""infantCount"":0,""wdc"":true}" --compressed

		// "{\"flightList\":[{\"departureStation\":\"CRL\",\"arrivalStation\":\"BUD\",\"departureDate\":\"2016-10-07\"},{\"departureStation\":\"BUD\",\"arrivalStation\":\"CRL\",\"departureDate\":\"2016-10-10\"}],\"adultCount\":1,\"childCount\":0,\"infantCount\":0,\"wdc\":true}"
		String lParameters = "";
		if( aTravelDataInput.mReturnTicket )
		{
			lParameters = "{\"flightList\":[{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"departureDate\":\""
					+ FormatDate( aTravelDataInput.mDepartureDay ) + "\"},{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"departureDate\":\"" + FormatDate(
					aTravelDataInput.mReturnDay )
					+ "\"}],\"adultCount\":" + aTravelDataInput.mAdultNumber + ",\"childCount\":"
					+ aTravelDataInput.mChildNumber + ",\"infantCount\":" + aTravelDataInput.mInfantNumber + ",\"wdc\":true}";
		}
		else
		{
			lParameters = "{\"flightList\":[{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"departureDate\":\""
					+ FormatDate( aTravelDataInput.mDepartureDay ) + "\"}],\"adultCount\":" + aTravelDataInput.mAdultNumber + ",\"childCount\":"
					+ aTravelDataInput.mChildNumber + ",\"infantCount\":" + aTravelDataInput.mInfantNumber + ",\"wdc\":true}";
		}

		HttpRequest request = new HttpRequest();
		String strResponse;
		strResponse = request.sendPost( mApiSearchUrl, lParameters );

		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirline = aTravelDataInput.mAirline;
		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
		mTravelDataResult.mTravelDataInput = aTravelDataInput;
		ParseTheResponse( strResponse );
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void TimeoutTest()
	{
		Sleep( 100 );
		if( Duration.ofMillis( System.currentTimeMillis() - mTimeoutStart ).getSeconds() > 60 )
			mThreadStopped = true;
	}

	public void run()
	{
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
					lTravelDataInput = mSearchQueue.pop();
				}

				try
				{
					FillTheForm( lTravelDataInput );
				}
				catch( URISyntaxException e )
				{
					mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
				}
				catch( IOException e )
				{
					mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
				}
				catch( IllegalStateException e )
				{
					mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
				}

				String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
				Sleep( 1000 * Integer.parseInt( lSleep ));
				mTimeoutStart = System.currentTimeMillis();
			}
			System.out.println("run()");
		}
		catch (Exception e)
		{
			mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
		}
	}

	public void WaitForFinish()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		try
		{
			mThread.join();
		}
		catch( InterruptedException e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ));
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}
}


// curl "https://be.wizzair.com/3.0.5/Api/search/search" -H "pragma: no-cache" -H "origin: https://wizzair.com"
// -H "accept-encoding: gzip, deflate, br" -H "accept-language: hu-HU,hu;q=0.8,en-US;q=0.6,en;q=0.4"
// -H "user-agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36"
// -H "content-type: application/json" -H "accept: application/json, text/plain, */*" -H "cache-control: no-cache"
// -H "authority: be.wizzair.com" -H "cookie: __gfp_64b=v1ZwjWFMy.S2s_BKE9rLUPwt2tj_xQ.Xhm_sOInyotT.37; ASP.NET_SessionId=0ejkw1kvwhesad5c1jekl05f; _ga=GA1.2.831145438.1445423299; _gat=1"
// -H "referer: https://wizzair.com/hu-HU/main-page"
// --data-binary "{""flightList"":[{""departureStation"":""GYD"",""arrivalStation"":""BUD"",""departureDate"":""2016-09-24""}],""adultCount"":1,""childCount"":0,""infantCount"":0,""wdc"":true}" --compressed