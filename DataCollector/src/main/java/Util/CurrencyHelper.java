package Util;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import java.util.Hashtable;
import java.util.Map;

public class CurrencyHelper
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger( CurrencyHelper.class);

    private static Hashtable<String, String> mCurrencies = new Hashtable<String, String>();
    private static Hashtable<String, Double> mMultipliers = new Hashtable<>();

    public static void Init()
    {
        synchronized( mCurrencies )
        {
            if( mCurrencies.isEmpty())
            {
                mCurrencies.put( "EUR", "€" );
                mCurrencies.put( "HUF", "Ft" );
                mCurrencies.put( "BGN", "lv" );
                mCurrencies.put( "GBP", "£" );
                mCurrencies.put( "USD", "$" );
            }
        }
    }

    /**
     *
     * @param aPrice e.g. 10.99 €, 25963.50 Ft, ...
     * @return
     */
    public static Double getCurrencyPriceInEuro( String aPrice )
    {
        String[] aList = aPrice.split( " " );

        if( aList.length == 0 )
        {
            mLogger.warn( "Wrong price format?! " + aPrice );
            return 1.0;
        }

        String aSymbol = aList[ aList.length - 1 ];

        return mMultipliers.getOrDefault( aSymbol, 1.0 );
    }

    public static Double convertPriceToPriceInEuro( String aPrice )
    {
        String[] aList = aPrice.split( " " );

        if( aList.length == 0 )
        {
            mLogger.warn( "Wrong price format?! " + aPrice );
            return 1.0;
        }

        String aSymbol = aList[ aList.length - 1 ];

        return Double.parseDouble( aList[ 0 ] ) * mMultipliers.getOrDefault( aSymbol, 1.0 );
    }

    public static String ConvertFromRyanairFormat( String aPrice )
    {
        // Ft 5,149
        int lPos;
        for( lPos = 0; lPos < aPrice.length(); lPos++ )
        {
            if( aPrice.charAt( lPos ) >= '0' && aPrice.charAt( lPos ) <=  '9' )
                break;
        }

        return aPrice.substring( lPos ) + " " + aPrice.substring( 0, lPos ).trim();
    }

    public static String ConvertFrom3Digits( String aCurrency )
    {
        return mCurrencies.get( aCurrency );
    }

    public static boolean DownloadRecentCurrencyPrices() throws InterruptedException
    {
        final java.lang.String lUrlTemplate = "http://www.xe.com/currencyconverter/convert/?Amount=1&From=BGN&To=EUR";
        Browser lBrowser = TeamDevJxBrowser.getInstance().getJxBrowser("wwww");
        for( Map.Entry<String,String> lItem : mCurrencies.entrySet())
        {
            java.lang.String lUrl = lUrlTemplate.replace( "BGN", lItem.getKey().toString() );
            Browser.invokeAndWaitFinishLoadingMainFrame(lBrowser, new Callback<Browser>() {
                @Override
                public void invoke(Browser browser) {
                    browser.loadURL(lUrl);
                }
            });

            // Wait until Chromium renders web page content
            Thread.sleep( 1000 );

            DOMDocument lDocument = lBrowser.getDocument();
            //DOMElement lElement = lDocument.findElement( By.xpath( "//*[@id=\"contentL\"]/div[1]/div[1]/div/span/table/tbody/tr[1]/td[3]" ) );
            DOMElement lElement = lDocument.findElement( By.xpath( "//*[@id=\"ucc-container\"]/span[2]/span[2]" ) );
            if( lElement == null )
                lElement = lDocument.findElement( By.xpath( "//*[@id=\"ucc-container\"]/span[3]/span[2]" ));
            if( lElement == null )
            {
                lBrowser.dispose();
                return false;
            }

            String lInner = lElement.getInnerText();
            //String lCurrencyValue = lElement.getInnerText().substring( 0, lInner.length() - 4 );
            String lCurrencyValue = lInner;
            mMultipliers.put( lItem.getValue().toString(), Double.valueOf( lCurrencyValue ) );
        }
        lBrowser.dispose();
        return true;
    }
}
