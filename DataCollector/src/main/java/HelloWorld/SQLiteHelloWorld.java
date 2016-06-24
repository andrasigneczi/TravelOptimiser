package HelloWorld;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Created by andras.igneczi on 25/03/2016.
 */
public class SQLiteHelloWorld
{
    public static void Test1( String args[] )
    {
        Connection c = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Opened database successfully");
    }

    public static void Test2( String args[] )
    {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            System.out.println("Opened database successfully");

            stmt = c.createStatement();
            String sql = "CREATE TABLE COMPANY " +
                    "(ID INT PRIMARY KEY     NOT NULL," +
                    " NAME           TEXT    NOT NULL, " +
                    " AGE            INT     NOT NULL, " +
                    " ADDRESS        CHAR(50), " +
                    " SALARY         REAL)";
            stmt.executeUpdate(sql);
            stmt.close();
            c.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Table created successfully");
    }

    public static void Test3( String args[] )
    {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            c.setAutoCommit(false);
            System.out.println("Opened database successfully");

            stmt = c.createStatement();
            String sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) " +
                    "VALUES (1, 'Paul', 32, 'California', 20000.00 );";
            stmt.executeUpdate(sql);

            sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) " +
                    "VALUES (2, 'Allen', 25, 'Texas', 15000.00 );";
            stmt.executeUpdate(sql);

            sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) " +
                    "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );";
            stmt.executeUpdate(sql);

            sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) " +
                    "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
            stmt.executeUpdate(sql);

            stmt.close();
            c.commit();
            c.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Records created successfully");
    }

    public static void Test4( String args[] )
    {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            c.setAutoCommit(false);
            System.out.println("Opened database successfully");

            stmt = c.createStatement();
            ResultSet rs = stmt.executeQuery( "SELECT * FROM COMPANY;" );
            while ( rs.next() ) {
                int id = rs.getInt("id");
                String  name = rs.getString("name");
                int age  = rs.getInt("age");
                String  address = rs.getString("address");
                float salary = rs.getFloat("salary");
                System.out.println( "ID = " + id );
                System.out.println( "NAME = " + name );
                System.out.println( "AGE = " + age );
                System.out.println( "ADDRESS = " + address );
                System.out.println( "SALARY = " + salary );
                System.out.println();
            }
            rs.close();
            stmt.close();
            c.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Operation done successfully");
    }

    public static void Test5( String args[] )
    {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            c.setAutoCommit(false);
            System.out.println("Opened database successfully");

            stmt = c.createStatement();
            String sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1;";
            stmt.executeUpdate(sql);
            c.commit();

            ResultSet rs = stmt.executeQuery( "SELECT * FROM COMPANY;" );
            while ( rs.next() ) {
                int id = rs.getInt("id");
                String  name = rs.getString("name");
                int age  = rs.getInt("age");
                String  address = rs.getString("address");
                float salary = rs.getFloat("salary");
                System.out.println( "ID = " + id );
                System.out.println( "NAME = " + name );
                System.out.println( "AGE = " + age );
                System.out.println( "ADDRESS = " + address );
                System.out.println( "SALARY = " + salary );
                System.out.println();
            }
            rs.close();
            stmt.close();
            c.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Operation done successfully");
    }

    public static void Test6( String args[] )
    {
        Connection c = null;
        Statement stmt = null;
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            c.setAutoCommit(false);
            System.out.println("Opened database successfully");

            stmt = c.createStatement();
            String sql = "DELETE from COMPANY where ID=2;";
            stmt.executeUpdate(sql);
            c.commit();

            ResultSet rs = stmt.executeQuery( "SELECT * FROM COMPANY;" );
            while ( rs.next() ) {
                int id = rs.getInt("id");
                String  name = rs.getString("name");
                int age  = rs.getInt("age");
                String  address = rs.getString("address");
                float salary = rs.getFloat("salary");
                System.out.println( "ID = " + id );
                System.out.println( "NAME = " + name );
                System.out.println( "AGE = " + age );
                System.out.println( "ADDRESS = " + address );
                System.out.println( "SALARY = " + salary );
                System.out.println();
            }
            rs.close();
            stmt.close();
            c.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }
        System.out.println("Operation done successfully");
    }

    public static void Test7()
    {
        try
        {
            Class.forName("org.sqlite.JDBC");
            Connection mConnection = DriverManager.getConnection("jdbc:sqlite:test.db");
            System.out.println("Opened database successfully");

            Statement stmt = mConnection.createStatement();
            stmt.executeUpdate("drop table Search;");

            String lSql = "CREATE TABLE IF NOT EXISTS Search\n" +
                    "(\n" +
                    "\tID                      INTEGER PRIMARY KEY NOT NULL,\n" +
                    "\tAirportCode_LeavingFrom CHAR(3)  NOT NULL,\n" +
                    "\tAirportCode_GoingTo     CHAR(3)  NOT NULL,\n" +
                    "\tDepartureDay            CHAR(10) NOT NULL,\n" +
                    "\tReturnDay               CHAR(10),\n" +
                    "\tAdultNumber             TINYINT NOT NULL DEFAULT 1,\n" +
                    "\tChildNumber             TINYINT NOT NULL DEFAULT 0,\n" +
                    "\tInfantNumber            TINYINT NOT NULL DEFAULT 0,\n" +
                    "\tNearbyAirports          TINYINT NOT NULL DEFAULT 0\n" +
                    ");\n";

            stmt.executeUpdate(lSql);


            lSql = "INSERT INTO Search(\n" +
                    "AirportCode_LeavingFrom,\n" +
                    "AirportCode_GoingTo,\n" +
                    "DepartureDay,\n" +
                    "ReturnDay,\n" +
                    "AdultNumber,\n" +
                    "ChildNumber,\n" +
                    "InfantNumber,\n" +
                    "NearbyAirports)\n" +
                    "VALUES(\n" +
                    "'HHN', 'BUD', '" + Util.StringHelper.escapeSQL( "-1%='1-" ) + "', '2016-11-12', '1', '1', '1', '0'" +
                    ");\n";

            stmt.executeUpdate(lSql);


            lSql = "SELECT ID FROM Search WHERE AirportCode_LeavingFrom='" + "HHN" + "' " +
                    "AND AirportCode_GoingTo='" + "BUD" + "' " +
                    "AND DepartureDay='" + "2016-10-11" + "' "+
                    "AND ReturnDay='" + "2016-10-13" + "' " +
                    "AND AdultNumber='" + "1" + "' " +
                    "AND ChildNumber='" + "1" + "' " +
                    "AND InfantNumber='" + "1" + "' " +
                    "AND NearbyAirports='" + "1" + "';";
            ResultSet rs = stmt.executeQuery( lSql );
            while ( rs.next() )
            {
                int id = rs.getInt( "id" );
            }
            rs.close();
            stmt.close();
            mConnection.close();
        }
        catch( Exception e )
        {
            e.printStackTrace();
        }

    }

}
