package Storage;

import PageGuest.TravelData_RESULT;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Created by Andras on 27/03/2016.
 */
public class SQLiteAgent extends ArchiverAgent
{
	Connection mConnection = null;
	public void SQLiteAgent()
	{

	}

	protected void WriteData( TravelData_RESULT aResult )
	{
		TravelDataResultComposer_SQL lComposer = new TravelDataResultComposer_SQL( aResult );
		ExecuteStatement( lComposer.toFormattedString());
	}

	private void ExecuteStatement( String aSql )
	{
		Statement stmt = null;
		try
		{
			stmt = mConnection.createStatement();
			stmt.executeUpdate( aSql );
			stmt.close();
		}
		catch ( Exception e ) {
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
	}

	public void InitializeDatabase()
	{
		try {
			Class.forName("org.sqlite.JDBC");
			mConnection = DriverManager.getConnection("jdbc:sqlite:test.db");
			System.out.println("Opened database successfully");

			String aSql = "CREATE TABLE IF NOT EXISTS Search\n" +
					"(\n" +
					"\tID                      INT PRIMARY KEY NOT NULL,\n" +
					"\tAirportCode_LeavingFrom CHAR(3)  NOT NULL,\n" +
					"\tAirportCode_GoingTo     CHAR(3)  NOT NULL,\n" +
					"\tDepartureDay            CHAR(10) NOT NULL,\n" +
					"\tReturnDay               CHAR(10),\n" +
					"\tAdultNumber             TINYINT NOT NULL DEFAULT 1,\n" +
					"\tChildNumber             TINYINT NOT NULL DEFAULT 0,\n" +
					"\tInfantNumber            TINYINT NOT NULL DEFAULT 0,\n" +
					"\tNearbyAirports          TINYINT NOT NULL DEFAULT 0\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS Search_datetime\n" +
					"(\n" +
					"\tID                      INT PRIMARY KEY NOT NULL,\n" +
					"\tSearchDatetime          CHAR(19) NOT NULL,\n" +
					"\tSearch_ID               INT NOT NULL,\n" +
					"\tFOREIGN KEY(Search_ID) REFERENCES Search(ID)\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS TravelDataResult\n" +
					"(\n" +
					"\tID INT PRIMARY KEY      NOT NULL,\n" +
					"\tAirline                 CHAR(100),\n" +
					"\tAirportCode_LeavingFrom CHAR(3),\n" +
					"\tAirportCode_GoingTo     CHAR(3),\n" +
					"\tSearch_ID               INT NOT NULL,\n" +
					"\tFOREIGN KEY(Search_ID) REFERENCES Search(ID)\n" +
					");\n";

			ExecuteStatement( aSql );

			aSql = "CREATE TABLE IF NOT EXISTS TravelDataResult_PossibleTrips\n" +
					"(\n" +
					"\tID INT PRIMARY KEY        NOT NULL,\n" +
					"\tDepartureDatetime CHAR(16) NOT NULL,\n" +     // 2016.03.25 17:10
					"\tArrivalDatetime   CHAR(16) NOT NULL,\n" +     // 2016.03.25 22:10
					"\tPrices_BasicFare_Normal   FLOAT NOT NULL,\n" +
					"\tPrices_BasicFare_Discount FLOAT,\n" +
					"\tPrices_PlusFare_Normal    FLOAT,\n" +
					"\tPrices_PlusFare_Discount  FLOAT,\n" +
					"\tOutboundTrip              TINYINT NOT NULL DEFAULT 0,\n" +
					"\tTravelDataResult_ID       INT NOT NULL,\n" +
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