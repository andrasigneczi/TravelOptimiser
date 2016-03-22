package PageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class SearchStateSearching extends SearchState
{
    TravelData_INPUT mTravelDataInput;

    public SearchStateSearching( TravelData_INPUT aTravelDataInput )
    {
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
        return "SearchStateSearching";
    }

    public TravelData_INPUT getTravelDataInput()
    {
        return mTravelDataInput;
    }
}
