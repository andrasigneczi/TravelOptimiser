package Storage;

import Configuration.Configuration;
import PageGuest.TravelData_RESULT;
import Util.CurrencyHelper;
import org.apache.log4j.Logger;

import java.io.UnsupportedEncodingException;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Properties;

import Configuration.Recipient;

import javax.mail.*;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

import Favorites.*;

/**
 * Created by Andras on 22/12/2016.
 */
public class EmailNotifierAgent extends ArchiverAgent
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(SQLiteAgent.class);

	private SQLiteAgent mSQLiteAgent;
	private String mPrice;
	private Float mCurrencyPriceInEuro;
	private ArrayList<Recipient> mRecipientList;
	private ArrayList<Recipient> mMatchedRecipients;

	final double mPriceDropTreshold = 10000; // €
	private double mOldPrice;
	private double mNewPrice;

	public EmailNotifierAgent( SQLiteAgent agent )
	{
		mSQLiteAgent = agent;
		mRecipientList = Configuration.getInstance().getRecipientList();
	}

	private void initMatchedRecipients( TravelData_RESULT aResult )
	{
		mMatchedRecipients = new ArrayList<Recipient>();

		for( Recipient r : mRecipientList )
		{
			String lAirLine = r.get( "airline" );
			if( lAirLine != null && lAirLine.compareToIgnoreCase( aResult.mAirline ) == 0 )
			{
				String lAirportCodes = r.get( "ObservedAirportCodes" );
				String[] lACodes = lAirportCodes.split( "," );
				for( String lAC : lACodes )
				{
					if( lAC.compareToIgnoreCase( aResult.mAirportCode_LeavingFrom ) == 0 ||
							lAC.compareToIgnoreCase( aResult.mAirportCode_GoingTo ) == 0 )
					{
						mMatchedRecipients.add( r );
						break;
					}
				}
			}
		}
	}

	@Override
	protected void WriteData( TravelData_RESULT aResult )
	{
		// Convert the possible trips to OneWayTrip and search the same trips in the Favorites.
		// Send e-mail about a trip, if it is in the TravelData_REULT and in the Favorites too, a price drop was detected.

		// Question: how can I detect the price drop in case of a possible trip?
		// Answer: I have to compare the price of this and price of the earlier newest trip.

		mLogger.trace( "begin" );
		initMatchedRecipients( aResult );

		if( mMatchedRecipients.size() == 0 )
			return;

		Favorites lFavorites = Favorites.getInstance();
		for( TravelData_RESULT.TravelData_PossibleTrip lTrip : aResult.mTrips )
		{
			// convert from 2017-01-24T14:55:00 to 2017-01-24 14:55
			String lDepartureDatetime = lTrip.mDepartureDatetime.replace( "T", " " );
			lDepartureDatetime = lDepartureDatetime.substring( 0, lDepartureDatetime.length() - 3 );
			OneWayTrip lOneWayTrip = new OneWayTrip( lDepartureDatetime, aResult.mAirline,
					aResult.mAirportCode_LeavingFrom, aResult.mAirportCode_GoingTo,
					lTrip.mOutboundTrip );
			if( lFavorites.contains( lOneWayTrip, null ))
			{
				if( LoadNewestEarlierTripData( lOneWayTrip ))
				{
					double lPriceDrop = getPriceDrop( lTrip );
					for( Recipient r : mRecipientList )
					{
						if( checkPriceDropTreshold( r, lPriceDrop ))
							sendMailSSL( r, lOneWayTrip );
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
					+ "limit 1";

			ResultSet lResultSet = mSQLiteAgent.Query( query );
			if( lResultSet == null )
				return false;
			mPrice = lResultSet.getString( "Prices_BasicFare_Discount");
			if( mPrice.length() == 0 )
				mPrice = lResultSet.getString( "Prices_BasicFare_Normal");

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
		mNewPrice = CurrencyHelper.convertPriceToPriceInEuro( lPrice );

		return  mOldPrice - mNewPrice;
	}

	private boolean checkPriceDropTreshold( Recipient r, double lPriceDrop )
	{
		String lPriceDropTreshold = r.get( "PriceDropTreshold" );
		String lPriceLimit = r.get( "PriceLimit" );

		if( lPriceDropTreshold != null && lPriceDropTreshold.length() >= 0 )
		{
			Double lPriceDropTresholdDouble = Double.parseDouble( lPriceDropTreshold );
			if( lPriceDropTresholdDouble <= lPriceDrop )
				return true;
		}

		return mPriceDropTreshold <= lPriceDrop;
	}

	private void sendMail( Recipient recipient, OneWayTrip aOWTrip )
	{
		// Get system properties
		Properties properties = System.getProperties();

		// Setup mail server
		properties.setProperty("mail.smtp.host", "localhost");
		Session session = Session.getDefaultInstance(properties, null);

		try {
			Message msg = new MimeMessage(session);
			msg.setFrom(new InternetAddress("agent@traveloptimizer.com", "Travel Optimizer"));
			msg.addRecipient(Message.RecipientType.TO,
					new InternetAddress( recipient.get("email"), recipient.get("name")));
			msg.setSubject("Travel Optimizer price drop warning");

			String text = "Hi " + recipient.get("name") + ",\n" +
					"the following trip's price went down:\n" +
					aOWTrip.getAirline() + "\n" +
					aOWTrip.getOutboundDepartureAirport() +
					" - " + aOWTrip.getOutboundArrivalAirport() +
					" " + aOWTrip.getDatetime() + "\n" +
					"old price: " + mOldPrice + "\n" +
					"new price: " + mNewPrice + "\n";

			msg.setText( text );
			Transport.send(msg);
		} catch (AddressException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		} catch (MessagingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		} catch (UnsupportedEncodingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}
	}

	private void sendMailSSL( Recipient recipient, OneWayTrip aOWTrip )
	{
		String smtp_host = "smtp.gmail.com";
		String smtp_port = "465";
		String smtp_username = "";
		String smtp_password = "";

		Properties props = new Properties();
		props.put("mail.smtp.host", smtp_host);
		props.put("mail.smtp.socketFactory.port", smtp_port);
		props.put("mail.smtp.socketFactory.class",
				"javax.net.ssl.SSLSocketFactory");
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.port", "465");
		props.put("mail.smtp.starttls.enable","true");

		Session session = Session.getDefaultInstance(props,
				new javax.mail.Authenticator() {
					protected PasswordAuthentication getPasswordAuthentication() {
						return new PasswordAuthentication(smtp_username,smtp_password);
					}
				});

		try {

			Message msg = new MimeMessage(session);
			msg.setFrom(new InternetAddress("agent@traveloptimizer.com", "Travel Optimizer"));
			msg.addRecipient(Message.RecipientType.TO,
					new InternetAddress( recipient.get("email"), recipient.get("name")));
			msg.setSubject("Travel Optimizer price drop warning");

			String text = "Hi " + recipient.get("name") + ",\n" +
					"the following trip's price went down:\n" +
					aOWTrip.getAirline() + "\n" +
					aOWTrip.getOutboundDepartureAirport() +
					" - " + aOWTrip.getOutboundArrivalAirport() +
					" " + aOWTrip.getDatetime() + "\n" +
					"old price: " + mOldPrice + "\n" +
					"new price: " + mNewPrice + "\n";

			msg.setText( text );
			//Transport.send(msg);
			Transport transport = session.getTransport("smtps");
			transport.connect (smtp_host, Integer.parseInt(smtp_port), smtp_username, smtp_password);
			transport.sendMessage(msg, msg.getAllRecipients());
			transport.close();

			System.out.println("Done");

		} catch (MessagingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		} catch (UnsupportedEncodingException e) {
			mLogger.warn( Util.StringHelper.getTraceInformation( e ) );
		}
	}
}
