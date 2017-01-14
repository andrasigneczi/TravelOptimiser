package Favorites;

import Util.Util;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.*;
import java.util.ArrayList;

/**
 * Created by Andras on 10/10/2016.
 */
public class FavouriteStorage_SQLite implements FavouritesStorage
{
	private static Logger mLogger = LoggerFactory.getLogger(FavouriteStorage_SQLite.class);

	private Connection mConnection = null;
	private final static String mDatabaseFileName = "favourites.db";

	public FavouriteStorage_SQLite()
	{
	}

	private void ConnectionOpen()
	{
		try
		{
			Class.forName("org.sqlite.JDBC");
			mConnection = DriverManager.getConnection( "jdbc:sqlite:" + mDatabaseFileName );
		}
		catch( ClassNotFoundException e )
		{
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
		}
		catch( SQLException e )
		{
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
		}
	}

	private void ConnectionClose()
	{
		try
		{
			if( mConnection != null )
				mConnection.close();
		}
		catch( SQLException e )
		{
			mLogger.error( "ConnectionClose error: " + Util.getTraceInformation( e ));
		}
	}

	@Override
	public ArrayList<String> LoadFavourites()
	{
		ConnectionOpen();
		ConnectionClose();
		return null;
	}

	@Override
	public void SaveFavourites( ArrayList<String> aTrips )
	{
		ConnectionOpen();
		ConnectionClose();
	}

	private int GetSearchId( String aQuery )
	{
		mLogger.trace( "begin" );

		mLogger.trace( aQuery );

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( aQuery );
			while ( lResultSet.next() ) {
				lID = lResultSet.getInt("ID");
			}
			lResultSet.close();
			lStmt.close();
			mLogger.trace( "return" );
			return lID;
		}
		catch ( Exception e ) {
			mLogger.error( Util.getTraceInformation( e ) );
			System.exit( 0 );
		}

		mLogger.trace( "end" );
		return -1;
	}

	private int ExecuteStatement( String aSql, int aReturnValueType )
	{
		mLogger.trace( "begin" );
		Statement lStmt = null;
		int lReturnValue = -1;
		try
		{
			lStmt = mConnection.createStatement();

			// The executeUpdate with statement parameter isn't implemented in SQLite
			lReturnValue = lStmt.executeUpdate( aSql/*, aReturnValueType*/ );

			if( aReturnValueType == Statement.RETURN_GENERATED_KEYS )
			{
				lReturnValue = GetSearchId( "select last_insert_rowid() as ID;" );
			}
			lStmt.close();
		}
		catch ( Exception e ) {
			mLogger.error( Util.getTraceInformation( e ) );
			System.exit( 0 );
		}
		mLogger.trace( "end" );
		return lReturnValue;
	}

	private void InitTables()
	{
		String aSql = "CREATE TABLE IF NOT EXISTS Favourites\n" +
				"";
		ExecuteStatement( aSql, Statement.CLOSE_ALL_RESULTS );
	}
}
