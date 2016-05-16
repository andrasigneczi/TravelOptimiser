package Root;

import PageGuest.ResultQueue;
import PageGuest.TravelData_RESULT;
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

//            WebPageGuest lGuestW = WebPageGuestFactory.Create( "WizzAir" );
            PageGuest.PageGuest lGuestR = PageGuestFactory.Create( "RyanAir" );
//            lGuestW.DoSearch( "SOF", "HHN", "2016.07.02.", "2016.07.05." );
            //lGuestR.DoSearch( "Dublin", "Faro", "2016.07.31.", "2017.01.04." );
            lGuestR.DoSearch( "DUB", "FAO", "2016.07.31.", "2017.01.04." );
//            lGuestR.DoSearch( "Frankfurt (HHN)", "Thessaloniki", "2016.09.03.", "2016.09.06." );

            //lGuest.DoSearchFromConfig();


//            lGuest.DoSearch( "SOF", "HHN", "2016.08.06.", "2016.08.09." );
//            lGuest.DoSearch( "CRL", "BUD", "2016.07.08.", "2016.07.11." );
//            lGuest.DoSearch( "CRL", "BUD", "2016.07.22.", "2016.07.25." );
//            lGuest.DoSearch( "BUD", "CRL", "2016.07.11.", "" );

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
 //           lGuestW.stop();
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
/*
        HelloWorld.SQLiteHelloWorld.Test1( new String[0] );
        HelloWorld.SQLiteHelloWorld.Test2( new String[0] );
        HelloWorld.SQLiteHelloWorld.Test3( new String[0] );
        HelloWorld.SQLiteHelloWorld.Test4( new String[0] );
        HelloWorld.SQLiteHelloWorld.Test5( new String[0] );
        HelloWorld.SQLiteHelloWorld.Test6( new String[0] );

        runMe( "hello" );
*/
/*
        Thread.sleep(1000000);
        System.exit(-1);

        Root.HttpRequest lH = new Root.HttpRequest();
        try
        {
            String lResponse = lH.sendGet( "https://wizzair.com/hu-HU/TimeTable/Brussels-Charleroi/Budapest", 30 );
            String lLogFileName = "response_page.html";

            Files.deleteIfExists( FileSystems.getDefault().getPath( lLogFileName));
            Files.write(Paths.get(lLogFileName), lResponse.getBytes(), StandardOpenOption.CREATE_NEW);

            // https://wizzair.com/hu-HU/TimeTable/Brussels-Charleroi/Budapest
            // https://wizzair.com/hu-HU/TimeTable/Budapest/Brussels-Charleroi
            // https://wizzair.com/hu-HU/TimeTable/Sofia/Frankfurt%20%E2%80%93%20Hahn
            // https://wizzair.com/hu-HU/TimeTable/Frankfurt%20%E2%80%93%20Hahn/Sofia

        }
        catch( Exception e )
        {
            e.printStackTrace();
        }
        */
    }

    private static void runMe(String parameter)
    {
        mLogger.debug("This is debug : " + parameter);
        mLogger.info("This is info : " + parameter);
        mLogger.warn("This is warn : " + parameter);
        mLogger.error("This is error : " + parameter);
        mLogger.fatal("This is fatal : " + parameter);
    }

    private static void TestDatetimeParser()
    {
        String lDatetime = "2016-07-31T10:05:00";
        DateTimeFormatter lFormatterWizzair = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
        LocalDateTime lLocalDateTime = LocalDateTime.parse(lDatetime, lFormatterWizzair);
        return;
    }
}
