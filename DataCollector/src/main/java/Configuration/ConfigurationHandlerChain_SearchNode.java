package Configuration;

import PageGuest.AccomodationData_INPUT;
import PageGuest.TravelData_INPUT;
import org.xml.sax.Attributes;

/**
 * Created by Andras on 26/12/2016.
 */
public class ConfigurationHandlerChain_SearchNode extends ConfigurationHandlerChain
{
	private String mSearchPath;
	enum SearchType {
		ST_AIRLINE,
		ST_ACCOMODATION
	};
	private SearchType mSearchType;

	public ConfigurationHandlerChain_SearchNode( Configuration aConfiguration, String aSearchPath )
	{
		super( aConfiguration );
		mSearchPath = aSearchPath;
	}

	@Override
	protected boolean conditionFunction( String aName, String aPath )
	{
		if( !aPath.equals( mSearchPath + aName ))
			return false;

		if( getConfiguration().getValidAirlines().contains( aName ))
		{
			mSearchType = SearchType.ST_AIRLINE;
		}
		else if( getConfiguration().getValidAccomodationBookings().contains( aName ))
		{
			mSearchType = SearchType.ST_ACCOMODATION;
		}
		else
		{
			return false;
		}
		return true;
	}

	@Override
	protected boolean conditionFunction2( String aName, String aPath )
	{
		return conditionFunction( aName, aPath );
	}

	@Override
	protected boolean doReaction( String aName, Attributes attributes )
	{
		if( mSearchType == SearchType.ST_AIRLINE )
		{
			mCurrentTravelDataInput = new TravelData_INPUT();
			mCurrentTravelDataInput.mAirline = aName;
			mOpenedNode = OpenedNode.SEARCH_NODE;
		}
		else if( mSearchType == SearchType.ST_ACCOMODATION )
		{
			mCurrentAccomodationDataInput = new AccomodationData_INPUT();
			mCurrentAccomodationDataInput.mSite = AccomodationData_INPUT.siteFromXmlName( aName );
			mOpenedNode = OpenedNode.SEARCH_NODE;
		}
		else
		{
			return false;
		}
		return true;
	}

	@Override
	protected boolean doReaction2( String aName )
	{
		if( mSearchType == SearchType.ST_AIRLINE )
		{
			getConfiguration().addShearchItem( mCurrentTravelDataInput );
			mCurrentTravelDataInput = null;
			mOpenedNode = OpenedNode.NONE;
		}
		else if( mSearchType == SearchType.ST_ACCOMODATION )
		{
			getConfiguration().addShearchItem( mCurrentAccomodationDataInput );
			mCurrentAccomodationDataInput = null;
			mOpenedNode = OpenedNode.NONE;
		}
		return true;
	}

	@Override
	protected boolean conditionFunction3( String aNodeName )
	{
		if( mOpenedNode != OpenedNode.SEARCH_NODE )
		{
			return false;
		}

		if( getConfiguration().getValidSearchAirlineNodes().contains( aNodeName ))
		{
			return true;
		}
		else if( getConfiguration().getValidSearchAccomodationNodes().contains( aNodeName ))
		{
			return true;
		}
		return false;
	}

	@Override
	protected boolean doReaction3( String aNodeName, String aNodeValue )
	{
		if( mSearchType == SearchType.ST_AIRLINE )
		{
			mCurrentTravelDataInput.set( aNodeName, aNodeValue );
		}
		else if( mSearchType == SearchType.ST_ACCOMODATION )
		{
			mCurrentAccomodationDataInput.set( aNodeName, aNodeValue );
		}
		return true;
	}
}
