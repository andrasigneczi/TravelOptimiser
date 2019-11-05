package PageGuest;

import Util.DCHttpClient;
import Util.WizzairHelper;
import org.openqa.selenium.*;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.chrome.ChromeDriver;

import QueueHandlers.JMSStack;
import QueueHandlers.LocalStack;
import QueueHandlers.ResultQueue;
import Configuration.Configuration;
import Util.StringHelper;
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

import static Util.CurrencyHelper.ConvertFrom3Digits;
import static Util.DatetimeHelper.FormatDate;

import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class WizzAirPageGuest201911 extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest201911.class);

	private long mTimeoutStart;
	private static String mApiSearchUrl = "https://be.wizzair.com/9.0.0/Api/search/search";
	private static String mHeader = "origin: https://wizzair.com\naccept-encoding: gzip, deflate, br\naccept-language: en-US,en;q=0.9,hu;q=0.8\nuser-agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\ncontent-type: application/json;charset=UTF-8\naccept: application/json, text/plain, */*\nreferer: https://wizzair.com/\nauthority: be.wizzair.com";
	private WebDriver driver = null;
	private Integer mEventCounter = 0;

	public void Init() throws Exception
	{
		InitJMS();

		/* close event from the browser
		frame.addWindowListener(new WindowAdapter()
		{
			@Override
			public void windowClosing(WindowEvent e)
			{
				mLogger.info( "Window is closing" );
				mThreadStopped = true;
				e.getWindow().dispose();
			}
		});*/

		driver = new ChromeDriver();
		driver.get("https://wizzair.com");
		WebDriverWait wait = new WebDriverWait(driver, 15);
		wait.until(webDriver -> ((JavascriptExecutor) driver).executeScript("return document.readyState").toString().equals("complete"));
		Thread.sleep(4000);  // Just to be sure! May crash occur wothout this sleep.

		String lApiVersion = WizzairHelper.getApiVersion(driver);
		mLogger.info("Wizzair Api version: " + lApiVersion);
		mApiSearchUrl = "https://be.wizzair.com/" + lApiVersion + "/Api/search/search";

		FillTheFormWithDummy();
		DoSearchFromConfig();
		synchronized (mMutex) { ++mEventCounter; }
	}
