package Util;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import java.util.logging.Level;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

/**
 * Created by Andras on 05/06/2017.
 */
public class WizzairHelper
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzairHelper.class);

	private static String mApiVersionNumber = new String();

	public static String getApiVersion() throws InterruptedException
	{
		if( mApiVersionNumber.length() > 0 )
			return mApiVersionNumber;

		getBrowserLogger().setLevel( Level.WARNING );
		getChromiumProcessLogger().setLevel( Level.WARNING );
		getIPCLogger().setLevel( Level.WARNING );

		Browser lBrowser = TeamDevJxBrowser.getInstance().getJxBrowser("wwwww");
		for( int i = 0; i < 3; i++ )
		{
			try
			{
				Browser.invokeAndWaitFinishLoadingMainFrame( lBrowser, new Callback<Browser>()
				{
					@Override
					public void invoke( Browser browser )
					{
						browser.loadURL( "https://wizzair.com" );
					}
				} );
				break;
			}
			catch( RuntimeException e )
			{
				mLogger.error( "WizzairHelper(" + i + "): " + StringHelper.getTraceInformation( e ));
				if( i == 2 )
					throw e;
			}
		}
		// Wait until Chromium renders web page content
		Thread.sleep( 1000 );

		DOMDocument lDocument = lBrowser.getDocument();
		String lContent = lDocument.getDocumentElement().getInnerHTML();

		Pattern reg = Pattern.compile( "https\\://be\\.wizzair\\.com/(\\d{1,2}\\.\\d{1,2}\\.\\d{1,2})/Api" );
		Matcher m = reg.matcher( lContent );
		if( m.find() )
		{
			mApiVersionNumber = m.group(1).toString().trim();
			mLogger.info( "WizzAir API version: " + mApiVersionNumber );
		}
		lBrowser.dispose();
		return mApiVersionNumber;
	}

	public static String getApiVersion_new() throws Exception
	{
		if( mApiVersionNumber.length() > 0 )
			return mApiVersionNumber;

		HttpRequest request = new HttpRequest();
		String response = request.sendGet( "http://www.wizzair.com", 0 );
		Pattern reg = Pattern.compile( "https\\://be\\.wizzair\\.com/(\\d{1,2}\\.\\d{1,2}\\.\\d{1,2})/Api" );
		Matcher m = reg.matcher( response );
		if( m.find() )
		{
			mApiVersionNumber = m.group(1).toString().trim();
			mLogger.info( "WizzAir API version: " + mApiVersionNumber );
		}
		return mApiVersionNumber;
	}
}
