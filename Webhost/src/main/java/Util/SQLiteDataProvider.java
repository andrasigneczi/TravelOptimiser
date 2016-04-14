package Util;

import java.sql.*;
import java.util.ArrayList;

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

	public String GetData( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency, DataResultComposer aDRComposer )
	{
		String lQuery;
		lQuery = mComposer.GetQuery( aDateTime, aAirline, aAirportFrom, aAirportTo, aCurrency);

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
}
