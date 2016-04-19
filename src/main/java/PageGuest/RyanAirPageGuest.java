package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
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
		super();
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
				mBrowser.loadURL( "http://www.wizzair.com" );
			}

			TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
			lTravelDataInput.mAirline                 = "ryanair";
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

	@Override
	public void stop()
	{

	}

	public void run()
	{

	}
}
