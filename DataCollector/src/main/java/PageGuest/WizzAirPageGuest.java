/*
TODO: fill the adult-,infant-,children number and handle it.
 */

package PageGuest;

import BrowserState.BrowserStateInit;
import BrowserState.BrowserStateReadyToSearch;
import BrowserState.BrowserStateSearching;
import BrowserState.BrowserStateSearchingFinished;
import Util.StringHelper;
import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.teamdev.jxbrowser.chromium.swing.internal.HeavyWeightWidget;
import com.teamdev.jxbrowser.chromium.swing.internal.LightWeightWidget;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.RenderedImage;
import java.io.File;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.stream.IntStream;

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

/**
 * Created by Andras on 15/03/2016.
 */
public class WizzAirPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest.class);

	private Browser mBrowser = null;
	private BrowserView mBrowserView = null;
	private boolean mThreadStopped = true;
	private JTabbedPane mTabbedPane = null;
	private static ArrayList<WizzAirPageGuest> mWizzAirPageGuestList = null;
	private final static String SEARCH_PAGE_URL =  "https://wizzair.com/hu-HU/FlightSearch";
	private final static String AIRLINE = "wizzair";
	private final Random mRandom = new Random();

	public WizzAirPageGuest()
	{
		super( AIRLINE, SEARCH_PAGE_URL );
		mLogger.trace( "begin" );
		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );
		InitObject();
		mLogger.trace( "end" );
	}

	private WizzAirPageGuest( JTabbedPane aTabbedPane )
	{
		super( AIRLINE, SEARCH_PAGE_URL );
		mLogger.trace( "begin" );
		mTabbedPane = aTabbedPane;
		InitObject();
		mLogger.trace( "end" );
	}

	private void InitObject()
	{
		mLogger.trace( "begin" );
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread( this );
		mThread.setName( "WizzAirThread " + java.lang.System.identityHashCode(this) );
		mThread.start();
		mLogger.trace( "end" );
	}

	public static void StartMultiBrowser( int aBrowserCount )
	{
		mLogger.trace( "begin" );
		if( mWizzAirPageGuestList != null )
			return;

		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		JTabbedPane lTabbedPane = new JTabbedPane();
		JFrame frame = new JFrame( "Travel Optimizer - " + AIRLINE );
		frame.setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );
		frame.getContentPane().add( lTabbedPane, BorderLayout.CENTER );
		frame.setSize( 1152, 864 );
		frame.setLocationRelativeTo( null );
		frame.setVisible( true );

		mWizzAirPageGuestList = new ArrayList<WizzAirPageGuest>();
		IntStream.range(0,aBrowserCount).forEach( i ->  mWizzAirPageGuestList.add( new WizzAirPageGuest(lTabbedPane)));
		DoMultiSearchFromConfig();
		mLogger.trace( "end" );
	}

	public static void StopMultiBrowser()
	{
		mLogger.trace( "begin" );
		if( mWizzAirPageGuestList == null )
			return;

		for( WizzAirPageGuest lWPG : mWizzAirPageGuestList )
		{
			lWPG.stop();
		}
		mLogger.trace( "end" );
	}

	private static void DoMultiSearchFromConfig()
	{
		mLogger.trace( "begin" );
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
					lWPG.mBrowser.loadURL( lWPG.getURL() );
				}
				lWPG.mSearchQueue.add( lTDI );
			}
			lPageIndex++;
			lPageIndex %= mWizzAirPageGuestList.size();
			lWPG = mWizzAirPageGuestList.get( lPageIndex );
		}
		mLogger.trace( "end" );
	}

	public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
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
				mBrowser.loadURL( getURL() );
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
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	public void DoSearchFromConfig()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser( 1 );
				mBrowser.loadURL( getURL() );
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
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private boolean InitBrowser( int aBrowserIndex )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		new BrowserStateInit().doAction( this );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser(getAirline());

		boolean lNewWindow = false;
		if( mTabbedPane == null )
		{
			lNewWindow = true;
			mTabbedPane = new JTabbedPane();
		}

		mBrowserView = new BrowserView( mBrowser );
		mTabbedPane.addTab( "Browser " + aBrowserIndex, mBrowserView );

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

		mLogger.trace( "end, thread name: " + getThreadName());
		return false;
	}

	private void setDOMInput( DOMDocument aDOMDocument, String aId, String aValue )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		DOMElement elementTextSource = aDOMDocument.findElement( By.id( aId ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		textInputSource.setValue( aValue );
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void setDOMSelect( DOMDocument aDOMDocument, String aId, String aValue )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
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
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void FillTheResultForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
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

		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void FillTheForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
	{
		mLogger.trace( "begin, thread name: " + getThreadName() + "; aTravelDataInput: " + aTravelDataInput.toString());
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

		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void ClickTheSearchButton( DOMDocument aDOMDocument )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		Sleep( 1000 * ( Integer.parseInt( lSleep ) + ( mRandom.nextInt( 2 ) - 2 )));

		// click the button
		DOMNode link = aDOMDocument.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
		if( link == null )
			link = aDOMDocument.findElement( By.id( "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ButtonSubmit" ) );

		if( link != null )
		{
			mLogger.trace( "click, thread name: " + getThreadName() );
			link.click();
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void CollectDatas_ParseTheRows( DOMElement aFlightBodyElement, boolean aOutbound )
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		java.util.List<DOMElement> lRows = aFlightBodyElement.findElements( By.className( "flight-row" ) );
		if( lRows.size() == 0 && aOutbound )
			mLogger.warn( "Probably there is no flight for this search: " + mTravelDataResult.mTravelDataInput.toString() );

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
						mLogger.trace( "lTrip.mDepartureDatetime: " + lTrip.mDepartureDatetime );

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
				{
					mLogger.debug( lTrip.dump() );
					mTravelDataResult.mTrips.add( lTrip );
				}
			}
			lRowElementIndex++;
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	private void CollectDatas_Change_TravelDataInput( DOMDocument aDOMDocument )
	{
		// Inputs
		String lLeavingFromHiddenId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_OriginStation";
		String lGoingToHiddenId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DestinationStation";
		String lDepartureDateId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DepartureDate";
		String lReturnDateId        = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ReturnDate";
		// Selects
		String lAdultId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountADT";
		String lChildrenlId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountCHD";
		String lInfantlId   = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountINFANT";

		DOMElement lLeavingFromHidden = aDOMDocument.findElement( By.id( lLeavingFromHiddenId ));
		DOMElement lGoingToHidden = aDOMDocument.findElement( By.id( lGoingToHiddenId ));
		DOMElement lDepartureDate = aDOMDocument.findElement( By.id( lDepartureDateId ));
		DOMElement lReturnDate = aDOMDocument.findElement( By.id( lReturnDateId ));

		DOMElement lAdult = aDOMDocument.findElement( By.id( lAdultId ));
		DOMElement lChildren = aDOMDocument.findElement( By.id( lChildrenlId ));
		DOMElement lInfant = aDOMDocument.findElement( By.id( lInfantlId ));

		if( lLeavingFromHidden == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lLeavingFromHidden is null" );
			return;
		}
		if( lGoingToHidden == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lGoingToHidden is null" );
			return;
		}
		if( lDepartureDate == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lDepartureDate is null" );
			return;
		}
		if( lReturnDate == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lReturnDate is null" );
			return;
		}
		if( lAdult == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lAdult is null" );
			return;
		}
		if( lChildren == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lChildren is null" );
			return;
		}
		if( lInfant == null )
		{
			mLogger.error( "thread name: " + getThreadName() + "; lInfant is null" );
			return;
		}

		String lValue = ((DOMInputElement)lLeavingFromHidden).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mAirportCode_LeavingFrom ))
		{
			mLogger.error( "mAirportCode_LeavingFrom will be changed from "
					+ mTravelDataResult.mTravelDataInput.mAirportCode_LeavingFrom + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mAirportCode_LeavingFrom = lValue;
		}

		lValue = ((DOMInputElement)lGoingToHidden).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mAirportCode_GoingTo ))
		{
			mLogger.error( "mAirportCode_GoingTo will be changed from "
					+ mTravelDataResult.mTravelDataInput.mAirportCode_GoingTo + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mAirportCode_GoingTo = lValue;
		}

		lValue = ((DOMInputElement)lDepartureDate).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mDepartureDay ))
		{
			mLogger.error( "mDepartureDay will be changed from "
					+ mTravelDataResult.mTravelDataInput.mDepartureDay + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mDepartureDay = lValue;
		}

		lValue = ((DOMInputElement)lReturnDate).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mReturnDay ))
		{
			mLogger.error( "mReturnDay will be changed from "
					+ mTravelDataResult.mTravelDataInput.mReturnDay + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mReturnDay = lValue;
			if( lValue.length() == 0 )
				mTravelDataResult.mTravelDataInput.mReturnTicket = false;
		}

		lValue = ((DOMSelectElement)lAdult).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mAdultNumber ))
		{
			mLogger.error( "mAdultNumber be will changed from "
					+ mTravelDataResult.mTravelDataInput.mAdultNumber + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mAdultNumber = lValue;
		}

		lValue = ((DOMSelectElement)lChildren).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mChildNumber ))
		{
			mLogger.error( "mChildNumber be will changed from "
					+ mTravelDataResult.mTravelDataInput.mChildNumber + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mChildNumber = lValue;
		}

		lValue = ((DOMSelectElement)lInfant).getValue();
		if(!lValue.equals( mTravelDataResult.mTravelDataInput.mInfantNumber ))
		{
			mLogger.error( "mInfantNumber be will changed from "
					+ mTravelDataResult.mTravelDataInput.mInfantNumber + " to " + lValue );
			mTravelDataResult.mTravelDataInput.mInfantNumber = lValue;
		}
	}

	private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirline = aTravelDataInput.mAirline;
		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
		mTravelDataResult.mTravelDataInput = aTravelDataInput;
		//mTravelDataResult.mReturnTicket = aTravelDataInput.mReturnTicket;

		CollectDatas_Change_TravelDataInput( document );

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
				String lLogInformation = "Something wrong with the result parser or there is no flights?!\n" +
                        StringHelper.getTraceInformation( aException ) + "\n" +
						aTravelDataInput.toString();
				mLogger.warn( lLogInformation );
			}
			lBodyElementIndex++;
		}

		if( lFlightsBodyElements.size() == 0 )
		{
			// lBodyElementIndex = lBodyElementIndex;
			mLogger.error( "thread name: " + getThreadName() + "; Something wrong with the result page!! Image saved." );

			LightWeightWidget heavyWeightWidget = (LightWeightWidget)mBrowserView.getComponent(0);
			Image image = heavyWeightWidget.getImage();
			try
			{
				String lFileName = getAirline() + "_"
						+ LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME) + "_" + getThreadName()
						+ ".png";
				lFileName = lFileName.replace( ":", "" ).replace( " ", "" );
				ImageIO.write((RenderedImage)image, "PNG", new File( lFileName ));
			}
			catch( IOException e )
			{
				e.printStackTrace();
			}
		}

		// ellenőrzi a aTravelDataInput.DepartureDay és a trip.mDepartureDatetime egyezőségét
		boolean lWrongTripFound = false;
		for( TravelData_RESULT.TravelData_PossibleTrip lTrip : mTravelDataResult.mTrips )
		{
			if( !aTravelDataInput.mDepartureDay.replace(".", "").equals( lTrip.mDepartureDatetime.substring(0,10).replace("-", ""))
               && !aTravelDataInput.mReturnDay.replace(".", "").equals( lTrip.mDepartureDatetime.substring(0,10).replace("-", "")))
			{
				lWrongTripFound = true;
				break;
			}
		}

		if( lWrongTripFound )
		{
			mLogger.error( "thread name: " + getThreadName()
					+ "; Wrong trip found: aTravelDataInput: "
					+ aTravelDataInput.toString());

			for( TravelData_RESULT.TravelData_PossibleTrip lTrip : mTravelDataResult.mTrips )
			{
				mLogger.error( "thread name: " + getThreadName()
						+ "; Trip: "
						+ lTrip.dump() );
			}
		}

		ResultQueue.getInstance().push( mTravelDataResult );
        mTravelDataResult = null;
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	public void run()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
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
					mLogger.trace( "thread name: " + getThreadName() + "; Browser: " + java.lang.System.identityHashCode(mBrowser));
					mLogger.trace( "thread name: " + getThreadName() + "; DOMDocument: " + java.lang.System.identityHashCode(lDOMDocument)
							+ "; lBrowserState: " + lBrowserState );

					if( lTravelDataInput != null )
						mLogger.trace( "thread name: " + getThreadName() + "; lTravelDataInput: " + lTravelDataInput.toString());
					// The last search has been finished, collect the datas, start a new search
					CollectDatas( lDOMDocument, lTravelDataInput );
					new BrowserStateReadyToSearch( lDOMDocument ).doAction( this );
				}
				else if( lBrowserState.equals( "BrowserStateReadyToSearch" ) )
				{
					BrowserStateReadyToSearch lState = (BrowserStateReadyToSearch)getBrowserState();
					TravelData_INPUT lTravelDataInput;
					DOMDocument lDOMDocument = lState.getDOMDocument();
					mLogger.trace( "thread name: " + getThreadName() + "; Browser: " + java.lang.System.identityHashCode(mBrowser));
					mLogger.trace( "thread name: " + getThreadName() + "; DOMDocument: " + java.lang.System.identityHashCode(lDOMDocument)
									+ "; lBrowserState: " + lBrowserState );

					synchronized( mMutex )
					{
						lTravelDataInput = mSearchQueue.remove( 0 );
					}
					if( lTravelDataInput != null )
						mLogger.trace( "thread name: " + getThreadName() + "; lTravelDataInput: " + lTravelDataInput.toString());
					new BrowserStateSearching( lTravelDataInput ).doAction( this );

					FillTheForm( lDOMDocument, lTravelDataInput );
					ClickTheSearchButton( lDOMDocument );
				}
			}
		}
		catch( Exception aException )
		{
			mLogger.error(StringHelper.getTraceInformation( aException ) );
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}

	public void stop()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
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
		mLogger.trace( "end, thread name: " + getThreadName());
	}
}
