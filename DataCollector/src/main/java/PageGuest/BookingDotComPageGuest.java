package PageGuest;

import Configuration.Configuration;
import Util.CurrencyHelper;
import Util.DatetimeHelper;
import com.teamdev.jxbrowser.chromium.*;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.dom.internal.MouseEvent;
import com.teamdev.jxbrowser.chromium.events.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import static Util.StringHelper.escapeXML;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

import java.util.*;
import java.util.logging.Level;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 15/03/2016.
 */

// TODO: filter: shared something(bathroom); size (10m2); review score (8+); exclude solde out;
// cheapest properties first

public class BookingDotComPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(BookingDotComPageGuest.class);

	private static boolean mSTOP_AT_THE_FIRST_PAGE = false;

	private Browser mBrowser = null;
	private BrowserView mBrowserView = null;
	private JTabbedPane mTabbedPane = null;

	private long mTimeoutStart;
	private boolean mThreadStopped = true;
	private DOMDocument mDOMDocument;
	private BookingDotComStatus mStatus = new BookingDotComStatus();

	private AccomodationData_INPUT mADI;
	private ArrayList<AccomodationData_RESULT> mAccomodationDataResults = new ArrayList<>(  );
	private int mLastOpenedAccomodation = -1;

	private ArrayList<AccomodationData_INPUT> mInputList = new ArrayList<>();
	private int mInputListIndex = -1;

	private String[] mFilters = null;
	private int mFilterIndex = -1;

	private Integer mLoadReadyTimeout = -1;
	private boolean mSeparatorFound = false;
	private HashSet<String> mHotelNames = new HashSet<>(  );
	boolean mCheckinNoTillLimitation = false;

	private String mSearchURL = "https://www.booking.com/searchresults.en-gb.html?&" +
			"lang=en-gb&sid=[SID]&sb=1&src=index&src_elem=sb&" +
			"ss=[SS]&ssne=Cegl%C3%A9d&ssne_untouched=Cegl%C3%A9d&checkin_monthday=[CHECKIN_MONTHDAY]&checkin_month=[CHECKIN_MONTH]&checkin_year=[CHECKIN_YEAR]&checkout_monthday=[CHECKOUT_MONTHDAY]&checkout_month=[CHECKOUT_MONTH]&checkout_year=[CHECKOUT_YEAR]&" +
			"sb_travel_purpose=[TRAVEL_PURPOSE]&room1=[ROOM1]&no_rooms=[NO_ROOMS]&group_adults=[GROUP_ADULTS]&group_children=[GROUP_CHILDREN][CHILDREN_AGES]&" +
			"ac_position=0&ac_langcode=en&ddest_type=city&search_pageview_id=15523d122cec0313&search_selected=true&" +
			"ac_suggestion_list_length=5&ac_suggestion_theme_list_length=0";

	class FilterAttribs {
		public FilterAttribs( String name, String value )
		{
			mName = name;
			mValue = value;
		}
		public String mName;
		public String mValue;
	}
	private HashMap<String,FilterAttribs> mFilterMap = new HashMap<>(  );

	public class BrowserLoadAdapter extends LoadAdapter
	{
		private BookingDotComPageGuest mGuest;
		public BrowserLoadAdapter( BookingDotComPageGuest guest )
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
					//System.out.println( "Main frame has finished loading, status: " + mGuest.mStatus.getStatus());
					if( !mSTOP_AT_THE_FIRST_PAGE )
						mGuest.mStatus.mainFrameLoaded( mGuest, event.getBrowser().getDocument());
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
			synchronized( mLoadReadyTimeout )
			{
				mLoadReadyTimeout = 50;
			}
//			if(( mGuest.mStatus.getStatus() == BookingDotComStatus.Status.NEXT_PAGE_LOADING /*||
//				 mGuest.mStatus.getStatus() == BookingDotComStatus.Status.APPLYING_A_FILTER*/ )
//					&& mGuest.isResultPage( event.getBrowser().getDocument()))
//			{
//				System.out.println("Frame document is loaded, status: " + mGuest.mStatus.getStatus());
//				mGuest.mStatus.mainFrameLoaded( mGuest, event.getBrowser().getDocument());
//			}
		}

		@Override
		public void onDocumentLoadedInMainFrame(LoadEvent event) {
			//System.out.println("Main frame document is loaded.");
		}

	}

	public void Init()
	{
		DoSearchFromConfig();
		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		mTabbedPane = new JTabbedPane();
		JFrame frame = new JFrame( "Travel Optimizer - Booking.com - jxBrowser " + ProductInfo.getVersion());
		//frame.setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );

		frame.addWindowListener(new WindowAdapter()
		{
			@Override
			public void windowClosing(WindowEvent e)
			{
				mLogger.info( "Window is closing" );
				mThreadStopped = true;
				e.getWindow().dispose();
			}
		});

		frame.getContentPane().add( mTabbedPane, BorderLayout.CENTER );
		frame.setSize( 1152, 964 );
		//frame.setLocationRelativeTo( null );
		frame.setLocation( 50, 50 );
		frame.setVisible( true );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser( "Booking.com" );

		boolean lNewWindow = false;

		mBrowserView = new BrowserView( mBrowser );
		//String remoteDebuggingURL = mBrowser.getRemoteDebuggingURL();

		mBrowserView.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked( java.awt.event.MouseEvent e) {
				//System.out.println("e = " + e);
				//System.out.println( "x:" + e.getXOnScreen() + "; y:" + e.getYOnScreen());
			}
		});


		mBrowserView.addMouseMotionListener(new MouseAdapter() {
			@Override
			public void mouseMoved( java.awt.event.MouseEvent e) {
				//System.out.println("e = " + e);
				//System.out.println( "x:" + e.getXOnScreen() + "; y:" + e.getYOnScreen());
			}
		});

		mTabbedPane.addTab( "Browser", mBrowserView );
		//mBrowser.addLoadListener( new WizzAirPageGuest_LoadListener(this));
		mBrowser.addLoadListener(new BrowserLoadAdapter( this ));
		//mBrowser.loadURL( "http://localhost:9222");



		// Creates another Browser instance and loads the remote Developer
		// Tools URL to access HTML inspector.
