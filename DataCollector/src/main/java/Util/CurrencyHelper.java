package Util;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import java.lang.*;
import java.lang.System;
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
     * @return price of 1 €
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

    // converts the format 10.99 € to double, if postfix is true
    // converts the format Ft 10.99 to double, if postfix is false
    public static Double convertPriceToPriceInEuro( String aPrice, boolean postfix )
    {
        //System.out.println( aPrice );
        // spacial space replace, what generated by getInnerText
        aPrice = aPrice.replace( " ", " " );

        String[] aList = aPrice.split( " " );

        if( aList.length == 0 )
        {
            mLogger.warn( "Wrong price format?! " + aPrice );
            return 1.0;
        }

        if( postfix )
        {
            String aSymbol = aList[ aList.length - 1 ];
            return Double.parseDouble( aList[ 0 ].replace( ",", "" )) * mMultipliers.getOrDefault( aSymbol, 1.0 );
        }
        String aSymbol = aList[ 0 ];
        return Double.parseDouble( aList[ aList.length - 1 ].replace( ",", "" )) * mMultipliers.getOrDefault( aSymbol, 1.0 );
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
        final java.lang.String lUrlTemplate1 = "http://www.xe.com/currencyconverter/convert/?Amount=1&From=BGN&To=EUR";
        final java.lang.String lUrlTemplate2 = "https://transferwise.com/au/currency-converter/BGN-to-eur-rate?amount=1";

        return DownloadRecentCurrencyPrices( lUrlTemplate1, "//*[@id=\"converterResult\"]/div/div/div[2]/span[1]", "" ) ||
            DownloadRecentCurrencyPrices( lUrlTemplate2, "/html/body/section/div/div/div/div/div[2]/div[2]/div[1]/div/h3[2]/span[2]", "" );
    }

    public static boolean DownloadRecentCurrencyPrices( String lUrlTemplate, String path1, String path2 ) throws InterruptedException
    {
        Browser lBrowser = TeamDevJxBrowser.getInstance().getJxBrowser("wwww");
        for( Map.Entry<String,String> lItem : mCurrencies.entrySet())
        {
            if( lItem.getKey().equals( "EUR" ))
            {
                mMultipliers.put( lItem.getValue().toString(), 1.0 );
                continue;
            }

            java.lang.String lUrl = lUrlTemplate.replace( "BGN", lItem.getKey().toString() );
            for( int i = 0; i < 3; i++ )
            {
                try
                {
                    Browser.invokeAndWaitFinishLoadingMainFrame(lBrowser, new Callback<Browser>() {
                        @Override
                        public void invoke(Browser browser) {
                            browser.loadURL(lUrl);
                        }
                    });
                    break;
                }
                catch( RuntimeException e )
                {
                    mLogger.error( "DownloadRecentCurrencyPrices(" + i + "): " + StringHelper.getTraceInformation( e ));
                    if( i == 2 )
                        throw e;
                }
            }

            // Wait until Chromium renders web page content
            Thread.sleep( 1000 );

            DOMDocument lDocument = lBrowser.getDocument();
            DOMElement lElement = lDocument.findElement( By.xpath( path1 ) );
            if( lElement == null && path2.length() > 0 )
                lElement = lDocument.findElement( By.xpath( path2 ));
            if( lElement == null )
            {
                lBrowser.dispose();
                return false;
            }

            String lInner = lElement.getInnerText();
            //String lCurrencyValue = lElement.getInnerText().substring( 0, lInner.length() - 4 );
            String lCurrencyValue = "";
            for( int i = 0; i < lInner.length(); ++i) {
                if(( lInner.charAt(i) >= '0' && lInner.charAt(i) <= '9' ) || lInner.charAt(i) == '.')
                    lCurrencyValue += lInner.charAt(i);
            }
            //String lCurrencyValue = lInner;
            double currencyValue = Double.valueOf( lCurrencyValue );
            if( currencyValue == 0.0 ) {
                lBrowser.dispose();
                return false;
            }
            mMultipliers.put( lItem.getValue().toString(), currencyValue );
        }
        lBrowser.dispose();
        return true;
    }
}
