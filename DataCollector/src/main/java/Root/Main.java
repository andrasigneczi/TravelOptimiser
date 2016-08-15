package Root;

import Apps.*;
import QueueHandlers.ResultQueue;
import PageGuest.TravelData_RESULT;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.StringHelper;
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
            else if( arg.equals( "-wizzairv2" ))
            {
                WizzAirV2App.Run();
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
        StartApp( argv );
        System.exit( 0 );
    }
}
