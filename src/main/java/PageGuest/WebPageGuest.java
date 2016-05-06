package PageGuest;

import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.Hashtable;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by andras.igneczi on 15/03/2016.
 */
public abstract class WebPageGuest
{
    private   Hashtable<String, String> mAirports;
    protected TravelData_RESULT         mTravelDataResult = null;
    protected BrowserState              mBrowserState     = null;
    protected Robot                     mRobot            = null;
    private final String mAirline;
    protected Insets mInsets;

    final protected String mGetElementByXPathPattern = "document.evaluate('%s', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue";

    public abstract void DoSearch(String aAirportCode_Way_From, String aAirportCode_Way_To,
                                  String aDepartureDate_Way_To, String aReturnDate_Way_Back);

    public abstract void DoSearchFromConfig();

    public abstract void stop();

    public WebPageGuest(String aAirline)
    {
        GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice      screen      = environment.getDefaultScreenDevice();
        mAirline = aAirline;
        InitAirportList();
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

    private void InitAirportList()
    {
        Scanner lScanner = new Scanner(
                getClass().getClassLoader().getResourceAsStream("airports_" + mAirline + ".txt"), "UTF-8");
        String lAirports = lScanner.useDelimiter("\\A").next();
        lScanner.close();

        mAirports = new Hashtable<String, String>();
        Pattern reg = Pattern.compile("^(.+)$", Pattern.MULTILINE);
        Matcher m   = reg.matcher(lAirports);

        while (m.find())
        {
            String lRow = m.group().toString().trim();
            if (lRow.startsWith("#"))
            {
                continue;
            }

            String lAirporCode = lRow.substring(0, 3);
            String lAirporName = lRow.substring(4);
            mAirports.put(lAirporCode, lAirporName);
        }
    }

    public String getAirportName(String aCode)
    {
        return mAirports.get(aCode);
    }

    public void setBrowserState(BrowserState aBrowserState)
    {
        mBrowserState = aBrowserState;
    }

    public BrowserState getBrowserState()
    {
        return mBrowserState;
    }

    protected void Sleep(int aValue)
    {
        try
        {
            Thread.sleep(aValue);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }

    public String getAirline()
    {
        return mAirline;
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

}
