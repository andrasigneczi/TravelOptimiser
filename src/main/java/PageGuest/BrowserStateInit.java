package PageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public class BrowserStateInit extends BrowserState
{
    @Override
    public void doAction( WebPageGuest aWebPageGuest )
    {
        mWebPageGuest = aWebPageGuest;
        aWebPageGuest.setBrowserState( this );
    }

    public String toString()
    {
        return "BrowserStateInit";
    }
}
