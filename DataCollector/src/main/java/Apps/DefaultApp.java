package Apps;

import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 11/08/2016.
 */
public class DefaultApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( DefaultApp.class);

	public static void Run()
	{
		try
		{
			HelloWorld.JxBrowserHelloWorld2.HelloWorld();
			Thread.sleep(100000);
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
