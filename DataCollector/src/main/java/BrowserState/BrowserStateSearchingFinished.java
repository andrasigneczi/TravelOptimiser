package BrowserState;

import PageGuest.TravelData_INPUT;
import PageGuest.WebPageGuest;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class BrowserStateSearchingFinished extends BrowserState
{
    DOMDocument mDOMDocument;
    TravelData_INPUT mTravelDataInput;

    public BrowserStateSearchingFinished( DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput )
    {
        mDOMDocument = aDOMDocument;
        mTravelDataInput = aTravelDataInput;
    }

    @Override
    public void doAction( WebPageGuest aWebPageGuest )
    {
        mWebPageGuest = aWebPageGuest;
        aWebPageGuest.setBrowserState( this );
    }

    public String toString()
    {
        return "BrowserStateSearchingFinished";
    }

    public TravelData_INPUT getTravelDataInput()
    {
        return mTravelDataInput;
    }
    public void setTravelDataInput( TravelData_INPUT  lTravelDataInput )
    {
        mTravelDataInput = lTravelDataInput;
    }
    public DOMDocument getDOMDocument()
    {
        return mDOMDocument;
    }
}
