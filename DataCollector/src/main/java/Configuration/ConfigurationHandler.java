package Configuration;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import java.util.ArrayList;

/**
 * Created by Andras on 10/04/2016.
 */
public class ConfigurationHandler extends DefaultHandler
{
	private Configuration mConfiguration;
	private ArrayList<String> mCurrentPath = new ArrayList<String>();

	ConfigurationHandlerChain_FlightNode     mCHChain_FlightNode;
	ConfigurationHandlerChain_SearchNode     mCHChain_SearchNode;
	ConfigurationHandlerChain_RecipientNode  mCHChain_RecipientNode;

	public ConfigurationHandler( Configuration aConfiguration,
	                             String aSearchPath,
	                             String aFlightPath,
	                             String aEmailPath )
	{
		mConfiguration = aConfiguration;

		mCHChain_FlightNode = new ConfigurationHandlerChain_FlightNode( aConfiguration, aFlightPath );
		mCHChain_SearchNode = new ConfigurationHandlerChain_SearchNode( aConfiguration, aSearchPath );
		mCHChain_RecipientNode = new ConfigurationHandlerChain_RecipientNode( aConfiguration, aEmailPath );
		mCHChain_FlightNode.setNext( mCHChain_SearchNode );
		mCHChain_SearchNode.setNext( mCHChain_RecipientNode );
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

		mCHChain_FlightNode.handleEvent( qName, getPath(), attributes );
	}

	public void endElement(String uri, String localName,
	                       String qName)
			throws SAXException {

		mCHChain_FlightNode.handleEvent2( qName, getPath() );
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

		//System.out.println("'" + new String(ch, start, length) + "'");

		String lNodeName = mCurrentPath.get( mCurrentPath.size() - 1 );
		String lNodeValue = new String(ch, start, length).trim();
		
		if( !mCHChain_FlightNode.handleEvent3( lNodeName, lNodeValue ))
		{
			//System.out.println("'" + getPath() + "': " + "'" + lNodeValue + "'");
			mConfiguration.put( getPath(), lNodeValue );
		}
	}
}
