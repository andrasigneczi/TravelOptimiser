package BrowserState;

import PageGuest.TravelData_INPUT;
import PageGuest.WebPageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class BrowserStateSearching extends BrowserState
{
    TravelData_INPUT mTravelDataInput;

    public BrowserStateSearching( TravelData_INPUT aTravelDataInput )
    {
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
        return "BrowserStateSearching";
    }

    public TravelData_INPUT getTravelDataInput()
    {
        return mTravelDataInput;
    }
}
