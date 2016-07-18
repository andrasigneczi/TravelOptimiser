package PageGuest;

import BrowserState.BrowserState;

import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

/**
 * Created by andras.igneczi on 15/03/2016.
 */
public abstract class WebPageGuest extends PageGuest
{
    protected BrowserState  mBrowserState     = null;
    protected Robot         mRobot            = null;
    protected Insets        mInsets;
    private   String        mURL;

    final protected String mGetElementByXPathPattern = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";

    public abstract void stop();

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

    public void setBrowserState(BrowserState aBrowserState)
    {
        mBrowserState = aBrowserState;
    }

    public BrowserState getBrowserState()
    {
        return mBrowserState;
    }

    public void MouseMove( int aX, int aY)
    {
        mRobot.mouseMove( aX + mInsets.left, aY + mInsets.top );
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

}
