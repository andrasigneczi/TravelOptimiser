package Apps;

import Configuration.Configuration;
import Favorites.*;
import PageGuest.TravelData_RESULT;
import QueueHandlers.ResultQueue;
import Storage.EmailNotifierAgent;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.GMailSender;
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
		EmailNotifierAgent lEmailNotifierAgent = null;
		SQLiteAgent lSQLiteAgent = null;
		try
		{
			getBrowserLogger().setLevel( Level.WARNING );
			getChromiumProcessLogger().setLevel( Level.WARNING );
			getIPCLogger().setLevel( Level.WARNING );

			for( int DownloadProbes = 5; DownloadProbes > 0; DownloadProbes-- )
			{
				if( CurrencyHelper.DownloadRecentCurrencyPrices() )
				{
					break;
				}
				else
				{
					mLogger.error( "Currency values are not available!" );
					if( DownloadProbes == 1 )
						return;
					Thread.sleep(60 * 1000);
				}
			}

			Favorites.getInstance().LoadFavourites();

			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			lSQLiteAgent = new SQLiteAgent();
			lSQLiteAgent.InitializeDatabase();

			lEmailNotifierAgent = new EmailNotifierAgent( lSQLiteAgent );
			lSQLiteAgent.setNextAgent( lEmailNotifierAgent );

			// the jms listen 1 second before return, so in case of 30 the waiting time will be 60 seconds
			final int WaitBeforeStop = 150;
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

		if( lSQLiteAgent != null )
		{
			sendSummaryMail( lSQLiteAgent.getWizzAirTripCount(), lSQLiteAgent.getRyanAirTripCount());
		}
		mLogger.trace( "DBAgentApp stop" );
	}

	private static void sendSummaryMail( int wizzAirTripCount, int ryanAirTripCount )
	{
		try
		{
			Configuration lConfiguration = Configuration.getInstance();
			String fromAddress = "agent@traveloptimizer.com";
			String fromName = "Travel Optimizer";
			String toAddress = lConfiguration.getValue( "/configuration/global/SummaryEmail", "" );
			String toName = lConfiguration.getValue( "/configuration/global/SummaryName", "" );
			String subject = "Travel Optimizer DBAgent summary";
			String msgBody = "Hi " + toName + ",\n" +
					"the DBAgent saved " +
					wizzAirTripCount +
					" wizzair trip data and " +
					ryanAirTripCount +
					" ryanair trip data";

			GMailSender.send( fromAddress, fromName, toAddress, toName, subject, msgBody );
		}
		catch( Exception e )
		{
			mLogger.error( "mail exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
