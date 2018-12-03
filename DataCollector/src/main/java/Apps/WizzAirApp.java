package Apps;

import QueueHandlers.ResultQueue;
import Root.PageGuestFactory;
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
			PageGuest.WizzAirPageGuest201609.InitApirURL();
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			final PageGuest.WizzAirPageGuest201812 lGuestW = (PageGuest.WizzAirPageGuest201812)PageGuestFactory.Create( "WizzAir" );
			lGuestW.Init();
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
