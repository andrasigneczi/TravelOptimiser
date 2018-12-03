package HelloWorld; /**
 * Created by andras.igneczi on 11/03/2016.
 */
import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.BrowserMouseEvent;
import com.teamdev.jxbrowser.chromium.LoadURLParams;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode.*;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyEventType.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.Map;

import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode.VK_H;

public class JxBrowserHelloWorld {

    public static void main(String[] args) throws Exception
    {
        JxBrowserHelloWorld.HelloWorld();
    }
    static int temp = 0;
    static Robot         mRobot            = null;

    static void initRobot() {
        GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice      screen      = environment.getDefaultScreenDevice();
        try
        {
            mRobot = new Robot(screen);
            //mRobot.setAutoDelay( 100 );
        }
        catch (AWTException e)
        {
            e.printStackTrace();
        }

    }

    final static Map<Character, KeyCode> keyCodeHashMap = new HashMap<Character, BrowserKeyEvent.KeyCode>();
    static {
        keyCodeHashMap.put( 'A', BrowserKeyEvent.KeyCode.VK_A);
        keyCodeHashMap.put( 'B', BrowserKeyEvent.KeyCode.VK_B);
        keyCodeHashMap.put( 'C', BrowserKeyEvent.KeyCode.VK_C);
        keyCodeHashMap.put( 'D', BrowserKeyEvent.KeyCode.VK_D);
        keyCodeHashMap.put( 'E', BrowserKeyEvent.KeyCode.VK_E);
        keyCodeHashMap.put( 'F', BrowserKeyEvent.KeyCode.VK_F);
        keyCodeHashMap.put( 'G', BrowserKeyEvent.KeyCode.VK_G);
        keyCodeHashMap.put( 'H', BrowserKeyEvent.KeyCode.VK_H);
        keyCodeHashMap.put( 'I', BrowserKeyEvent.KeyCode.VK_I);
        keyCodeHashMap.put( 'J', BrowserKeyEvent.KeyCode.VK_J);
        keyCodeHashMap.put( 'K', BrowserKeyEvent.KeyCode.VK_K);
        keyCodeHashMap.put( 'L', BrowserKeyEvent.KeyCode.VK_L);
        keyCodeHashMap.put( 'M', BrowserKeyEvent.KeyCode.VK_M);
        keyCodeHashMap.put( 'N', BrowserKeyEvent.KeyCode.VK_N);
        keyCodeHashMap.put( 'O', BrowserKeyEvent.KeyCode.VK_O);
        keyCodeHashMap.put( 'P', BrowserKeyEvent.KeyCode.VK_P);
        keyCodeHashMap.put( 'Q', BrowserKeyEvent.KeyCode.VK_Q);
        keyCodeHashMap.put( 'R', BrowserKeyEvent.KeyCode.VK_R);
        keyCodeHashMap.put( 'S', BrowserKeyEvent.KeyCode.VK_S);
        keyCodeHashMap.put( 'T', BrowserKeyEvent.KeyCode.VK_T);
        keyCodeHashMap.put( 'U', BrowserKeyEvent.KeyCode.VK_U);
        keyCodeHashMap.put( 'V', BrowserKeyEvent.KeyCode.VK_V);
        keyCodeHashMap.put( 'W', BrowserKeyEvent.KeyCode.VK_W);
        keyCodeHashMap.put( 'X', BrowserKeyEvent.KeyCode.VK_X);
        keyCodeHashMap.put( 'Y', BrowserKeyEvent.KeyCode.VK_Y);
        keyCodeHashMap.put( 'Z', BrowserKeyEvent.KeyCode.VK_Z);
        keyCodeHashMap.put( '\n', BrowserKeyEvent.KeyCode.VK_RETURN);
        keyCodeHashMap.put( '\t', BrowserKeyEvent.KeyCode.VK_TAB);
    }

    public static void typeText(Browser browser, String aText)
    {
        for (int i = 0; i < aText.length(); i++)
        {
            Sleep( 200 );
            char lC = aText.charAt(i);
            if ((lC >= 'A' && lC <= 'Z') || lC == '\t' || lC == '\n')
            {
                browser.forwardKeyEvent(new BrowserKeyEvent(TYPED, keyCodeHashMap.getOrDefault( lC, BrowserKeyEvent.KeyCode.VK_A ), lC ));
                Sleep(200);
            } else if (lC >= 'a' && lC <= 'z') {
                browser.forwardKeyEvent(new BrowserKeyEvent(TYPED, keyCodeHashMap.getOrDefault( 'A' + lC - 'a', BrowserKeyEvent.KeyCode.VK_A ), lC ));
                Sleep(200);
            }
        }
    }
    public static void Sleep(int millis) {
        try
        {
            Thread.sleep(millis);
        }
        catch( InterruptedException e )
        {
            e.printStackTrace();
        }
    }

