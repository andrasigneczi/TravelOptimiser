package Apps;

import Root.PageGuestFactory;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

/**
 * Created by Andras on 02/08/2016.
 */
public class InputFeederApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( InputFeederApp.class);

	public static void Run()
	{
		try
		{
			CurrencyHelper.Init();
			Util.Configuration lConfiguration = Util.Configuration.getInstance();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
