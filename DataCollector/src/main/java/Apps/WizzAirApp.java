package Apps;

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
		try
		{
			CurrencyHelper.Init();
			Util.Configuration lConfiguration = Util.Configuration.getInstance();
			final PageGuest.WizzAirPageGuest lGuestW = (PageGuest.WizzAirPageGuest)PageGuestFactory.Create( "WizzAir" );
	        lGuestW.DoSearchFromJMS();
			lGuestW.stop();
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
