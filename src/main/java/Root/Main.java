package Root;

import PageGuest.ResultQueue;
import PageGuest.TravelData_RESULT;
import PageGuest.WebPageGuest;
import Storage.FileWriterAgent;
import Storage.SQLiteAgent;
import org.apache.log4j.Logger;

/**
 * Created by andras.igneczi on 10/03/2016.
 */
public class Main
{
    private static org.apache.log4j.Logger log = Logger.getLogger(Main.class);

    public static void main(String [] argv)
    {
        try
        {
            //MozillaHelloWorld.Starter();
            //SQLiteAgent lSQLiteAgent2 = new SQLiteAgent();
            //lSQLiteAgent2.InitializeDatabase();
            //Root.SQLiteHelloWorld.Test7();
            //Root.XmlHelloWorld.Test();
            //System.exit(0);

            //Root.JxBrowserHelloWorld.HelloWorld();
	        //Root.JxBrowserHelloWorld.FlashSample();

            // Initialize the configuration
            Util.Configuration lConfiguration = Util.Configuration.getInstance();

            WebPageGuest lGuest = WebPageGuestFactory.Create( "WizzAir" );
            lGuest.DoSearchFromConfig();
/*
            lGuest.DoSearch( "SOF", "HHN", "2016.07.02.", "2016.07.05." );
            lGuest.DoSearch( "SOF", "HHN", "2016.08.06.", "2016.08.09." );
            lGuest.DoSearch( "CRL", "BUD", "2016.07.08.", "2016.07.11." );
            lGuest.DoSearch( "CRL", "BUD", "2016.07.22.", "2016.07.25." );
            lGuest.DoSearch( "BUD", "CRL", "2016.07.11.", "" );
*/
            FileWriterAgent lFWA = new FileWriterAgent( "database.html" );
            SQLiteAgent lSQLiteAgent = new SQLiteAgent();
            lSQLiteAgent.InitializeDatabase();
            lFWA.setNextAgent( lSQLiteAgent );

            for( int i = 0; i < 1000; )
            {
                TravelData_RESULT lResult = ResultQueue.getInstance().pop();
                if( lResult != null )
                {
                    lFWA.Archive( lResult );
                    continue;
                }
                Thread.sleep( 1800 );
                i++;
            }
            lGuest.stop();
        }
        catch( Exception e )
        {
            e.printStackTrace();
        }
/*
        Root.SQLiteHelloWorld.Test1( new String[0] );
        Root.SQLiteHelloWorld.Test2( new String[0] );
        Root.SQLiteHelloWorld.Test3( new String[0] );
        Root.SQLiteHelloWorld.Test4( new String[0] );
        Root.SQLiteHelloWorld.Test5( new String[0] );
        Root.SQLiteHelloWorld.Test6( new String[0] );

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
        log.debug("This is debug : " + parameter);
        log.info("This is info : " + parameter);
        log.warn("This is warn : " + parameter);
        log.error("This is error : " + parameter);
        log.fatal("This is fatal : " + parameter);
    }
}
