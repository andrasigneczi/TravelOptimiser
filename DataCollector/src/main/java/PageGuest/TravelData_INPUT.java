package PageGuest;

import java.io.IOException;
import java.io.Serializable;

/**
 * Created by Andras on 15/03/2016.
 */
public class TravelData_INPUT implements Cloneable, Serializable
{
	public String  mAirline;
	public String  mAirportCode_LeavingFrom;   // SOF
	public String  mAirportCode_GoingTo;       // HHN
	public String  mDepartureDay;              // 2016.03.25 17:10
	public String  mReturnDay         = "";    // 2016.03.27 17:10
	public String  mAdultNumber       = "1";
	public String  mChildNumber       = "0";
	public String  mInfantNumber      = "0";
	public boolean mNearbyAirports    = false;
	public boolean mReturnTicket      = true;

	private void writeObject(java.io.ObjectOutputStream out) throws IOException
	{
		out.writeObject(  mAirline );
		out.writeObject(  mAirportCode_LeavingFrom );
		out.writeObject(  mAirportCode_GoingTo );
		out.writeObject(  mDepartureDay );
		out.writeObject(  mReturnDay );
		out.writeObject(  mAdultNumber );
		out.writeObject(  mChildNumber );
		out.writeObject(  mInfantNumber );
		out.writeBoolean( mNearbyAirports );
		out.writeBoolean( mReturnTicket );
	}

	private void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException
	{
		mAirline                 = (String)in.readObject();
		mAirportCode_LeavingFrom = (String)in.readObject();
		mAirportCode_GoingTo     = (String)in.readObject();
		mDepartureDay            = (String)in.readObject();
		mReturnDay               = (String)in.readObject();
		mAdultNumber             = (String)in.readObject();
		mChildNumber             = (String)in.readObject();
		mInfantNumber            = (String)in.readObject();
		mNearbyAirports          = in.readBoolean();
		mReturnTicket            = in.readBoolean();
	}

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

			if( aName.equals( "DepartureDay" ) )
			{
				mDepartureDay = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "ReturnDay" ) )
			{
				mReturnDay = aValue;
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
		}
		return lReturnValue;
	}

	@Override
	public Object clone() throws CloneNotSupportedException
	{
		return super.clone();
	}

	@Override
	public String toString()
	{
		String lReturn = "";
		lReturn += "Airline: " + mAirline + "\n";
		lReturn += "AirportCode_LeavingFrom: " + mAirportCode_LeavingFrom  + "\n";
		lReturn += "AirportCode_GoingTo: " + mAirportCode_GoingTo + "\n";
		lReturn += "DepartureDay: " + mDepartureDay + "\n";
		lReturn += "ReturnDay: " + mReturnDay + "\n";
		lReturn += "AdultNumber: " + mAdultNumber + "\n";
		lReturn += "ChildNumber: " + mChildNumber + "\n";
		lReturn += "InfantNumber: " + mInfantNumber + "\n";
		lReturn += "NearbyAirports: " + mNearbyAirports + "\n";
		lReturn += "ReturnTicket: " + mReturnTicket + "\n";
		return lReturn;
	}
}
