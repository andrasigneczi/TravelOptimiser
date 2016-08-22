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
public class RyanAirApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( RyanAirApp.class);

	public static void Run()
	{
		mLogger.trace( "RyanAirApp start" );
		try
		{
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
	        final PageGuest.RyanAirPageGuest lGuestR = (PageGuest.RyanAirPageGuest)PageGuestFactory.Create( "RyanAir" );
			lGuestR.InitJMS();
			lGuestR.WaitForFinish();
			//lGuestR.stop();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
		mLogger.trace( "RyanAirApp stop" );
	}
}
