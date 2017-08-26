package Root;

import Apps.*;
import Configuration.Configuration;
import Util.CurrencyHelper;
import org.apache.log4j.Logger;

/**
 * Created by andras.igneczi on 10/03/2016.
 */
public class Main
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(Main.class);

    private static void StartApp( String[] argv)
    {
        if( argv.length == 0 )
        {
            DefaultApp.Run();
            return;
        }
        for( String arg : argv )
        {
            if( arg.equals( "-inputfeeder" ))
            {
                InputFeederApp.Run();
                break;
            }
            else if( arg.equals( "-wizzair" ))
            {
                WizzAirApp.Run();
                break;
            }
            else if( arg.equals( "-ryanair" ))
            {
                RyanAirApp.Run();
                break;
            }
            else if( arg.equals( "-wizzairtimetable" ))
            {
                WizzAirTimetableApp.Run();
                break;
            }
            else if( arg.equals( "-booking.com" ))
            {
                BookingDotComApp.Run();
                break;
            }
            else if( arg.equals( "-airbnb.com" ))
            {
                AirbnbDotComApp.Run();
                break;
            }
            else if( arg.equals( "-dbagent" ))
            {
                DBAgentApp.Run();
                break;
            }
        }
    }

    public static void main(String[] argv)
    {
        CurrencyHelper.Init();
        Configuration lConfiguration = Configuration.getInstance();
        StartApp( argv );
        System.exit( 0 );
    }
}
