package Util;

import Util.TravelData_INPUT;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import java.util.ArrayList;

/**
 * Created by Andras on 10/04/2016.
 */
public class ConfigurationHandler extends DefaultHandler
{
	Configuration mConfiguration;
	ArrayList<String> mCurrentPath = new ArrayList<String>();
	TravelData_INPUT mCurrentTravelDataInput;
	final String mSearchPath;

	public ConfigurationHandler( Configuration aConfiguration, String aSearchPath )
	{
		mConfiguration = aConfiguration;
		mSearchPath = aSearchPath;
	}

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
		if( mConfiguration.getValidAirlines().contains( qName ) && getPath().equals( mSearchPath + qName ))
		{
			mCurrentTravelDataInput = new TravelData_INPUT();
			mCurrentTravelDataInput.mAirline = qName;
		}
		else if( mCurrentTravelDataInput != null && mConfiguration.getValidSearchNodes().contains( qName ) )
		{
			if( qName.equals( "BoughtTicket" ))
			{
				TravelData_INPUT.BoughtTicket lBoughtTicket = new TravelData_INPUT.BoughtTicket();

				for( int i = 0; i < attributes.getLength(); i++ )
				{
					lBoughtTicket.set( attributes.getLocalName( i ), attributes.getValue( i ));
				}
				mCurrentTravelDataInput.add( lBoughtTicket );
			}
		}
	}

	public void endElement(String uri, String localName,
	                       String qName)
			throws SAXException {

		//System.out.println("End Element :" + qName);
		if( mConfiguration.getValidAirlines().contains( qName ) && getPath().equals( mSearchPath + qName ))
		{
			mConfiguration.add( mCurrentTravelDataInput );
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
		if( mCurrentTravelDataInput != null && mConfiguration.getValidSearchNodes().contains( lNodeName ) )
		{
			mCurrentTravelDataInput.set( lNodeName, lNodeValue );
		}
		else
		{
			mConfiguration.put( getPath(), lNodeValue );
		}
	}
}
