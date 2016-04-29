package PageGuest;

import Util.CurrencyHelper;
import Util.DatetimeHelper;
import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.dom.DOMNodeAtPoint;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 15/03/2016.
 */
public class RyanAirPageGuest extends WebPageGuest implements Runnable
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest.class);

    ArrayList<TravelData_INPUT> mSearchQueue;
    Thread                      mThread;
    Browser mBrowser       = null;
    Object  mMutex         = new Object();
    boolean mThreadStopped = true;

    enum PageType
    {
        PT_UNKNOWN, PT_FIRST, PT_RESULT
    }

    ;
    PageType mPageType = PageType.PT_UNKNOWN;

    public RyanAirPageGuest()
    {
        super("ryanair");
        mSearchQueue = new ArrayList<TravelData_INPUT>();
        mThread = new Thread(this);
        mThread.setName("RyanAirThread " + LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        mThread.start();
        System.out.println("RyanAirPageGuest()");
    }

    public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate)
    {
        if (!ValidateDate(aDepartureDate, aReturnDate))
        {
            mLogger.warn("DoSearch: the departure date (" + aDepartureDate + ") or the return date " +
                                 aReturnDate + " expired!");
            return;
        }

        synchronized (mMutex)
        {
            if (mBrowser == null)
            {
                InitBrowser();
                mBrowser.loadURL("http://www.ryanair.com");
            }

            TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
            lTravelDataInput.mAirline = getAirline();
            lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
            lTravelDataInput.mAirportCode_GoingTo = aTo;
            lTravelDataInput.mDepartureDay = aDepartureDate;
            lTravelDataInput.mReturnDay = aReturnDate;
            lTravelDataInput.mAdultNumber = "1";
            lTravelDataInput.mChildNumber = "0";
            lTravelDataInput.mInfantNumber = "0";
            //lTravelDataInput.mNearbyAirports          = false;
            if (aReturnDate.length() == 0)
            {
                lTravelDataInput.mReturnTicket = false;
            }
            else
            {
                lTravelDataInput.mReturnTicket = true;
            }

            mSearchQueue.add(lTravelDataInput);
        }
        System.out.println("DoSearch()");
    }

    public void DoSearchFromConfig()
    {
        synchronized (mMutex)
        {
            if (mBrowser == null)
            {
                InitBrowser();
                mBrowser.loadURL("http://www.ryanair.com");
            }

            ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
            for (TravelData_INPUT lTDI : lSearchList)
            {
                if (!lTDI.mAirline.equals(getAirline()))
                {
                    continue;
                }

                if (!ValidateDate(lTDI.mDepartureDay, lTDI.mReturnDay))
                {
                    mLogger.warn("DoSearch: the departure date (" + lTDI.mDepartureDay + ") or the return date " +
                                         lTDI.mReturnDay + " expired!");
                    continue;
                }

                if (lTDI.mReturnDay.length() == 0)
                {
                    lTDI.mReturnTicket = false;
                }
                mSearchQueue.add(lTDI);
            }
        }
    }

    private boolean ValidateDate(String aDepartureDay, String aReturnDay)
    {
        try
        {
            DateTimeFormatter lFormatter    = DateTimeFormatter.ofPattern("yyyy.MM.dd.");
            LocalDate         lDepartureDay = LocalDate.parse(aDepartureDay, lFormatter);
            if (LocalDate.now().isAfter(lDepartureDay))
            {
                return false;
            }

            if (aDepartureDay.length() == 0)
            {
                return true;
            }

            LocalDate lReturnDay = LocalDate.parse(aReturnDay, lFormatter);
            if (lReturnDay.isBefore(lDepartureDay))
            {
                return false;
            }
            return true;
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return false;
    }

    private boolean InitBrowser()
    {
        new BrowserStateInit().doAction(this);

        //mBrowser = new Browser();
        mBrowser = TeamDevJxBrowser.getInstance().getJxBrowser(getAirline());
        BrowserView view = new BrowserView(mBrowser);

        //final JTextField addressBar = new JTextField("http://www.teamdev.com/jxbrowser");
        //final JTextField addressBar = new JTextField("http://www.momondo.com");
//		final JTextField addressBar = new JTextField("http://www.wizzair.com");
//		addressBar.addActionListener(new ActionListener() {
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				mBrowser.loadURL(addressBar.getText());
//			}
//		});

//		JPanel addressPane = new JPanel(new BorderLayout());
//		addressPane.add(new JLabel(" URL: "), BorderLayout.WEST);
//		addressPane.add(addressBar, BorderLayout.CENTER);

        JFrame frame = new JFrame("Travel Optimizer");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//		frame.add(addressPane, BorderLayout.NORTH);
        frame.add(view, BorderLayout.CENTER);
        frame.setSize(1152, 1000);
        frame.setLocation(0, 0);
        //frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        System.out.println("InitBrowser()");
        return false;
    }

    @Override
    public void stop()
    {
        mThreadStopped = true;
        try
        {
            mThread.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("stop()");
    }

    private void PageIdentifier()
    {
        if (mBrowser == null || mBrowser.getDocument() == null)
        {
            return;
        }

        DOMElement elementTextSource = null;
        elementTextSource = mBrowser.getDocument().findElement(By.className("flight-selector-listing"));
        if (elementTextSource != null)
        {
            if (mPageType == PageType.PT_RESULT)
            {
                return;
            }
            Sleep(2000);
            mPageType = PageType.PT_RESULT;
        }
        else
        {
            elementTextSource = mBrowser.getDocument().findElement(By.name("departureAirportName"));
            if (elementTextSource != null)
            {
                if (mPageType == PageType.PT_FIRST)
                {
                    return;
                }
                mPageType = PageType.PT_FIRST;
            }
            else
            {
                mPageType = PageType.PT_UNKNOWN;
                return;
            }
        }

        TravelData_INPUT lTravelDataInput = null;
        if (getBrowserState().toString().equals("BrowserStateSearching"))
        {
            lTravelDataInput = ((BrowserStateSearching) getBrowserState()).getTravelDataInput();
        }

        DOMDocument lDOMDocument = mBrowser.getDocument();
        if (lTravelDataInput == null)
        {
            if (mPageType == PageType.PT_FIRST)
            {
                new BrowserStateReadyToSearch(lDOMDocument).doAction(getBrowserState().getWebPageGuest());
            }
        }
        else
        {
            new BrowserStateSearchingFinished(lDOMDocument, lTravelDataInput).doAction(
                    getBrowserState().getWebPageGuest());
        }
    }

    private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
    {
        // TODO: the departure/arrival datetime's year must be filled
        mTravelDataResult = new TravelData_RESULT();
        mTravelDataResult.mAirline = aTravelDataInput.mAirline;
        mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
        mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
        mTravelDataResult.mTravelDataInput = aTravelDataInput;
        TravelData_RESULT.TravelData_PossibleTrips lTripOutbound = null;
        TravelData_RESULT.TravelData_PossibleTrips lTripReturn   = null;

        java.util.List<DOMElement> lFlightsBodyElements = document.findElements(By.className("slide ng-scope active"));

        int lCellIndex = 0;
        for (DOMElement lFlightBodyElement : lFlightsBodyElements)
        {
            if (lCellIndex == 0)
            {
                lTripOutbound = new TravelData_RESULT.TravelData_PossibleTrips();
                lTripOutbound.mOutboundTrip = true;

                // date
                java.util.List<DOMElement> lDate1 = lFlightBodyElement.findElements(By.className("date ng-binding"));
                lTripOutbound.mDepartureDatetime = ((DOMElement) lDate1.get(0)).getInnerText(); // Only the date
                lTripOutbound.mArrivalDatetime = lTripOutbound.mDepartureDatetime;

                // price
                java.util.List<DOMElement> lPrice1 = lFlightBodyElement.findElements(By.className("fare ng-binding"));
                lTripOutbound.mPrices_BasicFare_Normal = ((DOMElement) lPrice1.get(0)).getInnerText();
                lCellIndex++;
            }
            else
            {
                if (lCellIndex == 1)
                {
                    lTripReturn = new TravelData_RESULT.TravelData_PossibleTrips();
                    lTripReturn.mOutboundTrip = false;
                    // date
                    java.util.List<DOMElement> lDate1 = lFlightBodyElement.findElements(
                            By.className("date ng-binding"));
                    lTripReturn.mDepartureDatetime = ((DOMElement) lDate1.get(0)).getInnerText();  // Only the date
                    lTripReturn.mArrivalDatetime = lTripReturn.mDepartureDatetime;

                    // price
                    java.util.List<DOMElement> lPrice1 = lFlightBodyElement.findElements(
                            By.className("fare ng-binding"));
                    lTripReturn.mPrices_BasicFare_Normal = ((DOMElement) lPrice1.get(0)).getInnerText();
                    //lTrip.mPrices_PlusFare_Normal;
                    lCellIndex++;
                }
            }
        }

        java.util.List<DOMElement> lFlightBasic = document.findElements(By.className("flight-basic"));
        lCellIndex = 0;
        for (DOMElement lFlightBasicElement : lFlightBasic)
        {
            java.util.List<DOMElement> lTimes = lFlightBasicElement.findElements(By.className("time ng-binding"));
            for (DOMElement lTimeElement : lTimes)
            {
                String lTime = lTimeElement.getInnerText();
                switch (lCellIndex)
                {
                    case 0: // outbound departure time
                        lTripOutbound.mDepartureDatetime += " " + lTime;
                        break;
                    case 1: // outbound arrival time
                        lTripOutbound.mArrivalDatetime += " " + lTime;
                        break;
                    case 2: // return departure time
                        lTripReturn.mDepartureDatetime += " " + lTime;
                        break;
                    case 3: // return arrival time
                        lTripReturn.mArrivalDatetime += " " + lTime;
                        break;
                }
                lCellIndex++;
            }
        }

        java.util.List<DOMElement> lPrices = document.findElements(By.className("price ng-binding"));
        lCellIndex = 0;
        for (DOMElement lPriceElement : lPrices)
        {
            String lPrice = lPriceElement.getInnerText();
            switch (lCellIndex)
            {
                case 0: // outbound normal price
                    if (!lTripOutbound.mPrices_BasicFare_Normal.equals(lPrice))
                    {
                        mLogger.warn("Something wrong with the outbound basic fare price collection");
                    }
                    break;
                case 1: // outbound business price
                    lTripOutbound.mPrices_PlusFare_Normal = lPrice;
                    break;
                case 2: // return norml price
                    if (!lTripReturn.mPrices_BasicFare_Normal.equals(lPrice))
                    {
                        mLogger.warn("Something wrong with the return basic fare price collection");
                    }
                    break;
                case 3: // return business price
                    lTripReturn.mPrices_PlusFare_Normal = lPrice;
                    break;
            }
            lCellIndex++;
        }

        lTripOutbound.mArrivalDatetime = DatetimeHelper.ConvertFromRyanairFormat(lTripOutbound.mArrivalDatetime);
        lTripOutbound.mDepartureDatetime = DatetimeHelper.ConvertFromRyanairFormat(lTripOutbound.mDepartureDatetime);
        lTripReturn.mArrivalDatetime = DatetimeHelper.ConvertFromRyanairFormat(lTripReturn.mArrivalDatetime);
        lTripReturn.mDepartureDatetime = DatetimeHelper.ConvertFromRyanairFormat(lTripReturn.mDepartureDatetime);

        lTripOutbound.mPrices_BasicFare_Normal = CurrencyHelper.ConvertFromRyanairFormat(
                lTripOutbound.mPrices_BasicFare_Normal);
        lTripOutbound.mPrices_PlusFare_Normal = CurrencyHelper.ConvertFromRyanairFormat(
                lTripOutbound.mPrices_PlusFare_Normal);
        lTripReturn.mPrices_BasicFare_Normal = CurrencyHelper.ConvertFromRyanairFormat(
                lTripReturn.mPrices_BasicFare_Normal);
        lTripReturn.mPrices_PlusFare_Normal = CurrencyHelper.ConvertFromRyanairFormat(
                lTripReturn.mPrices_PlusFare_Normal);

        mTravelDataResult.mTrips.add(lTripOutbound);
        mTravelDataResult.mTrips.add(lTripReturn);
        // ResultQueue.getInstance().push( mTravelDataResult );
    }

    private void ClickDateOnTheCalendar( int aDay, int aStartX, int aStartY )
    {
        String lDay = String.valueOf( aDay );
        for( int lY = 0; lY < 7; lY++ )
        {
            for( int lX = 0; lX < 7; lX++ )
            {
                DOMNodeAtPoint lNodeAtPoint   = mBrowser.getNodeAtPoint(aStartX + lX * 44, aStartY + lY * 41);
                DOMElement     lElement       = (DOMElement) lNodeAtPoint.getNode();
                if( lElement != null )
                {
                    try
                    {
                        if( lDay.equals( lElement.getInnerText()))
                        {
                            // The robot and the JxBrowser's positioning is different, we have to correct it.
                            MouseLeftClick( aStartX + lX * 44 + 15, aStartY + lY * 41 + 32 );
                            return;
                        }
                    }
                    catch ( Exception e )
                    {
                        mLogger.error( "Something wrong on the ryanair's calendar");
                    }
                }
            }
        }
    }

    private void ClickDateOnTheLeftCalendar( int iDay )
    {
        ClickDateOnTheCalendar( iDay, 192, 636 );
    }

    private void ClickDateOnTheRightCalendar( int iDay )
    {
        ClickDateOnTheCalendar( iDay, 192 + 390, 636 );
    }

    private void FillTheForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput)
    {
        // 2016 Majus 31, Dublin - 2017 Januar 4, Faro

        //String lAirportLabel  = "Budapest";
        //String lAirportLabel2 = "Brussels (CRL)";
        String lAirportLabel  = "Dublin\n";
        String lAirportLabel2 = "Faro\n";

        mRobot.delay(3000);
        // click into the leaving from field
        MouseLeftClick(175, 460);

        // fill the leaving from field
        PressCtrlA();
        PressDelete();
        TypeText(lAirportLabel);

        mRobot.delay(500);

        // click into the going to field
        MouseLeftClick(500, 460);

        // fill the going to field
        PressCtrlA();
        PressDelete();
        TypeText(lAirportLabel2);

        mRobot.delay(1000);

        // read the left calendar header
        DOMNodeAtPoint lNodeAtPoint   = mBrowser.getNodeAtPoint(222, 550);
        DOMElement     lElement       = (DOMElement) lNodeAtPoint.getNode();
        String         lLeftMonthYear = lElement.getInnerText();

        // read the right calendar header
        lNodeAtPoint = mBrowser.getNodeAtPoint(600, 550);
        lElement = (DOMElement) lNodeAtPoint.getNode();
        String lRightMonthYear = lElement.getInnerText();

        // page right on calendar
        MouseLeftClick(910, 710);

        mRobot.delay(1000);
        ClickDateOnTheLeftCalendar( 1 );
        mRobot.delay(1000);
        ClickDateOnTheRightCalendar( 10 );
        mRobot.delay(10000);

        // page left on calendar
        //MouseLeftClick(154, 710);
        return;

        // passengers
        // one way / return ticket
    }

    private void ClickTheSearchButton(DOMDocument aDOMDocument)
    {
        String lSleep = Util.Configuration.getInstance().getValue("/configuration/global/DelayBeforeClick", "3");
        Sleep(1000 * Integer.parseInt(lSleep));

        // click the Let's go (search) button
        MouseLeftClick(834, 513);
    }

    public void run()
    {
        // the JxBrowser's loadlistener doesn't work with the ryanair page
        // so, I have to observ the result.

        try
        {
            System.out.println("Thread::run");

            mThreadStopped = false;
            while (!mThreadStopped)
            {
                PageIdentifier();

                int lSearQueueSize;
                synchronized (mMutex)
                {
                    lSearQueueSize = mSearchQueue.size();
                }

                if (getBrowserState() == null)
                {
                    Sleep(100);
                    continue;
                }

                String lBrowserState = getBrowserState().toString();
                if ((lSearQueueSize == 0 && !lBrowserState.equals(
                        "BrowserStateSearchingFinished")) || lBrowserState.equals("BrowserStateInit"))
                {
                    Sleep(100);
                    continue;
                }

                if (lBrowserState.equals("BrowserStateSearchingFinished"))
                {
                    BrowserStateSearchingFinished lState           = (BrowserStateSearchingFinished) getBrowserState();
                    TravelData_INPUT              lTravelDataInput = lState.getTravelDataInput();
                    DOMDocument                   lDOMDocument     = lState.getDOMDocument();

                    // The last search has been finished, collect the datas, start a new search
                    CollectDatas(lDOMDocument, lTravelDataInput);
                    mPageType = PageType.PT_UNKNOWN;
                    new BrowserStateInit().doAction(this);
                    //mBrowser.loadURL("http://www.ryanair.com");
                    Sleep(5000);
                    //new BrowserStateReadyToSearch(lDOMDocument).doAction(this);
                }
                else
                {
                    if (lBrowserState.equals("BrowserStateReadyToSearch"))
                    {
                        BrowserStateReadyToSearch lState       = (BrowserStateReadyToSearch) getBrowserState();
                        TravelData_INPUT          lTravelDataInput;
                        DOMDocument               lDOMDocument = lState.getDOMDocument();

                        synchronized (mMutex)
                        {
                            lTravelDataInput = mSearchQueue.remove(0);
                        }
                        new BrowserStateSearching(lTravelDataInput).doAction(this);

                        FillTheForm(lDOMDocument, lTravelDataInput);
                        ClickTheSearchButton(lDOMDocument);
                    }
                }
            }
            System.out.println("run()");
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
