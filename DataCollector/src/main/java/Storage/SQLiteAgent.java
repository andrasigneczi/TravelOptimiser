package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import Configuration.Configuration;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.sql.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Created by Andras on 27/03/2016.
 */
public class SQLiteAgent extends ArchiverAgent
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(SQLiteAgent.class);

	private Connection mConnection = null;
	private TravelData_RESULT mResult;
	private TravelDataResultComposer_SQLite mComposer;
	private final static String mDatabaseFileName = "database";
	private final static String mDatabaseFileExtension = ".db";
	private final static String mDatabaseFullFileName = mDatabaseFileName + mDatabaseFileExtension;
	private String mOpenedDatabaseFileName = null;
	private int mWizzAirTripCount = 0;
	private int mRyanAirTripCount = 0;

	public void SQLiteAgent()
	{

	}

	public int getWizzAirTripCount() { return mWizzAirTripCount; }
	public int getRyanAirTripCount() { return mRyanAirTripCount; }

	private int GetSearchId()
	{
		return GetSearchId( null );
	}

	private int GetSearchId( String aQuery )
	{
		mLogger.trace( "begin" );

		String lQuery;
		if( aQuery == null )
			lQuery = mComposer.getSearchRecordIdString();
		else
			lQuery = aQuery;

		mLogger.trace( lQuery );

		Statement lStmt = null;
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
		return ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private int InsertTravelDataResult( int aSearchId )
	{
		mLogger.trace( "begin" );
		String lQuery = mComposer.insertTravelDataResultString( aSearchId );

		mLogger.trace( lQuery );

		mLogger.trace( "end" );
		return ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private void InsertTravelDataResult_PossibleTrips( int aTravelDataResultId, String recordedDatetime )
	{
		mLogger.trace( "begin" );
		for( int i = 0; i < mResult.mTrips.size(); i++ )
		{
			String lQuery = mComposer.insertTravelDataResult_PossibleTrips( mResult.mTrips.get( i ),
					aTravelDataResultId,
					recordedDatetime );

			mLogger.trace( lQuery );

			ExecuteStatement( lQuery );
		}
		mLogger.trace( "end" );
	}

	protected void WriteData( TravelData_RESULT aResult )
	{
		mLogger.trace( "begin" );
		mComposer = (TravelDataResultComposer_SQLite)TravelDataResultComposer.Create( aResult, "sqlite" );
		mResult = aResult;

		int lSearchId = GetSearchId();
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

	private int ExecuteStatement( String aSql )
	{
		return ExecuteStatement( aSql, Statement.EXECUTE_FAILED );
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
			//System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			mLogger.error( StringHelper.getTraceInformation( e ) );
			System.exit( 0 );
		}
		mLogger.trace( "end" );
		return lReturnValue;
	}

	public void DropEverything()
	{
		ExecuteStatement("DROP TABLE IF EXISTS Search;");
		ExecuteStatement("DROP TABLE IF EXISTS TravelDataResult;");
		ExecuteStatement("DROP TABLE IF EXISTS TravelDataResult_PossibleTrips;");
		ExecuteStatement("DROP INDEX IF EXISTS SearchIndex;");
		ExecuteStatement("DROP INDEX IF EXISTS TravelDataResultIndex;");
	}

	/**
	 * It exists in the Webhost too!
	 * @param aPath
	 * @return
	 * @throws IOException
	 */
	private static String SearchLatestDatabaseFile( String aPath ) throws IOException
	{
		String lJoinedString;
		final String lItemSeparator = "::";
		String[] lFileList = null;
		try (Stream<Path> stream = Files.list( Paths.get( aPath )))
		{
			lJoinedString = stream
					.map(String::valueOf)
					.filter(path -> path.matches("^.*\\\\database_\\d{4}-\\d{2}-\\d{2}T\\d{6}\\.\\d{1,3}\\.db$"))
					.sorted()
					.collect( Collectors.joining(lItemSeparator));
			lFileList = lJoinedString.split( lItemSeparator );
		}

		if( lFileList == null || lFileList.length == 0 )
			return null;

		// 20 database file backup is enough
		for( int i = 0; i < lFileList.length - 20; i++ )
			Files.delete( new File(lFileList[ i ]).toPath() );

		if( lFileList[ lFileList.length - 1 ].length() == 0 )
			return null;

		return lFileList[ lFileList.length - 1 ];
	}

	public void InitializeDatabase()
	{
		try {
			Configuration lConfiguration = Configuration.getInstance();
			String lArchivedDatabaseFolder = lConfiguration.getValue( "/configuration/global/ArchivedDatabaseFolder", "" );

			String lDatabaseFileName = SearchLatestDatabaseFile( lArchivedDatabaseFolder );
			if( lDatabaseFileName == null )
				lDatabaseFileName = mDatabaseFullFileName;
			ConnectionOpen( lDatabaseFileName );

			//DropEverything();

			String aSql = "CREATE TABLE IF NOT EXISTS Search\n" +
					"(\n" +
					"\tID                      INTEGER PRIMARY KEY NOT NULL,\n" +
					"\tAirportCode_LeavingFrom CHAR(3)  NOT NULL,\n" +
					"\tAirportCode_GoingTo     CHAR(3)  NOT NULL,\n" +
					"\tDepartureDay            CHAR(11) NOT NULL,\n" + // 2016.03.03.
					"\tReturnDay               CHAR(11),\n" +
					"\tAdultNumber             TINYINT NOT NULL DEFAULT 1,\n" +
					"\tChildNumber             TINYINT NOT NULL DEFAULT 0,\n" +
					"\tInfantNumber            TINYINT NOT NULL DEFAULT 0,\n" +
					"\tNearbyAirports          TINYINT NOT NULL DEFAULT 0\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE INDEX IF NOT EXISTS SearchIndex ON Search (AirportCode_LeavingFrom, AirportCode_GoingTo, DepartureDay, ReturnDay, " +
					"AdultNumber, ChildNumber, InfantNumber, NearbyAirports );";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS TravelDataResult\n" +
					"(\n" +
					"\tID                      INTEGER PRIMARY KEY NOT NULL,\n" +
					"\tAirline                 CHAR(100),\n" +
					"\tAirportCode_LeavingFrom CHAR(3),\n" +
					"\tAirportCode_GoingTo     CHAR(3),\n" +
					"\tSearch_ID               INTEGER NOT NULL,\n" +
					"\tFOREIGN KEY(Search_ID) REFERENCES Search(ID)\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE INDEX IF NOT EXISTS TravelDataResultIndex ON TravelDataResult (Airline,AirportCode_LeavingFrom, " +
					"AirportCode_GoingTo, Search_ID );";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS TravelDataResult_PossibleTrips\n" +
					"(\n" +
					"\tID                        INTEGER PRIMARY KEY NOT NULL,\n" +
					"\tDepartureDatetime         CHAR(16) NOT NULL,\n" +     // 2016.03.25 17:10
					"\tArrivalDatetime           CHAR(16) NOT NULL,\n" +     // 2016.03.25 22:10
					"\tPrices_BasicFare_Normal   FLOAT NOT NULL,\n" +
					"\tPrices_BasicFare_Discount FLOAT,\n" +
					"\tPrices_PlusFare_Normal    FLOAT,\n" +
					"\tPrices_PlusFare_Discount  FLOAT,\n" +
					"\tCurrency_Price_In_Euro    FLOAT,\n" +
					"\tOutboundTrip              TINYINT NOT NULL DEFAULT 0,\n" +
					"\tSearchDatetime            CHAR(19) NOT NULL,\n" +
					"\tTravelDataResult_ID       INTEGER NOT NULL,\n" +
					"\tFOREIGN KEY(TravelDataResult_ID) REFERENCES TravelDataResult(ID)\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS Flat (\n" +
					"ID       INTEGER PRIMARY KEY NOT NULL,\n" +
					"Type     CHAR, /*room=R,apartment=A,hotelroom=H*/\n" +
					"Name     CHAR(128) UNIQUE,\n" +
					"Site     CHAR, /*booking.com=B, airbnb.com=A*/\n" +
					"URL      CHAR(1024),\n" +
					"CheckIn  CHAR(50),\n" +
					"CheckOut CHAR(50),\n" +
					"Price    FLOAT,\n" +
					"Adult    TINYINT,\n" +
					"Children TINYINT\n" +
					");";

			ExecuteStatement( aSql );

		} catch ( Exception e ) {
			//System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			mLogger.error( StringHelper.getTraceInformation( e ) );
			System.exit( 0 );
		}
		System.out.println("Table created successfully");
	}

	private void ConnectionOpen( String aDatabaseFileName ) throws ClassNotFoundException, SQLException
	{
		Class.forName("org.sqlite.JDBC");
		mConnection = DriverManager.getConnection( "jdbc:sqlite:" + aDatabaseFileName );
		mOpenedDatabaseFileName = aDatabaseFileName;
	}

	public void ConnectionClose()
	{
		try
		{
			if( mConnection != null )
			{
				mConnection.close();
				mConnection = null;
			}
		}
		catch( SQLException e )
		{
			//e.printStackTrace();
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
	}

	public void ArchiveDatabaseFile()
	{
		Configuration lConfiguration = Configuration.getInstance();
		String lArchivedDatabaseFolder = lConfiguration.getValue( "/configuration/global/ArchivedDatabaseFolder", "" );
		String lNewDatabaseFullFileName = lArchivedDatabaseFolder + "\\" + mDatabaseFileName + "_"
				+ LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME).replace( ":", "" )
				+ mDatabaseFileExtension;
		try
		{
			ConnectionClose();
			final String lDatabaseFullFileName;
			if( mOpenedDatabaseFileName != null )
				lDatabaseFullFileName = mOpenedDatabaseFileName;
			else
				lDatabaseFullFileName = mDatabaseFullFileName;

			Files.copy(new File(lDatabaseFullFileName).toPath(), new File(lNewDatabaseFullFileName).toPath());
		}
		catch( IOException e )
		{
			//e.printStackTrace();
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
	}

	public ResultSet Query( String query )
	{
		mLogger.trace( "Query begin" );
		Statement lStmt = null;
		mLogger.trace( query );
		HashMap<String,String> result = new HashMap<>();
		try
		{
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( query );
			while ( lResultSet.next() ) {
				//lID = lResultSet.getInt("ID");
				return lResultSet;
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e ) {
			//System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}

		mLogger.trace( "end" );
		return null;
	}
}

/*

CREATE TABLE Search
(
	ID                      INT PRIMARY KEY NOT NULL,
	AirportCode_LeavingFrom CHAR(3)  NOT NULL,
	AirportCode_GoingTo     CHAR(3)  NOT NULL,
	DepartureDay            CHAR(10) NOT NULL,
	ReturnDay               CHAR(10),
	AdultNumber             TINYINT NOT NULL DEFAULT 1,
	ChildNumber             TINYINT NOT NULL DEFAULT 0,
	InfantNumber            TINYINT NOT NULL DEFAULT 0,
	NearbyAirports          TINYINT NOT NULL DEFAULT 0
);

CREATE TABLE TravelDataResult
(
	ID INT PRIMARY KEY      NOT NULL,
	Airline                 CHAR(100),
	AirportCode_LeavingFrom CHAR(3),
	AirportCode_GoingTo     CHAR(3)
);

CREATE TABLE TravelDataResult_PossibleTrips
(
	ID INT PRIMARY KEY        NOT NULL,
	DepartureDaytime CHAR(16) NOT NULL,    // 2016.03.25 17:10
	ArrivalDaytime   CHAR(16) NOT NULL,    // 2016.03.25 22:10
	Prices_BasicFare_Normal   FLOAT NOT NULL,
	Prices_BasicFare_Discount FLOAT,
	Prices_PlusFare_Normal    FLOAT,
	Prices_PlusFare_Discount  FLOAT,
	OutboundTrip              TINYINT NOT NULL DEFAULT 0
);

 */