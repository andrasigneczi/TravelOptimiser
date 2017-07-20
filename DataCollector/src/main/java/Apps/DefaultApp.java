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
			//HelloWorld.JxBrowserHelloWorld2.HelloWorld();
			//Thread.sleep(50000);
			//TestDatetimeParser();
//            mLogger.trace( "trace teszt" );
//            mLogger.error( "debug teszt" );
			//System.exit(0);

			//HelloWorld.JxBrowserHelloWorld.HelloWorld();
			//HelloWorld.JxBrowserHelloWorld.FlashSample();

			Configuration lConfiguration = Configuration.getInstance();
			getBrowserLogger().setLevel( Level.WARNING );
			getChromiumProcessLogger().setLevel( Level.WARNING );
			getIPCLogger().setLevel( Level.WARNING );

			if( !CurrencyHelper.DownloadRecentCurrencyPrices())
			{
				mLogger.error( "Currency values are not available!" );
				return;
			}

			final PageGuest.PageGuest lGuestR = PageGuestFactory.Create( "RyanAir" );
			final PageGuest.PageGuest lGuestW = PageGuestFactory.Create( "WizzAir" );

			lGuestW.DoSearchFromConfig();
			lGuestR.DoSearchFromConfig();


			SQLiteAgent lSQLiteAgent = new SQLiteAgent();
			lSQLiteAgent.InitializeDatabase();

			final int WaitBeforeStop = 120;
			int i = WaitBeforeStop;
			while( i > 0 )
			{
				Object lResult = ResultQueue.getInstance().pop();
				if (lResult != null)
				{
					lSQLiteAgent.Archive(lResult);
					i = WaitBeforeStop;
					continue;
				}
				Thread.sleep(1000);
				i--;
			}

			lGuestW.stop();
			lGuestR.stop();

			lSQLiteAgent.ConnectionClose();
			lSQLiteAgent.ArchiveDatabaseFile();

			System.exit(-1);
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