//		Browser browser2 = TeamDevJxBrowser.getInstance().getJxBrowser( "Booking.com debug" );
//		BrowserView browserView2 = new BrowserView(browser2);
//
//		JFrame frame2 = new JFrame();
//		frame2.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//		frame2.add(browserView2, BorderLayout.CENTER);
//		frame2.setSize(700, 500);
//		frame2.setLocationRelativeTo(null);
//		frame2.setVisible(true);
//
//		browser2.loadURL(remoteDebuggingURL);

		mFilterMap.put( "price_0-50",    new FilterAttribs( "data-id", "pri-1"));
		mFilterMap.put( "price_50-100",  new FilterAttribs( "data-id", "pri-2") );
		mFilterMap.put( "price_100-150", new FilterAttribs( "data-id", "pri-3") );
		mFilterMap.put( "price_150-200", new FilterAttribs( "data-id", "pri-4") );
		mFilterMap.put( "price_200+",    new FilterAttribs( "data-id", "pri-5") );

		mFilterMap.put( "checkin_no_till_limit", new FilterAttribs( "", "" ));
		mFilterMap.put( "apartments",            new FilterAttribs( "data-id", "ht_id-201" ));
		mFilterMap.put( "hotels",                new FilterAttribs( "data-id", "ht_id-204" ));
		mFilterMap.put( "free_wifi",             new FilterAttribs( "data-id", "hotelfacility-107" ));
		mFilterMap.put( "parking_place",         new FilterAttribs( "data-id", "hotelfacility-2" ));
		mFilterMap.put( "free_cancellation",     new FilterAttribs( "data-id", "fc-1" ));
		mFilterMap.put( "24h_reception",         new FilterAttribs( "data-id", "hr_24-8" ));
		mFilterMap.put( "private_bathroom",      new FilterAttribs( "data-id", "roomfacility-800038" ));

		mFilterMap.put( "score_9+", new FilterAttribs( "data-id", "review_score-90" ));
		mFilterMap.put( "score_8+", new FilterAttribs( "data-id", "review_score-80" ));
		mFilterMap.put( "score_7+", new FilterAttribs( "data-id", "review_score-70" ));
		mFilterMap.put( "score_6+", new FilterAttribs( "data-id", "review_score-60" ));
		mFilterMap.put( "score_no", new FilterAttribs( "data-id", "review_score-999" ));

		mFilterMap.put( "exclude_sold_out", new FilterAttribs( "data-id", "oos-1" ));


		startANewSearch();
	}

	public void startANewSearch()
	{
		mStatus.starting( this );
		mBrowser.loadURL( getURL());
	}

	public BookingDotComPageGuest()
	{
		super( null, "https://www.booking.com" );
		//super( null, "http://localhost:8090" );
		mThread = new Thread(this);
		mThread.setName("BookingDotComPageGuest " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
		mThread.start();
	}

	public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
	}

	public void DoSearchFromConfig()
	{
		ArrayList<AccomodationData_INPUT> lSearchList = Configuration.getInstance().getSearchListAccom();
		for( AccomodationData_INPUT lADI : lSearchList )
		{
			if( lADI.mSite != 'B' )
				continue;

			PageGuest.DateValidity lValidity = ValidateDate(lADI.mCheckIn, lADI.mCheckOut);

			if( lValidity == PageGuest.DateValidity.INVALID_COMBINATION )
			{
				mLogger.warn( "DoSearch: the departure date (" + lADI.mCheckIn + ") and/or the return date " +
						lADI.mCheckOut + " is/are invalid!" );
				continue;
			}

			if( lValidity == PageGuest.DateValidity.BOTH_OF_THEM_VALID )
			{
				mInputList.add( lADI );
			}
		}
	}

	@Override
	public void run()
	{
		mThreadStopped = false;
		while( !mThreadStopped )
		{
			try
			{
				Thread.sleep( 100 );
				synchronized( mLoadReadyTimeout )
				{
					if( mLoadReadyTimeout > 0 )
					{
						--mLoadReadyTimeout;
						if( mLoadReadyTimeout == 0 )
						{
							if( mStatus.getStatus() == BookingDotComStatus.Status.APPLYING_A_FILTER && isResultPage( mBrowser.getDocument()))
							{
								//mBrowser.saveWebPage( "filtered_result.html", "c:\\temp", SavePageType.ONLY_HTML);
								mLogger.info( "run Status: " + mStatus.getStatus());
								mStatus.mainFrameLoaded( this, mBrowser.getDocument());
							}
							else if(( mStatus.getStatus() == BookingDotComStatus.Status.NEXT_PAGE_LOADING )
									&& isResultPage( mBrowser.getDocument()))
							{
								mLogger.info("run Status: " + mStatus.getStatus());
								mStatus.mainFrameLoaded( this, mBrowser.getDocument());
							}
						}
					}
				}

			}
			catch( InterruptedException e )
			{
				e.printStackTrace();
			}
		}
	}

	private boolean setTextField( String path, String value )
	{
		DOMElement lElement = mDOMDocument.findElement( By.xpath( path ));
		if( lElement == null )
			return false;
		DOMInputElement lTextField = (DOMInputElement)lElement;
		lTextField.setValue( value );
		return true;
	}

	private boolean setSelect( String path, String value )
	{
		DOMElement lElement = mDOMDocument.findElement( By.xpath( path ));
		if( lElement == null )
			return false;
		DOMSelectElement lSelect = (DOMSelectElement)lElement;
		java.util.List<DOMOptionElement> lOptions = lSelect.getOptions();
		for( DOMOptionElement lDOMOptionElement : lOptions )
		{
			if( lDOMOptionElement.getAttribute("value").equals( value ))
			{
				lDOMOptionElement.setSelected( true );
				return true;
			}
		}
		return false;
	}

	private boolean setChecked( String path, boolean checked )
	{
		DOMElement lElement = mDOMDocument.findElement( By.xpath( path ));
		if( lElement == null )
			return false;
		DOMInputElement lRadio = (DOMInputElement)lElement;
		//lRadio.isRadioButton()
		lRadio.setChecked( checked );
		return true;
	}

	private boolean jQuerySetSelect( String id, String value )
	{
		mBrowser.executeJavaScript( "$(\"#" + id + "\").val('" + value + "').change();");
		return true;
	}

	private boolean jQuerySetSelect2( String jQuery, String value )
	{
		mBrowser.executeJavaScript( jQuery + ".val('" + value + "').change();");
		return true;
	}

	public void FillTheFormByURLPreparation( DOMDocument aDOMDocument )
	{
		Pattern lReg = Pattern.compile( "^sid: '(.+)',$", Pattern.MULTILINE );
		Matcher lMatch = lReg.matcher( aDOMDocument.getDocumentElement().getInnerHTML());
		String lSID = "_UNKNOWN_";
		while( lMatch.find() )
		{
			lSID = lMatch.group(1).toString().trim();
			mLogger.info( lSID );
		}

		String lSearchURL = mSearchURL.replace( "[SID]", lSID );

		// checkin_monthday=[CHECKIN_MONTHDAY]&checkin_month=[CHECKIN_MONTH]&checkin_year=[CHECKIN_YEAR]&checkout_monthday=[CHECKOUT_MONTHDAY]&checkout_month=[CHECKOUT_MONTH]&checkout_year=[CHECKOUT_YEAR]
		ArrayList<Integer> lDateComponents = DatetimeHelper.getDateItems( mADI.mCheckIn );
		lSearchURL = lSearchURL.replace( "[CHECKIN_MONTHDAY]", String.valueOf( lDateComponents.get( 2 )));
		lSearchURL = lSearchURL.replace( "[CHECKIN_MONTH]", String.valueOf( lDateComponents.get( 1 )));
		lSearchURL = lSearchURL.replace( "[CHECKIN_YEAR]", String.valueOf( lDateComponents.get( 0 )));

		ArrayList<Integer> lDateComponents2 = DatetimeHelper.getDateItems( mADI.mCheckOut );
		lSearchURL = lSearchURL.replace( "[CHECKOUT_MONTHDAY]", String.valueOf( lDateComponents2.get( 2 )));
		lSearchURL = lSearchURL.replace( "[CHECKOUT_MONTH]", String.valueOf( lDateComponents2.get( 1 )));
		lSearchURL = lSearchURL.replace( "[CHECKOUT_YEAR]", String.valueOf( lDateComponents2.get( 0 )));

		lSearchURL = lSearchURL.replace( "[TRAVEL_PURPOSE]", "leisure" );
		lSearchURL = lSearchURL.replace( "[NO_ROOMS]", String.valueOf( mADI.mRoomNumber ));

		lSearchURL = lSearchURL.replace( "[GROUP_ADULTS]", String.valueOf( mADI.mAdultNumber ));
		lSearchURL = lSearchURL.replace( "[GROUP_CHILDREN]", String.valueOf( mADI.mChildrenNumber ));

		String lChildrenAges = "";
		for( int i = 0; i < mADI.mChildrenAge.size(); i++ )
		{
			lChildrenAges += "&age=" + String.valueOf( mADI.mChildrenAge.get( i ));
		}
		lSearchURL = lSearchURL.replace( "[CHILDREN_AGES]", lChildrenAges );

		try
		{
			// Budapest%2C+Pest%2C+Hungary
			//lSearchURL = lSearchURL.replace( "[SS]", URLEncoder.encode( "Budapest, Pest, Hungary", "UTF-8" ));
			lSearchURL = lSearchURL.replace( "[SS]", URLEncoder.encode( mADI.mCity, "UTF-8" ));
			// A%2C11%2C8
			// room1=A%2CA%2C8%2C11
			String lRoom1 = "";
			for( int i = 0; i < mADI.mAdultNumber; i++ )
			{
				if( i > 0 )
					lRoom1 += ",";
				lRoom1 += "A";
			}
			for( int i = 0; i < mADI.mChildrenAge.size(); i++ )
			{
				if( i > 0 )
					lRoom1 += ",";
				lRoom1 += mADI.mChildrenAge.get( i );
			}

			lSearchURL = lSearchURL.replace( "[ROOM1]", URLEncoder.encode( lRoom1, "UTF-8" ));
			mLogger.info( lSearchURL );
		}
		catch( UnsupportedEncodingException e )
		{
			e.printStackTrace();
		}

		if( mADI.mFilters != null && mADI.mFilters.length() > 0 )
		{
			mFilters = mADI.mFilters.split("\\,", 0 );
			mFilterIndex = -1;
		}

		mBrowser.loadURL( lSearchURL );

		// https://www.booking.com/searchresults.en-gb.html?label=gen173nr-1FCAEoggJCAlhYSDNiBW5vcmVmaGeIAQGYAS7CAQp3aW5kb3dzIDEwyAEM2AEB6AEB-AELkgIBeagCAw&
		// lang=en-gb&sid=0f4b4bdf3191a7a580feb8b757e70fa4&sb=1&src=index&src_elem=sb&
		// error_url=https%3A%2F%2Fwww.booking.com%2Findex.en-gb.html%3Flabel%3Dgen173nr-1FCAEoggJCAlhYSDNiBW5vcmVmaGeIAQGYAS7CAQp3aW5kb3dzIDEwyAEM2AEB6AEB-AELkgIBeagCAw%3Bsid%3D0f4b4bdf3191a7a580feb8b757e70fa4%3Bsb_price_type%3Dtotal%26%3B&
		// ss=Budapest%2C+Pest%2C+Hungary&ssne=Cegl%C3%A9d&ssne_untouched=Cegl%C3%A9d&checkin_monthday=[CHECKIN_MONTHDAY]&checkin_month=[CHECKIN_MONTH]&checkin_year=[CHECKIN_YEAR]&
		// checkout_monthday=[CHECKOUT_MONTHDAY]&checkout_month=[CHECKOUT_MONTH]&checkout_year=[CHECKOUT_YEAR]&sb_travel_purpose=leisure&room1=A%2C11%2C8&no_rooms=2&group_adults=1&group_children=2&
		// age=11&age=8&ss_raw=Buda&ac_position=0&ac_langcode=en&dest_id=-850553&dest_type=city&search_pageview_id=15523d122cec0313&
		// search_selected=true&search_pageview_id=15523d122cec0313&ac_suggestion_list_length=5&ac_suggestion_theme_list_length=0
	}

	public void FillTheFormByRobot()
	{
		// destination
		MouseLeftClick( 120, 440 );
		Sleep( 500 );
		PressCtrlA();
		Sleep( 500 );
		PressDelete();
		Sleep( 500 );
		//TypeText( "Budapest, Pest, Hungary" );
		TypeText( mADI.mCity );
		Sleep( 5000 ); // lassú internetnél jobb mint 1000
		PressDown();
		Sleep( 1000 );
		TypeText( "\n" );
		Sleep( 1000 );
		TypeText( "\t" );
		Sleep( 1000 );

		// check-in
		//TypeText( "24072017\t" );
		//System.out.println( mADI.mCheckIn );
		TypeText( DatetimeHelper.ReverseDate( mADI.mCheckIn ) + "\t" );
		Sleep( 1000 );

		// check-out
		//TypeText( "01082017\t" );
		//System.out.println( mADI.mCheckOut );
		TypeText( DatetimeHelper.ReverseDate( mADI.mCheckOut ) + "\t" );
		Sleep( 1000 );

		// travelling for leisure radio
		if( !setChecked( "//*[@id=\"frm\"]/div[3]/div/div/fieldset/label[2]/input", true ))
			setChecked( "//*[@id=\"frm\"]/div[4]/div/div/fieldset/label[2]/input", true );

		Sleep( 1000 );

		// rooms select
		jQuerySetSelect( "no_rooms", String.valueOf( mADI.mRoomNumber ));

		Sleep( 1000 );

		// adults select
		jQuerySetSelect( "group_adults", String.valueOf( mADI.mAdultNumber ));

		Sleep( 1000 );

		// children select
		//setSelect( "//*[@id=\"group_children\"]", "4" );
		jQuerySetSelect( "group_children", String.valueOf( mADI.mChildrenNumber ));

		Sleep( 1000 );


		for( int i = 0; i < mADI.mChildrenAge.size(); i++ )
		{
			jQuerySetSelect2( "$('[data-group-child-age=\"" + i + "\"]')", String.valueOf( mADI.mChildrenAge.get( i )));
			Sleep( 1000 );
		}

//		// age1
//		jQuerySetSelect2( "$('[data-group-child-age=\"0\"]')", "8" );
//
//		Sleep( 1000 );
//
//		// age2
//		jQuerySetSelect2( "$('[data-group-child-age=\"1\"]')", "11" );
//		//jQuerySetSelect2( "$('[data-group-child-age=\"2\"]')", "10" );
//		//jQuerySetSelect2( "$('[data-group-child-age=\"3\"]')", "9" );
//		Sleep( 1000 );

		// search button xpath
		//DOMElement lElement = mDOMDocument.findElement( By.xpath( "" ));
		//if( lElement != null )
		//	lElement.click();

		if( mADI.mFilters != null && mADI.mFilters.length() > 0 )
		{
			mFilters = mADI.mFilters.split("\\,", 0 );
			mFilterIndex = -1;
		}

		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').click();" );
		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').submit();" );
		MouseLeftClick( 120, 440 );
		Sleep( 500 );
		TypeText( "\n" );
		Sleep( 1000 );
	}

	public void FillTheFormByJQuery()
	{
		// mukodik
		//mBrowser.executeJavaScript( "$(\"#frm\").submit();");

		// mukodik
		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').click();" );

		//mBrowser.executeJavaScript( "$(\"#ss\").val(\"Moscow, Russia\").change();");
		mBrowser.executeJavaScript( "$(\"#ss\").val(\"" + mADI.mCity + "\").change();");

		String[] dateA = mADI.mCheckIn.split("\\.", 0 );
		mBrowser.executeJavaScript( "$('[name=\"checkin_monthday\"]').val(\"" + dateA[2] + "\").change();");
		mBrowser.executeJavaScript( "$('[name=\"checkin_month\"]').val(\"" + dateA[1] + "\").change();");
		mBrowser.executeJavaScript( "$('[name=\"checkin_year\"]').val(\"" + dateA[0] + "\").change();");

		dateA = mADI.mCheckOut.split("\\.", 0 );
		mBrowser.executeJavaScript( "$('[name=\"checkout_monthday\"]').val(\"" + dateA[2] + "\").change();");
		mBrowser.executeJavaScript( "$('[name=\"checkout_month\"]').val(\"" + dateA[1] + "\").change();");
		mBrowser.executeJavaScript( "$('[name=\"checkout_year\"]').val(\"" + dateA[0] + "\").change();");



		// travelling for leisure radio
		mBrowser.executeJavaScript( "$('[name=\"sb_travel_purpose\"]').attr('checked', true);");
		//[0].checked = true
		//.attr('checked', true);
		//.prop('checked', true);

		Sleep( 2000 );

		// rooms select
		jQuerySetSelect( "no_rooms", String.valueOf( mADI.mRoomNumber ));

		Sleep( 2000 );

		// adults select
		jQuerySetSelect( "group_adults", String.valueOf( mADI.mAdultNumber ));

		Sleep( 2000 );

		// children select
		//setSelect( "//*[@id=\"group_children\"]", "4" );
		jQuerySetSelect( "group_children", String.valueOf( mADI.mChildrenNumber ));

		Sleep( 2000 );


		for( int i = 0; i < mADI.mChildrenAge.size(); i++ )
		{
			jQuerySetSelect2( "$('[data-group-child-age=\"" + i + "\"]')", String.valueOf( mADI.mChildrenAge.get( i )));
			Sleep( 1000 );
		}

		if( mADI.mFilters != null && mADI.mFilters.length() > 0 )
		{
			mFilters = mADI.mFilters.split("\\,", 0 );
			mFilterIndex = -1;
		}

		mBrowser.executeJavaScript( "$(\"#frm\").submit();");
	}

	// DEVEL
	public void FillTheForm( DOMDocument aDOMDocument )
	{
		//System.out.println( "FillTheForm: " + mInputListIndex + "; mInputList.size: " + mInputList.size());
		if( mInputListIndex + 1 >= mInputList.size())
		{
			mStatus.Done( this );
			mThreadStopped = true;
			mBrowser.dispose();
			//System.exit( -1 );
			return;
		}

		mSeparatorFound = false;
		mStatus.fillingTheForm( this );
		mDOMDocument = aDOMDocument;

		mADI = mInputList.get( ++mInputListIndex );

		mLogger.info( mADI.mSearchURL );
		if( mADI.mSearchURL != null && mADI.mSearchURL.length() > 0 )
		{
			// The filters won't be applied, they must be in the URL
			if( mADI.mFilters != null && mADI.mFilters.contains( "checkin_no_till_limit" ))
				mCheckinNoTillLimitation = true;
			mBrowser.loadURL( mADI.mSearchURL );
		}
		else
		{
			//FillTheFormByRobot();
			FillTheFormByJQuery();
		}

		mStatus.formIsFilled( this );

		mDOMDocument = null;
		mStatus.searching( this );
	}

	String getNextFilter()
	{
		if( mFilters == null || mFilters.length <= mFilterIndex + 1 )
		{
			return null;
		}

		return mFilters[ ++mFilterIndex ].trim();
	}

	boolean ApplyFilter( DOMDocument aDOMDocument, String filter ) {
		FilterAttribs f = mFilterMap.get( filter );
		if( f != null )
		{
			mLogger.info( "FILTER: " + filter );
			if( filter.equals( "checkin_no_till_limit" ))
			{
				mCheckinNoTillLimitation = true;
				return false;
			}
			else
			{
				java.util.List<DOMElement> lFilters = aDOMDocument.findElements( By.className( "filterelement" ));
				for( DOMElement lElement : lFilters )
				{
//					System.out.println( f.mName );
//					System.out.println( f.mValue );
//					System.out.println( "'" + lElement.getAttribute( f.mName ) + "'" );
					if( lElement.getAttribute( f.mName ).equals( f.mValue ))
					{
						mStatus.ApplyAFilter( this );
						//Sleep( 7000 );
						lElement.click();
						return true;
					}
				}
			}
		}
		mLogger.warn( "Illegal filter: " + filter );
		return false;
	}

	void ApplyFilter( DOMDocument aDOMDocument )
	{
		// if the form was not filled, because the rearch result was loaded from url, then
		// the getNextFilter returns with null
		for( String filter = getNextFilter(); filter != null; filter = getNextFilter())
		{
			if( ApplyFilter( aDOMDocument, filter ))
				return;
		}

		mLogger.info( "mBrowser.getURL: " + mBrowser.getURL());
		mLogger.info( "escaped URL: " + escapeXML( mBrowser.getURL()));
		ParseTheResult( aDOMDocument );
	}

	boolean testSoldOut( DOMElement element )
	{
		if( element.getAttribute( "class" ).contains( "sr_item--soldout" ))
			return true;

		if( element.findElement( By.className( "sold_out_msg" )) != null )
			return true;

		if( element.findElement( By.className( "sold_out_property" )) != null )
			return true;

		if( element.findElement( By.className( "sold_out_msg" )) != null )
			return true;

		if( element.getInnerHTML().contains( "You missed it!" ))
			return true;

		return false;
	}

	boolean testRecommendation( DOMElement element )
	{
		if( element.getInnerHTML().contains( "We recommend this property in" ))
			return true;
		return false;
	}

	void ParseTheResult( DOMDocument aDOMDocument )
	{
		mStatus.parsingTheResult( this );
		mDOMDocument = aDOMDocument;
		//Sleep( 10_000 );
		java.util.List<DOMElement> lElements = mDOMDocument.findElements( By.className( "sr_item" ));
		if( lElements != null )
		{
			for( DOMElement lElement : lElements )
			{
				if( testSoldOut( lElement ) || testRecommendation( lElement ))
					continue;

				if( lElement.getAttribute( "class" ).contains( "sr_separator" ))
				{
					mSeparatorFound = true;
					break;
				}

				AccomodationData_RESULT lResult = new AccomodationData_RESULT();

				DOMElement lName = lElement.findElement( By.className( "sr-hotel__name" ));
				DOMElement lURL = lElement.findElement( By.className( "hotel_name_link url" ));
				DOMElement lPrice = lElement.findElement( By.className( "sr_gs_price_total" ));

				if( lName != null )
				{
					lResult.mName = lName.getInnerText();
					if( mHotelNames.contains( lResult.mName ))
						continue;
					mHotelNames.add( lResult.mName );
					//System.out.println( "Name: " + lResult.mName );
				} else {
					continue;
				}

				if( lURL != null )
				{
					lResult.mURL = lURL.getAttribute( "href" );
					//System.out.println( "URL: " + getURL() + lResult.mURL );
				}

				if( lPrice != null )
				{
					lResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
					//System.out.println( "Price: " + lResult.mPrice );
				}

				if( lElement.hasAttribute( "data-score" ))
				{
					try
					{
						lResult.mScore = Double.parseDouble( lElement.getAttribute( "data-score" ) );
						//System.out.println( "Score: " + lResult.mScore );
					}
					catch( java.lang.NumberFormatException e )
					{
					}
				}
				mAccomodationDataResults.add( lResult );
			}
		}

		// Name : <span class="sr-hotel__name">Corvin Plaza Apartments &amp; Suites</span>

		// Review text:
		// <span class="review-score-widget__text">Very good</span>

		// Score:
		// <span class="review-score-badge">8<span class="review-score__decimal-separator">.</span>2</span>

		// Number of reviewers: <span class="review-score-widget__subtext">1,621 reviews</span>

		// Price: <b class="sr_gs_price_total">€&nbsp;183</b>

		// Starting block:
		// <div class="sr_item sr_item_new sr_item_default sr_property_block  sr_flex_layout                 genius_highlight " data-hotelid="367832" data-class="0" data-score="8.5">

		// pagination: <a class="sr_pagination_link" href="/searchresults.en-gb.html?label=gen173nr-1FCAEoggJCAlhYSDNiBW5vcmVmaIkBiAEBmAEuwgEKd2luZG93cyAxMMgBDNgBAegBAfgBC5ICAXmoAgM;sid=9e8e9e2e4a5ee51cd4367961239c350d;age=11;age=8;checkin_month=7;checkin_monthday=23;checkin_year=2017;checkout_month=7;checkout_monthday=24;checkout_year=2017;class_interval=1;dest_id=-850553;dest_type=city;dtdisc=0;group_adults=2;group_children=2;inac=0;index_postcard=0;label_click=undef;mih=0;no_rooms=1;postcard=0;raw_dest_type=city;room1=A%2CA%2C8%2C11;sb_price_type=total;sb_travel_purpose=leisure;src=index;src_elem=sb;ss=Budapest;ss_all=0;ssb=empty;sshis=0;ssne=Budapest;ssne_untouched=Budapest;rows=25">1</a>

		// hotel link: <a class="hotel_name_link url" href="..." target="_blank" rel="noopener" data-et-mouseenter="customGoal:eWKLfCcADDbdEHBNKNMC:1" data-et-click="">...</a>

		// The mDOMDocument mustn't be null, because the pageNext will be called from the parsingFinished.
		mStatus.parsingFinished( this );
		mDOMDocument = null;
	}

	public boolean pageNext()
	{
		if( mSeparatorFound )
			return false;

		// <a class="paging-next ga_sr_gotopage_2_18" data-page-next="" href="...">Next page</a>
		DOMElement lElement = mDOMDocument.findElement( By.className( "paging-next" ));
		if( lElement == null )
			return false;
		lElement.click();
		return true;
	}

	public boolean isResultPage( DOMDocument aDOMDocument )
	{
		DOMElement lElement = aDOMDocument.findElement( By.className( "sr_item" ));
		return lElement != null;
	}

	public boolean openTheNextHotel()
	{
		if( mLastOpenedAccomodation + 1 < mAccomodationDataResults.size())
		{
			++mLastOpenedAccomodation;
			mBrowser.loadURL( getURL() + mAccomodationDataResults.get( mLastOpenedAccomodation ).mURL );
			return true;
		}
		return false;
	}

	boolean testCheckinPolicy( String checkinPolicy )
	{
		if( !mCheckinNoTillLimitation )
			return true;

		if( checkinPolicy.length() == 0 || checkinPolicy.startsWith( "From" ))
			return true;

		// CheckInPolicy: 15:00 - 23:00
		return false;
	}

	private void ParseAHotelPage_S( AccomodationData_RESULT lAccomodation )
	{
		// check-out policy:
		// <div class="description" id="checkout_policy"><p class="policy_name"><span>Check-out</span></p><p>Until 11:00 hours</p><div style="clear:both"></div></div>
		DOMElement lCheckoutPolicy = mDOMDocument.findElement( By.id( "checkout_policy" ));
		if( lCheckoutPolicy != null )
		{
			lAccomodation.mCheckOutPolicy = lCheckoutPolicy.getInnerText();
			if( lAccomodation.mCheckOutPolicy.startsWith( "Check-out\n" ))
				lAccomodation.mCheckOutPolicy = lAccomodation.mCheckOutPolicy.substring( "Check-out\n".length());
			lAccomodation.mCheckOutPolicy = lAccomodation.mCheckOutPolicy.trim();
		}

		// Address
		// <span class="hp_address_subtitle jq_tooltip" rel="14" data-source="top_link" data-coords="," data-node_tt_id="location_score_tooltip" data-bbox="19.0532273054123,47.4821070329846,19.1041785478592,47.506432153588" data-width="350" id="b_tt_holder_1" data-title="">			1081 Budapest, Népszínház u. 39-41, Hungary			</span>

		DOMElement lAddress = mDOMDocument.findElement( By.className( "hp_address_subtitle" ));
		if( lAddress != null )
		{
			lAccomodation.mAddress = lAddress.getInnerText();
		}

		// map link
		// <a data-source="top_link" class="show_map jq_tooltip  show_map_with_endorsements " href="javascript:void(0);" data-bbox="19.0532273054123,47.4821070329846,19.1041785478592,47.506432153588" data-coords="," rel="" data-node_tt_id="show_map_endorsements_tooltip" data-width="300" id="show_id75172" style="white-space:nowrap" data-title="Atlas City Hotel, Budapest - Check location">Show map</a>

		// room link: <a href="#RD7517221" class="jqrt togglelink js-track-hp-rt-room-name" data-room-name-en="Family Room" title="" aria-haspopup="true"><i class="rt_room_type_ico bicon-triangleright"></i>Family Room</a>
		// room link: <a href="#RD7517204" class="jqrt togglelink js-track-hp-rt-room-name" data-room-name-en="Quadruple Room" title="" aria-haspopup="true"><i class="rt_room_type_ico bicon-triangleright"></i>Quadruple Room</a>

		// room block:
		// class="room_loop_counterX", ahol X egy index >=1. Azok a <tr> tagok, amelyek az adott szobához tartoznak, azonos indexel szerepelnek.
		// Különböző lehet az ágyak száma és az ár is.
		// Ezen belül az ár: <strong data-price-without-addons="€&nbsp;92.70" data-price-with-parking="" data-price-with-internet="" data-price-with-internet-parking="" class=" js-track-hp-rt-room-price b-tooltip-with-price-breakdown-tracker   rooms-table-room-price" title="">

		// Link a szobára: <tr id="7517222_93706251_2_1_0" data-breakfast-included="1" data-occupancy="2" class="room_loop_counter6">...</tr>
		// room name: <a href="#RD7517222" class="jqrt togglelink js-track-hp-rt-room-name" data-room-name-en="Comfort Double or Twin Room" title="" aria-haspopup="true"><i class="rt_room_type_ico bicon-triangleright"></i>Comfort Double or Twin Room</a>

		for( int i = 1; ; i++ )
		{
			java.util.List<DOMElement> lRooms = mDOMDocument.findElements( By.className( "room_loop_counter" + i ));
			if( lRooms == null || lRooms.size() == 0 )
				break;

			String roomName = "";
			for( DOMElement lRoom : lRooms )
			{
				String cssClassName = lRoom.getAttribute( "class" );
				if( cssClassName.contains( "maintr" ) || cssClassName.contains( "extendedRow" ))
					continue;

				DOMElement lRoomName = lRoom.findElement( By.className( "js-track-hp-rt-room-name" ));
				if( lRoomName != null )
				{
					roomName = lRoomName.getAttribute( "data-room-name-en" );
				}

				AccomodationData_RESULT lRoomResult = new AccomodationData_RESULT();
				lRoomResult.mName = roomName;
				lRoomResult.mMaxOccupancy = lRoom.getAttribute( "data-occupancy" );
				try
				{
					//System.out.println( "lRoomResult.mMaxOccupancy: '" + lRoomResult.mMaxOccupancy + "'" );
					if( Integer.parseInt( lRoomResult.mMaxOccupancy ) < mADI.mAdultNumber + mADI.mChildrenNumber )
						continue;
				}
				catch( NumberFormatException e )
				{
					e.printStackTrace();
				}
				lRoomResult.mBreakfastIncluded = "1".equals( lRoom.getAttribute( "data-breakfast-included" ));

				DOMElement lPrice = lRoom.findElement( By.className( "js-track-hp-rt-room-price" ));
				if( lPrice == null )
					continue;

				lRoomResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
				if( lRoomResult.mPrice > (double)mADI.mPriceLimit )
					continue;
				lAccomodation.mAvailableRooms.add( lRoomResult );
			}
		}
	}

	public void ParseAHotelPage( DOMDocument aDOMDocument )
	{
		mStatus.parsingAHotelPage( this );
		mDOMDocument = aDOMDocument;

		AccomodationData_RESULT lAccomodation = mAccomodationDataResults.get( mLastOpenedAccomodation );

		// check-in policy:
		// <div class="description" id="checkin_policy"><p class="policy_name"><span>Check-in</span></p><p>From 14:00 hours</p><div style="clear:both"></div></div>
		DOMElement lCheckinPolicy = mDOMDocument.findElement( By.id( "checkin_policy" ));
		if( lCheckinPolicy != null )
		{
			lAccomodation.mCheckInPolicy = lCheckinPolicy.getInnerText();
			if( lAccomodation.mCheckInPolicy.startsWith( "Check-in\n" ))
				lAccomodation.mCheckInPolicy = lAccomodation.mCheckInPolicy.substring( "Check-in\n".length());
			lAccomodation.mCheckInPolicy = lAccomodation.mCheckInPolicy.trim();
		}

		if( testCheckinPolicy( lAccomodation.mCheckInPolicy ))
			ParseAHotelPage_S( lAccomodation );

		mStatus.parsingFinished( this );
		mDOMDocument = null;
	}

	public void printTheMatches()
	{
		mLogger.info( "******************************************************************************************" );
		mLogger.info( mADI.toString());

		for( AccomodationData_RESULT lAccomodation : mAccomodationDataResults )
		{
			if( lAccomodation.mAvailableRooms.size() == 0 )
				continue;

			mLogger.info( "******************************************************************************************" );
			mLogger.info( "******************** HOTEL: " + lAccomodation.mName + "; Score: " + lAccomodation.mScore );
			mLogger.info( getURL() + lAccomodation.mURL );
			mLogger.info( "Address: " + lAccomodation.mAddress );
			for( AccomodationData_RESULT lRoom : lAccomodation.mAvailableRooms )
			{
				mLogger.info( "Room: " + lRoom.mName );
				mLogger.info( "     MaxOccupancy: " + lRoom.mMaxOccupancy );
				mLogger.info( "     BreakfastIncluded: " + lRoom.mBreakfastIncluded );
				mLogger.info( "     Price: " + lRoom.mPrice );
			}
			mLogger.info( "CheckInPolicy: " + lAccomodation.mCheckInPolicy );
			mLogger.info( "CheckOutPolicy: " + lAccomodation.mCheckOutPolicy );
		}
	}
}

// SEARCH FORM
// search button xpath: //*[@id="frm"]/div[7]/button
// destination input field: //*[@id="ss"]
// travelling for work radio: //*[@id="frm"]/div[3]/div/div/fieldset/label[2]/input
// check-in div: //*[@id="frm"]/div[4]/div/div[1]/div[1]/div/div/div[1]/div/div[2]
// check-out div: //*[@id="frm"]/div[4]/div/div[1]/div[2]/div/div/div[1]/div/div[2]
// rooms select: //*[@id="no_rooms"]
// adults select: //*[@id="group_adults"]
// children select: //*[@id="group_children"]
// age1: //*[@id="frm"]/div[5]/div/div[2]/div[4]/select[1]
// age2: //*[@id="frm"]/div[5]/div/div[2]/div[4]/select[2]