/*
	public class BrowserPopupHandler implements PopupHandler {
		private WizzAirPageGuest201911 mGuest;
		public BrowserPopupHandler( WizzAirPageGuest201911 guest )
		{
			mGuest = guest;
		}
		public PopupContainer handlePopup(PopupParams params) {
			return new PopupContainer() {
				public void insertBrowser(final Browser browser, final Rectangle initialBounds) {
					SwingUtilities.invokeLater(new Runnable() {
						@Override
						public void run() {
							mBrowser2 = browser;
							//mBrowser2.addLoadListener(new BrowserLoadAdapter( mGuest ));
							BrowserView popupView = new BrowserView(browser);
							popupView.setPreferredSize(new Rectangle(800,800).getSize());

							final JFrame popupFrame = new JFrame("Popup");
							popupFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
							popupFrame.add(popupView, BorderLayout.CENTER);
							popupFrame.pack();
							popupFrame.setLocation(new Rectangle( 800, 0, 0, 0 ).getLocation());
							popupFrame.setVisible(true);
							popupFrame.addWindowListener(new WindowAdapter() {
								@Override
								public void windowClosing(WindowEvent e) {
									browser.dispose();
								}
							});

							browser.addDisposeListener(new DisposeListener<Browser>() {
								public void onDisposed(DisposeEvent<Browser> event) {
									popupFrame.setVisible(false);
								}
							});
						}
					});
				}
			};
		}
	}
*/
	public WizzAirPageGuest201911()
	{
		super("wizzair", "https://wizzair.com");
		mSearchQueue = new LocalStack<>();
		mThread = new Thread(this);
		mThread.setName("WizzAirThread201812 " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();
	}
/*
	public class BrowserLoadAdapter extends LoadAdapter
	{
		private WizzAirPageGuest201911 mGuest;
		public BrowserLoadAdapter( WizzAirPageGuest201911 guest )
		{
			mGuest = guest;
		}

		@Override
		public void onStartLoadingFrame(StartLoadingEvent event) {
			if (event.isMainFrame()) {
				//System.out.println("Main frame has started loading");
			}
		}

		@Override
		public void onProvisionalLoadingFrame(ProvisionalLoadingEvent event) {
			if (event.isMainFrame()) {
				//System.out.println("Provisional load was committed for a frame");
			}
		}

		@Override
		public void onFinishLoadingFrame(FinishLoadingEvent event) {
			// A click után újra bejövök ide, erre ügyelni kell!!!!
			synchronized( this )
			{
				if( event.isMainFrame())
				{
					mLogger.trace( "Main frame has finished loading, status: " + mEventCounter);
					boolean search = false;
					synchronized (mMutex)
					{
						if( mEventCounter == 0 )
							search = true;
					}
					if(search)
					{
							Sleep( 2000 );
							// I don't need the first submit's result!
							//mGuest.mainFrameLoaded( event.getBrowser().getHTML() );
							mGuest.DoSearchFromConfig();
					}
					synchronized (mMutex)
					{
						++mEventCounter;
					}
				}
			}
		}

		@Override
		public void onFailLoadingFrame(FailLoadingEvent event) {
			NetError errorCode = event.getErrorCode();
			if (event.isMainFrame()) {
				mLogger.error("Main frame has failed loading: " + errorCode);
			}
		}

		@Override
		public void onDocumentLoadedInFrame(FrameLoadEvent event) {
		}

		@Override
		public void onDocumentLoadedInMainFrame(LoadEvent event) {
			//System.out.println("Main frame document is loaded.");
		}

	}
*/
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
			ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchListAirlines();
			for (TravelData_INPUT lTDI : lSearchList)
			{
				if (!lTDI.mAirline.equalsIgnoreCase(getAirline()))
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
			mSearchQueue = new JMSStack<>();
			mSearchQueue.setQueueName( getAirline() );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
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

			if( lBundle.equalsIgnoreCase( "BASIC" ))
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
/*
	class MainFrameCallback implements com.teamdev.jxbrowser.chromium.Callback<Browser>
	{
		private String mApiSearchUrl;
		private String mParameters;
		private String mHeader;
		public MainFrameCallback(String apiSearchUrl, String parameters, String header)
		{
			mApiSearchUrl = apiSearchUrl;
			mParameters   = parameters;
			mHeader       = header;
		}

		@Override
		public void invoke( Browser browser )
		{
			// POST to the wizzair API
	        browser.loadURL( new LoadURLParams(
	                mApiSearchUrl,
	                mParameters,
	                mHeader
	        ));
		}
	}
*/
	private void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException, InterruptedException {
		mLogger.trace( "begin, thread name: " + getThreadName());

		String lParameters = "";
		if( aTravelDataInput.mReturnTicket )
		{
			// {"isFlightChange":false,"isSeniorOrStudent":false,"flightList":[{"departureStation":"VIE","arrivalStation":"NCE","departureDate":"2018-12-17"},{"departureStation":"NCE","arrivalStation":"VIE","departureDate":"2019-01-14"}],"adultCount":1,"childCount":0,"infantCount":0,"wdc":true}
			lParameters = "{\"flightList\":[{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"departureDate\":\""
					+ FormatDate( aTravelDataInput.mDepartureDay ) + "\"},{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"departureDate\":\"" + FormatDate(
					aTravelDataInput.mReturnDay )
					+ "\"}],\"adultCount\":" + aTravelDataInput.mAdultNumber + ",\"childCount\":"
					+ aTravelDataInput.mChildNumber + ",\"infantCount\":" + aTravelDataInput.mInfantNumber
					+ ",\"isFlightChange\": false, \"isSeniorOrStudent\": false"
					+ ",\"wdc\":true}";
		}
		else
		{
			// {"isFlightChange":false,"isSeniorOrStudent":false,"flightList":[{"departureStation":"TIA","arrivalStation":"BUD","departureDate":"2019-01-08"}],"adultCount":1,"childCount":0,"infantCount":0,"wdc":true}
			lParameters = "{\"flightList\":[{\"departureStation\":\""
					+ aTravelDataInput.mAirportCode_LeavingFrom + "\",\"arrivalStation\":\""
					+ aTravelDataInput.mAirportCode_GoingTo + "\",\"departureDate\":\""
					+ FormatDate( aTravelDataInput.mDepartureDay ) + "\"}],\"adultCount\":" + aTravelDataInput.mAdultNumber + ",\"childCount\":"
					+ aTravelDataInput.mChildNumber + ",\"infantCount\":" + aTravelDataInput.mInfantNumber
					+ ",\"isFlightChange\": false, \"isSeniorOrStudent\": false"
					+ ",\"wdc\":true}";
		}

		//System.out.println( mApiSearchUrl + "\n" + lParameters );
		DCHttpClient dcHttpClient = new DCHttpClient();

		String strResponse = "";
		dcHttpClient.addProperties("origin", "https://wizzair.com");
		dcHttpClient.addProperties("accept-encoding", "gzip, deflate, br");
		dcHttpClient.addProperties("accept-language", "en-US,en;q=0.9,hu;q=0.8");
		dcHttpClient.addProperties("user-agent", "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36");
		dcHttpClient.addProperties("content-type", "application/json;charset=UTF-8");
		dcHttpClient.addProperties("accept", "application/json, text/plain, */*");
		dcHttpClient.addProperties("referer", "https://wizzair.com/");
		dcHttpClient.addProperties("authority", "be.wizzair.com");

		// copy cookies from browser
		/*
		Set<Cookie> allCookies = driver.manage().getCookies();
		String cookies = "";
		for(Cookie cookie : allCookies) {
			if(cookies.length() > 0) {
				cookies += ";";
			}
			cookies += cookie.toString();
		}

		if(cookies.length() > 0) {
			dcHttpClient.addProperties("Cookie", cookies);
		}
		*/
		for( int i = 0; i < 3; i++ )
		{
			try
			{
				strResponse = dcHttpClient.sendPost( mApiSearchUrl, lParameters );
				if( dcHttpClient.getResponseCode() != 404 && strResponse.length() > 0 ) {
				}
				break;
			}
			catch( Exception e )
			{
				mLogger.error( "WizzAirPageGuest201911(" + i + "): " + StringHelper.getTraceInformation( e ));
				if( i == 2 )
					throw e;
			}
			Sleep( 1000 );
		}

		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirline = aTravelDataInput.mAirline;
		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
		mTravelDataResult.mTravelDataInput = aTravelDataInput;

		Pattern reg = Pattern.compile( "\\{.*\\}" );
		Matcher m = reg.matcher( strResponse );
		String lJson = "";
		if( m.find() )
		{
			lJson = m.group(0).toString().trim();
		}

		mLogger.trace( strResponse );
		//DOMElement pre = mBrowser.getDocument().findElement( By.tagName( "pre" ));
		ParseTheResponse(lJson);
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void FillTheFormWithDummy() throws InterruptedException {
		mLogger.trace( "begin, thread name: " + getThreadName());
		WebElement departureBox = driver.findElement(By.id("search-departure-station"));
		departureBox.click();
		Thread.sleep(1000);

		departureBox.sendKeys("Budapest");
		Thread.sleep(2000);

		WebElement value0 = driver.findElement(By.xpath( "//*[@id=\"flight-search\"]/div/div/div[2]/form/div[1]/fieldset/div[3]/div/div[3]/div[1]/label" ));
		value0.click();
		Thread.sleep(1000);

		WebElement arrivalBox = driver.findElement(By.id("search-arrival-station"));
		arrivalBox.click();
		Thread.sleep(1000);

		arrivalBox.sendKeys("Charleroi");
		Thread.sleep(2000);

		value0.click();
		Thread.sleep(2000);

		WebElement searchButton = driver.findElement(By.xpath( "//*[@id=\"flight-search\"]/div/div/div[2]/form/div[3]/button" ));
		searchButton.click();
		// the wait.until doesn't work here, it's a complex page, and slow with the booking at the same time
		Thread.sleep(60000);

		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void clickLeftArrow() throws InterruptedException {
		mLogger.trace( "begin, thread name: " + getThreadName());

		ArrayList tabs = new ArrayList (driver.getWindowHandles());
		driver.switchTo().window(tabs.get(tabs.size() - 1).toString());
		Thread.sleep(2000);

		WebElement rightArrow = driver.findElement( By.xpath( "//*[@id=\"outbound-fare-selector\"]/div[2]/div[1]/button[2]" ));

		if( rightArrow  != null ) {rightArrow.click();}
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
					if(mEventCounter < 1)
						continue;

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
					//mEventCounter = 10;
					clickLeftArrow();
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

				String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
				Sleep( 1000 * Integer.parseInt( lSleep ));
				mTimeoutStart = System.currentTimeMillis();
			}
			System.out.println("run()");
		}
		catch (Exception e)
		{
			mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
		}
		driver.quit();
	}
}


// curl 'https://be.wizzair.com/9.0.1/Api/search/search' -H 'origin: https://wizzair.com' -H 'accept-encoding: gzip, deflate, br' 
// -H 'accept-language: en-US,en;q=0.9,hu;q=0.8' 
// -H 'user-agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36' 
// -H 'content-type: application/json;charset=UTF-8' -H 'accept: application/json, text/plain, */*' -H 'referer: https://wizzair.com/' 
// -H 'authority: be.wizzair.com'  
// --data-binary '{"isFlightChange":false,"isSeniorOrStudent":false,"flightList":[{"departureStation":"TIA","arrivalStation":"BUD","departureDate":"2019-01-08"}],"adultCount":1,"childCount":0,"infantCount":0,"wdc":true}' 
// --compressed

// response on 26.03.2019
// {"outboundFlights":[{"departureStation":"BUD","arrivalStation":"CRL","carrierCode":"W6","flightNumber":"2281","flightSellKey":"W6~2281~ ~~BUD~07/08/2019 06:15~CRL~07/08/2019 08:10~","departureDateTime":"2019-07-08T06:15:00","arrivalDateTime":"2019-07-08T08:10:00","fares":[{"fareSellKey":"0~IW~~IWZZC~WZZC~~9~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":25790.0,"currencyCode":"HUF"},"discountedPrice":{"amount":25790.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":25790.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":23190.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":25790.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":23190.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":25790.0,"currencyCode":"HUF"}},"bundle":"basic","fareDiscountType":"none","wdc":true,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~IW~~IWZZC~WZZC~~9~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":35695.0,"currencyCode":"HUF"},"discountedPrice":{"amount":35695.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":44540.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":23190.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":35695.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":33095.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":35695.0,"currencyCode":"HUF"}},"bundle":"middle","fareDiscountType":"none","wdc":true,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~IW~~IWZZC~WZZC~~9~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":41630.0,"currencyCode":"HUF"},"discountedPrice":{"amount":41630.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":53640.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":23190.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":41630.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":39030.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":41630.0,"currencyCode":"HUF"}},"bundle":"plus","fareDiscountType":"none","wdc":true,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~I~~IREG~REG1~~7~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":28690.0,"currencyCode":"HUF"},"discountedPrice":{"amount":28690.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":28690.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":26090.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":28690.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":26090.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":28690.0,"currencyCode":"HUF"}},"bundle":"basic","fareDiscountType":"none","wdc":false,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~I~~IREG~REG1~~7~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":39610.0,"currencyCode":"HUF"},"discountedPrice":{"amount":39610.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":47440.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":26090.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":39610.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":37010.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":39610.0,"currencyCode":"HUF"}},"bundle":"middle","fareDiscountType":"none","wdc":false,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~I~~IREG~REG1~~7~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":45400.0,"currencyCode":"HUF"},"discountedPrice":{"amount":45400.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":56540.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":26090.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":45400.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":42800.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":45400.0,"currencyCode":"HUF"}},"bundle":"plus","fareDiscountType":"none","wdc":false,"availableCount":6,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}}],"infantLimitExceeded":{"limitExceeded":false,"isBlocking":true},"wheelchairLimitExceeded":{"unavailableCount":0,"limitExceeded":false,"isBlocking":false},"oxyLimitExceeded":{"limitExceeded":false,"isBlocking":true},"sportsEquipmentLimitExceeded":{"unavailableCount":0,"limitExceeded":false,"isBlocking":false},"isRequest":false,"ePie":true,"isLease":false,"duration":"01:55:00"},{"departureStation":"BUD","arrivalStation":"CRL","carrierCode":"W6","flightNumber":"2283","flightSellKey":"W6~2283~ ~~BUD~07/08/2019 18:50~CRL~07/08/2019 20:55~","departureDateTime":"2019-07-08T18:50:00","arrivalDateTime":"2019-07-08T20:55:00","fares":[{"fareSellKey":"0~GFW~~GFWZZC~WZZC~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":38545.0,"currencyCode":"HUF"},"discountedPrice":{"amount":38545.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":38545.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":35945.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":38545.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":35945.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":38545.0,"currencyCode":"HUF"}},"bundle":"basic","fareDiscountType":"none","wdc":true,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~GFW~~GFWZZC~WZZC~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":48450.0,"currencyCode":"HUF"},"discountedPrice":{"amount":48450.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":57295.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":35945.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":48450.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":45850.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":48450.0,"currencyCode":"HUF"}},"bundle":"middle","fareDiscountType":"none","wdc":true,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~GFW~~GFWZZC~WZZC~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":54385.0,"currencyCode":"HUF"},"discountedPrice":{"amount":54385.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":66395.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":35945.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":54385.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":51785.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":54385.0,"currencyCode":"HUF"}},"bundle":"plus","fareDiscountType":"none","wdc":true,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~GF~~GFREG~REG1~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":44345.0,"currencyCode":"HUF"},"discountedPrice":{"amount":44345.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":44345.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":41745.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":44345.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":41745.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":44345.0,"currencyCode":"HUF"}},"bundle":"basic","fareDiscountType":"none","wdc":false,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~GF~~GFREG~REG1~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":55265.0,"currencyCode":"HUF"},"discountedPrice":{"amount":55265.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":63095.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":41745.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":55265.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":52665.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":55265.0,"currencyCode":"HUF"}},"bundle":"middle","fareDiscountType":"none","wdc":false,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}},{"fareSellKey":"0~GF~~GFREG~REG1~~2~X","administrationFeePrice":{"amount":2600.0,"currencyCode":"HUF"},"basePrice":{"amount":61055.0,"currencyCode":"HUF"},"discountedPrice":{"amount":61055.0,"currencyCode":"HUF"},"fullBasePrice":{"amount":72195.0,"currencyCode":"HUF"},"discountedFarePrice":{"amount":41745.0000,"currencyCode":"HUF"},"discountedPriceWithoutFamilyDiscount":{"amount":61055.0,"currencyCode":"HUF"},"flightChangeFeePrice":{"code":null,"amount":0.0,"currencyCode":"HUF"},"fareLockPrice":{"amount":950.0,"currencyCode":"HUF"},"flightPriceDetail":{"discountRate":0.0,"discountPrice":{"amount":0.0,"currencyCode":"HUF"},"price":{"amount":58455.0,"currencyCode":"HUF"},"fees":[{"included":false,"specificType":"administration","displayCount":1,"price":{"amount":2600.0,"currencyCode":"HUF"},"promotedPrice":null,"order":0,"code":"ADM"}],"displayCount":1,"total":{"amount":61055.0,"currencyCode":"HUF"}},"bundle":"plus","fareDiscountType":"none","wdc":false,"availableCount":3,"distributionFeePrice":{"amount":0.0,"currencyCode":"HUF"},"isFamily":false,"soldOut":false,"groupAdministrationFeePrice":{"amount":0.0,"currencyCode":"HUF"}}],"infantLimitExceeded":{"limitExceeded":false,"isBlocking":true},"wheelchairLimitExceeded":{"unavailableCount":0,"limitExceeded":false,"isBlocking":false},"oxyLimitExceeded":{"limitExceeded":false,"isBlocking":true},"sportsEquipmentLimitExceeded":{"unavailableCount":0,"limitExceeded":false,"isBlocking":false},"isRequest":false,"ePie":true,"isLease":false,"duration":"02:05:00"}],"returnFlights":null,"outboundBundles":[{"code":"basic","ancillaryServices":["bundle-ancillary-carry-on-bag","bundle-ancillary-2-day-check-in-window"],"fareLockFeeCode":"FLBS"},{"code":"middle","ancillaryServices":["bundle-ancillary-carry-on-bag","bundle-ancillary-trolley-bag","bundle-ancillary-ultralight-checked-in-baggage","bundle-ancillary-seat-selection","bundle-ancillary-priority-boarding","bundle-ancillary-priority-check-in","bundle-ancillary-30-day-check-in-window","bundle-ancillary-airport-check-in"],"fareLockFeeCode":"FLGO"},{"code":"plus","ancillaryServices":["bundle-ancillary-carry-on-bag","bundle-ancillary-trolley-bag","bundle-ancillary-ultralight-checked-in-baggage","bundle-ancillary-seat-selection","bundle-ancillary-priority-boarding","bundle-ancillary-priority-check-in","bundle-ancillary-wizz-flex","bundle-ancillary-30-day-check-in-window","bundle-ancillary-airport-check-in","bundle-ancillary-flightinformation","bundle-ancillary-wizz-account-refund"],"fareLockFeeCode":"FLPL"}],"returnBundles":null,"currencyCode":"HUF","arrivalStationCurrencyCode":"EUR","isDomestic":false,"isGroup":false,"discountType":"none","discountPercentage":0.0,"bookingCurrencyRenewalPrice":null,"var99":false}
// expected keywords: outboundFlights, returnFlights, departureDateTime, arrivalDateTime, fares, BASIC, currencyCode, amount, discountedPrice, wdc, bundle
