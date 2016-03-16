import PageGuest.WebPageGuest;
import javafx.scene.shape.Path;

import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

/**
 * Created by andras.igneczi on 10/03/2016.
 */
public class Main
{
    public static void main( String[] args ) throws InterruptedException
    {

        try
        {
            //JxBrowserHelloWorld.HelloWorld();
	        //JxBrowserHelloWorld.FlashSample();
            WebPageGuest lGuest = WebPageGuestFactory.Create( "WizzAir" );
            lGuest.DoSearch( "SOF", "HHN", "2016.07.21.", "2016.07.23." );
        }
        catch( Exception e )
        {
            e.printStackTrace();
        }
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
}
