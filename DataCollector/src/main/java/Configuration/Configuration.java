package Configuration;

import PageGuest.TravelData_INPUT;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;

/**
 * Created by Andras on 05/04/2016.
 */
public class Configuration
{
	private Object mMutex  = null;
	private static Configuration mInstance = null;

	private ArrayList<TravelData_INPUT> mSearchList = null;
	private ArrayList<TravelData_INPUT> mFlightList = null;
	private ArrayList<Recipient> mRecipientList = null;
	private Hashtable<String,String> mConfigValues;

	private HashSet<String> mValidAirlines = new HashSet<String>();
	private HashSet<String> mValidSearchNodes = new HashSet<String>();
	private HashSet<String> mValidFlightNodes = new HashSet<String>();


	private Configuration()
	{
		mMutex = new Object();

		mSearchList = new ArrayList<TravelData_INPUT>();
		mFlightList = new ArrayList<TravelData_INPUT>();
		mRecipientList = new ArrayList<Recipient>();

		mConfigValues = new Hashtable<String, String>(  );

		mValidAirlines.add( "wizzair" );
		mValidAirlines.add( "ryanair" );

		mValidSearchNodes.add( "LeavingFrom" );
		mValidSearchNodes.add( "GoingTo" );
		mValidSearchNodes.add( "DepartureDay" );
		mValidSearchNodes.add( "ReturnDay" );
		mValidSearchNodes.add( "AdultNumber" );
		mValidSearchNodes.add( "ChildNumber" );
		mValidSearchNodes.add( "InfantNumber" );
		mValidSearchNodes.add( "NearbyAirports" );
		mValidSearchNodes.add( "ReturnTicket" );

		mValidFlightNodes.add( "LeavingFrom" );
		mValidFlightNodes.add( "GoingTo" );
		mValidFlightNodes.add( "Filter" );
		mValidFlightNodes.add( "Interval" );

		ParseConfigurationFile();
	}

	public static Configuration getInstance()
	{
		if (mInstance != null)
		{
			return mInstance;
		}

		synchronized(Configuration.class)
		{
			if (mInstance != null)
			{
				return mInstance;
			}
			mInstance = new Configuration();
		}
		return mInstance;
	}

	public String getValue( String aPath, String aDefaultValue )
	{
		String lReturn = mConfigValues.get( aPath );
		if( lReturn == null )
			return aDefaultValue;
		return lReturn;
	}

	public int getIntValue( String aPath, String aDefaultValue ) throws NumberFormatException
	{
		String lReturn = mConfigValues.get( aPath );
		if( lReturn == null )
			return Integer.parseInt( aDefaultValue );
		return Integer.parseInt( lReturn );
	}

	private void ParseConfigurationFile()
	{
		try {

			SAXParserFactory factory = SAXParserFactory.newInstance();
			SAXParser saxParser = factory.newSAXParser();

			DefaultHandler handler = new ConfigurationHandler( this
					, "/configuration/searches/"
					, "/configuration/flights/"
					, "/configuration/emails/");

			//File file = new File("test.xml");
			//InputStream inputStream= new FileInputStream(file);
			InputStream inputStream = getClass().getClassLoader().getResourceAsStream( "config.xml" );
			Reader reader = new InputStreamReader(inputStream,"UTF-8");

			InputSource is = new InputSource(reader);
			is.setEncoding("UTF-8");

			saxParser.parse(is, handler);


		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	public ArrayList<TravelData_INPUT> getSearchList()
	{
		ArrayList<TravelData_INPUT> lSearchList = new ArrayList<TravelData_INPUT>();
		for( TravelData_INPUT lTDI : mSearchList )
		{
			TravelData_INPUT lClone = null;
			try
			{
				lClone = (TravelData_INPUT)lTDI.clone();
			}
			catch( CloneNotSupportedException e )
			{
				e.printStackTrace();
			}
			lSearchList.add( lClone );
		}
		return lSearchList;
	}

	public ArrayList<TravelData_INPUT> getFlightList()
	{
		ArrayList<TravelData_INPUT> lFlightList = new ArrayList<TravelData_INPUT>();
		for( TravelData_INPUT lTDI : mFlightList )
		{
			TravelData_INPUT lClone = null;
			try
			{
				lClone = (TravelData_INPUT)lTDI.clone();
			}
			catch( CloneNotSupportedException e )
			{
				e.printStackTrace();
			}
			lFlightList.add( lClone );
		}
		return lFlightList;
	}

	public ArrayList<Recipient> getRecipientList()
	{
		ArrayList<Recipient> lRecipientList = new ArrayList<Recipient>();
		for( Recipient lRecipient : mRecipientList )
		{
			Recipient lClone = null;
			try
			{
				lClone = (Recipient)lRecipient.clone();
			}
			catch( CloneNotSupportedException e )
			{
				e.printStackTrace();
			}
			lRecipientList.add( lClone );
		}
		return lRecipientList;
	}

	public HashSet<String> getValidAirlines()
	{
		return mValidAirlines;
	}

	public HashSet<String> getValidSearchNodes()
	{
		return mValidSearchNodes;
	}

	public HashSet<String> getValidFlightNodes()
	{
		return mValidFlightNodes;
	}

	public void put( String aPath, String aNodeValue )
	{
		mConfigValues.put( aPath, aNodeValue );
	}

	public void addShearchItem( TravelData_INPUT aTDI )
	{
		mSearchList.add( aTDI );
	}
	public void addFlightItem( TravelData_INPUT aTDI )
	{
		mFlightList.add( aTDI );
	}
	public void addRecipientItem( Recipient aR )
	{
		mRecipientList.add( aR );
	}
}
