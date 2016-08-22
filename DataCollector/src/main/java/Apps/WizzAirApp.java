package Apps;

import QueueHandlers.ResultQueue;
import Root.Main;
import Root.PageGuestFactory;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 02/08/2016.
 */
public class WizzAirApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzAirApp.class);

	public static void Run()
	{
		mLogger.trace( "WizzAirApp start" );
		try
		{
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			final PageGuest.WizzAirPageGuest lGuestW = (PageGuest.WizzAirPageGuest)PageGuestFactory.Create( "WizzAir" );
			lGuestW.InitJMS();
			lGuestW.WaitForFinish();
			//lGuestW.stop();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
		mLogger.trace( "WizzAirApp stop" );
	}
}
