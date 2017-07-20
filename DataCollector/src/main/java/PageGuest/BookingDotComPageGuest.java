package PageGuest;

import Configuration.Configuration;
import QueueHandlers.JMSStack;
import QueueHandlers.ResultQueue;
import Util.CurrencyHelper;
import Util.DatetimeHelper;
import Util.StringHelper;
import com.teamdev.jxbrowser.chromium.*;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import static Util.StringHelper.escapeXML;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

import java.util.*;
import java.util.logging.Level;

/**
 * Created by Andras on 15/03/2016.
 */

public class BookingDotComPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(BookingDotComPageGuest.class);

	private static boolean mSTOP_AT_THE_FIRST_PAGE = false;

	private Browser mBrowser = null;
	private BrowserView mBrowserView = null;
	private JTabbedPane mTabbedPane = null;

	private boolean mThreadStopped = true;
	private DOMDocument mDOMDocument;
	private BookingDotComStatus mStatus = new BookingDotComStatus();

	private AccomodationData_INPUT mADI;
	private ArrayList<AccomodationData_RESULT> mAccomodationDataResults = new ArrayList<>();
	private int mLastOpenedAccomodation = -1;

	private ArrayList<AccomodationData_INPUT> mInputList = new ArrayList<>();
	private int mInputListIndex = -1;

	private String[] mFilters = null;
	private int mFilterIndex = -1;

	private Integer mLoadReadyTimeout = -1;
	private boolean mSeparatorFound = false;
	private HashSet<String> mHotelNames = new HashSet<>();
	private int mHigherPriceCounter; // if 5 consecutive accomodation have only higher price than my limit, I stop the parsing.
	private static final int HIGH_PRICE_FLAT_COUNT = 5;

	enum MyFilterIds
	{
		checkin_no_till_limit,
		room_size_15p,
		room_size_20p,
		room_size_25p,
		room_size_30p,
		room_size_35p,
		room_size_50p,
		room_size_60p,
		room_size_70p,
		room_size_80p,
		room_size_90p,
		room_size_100p,
	};

	class FilterAttribs {
		public FilterAttribs( String name, String value )
		{
			mName = name;
			mValue = value;
		}
		public String mName;
		public String mValue;
	}

	private HashMap<String,FilterAttribs> mFilterMap = new HashMap<>();
	private HashMap<String,MyFilterIds>   mMyFilterMap = new HashMap<>();
	private HashMap<MyFilterIds,Boolean>  mMyFilterMap2 = new HashMap<>();
	private boolean mResultSorted = false;

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
					{
						Sleep( 2000 );
						mGuest.mStatus.mainFrameLoaded( mGuest, event.getBrowser().getDocument() );
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
			synchronized( mLoadReadyTimeout )
			{
				mLoadReadyTimeout = 50;
			}
		}

		@Override
		public void onDocumentLoadedInMainFrame(LoadEvent event) {
			//System.out.println("Main frame document is loaded.");
		}

	}

