package Util;

public class DatetimeHelper
{
    // wizzair format, this format the required: "yyyy-MM-dd'T'HH:mm:ss"

    private static final String [] mMonthNames = new String[] { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    private static final String [] mDayNames = new String[] { "Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun" };

    public static String ConvertFromRyanairFormat( String aDatetime )
    {
        // Fri 1 Jul 22:25
        // what about the year?

        // skip the name of the day
        String lDatetime = aDatetime.substring( 4 );

        int lSpacePos = lDatetime.indexOf(" ");
        int lDay = Integer.parseInt( lDatetime.substring( 0, lSpacePos ) );
        lDatetime = lDatetime.substring( lSpacePos ).trim();

        int lMonth = 0;
        for( int i = 0; i < mMonthNames.length; i++ )
        {
            if (lDatetime.startsWith(mMonthNames[i]))
            {
                lMonth = i;
                break;
            }
        }

        lDatetime = lDatetime.substring( 4 );
        String [] lTime = lDatetime.split( ":" );

        return String.format( "%04d-%02d-%02d'T'%02d:%02d:00", 2016, lMonth + 1, lDay, Integer.parseInt( lTime[ 0 ]), Integer.parseInt( lTime[ 1 ]) );
    }
}
