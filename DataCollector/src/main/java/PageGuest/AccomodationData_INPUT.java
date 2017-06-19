package PageGuest;

import java.io.IOException;
import java.io.Serializable;

/**
 * Created by Andras on 16/06/2017.
 */
public class AccomodationData_INPUT implements Cloneable, Serializable
{
	public char    mSite;      // booking.com=B, airbnb.com=A, unknown=U
	public char    mType;      // room=R,apartment=A,hotelroom=H
	public String  mCheckIn;   // e.g. 2017.06.28.
	public String  mCheckOut;  // e.g. 2017.06.29.
	public Integer mPriceLimit;
	public String  mCity;
	public String  mFilters; // checklist, e.g. apartment,free wifi,parking place

	public static char siteFromXmlName( String name )
	{
		if( name.equals( "bookingdotcom" ))
			return 'B';
		else if( name.equals( "airbnb" ))
			return 'A';
		else return 'U';
	}

	public boolean set( String aName, String aValue )
	{
		boolean lReturnValue = false;
		setvalues:
		{
			if( aName.equals( "Checkin" ) )
			{
				mCheckIn = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "Checkout" ) )
			{
				mCheckOut = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "PriceLimit" ) )
			{
				mPriceLimit = Integer.parseInt( aValue );
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "City" ) )
			{
				mCity = aValue;
				lReturnValue = true;
				break setvalues;
			}

			if( aName.equals( "Filters" ) )
			{
				mFilters = aValue;
				lReturnValue = true;
				break setvalues;
			}
		}
		return lReturnValue;
	}
	private void writeObject(java.io.ObjectOutputStream out) throws IOException
	{
		out.writeObject(  mSite );
		out.writeObject(  mType );
		out.writeObject(  mCheckIn );
		out.writeObject(  mCheckOut );
		out.writeObject(  mPriceLimit );
		out.writeObject(  mCity );
		out.writeObject(  mFilters );
	}

	private void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException
	{
		mSite       = (char)in.readObject();
		mType       = (char)in.readObject();
		mCheckIn    = (String)in.readObject();
		mCheckOut   = (String)in.readObject();
		mPriceLimit = (Integer)in.readObject();
		mCity       = (String)in.readObject();
		mFilters    = (String)in.readObject();
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
		lReturn += "Site: " + mSite + "\n";
		lReturn += "Type: " + mType  + "\n";
		lReturn += "Check-in: " + mCheckIn + "\n";
		lReturn += "Check-out: " + mCheckOut + "\n";
		lReturn += "Price limit: " + mPriceLimit + "\n";
		lReturn += "City: " + mCity + "\n";
		lReturn += "Filters: " + mFilters + "\n";
		return lReturn;
	}
}
