package Util;

import org.apache.log4j.Logger;
import org.openqa.selenium.WebDriver;

import java.util.logging.Level;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 05/06/2017.
 */
public class WizzairHelper
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzairHelper.class);

	private static String mApiVersionNumber = new String();

	public static String getApiVersion(WebDriver driver) throws InterruptedException
	{
		if( mApiVersionNumber.length() > 0 )
			return mApiVersionNumber;

		String lContent = driver.getPageSource();
		Pattern reg = Pattern.compile( "https\\://be\\.wizzair\\.com/(\\d{1,2}\\.\\d{1,2}\\.\\d{1,2})/Api" );
		Matcher m = reg.matcher( lContent );
		if( m.find() )	{ mApiVersionNumber = m.group(1).toString().trim(); }
		return mApiVersionNumber;
	}
}
