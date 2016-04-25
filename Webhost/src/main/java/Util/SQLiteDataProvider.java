package Util;

import java.sql.*;

/**
 * Created by Andras on 13/04/2016.
 */
public class SQLiteDataProvider implements DataProvider
{
	private static SQLiteDataProvider mInstance = null;
	private Connection mConnection = null;
	private SQLiteComposer mComposer = null;

	private SQLiteDataProvider()
	{
		try {
			Class.forName("org.sqlite.JDBC");
			mConnection = DriverManager.getConnection("jdbc:sqlite:test.db");
		} catch ( Exception e ) {
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

	public String GetTripData( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency, DataResultComposer aDRComposer )
	{
		String lQuery;
		lQuery = mComposer.GetTripQuery( aDateTime, aAirline, aAirportFrom, aAirportTo, aCurrency);

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				aDRComposer.add( lResultSet.getString( "SearchDatetime" ), lResultSet.getString( "Prices_BasicFare_Discount"), aCurrency);
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}

		return aDRComposer.getResult();
	}

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
				aHtmlListFormatter.add( new String[]{lResultSet.getString( "DepartureDatetime" ),
						lResultSet.getString( "Airline" )});
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aHtmlListFormatter.getFormattedResult();
	}

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
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aDepartureAirportListFormatter.getFormattedResult();
	}

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
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aArrivalAirportListFormatter.getFormattedResult();
	}
}
