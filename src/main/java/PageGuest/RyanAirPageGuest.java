package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.By;
import com.teamdev.jxbrowser.chromium.dom.DOMDocument;
import com.teamdev.jxbrowser.chromium.dom.DOMElement;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.traveloptimizer.browserengine.TeamDevJxBrowser;
import org.apache.log4j.Logger;

import javax.swing.*;
import java.awt.*;
import java.awt.event.InputEvent;
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
            } else
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
        frame.setSize(1152, 864);
        frame.setLocation(0, 0);
        //frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        mBrowser.addLoadListener(new LoadAdapter()
        {
            @Override
            public void onFinishLoadingFrame(FinishLoadingEvent event)
            {
                // A click után újra bejövök ide, erre ügyelni kell!!!!
                if (event.isMainFrame())
                {

                    DOMElement elementTextSource = null;
                    do
                    {
                        elementTextSource = mBrowser.getDocument().findElement(By.name("departureAirportName"));
                        if (elementTextSource == null)
                        {
                            Sleep(1000);
                        }
                    }
                    while (elementTextSource == null);

                    TravelData_INPUT lTravelDataInput = null;
                    if (getBrowserState().toString().equals("BrowserStateSearching"))
                    {
                        lTravelDataInput = ((BrowserStateSearching) getBrowserState()).getTravelDataInput();
                    }

                    DOMDocument lDOMDocument = mBrowser.getDocument();
                    if (lTravelDataInput == null)
                    {
                        new BrowserStateReadyToSearch(lDOMDocument).doAction(getBrowserState().getWebPageGuest());
                    } else
                    {
                        new BrowserStateSearchingFinished(lDOMDocument, lTravelDataInput).doAction(
                                getBrowserState().getWebPageGuest());
                    }
                    System.out.println("addLoadListener()");
                }
            }
        });

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

    private void CollectDatas(DOMDocument document, TravelData_INPUT aTravelDataInput)
    {
        // flight out date
        // <div class="slide ng-scope active" data-index="10" ng-class="{ 'active': activePane == (item.index || $index) }" ng-repeat="item in panes" ng-include="itemTemplate" ng-click="onCarouselItemSelect(item, (item.index || $index))" style="transform: translate(1600px, 0px) translateZ(0px);"><div class="carousel-item daily ng-scope" ng-class="{'item-not-available' : item.isNotAvailable, 'item-sold-out' : item.isSoldOut}"><div class="date ng-binding">Mon 2 May</div><div ng-hide="item.isSoldOut || item.isNotAvailable" class="fare ng-binding">€&nbsp;42.99</div><core-icon ng-show="item.isSoldOut" icon-id="empty-state-seat" class="ng-isolate-scope ng-hide"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#empty-state-seat" ng-href="/gb/en/booking/home#empty-state-seat"></use></svg></div></core-icon><core-icon ng-show="item.isNotAvailable" icon-id="empty-state-flight" class="ng-isolate-scope ng-hide"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#empty-state-flight" ng-href="/gb/en/booking/home#empty-state-flight"></use></svg></div></core-icon></div></div>
        // standard fare
        // <div class="fare" ng-click="(flight.selectionDisabled || disabledFareType === 'regular') || onFlightSelected(flight.regularFlightFareKey, 'regular', flight)" ng-class="{'selected': selectedFlight == flight.regularFlightFareKey &amp;&amp; flight.fare !== null, 'no-fares': flight.fare === null, 'disabled': disabledFareType == 'regular', 'promo': flight.fare.ADT.hasDiscount &amp;&amp; flight.fare.ADT.publishedFare !== flight.fare.ADT.amount}"><del class="published-fare ng-binding ng-hide" ng-hide="!flight.fare.ADT.hasDiscount || flight.fare.ADT.publishedFare === flight.fare.ADT.amount">€&nbsp;206.99</del><span class="price ng-binding" ng-hide="!flight.fare">€&nbsp;206.99</span><div class="icon circle blue outbound arrow-right no-seat ng-hide" ng-hide="flight.faresLeft !== 0"><core-icon icon-id="glyphs.empty-state-seat" class="ng-isolate-scope"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#glyphs.empty-state-seat" ng-href="/gb/en/booking/home#glyphs.empty-state-seat"></use></svg></div></core-icon></div><span class="sold-out ng-scope ng-hide" ng-hide="flight.faresLeft !== 0" translate="trips.flight_list_table.soldout" translate-default="">Sold out</span> <span class="standard-fare ng-scope ng-hide" ng-hide="flight.faresLeft < 1" translate="trips.flight_list_table.seats-left" translate-values="{number: flight.faresLeft}" translate-default="">-1 seats remaining at this price</span> <span class="standard-fare" ng-hide="flight.faresLeft >= 1"></span></div>
        // business plus fare

        // flight back date
        // <div class="slide ng-scope active" data-index="10" ng-class="{ 'active': activePane == (item.index || $index) }" ng-repeat="item in panes" ng-include="itemTemplate" ng-click="onCarouselItemSelect(item, (item.index || $index))" style="transform: translate(1600px, 0px) translateZ(0px);"><div class="carousel-item daily ng-scope" ng-class="{'item-not-available' : item.isNotAvailable, 'item-sold-out' : item.isSoldOut}"><div class="date ng-binding">Mon 2 May</div><div ng-hide="item.isSoldOut || item.isNotAvailable" class="fare ng-binding">€&nbsp;42.99</div><core-icon ng-show="item.isSoldOut" icon-id="empty-state-seat" class="ng-isolate-scope ng-hide"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#empty-state-seat" ng-href="/gb/en/booking/home#empty-state-seat"></use></svg></div></core-icon><core-icon ng-show="item.isNotAvailable" icon-id="empty-state-flight" class="ng-isolate-scope ng-hide"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#empty-state-flight" ng-href="/gb/en/booking/home#empty-state-flight"></use></svg></div></core-icon></div></div>
        // flight back standard fare
        // <div class="fare" ng-click="(flight.selectionDisabled || disabledFareType === 'regular') || onFlightSelected(flight.regularFlightFareKey, 'regular', flight)" ng-class="{'selected': selectedFlight == flight.regularFlightFareKey &amp;&amp; flight.fare !== null, 'no-fares': flight.fare === null, 'disabled': disabledFareType == 'regular', 'promo': flight.fare.ADT.hasDiscount &amp;&amp; flight.fare.ADT.publishedFare !== flight.fare.ADT.amount}"><del class="published-fare ng-binding ng-hide" ng-hide="!flight.fare.ADT.hasDiscount || flight.fare.ADT.publishedFare === flight.fare.ADT.amount">€&nbsp;42.99</del><span class="price ng-binding" ng-hide="!flight.fare">€&nbsp;42.99</span><div class="icon circle blue outbound arrow-right no-seat ng-hide" ng-hide="flight.faresLeft !== 0"><core-icon icon-id="glyphs.empty-state-seat" class="ng-isolate-scope"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#glyphs.empty-state-seat" ng-href="/gb/en/booking/home#glyphs.empty-state-seat"></use></svg></div></core-icon></div><span class="sold-out ng-scope ng-hide" ng-hide="flight.faresLeft !== 0" translate="trips.flight_list_table.soldout" translate-default="">Sold out</span> <span class="standard-fare ng-scope" ng-hide="flight.faresLeft < 1" translate="trips.flight_list_table.seats-left" translate-values="{number: flight.faresLeft}" translate-default="">2 seats remaining at this price</span> <span class="standard-fare ng-hide" ng-hide="flight.faresLeft >= 1"></span></div>
        // flight back business plus fare
        // <div class="fare promo" ng-click="(flight.selectionDisabled || disabledFareType === 'business') || onFlightSelected(flight.businessFlightFareKey, 'business', flight)" ng-class="{'selected': selectedFlight == flight.businessFlightFareKey &amp;&amp; flight.businessFare !== null, 'no-fares': flight.fare === null, 'disabled': disabledFareType == 'business', 'promo': flight.businessFare.ADT.hasDiscount &amp;&amp; flight.businessFare.ADT.publishedFare !== flight.businessFare.ADT.amount}"><del class="published-fare ng-binding" ng-hide="!flight.businessFare.ADT.hasDiscount || flight.businessFare.ADT.publishedFare === flight.businessFare.ADT.amount">€&nbsp;94.99</del><span class="price ng-binding" ng-hide="!flight.businessFare">€&nbsp;74.99</span><div class="icon circle blue outbound arrow-right no-seat ng-hide" ng-hide="flight.faresLeft !== 0"><core-icon icon-id="glyphs.empty-state-seat" class="ng-isolate-scope"><div><svg tabindex="-1" focusable="false" role="img"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/gb/en/booking/home#glyphs.empty-state-seat" ng-href="/gb/en/booking/home#glyphs.empty-state-seat"></use></svg></div></core-icon></div><span class="sold-out ng-scope ng-hide" ng-hide="flight.faresLeft !== 0" translate="trips.flight_list_table.soldout" translate-default="">Sold out</span> <span class="business-fare" ng-hide="flight.faresLeft === 0"></span></div>
    }

    private void FillTheForm(DOMDocument aDOMDocument, TravelData_INPUT aTravelDataInput)
    {
        String lAirportLabel  = "Budapest";
        String lAirportLabel2 = "Brussels (CRL)";

        mRobot.delay(1000);
        // click into the leaving from field
        mRobot.mouseMove(175, 460);
        mRobot.mousePress(InputEvent.BUTTON1_MASK);
        mRobot.mouseRelease(InputEvent.BUTTON1_MASK);

        // fill the leaving from field
        PressCtrlA();
        PressDelete();
        TypeText("Budapest\t");

        mRobot.delay(500);

        // click into the going to field
        mRobot.mouseMove(500, 460);
        mRobot.mousePress(InputEvent.BUTTON1_MASK);
        mRobot.mouseRelease(InputEvent.BUTTON1_MASK);

        // fill the going to field
        PressCtrlA();
        PressDelete();
        TypeText("Brussels (CRL)\n");

        mRobot.delay(1000);

        // fill departure day field
        PressCtrlA();
        PressBackspace();
        TypeText("1");

        // go to the departure month field
        mRobot.delay(500);
        TypeText("\t");
        mRobot.delay(500);

        // fill departure month field
        PressBackspace();
        PressBackspace();
        TypeText("7");

        // go to the departure year field
        mRobot.delay(500);
        TypeText("\t");
        mRobot.delay(500);

        // fill departure year
        PressBackspace();
        PressBackspace();
        PressBackspace();
        PressBackspace();
        TypeText("2016");

        // go to the return day field
        mRobot.delay(500);
        TypeText("\t");
        mRobot.delay(500);

        // fill the return day field
        PressCtrlA();
        PressBackspace();
        TypeText("3");

        // go to the return month field
        mRobot.delay(500);
        TypeText("\t");
        mRobot.delay(500);

        // fill the return month field
        PressBackspace();
        PressBackspace();
        TypeText("7");

        // go to the return year field
        mRobot.delay(500);
        TypeText("\t");
        mRobot.delay(500);

        // fill the return year field
        PressBackspace();
        PressBackspace();
        PressBackspace();
        PressBackspace();
        TypeText("2016");

        // passengers
        // one way / return ticket
    }

    private void ClickTheSearchButton(DOMDocument aDOMDocument)
    {
        String lSleep = Util.Configuration.getInstance().getValue("/configuration/global/DelayBeforeClick", "3");
        Sleep(1000 * Integer.parseInt(lSleep));

        // click the Let's go (search) button
        mRobot.mouseMove(834, 513);
        mRobot.mousePress(InputEvent.BUTTON1_MASK);
        mRobot.mouseRelease(InputEvent.BUTTON1_MASK);
    }

    public void run()
    {
        try
        {
            System.out.println("Thread::run");

            mThreadStopped = false;
            while (!mThreadStopped)
            {
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
                    //new BrowserStateReadyToSearch(lDOMDocument).doAction(this);
                } else
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
                        //ClickTheSearchButton( lDOMDocument );
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
