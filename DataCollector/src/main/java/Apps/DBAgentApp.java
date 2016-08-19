package Apps;

import PageGuest.TravelData_RESULT;
import PageGuest.WizzAirPageGuest;
import QueueHandlers.ResultQueue;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 02/08/2016.
 */
public class DBAgentApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( DBAgentApp.class);

	public static void Run()
	{
		try
		{
			if( !CurrencyHelper.DownloadRecentCurrencyPrices())
			{
				mLogger.error( "Currency values are not available!" );
				return;
			}
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			SQLiteAgent lSQLiteAgent = new SQLiteAgent();
			lSQLiteAgent.InitializeDatabase();

			final int WaitBeforeStop = 120;
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
	}
}
