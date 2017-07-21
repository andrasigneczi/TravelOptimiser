package Apps;

import PageGuest.BookingDotComPageGuest;
import PageGuest.WizzAirPageGuestTimetable;
import QueueHandlers.ResultQueue;
import Root.PageGuestFactory;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 15/06/2017.
 */
public class BookingDotComApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( BookingDotComApp.class);

	public static void Run()
	{
		try
		{
			mLogger.trace( "BookingDotComApp start" );
			ResultQueue.setQueueType( ResultQueue.RESULT_QUEUE_TYPE.JMS, "DBAgent" );
			final BookingDotComPageGuest lGuest = (BookingDotComPageGuest) PageGuestFactory.Create( "booking.com" );
			lGuest.Init();
			lGuest.WaitForFinish();
			mLogger.trace( "BookingDotComApp stop" );
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
