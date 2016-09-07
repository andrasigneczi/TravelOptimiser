package Apps;

import PageGuest.TravelData_RESULT;
import QueueHandlers.ResultQueue;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.util.logging.Level;

import static com.teamdev.jxbrowser.chromium.LoggerProvider.getBrowserLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getChromiumProcessLogger;
import static com.teamdev.jxbrowser.chromium.LoggerProvider.getIPCLogger;

/**
 * Created by Andras on 02/08/2016.
 */
public class DBAgentApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( DBAgentApp.class);

	public static void Run()
	{
		mLogger.trace( "DBAgentApp start" );
		try
		{
			getBrowserLogger().setLevel( Level.WARNING );
			getChromiumProcessLogger().setLevel( Level.WARNING );
			getIPCLogger().setLevel( Level.WARNING );

			if( !CurrencyHelper.DownloadRecentCurrencyPrices())
			{
				mLogger.error( "Currency values are not available!" );
				return;
			}
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			SQLiteAgent lSQLiteAgent = new SQLiteAgent();
			lSQLiteAgent.InitializeDatabase();

			// the jms listen 1 second before return, so in case of 30 the waiting time will be 60 seconds
			final int WaitBeforeStop = 30;
			int i = WaitBeforeStop;
			while( i > 0 )
			{
				TravelData_RESULT lResult = ResultQueue.getInstance().pop();
				if (lResult != null)
				{
					lSQLiteAgent.Archive(lResult);
					i = WaitBeforeStop;
					continue;
				}
				Thread.sleep(1000);
				i--;
			}

			lSQLiteAgent.ConnectionClose();
			lSQLiteAgent.ArchiveDatabaseFile();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
		mLogger.trace( "DBAgentApp stop" );
	}
}
