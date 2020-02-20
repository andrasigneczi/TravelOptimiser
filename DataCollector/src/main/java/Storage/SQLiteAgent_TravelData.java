package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Created by Andras on 14/07/2017.
 */
public class SQLiteAgent_TravelData
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(SQLiteAgent_TravelData.class);

	private TravelData_RESULT mResult;
	private TravelDataResultComposer_SQLite mComposer;
	private int mWizzAirTripCount = 0;
	private int mRyanAirTripCount = 0;
	private Connection mConnection = null;
	private SQLiteAgent mSQLiteAgent;

	public SQLiteAgent_TravelData( Connection connection, SQLiteAgent sqliteAgent )
	{
		mConnection = connection;
		mSQLiteAgent = sqliteAgent;
	}

	public int getWizzAirTripCount() { return mWizzAirTripCount; }
	public int getRyanAirTripCount() { return mRyanAirTripCount; }

	private int GetTravelDataResultId( int aSearchId )
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.getTravelDataResultRecordIdString( aSearchId );
		Statement lStmt = null;

		mLogger.trace( lQuery );

		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() ) {
				lID = lResultSet.getInt("ID");
			}
			lResultSet.close();
			lStmt.close();
			mLogger.trace( "return" );
			return lID;
		}
		catch ( Exception e ) {
			//System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			mLogger.error( StringHelper.getTraceInformation( e ) );
			System.exit( 0 );
		}

		mLogger.trace( "end" );
		return -1;
	}

	private int InsertNewSearch()
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.insertNewSearchString();

		mLogger.trace( lQuery );

		mLogger.trace( "end" );
		return mSQLiteAgent.ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private int InsertTravelDataResult( int aSearchId )
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.insertTravelDataResultString( aSearchId );

		mLogger.trace( lQuery );

		mLogger.trace( "end" );
		return mSQLiteAgent.ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private void InsertTravelDataResult_PossibleTrips( int aTravelDataResultId, String recordedDatetime )
	{
		mLogger.trace( "begin" );
		for( int i = 0; i < mResult.mTrips.size(); i++ )
		{
			try
			{
				String lQuery = mComposer.insertTravelDataResult_PossibleTrips( mResult.mTrips.get( i ),
						aTravelDataResultId,
						recordedDatetime );

				mLogger.trace( lQuery );

				mSQLiteAgent.ExecuteStatement( lQuery );
			} catch (java.time.format.DateTimeParseException e) {
				mLogger.error(e.getMessage());
			}
		}
		mLogger.trace( "end" );
	}

	void WriteData( TravelData_RESULT aResult )
	{
		mLogger.trace( "begin" );
		mComposer = (TravelDataResultComposer_SQLite) TravelDataResultComposer.Create( aResult, "sqlite" );
		mResult = aResult;

		int lSearchId = mSQLiteAgent.GetSearchId( mComposer.getSearchRecordIdString());
		if( lSearchId == -1 )
		{
			lSearchId = InsertNewSearch();
		}

		if( aResult.mAirline.equalsIgnoreCase( "wizzair" ))
			mWizzAirTripCount++;
		else if( aResult.mAirline.equalsIgnoreCase( "ryanair" ))
			mRyanAirTripCount++;

		int lTravelDataResultId =  GetTravelDataResultId( lSearchId );
		if( lTravelDataResultId == -1 )
		{
			lTravelDataResultId = InsertTravelDataResult( lSearchId );
		}
		InsertTravelDataResult_PossibleTrips( lTravelDataResultId, aResult.mRecordedDatetime );
		mLogger.trace( "end" );

	}
}
