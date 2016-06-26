package Util;

import java.util.HashMap;
import java.util.Hashtable;

public class CurrencyHelper
{
    private static Hashtable<String, String> mCurrencies = new Hashtable<String, String>();

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
}