	public static void HelloWorld() throws Exception {
        initRobot();
        final Browser browser = new Browser();
        BrowserView view = new BrowserView(browser);

        //final JTextField addressBar = new JTextField("http://www.teamdev.com/jxbrowser");
        //final JTextField addressBar = new JTextField("http://www.momondo.com");
        final JTextField addressBar = new JTextField("https://wizzair.com/");
        //final JTextField addressBar = new JTextField("https://wizzair.com/#/booking/select-flight/BUD/CRL/2019-01-18/null/1/0/0/0/null");
        addressBar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                browser.loadURL(addressBar.getText());
            }
        });

        JPanel addressPane = new JPanel(new BorderLayout());
        addressPane.add(new JLabel(" URL: "), BorderLayout.WEST);
        addressPane.add(addressBar, BorderLayout.CENTER);

        JFrame frame = new JFrame("JxBrowser - Hello World");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.add(addressPane, BorderLayout.NORTH);
        frame.add(view, BorderLayout.CENTER);
        frame.setSize(800, 800);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        //
        browser.addLoadListener(new LoadAdapter() {
            @Override
            public void onStartLoadingFrame(StartLoadingEvent event) {
                if (event.isMainFrame()) {
                    System.out.println("Main frame has started loading");
                }
            }

            @Override
            public void onProvisionalLoadingFrame(ProvisionalLoadingEvent event) {
                if (event.isMainFrame()) {
                    System.out.println("Provisional load was committed for a frame");
                }
            }

            @Override
            public void onFinishLoadingFrame(FinishLoadingEvent event) {
                if (event.isMainFrame()) {
                    System.out.println("Main frame has finished loading");
                    if(temp == 0) {
                        // origin text field
                        Sleep(4000);
                        DOMNode origin = event.getBrowser().getDocument().findElement( By.xpath( "//*[@id=\"search-departure-station\"]" ) );
                        origin.click();
                        typeText( event.getBrowser(), "Budap" );

                        DOMElement value0 = event.getBrowser().getDocument().findElement( By.xpath( "//*[@id=\"flight-search\"]/div/div/div[3]/form/div[1]/fieldset/div[3]/div/div[3]/div[1]/label" ) );
                        value0.click();
                        Sleep(2000);
                        //*[@id="flight-search"]/div/div/div[3]/form/div[1]/fieldset/div[3]/div/div[3]/div[1]/label
                        // destionation text field
                        DOMNode destionation = event.getBrowser().getDocument().findElement( By.xpath( "//*[@id=\"search-arrival-station\"]" ) );
                        destionation.click();
                        typeText( event.getBrowser(), "CHARLE" );
                        value0.click();
                        Sleep(2000);
                        //value0.click();
                        //Sleep(2000);

                        // click the submit
                        DOMNode link = event.getBrowser().getDocument().findElement( By.xpath( "//*[@id=\"flight-search\"]/div/div/div[3]/form/div[4]/button" ) );

                        if( link != null )
                        {
                            Rectangle rect = ((DOMElement)link).getBoundingClientRect();
                            BrowserMouseEvent.BrowserMouseEventBuilder meb = new BrowserMouseEvent.BrowserMouseEventBuilder();
                            meb.setButtonType( BrowserMouseEvent.MouseButtonType.PRIMARY );
                            meb.setClickCount( 1 );
                            meb.setEventType( BrowserMouseEvent.MouseEventType.MOUSE_PRESSED );
                            meb.setGlobalX( 0);
                            meb.setGlobalY( 0);
                            meb.setX( (int)rect.getX() );
                            meb.setY( (int)rect.getY() );
                            meb.setWhen( 1 );
                            event.getBrowser().forwardMouseEvent( meb.build() );
                            //Sleep( 200 );
                            meb.setEventType( BrowserMouseEvent.MouseEventType.MOUSE_RELEASED );
                            event.getBrowser().forwardMouseEvent( meb.build() );
                            //valueO.click();
                            //typeText("BUD\n");
                            Sleep( 2000 );
                            //link.click();

                        }
                    } else if(temp == 1)
                    {
                        Sleep( 2000 );
                        browser.loadURL( new LoadURLParams(
                                "https://be.wizzair.com/9.0.1/Api/search/search",
                                "{\"isFlightChange\":false,\"isSeniorOrStudent\":false,\"flightList\":[{\"departureStation\":\"BUD\",\"arrivalStation\":\"CRL\",\"departureDate\":\"2019-01-11\"}],\"adultCount\":1,\"childCount\":0,\"infantCount\":0,\"wdc\":true}",
                                "origin: https://wizzair.com\naccept-encoding: gzip, deflate, br\naccept-language: en-US,en;q=0.9,hu;q=0.8\nuser-agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\ncontent-type: application/json;charset=UTF-8\naccept: application/json, text/plain, */*\nreferer: https://wizzair.com/\nauthority: be.wizzair.com"
                        ) );
                    } else if(temp == 2)
                    {
                        Sleep( 2000 );
                        System.out.println("\n2. -------------------------");
                        System.out.println(event.getBrowser().getHTML());
                        browser.loadURL( new LoadURLParams(
                                "https://be.wizzair.com/9.0.1/Api/search/search",
                                "{\"isFlightChange\":false,\"isSeniorOrStudent\":false,\"flightList\":[{\"departureStation\":\"CRL\",\"arrivalStation\":\"BUD\",\"departureDate\":\"2019-01-18\"}],\"adultCount\":1,\"childCount\":0,\"infantCount\":0,\"wdc\":true}",
                                "origin: https://wizzair.com\naccept-encoding: gzip, deflate, br\naccept-language: en-US,en;q=0.9,hu;q=0.8\nuser-agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\ncontent-type: application/json;charset=UTF-8\naccept: application/json, text/plain, */*\nreferer: https://wizzair.com/\nauthority: be.wizzair.com"
                        ) );
                    } else if(temp == 3)
                    {
                        System.out.println("\n3. -------------------------");
                        System.out.println(event.getBrowser().getHTML());
                    }
                    ++temp;
                }
            }

            @Override
            public void onFailLoadingFrame(FailLoadingEvent event) {
                NetError errorCode = event.getErrorCode();
                if (event.isMainFrame()) {
                    System.out.println("Main frame has failed loading: " + errorCode);
                }
            }

            @Override
            public void onDocumentLoadedInFrame(FrameLoadEvent event) {
                System.out.println("Frame document is loaded.");
            }

            @Override
            public void onDocumentLoadedInMainFrame(LoadEvent event) {
                System.out.println("Main frame document is loaded.");
            }
        });

