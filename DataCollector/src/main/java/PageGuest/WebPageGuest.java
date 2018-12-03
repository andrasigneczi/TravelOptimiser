package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode.*;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyEventType.*;

import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by andras.igneczi on 15/03/2016.
 */
public abstract class WebPageGuest extends PageGuest
{
//    protected BrowserState  mBrowserState     = null;
    protected Robot         mRobot            = null;
    protected Insets        mInsets;
    private   String        mURL;

    final protected String mGetElementByXPathPattern = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";

    public WebPageGuest(String aAirline, String aURL)
    {
        super( aAirline );
        mURL = aURL;
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
        mInsets = new Insets(0, 0, 0, 0);
    }

    public void MouseMove( int aX, int aY)
    {
        mRobot.mouseMove( aX + mInsets.left, aY + mInsets.top );
    }
    public void MouseMoveAround( int aX, int aY)
    {
        MouseMove( aX - 1, aY - 1);
        Sleep( 100 );
        MouseMove( aX, aY - 1);
        Sleep( 100 );
        MouseMove( aX, aY );
    }

    public void MouseLeftClick( int aX, int aY)
    {
        mRobot.mouseMove(aX + mInsets.left, aY + mInsets.top);
        mRobot.mousePress(InputEvent.BUTTON1_MASK);
        mRobot.mouseRelease(InputEvent.BUTTON1_MASK);
    }

