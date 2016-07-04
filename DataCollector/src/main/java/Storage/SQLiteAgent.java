package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import Util.Configuration;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.sql.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 * Created by Andras on 27/03/2016.
 */
public class SQLiteAgent extends ArchiverAgent
{
	private Connection mConnection = null;
	private TravelData_RESULT mResult;
	private TravelDataResultComposer_LiteSQL mComposer;
	private final static String mDatabaseFileName = "database";
	private final static String mDatabaseFileExtension = ".db";
	private final static String mDatabaseFullFileName = mDatabaseFileName + mDatabaseFileExtension;

	public void SQLiteAgent()
	{

	}

	private int GetSearchId()
	{
		return GetSearchId( null );
	}

	private int GetSearchId( String aQuery )
	{
		String lQuery;
		if( aQuery == null )
			lQuery = mComposer.getSearchRecordIdString();
		else
			lQuery = aQuery;

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
			return lID;
		}
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}

		return -1;
	}

	private int GetTravelDataResultId( int aSearchId )
	{
		String lQuery = mComposer.getTravelDataResultRecordIdString( aSearchId );
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
			return lID;
		}
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}

		return -1;
	}

	private int InsertNewSearch()
	{
		String lQuery = mComposer.insertNewSearchString();
		return ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private int InsertTravelDataResult( int aSearchId )
	{
		String lQuery = mComposer.insertTravelDataResultString( aSearchId );
		return ExecuteStatement( lQuery, Statement.RETURN_GENERATED_KEYS );
	}

	private void InsertTravelDataResult_PossibleTrips( int aTravelDataResultId )
	{
		for( int i = 0; i < mResult.mTrips.size(); i++ )
		{
			String lQuery = mComposer.insertTravelDataResult_PossibleTrips( mResult.mTrips.get( i ), aTravelDataResultId );
			ExecuteStatement( lQuery );
		}
	}

	protected void WriteData( TravelData_RESULT aResult )
	{
		mComposer = (TravelDataResultComposer_LiteSQL)TravelDataResultComposer.Create( aResult, "litesql" );
		mResult = aResult;

		int lSearchId = GetSearchId();
		if( lSearchId == -1 )
		{
			lSearchId = InsertNewSearch();
		}

		int lTravelDataResultId =  GetTravelDataResultId( lSearchId );
		if( lTravelDataResultId == -1 )
		{
			lTravelDataResultId = InsertTravelDataResult( lSearchId );
		}
		InsertTravelDataResult_PossibleTrips( lTravelDataResultId );
	}

	private int ExecuteStatement( String aSql )
	{
		return ExecuteStatement( aSql, Statement.EXECUTE_FAILED );
	}

	private int ExecuteStatement( String aSql, int aReturnValueType )
	{
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
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
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

	public void InitializeDatabase()
	{
		try {
			Class.forName("org.sqlite.JDBC");
			mConnection = DriverManager.getConnection("jdbc:sqlite:" + mDatabaseFullFileName );
			System.out.println("Opened database successfully");

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
					"\tOutboundTrip              TINYINT NOT NULL DEFAULT 0,\n" +
					"\tSearchDatetime            CHAR(19) NOT NULL,\n" +
					"\tTravelDataResult_ID       INTEGER NOT NULL,\n" +
					"\tFOREIGN KEY(TravelDataResult_ID) REFERENCES TravelDataResult(ID)\n" +
					");\n";

			ExecuteStatement( aSql );

		} catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		System.out.println("Table created successfully");
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

	public void ArchiveDatabaseFile()
	{
		Configuration lConfiguration = Configuration.getInstance();
		String lArchivedDatabaseFolder = lConfiguration.getValue( "/configuration/global/ArchivedDatabaseFolder", "" );
		String lNewDatabaseFullFileName = lArchivedDatabaseFolder + "\\" + mDatabaseFileName + "_"
				+ LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE_TIME).replace( ":", "" )
				+ mDatabaseFileExtension;
		try
		{
			Files.copy(new File(mDatabaseFullFileName).toPath(), new File(lNewDatabaseFullFileName).toPath());
		}
		catch( IOException e )
		{
			e.printStackTrace();
		}
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