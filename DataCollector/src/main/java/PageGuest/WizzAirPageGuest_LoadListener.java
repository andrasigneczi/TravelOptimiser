package PageGuest;

import BrowserState.BrowserStateReadyToSearch;
import BrowserState.BrowserStateSearching;
import BrowserState.BrowserStateSearchingFinished;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.dom.DOMInputElement;
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
			mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; Browser: " + java.lang.System.identityHashCode(event.getBrowser()));
			mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; DOMDocument: " + java.lang.System.identityHashCode(lDOMDocument));
			mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; Is lTravelDataInput null?: " + ( lTravelDataInput == null ) );

			if( lTravelDataInput == null )
			{
				new BrowserStateReadyToSearch( lDOMDocument ).doAction(
						mPageGuest.getBrowserState().getWebPageGuest() );
			}
			else
			{
				CheckTheReceivedDocument( lDOMDocument );
				mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; lTravelDataInput: " + lTravelDataInput.toString());
				new BrowserStateSearchingFinished( lDOMDocument, lTravelDataInput ).doAction(
						mPageGuest.getBrowserState().getWebPageGuest() );
			}
			mLogger.trace( "end, thread name: " + mPageGuest.getThreadName());
		}
	}

	private void TraceInputElementValue( String aLabel, DOMElement aElement )
	{
		if( aElement == null )
		{
			mLogger.error( "thread name: " + mPageGuest.getThreadName() + "; " + aLabel + " is null" );
		}
		else
		{
			if( aElement instanceof DOMInputElement)
				mLogger.trace(
					"thread name: " + mPageGuest.getThreadName() + "; " + aLabel + ": " + ( (DOMInputElement) aElement ).getValue() );
			else
				mLogger.error( "thread name: " + mPageGuest.getThreadName() + "; DOMElement is not instance of DOMInputElement" );
		}
	}

	private void CheckTheReceivedDocument( DOMDocument aDOMDocument )
	{
		mLogger.trace( "thread name: " + mPageGuest.getThreadName() + "; DOMDocument fields' values: " );

		String lLeavingFromId    = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteOriginStation";
		String lLeavingFromHiddenId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_OriginStation";
		String lGoingToId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteDestinationStation";
		String lGoingToHiddenId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DestinationStation";
		String lDepartureDateId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DepartureDate";
		String lReturnDateId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ReturnDate";

		TraceInputElementValue( "LeavingFrom", aDOMDocument.findElement( By.id( lLeavingFromId )));
		TraceInputElementValue( "LeavingFromHidden", aDOMDocument.findElement( By.id( lLeavingFromHiddenId )));
		TraceInputElementValue( "GoingTo", aDOMDocument.findElement( By.id( lGoingToId )));
		TraceInputElementValue( "GoingToHidden", aDOMDocument.findElement( By.id( lGoingToHiddenId )));
		TraceInputElementValue( "DepartureDate", aDOMDocument.findElement( By.id( lDepartureDateId )));
		TraceInputElementValue( "ReturnDate", aDOMDocument.findElement( By.id( lReturnDateId )));
	}
}