    public void PressCtrlA()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_CONTROL);
        mRobot.keyPress(KeyEvent.VK_A);
        mRobot.keyRelease(KeyEvent.VK_A);
        mRobot.keyRelease(KeyEvent.VK_CONTROL);
    }

    public void PressUp()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_UP);
        mRobot.keyRelease(KeyEvent.VK_UP);
    }

    public void PressDown()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_DOWN);
        mRobot.keyRelease(KeyEvent.VK_DOWN);
    }

    public void PressTab()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_TAB);
        mRobot.keyRelease(KeyEvent.VK_TAB);
    }

    public void PressShiftTab()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_SHIFT);
        mRobot.keyPress(KeyEvent.VK_TAB);
        mRobot.keyRelease(KeyEvent.VK_TAB);
        mRobot.keyRelease(KeyEvent.VK_SHIFT);
    }

    public void PressDelete()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_DELETE);
        mRobot.keyRelease(KeyEvent.VK_DELETE);
    }

    public void PressBackspace()
    {
        if (mRobot == null)
        {
            return;
        }
        mRobot.keyPress(KeyEvent.VK_BACK_SPACE);
        mRobot.keyRelease(KeyEvent.VK_BACK_SPACE);
    }

    public void TypeText(String aText)
    {
        if (mRobot == null)
        {
            return;
        }

        for (int i = 0; i < aText.length(); i++)
        {
            Sleep( 200 );
            char lC = aText.charAt(i);
            if (lC >= 'A' && lC <= 'Z')
            {
                mRobot.keyPress(KeyEvent.VK_SHIFT);
                mRobot.keyPress(KeyEvent.VK_A + lC - 'A');
                mRobot.keyRelease(KeyEvent.VK_A + lC - 'A');
            }

            if ((lC >= 'a' && lC <= 'z'))
            {
                mRobot.keyPress(KeyEvent.VK_A + lC - 'a');
                mRobot.keyRelease(KeyEvent.VK_A + lC - 'a');
            }

            if ((lC >= '0' && lC <= '9'))
            {
                mRobot.keyPress(KeyEvent.VK_0 + lC - '0');
                mRobot.keyRelease(KeyEvent.VK_0 + lC - '0');
            }

            if (lC >= 'A' && lC <= 'Z')
            {
                mRobot.keyRelease(KeyEvent.VK_SHIFT);
            }

            if (lC == ' ')
            {
                mRobot.keyPress(KeyEvent.VK_SPACE);
                mRobot.keyRelease(KeyEvent.VK_SPACE);
            }

            if (lC == ',')
            {
                mRobot.keyPress(KeyEvent.VK_COMMA);
                mRobot.keyRelease(KeyEvent.VK_COMMA);
            }

            if (lC == '.')
            {
                mRobot.keyPress(KeyEvent.VK_COLON);
                mRobot.keyRelease(KeyEvent.VK_COLON);
            }

            if (lC == '(')
            {
                mRobot.keyPress(KeyEvent.VK_SHIFT);
                mRobot.keyPress(KeyEvent.VK_8);
                mRobot.keyRelease(KeyEvent.VK_8);
                mRobot.keyRelease(KeyEvent.VK_SHIFT);
            }

            if (lC == ')')
            {
                mRobot.keyPress(KeyEvent.VK_SHIFT);
                mRobot.keyPress(KeyEvent.VK_9);
                mRobot.keyRelease(KeyEvent.VK_9);
                mRobot.keyRelease(KeyEvent.VK_SHIFT);
            }

            if (lC == '\t')
            {
                mRobot.keyPress(KeyEvent.VK_TAB);
                mRobot.keyRelease(KeyEvent.VK_TAB);
            }

            if (lC == '\n')
            {
                mRobot.keyPress(KeyEvent.VK_ENTER);
                mRobot.keyRelease(KeyEvent.VK_ENTER);
            }
        }
    }

    public String getURL()
    {
        return mURL;
    }

    public void setURL( String mURL )
    {
        this.mURL = mURL;
    }

    private void javaScriptSetFocus( Browser aBrowser, String aXPath )
    {
        aBrowser.executeJavaScript( String.format( mGetElementByXPathPattern + ".focus();", aXPath ));
    }

    public void javaScriptSubmit( Browser aBrowser, String aXPath )
    {
        aBrowser.executeJavaScript( String.format( mGetElementByXPathPattern + ".submit();", aXPath ));
    }

    private void javaSendKeys( Browser aBrowser, String aXPath, int aKey )
    {
        String lSendKeys = ";TraveDataOptimizer.sendkeys(" + String.format( "%d", aKey ) + ");";
        aBrowser.executeJavaScript( String.format( "var TraveDataOptimizer = " + mGetElementByXPathPattern + lSendKeys, aXPath ));
    }

    private void javaScriptClick( Browser aBrowser, String aXPath )
    {
        aBrowser.executeJavaScript( String.format( mGetElementByXPathPattern + ".click();", aXPath ));
    }

    public static DOMElement findElementByAttrib( DOMDocument aDOMDocument, String tagName, String attribName, String attribValue )
    {
        java.util.List<DOMElement> tags = aDOMDocument.findElements( By.tagName( tagName));

        for( DOMElement element : tags )
        {
            String value = element.getAttribute( attribName );
            if( value != null && value.equals( attribValue ))
                return element;
        }
        return null;
    }

    // JxBrowser robot
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
        keyCodeHashMap.put( '0', BrowserKeyEvent.KeyCode.VK_0);
        keyCodeHashMap.put( '1', BrowserKeyEvent.KeyCode.VK_1);
        keyCodeHashMap.put( '2', BrowserKeyEvent.KeyCode.VK_2);
        keyCodeHashMap.put( '3', BrowserKeyEvent.KeyCode.VK_3);
        keyCodeHashMap.put( '4', BrowserKeyEvent.KeyCode.VK_4);
        keyCodeHashMap.put( '5', BrowserKeyEvent.KeyCode.VK_5);
        keyCodeHashMap.put( '6', BrowserKeyEvent.KeyCode.VK_6);
        keyCodeHashMap.put( '7', BrowserKeyEvent.KeyCode.VK_7);
        keyCodeHashMap.put( '8', BrowserKeyEvent.KeyCode.VK_8);
        keyCodeHashMap.put( '9', BrowserKeyEvent.KeyCode.VK_9);
    }

    public static void typeText(Browser browser, String aText)
    {
        for (int i = 0; i < aText.length(); i++)
        {
            Sleep( 200 );
            char lC = aText.charAt(i);
            if ((lC >= 'A' && lC <= 'Z') || lC == '\t' || lC == '\n' || (lC >= '0' && lC <= '9'))
            {
                browser.forwardKeyEvent(new BrowserKeyEvent(TYPED, keyCodeHashMap.getOrDefault( lC, BrowserKeyEvent.KeyCode.VK_A ), lC ));
                Sleep(200);
            } else if (lC >= 'a' && lC <= 'z') {
                browser.forwardKeyEvent(new BrowserKeyEvent(TYPED, keyCodeHashMap.getOrDefault( 'A' + lC - 'a', BrowserKeyEvent.KeyCode.VK_A ), lC ));
                Sleep(200);
            }
        }
    }
}
