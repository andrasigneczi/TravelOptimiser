package Configuration;

import PageGuest.TravelData_INPUT;
import org.xml.sax.Attributes;

/**
 * Created by Andras on 25/12/2016.
 */
public abstract class ConfigurationHandlerChain
{
	private ConfigurationHandlerChain mNext = null;
	private Configuration mConfiguration;
	protected TravelData_INPUT mCurrentTravelDataInput;
	protected Recipient mRecipient;

	protected OpenedNode mOpenedNode = OpenedNode.NONE;
	enum OpenedNode {
		SEARCH_NODE,
		FLIGHT_NODE,
		EMAIL_NODE,
		NONE
	};

	public ConfigurationHandlerChain( Configuration aConfiguration )
	{
		mConfiguration = aConfiguration;
	}

	public ConfigurationHandlerChain setNext( ConfigurationHandlerChain next )
	{
		ConfigurationHandlerChain prev = mNext;
		mNext = next;
		return prev;
	}

	public boolean handleEvent( String aName, String aPath, Attributes attributes )
	{
		if( conditionFunction( aName, aPath ))
			doReaction( aName, attributes );
		else if( mNext != null )
			return mNext.handleEvent( aName, aPath, attributes );

		return true;
	}

	public boolean handleEvent2( String aName, String aPath )
	{
		if( conditionFunction2( aName, aPath ))
			doReaction2( aName );
		else if( mNext != null )
			return mNext.handleEvent2( aName, aPath );

		return true;
	}

	public boolean handleEvent3( String aNodeName, String aNodeValue )
	{
		if( conditionFunction3( aNodeName ))
			doReaction3( aNodeName, aNodeValue );
		else if( mNext != null )
			return mNext.handleEvent3( aNodeName, aNodeValue );

		return true;
	}

	protected abstract boolean conditionFunction( String aName, String aPath );
	protected abstract boolean conditionFunction2( String aName, String aPath );
	protected abstract boolean doReaction( String aName, Attributes attributes );
	protected abstract boolean doReaction2( String aName );

	protected abstract boolean conditionFunction3( String aNodeName );
	protected abstract boolean doReaction3( String aNodeName, String aNodeValue );

	public Configuration getConfiguration()
	{
		return mConfiguration;
	}
}
