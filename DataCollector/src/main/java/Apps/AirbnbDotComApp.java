package Apps;

import PageGuest.AirbnbDotComPageGuest;
import QueueHandlers.ResultQueue;
import Root.PageGuestFactory;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 25/07/2017.
 */
public class AirbnbDotComApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( AirbnbDotComApp.class);

	public static void Run()
	{
		try
		{
			mLogger.trace( "AirbnbDotComApp start" );
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			final AirbnbDotComPageGuest lGuest = (AirbnbDotComPageGuest) PageGuestFactory.Create( "airbnb.com" );
			lGuest.Init();
			lGuest.WaitForFinish();
			mLogger.trace( "AirbnbDotComApp stop" );
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
