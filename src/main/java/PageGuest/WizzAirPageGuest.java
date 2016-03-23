package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 15/03/2016.
 */
public class WizzAirPageGuest extends WebPageGuest implements Runnable
{
	ArrayList<TravelData_INPUT> mSearchQueue;
	Thread mThread;
	Browser mBrowser = null;
	Object mMutex = new Object();
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
		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser();
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
			lTravelDataInput.mAirlines                = "wizzair";
			lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
			lTravelDataInput.mAirportCode_GoingTo     = aTo;
			lTravelDataInput.mDepartureDay            = aDepartureDate;
			lTravelDataInput.mReturnDay               = aReturnDate;
			if( aReturnDate.length() == 0 )
				lTravelDataInput.mReturnTicket = false;
			else
				lTravelDataInput.mReturnTicket = true;

			mSearchQueue.add( lTravelDataInput );
		}
		System.out.println("DoSearch()");
	}

	private boolean InitBrowser()
	{
		new BrowserStateInit().doAction( this );

		mBrowser = new Browser();
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
					return;



/*
					DOMDocument document = event.getBrowser().getDocument();
					if( !getBrowserState().toString().equals( "BrowserStateInit" ))
					{
						CollectDatas( document );
						new BrowserStateSearchingFinished( document ).doAction( getBrowserState().getWebPageGuest() );
						return;
					}

					TravelData_INPUT lTravelDataInput;
					synchronized( mMutex )
					{
						lTravelDataInput = mSearchQueue.remove( 0 );
					}
					new BrowserStateSearching( lTravelDataInput ).doAction( getBrowserState().getWebPageGuest() );

					FillTheForm(document);

					// click the button
					DOMNode link = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
					if( link != null )
					{
						link.click();
					}
*/
				}
			}
		});

		System.out.println("InitBrowser()");
		return false;
	}

	private void FillTheResultForm(DOMDocument document, TravelData_INPUT aTravelDataInput )
	{

	}

	private void FillTheForm(DOMDocument document, TravelData_INPUT aTravelDataInput )
	{
		//DOMElement element = document.findElement( By.xpath("//textarea"));
		//DOMTextAreaElement textArea = (DOMTextAreaElement) element;

		// source
		DOMElement elementTextSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation" ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		String lAirportLabel = getAirportName( aTravelDataInput.mAirportCode_LeavingFrom ) +  " (" + aTravelDataInput.mAirportCode_LeavingFrom + ")";
		textInputSource.setValue( lAirportLabel );

		// we have to fill the hidden fields as well
		DOMElement elementIdSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation" ) );
		DOMInputElement hiddenInputSource = (DOMInputElement)elementIdSource;
		hiddenInputSource.setValue( aTravelDataInput.mAirportCode_LeavingFrom );

		// target
		String lTargetInputId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
		DOMElement elementTextTarget = document.findElement( By.id( lTargetInputId ) );
		DOMInputElement textInputTarget = (DOMInputElement)elementTextTarget;
		lAirportLabel = getAirportName( aTravelDataInput.mAirportCode_GoingTo ) +  " (" + aTravelDataInput.mAirportCode_GoingTo + ")";
		textInputTarget.setValue( lAirportLabel );

		// we have to fill the hidden fields as well
		DOMElement elementIdTarget = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ) );
		DOMInputElement hiddenInputTarget = (DOMInputElement)elementIdTarget;
		hiddenInputTarget.setValue( aTravelDataInput.mAirportCode_GoingTo );

		// departure date
		DOMElement elementIdDepartureDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate" ) );
		DOMInputElement inputDepartureDate = (DOMInputElement)elementIdDepartureDate;
		inputDepartureDate.setValue( aTravelDataInput.mDepartureDay );

		// arrival date
		DOMElement elementIdReturnDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate" ) );
		DOMInputElement inputReturnDate = (DOMInputElement)elementIdReturnDate;
		inputReturnDate.setValue( aTravelDataInput.mReturnDay );
		System.out.println("FillTheForm()");
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

						lTrip.mDepartureDaytime = ((DOMElement)lChildren.get(0)).getAttribute("data-flight-departure");
						lTrip.mArrivalDaytime = ((DOMElement)lChildren.get(0)).getAttribute("data-flight-arrival");

					}
					else if( lCellIndex == 1 )
					{
						// class: flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						java.util.List<DOMNode> lChildren = lCell.getChildren();
						lTrip.mPrices_BasicFare_Normal = lChildren.get(0).getTextContent();
						lTrip.mPrices_BasicFare_Discount = lChildren.get(1).getTextContent();
					}
					else if( lCellIndex == 2 )
					{
						// class: flight flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						java.util.List<DOMNode> lChildren = lCell.getChildren();
						lTrip.mPrices_PlusFare_Normal = lChildren.get(0).getTextContent();
						lTrip.mPrices_PlusFare_Discount = lChildren.get(1).getTextContent();
					}
					lCellIndex++;
				}
				mTravelDataResult.mTrips.add( lTrip );
			}
			lRowElementIndex++;
		}
		System.out.println("CollectDatas_ParseTheRows()");
	}

	private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
	{
		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirlines = aTravelDataInput.mAirlines;
		mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
		mTravelDataResult.mReturnTicket = mTravelDataResult.mReturnTicket;

		java.util.List<DOMElement> lFlightsBodyElements = document.findElements( By.className( "flights-body" ) );
		int lBodyElementIndex = 0;
		for( DOMElement lFlightBodyElement : lFlightsBodyElements )
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
			lBodyElementIndex++;
		}

		ResultQueue.getInstance().push( mTravelDataResult );
		System.out.println("CollectDatas()");
	}

	public void run()
	{
		mThreadStopped = false;
		while( !mThreadStopped )
		{
			int lSearQueueSize;
			synchronized( mMutex )
			{
				lSearQueueSize = mSearchQueue.size();
			}

			String lBrowserState = getBrowserState().toString();
			if(( lSearQueueSize == 0 && !lBrowserState.equals( "BrowserStateSearchingFinished" )) || lBrowserState.equals( "BrowserStateInit" ))
				{
				try
				{
					Thread.sleep( 100 );
				}
				catch( InterruptedException e )
				{
					e.printStackTrace();
				}
				continue;
			}

			if( lBrowserState.equals( "BrowserStateSearchingFinished" ))
			{
				BrowserStateSearchingFinished lState = (BrowserStateSearchingFinished)getBrowserState();
				TravelData_INPUT lTravelDataInput = lState.getTravelDataInput();
				DOMDocument lDOMDocument = lState.getDOMDocument();

				// The last search has been finished, collect the datas, start a new search
				CollectDatas( lDOMDocument, lTravelDataInput );
				new BrowserStateReadyToSearch( lDOMDocument ).doAction( this );
			}
			else if( lBrowserState.equals( "BrowserStateReadyToSearch" ))
			{
				BrowserStateReadyToSearch lState = (BrowserStateReadyToSearch)getBrowserState();
				TravelData_INPUT lTravelDataInput;
				DOMDocument lDOMDocument = lState.getDOMDocument();

				synchronized( mMutex )
				{
					lTravelDataInput = mSearchQueue.remove( 0 );
				}
				new BrowserStateSearching( lTravelDataInput ).doAction( this );

				FillTheForm(lDOMDocument, lTravelDataInput);

				// click the button
				DOMNode link = lDOMDocument.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
				if( link != null )
				{
					link.click();
				}
			}
		}
		System.out.println("run()");
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
	}
}
