package Root;

import PageGuest.ResultQueue;
import PageGuest.TravelData_RESULT;
import PageGuest.WebPageGuest;
import Storage.FileWriterAgent;
import Storage.SQLiteAgent;
import Util.CurrencyHelper;
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
//            HelloWorld.JxBrowserHelloWorld.HelloWorld();
//            Thread.sleep(50000);
//            Thread.sleep(50000);
//            Thread.sleep(50000);
            //TestDatetimeParser();
            //System.exit(0);

            //HelloWorld.JxBrowserHelloWorld.HelloWorld();
	        //HelloWorld.JxBrowserHelloWorld.FlashSample();

            CurrencyHelper.Init();
            // Initialize the configuration
            Util.Configuration lConfiguration = Util.Configuration.getInstance();

            PageGuest.PageGuest lGuestW = PageGuestFactory.Create( "WizzAir" );
            PageGuest.PageGuest lGuestR = PageGuestFactory.Create( "RyanAir" );

            lGuestW.DoSearchFromConfig();
            lGuestR.DoSearchFromConfig();


            FileWriterAgent lFWA         = new FileWriterAgent("database.html");
            SQLiteAgent     lSQLiteAgent = new SQLiteAgent();
            lSQLiteAgent.InitializeDatabase();
            lFWA.setNextAgent(lSQLiteAgent);

            final int WaitBeforeStop = 5 * 60;
            int i = WaitBeforeStop;
            while( i > 0 )
            {
                TravelData_RESULT lResult = ResultQueue.getInstance().pop();
                if (lResult != null)
                {
                    lFWA.Archive(lResult);
                    i = WaitBeforeStop;
                    continue;
                }
                Thread.sleep(1000);
                i--;
            }
            lGuestW.stop();
            lGuestR.stop();
            System.exit(-1);
        }
        catch (Exception e)
        {
            StringWriter lStringWriter = new StringWriter();
            PrintWriter lPrintWriter = new PrintWriter(lStringWriter);
            e.printStackTrace( lPrintWriter );
            mLogger.error( "Unhandled exception: " + lStringWriter.toString() );
        }
    }
}
