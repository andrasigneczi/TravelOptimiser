import PageGuest.ResultQueue;
import PageGuest.TravelData_RESULT;
import PageGuest.WebPageGuest;
import Storage.FileWriterAgent;
import Storage.SQLiteAgent;
import javafx.scene.shape.Path;
import org.apache.log4j.Logger;

import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.logging.Level;

/**
 * Created by andras.igneczi on 10/03/2016.
 */
public class Main
{
    private static org.apache.log4j.Logger log = Logger.getLogger(Main.class);

    public static void main( String[] args ) throws InterruptedException
    {
        try
        {
            //JxBrowserHelloWorld.HelloWorld();
	        //JxBrowserHelloWorld.FlashSample();
            WebPageGuest lGuest = WebPageGuestFactory.Create( "WizzAir" );
            lGuest.DoSearch( "SOF", "HHN", "2016.07.02.", "2016.07.05." );
            lGuest.DoSearch( "SOF", "HHN", "2016.08.06.", "2016.08.09." );
            lGuest.DoSearch( "CRL", "BUD", "2016.07.08.", "2016.07.11." );
            FileWriterAgent lFWA = new FileWriterAgent( "database.html" );
            SQLiteAgent lSQLiteAgent = new SQLiteAgent();
            lSQLiteAgent.InitializeDatabase();
            //lFWA.setNextAgent( lSQLiteAgent );

            for( int i = 0; i < 100; i++ )
            {
                TravelData_RESULT lResult = ResultQueue.getInstance().pop();
                if( lResult != null )
                    lFWA.Archive( lResult );
                Thread.sleep( 1000 );
            }
            lGuest.stop();
        }
        catch( Exception e )
        {
            e.printStackTrace();
        }
/*
        SQLiteHelloWorld.Test1( new String[0] );
        SQLiteHelloWorld.Test2( new String[0] );
        SQLiteHelloWorld.Test3( new String[0] );
        SQLiteHelloWorld.Test4( new String[0] );
        SQLiteHelloWorld.Test5( new String[0] );
        SQLiteHelloWorld.Test6( new String[0] );

        runMe( "hello" );
*/
/*
        Thread.sleep(1000000);
        System.exit(-1);

        HttpRequest lH = new HttpRequest();
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