/*
        browser.addLoadListener(new LoadAdapter() {
            @Override
            public void onFinishLoadingFrame(FinishLoadingEvent event) {
                if (event.isMainFrame())
                {
                    DOMDocument document = event.getBrowser().getDocument();
                    //DOMElement element = document.findElement( By.xpath("//textarea"));
                    //DOMTextAreaElement textArea = (DOMTextAreaElement) element;

                    // source
                    DOMElement elementTextSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation" ) );
                    DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
                    textInputSource.setValue( "Szófia (SOF)" );

                    DOMElement elementIdSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation" ) );
                    DOMInputElement hiddenInputSource = (DOMInputElement)elementIdSource;
                    hiddenInputSource.setValue( "SOF" );

                    // target
                    String lTargetInputId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
                    DOMElement elementTextTarget = document.findElement( By.id( lTargetInputId ) );
                    DOMInputElement textInputTarget = (DOMInputElement)elementTextTarget;
                    textInputTarget.setValue( "Frankfurt Hahn (HHN)" );

                    DOMElement elementIdTarget = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ) );
                    DOMInputElement hiddenInputTarget = (DOMInputElement)elementIdTarget;
                    hiddenInputTarget.setValue( "HHN" );

                    // departure date
                    DOMElement elementIdDepartureDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate" ) );
                    DOMInputElement inputDepartureDate = (DOMInputElement)elementIdDepartureDate;
                    inputDepartureDate.setValue( "2016.07.21." );

                    // arrival date
                    DOMElement elementIdReturnDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate" ) );
                    DOMInputElement inputReturnDate = (DOMInputElement)elementIdReturnDate;
                    inputReturnDate.setValue( "2016.07.23." );

                    // click the button
                    DOMNode link = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
                    if( link != null )
                    {
                        link.click();
                    }
                }
            }
        });
*/

        browser.loadURL(addressBar.getText());
    }
}
