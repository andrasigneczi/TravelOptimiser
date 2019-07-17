package Apps;

import Configuration.Configuration;
import PageGuest.TravelData_RESULT;
import QueueHandlers.ResultQueue;
import Root.PageGuestFactory;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.util.logging.Level;

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

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
			//MozillaHelloWorld.Starter();
			//SQLiteAgent lSQLiteAgent2 = new SQLiteAgent();
			//lSQLiteAgent2.InitializeDatabase();
			//HelloWorld.SQLiteHelloWorld.Test7();
			//HelloWorld.XmlHelloWorld.Test();
			HelloWorld.JxBrowserHelloWorld2.HelloWorld();
			Thread.sleep(100000);
			//TestDatetimeParser();
//            mLogger.trace( "trace teszt" );
//            mLogger.error( "debug teszt" );
			//System.exit(0);

			//HelloWorld.JxBrowserHelloWorld.HelloWorld();
			//HelloWorld.JxBrowserHelloWorld.FlashSample();

		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
