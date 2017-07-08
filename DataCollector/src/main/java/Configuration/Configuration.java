package Configuration;

import PageGuest.AccomodationData_INPUT;
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

	private ArrayList<TravelData_INPUT> mSearchListAirlines = null; // <searches><wizzair></wizzair><ryanair></ryanair>...</searches>
	private ArrayList<TravelData_INPUT> mFlightList = null; // <flights>...</flights>
	private ArrayList<AccomodationData_INPUT> mSearchListAccom = null; // <searches><bookingdotcom></bookingdotcom><airbnb></airbnb>...</searches>
	private ArrayList<Recipient> mRecipientList = null;
	private Hashtable<String,String> mConfigValues;

	private HashSet<String> mValidAirlines = new HashSet<String>();
	private HashSet<String> mValidSearchAirlineNodes = new HashSet<String>();
	private HashSet<String> mValidSearchAccomodationNodes = new HashSet<String>();
	private HashSet<String> mValidFlightNodes = new HashSet<String>();
	private HashSet<String> mAccomodationBookings = new HashSet<String>();

	private Configuration()
	{
		mMutex = new Object();

		mSearchListAirlines = new ArrayList<TravelData_INPUT>();
		mSearchListAccom = new ArrayList<AccomodationData_INPUT>();
		mFlightList = new ArrayList<TravelData_INPUT>();
		mRecipientList = new ArrayList<Recipient>();

		mConfigValues = new Hashtable<String, String>(  );

		mValidAirlines.add( "wizzair" );
		mValidAirlines.add( "ryanair" );

		mValidSearchAirlineNodes.add( "LeavingFrom" );
		mValidSearchAirlineNodes.add( "GoingTo" );
		mValidSearchAirlineNodes.add( "DepartureDay" );
		mValidSearchAirlineNodes.add( "ReturnDay" );
		mValidSearchAirlineNodes.add( "AdultNumber" );
		mValidSearchAirlineNodes.add( "ChildNumber" );
		mValidSearchAirlineNodes.add( "InfantNumber" );
		mValidSearchAirlineNodes.add( "NearbyAirports" );
		mValidSearchAirlineNodes.add( "ReturnTicket" );

		mValidSearchAccomodationNodes.add( "Checkin" );
		mValidSearchAccomodationNodes.add( "Checkout" );
		mValidSearchAccomodationNodes.add( "PriceLimit" );
		mValidSearchAccomodationNodes.add( "City" );
		mValidSearchAccomodationNodes.add( "Filters" );
		mValidSearchAccomodationNodes.add( "SearchURL" );
		mValidSearchAccomodationNodes.add( "RoomNumber" );
		mValidSearchAccomodationNodes.add( "AdultNumber" );
		mValidSearchAccomodationNodes.add( "ChildrenNumber" );
		mValidSearchAccomodationNodes.add( "ChildrenAges" );

		mValidFlightNodes.add( "LeavingFrom" );
		mValidFlightNodes.add( "GoingTo" );
		mValidFlightNodes.add( "Filter" );
		mValidFlightNodes.add( "Interval" );

		mAccomodationBookings.add( "bookingdotcom" );
		mAccomodationBookings.add( "airbnb" );

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

	public ArrayList<TravelData_INPUT> getSearchListAirlines()
	{
		ArrayList<TravelData_INPUT> lSearchList = new ArrayList<TravelData_INPUT>();
		for( TravelData_INPUT lTDI : mSearchListAirlines )
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

	public ArrayList<AccomodationData_INPUT> getSearchListAccom()
	{
		ArrayList<AccomodationData_INPUT> lSearchList = new ArrayList<AccomodationData_INPUT>();
		for( AccomodationData_INPUT lADI : mSearchListAccom )
		{
			AccomodationData_INPUT lClone = null;
			try
			{
				lClone = (AccomodationData_INPUT) lADI.clone();
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

	public HashSet<String> getValidSearchAirlineNodes()
	{
		return mValidSearchAirlineNodes;
	}
	public HashSet<String> getValidSearchAccomodationNodes()
	{
		return mValidSearchAccomodationNodes;
	}

	public HashSet<String> getValidFlightNodes()
	{
		return mValidFlightNodes;
	}
	public HashSet<String> getValidAccomodationBookings()
	{
		return mAccomodationBookings;
	}

	public void put( String aPath, String aNodeValue )
	{
		if( mConfigValues.containsKey( aPath ))
		{
			// if there is an & character in the string, the xml parser gives the parts one by one
			mConfigValues.put( aPath, mConfigValues.get( aPath ) + aNodeValue );
			//System.out.println( aPath + ":" + mConfigValues.get( aPath ));
		}
		else
		{
			mConfigValues.put( aPath, aNodeValue );
		}
	}

	public void addShearchItem( TravelData_INPUT aTDI )
	{
		mSearchListAirlines.add( aTDI );
	}

	public void addShearchItem( AccomodationData_INPUT aADI )
	{
		mSearchListAccom.add( aADI );
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
