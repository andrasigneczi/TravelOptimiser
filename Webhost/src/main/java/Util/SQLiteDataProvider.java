package Util;

import org.apache.log4j.Logger;

import java.sql.*;
import java.util.Hashtable;

/**
 * Created by Andras on 13/04/2016.
 */
public class SQLiteDataProvider implements DataProvider
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(HighChartDataResultComposer.class);

	private static SQLiteDataProvider mInstance = null;
	private Connection mConnection = null;
	private SQLiteComposer mComposer = null;

	private SQLiteDataProvider()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			mConnection = DriverManager.getConnection("jdbc:sqlite:test.db");
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		mComposer = new SQLiteComposer();
	}

	public static SQLiteDataProvider getInstance()
	{
		if (mInstance != null)
		{
			return mInstance;
		}

		synchronized(SQLiteDataProvider.class)
		{
			if (mInstance != null)
			{
				return mInstance;
			}
			mInstance = new SQLiteDataProvider();
		}
		return mInstance;
	}

	public void ConnectionClose()
	{
		try
		{
			mConnection.close();
		}
		catch( SQLException e )
		{
			e.printStackTrace();
		}
	}

	/**
	 *
	 * @param aDateTime
	 * @param aAirline
	 * @param aAirportFrom
	 * @param aAirportTo
	 * @param aCurrency
	 * @param aDRComposer
	 * @return
	 */
	public Hashtable<String,String> GetTripData( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency, DataResultComposer aDRComposer )
	{
		Hashtable<String,String> lReturnData = new Hashtable<String,String>();
		String lQuery;
		lQuery = mComposer.GetTripQuery( aDateTime, aAirline, aAirportFrom, aAirportTo, aCurrency);

		String lAirportCode_LeavingFrom = "";
		String lAirportCode_GoingTo = "";
		String lAirline = "";

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				if( lAirportCode_LeavingFrom.length() == 0 )
					lAirportCode_LeavingFrom = lResultSet.getString( "AirportCode_LeavingFrom" );
				else if( !lAirportCode_LeavingFrom.equals( lResultSet.getString( "AirportCode_LeavingFrom" ) ))
					mLogger.warn( "'AirportCode_LeavingFrom' inconsistency?!" );

				if( lAirportCode_GoingTo.length() == 0 )
					lAirportCode_GoingTo = lResultSet.getString( "AirportCode_GoingTo" );
				else if( !lAirportCode_GoingTo.equals( lResultSet.getString( "AirportCode_GoingTo" ) ))
					mLogger.warn( "'AirportCode_GoingTo' inconsistency?!" );

				if( lAirline.length() == 0 )
					lAirline = lResultSet.getString( "Airline" );
				else if( !lAirline.equals( lResultSet.getString( "Airline" )))
					mLogger.warn( "'Airline' inconsistency?!" );

				String lPrice = lResultSet.getString( "Prices_BasicFare_Discount");
				if( lPrice.length() == 0 )
					lPrice = lResultSet.getString( "Prices_BasicFare_Normal");

				aDRComposer.add( lResultSet.getString( "SearchDatetime" ), lPrice, aCurrency);
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}

		lReturnData.put( "Result", aDRComposer.getResult());
		lReturnData.put( "Airline", lAirline );
		lReturnData.put( "AirportCode_LeavingFrom", lAirportCode_LeavingFrom );
		lReturnData.put( "AirportCode_GoingTo", lAirportCode_GoingTo );

		return lReturnData;
	}

	/**
	 *
	 * @param aHtmlListFormatter
	 * @param aSelectedDepartureAirport
	 * @param aSelectedArrivalAirport
	 * @param aReturnCheckboxChecked
	 * @return
	 */
	public String GetCollectedDepartureDateList( HtmlListFormatter aHtmlListFormatter,
	                                             String aSelectedDepartureAirport,
	                                             String aSelectedArrivalAirport,
	                                             boolean aReturnCheckboxChecked )
	{
		String lQuery;
		lQuery = mComposer.GetTripDateListQuery( aSelectedDepartureAirport, aSelectedArrivalAirport, aReturnCheckboxChecked );

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				aHtmlListFormatter.add(
						new String[]{
								lResultSet.getString( "DepartureDatetime" ),
								lResultSet.getString( "Airline" ),
								lResultSet.getString( "AirportCode_LeavingFrom" ),
								lResultSet.getString( "AirportCode_GoingTo" ),
								lResultSet.getString( "OutboundTrip" )
						});
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aHtmlListFormatter.getFormattedResult();
	}

	/**
	 *
	 * @param aDepartureAirportListFormatter
	 * @param aSelectedDepartureAirport
	 * @return
	 */
	public String GetDepartureAirportList( HtmlListFormatter aDepartureAirportListFormatter, String aSelectedDepartureAirport )
	{
		String lQuery;
		lQuery = mComposer.GetDepartureAirportListQuery();
		aDepartureAirportListFormatter.setSelected( aSelectedDepartureAirport );

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				//boolean lO = lResultSet.getBoolean( "OutboundTrip" );
				//int lI = lResultSet.getInt( "OutboundTrip" );
				String lOutboundTrip = lResultSet.getString( "OutboundTrip" );
				if( lOutboundTrip.equals( "true" ))
					aDepartureAirportListFormatter.add( lResultSet.getString( "AirportCode_LeavingFrom" ));
				else
					aDepartureAirportListFormatter.add( lResultSet.getString( "AirportCode_GoingTo" ));
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aDepartureAirportListFormatter.getFormattedResult();
	}

	/**
	 *
	 * @param aArrivalAirportListFormatter
	 * @param aSelectedDepartureAirport
	 * @param aSelectedArrivalAirport
	 * @return
	 */
	public String GetArrivalAirportList( HtmlListFormatter aArrivalAirportListFormatter, String aSelectedDepartureAirport, String aSelectedArrivalAirport )
	{
		String lQuery;
		lQuery = mComposer.GetArrivalAirportListQuery( aSelectedDepartureAirport );
		aArrivalAirportListFormatter.setSelected( aSelectedArrivalAirport );

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				String lOutboundTrip = lResultSet.getString( "OutboundTrip" );
				if( lOutboundTrip.equals( "true" ))
					aArrivalAirportListFormatter.add( lResultSet.getString( "AirportCode_LeavingFrom" ));
				else
					aArrivalAirportListFormatter.add( lResultSet.getString( "AirportCode_GoingTo" ));
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aArrivalAirportListFormatter.getFormattedResult();
	}
}
