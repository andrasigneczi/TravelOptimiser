package Apps;

import PageGuest.WizzAirPageGuestTimetable;
import Root.PageGuestFactory;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 02/08/2016.
 */
public class WizzAirTimetableApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzAirTimetableApp.class);

	public static void Run()
	{
		try
		{
			mLogger.trace( "WizzAirTimetableApp start" );

			final WizzAirPageGuestTimetable lGuestW = (WizzAirPageGuestTimetable) PageGuestFactory.Create( "WizzAirTimetable" );
			lGuestW.DoSearchFromConfig();
			lGuestW.WaitForFinish();
			mLogger.trace( "WizzAirTimetableApp stop" );
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
