package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.ProductInfo;
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
	private Thread mThread = null;

	private long mTimeoutStart;
	private boolean mThreadStopped = true;
	DOMDocument mDOMDocument;
	private boolean mAlreadyProcessed = false;

	public void Init()
	{
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
		frame.setSize( 1152, 864 );
		//frame.setLocationRelativeTo( null );
		frame.setLocation( 50, 50 );
		frame.setVisible( true );

		mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser( "Booking.com" );

		boolean lNewWindow = false;

		mBrowserView = new BrowserView( mBrowser );
		mTabbedPane.addTab( "Browser", mBrowserView );
		//mBrowser.addLoadListener( new WizzAirPageGuest_LoadListener(this));
		mBrowser.addLoadListener(new LoadAdapter() {
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
					if( event.isMainFrame() && !mAlreadyProcessed )
					{
						mAlreadyProcessed = true;
						System.out.println( "Main frame has finished loading" );

						FillTheForm( event.getBrowser().getDocument() );
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
				System.out.println("Frame document is loaded.");
			}

			@Override
			public void onDocumentLoadedInMainFrame(LoadEvent event) {
				System.out.println("Main frame document is loaded.");
			}
		});

		mBrowser.loadURL( getURL());
	}

	public BookingDotComPageGuest()
	{
		super( null, "http://www.booking.com" );
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

	public void FillTheForm_test( DOMDocument aDOMDocument )
	{
		mDOMDocument = aDOMDocument;
		//MouseMove( 1180, 824 );
		MouseLeftClick( 1180, 824 );
		Sleep( 500 );
		MouseLeftClick( 1180, 824 );
		Sleep( 500 );
		MouseMoveAround( 812, 592 );
		mDOMDocument = null;
	}

	// DEVEL
	public void FillTheForm( DOMDocument aDOMDocument )
	{
		mDOMDocument = aDOMDocument;

		// destination
		MouseLeftClick( 120, 326 );
		Sleep( 500 );
		PressCtrlA();
		Sleep( 500 );
		PressDelete();
		Sleep( 500 );
		TypeText( "Budapest, Pest, Hungary" );
		Sleep( 1000 );
		PressDown();
		Sleep( 1000 );
		TypeText( "\n" );
		Sleep( 1000 );
		TypeText( "\t" );
		Sleep( 1000 );

		// check-in
		TypeText( "24062017\t" );
		Sleep( 1000 );

		// check-out
		TypeText( "01072017\t" );
		Sleep( 1000 );

		// travelling for leisure radio
		if( !setChecked( "//*[@id=\"frm\"]/div[3]/div/div/fieldset/label[2]/input", true ))
			setChecked( "//*[@id=\"frm\"]/div[4]/div/div/fieldset/label[2]/input", true );

		Sleep( 1000 );

		// rooms select
		jQuerySetSelect( "no_rooms", "2" );

		Sleep( 1000 );

		// adults select
		jQuerySetSelect( "group_adults", "2" );

		Sleep( 1000 );

		// children select
		//setSelect( "//*[@id=\"group_children\"]", "4" );
		jQuerySetSelect( "group_children", "2" );

		Sleep( 1000 );

		// age1
		jQuerySetSelect2( "$('[data-group-child-age=\"0\"]')", "8" );

		Sleep( 1000 );

		// age2
		jQuerySetSelect2( "$('[data-group-child-age=\"1\"]')", "11" );
		//jQuerySetSelect2( "$('[data-group-child-age=\"2\"]')", "10" );
		//jQuerySetSelect2( "$('[data-group-child-age=\"3\"]')", "9" );
		Sleep( 1000 );

		// search button xpath
		//DOMElement lElement = mDOMDocument.findElement( By.xpath( "" ));
		//if( lElement != null )
		//	lElement.click();


		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').click();" );
		//mBrowser.executeJavaScript( "$('[data-sb-id=\"main\"]').submit();" );
		MouseLeftClick( 120, 326 );
		Sleep( 500 );
		TypeText( "\n" );
		Sleep( 1000 );

		mDOMDocument = null;
	}

	public void FillTheForm1( DOMDocument aDOMDocument )
	{
		mDOMDocument = aDOMDocument;

		// destination input field
		setTextField( "//*[@id=\"ss\"]", "Budapest" );

		// rooms select
		setSelect( "//*[@id=\"no_rooms\"]", "1" );

		// adults select
		setSelect( "//*[@id=\"group_adults\"]", "1" );

		// children select
		setSelect( "//*[@id=\"group_children\"]", "2" );

		// age1
		setSelect( "//*[@id=\"frm\"]/div[5]/div/div[2]/div[4]/select[1]", "8" );

		// age2
		setSelect( "//*[@id=\"frm\"]/div[5]/div/div[2]/div[4]/select[2]", "11" );

		// travelling for leisure radio
		setChecked( "//*[@id=\"frm\"]/div[3]/div/div/fieldset/label[2]/input", true );

		// check-in div: //*[@id="frm"]/div[4]/div/div[1]/div[1]/div/div/div[1]/div/div[2]
		// check-out div: //*[@id="frm"]/div[4]/div/div[1]/div[2]/div/div/div[1]/div/div[2]

		// search button xpath
		DOMElement lElement = mDOMDocument.findElement( By.xpath( "//*[@id=\"frm\"]/div[7]/button" ));
		lElement.click();

		mDOMDocument = null;
	}

	public void join()
	{
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
