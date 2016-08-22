package Apps;

import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 02/08/2016.
 */
public class WizzAirV2App
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( WizzAirV2App.class);

	public static void Run()
	{
		try
		{
			mLogger.trace( "WizzAirV2App start" );
			mLogger.trace( "WizzAirV2App stop" );
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
