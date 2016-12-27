package Util;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 * Created by Andras on 07/07/2016.
 */
public class Util
{
	private final static DateTimeFormatter mFormatter1 = DateTimeFormatter.ofPattern( "yyyy-MM-dd'T'HH:mm:ss" );
	private final static DateTimeFormatter mFormatter2 = DateTimeFormatter.ofPattern( "yyyy-MM-dd HH:mm" );

	public static String getTraceInformation( Exception aException )
	{
		StringWriter lStringWriter = new StringWriter();
		PrintWriter lPrintWriter = new PrintWriter(lStringWriter);
		aException.printStackTrace( lPrintWriter );
		return lStringWriter.toString();
	}

	public static int compareDateTime( String d1, String d2 ){
		// 2016-05-04 00:00
		// 2016-04-18T03:53:04
		LocalDateTime lDT1, lDT2;

		if( d1.indexOf( 'T' ) != -1 )
			lDT1 = LocalDateTime.parse( d1, mFormatter1 );
		else
			lDT1 = LocalDateTime.parse( d1, mFormatter2 );

		if( d2.indexOf( 'T' ) != -1 )
			lDT2 = LocalDateTime.parse( d2, mFormatter1 );
		else
			lDT2 = LocalDateTime.parse( d2, mFormatter2 );

		if( lDT1.isAfter( lDT2 ))
			return 1;
		if( lDT1.isBefore( lDT2 ))
			return -1;
		return 0;
	}

	public static String htmlColorChanger( String color, int add )
	{
		// parse hexadeciaml string
		Long value = Long.parseLong( color.replace( "#", "" ), 16 );
		value += add;
		String retvalue = String.format( "#%x", value % 0xffffff );
		return retvalue;
	}
}
