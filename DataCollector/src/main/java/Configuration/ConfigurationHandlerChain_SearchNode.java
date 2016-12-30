package Configuration;

import PageGuest.TravelData_INPUT;
import org.xml.sax.Attributes;

/**
 * Created by Andras on 26/12/2016.
 */
public class ConfigurationHandlerChain_SearchNode extends ConfigurationHandlerChain
{
	private String mSearchPath;
	public ConfigurationHandlerChain_SearchNode( Configuration aConfiguration, String aSearchPath )
	{
		super( aConfiguration );
		mSearchPath = aSearchPath;
	}

	@Override
	protected boolean conditionFunction( String aName, String aPath )
	{
		return getConfiguration().getValidAirlines().contains( aName ) && aPath.equals( mSearchPath + aName );
	}

	@Override
	protected boolean conditionFunction2( String aName, String aPath )
	{
		return conditionFunction( aName, aPath );
	}

	@Override
	protected boolean doReaction( String aName, Attributes attributes )
	{
		mCurrentTravelDataInput = new TravelData_INPUT();
		mCurrentTravelDataInput.mAirline = aName;
		mOpenedNode = OpenedNode.SEARCH_NODE;
		return true;
	}

	@Override
	protected boolean doReaction2( String aName )
	{
		getConfiguration().addShearchItem( mCurrentTravelDataInput );
		mCurrentTravelDataInput = null;
		mOpenedNode = OpenedNode.NONE;
		return true;
	}

	@Override
	protected boolean conditionFunction3( String aNodeName )
	{
		return mOpenedNode == OpenedNode.SEARCH_NODE && getConfiguration().getValidSearchNodes().contains( aNodeName );
	}

	@Override
	protected boolean doReaction3( String aNodeName, String aNodeValue )
	{
		mCurrentTravelDataInput.set( aNodeName, aNodeValue );
		return true;
	}
}
