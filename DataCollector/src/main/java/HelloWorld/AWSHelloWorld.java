package HelloWorld;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.sql.*;

public class AWSHelloWorld
{
    public static void main(String ... argv)
    {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs   = null;

        try
        {
            final String lHost = "andras-igneczi-mysql-micro-db.cxkiqyh1dwzc.eu-central-1.rds.amazonaws.com";
            final int lPort = 3306;

            //Socket lSocket = new Socket( lHost, lPort );
            Socket lSocket = new Socket( "www.index.hu", 80 );
            lSocket.close();

            conn = DriverManager.getConnection("jdbc:driver://hostname:port/dbName?user=userName&password=password");


            stmt = conn.createStatement();
            //rs = stmt.executeQuery("SELECT * FROM bar");

            // or alternatively, if you don't know ahead of time that
            // the query will be a SELECT...

            if (stmt.execute("show tables")) {
                rs = stmt.getResultSet();
            }
        }
        catch (SQLException ex)
        {
            // handle any errors
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
        }
        catch( UnknownHostException e )
        {
            e.printStackTrace();
        }
        catch( IOException e )
        {
            e.printStackTrace();
        }
        finally {
            // it is a good idea to release
            // resources in a finally{} block
            // in reverse-order of their creation
            // if they are no-longer needed

            if (rs != null) {
                try {
                    rs.close();
                } catch (SQLException sqlEx) { } // ignore

                rs = null;
            }

            if (stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException sqlEx) { } // ignore

                stmt = null;
            }
        }
    }
}
