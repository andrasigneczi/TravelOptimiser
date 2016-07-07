package Util;

import java.io.PrintWriter;
import java.io.StringWriter;

/**
 * Created by Andras on 07/07/2016.
 */
public class Util
{
	static String getTraceInformation( Exception aException )
	{
		StringWriter lStringWriter = new StringWriter();
		PrintWriter lPrintWriter = new PrintWriter(lStringWriter);
		aException.printStackTrace( lPrintWriter );
		return lStringWriter.toString();
	}
}
