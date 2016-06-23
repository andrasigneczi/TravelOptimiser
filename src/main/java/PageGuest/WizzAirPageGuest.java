/*
TODO: fill the adult-,infant-,children number and handle it.
 */

package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.IntStream;

/**
 * Created by Andras on 15/03/2016.
 */
public class WizzAirPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest.class);

	private Thread  mThread;
	private Browser mBrowser = null;
	private boolean mThreadStopped = true;
	private JTabbedPane mTabbedPane = null;
	private static ArrayList<WizzAirPageGuest> mWizzAirPageGuestList = null;

	public WizzAirPageGuest()
	{
		super( "wizzair" );
		mLogger.trace( "tr" );
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread( this );
		mThread.setName( "WizzAirThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME ) );
		mThread.start();
		System.out.println("WizzAirPageGuest()");
	}

	private WizzAirPageGuest( JTabbedPane aTabbedPane )
	{
		super( "wizzair" );
		mLogger.trace( "tr" );
		mTabbedPane = aTabbedPane;
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread( this );
		mThread.setName( "WizzAirThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME ) );
		mThread.start();
		System.out.println("WizzAirPageGuest()");
	}

	public static void StartMultiBrowser( int aBrowserCount )
	{
		mLogger.trace( "tr" );
		if( mWizzAirPageGuestList != null )
			return;

		JTabbedPane lTabbedPane = new JTabbedPane();
		JFrame frame = new JFrame( "Travel Optimizer - wizzair" );
		frame.setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );
		frame.getContentPane().add( lTabbedPane, BorderLayout.CENTER );
		frame.setSize( 1152, 864 );
		frame.setLocationRelativeTo( null );
		frame.setVisible( true );

		mWizzAirPageGuestList = new ArrayList<WizzAirPageGuest>();
		IntStream.range(0,aBrowserCount).forEach( i ->  mWizzAirPageGuestList.add( new WizzAirPageGuest(lTabbedPane)));
		DoMultiSearchFromConfig();
	}

	public static void StopMultiBrowser()
	{
		mLogger.trace( "tr" );
		if( mWizzAirPageGuestList == null )
			return;

		for( WizzAirPageGuest lWPG : mWizzAirPageGuestList )
		{
			lWPG.stop();
		}
	}

	private static void DoMultiSearchFromConfig()
	{
		mLogger.trace( "tr" );
		int lPageIndex = 0;
		WizzAirPageGuest lWPG = mWizzAirPageGuestList.get( lPageIndex );
		ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
		for( TravelData_INPUT lTDI : lSearchList )
		{
			if( !lTDI.mAirline.equals( lWPG.getAirline() ))
				continue;

			if( !lWPG.ValidateDate( lTDI.mDepartureDay, lTDI.mReturnDay ))
			{
				mLogger.warn( "DoSearch: the departure date (" + lTDI.mDepartureDay + ") or the return date " +
						lTDI.mReturnDay + " expired!" );
				continue;
			}

			if( lTDI.mReturnDay.length() == 0 )
				lTDI.mReturnTicket = false;

			synchronized( lWPG.mMutex )
			{
				if( lWPG.mBrowser == null )
				{
					lWPG.InitBrowser( lPageIndex + 1 );
					lWPG.mBrowser.loadURL( "http://www.wizzair.com" );
				}
				lWPG.mSearchQueue.add( lTDI );
			}
			lPageIndex++;
			lPageIndex %= mWizzAirPageGuestList.size();
			lWPG = mWizzAirPageGuestList.get( lPageIndex );
		}
	}

	public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		if( !ValidateDate( aDepartureDate, aReturnDate ))
		{
			mLogger.warn( "DoSearch: the departure date (" + aDepartureDate + ") or the return date " +
					aReturnDate + " expired!" );
			return;
		}

		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser( 1 );
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
			lTravelDataInput.mAirline                 = getAirline();
			lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
			lTravelDataInput.mAirportCode_GoingTo     = aTo;
			lTravelDataInput.mDepartureDay            = aDepartureDate;
			lTravelDataInput.mReturnDay               = aReturnDate;
			lTravelDataInput.mAdultNumber             = "1";
			lTravelDataInput.mChildNumber             = "0";
			lTravelDataInput.mInfantNumber            = "0";
			//lTravelDataInput.mNearbyAirports          = false;
			if( aReturnDate.length() == 0 )
				lTravelDataInput.mReturnTicket = false;
			else
				lTravelDataInput.mReturnTicket = true;

			mSearchQueue.add( lTravelDataInput );
		}
		System.out.println("DoSearch()");
	}

	public void DoSearchFromConfig()
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser( 1 );
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
			for( TravelData_INPUT lTDI : lSearchList )
			{
				if( !lTDI.mAirline.equals( getAirline() ))
					continue;

				if( !ValidateDate( lTDI.mDepartureDay, lTDI.mReturnDay ))
				{
					mLogger.warn( "DoSearch: the departure date (" + lTDI.mDepartureDay + ") or the return date " +
							lTDI.mReturnDay + " expired!" );
					continue;
				}

				if( lTDI.mReturnDay.length() == 0 )
					lTDI.mReturnTicket = false;
				mSearchQueue.add( lTDI );
			}
		}
	}

	private boolean InitBrowser( int aBrowserIndex )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		new BrowserStateInit().doAction( this );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser(getAirline());

		boolean lNewWindow = false;
		if( mTabbedPane == null )
		{
			lNewWindow = true;
			mTabbedPane = new JTabbedPane();
		}

		mTabbedPane.addTab("Browser " + aBrowserIndex, new BrowserView(mBrowser));

		if( lNewWindow )
		{
			JFrame frame = new JFrame( "Travel Optimizer - " + getAirline() );
			frame.setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );
			frame.getContentPane().add( mTabbedPane, BorderLayout.CENTER );
			frame.setSize( 1152, 864 );
			frame.setLocationRelativeTo( null );
			frame.setVisible( true );
		}

		mBrowser.addLoadListener( new WizzAirPageGuest_LoadListener(this));

		System.out.println("InitBrowser()");
		return false;
	}

	private void setDOMInput( DOMDocument aDOMDocument, String aId, String aValue )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		DOMElement elementTextSource = aDOMDocument.findElement( By.id( aId ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		textInputSource.setValue( aValue );
	}

	private void setDOMSelect( DOMDocument aDOMDocument, String aId, String aValue )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		DOMElement elementAdultNumber = aDOMDocument.findElement( By.id( aId ) );
		DOMSelectElement selectAdultNumber = (DOMSelectElement)elementAdultNumber;
		java.util.List<DOMOptionElement> lOptionsAdultNumber = selectAdultNumber.getOptions();
		for( DOMOptionElement lDOMOptionElement : lOptionsAdultNumber )
		{
			if( lDOMOptionElement.getAttribute("value").equals( aValue ))
			{
				lDOMOptionElement.setSelected( true );
				break;
			}
		}
	}

	private void FillTheResultForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		// leaving from
		String lId    = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteOriginStation";
		String lValue = getAirportName( aTravelDataInput.mAirportCode_LeavingFrom ) +  " (" + aTravelDataInput.mAirportCode_LeavingFrom + ")";
		setDOMInput( aDOMDocument, lId, lValue );

		// we have to fill the hidden fields as well
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_OriginStation";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mAirportCode_LeavingFrom );

		// going to
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteDestinationStation";
		lValue = getAirportName( aTravelDataInput.mAirportCode_GoingTo ) +  " (" + aTravelDataInput.mAirportCode_GoingTo + ")";
		setDOMInput( aDOMDocument, lId, lValue );

		// we have to fill the hidden fields as well
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DestinationStation";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mAirportCode_GoingTo );

		// departure date
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DepartureDate";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mDepartureDay );

		// return date
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ReturnDate";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mReturnDay );

		// Adult id
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountADT";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mAdultNumber );

		// Children id
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountCHD";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mChildNumber );

		// Infant id
		lId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountINFANT";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mInfantNumber );

		System.out.println("FillTheResultForm()");
	}

	private void FillTheForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		mLogger.debug( "FillTheForm: " + aTravelDataInput.toString() );
		//DOMElement element = document.findElement( By.xpath("//textarea"));
		//DOMTextAreaElement textArea = (DOMTextAreaElement) element;

		// leaving from
		DOMElement elementTextSource = aDOMDocument.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation" ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		if( textInputSource == null )
		{
			FillTheResultForm( aDOMDocument, aTravelDataInput);
			return;
		}
		String lAirportLabel = getAirportName( aTravelDataInput.mAirportCode_LeavingFrom ) +  " (" + aTravelDataInput.mAirportCode_LeavingFrom + ")";
		textInputSource.setValue( lAirportLabel );

		// we have to fill the hidden fields as well
		String lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mAirportCode_LeavingFrom );

		// going to
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
		String lValue = getAirportName( aTravelDataInput.mAirportCode_GoingTo ) +  " (" + aTravelDataInput.mAirportCode_GoingTo + ")";
		setDOMInput( aDOMDocument, lId, lValue );

		// we have to fill the hidden fields as well
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ;
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mAirportCode_GoingTo );

		// departure date
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mDepartureDay );

		// return date
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate";
		setDOMInput( aDOMDocument, lId, aTravelDataInput.mReturnDay );

		// Adult id
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_PaxCountADT";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mAdultNumber );

		// Children id
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_PaxCountCHD";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mChildNumber );

		// Infant id
		lId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_PaxCountINFANT";
		setDOMSelect( aDOMDocument, lId, aTravelDataInput.mInfantNumber );

		System.out.println("FillTheForm()");
	}

	private void ClickTheSearchButton( DOMDocument aDOMDocument )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		Sleep( 1000 * Integer.parseInt( lSleep ));

		// click the button
		DOMNode link = aDOMDocument.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
		if( link == null )
			link = aDOMDocument.findElement( By.id( "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ButtonSubmit" ) );

		if( link != null )
		{
			mLogger.trace( "click, thread name: " + mThread.getName() );
			link.click();
		}
	}

	private void CollectDatas_ParseTheRows( DOMElement aFlightBodyElement, boolean aOutbound )
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		java.util.List<DOMElement> lRows = aFlightBodyElement.findElements( By.className( "flight-row" ) );
		if( lRows.size() == 0 )
			mLogger.warn( "Probably there is no flight for this search." );

		int lRowElementIndex = 0;
		for( DOMElement lRowElement : lRows )
		{
			if( lRowElementIndex == 0 )
			{
				// header of the table
			}
			else
			{
				// rows of the table with useful datas
				TravelData_RESULT.TravelData_PossibleTrip lTrip = new TravelData_RESULT.TravelData_PossibleTrip();
				lTrip.mOutboundTrip = aOutbound;
				java.util.List<DOMNode> lCells = lRowElement.getChildren();

				int lCellIndex = 0;
				for( DOMNode lCell : lCells )
				{
					if( lCellIndex == 0 )
					{
						// class: flight-data flight-date
						//          <span data-flight-departure="2016-04-08T07:45:00" data-flight-arrival="2016-04-08T09:40:00">Fri, 08 Apr</span>
						// "Fri, 08 Apr 8:45 → 10:40"
						java.util.List<DOMNode> lChildren = lCell.getChildren();

						lTrip.mDepartureDatetime = ((DOMElement)lChildren.get(0)).getAttribute("data-flight-departure");
						lTrip.mArrivalDatetime = ((DOMElement)lChildren.get(0)).getAttribute("data-flight-arrival");
						System.out.println( lTrip.mDepartureDatetime );

					}
					else if( lCellIndex == 1 )
					{
						// class: flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						java.util.List<DOMNode> lChildren = lCell.getChildren();
						lTrip.mPrices_BasicFare_Normal = ((DOMElement)lChildren.get(0)).getInnerText();
						if(( lTrip.mPrices_BasicFare_Normal.equals( "Elfogyott" ) ||
								lTrip.mPrices_BasicFare_Normal.equals( "A megadott napon nem találhatók járatok."))
								&& lTrip.mDepartureDatetime.length() == 0
								&& lTrip.mArrivalDatetime.length() == 0 )
						{
							mLogger.warn( lTrip.mPrices_BasicFare_Normal + ": " + mTravelDataResult.mTravelDataInput.toString() );
							lTrip = null;
							// the trip is invalid, the company out of tickets
							break;
						}
						lTrip.mPrices_BasicFare_Discount = ((DOMElement)lChildren.get(1)).getInnerText();
					}
					else if( lCellIndex == 2 )
					{
						// class: flight flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						java.util.List<DOMNode> lChildren = lCell.getChildren();
						lTrip.mPrices_PlusFare_Normal = ((DOMElement)lChildren.get(0)).getInnerText();
						lTrip.mPrices_PlusFare_Discount = ((DOMElement)lChildren.get(1)).getInnerText();
					}
					lCellIndex++;
				}
				if( lTrip != null )
					mTravelDataResult.mTrips.add( lTrip );
			}
			lRowElementIndex++;
		}
		System.out.println("CollectDatas_ParseTheRows()");
	}

	private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirline = aTravelDataInput.mAirline;
		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
		mTravelDataResult.mTravelDataInput = aTravelDataInput;
		//mTravelDataResult.mReturnTicket = aTravelDataInput.mReturnTicket;

		java.util.List<DOMElement> lFlightsBodyElements = document.findElements( By.className( "flights-body" ) );
		int lBodyElementIndex = 0;
		for( DOMElement lFlightBodyElement : lFlightsBodyElements )
		{
			try
			{
				if( lBodyElementIndex == 0 )
				{
					// Outbound trip
					CollectDatas_ParseTheRows( lFlightBodyElement, true );
				}
				else if( lBodyElementIndex == 1 )
				{
					// Return element
					CollectDatas_ParseTheRows( lFlightBodyElement, false );
				}
			}
			catch( Exception aException )
			{
				StringWriter lStringWriter = new StringWriter();
				PrintWriter lPrintWriter = new PrintWriter(lStringWriter);
				aException.printStackTrace( lPrintWriter );

				String lLogInformation = "Something wrong with the result parser or there is no flights?!\n" +
						aException.getMessage() + "\n" +
						lStringWriter.toString() + "\n" +
						aTravelDataInput.toString();
				mLogger.warn( lLogInformation );
			}
			lBodyElementIndex++;
		}

		ResultQueue.getInstance().push( mTravelDataResult );
		System.out.println("CollectDatas()");
	}

	public void run()
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		try
		{
			System.out.println( "Thread::run" );

			mThreadStopped = false;
			while( !mThreadStopped )
			{
				int lSearQueueSize;
				synchronized( mMutex )
				{
					lSearQueueSize = mSearchQueue.size();
				}

				if( getBrowserState() == null )
				{
					Sleep( 100 );
					continue;
				}

				String lBrowserState = getBrowserState().toString();
				if( ( lSearQueueSize == 0 && !lBrowserState.equals( "BrowserStateSearchingFinished" ) ) || lBrowserState.equals( "BrowserStateInit" ) )
				{
					Sleep( 100 );
					continue;
				}

				if( lBrowserState.equals( "BrowserStateSearchingFinished" ) )
				{
					BrowserStateSearchingFinished lState = (BrowserStateSearchingFinished)getBrowserState();
					TravelData_INPUT lTravelDataInput = lState.getTravelDataInput();
					DOMDocument lDOMDocument = lState.getDOMDocument();

					// The last search has been finished, collect the datas, start a new search
					CollectDatas( lDOMDocument, lTravelDataInput );
					new BrowserStateReadyToSearch( lDOMDocument ).doAction( this );
				}
				else if( lBrowserState.equals( "BrowserStateReadyToSearch" ) )
				{
					BrowserStateReadyToSearch lState = (BrowserStateReadyToSearch)getBrowserState();
					TravelData_INPUT lTravelDataInput;
					DOMDocument lDOMDocument = lState.getDOMDocument();

					synchronized( mMutex )
					{
						lTravelDataInput = mSearchQueue.remove( 0 );
					}
					new BrowserStateSearching( lTravelDataInput ).doAction( this );

					FillTheForm( lDOMDocument, lTravelDataInput );
					ClickTheSearchButton( lDOMDocument );
				}
			}
			System.out.println( "run()" );
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
	}

	public void stop()
	{
		mLogger.trace( "Thread name: " + mThread.getName() );
		mThreadStopped = true;
		try
		{
			mThread.join();
		}
		catch( InterruptedException e )
		{
			e.printStackTrace();
		}
		System.out.println("stop()");
		if( mBrowser != null )
			mBrowser.dispose();
	}
}
