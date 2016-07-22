package Root;

import PageGuest.ResultQueue;
import PageGuest.TravelData_RESULT;
import PageGuest.WebPageGuest;
import PageGuest.WizzAirPageGuest;
import Storage.FileWriterAgent;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 * Created by andras.igneczi on 10/03/2016.
 */
public class Main
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(Main.class);

    public static void main(String[] argv)
    {
        try
        {
            //MozillaHelloWorld.Starter();
            //SQLiteAgent lSQLiteAgent2 = new SQLiteAgent();
            //lSQLiteAgent2.InitializeDatabase();
            //HelloWorld.SQLiteHelloWorld.Test7();
            //HelloWorld.XmlHelloWorld.Test();
            //HelloWorld.JxBrowserHelloWorld2.HelloWorld();
            //Thread.sleep(50000);
            //TestDatetimeParser();
//            mLogger.trace( "trace teszt" );
//            mLogger.error( "debug teszt" );
            //System.exit(0);

            //HelloWorld.JxBrowserHelloWorld.HelloWorld();
            //HelloWorld.JxBrowserHelloWorld.FlashSample();

            CurrencyHelper.Init();
            // Initialize the configuration
            Util.Configuration lConfiguration = Util.Configuration.getInstance();
            int lWizzAirWindowCount;

            try
            {
                lWizzAirWindowCount = lConfiguration.getIntValue( "/configuration/global/WizzAirWindowCount", "1" );
            }
            catch( NumberFormatException e )
            {
                mLogger.error( "WizzAirWindowCount problem: " + StringHelper.getTraceInformation( e ));
                lWizzAirWindowCount = 1;
            }

            PageGuest.PageGuest lGuestR = PageGuestFactory.Create( "RyanAir" );

            final PageGuest.PageGuest lGuestW;
            if( lWizzAirWindowCount > 1 )
            {
                WizzAirPageGuest.StartMultiBrowser( 4 );
                lGuestW = null;
            }
            else
            {
                lGuestW = PageGuestFactory.Create( "WizzAir" );
                lGuestW.DoSearchFromConfig();
            }

            lGuestR.DoSearchFromConfig();


            SQLiteAgent lSQLiteAgent = new SQLiteAgent();
            lSQLiteAgent.InitializeDatabase();

            final int WaitBeforeStop = 120;
            int i = WaitBeforeStop;
            while( i > 0 )
            {
                TravelData_RESULT lResult = ResultQueue.getInstance().pop();
                if (lResult != null)
                {
                    lSQLiteAgent.Archive(lResult);
                    i = WaitBeforeStop;
                    continue;
                }
                Thread.sleep(1000);
                i--;
            }
            if( lWizzAirWindowCount > 1 )
                WizzAirPageGuest.StopMultiBrowser();
            else
                lGuestW.stop();
            lGuestR.stop();

            lSQLiteAgent.ConnectionClose();
            lSQLiteAgent.ArchiveDatabaseFile();

            System.exit(-1);
        }
        catch (Exception e)
        {
            mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
        }
    }
}
