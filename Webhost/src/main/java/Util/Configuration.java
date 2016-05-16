package Util;

import Util.TravelData_INPUT;
import org.xml.sax.InputSource;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
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
	private Hashtable<String,String> mConfigValues;
	private HashSet<String> mValidAirlines = new HashSet<String>();
	private HashSet<String> mValidSearchNodes = new HashSet<String>();

	private Configuration()
	{
		mMutex = new Object();
		mSearchList = new ArrayList<TravelData_INPUT>();
		mConfigValues = new Hashtable<String, String>(  );
		mValidAirlines.add( "wizzair" );
		mValidAirlines.add( "ryanair" );
		mValidSearchNodes.add( "LeavingFrom" );
		mValidSearchNodes.add( "GoingTo" );
		mValidSearchNodes.add( "DepartureDatetime" );
		mValidSearchNodes.add( "ReturnDatetime" );
		mValidSearchNodes.add( "AdultNumber" );
		mValidSearchNodes.add( "ChildNumber" );
		mValidSearchNodes.add( "InfantNumber" );
		mValidSearchNodes.add( "NearbyAirports" );
		mValidSearchNodes.add( "ReturnTicket" );
		mValidSearchNodes.add( "Currency" );
		mValidSearchNodes.add( "BoughtTicket" );
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

	private void ParseConfigurationFile()
	{
		try {

			SAXParserFactory factory = SAXParserFactory.newInstance();
			SAXParser saxParser = factory.newSAXParser();

			DefaultHandler handler = new ConfigurationHandler( this, "/configuration/charts/" );

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

	public HashSet<String> getValidAirlines()
	{
		return mValidAirlines;
	}

	public HashSet<String> getValidSearchNodes()
	{
		return mValidSearchNodes;
	}

	public void put( String aPath, String aNodeValue )
	{
		mConfigValues.put( aPath, aNodeValue );
	}

	public void add( TravelData_INPUT aTDI )
	{
		mSearchList.add( aTDI );
	}
}
