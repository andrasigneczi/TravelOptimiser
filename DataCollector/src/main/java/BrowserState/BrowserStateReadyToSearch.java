package BrowserState;

import PageGuest.WebPageGuest;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;

/**
 * Created by andras.igneczi on 23/03/2016.
 */
public class BrowserStateReadyToSearch  extends BrowserState
{
    DOMDocument mDOMDocument;

    public BrowserStateReadyToSearch( DOMDocument aDOMDocument )
    {
        mDOMDocument = aDOMDocument;
    }

    @Override
    public void doAction( WebPageGuest aWebPageGuest )
    {
        mWebPageGuest = aWebPageGuest;
        aWebPageGuest.setBrowserState( this );
    }

    @Override
    public String toString()
    {
        return "BrowserStateReadyToSearch";
    }
    public DOMDocument getDOMDocument()
    {
        return mDOMDocument;
    }
}
