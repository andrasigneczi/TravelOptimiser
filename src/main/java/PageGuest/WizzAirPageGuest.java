/*
TODO: fill the adult-,infant-,children number and handle it.
 */

package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.security.auth.login.Configuration;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 15/03/2016.
 */
public class WizzAirPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest.class);

	ArrayList<TravelData_INPUT> mSearchQueue;
	Thread  mThread;
	Browser mBrowser = null;
	Object  mMutex = new Object();
	boolean mThreadStopped = true;

	public WizzAirPageGuest()
	{
		super();
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread( this );
		mThread.setName( "WizzAirThread " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME ) );
		mThread.start();
		System.out.println("WizzAirPageGuest()");
	}

	public boolean OpenStartPage()
	{
		return false;
	}
	public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
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
				InitBrowser();
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
			lTravelDataInput.mAirline                 = "wizzair";
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
		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser();
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
			for( TravelData_INPUT lTDI : lSearchList )
			{
				if( !lTDI.mAirline.equals( "wizzair" ))
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

	private boolean ValidateDate( String aDepartureDay, String aReturnDay )
	{
		try
		{
			DateTimeFormatter lFormatter = DateTimeFormatter.ofPattern( "yyyy.MM.dd." );
			LocalDate lDepartureDay = LocalDate.parse( aDepartureDay, lFormatter );
			if( LocalDate.now().isAfter( lDepartureDay ) )
			{
				return false;
			}

			if( aDepartureDay.length() == 0 )
				return true;

			LocalDate lReturnDay = LocalDate.parse( aReturnDay, lFormatter );
			if( lReturnDay.isBefore( lDepartureDay ) )
				return false;
			return true;
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
		return false;
	}

	private boolean InitBrowser()
	{
		new BrowserStateInit().doAction( this );

		//mBrowser = new Browser();
		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser();
		BrowserView view = new BrowserView(mBrowser);

		//final JTextField addressBar = new JTextField("http://www.teamdev.com/jxbrowser");
		//final JTextField addressBar = new JTextField("http://www.momondo.com");
//		final JTextField addressBar = new JTextField("http://www.wizzair.com");
//		addressBar.addActionListener(new ActionListener() {
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				mBrowser.loadURL(addressBar.getText());
//			}
//		});

//		JPanel addressPane = new JPanel(new BorderLayout());
//		addressPane.add(new JLabel(" URL: "), BorderLayout.WEST);
//		addressPane.add(addressBar, BorderLayout.CENTER);

		JFrame frame = new JFrame("Travel Optimizer");
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//		frame.add(addressPane, BorderLayout.NORTH);
		frame.add(view, BorderLayout.CENTER);
		frame.setSize(1152, 864);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		mBrowser.addLoadListener(new LoadAdapter() {
			@Override
			public void onFinishLoadingFrame(FinishLoadingEvent event) {
				// A click után újra bejövök ide, erre ügyelni kell!!!!
				if (event.isMainFrame())
				{
					TravelData_INPUT lTravelDataInput = null;
					if( getBrowserState().toString().equals( "BrowserStateSearching" ))
					{
						lTravelDataInput = ((BrowserStateSearching)getBrowserState()).getTravelDataInput();
					}

					DOMDocument lDOMDocument = event.getBrowser().getDocument();
					if( lTravelDataInput == null )
						new BrowserStateReadyToSearch( lDOMDocument ).doAction( getBrowserState().getWebPageGuest());
					else
						new BrowserStateSearchingFinished( lDOMDocument, lTravelDataInput ).doAction( getBrowserState().getWebPageGuest() );
					System.out.println("addLoadListener()");
				}
			}
		});

		System.out.println("InitBrowser()");
		return false;
	}

	private void setDOMInput( DOMDocument aDOMDocument, String aId, String aValue )
	{
		DOMElement elementTextSource = aDOMDocument.findElement( By.id( aId ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		textInputSource.setValue( aValue );
	}

	private void setDOMSelect( DOMDocument aDOMDocument, String aId, String aValue )
	{
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
		String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		try
		{
			Thread.sleep( 1000 * Integer.parseInt( lSleep ) );
		}
		catch( InterruptedException e )
		{
			e.printStackTrace();
		}
		// click the button
		DOMNode link = aDOMDocument.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
		if( link == null )
			link = aDOMDocument.findElement( By.id( "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ButtonSubmit" ) );

		if( link != null )
		{
			link.click();
		}
	}

	private void CollectDatas_ParseTheRows( DOMElement aFlightBodyElement, boolean aOutbound )
	{
		java.util.List<DOMElement> lRows = aFlightBodyElement.findElements( By.className( "flight-row" ) );
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
				TravelData_RESULT.TravelData_PossibleTrips lTrip = new TravelData_RESULT.TravelData_PossibleTrips();
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
						if( lTrip.mPrices_BasicFare_Normal.equals( "Elfogyott" ) &&
								lTrip.mDepartureDatetime.length() == 0 &&
								lTrip.mArrivalDatetime.length() == 0 )
						{
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

				String lLogInformation = "Something wrong with the result parser!\n" +
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

	private void Sleep( int aValue )
	{
		try
		{
			Thread.sleep( aValue );
		}
		catch( InterruptedException e )
		{
			e.printStackTrace();
		}
	}

	public void run()
	{
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
		mBrowser.dispose();
	}
}
