package Storage;

import Configuration.Configuration;
import PageGuest.AccomodationData_RESULT;
import PageGuest.TravelData_RESULT;
import Util.CurrencyHelper;
import Util.GMailSender;
import org.apache.log4j.Logger;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;

import Configuration.Recipient;
import Favorites.*;

/**
 * Created by Andras on 22/12/2016.
 */
public class EmailNotifierAgent extends ArchiverAgent
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(EmailNotifierAgent.class);

	private SQLiteAgent mSQLiteAgent;
	private String mPrice;
	private Float mCurrencyPriceInEuro;
	private ArrayList<Recipient> mRecipientList;
	private ArrayList<Recipient> mMatchedRecipients;

	final double mPriceDropTreshold = 10000; // €
	private double mOldPrice;
	private double mNewPrice;

	private HashSet<String> mMatchedTrips;
	private GMailSender mGmailSender;

	public EmailNotifierAgent( SQLiteAgent agent, GMailSender gmailSender )
	{
		mSQLiteAgent = agent;
		mRecipientList = Configuration.getInstance().getRecipientList();
		mMatchedTrips = new HashSet<>(  );
		mGmailSender = gmailSender;
	}

	private void initMatchedRecipients( TravelData_RESULT aResult )
	{
		mLogger.trace( "begin" );
		mMatchedRecipients = new ArrayList<Recipient>();

		mLogger.trace( "result airline: " + aResult.mAirline );
		for( Recipient r : mRecipientList )
		{
			String lAirLine = r.get( "airline" );
			if( lAirLine != null && lAirLine.compareToIgnoreCase( aResult.mAirline ) == 0 )
			{
				mLogger.trace( "recipient airline: " + lAirLine );
				String lAirportCodes = r.get( "ObservedAirportCodes" );
				mLogger.trace( "lAirportCodes: " + lAirportCodes );
				String[] lACodes = lAirportCodes.split( "," );
				for( String lAC : lACodes )
				{
					if( lAC.compareToIgnoreCase( aResult.mAirportCode_LeavingFrom ) == 0 ||
							lAC.compareToIgnoreCase( aResult.mAirportCode_GoingTo ) == 0 )
					{
						mLogger.trace( "matched recipient: " + r.toString() );
						mMatchedRecipients.add( r );
						break;
					}
				}
			}
		}
		mLogger.trace( "end" );
	}

	@Override
	protected void WriteData( Object aResultObject )
	{
		// Convert the possible trips to OneWayTrip and search the same trips in the Favorites.
		// Send e-mail about a trip, if it is in the TravelData_REULT and in the Favorites too, a price drop was detected.

		// Question: how can I detect the price drop in case of a possible trip?
		// Answer: I have to compare the price of this and price of the earlier newest trip.

		TravelData_RESULT lResult;
		if( aResultObject instanceof TravelData_RESULT )
			lResult = (TravelData_RESULT)aResultObject;
		else
			return;

		mLogger.trace( "begin" );
		initMatchedRecipients( lResult );

		if( mMatchedRecipients.size() == 0 )
			return;

		mLogger.trace( "there are " + mMatchedRecipients.size() + " recipients" );

		Favorites lFavorites = Favorites.getInstance();
		mLogger.trace( "favourites: " + lFavorites.toString() );
		for( TravelData_RESULT.TravelData_PossibleTrip lTrip : lResult.mTrips )
		{
			// convert from 2017-01-24T14:55:00 to 2017-01-24 14:55
			String lDepartureDatetime = lTrip.mDepartureDatetime.replace( "T", " " );
			lDepartureDatetime = lDepartureDatetime.substring( 0, lDepartureDatetime.length() - 3 );
			OneWayTrip lOneWayTrip = new OneWayTrip( lDepartureDatetime, lResult.mAirline,
					lResult.mAirportCode_LeavingFrom, lResult.mAirportCode_GoingTo,
					lTrip.mOutboundTrip );
			String oneWayTripString = lOneWayTrip.toString();
			mLogger.trace( "one way trip: " + oneWayTripString );
			if( !mMatchedTrips.contains( oneWayTripString )
					&& lFavorites.contains( lOneWayTrip, null ))
			{
				mLogger.trace( "one way trip found in the favourites" );
				if( LoadNewestEarlierTripData( lOneWayTrip ))
				{
					double lPriceDrop = getPriceDrop( lTrip );
					mLogger.trace( "mOldPrice: " + mOldPrice + "; mNewPrice: " + mNewPrice );
					for( Recipient r : mMatchedRecipients )
					{
						if( checkPriceDropTreshold( r, lPriceDrop ))
						{
							sendMailSSL( r, lOneWayTrip, lResult.mRecordedDatetime );
							mMatchedTrips.add( oneWayTripString );
						}
					}
				}
			}
		}
		mLogger.trace( "end" );
	}

	public boolean LoadNewestEarlierTripData( final OneWayTrip aTrip )
	{
		mLogger.trace( "begin" );
		try
		{
			String query = "SELECT * FROM TravelDataResult tdr, TravelDataResult_PossibleTrips pt "
					+ "where tdr.ID=pt.TravelDataResult_ID and tdr.Airline='" + aTrip.getAirline()
					+ "' and ((tdr.AirportCode_LeavingFrom='" + aTrip.getLeavingFrom()
					+ "' and tdr.AirportCode_GoingTo='" + aTrip.getGoingTo()
					+ "' and pt.OutBoundTrip='" + (aTrip.getOutbound() ? "true" : "false" ) + "') OR "
					+ "(tdr.AirportCode_LeavingFrom='" + aTrip.getGoingTo()
					+ "' and tdr.AirportCode_GoingTo='" + aTrip.getLeavingFrom()
					+ "' and pt.OutBoundTrip='" + ( !aTrip.getOutbound() ? "true" : "false" ) + "')) AND "
					+ "pt.DepartureDateTime='" + aTrip.getDatetime() + "' "
					+ "order by pt.SearchDateTime desc "
					+ "limit 2";

			// The newest record is already written in the DB, so the old one is the one before the newest one.
			ResultSet lResultSet = mSQLiteAgent.Query( query );
			if( lResultSet == null )
				return false;

			if( !lResultSet.next()) {
				lResultSet.close();
				lResultSet.getStatement().close();
				return false;
			}

			mPrice = lResultSet.getString( "Prices_BasicFare_Discount");
			if( mPrice.length() == 0 )
				mPrice = lResultSet.getString( "Prices_BasicFare_Normal");
			if( mPrice.length() == 0 )
				mPrice = lResultSet.getString( "Prices_PlusFare_Discount");
			if( mPrice.length() == 0 )
				mPrice = lResultSet.getString( "Prices_PlusFare_Normal");

			mCurrencyPriceInEuro = lResultSet.getFloat( "Currency_Price_In_Euro" );
			if( lResultSet.wasNull())
				mCurrencyPriceInEuro = null;
			lResultSet.close();
			lResultSet.getStatement().close();
			mLogger.trace( "end true" );
			return true;
		}
		catch( SQLException e )
		{
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}

		mLogger.trace( "end false" );
		return false;
	}

	private double getPriceDrop( TravelData_RESULT.TravelData_PossibleTrip aTrip )
	{
		// DB PRICE CONVERTING
		// 176,89 lv
		// 53 195,00 Ft

		String lValue = "";
		int lPos = mPrice.length() - 1;
		char lActChar = mPrice.charAt( lPos );
		while( lActChar < '0' || lActChar > '9' )
		{
			lPos--;
			lActChar = mPrice.charAt( lPos );
		}
		lValue = mPrice.substring( 0, lPos + 1 ).trim();
		lValue = lValue.replace( ",", "." );
		StringBuffer lBuffer = new StringBuffer();
		for( int i = 0; i < lValue.length(); i++ )
			if(( lValue.charAt( i ) >= '0' && lValue.charAt( i ) <= '9') ||
					lValue.charAt( i ) == '.' )
				lBuffer.append( lValue.charAt( i ));
		mOldPrice = Double.parseDouble( lBuffer.toString() );
		if( mCurrencyPriceInEuro != null && mCurrencyPriceInEuro > 0.0 )
			mOldPrice *= (double)mCurrencyPriceInEuro;


		// Trip Price Converting
		String lPrice = aTrip.mPrices_BasicFare_Discount;
		if( lPrice.length() == 0 )
			lPrice = aTrip.mPrices_BasicFare_Normal;
		if( lPrice.length() == 0 )
			lPrice = aTrip.mPrices_PlusFare_Discount;
		if( lPrice.length() == 0 )
			lPrice = aTrip.mPrices_PlusFare_Normal;

		mNewPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice, true );

		return  mOldPrice - mNewPrice;
	}

	private boolean checkPriceDropTreshold( Recipient r, double aPriceDrop )
	{
		String lPriceDropTreshold = r.get( "PriceDropTreshold" );
		String lPriceLimit = r.get( "PriceLimit" );
		mLogger.trace( "lPriceDropTreshold: " + lPriceDropTreshold );
		mLogger.trace( "lPriceLimit: " + lPriceLimit );
		mLogger.trace( "lPriceDrop: " + aPriceDrop );

		if( lPriceDropTreshold != null && lPriceDropTreshold.length() >= 0 )
		{
			Double lPriceDropTresholdDouble = Double.parseDouble( lPriceDropTreshold );
			if( lPriceDropTresholdDouble <= aPriceDrop )
				return true;
		}

		if( lPriceLimit != null && lPriceLimit.length() >= 0 ){
			Double lPriceLimitDouble = Double.parseDouble( lPriceLimit );
			if( lPriceLimitDouble >= mNewPrice )
				return true;
		}
		return mPriceDropTreshold <= aPriceDrop;
	}

	private void sendMailSSL( Recipient recipient, OneWayTrip aOWTrip, String recordedDatetime )
	{
		String fromAddress = "agent@traveloptimizer.com";
		String fromName = "Travel Optimizer";
		String toAddress = recipient.get( "email" );
		String toName = recipient.get( "name" );
		String subject = "Travel Optimizer price drop warning";
		String msgBody = "Hi " + recipient.get( "name" ) + ",\n" +
				"the following trip's price went down:\n" +
				aOWTrip.getAirline() + "\n" +
				aOWTrip.getOutboundDepartureAirport() +
				" - " + aOWTrip.getOutboundArrivalAirport() +
				" " + aOWTrip.getDatetime() + "\n" +
				"old price: " + mOldPrice + "\n" +
				"new price: " + mNewPrice + "\n" +
				"recorded datetime: " + recordedDatetime + "\n";

		//GMailSender.send( fromAddress, fromName, toAddress, toName, subject, msgBody );
		mGmailSender.add( fromAddress, fromName, toAddress, toName, subject, msgBody );
	}
}
