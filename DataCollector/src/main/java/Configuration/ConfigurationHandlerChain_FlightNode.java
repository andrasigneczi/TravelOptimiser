package Configuration;

import PageGuest.ResultFilterBuilder;
import PageGuest.TravelData_INPUT;
import org.xml.sax.Attributes;

/**
 * Created by Andras on 25/12/2016.
 */
public class ConfigurationHandlerChain_FlightNode extends ConfigurationHandlerChain
{
	private String mFlightPath;
	public ConfigurationHandlerChain_FlightNode( Configuration aConfiguration, String aFlightPath )
	{
		super( aConfiguration );
		mFlightPath = aFlightPath;
	}

	@Override
	protected boolean conditionFunction( String aName, String aPath )
	{
		if( aName.equals( "DayFilter" ) && mCurrentTravelDataInput != null )
			return true;

		return getConfiguration().getValidAirlines().contains( aName ) && aPath.equals( mFlightPath + aName );
	}

	@Override
	protected boolean doReaction( String aName, Attributes attributes )
	{
		if( aName.equals( "DayFilter" ) && mCurrentTravelDataInput != null )
		{
			mCurrentTravelDataInput.add( ResultFilterBuilder.Release() );
			ResultFilterBuilder.Create( ResultFilterBuilder.ResultFilterType.Day );
			for( int i = 0; i < attributes.getLength(); i++ )
			{
				ResultFilterBuilder.set( attributes.getQName( i ), attributes.getValue( i ) );
			}
			return true;
		}

		mCurrentTravelDataInput = new TravelData_INPUT();
		mCurrentTravelDataInput.mAirline = aName;
		mOpenedNode = OpenedNode.FLIGHT_NODE;
		return true;
	}

	@Override
	protected boolean doReaction2( String aName )
	{
		mCurrentTravelDataInput.add( ResultFilterBuilder.Release());
		getConfiguration().addFlightItem( mCurrentTravelDataInput );
		mCurrentTravelDataInput = null;
		mOpenedNode = OpenedNode.NONE;
		return true;
	}

	@Override
	protected boolean conditionFunction3( String aNodeName )
	{
		return mOpenedNode == OpenedNode.FLIGHT_NODE && getConfiguration().getValidFlightNodes().contains( aNodeName );
	}

	@Override
	protected boolean doReaction3( String aNodeName, String aNodeValue )
	{
		mCurrentTravelDataInput.set( aNodeName, aNodeValue );
		return true;
	}
}
