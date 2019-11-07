package PageGuest;

import QueueHandlers.JMSStack;
import QueueHandlers.LocalStack;
import QueueHandlers.ResultQueue;
import Configuration.Configuration;
import Util.DCHttpClient;
import Util.DatetimeHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static Util.CurrencyHelper.ConvertFrom3Digits;
import static Util.DatetimeHelper.FormatDate;

/**
 * Created by Andras on 15/03/2016.
 *
 * Airport aliases: https://www.ryanair.com/etc/designs/ryanair/frontend/resources/aem/station-config/aliases.json
 */
public class RyanAirPageGuest extends PageGuest implements Runnable
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger(RyanAirPageGuest.class);

    private long mTimeoutStart;
    private DCHttpClient dcHttpClient = new DCHttpClient();
    private static String mServerApiUrl = "https://desktopapps.ryanair.com/v4";

    public RyanAirPageGuest()
    {
        super("ryanair");
        mSearchQueue = new LocalStack<>();
        mThread = new Thread(this);
        mThread.setName("RyanAirThread " + LocalDateTime.now().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME));
        InitHttpRequest();
        mThread.start();
        System.out.println("RyanAirPageGuest()");
    }

    private void InitHttpRequest()
    {
        dcHttpClient.addProperties( "Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8" );
        //dcHttpClient.addProperties( "Host", "desktopapps.ryanair.com" );
        //Connection-specific header fields such as Connection must not be used with HTTP/2.
        //dcHttpClient.addProperties( "Connection", "keep-alive" );
        dcHttpClient.addProperties( "Upgrade-Insecure-Requests", "1" );
    }

    private void InitServerApiUrl( String response ) {
        Pattern reg = Pattern.compile( "window\\.SERVER_CFG_REZAPI = \"(.*?)\";" );
        Matcher m = reg.matcher( response );
        if( m.find() )
        {
            String lServerApiUrl = m.group(1).toString().trim();
            if(!lServerApiUrl.startsWith("https:")) lServerApiUrl = "https://www.ryanair.com" + lServerApiUrl;
            mServerApiUrl = lServerApiUrl.replaceAll( "\\\\", "" );
            mLogger.info( "RyanAir API Url: " + mServerApiUrl );
        }
    }

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

    public void DoSearchFromConfig()
    {
        synchronized (mMutex)
        {
            ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchListAirlines();
            for (TravelData_INPUT lTDI : lSearchList)
            {
                if (!lTDI.mAirline.equals(getAirline()))
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
                JSONObject lBusinessFare = null;
                try
                {
                    lBusinessFare = lFlight.getJSONObject( "businessFare" );
                }
                catch ( JSONException e)
                {
                    mLogger.info( "businessFare JSONObject not found: " + StringHelper.getTraceInformation( e ) );
                    mLogger.info(lFlight.toString());
                }

                ParseFares( lRegularFare, FareType.Normal, lTripClone, aCurrency );
                if( lBusinessFare != null )
                    ParseFares( lBusinessFare, FareType.Business, lTripClone, aCurrency );
                ConvertToWizzairFormatAndStore( lTripClone );
            }
        }
    }

    private void FillTheForm( TravelData_INPUT aTravelDataInput ) throws Exception
    {
        // https://desktopapps.ryanair.com/v4/en-ie/availability?ADT=1&CHD=0&DateOut=2018-02-07&Destination=BUD&FlexDaysOut=4&INF=0&IncludeConnectingFlights=true&Origin=EDI&RoundTrip=false&TEEN=0&ToUs=AGREED&exists=false&promoCode=
        String lUrl = mServerApiUrl + "/en-gb/availability?ADT="
                + aTravelDataInput.mAdultNumber
                + "&CHD=" + aTravelDataInput.mChildNumber
                + "&DateOut=" + FormatDate( aTravelDataInput.mDepartureDay );

        if( aTravelDataInput.mReturnTicket )
                lUrl += "&DateIn=" + FormatDate( aTravelDataInput.mReturnDay );

        lUrl += "&Destination=" + aTravelDataInput.mAirportCode_GoingTo
                + "&FlexDaysIn=6&FlexDaysOut=6&INF=" + aTravelDataInput.mInfantNumber
                + "&IncludeConnectingFlights=false"
                + "&Origin=" + aTravelDataInput.mAirportCode_LeavingFrom
                + "&RoundTrip=" + ( aTravelDataInput.mReturnTicket ? "true" : "false" )
                + "&TEEN=0&ToUs=AGREED&exists=false&promoCode=";

//        String lTestJsonString = "\n" +
// {"currency":"HUF","currPrecision":0,"trips":[{"origin":"BUD","originName":"Budapest T2B","destination":"AGP","destinationName":"Malaga T2","dates":[{"dateOut":"2017-06-22T00:00:00.000","flights":[]},{"dateOut":"2017-06-23T00:00:00.000","flights":[]},{"dateOut":"2017-06-24T00:00:00.000","flights":[{"faresLeft":2,"flightKey":"FR~2273~ ~~BUD~06/24/2017 16:45~AGP~06/24/2017 20:15~","infantsLeft":18,"regularFare":{"fareKey":"0~B~~B12HIGH~BO12~~1~X","fareClass":"B","fares":[{"type":"ADT","amount":68489.0000,"count":1,"hasDiscount":false,"publishedFare":68489.0000,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"BUD","destination":"AGP","flightNumber":"FR 2273","time":["2017-06-24T16:45:00.000","2017-06-24T20:15:00.000"],"timeUTC":["2017-06-24T14:45:00.000Z","2017-06-24T18:15:00.000Z"],"duration":"03:30"}],"flightNumber":"FR 2273","time":["2017-06-24T16:45:00.000","2017-06-24T20:15:00.000"],"timeUTC":["2017-06-24T14:45:00.000Z","2017-06-24T18:15:00.000Z"],"duration":"03:30"}]},{"dateOut":"2017-06-25T00:00:00.000","flights":[]},{"dateOut":"2017-06-26T00:00:00.000","flights":[]}]},{"origin":"AGP","originName":"Budapest T2B","destination":"BUD","destinationName":"Malaga T2","dates":[{"dateOut":"2017-07-27T00:00:00.000","flights":[]},{"dateOut":"2017-07-28T00:00:00.000","flights":[]},{"dateOut":"2017-07-29T00:00:00.000","flights":[{"faresLeft":4,"flightKey":"FR~2274~ ~~AGP~07/29/2017 20:50~BUD~07/30/2017 00:20~","infantsLeft":16,"regularFare":{"fareKey":"0~L~~L12HIGH~BO12~~1~X","fareClass":"L","fares":[{"type":"ADT","amount":50609.0000,"count":1,"hasDiscount":false,"publishedFare":50609.0000,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"BUD","flightNumber":"FR 2274","time":["2017-07-29T20:50:00.000","2017-07-30T00:20:00.000"],"timeUTC":["2017-07-29T18:50:00.000Z","2017-07-29T22:20:00.000Z"],"duration":"03:30"}],"flightNumber":"FR 2274","time":["2017-07-29T20:50:00.000","2017-07-30T00:20:00.000"],"timeUTC":["2017-07-29T18:50:00.000Z","2017-07-29T22:20:00.000Z"],"duration":"03:30"}]},{"dateOut":"2017-07-30T00:00:00.000","flights":[]},{"dateOut":"2017-07-31T00:00:00.000","flights":[]},{"dateOut":"2017-08-01T00:00:00.000","flights":[]},{"dateOut":"2017-08-02T00:00:00.000","flights":[{"faresLeft":-1,"flightKey":"FR~2274~ ~~AGP~08/02/2017 20:50~BUD~08/03/2017 00:20~","infantsLeft":16,"regularFare":{"fareKey":"0~V~~V12HIGH~BO12~~1~X","fareClass":"V","fares":[{"type":"ADT","amount":30609.0000,"count":1,"hasDiscount":false,"publishedFare":30609.0000,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"BUD","flightNumber":"FR 2274","time":["2017-08-02T20:50:00.000","2017-08-03T00:20:00.000"],"timeUTC":["2017-08-02T18:50:00.000Z","2017-08-02T22:20:00.000Z"],"duration":"03:30"}],"flightNumber":"FR 2274","time":["2017-08-02T20:50:00.000","2017-08-03T00:20:00.000"],"timeUTC":["2017-08-02T18:50:00.000Z","2017-08-02T22:20:00.000Z"],"duration":"03:30"}]}]}],"serverTimeUTC":"2017-06-11T08:35:41.477Z"}
// {"termsOfUse":"https://www.ryanair.com/ie/en/corporate/terms-of-use=AGREED","currency":"EUR","currPrecision":2,"trips":[{"origin":"FRA","originName":"Frankfurt International Airport","destination":"AGP","destinationName":"Malaga T2","dates":[{"dateOut":"2017-08-30T00:00:00.000","flights":[{"faresLeft":-1,"flightKey":"FR~4100~ ~~FRA~08/30/2017 07:00~AGP~08/30/2017 10:05~","infantsLeft":17,"regularFare":{"fareKey":"0~T~~TZ12LOW~BO12~~2~X","fareClass":"T","fares":[{"type":"ADT","amount":35.9900,"count":1,"hasDiscount":false,"publishedFare":35.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"FRA","destination":"AGP","flightNumber":"FR 4100","time":["2017-08-30T07:00:00.000","2017-08-30T10:05:00.000"],"timeUTC":["2017-08-30T05:00:00.000Z","2017-08-30T08:05:00.000Z"],"duration":"03:05"}],"flightNumber":"FR 4100","time":["2017-08-30T07:00:00.000","2017-08-30T10:05:00.000"],"timeUTC":["2017-08-30T05:00:00.000Z","2017-08-30T08:05:00.000Z"],"duration":"03:05"}]},{"dateOut":"2017-08-31T00:00:00.000","flights":[{"faresLeft":-1,"flightKey":"FR~4100~ ~~FRA~08/31/2017 07:00~AGP~08/31/2017 10:05~","infantsLeft":18,"regularFare":{"fareKey":"0~A~~AZ12LOW~BO12~~2~X","fareClass":"A","fares":[{"type":"ADT","amount":50.9900,"count":1,"hasDiscount":false,"publishedFare":50.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"FRA","destination":"AGP","flightNumber":"FR 4100","time":["2017-08-31T07:00:00.000","2017-08-31T10:05:00.000"],"timeUTC":["2017-08-31T05:00:00.000Z","2017-08-31T08:05:00.000Z"],"duration":"03:05"}],"flightNumber":"FR 4100","time":["2017-08-31T07:00:00.000","2017-08-31T10:05:00.000"],"timeUTC":["2017-08-31T05:00:00.000Z","2017-08-31T08:05:00.000Z"],"duration":"03:05"}]},{"dateOut":"2017-09-01T00:00:00.000","flights":[{"faresLeft":-1,"flightKey":"FR~4100~ ~~FRA~09/01/2017 07:00~AGP~09/01/2017 10:05~","infantsLeft":18,"regularFare":{"fareKey":"0~C~~CZ12LOW~BO12~~2~X","fareClass":"C","fares":[{"type":"ADT","amount":69.9900,"count":1,"hasDiscount":false,"publishedFare":69.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"FRA","destination":"AGP","flightNumber":"FR 4100","time":["2017-09-01T07:00:00.000","2017-09-01T10:05:00.000"],"timeUTC":["2017-09-01T05:00:00.000Z","2017-09-01T08:05:00.000Z"],"duration":"03:05"}],"flightNumber":"FR 4100","time":["2017-09-01T07:00:00.000","2017-09-01T10:05:00.000"],"timeUTC":["2017-09-01T05:00:00.000Z","2017-09-01T08:05:00.000Z"],"duration":"03:05"}]},{"dateOut":"2017-09-02T00:00:00.000","flights":[{"faresLeft":3,"flightKey":"FR~4100~ ~~FRA~09/02/2017 07:00~AGP~09/02/2017 10:05~","infantsLeft":16,"regularFare":{"fareKey":"0~H~~HZ12LOW~BO12~~2~X","fareClass":"H","fares":[{"type":"ADT","amount":59.9900,"count":1,"hasDiscount":false,"publishedFare":59.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"FRA","destination":"AGP","flightNumber":"FR 4100","time":["2017-09-02T07:00:00.000","2017-09-02T10:05:00.000"],"timeUTC":["2017-09-02T05:00:00.000Z","2017-09-02T08:05:00.000Z"],"duration":"03:05"}],"flightNumber":"FR 4100","time":["2017-09-02T07:00:00.000","2017-09-02T10:05:00.000"],"timeUTC":["2017-09-02T05:00:00.000Z","2017-09-02T08:05:00.000Z"],"duration":"03:05"}]},{"dateOut":"2017-09-03T00:00:00.000","flights":[{"faresLeft":2,"flightKey":"FR~4100~ ~~FRA~09/03/2017 07:25~AGP~09/03/2017 10:30~","infantsLeft":16,"regularFare":{"fareKey":"0~H~~HZ12LOW~BO12~~2~X","fareClass":"H","fares":[{"type":"ADT","amount":59.9900,"count":1,"hasDiscount":false,"publishedFare":59.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"FRA","destination":"AGP","flightNumber":"FR 4100","time":["2017-09-03T07:25:00.000","2017-09-03T10:30:00.000"],"timeUTC":["2017-09-03T05:25:00.000Z","2017-09-03T08:30:00.000Z"],"duration":"03:05"}],"flightNumber":"FR 4100","time":["2017-09-03T07:25:00.000","2017-09-03T10:30:00.000"],"timeUTC":["2017-09-03T05:25:00.000Z","2017-09-03T08:30:00.000Z"],"duration":"03:05"}]}]},{"origin":"AGP","originName":"Frankfurt International Airport","destination":"FRA","destinationName":"Malaga T2","dates":[{"dateOut":"2017-09-01T00:00:00.000","flights":[{"faresLeft":3,"flightKey":"FR~4110~ ~~AGP~09/01/2017 10:50~FRA~09/01/2017 14:00~","infantsLeft":18,"regularFare":{"fareKey":"0~C~~CZ12LOW~BO12~~2~X","fareClass":"C","fares":[{"type":"ADT","amount":69.9900,"count":1,"hasDiscount":false,"publishedFare":69.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-01T10:50:00.000","2017-09-01T14:00:00.000"],"timeUTC":["2017-09-01T08:50:00.000Z","2017-09-01T12:00:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-01T10:50:00.000","2017-09-01T14:00:00.000"],"timeUTC":["2017-09-01T08:50:00.000Z","2017-09-01T12:00:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-02T00:00:00.000","flights":[{"faresLeft":5,"flightKey":"FR~4110~ ~~AGP~09/02/2017 11:05~FRA~09/02/2017 14:15~","infantsLeft":17,"regularFare":{"fareKey":"0~V~~VZ12LOW~BO12~~2~X","fareClass":"V","fares":[{"type":"ADT","amount":81.9900,"count":1,"hasDiscount":false,"publishedFare":81.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-02T11:05:00.000","2017-09-02T14:15:00.000"],"timeUTC":["2017-09-02T09:05:00.000Z","2017-09-02T12:15:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-02T11:05:00.000","2017-09-02T14:15:00.000"],"timeUTC":["2017-09-02T09:05:00.000Z","2017-09-02T12:15:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-03T00:00:00.000","flights":[{"faresLeft":2,"flightKey":"FR~4110~ ~~AGP~09/03/2017 11:10~FRA~09/03/2017 14:20~","infantsLeft":16,"regularFare":{"fareKey":"0~V~~VZ12LOW~BO12~~2~X","fareClass":"V","fares":[{"type":"ADT","amount":81.9900,"count":1,"hasDiscount":false,"publishedFare":81.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-03T11:10:00.000","2017-09-03T14:20:00.000"],"timeUTC":["2017-09-03T09:10:00.000Z","2017-09-03T12:20:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-03T11:10:00.000","2017-09-03T14:20:00.000"],"timeUTC":["2017-09-03T09:10:00.000Z","2017-09-03T12:20:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-04T00:00:00.000","flights":[{"faresLeft":1,"flightKey":"FR~4110~ ~~AGP~09/04/2017 10:50~FRA~09/04/2017 14:00~","infantsLeft":16,"regularFare":{"fareKey":"0~V~~VZ12LOW~BO12~~2~X","fareClass":"V","fares":[{"type":"ADT","amount":81.9900,"count":1,"hasDiscount":false,"publishedFare":81.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-04T10:50:00.000","2017-09-04T14:00:00.000"],"timeUTC":["2017-09-04T08:50:00.000Z","2017-09-04T12:00:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-04T10:50:00.000","2017-09-04T14:00:00.000"],"timeUTC":["2017-09-04T08:50:00.000Z","2017-09-04T12:00:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-05T00:00:00.000","flights":[{"faresLeft":1,"flightKey":"FR~4110~ ~~AGP~09/05/2017 11:05~FRA~09/05/2017 14:15~","infantsLeft":17,"regularFare":{"fareKey":"0~H~~HZ12LOW~BO12~~2~X","fareClass":"H","fares":[{"type":"ADT","amount":59.9900,"count":1,"hasDiscount":false,"publishedFare":59.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-05T11:05:00.000","2017-09-05T14:15:00.000"],"timeUTC":["2017-09-05T09:05:00.000Z","2017-09-05T12:15:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-05T11:05:00.000","2017-09-05T14:15:00.000"],"timeUTC":["2017-09-05T09:05:00.000Z","2017-09-05T12:15:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-06T00:00:00.000","flights":[{"faresLeft":-1,"flightKey":"FR~4110~ ~~AGP~09/06/2017 10:50~FRA~09/06/2017 14:00~","infantsLeft":17,"regularFare":{"fareKey":"0~H~~HZ12LOW~BO12~~2~X","fareClass":"H","fares":[{"type":"ADT","amount":59.9900,"count":1,"hasDiscount":false,"publishedFare":59.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-06T10:50:00.000","2017-09-06T14:00:00.000"],"timeUTC":["2017-09-06T08:50:00.000Z","2017-09-06T12:00:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-06T10:50:00.000","2017-09-06T14:00:00.000"],"timeUTC":["2017-09-06T08:50:00.000Z","2017-09-06T12:00:00.000Z"],"duration":"03:10"}]},{"dateOut":"2017-09-07T00:00:00.000","flights":[{"faresLeft":1,"flightKey":"FR~4110~ ~~AGP~09/07/2017 11:10~FRA~09/07/2017 14:20~","infantsLeft":17,"regularFare":{"fareKey":"0~A~~AZ12LOW~BO12~~2~X","fareClass":"A","fares":[{"type":"ADT","amount":50.9900,"count":1,"hasDiscount":false,"publishedFare":50.9900,"discountInPercent":0,"hasPromoDiscount":false}]},"segments":[{"segmentNr":0,"origin":"AGP","destination":"FRA","flightNumber":"FR 4110","time":["2017-09-07T11:10:00.000","2017-09-07T14:20:00.000"],"timeUTC":["2017-09-07T09:10:00.000Z","2017-09-07T12:20:00.000Z"],"duration":"03:10"}],"flightNumber":"FR 4110","time":["2017-09-07T11:10:00.000","2017-09-07T14:20:00.000"],"timeUTC":["2017-09-07T09:10:00.000Z","2017-09-07T12:20:00.000Z"],"duration":"03:10"}]}]}],"serverTimeUTC":"2017-07-08T15:16:40.886Z"}


        //URI lURI = null;
        JSONTokener lTokener = null;
		//lURI = new URI( lUrl );
		//lTokener = new JSONTokener( lURI.toURL().openStream());
        //lTokener = new JSONTokener(new ByteArrayInputStream( lTestJsonString.getBytes() ));

        String strResponse;
        strResponse = dcHttpClient.sendGet( lUrl );

        if( dcHttpClient.getResponseCode() != 404 && strResponse.length() > 0 )
            lTokener = new JSONTokener(new ByteArrayInputStream( strResponse.getBytes() ));


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
            // we need the cookie to get the flight information in the FillTheForm
            String response = dcHttpClient.sendGet( "https://www.ryanair.com" );
            InitServerApiUrl( response );

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
                    lTravelDataInput = (TravelData_INPUT) mSearchQueue.pop();
                }

                try
                {
                    FillTheForm( lTravelDataInput );
                }
                catch( URISyntaxException e )
                {
                    mLogger.error( "Exception in RyanAir.run: " + StringHelper.getTraceInformation( e ) );
                }
                catch( IOException e )
                {
                    mLogger.error( "Exception in RyanAir.run: " + StringHelper.getTraceInformation( e ) );
                }

                String lSleep = Configuration.getInstance().getValue( "/configuration/global/DelayBeforeClick", "3" );
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
}
