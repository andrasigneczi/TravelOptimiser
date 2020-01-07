package PageGuest;

import QueueHandlers.ResultQueue;
import org.openqa.selenium.*;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.chrome.ChromeDriver;

import QueueHandlers.JMSStack;
import QueueHandlers.LocalStack;
import Configuration.Configuration;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

import static Util.CurrencyHelper.ConvertFromPrefixFormat;
import static Util.DatetimeHelper.FormatDate;

import java.util.List;
import java.util.concurrent.TimeUnit;

// flight
// https://wizzair.com/#/booking/select-flight/BUD/CRL/2020-03-07/null/1/0/0/0/null

// timetable
// https://wizzair.com/en-gb/flights/timetable/budapest/brussels-charleroi#/0/1/1/0/0/2020-02-04/2020-03-04

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class WizzAirPageGuest202001 extends WebPageGuest implements Runnable {
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(WizzAirPageGuest202001.class);
    WebDriver driver;
    private Integer mEventCounter = 0;
    private long mTimeoutStart;

    public WizzAirPageGuest202001() {
        super("wizzair", "https://wizzair.com");
        mSearchQueue = new LocalStack<>();
        mThread = new Thread(this);
        mThread.setName("WizzAirThread202001 " + LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        mThread.start();
    }

    public void Init() throws Exception {
        InitJMS();

        /*
        ChromeOptions options = new ChromeOptions();
        options.addArguments("--proxy-server='direct://'");
        options.addArguments("--proxy-bypass-list=*");
        driver = new ChromeDriver(options);
         */
        System.setProperty("webdriver.gecko.driver", "/usr/bin/geckodriver");
        driver = new FirefoxDriver();
        driver.manage().timeouts().implicitlyWait(60, TimeUnit.SECONDS);
        DoSearchFromConfig();
        synchronized (mMutex) { ++mEventCounter; }
    }

    @Override
    public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate)
    {
        mLogger.trace( "begin, thread name: " + getThreadName());
        DateValidity lValidity = ValidateDate(aDepartureDate, aReturnDate);

        if( lValidity == DateValidity.INVALID_COMBINATION )
        {
            mLogger.warn( "DoSearch: the departure date (" + aDepartureDate + ") and/or the return date " +
                    aReturnDate + " is/are invalid!" );
            return;
        }

        TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
        lTravelDataInput.mAirline = getAirline();
        lTravelDataInput.mAdultNumber = "1";
        lTravelDataInput.mChildNumber = "0";
        lTravelDataInput.mInfantNumber = "0";

        if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
        {
            mLogger.warn(" DoSearch: the departure date (" + aDepartureDate + ") is invalid!" );

            // we will use only the return date
            lTravelDataInput.mAirportCode_LeavingFrom = aTo;
            lTravelDataInput.mAirportCode_GoingTo = aFrom;
            lTravelDataInput.mDepartureDay = aReturnDate;
            lTravelDataInput.mReturnDay = "";
            lTravelDataInput.mReturnTicket = false;
        }
        else if( lValidity == DateValidity.BOTH_OF_THEM_VALID )
        {
            lTravelDataInput.mAirportCode_LeavingFrom = aFrom;
            lTravelDataInput.mAirportCode_GoingTo = aTo;
            lTravelDataInput.mDepartureDay = aDepartureDate;
            lTravelDataInput.mReturnDay = aReturnDate;
            //lTravelDataInput.mNearbyAirports          = false;
            if (aReturnDate.length() == 0)
                lTravelDataInput.mReturnTicket = false;
            else
                lTravelDataInput.mReturnTicket = true;
        }

        synchronized (mMutex)
        {
            mSearchQueue.push(lTravelDataInput);
        }
        mLogger.trace( "end, thread name: " + getThreadName());
    }

    @Override
    public void DoSearchFromConfig()
    {
        synchronized (mMutex)
        {
            ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchListAirlines();
            for (TravelData_INPUT lTDI : lSearchList)
            {
                if (!lTDI.mAirline.equalsIgnoreCase(getAirline()))
                    continue;

                DateValidity lValidity = ValidateDate(lTDI.mDepartureDay, lTDI.mReturnDay);

                if( lValidity == DateValidity.INVALID_COMBINATION )
                {
                    mLogger.warn( "DoSearch: the departure date (" + lTDI.mDepartureDay + ") and/or the return date " +
                            lTDI.mReturnDay + " is/are invalid!" );
                    continue;
                }

                if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
                {
                    mLogger.warn(" DoSearch: the departure date (" + lTDI.mDepartureDay + ") is invalid!" );

                    // we will use only the return date
                    String lTemp = lTDI.mAirportCode_LeavingFrom;
                    lTDI.mAirportCode_LeavingFrom = lTDI.mAirportCode_GoingTo;
                    lTDI.mAirportCode_GoingTo = lTemp;
                    lTDI.mDepartureDay = lTDI.mReturnDay;
                    lTDI.mReturnDay = "";
                    lTDI.mReturnTicket = false;
                }
                else if( lValidity == DateValidity.BOTH_OF_THEM_VALID )
                {
                    if (lTDI.mReturnDay.length() == 0)
                        lTDI.mReturnTicket = false;
                    else
                        lTDI.mReturnTicket = true;
                }

                mSearchQueue.push(lTDI);
            }
        }
    }

    public void InitJMS()
    {
        mLogger.trace( "begin, thread name: " + getThreadName());
        synchronized (mMutex)
        {
            mSearchQueue = new JMSStack<>();
            mSearchQueue.setQueueName( getAirline() );
        }
        mLogger.trace( "end, thread name: " + getThreadName());
    }

    private void TimeoutTest()
    {
        Sleep( 100 );
        if( Duration.ofMillis( System.currentTimeMillis() - mTimeoutStart ).getSeconds() > 60 )
            mThreadStopped = true;
    }

    @Override
    public void run()
    {
        try
        {
            System.out.println("Thread::run");

            mThreadStopped = false;
            mTimeoutStart = System.currentTimeMillis();
            while (!mThreadStopped)
            {
                int lSearQueueSize;
                synchronized (mMutex)
                {
                    if(mEventCounter < 1)
                        continue;

                    lSearQueueSize = mSearchQueue.isEmpty();
                }

                if ( lSearQueueSize == 0 )
                {
                    TimeoutTest();
                    continue;
                }

                TravelData_INPUT lTravelDataInput = null;
                synchronized (mMutex)
                {
                    lTravelDataInput = (TravelData_INPUT) mSearchQueue.pop();
                }

                try
                {
                    FillTheForm( lTravelDataInput );
                }
                catch( IllegalStateException e )
                {
                    mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
                }

                String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
                Sleep( 1000 * Integer.parseInt( lSleep ));
                mTimeoutStart = System.currentTimeMillis();
            }
            System.out.println("run()");
        }
        catch (Exception e)
        {
            mLogger.error( "Exception in WizzAir.run: " + StringHelper.getTraceInformation( e ) );
        }
        driver.quit();
    }

    private void ParseResult(String departureDay) {
        // reading the departure and arrival hours
        List<WebElement> hours = driver.findElements(By.className("hour"));
        List<WebElement> discoutFares = driver.findElements(By.className("fare-type-button__title"));

        TravelData_RESULT.TravelData_PossibleTrip lTDRTrip = new TravelData_RESULT.TravelData_PossibleTrip();
        //lTDRTrip.mOutboundTrip = aOutbound;
        lTDRTrip.mOutboundTrip = true;

        for(int i = 0; i < discoutFares.size() && 2 * i + 1 < hours.size(); ++i) {
            WebElement fareElement = discoutFares.get(i).findElement(By.tagName("SPAN"));
            String hour1 = hours.get(2 * i).getText().trim();
            String hour2 = hours.get(2 * i + 1).getText().trim();
            String fare = ConvertFromPrefixFormat(fareElement.getText()).replace(",", "");

            TravelData_RESULT.TravelData_PossibleTrip lTripClone = (TravelData_RESULT.TravelData_PossibleTrip)lTDRTrip.clone();
            lTripClone.mDepartureDatetime = departureDay + "T" + hour1 + ":00";
            lTripClone.mArrivalDatetime   = departureDay + "T" + hour2 + ":00";
            lTripClone.mPrices_BasicFare_Discount = fare;
            //lTripClone.mPrices_BasicFare_Normal = "59.99" + " " + "Ft";
            mTravelDataResult.mTrips.add( lTripClone );
            mLogger.trace( "WizzAir result mDepartureDatetime: " + lTripClone.mDepartureDatetime );
            mLogger.trace( "WizzAir result mArrivalDatetime: " + lTripClone.mArrivalDatetime );
            mLogger.trace( "WizzAir result mPrices_BasicFare_Discount: " + lTripClone.mPrices_BasicFare_Discount );
        }
    }
    private void FillTheForm( TravelData_INPUT aTravelDataInput ) {
        mLogger.trace( "begin, thread name: " + getThreadName());
        // https://wizzair.com/#/booking/select-flight/BUD/CRL/2020-03-07/null/1/0/0/0/null
        if( aTravelDataInput.mReturnTicket ) {

        } else {
            String url = "https://wizzair.com/#/booking/select-flight/{FROM}/{TO}/{DEPARTURE_DAY}/null/1/0/0/0/null";
            url = url.replace("{FROM}", aTravelDataInput.mAirportCode_LeavingFrom);
            url = url.replace("{TO}", aTravelDataInput.mAirportCode_GoingTo);
            url = url.replace("{DEPARTURE_DAY}", FormatDate( aTravelDataInput.mDepartureDay));
            mLogger.trace("WizzAir URL: '" + url + "'");
            driver.get(url);
            mTravelDataResult = new TravelData_RESULT();
            mTravelDataResult.mAirline = aTravelDataInput.mAirline;
            mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
            mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
            mTravelDataResult.mTravelDataInput = aTravelDataInput;
            ParseResult(FormatDate( aTravelDataInput.mDepartureDay));
            ResultQueue.getInstance().push( mTravelDataResult );
            mTravelDataResult = null;

            // aTravelDataInput.mAdultNumber
            // aTravelDataInput.mChildNumber
            // aTravelDataInput.mInfantNumber
        }

        mLogger.trace( "end, thread name: " + getThreadName());
    }
}
