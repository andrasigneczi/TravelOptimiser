package BrowserState;

import PageGuest.WebPageGuest;

/**
 * Created by andras.igneczi on 16/03/2016.
 */
public abstract class BrowserState
{
    WebPageGuest mWebPageGuest = null;

    public abstract void doAction( WebPageGuest aWebPageGuest );

    public WebPageGuest getWebPageGuest()
    {
        return mWebPageGuest;
    }

    public abstract String toString();
}
