package Util;

import PageGuest.TravelData_INPUT;
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
	final String mFlightPath;
	enum OpenedNode {
		SEARCH_NODE,
		FLIGHT_NODE,
		NONE
	};

	OpenedNode mOpenedNode = OpenedNode.NONE;

	public ConfigurationHandler( Configuration aConfiguration, String aSearchPath, String aFlightPath )
	{
		mConfiguration = aConfiguration;
		mSearchPath = aSearchPath;
		mFlightPath = aFlightPath;
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
			mOpenedNode = OpenedNode.SEARCH_NODE;
		}
		else if( mConfiguration.getValidAirlines().contains( qName ) && getPath().equals( mFlightPath + qName ))
		{
			mCurrentTravelDataInput = new TravelData_INPUT();
			mCurrentTravelDataInput.mAirline = qName;
			mOpenedNode = OpenedNode.FLIGHT_NODE;
		}
	}

	public void endElement(String uri, String localName,
	                       String qName)
			throws SAXException {

		//System.out.println("End Element :" + qName);
		if( mConfiguration.getValidAirlines().contains( qName ) && getPath().equals( mSearchPath + qName ))
		{
			mConfiguration.addShearchItem( mCurrentTravelDataInput );
			mCurrentTravelDataInput = null;
			mOpenedNode = OpenedNode.NONE;
		}
		else if( mConfiguration.getValidAirlines().contains( qName ) && getPath().equals( mFlightPath + qName ))
		{
			mConfiguration.addFlightItem( mCurrentTravelDataInput );
			mCurrentTravelDataInput = null;
			mOpenedNode = OpenedNode.NONE;
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
		
//		if( mCurrentTravelDataInput != null
//            && ( mConfiguration.getValidSearchNodes().contains( lNodeName )
//				|| mConfiguration.getValidFlightNodes().contains( lNodeName ))
//          )
		boolean lValid = ( mOpenedNode == OpenedNode.SEARCH_NODE && mConfiguration.getValidSearchNodes().contains( lNodeName ));
		if( !lValid )
			lValid = ( mOpenedNode == OpenedNode.FLIGHT_NODE && mConfiguration.getValidFlightNodes().contains( lNodeName ));

		if( lValid )
		{
			mCurrentTravelDataInput.set( lNodeName, lNodeValue );
		}
		else
		{
			mConfiguration.put( getPath(), lNodeValue );
		}
	}
}