//	public void InitJMS()
//	{
//		mLogger.trace( "begin, thread name: " + getThreadName());
//		synchronized (mMutex)
//		{
//			mSearchQueue = new JMSStack<>();
//			mSearchQueue.setQueueName( "booking.com" );
//		}
//		mLogger.trace( "end, thread name: " + getThreadName());
//	}

	public void Init()
	{
		DoSearchFromConfig();
		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		mTabbedPane = new JTabbedPane();
		JFrame frame = new JFrame( "Travel Optimizer - Booking.com - jxBrowser " + ProductInfo.getVersion());

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
		frame.setLocation( 50, 50 );
		frame.setVisible( true );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser( "Booking.com" );
		mBrowserView = new BrowserView( mBrowser );

		mTabbedPane.addTab( "Browser", mBrowserView );
		mBrowser.addLoadListener(new BrowserLoadAdapter( this ));
		//mBrowser.loadURL( "http://localhost:9222");

		// booking.com filters
		mFilterMap.put( "price_0-50",    new FilterAttribs( "data-id", "pri-1"));
		mFilterMap.put( "price_50-100",  new FilterAttribs( "data-id", "pri-2") );
		mFilterMap.put( "price_100-150", new FilterAttribs( "data-id", "pri-3") );
		mFilterMap.put( "price_150-200", new FilterAttribs( "data-id", "pri-4") );
		mFilterMap.put( "price_200+",    new FilterAttribs( "data-id", "pri-5") );

		mFilterMap.put( "free_wifi",             new FilterAttribs( "data-id", "hotelfacility-107" ));
		mFilterMap.put( "parking_place",         new FilterAttribs( "data-id", "hotelfacility-2" ));
		mFilterMap.put( "non_smoking_rooms",     new FilterAttribs( "data-id", "hotelfacility-16" ));
		mFilterMap.put( "restaurant",            new FilterAttribs( "data-id", "hotelfacility-3" ));

		mFilterMap.put( "apartments",            new FilterAttribs( "data-id", "ht_id-201" ));
		mFilterMap.put( "hotels",                new FilterAttribs( "data-id", "ht_id-204" ));
		mFilterMap.put( "free_cancellation",     new FilterAttribs( "data-id", "fc-1" ));
		mFilterMap.put( "24h_reception",         new FilterAttribs( "data-id", "hr_24-8" ));

		mFilterMap.put( "private_bathroom",      new FilterAttribs( "data-id", "roomfacility-800038" ));
		mFilterMap.put( "air_conditioning",      new FilterAttribs( "data-id", "roomfacility-800011" ));
		mFilterMap.put( "bath",                  new FilterAttribs( "data-id", "roomfacility-80005" ));
		mFilterMap.put( "electric_kettle",       new FilterAttribs( "data-id", "roomfacility-800086" ));
		mFilterMap.put( "washing_machine",       new FilterAttribs( "data-id", "roomfacility-800034" ));

		mFilterMap.put( "score_9+", new FilterAttribs( "data-id", "review_score-90" ));
		mFilterMap.put( "score_8+", new FilterAttribs( "data-id", "review_score-80" ));
		mFilterMap.put( "score_7+", new FilterAttribs( "data-id", "review_score-70" ));
		mFilterMap.put( "score_6+", new FilterAttribs( "data-id", "review_score-60" ));
		mFilterMap.put( "score_no", new FilterAttribs( "data-id", "review_score-999" ));

		mFilterMap.put( "exclude_sold_out", new FilterAttribs( "data-id", "oos-1" ));


		// My filters
		mMyFilterMap.put( "checkin_no_till_limit", MyFilterIds.checkin_no_till_limit );
		mMyFilterMap.put( "room_size_15+", MyFilterIds.room_size_15p );
		mMyFilterMap.put( "room_size_20+", MyFilterIds.room_size_20p );
		mMyFilterMap.put( "room_size_25+", MyFilterIds.room_size_25p );
		mMyFilterMap.put( "room_size_30+", MyFilterIds.room_size_30p );
		mMyFilterMap.put( "room_size_35+", MyFilterIds.room_size_35p );

		mMyFilterMap.put( "room_size_50+", MyFilterIds.room_size_50p );
		mMyFilterMap.put( "room_size_60+", MyFilterIds.room_size_60p );
		mMyFilterMap.put( "room_size_70+", MyFilterIds.room_size_70p );
		mMyFilterMap.put( "room_size_80+", MyFilterIds.room_size_80p );
		mMyFilterMap.put( "room_size_90+", MyFilterIds.room_size_90p );
		mMyFilterMap.put( "room_size_100+", MyFilterIds.room_size_100p );


		for( MyFilterIds id : MyFilterIds.values())
			mMyFilterMap2.put( id, false );

		//InitJMS();
		startANewSearch();
	}

	public void startANewSearch()
	{
		mStatus.starting( this );
		mAccomodationDataResults = new ArrayList<>();
		mHotelNames = new HashSet<>();
		mResultSorted = false;
		mHigherPriceCounter = HIGH_PRICE_FLAT_COUNT;
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
				mLogger.warn( StringHelper.getTraceInformation( e ));
			}
		}
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

		if( mADI.mFilters != null && mADI.mFilters.length() > 0 )
		{
			mFilters = mADI.mFilters.split("\\,", 0 );
			mFilterIndex = -1;
		}

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
			// I will set my filters
			if( mADI.mFilters != null && mADI.mFilters.length() > 0 )
			{
				String[] filters = mADI.mFilters.split( "\\,", 0 );
				for( int i = 0; i < filters.length; i++ )
					ApplyMyFilters( filters[ i ] );
			}
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
			return null;

		return mFilters[ ++mFilterIndex ].trim();
	}

	/**
	 *
	 * @param filter
	 * @return true, if my filter was applied, otherwise false
	 */
	boolean ApplyMyFilters( String filter )
	{
		if( mMyFilterMap.containsKey( filter ))
		{
			mMyFilterMap2.put( mMyFilterMap.get( filter ), true );
			//mCheckinNoTillLimitation = true;
			return true;
		}
		return false;
	}

	boolean ApplySortingFilter( DOMDocument aDOMDocument )
	{
		// sort_by_price
		// <div id="sort_by" class=" hilite  ">
		// ....
		// <li class=" sort_category   sort_price sort_category__button ">
		// <a href="/searchresults.en-gb.html?label=gen173nr-1DCAEoggJCAlhYSDNiBW5vcmVmaDuIAQGYAS7CAQNhYm7IAQzYAQPoAQGSAgF5qAIE;sid=bb513d800525df12982c6f7fd2158280;age=11;age=8;checkin_month=9;checkin_monthday=8;checkin_year=2017;checkout_month=9;checkout_monthday=11;checkout_year=2017;class_interval=1;dest_id=-850553;dest_type=city;dtdisc=0;group_adults=1;group_children=2;inac=0;index_postcard=0;label_click=undef;no_rooms=1;postcard=0;raw_dest_type=city;req_age=11;req_age=8;room1=A%2C8%2C11;sb_price_type=total;sb_travel_purpose=leisure;src_elem=sb;ss=Budapest;ss_all=0;ssb=empty;sshis=0;ssne=Budapest;ssne_untouched=Budapest&amp;;order=price" class="sort_option sort_options__button">
		// Cheapest properties first
		//	</a>
		// </li>

		DOMElement sortBar = aDOMDocument.findElement( By.id( "sort_by" ));
		if( sortBar == null )
			return false;

		DOMElement priceLi = sortBar.findElement( By.className( "sort_price" ));
		if( priceLi == null )
			return false;

		DOMElement priceA = priceLi.findElement( By.tagName( "a" ));
		if( priceA == null )
			return false;

		priceA.click();

		return true;
	}

	boolean ApplyBookingFilters( DOMDocument aDOMDocument, String filter )
	{
		FilterAttribs f = mFilterMap.get( filter );
		if( f == null )
			return false;

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

		return false;
	}

	/**
	 *
	 * @param aDOMDocument
	 * @param filter
	 * @return true, if a booking filter was applied, otherwise false (if it was my filter or illegal filter name)
	 */
	boolean ApplyFilter( DOMDocument aDOMDocument, String filter ) {
		mLogger.info( "FILTER: " + filter );
		if( ApplyMyFilters( filter ))
			return false;

		if( ApplyBookingFilters( aDOMDocument, filter ))
			return true;

		mLogger.warn( "Illegal filter: " + filter );
		return false;
	}

	void ApplyFilter( DOMDocument aDOMDocument )
	{
		if( !mResultSorted )
		{
			if( ApplySortingFilter( aDOMDocument ))
				mResultSorted = true;
		}

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
					//lResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
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
		if( mHigherPriceCounter >= 0 && mLastOpenedAccomodation + 1 < mAccomodationDataResults.size())
		{
			++mLastOpenedAccomodation;
			mBrowser.loadURL( getURL() + mAccomodationDataResults.get( mLastOpenedAccomodation ).mURL );
			return true;
		}

		if( mHigherPriceCounter < 0 )
			mLogger.info( "The last 5 accomodation haven't had lower price than the limit." );

		return false;
	}

	boolean testCheckinPolicy( String checkinPolicy )
	{
		if( !mMyFilterMap2.getOrDefault( MyFilterIds.checkin_no_till_limit, false ))
			return true;

		if( checkinPolicy.length() == 0 || checkinPolicy.startsWith( "From" ))
			return true;

		// CheckInPolicy: 15:00 - 23:00
		return false;
	}

	private String getRoomSize( String roomMetaId )
	{
		String roomSize = "";
		if( roomMetaId != null )
		{
			// cutting the starting #
			roomMetaId = roomMetaId.substring( 1 );

			// blocktoggle #RD17925503
			DOMElement lRoomMetaBlock = mDOMDocument.findElement( By.id( "blocktoggle" + roomMetaId ));
			if( lRoomMetaBlock != null )
			{
				DOMElement lRoomInfo = lRoomMetaBlock.findElement( By.className( "info" ));
				if( lRoomInfo != null )
				{
					roomSize = lRoomInfo.getInnerText()
							.replaceAll( "\n", "" )
							.replace( "Room size:", "" )
							.replace( "Apartment size:", "" )
							.trim();
				}
			}
		}
		return roomSize;
	}

	boolean testRoomSize( String roomSize )
	{
		if( roomSize == null || roomSize.length() == 0 )
			return true;

		try
		{
			int size = Integer.parseInt( roomSize.substring( 0, roomSize.indexOf( " " ) ) );
			if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_15p, false ) && size < 15 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_20p, false ) && size < 20 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_25p, false ) && size < 25 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_30p, false ) && size < 30 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_35p, false ) && size < 35 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_50p, false ) && size < 50 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_60p, false ) && size < 60 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_70p, false ) && size < 70 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_80p, false ) && size < 80 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_90p, false ) && size < 90 )
				return false;
			else if( mMyFilterMap2.getOrDefault( MyFilterIds.room_size_100p, false ) && size < 100 )
				return false;
		}
		catch( NumberFormatException e )
		{
			mLogger.warn( StringHelper.getTraceInformation( e ));
			mLogger.warn( "roomSize: '" + roomSize + "'" );
			return true;
		}
		return true;
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

		//mStatus.Done( this );

		boolean foundLowerPrice = false;

		for( int i = 1; ; i++ )
		{
			java.util.List<DOMElement> lRooms = mDOMDocument.findElements( By.className( "room_loop_counter" + i ));
			if( lRooms == null || lRooms.size() == 0 )
				break;

			String roomName = "";
			String roomSize = "";
			AccomodationData_RESULT.Room lRoomResult = new AccomodationData_RESULT.Room();
			for( DOMElement lRoom : lRooms )
			{
				String cssClassName = lRoom.getAttribute( "class" );
				if( cssClassName.contains( "extendedRow" ))
				{
					// this is the very last row without valueable information
					continue;
				}

				if( cssClassName.contains( "maintr" ))
				{
					// here are the main information, which can be common among more rooms
					DOMElement lRoomName = lRoom.findElement( By.className( "js-track-hp-rt-room-name" ));
					if( lRoomName != null )
					{
						lRoomResult.mName = lRoomName.getAttribute( "data-room-name-en" );
						lRoomResult.mRoomHook = lRoomName.getAttribute( "href" );
						lRoomResult.mRoomSize = getRoomSize( lRoomResult.mRoomHook );
						if( !testRoomSize( lRoomResult.mRoomSize ))
							continue;
					}
				}
				else
				{
					// PRICE
					DOMElement lPrice = lRoom.findElement( By.className( "js-track-hp-rt-room-price" ));
					if( lPrice == null && mADI.mPriceLimit != null )
						continue;

					if( lPrice != null && mADI.mPriceLimit != null )
					{
						lRoomResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
						if( mADI.mPriceLimit != null )
						{
							if( lRoomResult.mPrice > (double) mADI.mPriceLimit )
								continue;
							foundLowerPrice = true;
						}
					}

					// MAX OCCUPAMCY
					String maxOccupancy = lRoom.getAttribute( "data-occupancy" );
					if( maxOccupancy != null && maxOccupancy.length() > 0 )
						lRoomResult.mMaxOccupancy = maxOccupancy;
					try
					{
						//System.out.println( "lRoomResult.mMaxOccupancy: '" + lRoomResult.mMaxOccupancy + "'" );
						if( Integer.parseInt( lRoomResult.mMaxOccupancy ) < mADI.mAdultNumber + mADI.mChildrenNumber )
							continue;
					}
					catch( NumberFormatException e )
					{
						mLogger.warn( StringHelper.getTraceInformation( e ));
					}

					// BREAKFAST
					lRoomResult.mBreakfastIncluded = "1".equals( lRoom.getAttribute( "data-breakfast-included" ));

					// Cancellation
					DOMElement lCancellation = lRoom.findElement( By.id( "cancel_policy_first" ));
					if( lCancellation != null )
						lRoomResult.mCancellationPolicy = lCancellation.getInnerText();

					lAccomodation.mAvailableRooms.add( lRoomResult );
					try
					{
						lRoomResult = (AccomodationData_RESULT.Room) lRoomResult.clone();
					}
					catch( CloneNotSupportedException e )
					{
						e.printStackTrace();
					}
				}
			}
		}

		if( mADI.mPriceLimit != null )
		{
			if( foundLowerPrice )
				mHigherPriceCounter = HIGH_PRICE_FLAT_COUNT;
			else
				--mHigherPriceCounter;
		}
	}

	public void ParseAHotelPage( DOMDocument aDOMDocument )
	{
		mStatus.parsingAHotelPage( this );
		mDOMDocument = aDOMDocument;

		AccomodationData_RESULT lAccomodation = mAccomodationDataResults.get( mLastOpenedAccomodation );
		lAccomodation.mSite = 'B';

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
		mLogger.info( "**************************************************************" );
		mLogger.info( "**************************** MATCHES *************************" );
		mLogger.info( "**************************************************************" );
		mLogger.info( "Search data:\n" + mADI.toString());

		for( AccomodationData_RESULT lAccomodation : mAccomodationDataResults )
		{
			if( lAccomodation.mAvailableRooms.size() == 0 )
				continue;

			ResultQueue.getInstance().push( lAccomodation );

			mLogger.info( "HOTEL: " + lAccomodation.mName + "; Score: " + lAccomodation.mScore );
			mLogger.info( getURL() + lAccomodation.mURL );
			mLogger.info( "Address: " + lAccomodation.mAddress );
			for( AccomodationData_RESULT.Room lRoom : lAccomodation.mAvailableRooms )
			{
				mLogger.info( "Room: " + lRoom.mName );
				mLogger.info( "     Size: " + lRoom.mRoomSize );
				mLogger.info( "     MaxOccupancy: " + lRoom.mMaxOccupancy );
				mLogger.info( "     BreakfastIncluded: " + lRoom.mBreakfastIncluded );
				mLogger.info( "     Price: " + lRoom.mPrice );
			}
			mLogger.info( "CheckInPolicy: " + lAccomodation.mCheckInPolicy );
			mLogger.info( "CheckOutPolicy: " + lAccomodation.mCheckOutPolicy );
		}
	}
}
