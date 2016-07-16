package PageGuest;

import BrowserState.BrowserStateReadyToSearch;
import BrowserState.BrowserStateSearching;
import BrowserState.BrowserStateSearchingFinished;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 22/06/2016.
 */
public class WizzAirPageGuest_LoadListener extends LoadAdapter
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest_LoadListener.class);
	WebPageGuest mPageGuest;

	public WizzAirPageGuest_LoadListener( WebPageGuest aPageGuest )
	{
		mPageGuest = aPageGuest;
	}

	@Override
	public void onFinishLoadingFrame(FinishLoadingEvent event) {
		// A click után újra bejövök ide, erre ügyelni kell!!!!
		if (event.isMainFrame())
		{
			mLogger.trace( "begin, thread name: " + mPageGuest.getThreadName());
			TravelData_INPUT lTravelDataInput = null;
			if( mPageGuest.getBrowserState().toString().equals( "BrowserStateSearching" ))
			{
				lTravelDataInput = ((BrowserStateSearching)mPageGuest.getBrowserState()).getTravelDataInput();
			}

			DOMDocument lDOMDocument = event.getBrowser().getDocument();
			mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; DOMDocument: " + java.lang.System.identityHashCode(lDOMDocument));
			if( lTravelDataInput == null )
				new BrowserStateReadyToSearch( lDOMDocument ).doAction( mPageGuest.getBrowserState().getWebPageGuest());
			else
				new BrowserStateSearchingFinished( lDOMDocument, lTravelDataInput ).doAction( mPageGuest.getBrowserState().getWebPageGuest() );
			mLogger.trace( "is lTravelDataInput null?: " + lTravelDataInput == null );
			mLogger.trace( "end, thread name: " + mPageGuest.getThreadName());
		}
	}
}
