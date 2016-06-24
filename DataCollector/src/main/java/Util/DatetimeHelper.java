package Util;

import org.apache.log4j.Logger;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZoneOffset;
import java.time.ZonedDateTime;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DatetimeHelper
{
    // wizzair format, this format the required: "yyyy-MM-dd'T'HH:mm:ss"

    private static final String [] mMonthShortNames = new String[] { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    private static final String [] mDayNames = new String[] { "Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun" };
    private static final String [] lMonthNames = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    private static org.apache.log4j.Logger mLogger = Logger.getLogger( DatetimeHelper.class);


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
        for( int i = 0; i < mMonthShortNames.length; i++ )
        {
            if (lDatetime.startsWith(mMonthShortNames[i]))
            {
                lMonth = i;
                break;
            }
        }

        lDatetime = lDatetime.substring( 4 );
        String [] lTime = lDatetime.split( ":" );

        return String.format( "%04d-%02d-%02dT%02d:%02d:00", 2016, lMonth + 1, lDay, Integer.parseInt( lTime[ 0 ]), Integer.parseInt( lTime[ 1 ]) );
    }

    /**
     *
     * @param aDatetime format: yyyy.mm.dd.
     * @return format: month_long_name yyyy
     */
    public static String CreateRyanairCalendarHeader( String aDatetime )
    {
        String[] lParts = aDatetime.split("\\.", 0 );
        while( lParts[ 1 ].startsWith( "0" ))
            lParts[ 1 ] = lParts[ 1 ].substring( 1 );
        return String.format( "%s %s", lMonthNames[ Integer.parseInt( lParts[ 1 ] ) - 1], lParts[ 0 ]);
    }

    /**
     *
     * @param aDatetime    format: yyyy.mm.dd.
     * @return
     */
    public static int GetDayOfMonth( String aDatetime )
    {
        String[] lParts = aDatetime.split("\\.", 0 );
        while( lParts[ 2 ].startsWith( "0" ))
            lParts[ 2 ] = lParts[ 2 ].substring( 1 );
        return Integer.parseInt( lParts[ 2 ] );
    }

    /**
     *
     * @param aDatetime1    format: month_long_name yyyy
     * @param aDatetime2    format: month_long_name yyyy
     * @return
     */
    public static int CompareRyanairCalendarHeaders(String aDatetime1, String aDatetime2)
    {
        String[] lParts1 = aDatetime1.split(" ", 0 );
        String[] lParts2 = aDatetime2.split(" ", 0 );

        int lYear1 = Integer.parseInt( lParts1[ 1 ]);
        int lYear2 = Integer.parseInt( lParts2[ 1 ]);

        int lMonthIndex1 = 0;
        int lMonthIndex2 = 0;

        for( int lIndex = 0; lIndex < 12; lIndex++ )
        {
            if( lParts1[ 0 ].equals( lMonthNames[ lIndex ]))
                lMonthIndex1 = lIndex;

            if( lParts2[ 0 ].equals( lMonthNames[ lIndex ]))
                lMonthIndex2 = lIndex;
        }

        if( lYear1 > lYear2 )
            return 1;

        if( lYear1 < lYear2 )
            return -1;

        if( lMonthIndex1 > lMonthIndex2 )
            return 1;

        if( lMonthIndex1 < lMonthIndex2 )
            return -1;

        return 0;
    }

    public static String ConvertFromRyanairJSONStoredFormat( String aDatetime )
    {
        // 2017-01-04T17:25:00.000
        if( aDatetime.length() != 23 )
        {
            mLogger.warn( "Something wrong with the ryanair date time format: " + aDatetime );
            return aDatetime;
        }
        return aDatetime.substring( 0, aDatetime.length() - 4 );
    }

    public static String ConvertFromWizzairJSONStoredFormat( String aDatetime )
    {
        // 20160103 8:33
        //
        Pattern lReg = Pattern.compile( "^(\\d{4})(\\d{2})(\\d{2})\\s(\\d{1,2})\\:(\\d{2})$" );
        Matcher lMatch = lReg.matcher( aDatetime );
        if( lMatch.find() )
        {
            String lRow = lMatch.group(1).toString()
                    + "-"
                    + lMatch.group(2).toString()
                    + "-"
                    + lMatch.group(3).toString()
                    + "T"
                    + String.format( "%02d", Integer.parseInt( lMatch.group(4).toString()))
                    + ":"
                    + lMatch.group(5).toString()
                    + ":00";
            return lRow;
        }
        mLogger.warn( "Something wrong with the wizzair date time format: " + aDatetime );
        return "";
    }

    public static LocalDateTime WizzAirDatetimeCorrection( LocalDateTime aLocalDateTime )
    {
        // TODO: why must I add 1 more hour to get the right time?

        ZonedDateTime lZDT = aLocalDateTime.atZone( ZoneId.of( "Europe/Budapest" ));
        ZoneOffset lZO = lZDT.getOffset();
        String lZId = lZO.getId();

        Pattern reg = Pattern.compile( "(\\+|-)(\\d{2})\\:(\\d{2})" );
        Matcher m = reg.matcher( lZId );

        if( m.find() )
        {
            String lPrefix = m.group(1).toString().trim();
            String lHours = m.group(2).toString().trim();
            String lMinutes = m.group(3).toString().trim();

            if( lHours.charAt( 0 ) == '0' )
                lHours = lHours.substring( 1 );
            int lIHours = Integer.parseInt( lHours );
            if( lMinutes.charAt( 0 ) == '0' )
                lMinutes = lMinutes.substring( 1 );
            int lIMinutes = Integer.parseInt( lMinutes );

            if( lPrefix.equals( "+" ))
            {
                aLocalDateTime = aLocalDateTime.plusHours( lIHours - 1 );
                aLocalDateTime = aLocalDateTime.plusMinutes( lIMinutes );
            }
            else
            {
                aLocalDateTime = aLocalDateTime.minusHours( lIHours - 1 );
                aLocalDateTime = aLocalDateTime.minusMinutes( lIMinutes );
            }
        }

        return aLocalDateTime;
    }
}
