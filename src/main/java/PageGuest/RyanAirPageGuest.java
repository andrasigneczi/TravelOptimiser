package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.dom.DOMInputElement;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.events.RenderAdapter;
import com.teamdev.jxbrowser.chromium.events.RenderEvent;
import com.teamdev.jxbrowser.chromium.javafx.internal.KeyModifiers;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 15/03/2016.
 */
public class RyanAirPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest.class);

	ArrayList<TravelData_INPUT> mSearchQueue;
	Thread                      mThread;
	Browser mBrowser       = null;
	Object  mMutex         = new Object();
	boolean mThreadStopped = true;

	public RyanAirPageGuest()
	{
		super( "ryanair" );
		mSearchQueue = new ArrayList<TravelData_INPUT>();
		mThread = new Thread( this );
		mThread.setName( "RyanAirThread " + LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME ) );
		mThread.start();
		System.out.println("RyanAirPageGuest()");
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
				mBrowser.loadURL( "http://www.ryanair.com" );
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
		synchronized( mMutex )
		{
			if( mBrowser == null )
			{
				InitBrowser();
				mBrowser.loadURL( "http://www.ryanair.com" );
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

	private boolean ValidateDate( String aDepartureDay, String aReturnDay )
	{
		try
		{
			DateTimeFormatter lFormatter    = DateTimeFormatter.ofPattern( "yyyy.MM.dd." );
			LocalDate         lDepartureDay = LocalDate.parse(aDepartureDay, lFormatter );
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
		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser( getAirline());
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
		frame.setLocation( 0, 0 );
		//frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		mBrowser.addLoadListener(new LoadAdapter() {
			@Override
			public void onFinishLoadingFrame(FinishLoadingEvent event) {
				// A click után újra bejövök ide, erre ügyelni kell!!!!
				if (event.isMainFrame())
				{

					DOMElement elementTextSource = null;
					do
					{
						elementTextSource = mBrowser.getDocument().findElement(By.name("departureAirportName" ) );
						if( elementTextSource == null )
							Sleep( 1000 );
					}
					while( elementTextSource == null );

					TravelData_INPUT lTravelDataInput = null;
					if( getBrowserState().toString().equals( "BrowserStateSearching" ))
					{
						lTravelDataInput = ((BrowserStateSearching)getBrowserState()).getTravelDataInput();
					}

					DOMDocument lDOMDocument = mBrowser.getDocument();
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

	@Override
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
	}

	private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
	{

	}

	private void setDOMDivValue( DOMDocument aDOMDocument, String aXPath, String aValue )
	{
		DOMElement lDOMElement = aDOMDocument.findElement(By.xpath( aXPath ));
		lDOMElement.setAttribute( "value", aValue );
	}

	private void setDOMInput( DOMDocument aDOMDocument, String aXPath, String aValue )
	{
		DOMElement lDOMElement = aDOMDocument.findElement(By.xpath( aXPath ));
		DOMInputElement lDOMImputElement = (DOMInputElement)lDOMElement;
		lDOMImputElement.setValue( aValue );
	}

	private void javaScriptSetFocus( String aXPath )
	{
		final String lGetElementByXPath = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";
		mBrowser.executeJavaScript( String.format( lGetElementByXPath + ".focus();", aXPath ));
	}

	private void javaScriptSubmit( String aXPath )
	{
		final String lGetElementByXPath = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";
		mBrowser.executeJavaScript( String.format( lGetElementByXPath + ".submit();", aXPath ));
	}

	private void javaSendKeys( String aXPath, int aKey )
	{
		final String lGetElementByXPath = "TraveDataOptimizer = document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue;TraveDataOptimizer.sendkeys(" + String.format( "%d", aKey ) + ");";
		mBrowser.executeJavaScript( String.format( lGetElementByXPath, aXPath ));
	}

	private void javaScriptClick( String aXPath )
	{
		final String lGetElementByXPath = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";
		mBrowser.executeJavaScript( String.format( lGetElementByXPath + ".click();", aXPath ));
	}

	private void FillTheForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
	{
		String lAirportLabel = "Budapest";
		String lAirportLabel2 = "Brussels (CRL)";

		// leaving from
		//javaSendKeys( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", '\t' );
		//javaSendKeys( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", 66 );
		//javaSendKeys( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", 67 );
		//javaScriptClick( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input" );
		//DOMElement lButton = aDOMDocument.findElement(By.xpath( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input" ));
		//lButton.click();
		//javaScriptSetFocus("//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input");
		//javaSendKeys( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", 'B' );
		//setDOMInput( aDOMDocument, "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", lAirportLabel );
		//javaSendKeys( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]/div[2]/div/div[1]/input", 'B' );
		//setDOMDivValue( aDOMDocument, "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[1]/div[2]", lAirportLabel );

		mRobot.delay( 1000 );
		// Simulate a mouse click
		mRobot.mouseMove( 175, 460 );
		mRobot.mousePress(InputEvent.BUTTON1_MASK);
		mRobot.mouseRelease(InputEvent.BUTTON1_MASK);

		// Simulate a key press
		PressCtrlA();
		PressDelete();
		TypeText( "Budapest\t");

		mRobot.delay(500);

		mRobot.mouseMove( 500, 460 );
		mRobot.mousePress(InputEvent.BUTTON1_MASK);
		mRobot.mouseRelease(InputEvent.BUTTON1_MASK);

		PressCtrlA();
		PressDelete();
		TypeText( "Brussels (CRL)\n");
		mRobot.delay(1000);
		TypeText( "01072016\t");
		TypeText( "03072016\t");
//
//		mRobot.delay( 1000 );
//		// Simulate a mouse click
//		mRobot.mouseMove( 834, 455 );
//		mRobot.mousePress(InputEvent.BUTTON1_MASK);
//		mRobot.mouseRelease(InputEvent.BUTTON1_MASK);

//
//		// going to
//		javaScriptSetFocus( "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[2]/div[2]/div[2]/div/div[1]/input" );
//		//setDOMInput( aDOMDocument, "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[2]/div[2]/div[2]/div/div[1]/input", lAirportLabel2 );
//		//setDOMDivValue( aDOMDocument, "//*[@id=\"search-container\"]/div/div/form/div[1]/div[2]/div/div[2]/div[2]", lAirportLabel2 );
//
//		// click on continue
//		DOMElement lButton = aDOMDocument.findElement(By.xpath( "//*[@id=\"search-container\"]/div/div/form/div[3]/button[1]" ));
//		lButton.click();
//
//		// waiting for the javascript
//		Sleep( 2000 );
//
//		// setfocus on day field using javascript finding by xpath
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[1]" );
//
//		// fly out day month year
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[1]", "01" );
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[2]" );
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[2]", "07" );
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[3]" );
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[1]/div/div[2]/div[2]/div/input[3]", "2016" );
//
//		// fly back day month year
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[1]" );
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[1]", "03" );
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[2]" );
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[2]", "07" );
//		javaScriptSetFocus( "//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[3]" );
//		setDOMInput( aDOMDocument,"//*[@id=\"row-dates-pax\"]/div[1]/div/div[2]/div/div[2]/div[2]/div/input[3]", "2016" );
//
//		//String lAirportLabel = getAirportName( aTravelDataInput.mAirportCode_LeavingFrom ) +  " (" + aTravelDataInput.mAirportCode_LeavingFrom + ")";
//
//		//javaScriptSubmit( "//*[@id=\"search-container\"]/div/div/form" );
//
//		// passengers
	}

	private void ClickTheSearchButton( DOMDocument aDOMDocument )
	{
		String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
		Sleep( 1000 * Integer.parseInt( lSleep ));

		DOMElement lButton = aDOMDocument.findElement(By.xpath( "//*[@id=\"search-container\"]/div/div/form/div[3]/button[2]" ));

		if( lButton != null )
		{
			lButton.click();
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
					//ClickTheSearchButton( lDOMDocument );
				}
			}
			System.out.println( "run()" );
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
	}
}
