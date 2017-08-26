package PageGuest;

import Configuration.Configuration;
import Util.StringHelper;
import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.ProductInfo;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.dom.DOMInputElement;
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
import java.util.ArrayList;
import java.util.HashSet;
import java.util.logging.Level;

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

/**
 * Created by Andras on 25/07/2017.
 */
public class AirbnbDotComPageGuest extends WebPageGuest implements Runnable
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( AirbnbDotComPageGuest.class );

	private static boolean mSTOP_AT_THE_FIRST_PAGE = false;

	private Browser mBrowser = null;
	private BrowserView mBrowserView = null;
	private JTabbedPane mTabbedPane = null;

	private DOMDocument mDOMDocument;
	private AirbnbDotComStatus mStatus = new AirbnbDotComStatus();

	private ArrayList<AccomodationData_INPUT> mInputList = new ArrayList<>();
	private int mInputListIndex = -1;
	private Integer mLoadReadyTimeout = -1;

	public class BrowserLoadAdapter extends LoadAdapter
	{
		private AirbnbDotComPageGuest mGuest;

		public BrowserLoadAdapter( AirbnbDotComPageGuest guest )
		{
			mGuest = guest;
		}

		@Override
		public void onStartLoadingFrame( StartLoadingEvent event )
		{
			if( event.isMainFrame() )
			{
				System.out.println("Main frame has started loading");
			}
		}

		@Override
		public void onProvisionalLoadingFrame( ProvisionalLoadingEvent event )
		{
			if( event.isMainFrame() )
			{
				System.out.println("Provisional load was committed for a frame");
			}
		}

		@Override
		public void onFinishLoadingFrame( FinishLoadingEvent event )
		{
			// A click után újra bejövök ide, erre ügyelni kell!!!!
			synchronized( this )
			{
				if( event.isMainFrame() )
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
		public void onFailLoadingFrame( FailLoadingEvent event )
		{
			NetError errorCode = event.getErrorCode();
			if( event.isMainFrame() )
			{
				mLogger.error( "Main frame has failed loading: " + errorCode );
			}
		}

		@Override
		public void onDocumentLoadedInFrame( FrameLoadEvent event )
		{
			synchronized( mLoadReadyTimeout )
			{
				mLoadReadyTimeout = 70;
				System.out.println("DocumentLoadedInFrame.");
			}
		}

		@Override
		public void onDocumentLoadedInMainFrame( LoadEvent event )
		{
			System.out.println("Main frame document is loaded.");
		}

	}

	public void Init()
	{
		DoSearchFromConfig();
		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		mTabbedPane = new JTabbedPane();
		JFrame frame = new JFrame( "Travel Optimizer - Booking.com - jxBrowser " + ProductInfo.getVersion() );

		frame.addWindowListener( new WindowAdapter()
		{
			@Override
			public void windowClosing( WindowEvent e )
			{
				mLogger.info( "Window is closing" );
				mThreadStopped = true;
				e.getWindow().dispose();
			}
		} );

		frame.getContentPane().add( mTabbedPane, BorderLayout.CENTER );
		frame.setSize( 1152, 964 );
		frame.setLocation( 50, 50 );
		frame.setVisible( true );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser( "Airbnb.com" );
		mBrowserView = new BrowserView( mBrowser );

		mTabbedPane.addTab( "Browser", mBrowserView );
		mBrowser.addLoadListener( new AirbnbDotComPageGuest.BrowserLoadAdapter( this ) );
		startANewSearch();
	}

	public void startANewSearch()
	{
		mStatus.starting( this );
//		mAccomodationDataResults = new ArrayList<>();
//		mHotelNames = new HashSet<>();
//		mResultSorted = false;
//		mHigherPriceCounter = HIGH_PRICE_FLAT_COUNT;
//		mMatchedAccomodationCounter = 0;
		mBrowser.loadURL( getURL() );
	}

	public AirbnbDotComPageGuest()
	{
		super( null, "https://www.airbnb.com" );
		//super( null, "http://localhost:8090" );
		mThread = new Thread( this );
		mThread.setName(
				"AirbnbDotComPageGuest " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME ) );
		mThread.start();
	}

	public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
	}

	public void DoSearchFromConfig()
	{
		ArrayList<AccomodationData_INPUT> lSearchList = Configuration.getInstance().getSearchListAccom();
		for( AccomodationData_INPUT lADI : lSearchList )
		{
			if( lADI.mSite != 'B' )
				continue;

			PageGuest.DateValidity lValidity = ValidateDate( lADI.mCheckIn, lADI.mCheckOut );

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
							if( mStatus.getStatus() == AirbnbDotComStatus.Status.FILLING_THE_FORM )
							{
								//mBrowser.executeJavaScript( "$(\"#GeocompleteController-via-SearchBar\").val(\"Budapest\").change();");
								mBrowser.executeJavaScript( "$(\"#GeocompleteController-via-SearchBar\").focus();");

//								DOMElement element = mDOMDocument.findElement( By.id( "GeocompleteController-via-SearchBar" ));
//								if( element != null )
//								{
//									System.out.println( "---------------------------------" );
//									//((DOMInputElement)element).setValue( "Budapest" );
//									element.click();
//								}
								mStatus.Done( this );
							}
//							if( mStatus.getStatus() == BookingDotComStatus.Status.APPLYING_A_FILTER && isResultPage( mBrowser.getDocument()))
//							{
//								//mBrowser.saveWebPage( "filtered_result.html", "c:\\temp", SavePageType.ONLY_HTML);
//								mLogger.info( "run Status: " + mStatus.getStatus());
//								mStatus.mainFrameLoaded( this, mBrowser.getDocument());
//							}
//							else if(( mStatus.getStatus() == BookingDotComStatus.Status.NEXT_PAGE_LOADING )
//									&& isResultPage( mBrowser.getDocument()))
//							{
//								mLogger.info("run Status: " + mStatus.getStatus());
//								mStatus.mainFrameLoaded( this, mBrowser.getDocument());
//							}
						}
					}
				}

			}
			catch( InterruptedException e )
			{
				mLogger.warn( StringHelper.getTraceInformation( e ) );
			}
		}
	}

	// DEVEL
	public void FillTheForm( DOMDocument aDOMDocument )
	{
		mStatus.fillingTheForm( this );
		mDOMDocument = aDOMDocument;

		//mBrowser.executeJavaScript( "$(\"#GeocompleteController-via-SearchBarLarge-via-HeaderController\").val(\"Budapest\").change();");
		//DOMElement element = findElementByAttrib( aDOMDocument, "span", "data-reactid", "214" );
		DOMElement element = findElementByAttrib( aDOMDocument, "button", "data-reactid", "209" );
		if( element != null )
		{
			//element.setInnerText( "Budapest" );
			element.click();
		}
		//DOMElement lElement = aDOMDocument.findElement( By.xpath(  ));
		Sleep( 3000 );

		//mStatus.formIsFilled( this );

		//mDOMDocument = null;
		//mStatus.searching( this );

		//mBrowser.executeJavaScript( "$(\"#GeocompleteController-via-SearchBar\").val(\"Budapest\").change();");
		//Sleep( 3000 );

	}

	public void printTheMatches()
	{

	}

	public boolean openTheNextHotel()
	{
		return false;
	}

	public boolean pageNext()
	{
		return false;
	}

	public void ApplyFilter( DOMDocument aDOMDocument )
	{

	}

	public void ParseTheResult( DOMDocument aDocument )
	{

	}

	public void ParseAHotelPage( DOMDocument aDocument )
	{

	}
}