package PageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public abstract class SearchState
{
    WebPageGuest mWebPageGuest = null;

    public abstract void doAction( WebPageGuest aWebPageGuest );

    public WebPageGuest getWebPageGuest()
    {
        return mWebPageGuest;
    }

    public abstract String toString();
}
