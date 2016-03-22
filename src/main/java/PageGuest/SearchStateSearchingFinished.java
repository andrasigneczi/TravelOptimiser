package PageGuest;

import com.teamdev.jxbrowser.chromium.dom.DOMDocument;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class SearchStateSearchingFinished extends SearchState
{
    DOMDocument mDocument;
    TravelData_INPUT mTravelDataInput;

    public SearchStateSearchingFinished( DOMDocument aDocument, TravelData_INPUT aTravelDataInput )
    {
        mDocument = aDocument;
        mTravelDataInput = aTravelDataInput;
    }

    @Override
    public void doAction( WebPageGuest aWebPageGuest )
    {
        mWebPageGuest = aWebPageGuest;
        aWebPageGuest.setSearchState( this );
    }

    public String toString()
    {
        return "SearchStateSearchingFinished";
    }

    public TravelData_INPUT getTravelDataInput()
    {
        return mTravelDataInput;
    }
}
