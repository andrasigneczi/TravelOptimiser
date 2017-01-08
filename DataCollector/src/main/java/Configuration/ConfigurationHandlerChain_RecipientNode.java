package Configuration;

import org.xml.sax.Attributes;

/**
 * Created by Andras on 26/12/2016.
 */
public class ConfigurationHandlerChain_RecipientNode extends ConfigurationHandlerChain
{
	private String mRecipientPath;
	private String mAirline = "";
	public ConfigurationHandlerChain_RecipientNode( Configuration aConfiguration, String aEmailPath )
	{
		super( aConfiguration );
		mRecipientPath = aEmailPath;
	}

	@Override
	protected boolean conditionFunction( String aName, String aPath )
	{
		if( aName.equalsIgnoreCase( "recipient" ) && mRecipient != null )
			return true;
		return conditionFunction2( aName, aPath );
	}

	@Override
	protected boolean conditionFunction2( String aName, String aPath )
	{
		return getConfiguration().getValidAirlines().contains( aName ) && aPath.equals( mRecipientPath + aName );
	}

	@Override
	protected boolean doReaction( String aName, Attributes attributes )
	{
		if( aName.equalsIgnoreCase( "recipient" ) && mRecipient != null )
		{
			for( int i = 0; i < attributes.getLength(); i++ )
			{
				mRecipient.set( attributes.getQName( i ), attributes.getValue( i ) );
			}
			getConfiguration().addRecipientItem( mRecipient );
			mRecipient = new Recipient();
			mRecipient.set( "Airline", mAirline );
			return true;
		}
		mRecipient = new Recipient();
		mRecipient.set( "Airline", aName );
		mAirline = aName;
		mOpenedNode = OpenedNode.EMAIL_NODE;
		return true;
	}

	@Override
	protected boolean doReaction2( String aName )
	{
		//getConfiguration().addRecipientItem( mRecipient );
		mRecipient = null;
		mOpenedNode = OpenedNode.NONE;
		return true;
	}

	@Override
	protected boolean conditionFunction3( String aNodeName )
	{
		return mOpenedNode == OpenedNode.EMAIL_NODE && getConfiguration().getValidFlightNodes().contains( aNodeName );
	}

	@Override
	protected boolean doReaction3( String aNodeName, String aNodeValue )
	{
		mRecipient.set( aNodeName, aNodeValue );
		return true;
	}
}
