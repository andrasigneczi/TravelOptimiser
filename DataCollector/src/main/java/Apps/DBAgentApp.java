package Apps;

import Configuration.Configuration;
import Favorites.*;
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

			GMailSender lGmailSender = new GMailSender();
			lEmailNotifierAgent = new EmailNotifierAgent( lSQLiteAgent, lGmailSender );
			lSQLiteAgent.setNextAgent( lEmailNotifierAgent );

			// the jms listen 1 second before return, so in case of 30 the waiting time will be 60 seconds
			final int WaitBeforeStop = 150;
			int i = WaitBeforeStop;
			while( i > 0 )
			{
				Object lResultObject = ResultQueue.getInstance().pop();

				if (lResultObject != null)
				{
					lSQLiteAgent.Archive(lResultObject);
					i = WaitBeforeStop;
					continue;
				}
				Thread.sleep(1000);
				i--;
			}

			lSQLiteAgent.ConnectionClose();
			lSQLiteAgent.ArchiveDatabaseFile();
			lGmailSender.sendAll();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}

		if( lSQLiteAgent != null )
		{
			sendSummaryMail( lSQLiteAgent.getWizzAirTripCount(), lSQLiteAgent.getRyanAirTripCount(),
					lSQLiteAgent.getBookingDotComAccomodationCount());
		}
		mLogger.trace( "DBAgentApp stop" );
	}

	private static void sendSummaryMail( int wizzAirTripCount, int ryanAirTripCount, int bookingDotComAccomodationCount )
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
					" wizzair trip data, " +
					ryanAirTripCount +
					" ryanair trip data and " +
					bookingDotComAccomodationCount +
					" booking.com accomodataion.";

			GMailSender.send( fromAddress, fromName, toAddress, toName, subject, msgBody );
		}
		catch( Exception e )
		{
			mLogger.error( "mail exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
