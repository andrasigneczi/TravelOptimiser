package PageGuest;

import Configuration.Configuration;
import Util.CurrencyHelper;
import Util.DatetimeHelper;
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

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

import java.util.ArrayList;
import java.util.logging.Level;

/**
 * Created by Andras on 15/03/2016.
 */

public class BookingDotComPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(BookingDotComPageGuest.class);
	private Browser mBrowser = null;
	private BrowserView mBrowserView = null;
	private JTabbedPane mTabbedPane = null;

	private long mTimeoutStart;
	private boolean mThreadStopped = true;
	DOMDocument mDOMDocument;
	private BookingDotComStatus mStatus = new BookingDotComStatus();

	ArrayList<AccomodationData_RESULT> mAccomodationDataResults = new ArrayList<>(  );
	int mLastOpenedAccomodation = -1;

	ArrayList<AccomodationData_INPUT> mInputList = new ArrayList<>();
	int mInputListIndex = -1;

	String[] mFilters = null;
	int mFilterIndex = -1;

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
				System.out.println("Main frame has started loading");
			}
		}

		@Override
		public void onProvisionalLoadingFrame(ProvisionalLoadingEvent event) {
			if (event.isMainFrame()) {
				System.out.println("Provisional load was committed for a frame");
			}
		}

		@Override
		public void onFinishLoadingFrame(FinishLoadingEvent event) {
			// A click után újra bejövök ide, erre ügyelni kell!!!!
			synchronized( this )
			{
				if( event.isMainFrame())
				{
					System.out.println( "Main frame has finished loading" );
					System.out.println( "Status: " + mGuest.mStatus.getStatus());
					mGuest.mStatus.mainFrameLoaded( mGuest, event.getBrowser().getDocument());
				}
			}
		}

		@Override
		public void onFailLoadingFrame(FailLoadingEvent event) {
			NetError errorCode = event.getErrorCode();
			if (event.isMainFrame()) {
				System.out.println("Main frame has failed loading: " + errorCode);
			}
		}

		@Override
		public void onDocumentLoadedInFrame(FrameLoadEvent event) {
			System.out.println("Frame document is loaded." );
			if(( mGuest.mStatus.getStatus() == BookingDotComStatus.Status.NEXT_PAGE_LOADING ||
				 mGuest.mStatus.getStatus() == BookingDotComStatus.Status.APPLYING_A_FILTER )
					&& mGuest.isResultPage( event.getBrowser().getDocument()))
			{
				System.out.println( "Status: " + mGuest.mStatus.getStatus());
				mGuest.mStatus.mainFrameLoaded( mGuest, event.getBrowser().getDocument());
			}
		}

		@Override
		public void onDocumentLoadedInMainFrame(LoadEvent event) {
			System.out.println("Main frame document is loaded.");
		}

	}

	public void Init()
	{
		mStatus.starting( this );
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
				System.out.println("Closed");
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
		mTabbedPane.addTab( "Browser", mBrowserView );
		//mBrowser.addLoadListener( new WizzAirPageGuest_LoadListener(this));
		mBrowser.addLoadListener(new BrowserLoadAdapter( this ));
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

	// DEVEL
	public void FillTheForm( DOMDocument aDOMDocument )
	{
		if( mInputListIndex + 1 >= mInputList.size())
		{
			mStatus.Done( this );
			return;
		}

		mStatus.fillingTheForm( this );
		mDOMDocument = aDOMDocument;

		AccomodationData_INPUT lADI = mInputList.get( ++mInputListIndex );


		// destination
		MouseLeftClick( 120, 326 );
		Sleep( 500 );
		PressCtrlA();
		Sleep( 500 );
		PressDelete();
		Sleep( 500 );
		//TypeText( "Budapest, Pest, Hungary" );
		TypeText( lADI.mCity );
		Sleep( 1000 );
		PressDown();
		Sleep( 1000 );
		TypeText( "\n" );
		Sleep( 1000 );
		TypeText( "\t" );
		Sleep( 1000 );

		// check-in
		//TypeText( "24072017\t" );
		System.out.println( lADI.mCheckIn );
		TypeText( DatetimeHelper.ReverseDate( lADI.mCheckIn ) + "\t" );
		Sleep( 1000 );

		// check-out
		//TypeText( "01082017\t" );
		System.out.println( lADI.mCheckOut );
		TypeText( DatetimeHelper.ReverseDate( lADI.mCheckOut ) + "\t" );
		Sleep( 1000 );

		// travelling for leisure radio
		if( !setChecked( "//*[@id=\"frm\"]/div[3]/div/div/fieldset/label[2]/input", true ))
			setChecked( "//*[@id=\"frm\"]/div[4]/div/div/fieldset/label[2]/input", true );

		Sleep( 1000 );

		// rooms select
		jQuerySetSelect( "no_rooms", String.valueOf( lADI.mRoomNumber ));

		Sleep( 1000 );

		// adults select
		jQuerySetSelect( "group_adults", String.valueOf( lADI.mAdultNumber ));

		Sleep( 1000 );

		// children select
		//setSelect( "//*[@id=\"group_children\"]", "4" );
		jQuerySetSelect( "group_children", String.valueOf( lADI.mChildrenNumber ));

		Sleep( 1000 );


		for( int i = 0; i < lADI.mChildrenAge.size(); i++ )
		{
			jQuerySetSelect2( "$('[data-group-child-age=\"" + i + "\"]')", String.valueOf( lADI.mChildrenAge.get( i )));
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

		if( lADI.mFilters != null && lADI.mFilters.length() > 0 )
		{
			mFilters = lADI.mFilters.split("\\,", 0 );
			mFilterIndex = -1;
		}

		mStatus.formIsFilled( this );

		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').click();" );
		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').submit();" );
		MouseLeftClick( 120, 326 );
		Sleep( 500 );
		TypeText( "\n" );
		Sleep( 1000 );

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

	void ApplyFilter( DOMDocument aDOMDocument )
	{
		for( String filter = getNextFilter(); filter != null; filter = getNextFilter())
		{
			if( filter.equals( "price_0-50" ))
			{
				System.out.println( "FILTER: " + filter );
				mStatus.ApplyAFilter( this );
				DOMElement lFilter = aDOMDocument.findElement( By.xpath( "//*[@id=\"filter_price\"]/div[2]/a[1]" ));
				lFilter.click();
				Sleep( 7000 );
				return;
			}
			else if( filter.equals( "price_50-100" ))
			{
				System.out.println( "FILTER: " + filter );
				mStatus.ApplyAFilter( this );
				DOMElement lFilter = aDOMDocument.findElement( By.xpath( "//*[@id=\"filter_price\"]/div[2]/a[2]" ));
				lFilter.click();
				Sleep( 7000 );
				return;
			}
			else
			{
				mLogger.warn( "Illegal filter: " + filter );
			}
		}

		ParseTheResult( aDOMDocument );

		// filter 24h reception: //*[@id="filter_24hr_reception"]/div[2]/a
		// filter free cancellation: //*[@id="filter_fc"]/div[2]/a[1]
		// filter apartment: //*[@id="filter_hoteltype"]/div[2]/a[1]
		// filter hotels: //*[@id="filter_hoteltype"]/div[2]/a[2]
		// filter free wifi: //*[@id="filter_facilities"]/div[2]/a[7]
		// filter restaurant: //*[@id="filter_facilities"]/div[2]/a[4]
		// filter AC: //*[@id="filter_roomfacilities"]/div[2]/a[1]
		// filter batch: //*[@id="filter_roomfacilities"]/div[2]/a[3]
		// filter disctict 8: //*[@id="filter_district"]/div[2]/a[6]
		// filter disctrict 13: //*[@id="filter_district"]/div[2]/a[9]
		// filter disctrict 19: //*[@id="filter_district"]/div[2]/a[20]

	}

	void ParseTheResult( DOMDocument aDOMDocument )
	{
		mStatus.parsingTheResult( this );
		mDOMDocument = aDOMDocument;

		java.util.List<DOMElement> lElements = mDOMDocument.findElements( By.className( "sr_item" ));
		if( lElements != null )
		{
			for( DOMElement lElement : lElements )
			{
				if( lElement.getAttribute( "class" ).contains( "sr_item--soldout" ))
					continue;

				if( lElement.getAttribute( "class" ).contains( "sr_separator" ))
					break;

				AccomodationData_RESULT lResult = new AccomodationData_RESULT();

				DOMElement lName = lElement.findElement( By.className( "sr-hotel__name" ));
				DOMElement lURL = lElement.findElement( By.className( "hotel_name_link url" ));
				DOMElement lPrice = lElement.findElement( By.className( "sr_gs_price_total" ));
				if( lName != null )
				{
					lResult.mName = lName.getInnerText();
					System.out.println( "Name: " + lResult.mName );
				}

				if( lURL != null )
				{
					lResult.mURL = lURL.getAttribute( "href" );
					System.out.println( "URL: " + getURL() + lResult.mURL );
				}

				if( lPrice != null )
				{
					lResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
					System.out.println( "Price: " + lResult.mPrice );
				}

				if( lElement.hasAttribute( "data-score" ))
				{
					try
					{
						lResult.mScore = Double.parseDouble( lElement.getAttribute( "data-score" ) );
						System.out.println( "Score: " + lResult.mScore );
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

		mStatus.parsingFinished( this );
		mDOMDocument = null;
	}

	public boolean pageNext()
	{
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

	public void ParseAHotelPage( DOMDocument aDOMDocument )
	{
		mStatus.parsingAHotelPage( this );
		mDOMDocument = aDOMDocument;

		System.out.println( "***************************************************************" );
		System.out.println( "******************** HOTEL ************************************" );
		System.out.println( "***************************************************************" );
		AccomodationData_RESULT lAccomodation = mAccomodationDataResults.get( mLastOpenedAccomodation );

		// Address
		// <span class="hp_address_subtitle jq_tooltip" rel="14" data-source="top_link" data-coords="," data-node_tt_id="location_score_tooltip" data-bbox="19.0532273054123,47.4821070329846,19.1041785478592,47.506432153588" data-width="350" id="b_tt_holder_1" data-title="">			1081 Budapest, Népszínház u. 39-41, Hungary			</span>

		DOMElement lAddress = mDOMDocument.findElement( By.className( "hp_address_subtitle" ));
		if( lAddress != null )
		{
			lAccomodation.mAddress = lAddress.getInnerText();
			System.out.println( "Address: " + lAccomodation.mAddress );
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
			java.util.List<DOMElement> lRooms = aDOMDocument.findElements( By.className( "room_loop_counter" + i ));
			if( lRooms == null || lRooms.size() == 0 )
				break;

			String roomName = "";
			for( DOMElement lRoom : lRooms )
			{
				DOMElement lRoomName = lRoom.findElement( By.className( "js-track-hp-rt-room-name" ));
				if( lRoomName != null )
				{
					roomName = lRoomName.getAttribute( "data-room-name-en" );
				}

				AccomodationData_RESULT lRoomResult = new AccomodationData_RESULT();
				lRoomResult.mName = roomName;
				lRoomResult.mMaxOccupancy = lRoom.getAttribute( "data-occupancy" );
				lRoomResult.mBreakfastIncluded = "1".equals( lRoom.getAttribute( "data-breakfast-included" ));

				DOMElement lPrice = lRoom.findElement( By.className( "js-track-hp-rt-room-price" ));
				if( lPrice == null )
					continue;

				lRoomResult.mPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice.getInnerText(), false );
				lAccomodation.mAvailableRooms.add( lRoomResult );

				System.out.println( "Room: " + lRoomResult.mName );
				System.out.println( "     MaxOccupancy: " + lRoomResult.mMaxOccupancy );
				System.out.println( "     BreakfastIncluded: " + lRoomResult.mBreakfastIncluded );
				System.out.println( "     Price: " + lRoomResult.mPrice );
			}
		}
		// check-in policy:
		// <div class="description" id="checkin_policy"><p class="policy_name"><span>Check-in</span></p><p>From 14:00 hours</p><div style="clear:both"></div></div>

		DOMElement lCheckinPolicy = mDOMDocument.findElement( By.id( "checkin_policy" ));
		if( lCheckinPolicy != null )
		{
			lAccomodation.mCheckInPolicy = lCheckinPolicy.getInnerText();
			if( lAccomodation.mCheckInPolicy.startsWith( "Check-in\n" ))
				lAccomodation.mCheckInPolicy = lAccomodation.mCheckInPolicy.substring( "Check-in\n".length());
			lAccomodation.mCheckInPolicy = lAccomodation.mCheckInPolicy.trim();
			System.out.println( "CheckInPolicy: " + lAccomodation.mCheckInPolicy );
		}

		// check-out policy:
		// <div class="description" id="checkout_policy"><p class="policy_name"><span>Check-out</span></p><p>Until 11:00 hours</p><div style="clear:both"></div></div>

		DOMElement lCheckoutPolicy = mDOMDocument.findElement( By.id( "checkout_policy" ));
		if( lCheckoutPolicy != null )
		{
			lAccomodation.mCheckOutPolicy = lCheckoutPolicy.getInnerText();
			if( lAccomodation.mCheckOutPolicy.startsWith( "Check-out\n" ))
				lAccomodation.mCheckOutPolicy = lAccomodation.mCheckOutPolicy.substring( "Check-out\n".length());
			lAccomodation.mCheckOutPolicy = lAccomodation.mCheckOutPolicy.trim();
			System.out.println( "CheckOutPolicy: " + lAccomodation.mCheckOutPolicy );
		}

		mStatus.parsingFinished( this );
		mDOMDocument = null;
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
