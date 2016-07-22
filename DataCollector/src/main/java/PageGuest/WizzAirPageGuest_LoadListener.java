package PageGuest;

import BrowserState.BrowserStateReadyToSearch;
import BrowserState.BrowserStateSearching;
import BrowserState.BrowserStateSearchingFinished;
import com.teamdev.jxbrowser.chromium.dom.*;
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
		//synchronized( this )
		{
			if( event.isMainFrame() )
			{
				mLogger.trace( "begin, thread name: " + mPageGuest.getThreadName() );
				TravelData_INPUT lTravelDataInput = null;
				if( mPageGuest.getBrowserState().toString().equals( "BrowserStateSearching" ) )
				{
					lTravelDataInput = ( (BrowserStateSearching) mPageGuest.getBrowserState() ).getTravelDataInput();
				}

				DOMDocument lDOMDocument = event.getBrowser().getDocument();
				mLogger.trace(
						"thread name: " + mPageGuest.getThreadName() + "; Browser: " + java.lang.System.identityHashCode(
								event.getBrowser() ) );
				mLogger.trace(
						"thread name: " + mPageGuest.getThreadName() + "; DOMDocument: " + java.lang.System.identityHashCode(
								lDOMDocument ) );
				mLogger.trace(
						"thread name: " + mPageGuest.getThreadName() + "; Is lTravelDataInput null?: " + ( lTravelDataInput == null ) );

				if( lTravelDataInput == null )
				{
					new BrowserStateReadyToSearch( lDOMDocument ).doAction(
							mPageGuest.getBrowserState().getWebPageGuest() );
				}
				else
				{
					mLogger.trace(
							"thread name: " + mPageGuest.getThreadName() + "; lTravelDataInput: " + lTravelDataInput.toString() );
					//if( CheckTheReceivedDocument( lDOMDocument, lTravelDataInput ) )
					{
						new BrowserStateSearchingFinished( lDOMDocument, lTravelDataInput ).doAction(
								mPageGuest.getBrowserState().getWebPageGuest() );
					}
				}
				mLogger.trace( "end, thread name: " + mPageGuest.getThreadName() );
			}
		}
	}

	private boolean CheckDOMElementValue( DOMElement aElement, String aTraceLabel, String aValue )
	{
		if( aElement == null )
		{
			mLogger.error( "thread name: " + mPageGuest.getThreadName() + "; " + aTraceLabel + " is null" );
			return false;
		}
		else
		{
			if( aElement instanceof DOMInputElement)
			{
				String lValue = ((DOMInputElement)aElement).getValue();
				mLogger.trace(
						"thread name: " + mPageGuest.getThreadName() + "; " + aTraceLabel + ": " + lValue );
				boolean lResult = lValue.equals( aValue );
				if( !lResult )
					mLogger.error("thread name: " + mPageGuest.getThreadName()
							+ "; " + aTraceLabel + " is defferent" );
				return lResult;

			}
			else
			{
				if( aElement instanceof DOMSelectElement)
				{
					String lValue = ((DOMSelectElement)aElement).getValue();
					mLogger.trace(
							"thread name: " + mPageGuest.getThreadName() + "; " + aTraceLabel + ": " + lValue );
					boolean lResult = lValue.equals( aValue );
					if( !lResult )
						mLogger.error("thread name: " + mPageGuest.getThreadName()
								+ "; " + aTraceLabel + " is defferent" );
					return lResult;
				}

				mLogger.error(
						"thread name: " + mPageGuest.getThreadName() + "; DOMElement is not instance of DOMInputElement or DOMSelectElement" );
			}
		}
		return false;
	}

	private boolean CheckTheReceivedDocument( DOMDocument aDOMDocument, TravelData_INPUT aTravelData_input )
	{
		mLogger.trace( "begin, thread name: " + mPageGuest.getThreadName());

		// Inputs
		//String lLeavingFromId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteOriginStation";
		//String lGoingToId         = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_AutocompleteDestinationStation";
		String lLeavingFromHiddenId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_OriginStation";
		String lGoingToHiddenId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DestinationStation";
		String lDepartureDateId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_DepartureDate";
		String lReturnDateId        = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_ReturnDate";

		// Selects
		String lAdultId     = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountADT";
		String lChildrenlId = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountCHD";
		String lInfantlId   = "HeaderControlGroupRibbonSelectView_AvailabilitySearchInputRibbonSelectView_PaxCountINFANT";

		//if( !TraceInputElementValue( aDOMDocument.findElement( By.id( lLeavingFromId )), "LeavingFrom", aTravelData_input.mAirportCode_LeavingFrom ))
		//	return false;

		//TraceInputElementValue( "GoingTo", aDOMDocument.findElement( By.id( lGoingToId )));

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lLeavingFromHiddenId )), "LeavingFromHidden", aTravelData_input.mAirportCode_LeavingFrom ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lGoingToHiddenId )), "GoingToHidden", aTravelData_input.mAirportCode_GoingTo ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lDepartureDateId )), "DepartureDate", aTravelData_input.mDepartureDay ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lReturnDateId )), "ReturnDate", aTravelData_input.mReturnDay ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lAdultId )), "AdultCount", aTravelData_input.mAdultNumber ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lChildrenlId )), "ChildrenCount", aTravelData_input.mChildNumber ))
			return false;

		if( !CheckDOMElementValue( aDOMDocument.findElement( By.id( lInfantlId )), "InfantCount", aTravelData_input.mInfantNumber ))
			return false;

		mLogger.trace( "end, thread name: " + mPageGuest.getThreadName());
		return true;
	}
}
