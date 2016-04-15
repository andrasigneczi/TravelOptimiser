package Util;

/**
 * Created by Andras on 15/03/2016.
 */
public class TravelData_INPUT implements Cloneable
{
	public String  mAirline;
	public String  mAirportCode_LeavingFrom;   // SOF
	public String  mAirportCode_GoingTo;       // HHN
	public String  mDepartureDatetime;         // 2016.03.25 17:10
	public String  mReturnDatetime    = "";    // 2016.03.27 17:10
	public String  mAdultNumber       = "1";
	public String  mChildNumber       = "0";
	public String  mInfantNumber      = "0";
	public boolean mNearbyAirports    = false;
	public boolean mReturnTicket      = false;
	public String mCurrency           = "";

	public boolean set( String aName, String aValue )
	{
		boolean lReturnValue = false;
		setvalues:
		{
			if( aName.equals( "Airline" ) )
			{
				mAirline = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "LeavingFrom" ) )
			{
				mAirportCode_LeavingFrom = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "GoingTo" ) )
			{
				mAirportCode_GoingTo = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "DepartureDatetime" ) )
			{
				mDepartureDatetime = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "ReturnDatetime" ) )
			{
				mReturnDatetime = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "AdultNumber" ) )
			{
				mAdultNumber = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "ChildNumber" ) )
			{
				mChildNumber = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "InfantNumber" ) )
			{
				mInfantNumber = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "NearbyAirports" ) )
			{
				mNearbyAirports = aValue.equals( "true" );
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "ReturnTicket" ) )
			{
				mReturnTicket = aValue.equals( "true" );
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "Currency" ) )
			{
				mCurrency = aValue;
				lReturnValue = true;
				break setvalues;
			}
		}
		return lReturnValue;
	}

	@Override
	public Object clone() throws CloneNotSupportedException
	{
		return super.clone();
	}
}
