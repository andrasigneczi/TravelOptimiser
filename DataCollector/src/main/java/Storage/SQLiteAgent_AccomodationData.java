package Storage;

import PageGuest.AccomodationDataResultComposer;
import PageGuest.AccomodationData_RESULT;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Created by Andras on 14/07/2017.
 */
public class SQLiteAgent_AccomodationData
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(SQLiteAgent_AccomodationData.class);

	private AccomodationData_RESULT mResult;
	private AccomodationDataResultComposer_SQLite mComposer;
	private int mBookingComCount = 0;
	private int mAirbnbComCount = 0;
	private Connection mConnection = null;
	private SQLiteAgent mSQLiteAgent;

	public SQLiteAgent_AccomodationData( Connection connection, SQLiteAgent sqliteAgent )
	{
		mConnection = connection;
		mSQLiteAgent = sqliteAgent;
	}

	private int InsertNewSearch()
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.insertNewSearchString();

		mLogger.trace( lQuery );

		mLogger.trace( "end" );
		return mSQLiteAgent.ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private int GetAccomodationDataResultId( int aSearchId )
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.getAccomodationDataResultRecordIdString( aSearchId );
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

	private int InsertAccomodationDataResult( int aSearchId )
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.insertAccomodationDataResultString( aSearchId );

		mLogger.trace( lQuery );

		mLogger.trace( "end" );
		return mSQLiteAgent.ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private void InsertAccomodationDataResult_AvailableRooms( int aAccomodationDataResultId, String recordedDatetime )
	{
		mLogger.trace( "begin" );
		for( int i = 0; i < mResult.mAvailableRooms.size(); i++ )
		{
			String lQuery = mComposer.insertAccomodationDataResult_AvailableRooms( mResult.mAvailableRooms.get( i ),
					aAccomodationDataResultId,
					recordedDatetime );

			mLogger.trace( lQuery );

			mSQLiteAgent.ExecuteStatement( lQuery );
		}
		mLogger.trace( "end" );
	}

	void WriteData( AccomodationData_RESULT aResult )
	{
		mLogger.trace( "begin" );
		mComposer = (AccomodationDataResultComposer_SQLite) AccomodationDataResultComposer.Create( aResult, "sqlite" );
		mResult = aResult;

		int lSearchId = mSQLiteAgent.GetSearchId( mComposer.getSearchRecordIdString());
		if( lSearchId == -1 )
		{
			lSearchId = InsertNewSearch();
		}

		if( aResult.mType == 'B' )
			mBookingComCount++;
		else if( aResult.mType == 'A' )
			mAirbnbComCount++;

		int lAccomodationDataResultId =  GetAccomodationDataResultId( lSearchId );
		if( lAccomodationDataResultId == -1 )
		{
			lAccomodationDataResultId = InsertAccomodationDataResult( lSearchId );
		}
		InsertAccomodationDataResult_AvailableRooms( lAccomodationDataResultId, aResult.mRecordedDatetime );
		mLogger.trace( "end" );
	}

	public int getBookingDotComAccomodationCount()
	{
		return mBookingComCount;
	}
}
