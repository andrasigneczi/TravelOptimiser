package Util;

import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.sql.*;
import java.util.Hashtable;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Created by Andras on 13/04/2016.
 */
public class SQLiteDataProvider implements DataProvider
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(SQLiteDataProvider.class);

	private static SQLiteDataProvider mInstance = null;
	private Connection mConnection = null;
	private SQLiteComposer mComposer = null;
	private final static String mDatabaseFileName = "database";
	private final static String mDatabaseFileExtension = ".db";
	private final static String mDatabaseFullFileName = mDatabaseFileName + mDatabaseFileExtension;
	private String mOpenedDatabaseFileName = null;

	private SQLiteDataProvider()
	{
		try
		{
			Configuration lConfiguration = Configuration.getInstance();
			String lArchivedDatabaseFolder = lConfiguration.getValue( "/configuration/global/ArchivedDatabaseFolder", "" );

			String lDatabaseFileName = SearchLatestDatabaseFile( lArchivedDatabaseFolder );
			if( lDatabaseFileName == null )
				lDatabaseFileName = mDatabaseFullFileName;
			ConnectionOpen( lDatabaseFileName );
		}
		catch ( Exception e )
		{
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

	private void ConnectionOpen( String aDatabaseFileName ) throws ClassNotFoundException, SQLException
	{
		Class.forName("org.sqlite.JDBC");
		mConnection = DriverManager.getConnection( "jdbc:sqlite:" + aDatabaseFileName );
		mOpenedDatabaseFileName = aDatabaseFileName;
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

	/**
	 *
	 * @param aDateTime
	 * @param aAirline
	 * @param aAirportFrom
	 * @param aAirportTo
	 * @param aDRComposer
	 * @return
	 */
	public Hashtable<String,String> GetTripData( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, DataResultComposer aDRComposer )
	{
		Hashtable<String,String> lReturnData = new Hashtable<String,String>();
		String lQuery;
		lQuery = mComposer.GetTripQuery( aDateTime, aAirline, aAirportFrom, aAirportTo);

		String lAirportCode_LeavingFrom = "";
		String lAirportCode_GoingTo = "";
		String lAirline = "";

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				if( lAirportCode_LeavingFrom.length() == 0 )
					lAirportCode_LeavingFrom = lResultSet.getString( "AirportCode_LeavingFrom" );
				else if( !lAirportCode_LeavingFrom.equals( lResultSet.getString( "AirportCode_LeavingFrom" ) ))
					mLogger.warn( "'AirportCode_LeavingFrom' inconsistency?!" );

				if( lAirportCode_GoingTo.length() == 0 )
					lAirportCode_GoingTo = lResultSet.getString( "AirportCode_GoingTo" );
				else if( !lAirportCode_GoingTo.equals( lResultSet.getString( "AirportCode_GoingTo" ) ))
					mLogger.warn( "'AirportCode_GoingTo' inconsistency?!" );

				if( lAirline.length() == 0 )
					lAirline = lResultSet.getString( "Airline" );
				else if( !lAirline.equals( lResultSet.getString( "Airline" )))
					mLogger.warn( "'Airline' inconsistency?!" );

				String lPrice = lResultSet.getString( "Prices_BasicFare_Discount");
				if( lPrice.length() == 0 )
					lPrice = lResultSet.getString( "Prices_BasicFare_Normal");

				Float lCurrencyPriceInEuro = lResultSet.getFloat( "Currency_Price_In_Euro" );
				if( lResultSet.wasNull())
					lCurrencyPriceInEuro = null;
				aDRComposer.add( lResultSet.getString( "SearchDatetime" ), lPrice, lCurrencyPriceInEuro );
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			mLogger.error( "Trip data processing threw an exception: " + Util.getTraceInformation( e ) );
			System.exit( 0 );
		}

		lReturnData.put( "Result", aDRComposer.getResult());
		lReturnData.put( "Airline", lAirline );
		lReturnData.put( "AirportCode_LeavingFrom", lAirportCode_LeavingFrom );
		lReturnData.put( "AirportCode_GoingTo", lAirportCode_GoingTo );

		return lReturnData;
	}

	/**
	 *
	 * @param aHtmlListFormatter
	 * @param aSelectedDepartureAirport
	 * @param aSelectedArrivalAirport
	 * @param aReturnCheckboxChecked
	 * @return
	 */
	public String GetCollectedDepartureDateList( HtmlListFormatter aHtmlListFormatter,
	                                             String  aSelectedDepartureAirport,
	                                             String  aSelectedArrivalAirport,
	                                             boolean aReturnCheckboxChecked,
	                                             String  aOutboundDate,
	                                             String  aInboundDate )
	{
		String lQuery;
		lQuery = mComposer.GetTripDateListQuery( aSelectedDepartureAirport, aSelectedArrivalAirport,
				aReturnCheckboxChecked, aOutboundDate, aInboundDate );

		Statement lStmt = null;
		try
		{
			int lID = -1;
			lStmt = mConnection.createStatement();
			ResultSet lResultSet = lStmt.executeQuery( lQuery );
			while ( lResultSet.next() )
			{
				aHtmlListFormatter.add(
						new String[]{
								lResultSet.getString( "DepartureDatetime" ),
								lResultSet.getString( "Airline" ),
								lResultSet.getString( "AirportCode_LeavingFrom" ),
								lResultSet.getString( "AirportCode_GoingTo" ),
								lResultSet.getString( "OutboundTrip" )
						});
			}
			lResultSet.close();
			lStmt.close();
		}
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aHtmlListFormatter.getFormattedResult();
	}

	/**
	 *
	 * @param aDepartureAirportListFormatter
	 * @param aSelectedDepartureAirport
	 * @return
	 */
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
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aDepartureAirportListFormatter.getFormattedResult();
	}

	/**
	 *
	 * @param aArrivalAirportListFormatter
	 * @param aSelectedDepartureAirport
	 * @param aSelectedArrivalAirport
	 * @return
	 */
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
		catch ( Exception e )
		{
			System.err.println( e.getClass().getName() + ": " + e.getMessage() );
			System.exit( 0 );
		}
		return aArrivalAirportListFormatter.getFormattedResult();
	}

	/**
	 * It exists in the DataCollector too!
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
					.filter(path -> path.matches("^.*\\\\database_\\d{4}-\\d{2}-\\d{2}T\\d{6}(\\.\\d{1,3})?\\.db$"))
					.sorted()
					.collect( Collectors.joining(lItemSeparator));
			lFileList = lJoinedString.split( lItemSeparator );
		}

		if( lFileList == null || lFileList.length == 0 )
			return null;

		// 20 database file backup is enough
		for( int i = 0; i < lFileList.length - 20; i++ )
			Files.delete( new File(lFileList[ i ]).toPath() );

		return lFileList[ lFileList.length - 1 ];
	}

	public void OpenANewerDatabaseFile()
	{
		Configuration lConfiguration = Configuration.getInstance();
		String lArchivedDatabaseFolder = lConfiguration.getValue( "/configuration/global/ArchivedDatabaseFolder", "" );
		String lDatabaseFileName = null;

		try
		{
			lDatabaseFileName = SearchLatestDatabaseFile( lArchivedDatabaseFolder );
		}
		catch (IOException aException)
		{
			mLogger.error( "SearchLatestDatabaseFile threw an exception: " + Util.getTraceInformation( aException ) );
			return;
		}

		if( lDatabaseFileName == null || mOpenedDatabaseFileName == null || lDatabaseFileName.equals( mOpenedDatabaseFileName ) )
			return;

		if( lDatabaseFileName.compareToIgnoreCase(mOpenedDatabaseFileName) <= 0 )
			return;

		ConnectionClose();

		try
		{
			ConnectionOpen( lDatabaseFileName );
		}
		catch (SQLException aException)
		{
			mLogger.error( "Open database threw an exception: " + Util.getTraceInformation( aException ) );
		}
		catch( ClassNotFoundException e )
		{
			mLogger.error( "Open database threw an exception: " + Util.getTraceInformation( e ) );
		}
	}
}
