package Util;

public class CurrencyHelper
{
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
}
