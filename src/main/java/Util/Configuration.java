package Util;

import PageGuest.TravelData_INPUT;
import PageGuest.TravelData_RESULT;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
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
	private int mDelayBeforeClick = 10;
	ArrayList<TravelData_INPUT> mSearchList = null;
	Hashtable<String,String> mConfigValues;
	HashSet<String> mValidAirlines = new HashSet<String>();
	HashSet<String> mValidSearchNodes = new HashSet<String>();

	private Configuration()
	{
		mMutex = new Object();
		mSearchList = new ArrayList<TravelData_INPUT>();
		mConfigValues = new Hashtable<String, String>(  );
		mValidAirlines.add( "wizzair" );
		mValidSearchNodes.add( "LeavingFrom" );
		mValidSearchNodes.add( "GoingTo" );
		mValidSearchNodes.add( "DepartureDay" );
		mValidSearchNodes.add( "ReturnDay" );
		mValidSearchNodes.add( "AdultNumber" );
		mValidSearchNodes.add( "ChildNumber" );
		mValidSearchNodes.add( "InfantNumber" );
		mValidSearchNodes.add( "NearbyAirports" );
		mValidSearchNodes.add( "ReturnTicket" );
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

			DefaultHandler handler = new DefaultHandler() {

				ArrayList<String> mCurrentPath = new ArrayList<String>();
				TravelData_INPUT mCurrentTravelDataInput;

				public void startElement(String uri, String localName,
				                         String qName, Attributes attributes)
						throws SAXException
				{

					/*
					attributes.getName(0)
					attributes.getValue(0)
					attributes.getLength()
					 */
					//System.out.println("Start Element :" + qName);
					mCurrentPath.add( qName );
					if( mValidAirlines.contains( qName ) && getPath().equals( "/configuration/searches/" + qName ))
					{
						mCurrentTravelDataInput = new TravelData_INPUT();
						mCurrentTravelDataInput.mAirline = qName;
					}
				}

				public void endElement(String uri, String localName,
				                       String qName)
						throws SAXException {

					//System.out.println("End Element :" + qName);
					if( mValidAirlines.contains( qName ) && getPath().equals( "/configuration/searches/" + qName ))
					{
						mSearchList.add( mCurrentTravelDataInput );
						mCurrentTravelDataInput = null;
					}
					mCurrentPath.remove( mCurrentPath.size() - 1 );
				}

				private String getPath()
				{
					String lPath = "";
					for( String lNode : mCurrentPath )
					{
						lPath += "/" + lNode;
					}
					return lPath;
				}

				public void characters(char ch[], int start, int length)
						throws SAXException {

					//System.out.println(new String(ch, start, length));

					String lNodeName = mCurrentPath.get( mCurrentPath.size() - 1 );
					String lNodeValue = new String(ch, start, length).trim();
					if( mCurrentTravelDataInput != null && mValidSearchNodes.contains( lNodeName ) )
					{
						mCurrentTravelDataInput.set( lNodeName, lNodeValue );
					}
					else
					{
						mConfigValues.put( getPath(), lNodeValue );
					}
				}

			};

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
}
