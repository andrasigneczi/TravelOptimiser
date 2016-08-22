package PageGuest;

import QueueHandlers.JMSStack;
import QueueHandlers.LocalStack;
import QueueHandlers.ResultQueue;
import QueueHandlers.StackIF;
import Util.Configuration;
import Util.DatetimeHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URI;
import java.net.URISyntaxException;
import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

import static Util.CurrencyHelper.ConvertFrom3Digits;

/**
 * Created by Andras on 15/03/2016.
 */
public class RyanAirPageGuest extends PageGuest implements Runnable
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(RyanAirPageGuest.class);

    private boolean mThreadStopped = true;
    private long mTimeoutStart;

    public RyanAirPageGuest()
    {
        super("ryanair");
        mSearchQueue = new LocalStack<>();
        mThread = new Thread(this);
        mThread.setName("RyanAirThread " + LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        mThread.start();
        System.out.println("RyanAirPageGuest()");
    }

    public void DoSearch(String aFrom, String aTo, String aDepartureDate, String aReturnDate)
    {
        mLogger.trace( "begin, thread name: " + getThreadName());
        DateValidity lValidity = ValidateDate(aDepartureDate, aReturnDate);

        if( lValidity == DateValidity.INVALID_COMBINATION )
        {
            mLogger.warn("DoSearch: the departure date (" + aDepartureDate + ") and/or the return date " +
                                 aReturnDate + " invalid!");
            return;
        }

        TravelData_INPUT lTravelDataInput = new TravelData_INPUT();
        lTravelDataInput.mAirline = getAirline();
        lTravelDataInput.mAdultNumber = "1";
        lTravelDataInput.mChildNumber = "0";
        lTravelDataInput.mInfantNumber = "0";

        if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
        {
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

    public void DoSearchFromConfig()
    {
        synchronized (mMutex)
        {
            ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchList();
            for (TravelData_INPUT lTDI : lSearchList)
            {
                if (!lTDI.mAirline.equals(getAirline()))
                    continue;

                DateValidity lValidity = ValidateDate(lTDI.mDepartureDay, lTDI.mReturnDay);

                if( lValidity == DateValidity.INVALID_COMBINATION )
                {
                    mLogger.warn("DoSearch: the departure date (" + lTDI.mDepartureDay + ") and/or the return date " +
                            lTDI.mReturnDay + " invalid!");
                    continue;
                }

                if( lValidity == DateValidity.ONLY_THE_RETURN_DATE_VALID )
                {
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
            mSearchQueue = new JMSStack<TravelData_INPUT>();
            mSearchQueue.setQueueName( getAirline() );
        }
        mLogger.trace( "end, thread name: " + getThreadName());
    }

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

    private void ConvertToWizzairFormatAndStore( TravelData_RESULT.TravelData_PossibleTrip aTrip )
    {
        aTrip.mArrivalDatetime = DatetimeHelper.ConvertFromRyanairJSONStoredFormat(aTrip.mArrivalDatetime);
        aTrip.mDepartureDatetime = DatetimeHelper.ConvertFromRyanairJSONStoredFormat(aTrip.mDepartureDatetime);
        mTravelDataResult.mTrips.add(aTrip);
    }

    private static void ParseFares( JSONObject aFares, FareType aFareType,
                                      TravelData_RESULT.TravelData_PossibleTrip aTripClone,
                                      String aCurrency)
    {
        JSONArray lFares = aFares.getJSONArray( "fares" );
        for( int lFareIndex = 0; lFareIndex < lFares.length(); lFareIndex++ )
        {
            JSONObject lFare = lFares.getJSONObject(lFareIndex);
            double lAmount = lFare.getDouble( "amount" );
            double lPublishedFare = lFare.getDouble( "publishedFare" );
            boolean lHasDiccount = lFare.getBoolean( "hasDiscount" );
            if( aFareType == FareType.Normal )
            {
                if( lHasDiccount )
                    aTripClone.mPrices_BasicFare_Discount = String.valueOf( lAmount ) + " " + aCurrency;
                else
                    aTripClone.mPrices_BasicFare_Normal = String.valueOf( lPublishedFare ) + " " + aCurrency;
            }
            else
            {
                if( lHasDiccount )
                    aTripClone.mPrices_PlusFare_Discount = String.valueOf( lAmount ) + " " + aCurrency;
                else
                    aTripClone.mPrices_PlusFare_Normal = String.valueOf( lPublishedFare ) + " " + aCurrency;
            }
        }
    }

    private void ParseTrip( JSONObject aTrip, String aCurrency )
    {
        TravelData_RESULT.TravelData_PossibleTrip lTDRTrip = new TravelData_RESULT.TravelData_PossibleTrip();
        lTDRTrip.mOutboundTrip = true;

        String lOrigin = aTrip.getString( "origin" );
        String lDestination = aTrip.getString( "destination" );

        if( lOrigin.equals( mTravelDataResult.mAirportCode_GoingTo ))
        {
            lTDRTrip.mOutboundTrip = false;
        }

        JSONArray lDates = aTrip.getJSONArray( "dates" );
        for( int lDateIndex = 0; lDateIndex < lDates.length(); lDateIndex++ )
        {
            JSONObject lDate = lDates.getJSONObject( lDateIndex );
            // the time caontains the date below
            //String lDateOut = lDate.getString( "dateOut" );
            //lTDRTrip.mDepartureDatetime = lDateOut;
            //lTDRTrip.mArrivalDatetime   = lDateOut;

            JSONArray lFlights = lDate.getJSONArray( "flights" );
            for( int lFlightIndex = 0; lFlightIndex < lFlights.length(); lFlightIndex++ )
            {
                TravelData_RESULT.TravelData_PossibleTrip lTripClone = (TravelData_RESULT.TravelData_PossibleTrip)lTDRTrip.clone();

                JSONObject lFlight = lFlights.getJSONObject( lFlightIndex );
                JSONArray lTime = lFlight.getJSONArray( "time" );
                lTripClone.mDepartureDatetime = lTime.getString( 0 );
                lTripClone.mArrivalDatetime   = lTime.getString( 1 );

                JSONObject lRegularFare  = lFlight.getJSONObject( "regularFare" );
                JSONObject lBusinessFare = lFlight.getJSONObject( "businessFare" );

                ParseFares( lRegularFare, FareType.Normal, lTripClone, aCurrency );
                ParseFares( lBusinessFare, FareType.Business, lTripClone, aCurrency );
                ConvertToWizzairFormatAndStore( lTripClone );
            }
        }
    }

    private String FormatDate( String aDate )
    {
        String[] lParts = aDate.split("\\.", 0 );
        return String.format( "%s-%s-%s", lParts[ 0 ], lParts[ 1 ], lParts[ 2 ] );
    }

    private void FillTheForm( TravelData_INPUT aTravelDataInput ) throws URISyntaxException, IOException
    {
        //String lUrl = "https://desktopapps.ryanair.com/en-gb/availability?ADT=1&CHD=0&DateIn=2016-07-31&" +
        //        "DateOut=2017-01-04&Destination=FAO&FlexDaysIn=6&FlexDaysOut=6&INF=0&Origin=DUB&RoundTrip=true&TEEN=0";
        String lUrl = "https://desktopapps.ryanair.com/en-gb/availability?ADT="
                + aTravelDataInput.mAdultNumber
                + "&CHD=" + aTravelDataInput.mChildNumber
                + "&DateIn=" + FormatDate( aTravelDataInput.mReturnDay )
                + "&DateOut=" + FormatDate( aTravelDataInput.mDepartureDay )
                + "&Destination=" + aTravelDataInput.mAirportCode_GoingTo
                + "&FlexDaysIn=6&FlexDaysOut=6&INF=" + aTravelDataInput.mInfantNumber
                + "&Origin=" + aTravelDataInput.mAirportCode_LeavingFrom
                + "&RoundTrip=" + ( aTravelDataInput.mReturnTicket ? "true" : "false" )
                + "&TEEN=0";

//        String lTestJsonString = "\n" +
  //              "{\"currency\":\"EUR\",\"currPrecision\":2,\"trips\":[{\"origin\":\"DUB\",\"destination\":\"FAO\",\"dates\":[{\"dateOut\":\"2017-01-04T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-04T17:25:00.000\",\"2017-01-04T20:25:00.000\"],\"timeUTC\":[\"2017-01-04T17:25:00.000Z\",\"2017-01-04T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/04/2017 17:25~FAO~01/04/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-05T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-05T06:25:00.000\",\"2017-01-05T09:25:00.000\"],\"timeUTC\":[\"2017-01-05T06:25:00.000Z\",\"2017-01-05T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/05/2017 06:25~FAO~01/05/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-06T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-06T17:25:00.000\",\"2017-01-06T20:25:00.000\"],\"timeUTC\":[\"2017-01-06T17:25:00.000Z\",\"2017-01-06T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/06/2017 17:25~FAO~01/06/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-07T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-07T06:25:00.000\",\"2017-01-07T09:25:00.000\"],\"timeUTC\":[\"2017-01-07T06:25:00.000Z\",\"2017-01-07T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/07/2017 06:25~FAO~01/07/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-08T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-08T17:25:00.000\",\"2017-01-08T20:25:00.000\"],\"timeUTC\":[\"2017-01-08T17:25:00.000Z\",\"2017-01-08T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/08/2017 17:25~FAO~01/08/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-09T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-09T17:25:00.000\",\"2017-01-09T20:25:00.000\"],\"timeUTC\":[\"2017-01-09T17:25:00.000Z\",\"2017-01-09T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/09/2017 17:25~FAO~01/09/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-10T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-10T06:25:00.000\",\"2017-01-10T09:25:00.000\"],\"timeUTC\":[\"2017-01-10T06:25:00.000Z\",\"2017-01-10T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/10/2017 06:25~FAO~01/10/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]}]},{\"origin\":\"FAO\",\"destination\":\"DUB\",\"dates\":[{\"dateOut\":\"2016-07-31T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7031\",\"time\":[\"2016-07-31T06:45:00.000\",\"2016-07-31T09:40:00.000\"],\"timeUTC\":[\"2016-07-31T05:45:00.000Z\",\"2016-07-31T08:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7031~ ~~FAO~07/31/2016 06:45~DUB~07/31/2016 09:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~K~~K14HIGH~BO14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":133.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":133.9900}]},\"businessFare\":{\"fareKey\":\"0~K~~K14HBUS~BS14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":219.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":219.9900}]}},{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-07-31T09:45:00.000\",\"2016-07-31T12:40:00.000\"],\"timeUTC\":[\"2016-07-31T08:45:00.000Z\",\"2016-07-31T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":5,\"flightKey\":\"FR~7035~ ~~FAO~07/31/2016 09:45~DUB~07/31/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~K~~K14HIGH~BO14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":133.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":133.9900}]},\"businessFare\":{\"fareKey\":\"0~K~~K14HBUS~BS14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":219.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":219.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-07-31T16:55:00.000\",\"2016-07-31T19:50:00.000\"],\"timeUTC\":[\"2016-07-31T15:55:00.000Z\",\"2016-07-31T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7033~ ~~FAO~07/31/2016 16:55~DUB~07/31/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-01T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-01T09:45:00.000\",\"2016-08-01T12:40:00.000\"],\"timeUTC\":[\"2016-08-01T08:45:00.000Z\",\"2016-08-01T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/01/2016 09:45~DUB~08/01/2016 12:40~\",\"infantsLeft\":15,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-01T16:55:00.000\",\"2016-08-01T19:50:00.000\"],\"timeUTC\":[\"2016-08-01T15:55:00.000Z\",\"2016-08-01T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":2,\"flightKey\":\"FR~7033~ ~~FAO~08/01/2016 16:55~DUB~08/01/2016 19:50~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~B~~B14HIGH~BO14~~1~X\",\"fareClass\":\"B\",\"fares\":[{\"type\":\"ADT\",\"amount\":240.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":240.9900}]},\"businessFare\":{\"fareKey\":\"0~B~~B14HBUS~BS14~~1~X\",\"fareClass\":\"B\",\"fares\":[{\"type\":\"ADT\",\"amount\":334.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":334.9900}]}}]},{\"dateOut\":\"2016-08-02T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-02T09:45:00.000\",\"2016-08-02T12:40:00.000\"],\"timeUTC\":[\"2016-08-02T08:45:00.000Z\",\"2016-08-02T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/02/2016 09:45~DUB~08/02/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-02T16:55:00.000\",\"2016-08-02T19:50:00.000\"],\"timeUTC\":[\"2016-08-02T15:55:00.000Z\",\"2016-08-02T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":4,\"flightKey\":\"FR~7033~ ~~FAO~08/02/2016 16:55~DUB~08/02/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-03T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-03T09:45:00.000\",\"2016-08-03T12:40:00.000\"],\"timeUTC\":[\"2016-08-03T08:45:00.000Z\",\"2016-08-03T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/03/2016 09:45~DUB~08/03/2016 12:40~\",\"infantsLeft\":15,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-03T16:55:00.000\",\"2016-08-03T19:50:00.000\"],\"timeUTC\":[\"2016-08-03T15:55:00.000Z\",\"2016-08-03T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7033~ ~~FAO~08/03/2016 16:55~DUB~08/03/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}}]},{\"dateOut\":\"2016-08-04T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-04T09:45:00.000\",\"2016-08-04T12:40:00.000\"],\"timeUTC\":[\"2016-08-04T08:45:00.000Z\",\"2016-08-04T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7035~ ~~FAO~08/04/2016 09:45~DUB~08/04/2016 12:40~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-04T16:55:00.000\",\"2016-08-04T19:50:00.000\"],\"timeUTC\":[\"2016-08-04T15:55:00.000Z\",\"2016-08-04T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":3,\"flightKey\":\"FR~7033~ ~~FAO~08/04/2016 16:55~DUB~08/04/2016 19:50~\",\"infantsLeft\":14,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-05T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-05T09:45:00.000\",\"2016-08-05T12:40:00.000\"],\"timeUTC\":[\"2016-08-05T08:45:00.000Z\",\"2016-08-05T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/05/2016 09:45~DUB~08/05/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-05T16:55:00.000\",\"2016-08-05T19:50:00.000\"],\"timeUTC\":[\"2016-08-05T15:55:00.000Z\",\"2016-08-05T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7033~ ~~FAO~08/05/2016 16:55~DUB~08/05/2016 19:50~\",\"infantsLeft\":12,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-06T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7031\",\"time\":[\"2016-08-06T06:25:00.000\",\"2016-08-06T09:20:00.000\"],\"timeUTC\":[\"2016-08-06T05:25:00.000Z\",\"2016-08-06T08:20:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":5,\"flightKey\":\"FR~7031~ ~~FAO~08/06/2016 06:25~DUB~08/06/2016 09:20~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-06T09:45:00.000\",\"2016-08-06T12:40:00.000\"],\"timeUTC\":[\"2016-08-06T08:45:00.000Z\",\"2016-08-06T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7035~ ~~FAO~08/06/2016 09:45~DUB~08/06/2016 12:40~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-06T16:55:00.000\",\"2016-08-06T19:50:00.000\"],\"timeUTC\":[\"2016-08-06T15:55:00.000Z\",\"2016-08-06T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":3,\"flightKey\":\"FR~7033~ ~~FAO~08/06/2016 16:55~DUB~08/06/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}}]}]}],\"serverTimeUTC\":\"2016-05-13T13:37:25.500Z\"}";

        URI lURI = null;
        JSONTokener lTokener = null;
		lURI = new URI( lUrl );
		lTokener = new JSONTokener( lURI.toURL().openStream());
        //lTokener = new JSONTokener(new ByteArrayInputStream( lTestJsonString.getBytes() ));
        JSONObject root = new JSONObject( lTokener );
        String lCurrency = ConvertFrom3Digits( root.getString( "currency" ));
        JSONArray lTrips = root.getJSONArray( "trips" );

        mTravelDataResult = new TravelData_RESULT();
        mTravelDataResult.mAirline = aTravelDataInput.mAirline;
        mTravelDataResult.mAirportCode_GoingTo = aTravelDataInput.mAirportCode_GoingTo;
        mTravelDataResult.mAirportCode_LeavingFrom = aTravelDataInput.mAirportCode_LeavingFrom;
        mTravelDataResult.mTravelDataInput = aTravelDataInput;

        for( int lTripIndex = 0; lTripIndex < lTrips.length(); lTripIndex++ )
        {
            ParseTrip( lTrips.getJSONObject( lTripIndex ), lCurrency );
        }
        ResultQueue.getInstance().push( mTravelDataResult );
    }

    private void TimeoutTest()
    {
        Sleep( 100 );
        if( Duration.ofMillis( System.currentTimeMillis() - mTimeoutStart ).getSeconds() > 60 )
            mThreadStopped = true;
    }

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
                    lTravelDataInput = mSearchQueue.pop();
                }

                try
                {
                    FillTheForm( lTravelDataInput );
                }
                catch( URISyntaxException e )
                {
                }
                catch( IOException e )
                {

                }

                String lSleep = Util.Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
                Sleep( 1000 * Integer.parseInt( lSleep ));
                mTimeoutStart = System.currentTimeMillis();
            }
            System.out.println("run()");
        }
        catch (Exception e)
        {
            mLogger.error( "Exception in Ryanair.run: " + StringHelper.getTraceInformation( e ) );
        }
    }

    public void WaitForFinish()
    {
        mLogger.trace( "begin, thread name: " + getThreadName());
        try
        {
            mThread.join();
        }
        catch( InterruptedException e )
        {
            mLogger.error( StringHelper.getTraceInformation( e ));
        }
        mLogger.trace( "end, thread name: " + getThreadName());
    }
}
