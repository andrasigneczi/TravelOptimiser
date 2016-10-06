package PageGuest;

import java.io.IOException;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class TravelData_RESULT implements Serializable
{
	public static class TravelData_PossibleTrip implements Cloneable, Serializable
	{
		public String  mDepartureDatetime          = "";    // 2017-01-04T17:25
		public String  mArrivalDatetime            = "";    // 2017-01-04T17:25
		public String  mPrices_BasicFare_Normal    = "";
		public String  mPrices_BasicFare_Discount  = "";
		public String  mPrices_PlusFare_Normal     = "";
		public String  mPrices_PlusFare_Discount   = "";
		public boolean mOutboundTrip               = false;

		private void writeObject(java.io.ObjectOutputStream out)
				throws IOException
		{
			out.writeObject( mDepartureDatetime );
			out.writeObject( mArrivalDatetime );
			out.writeObject( mPrices_BasicFare_Normal );
			out.writeObject( mPrices_BasicFare_Discount );
			out.writeObject( mPrices_PlusFare_Normal );
			out.writeObject( mPrices_PlusFare_Discount );
			out.writeBoolean( mOutboundTrip );
		}

		private void readObject(java.io.ObjectInputStream in)
				throws IOException, ClassNotFoundException
		{
			mDepartureDatetime          = (String)in.readObject();
			mArrivalDatetime            = (String)in.readObject();
			mPrices_BasicFare_Normal    = (String)in.readObject();
			mPrices_BasicFare_Discount  = (String)in.readObject();
			mPrices_PlusFare_Normal     = (String)in.readObject();
			mPrices_PlusFare_Discount   = (String)in.readObject();
			mOutboundTrip               = in.readBoolean();
		}

		@Override
		public Object clone()
		{
			try
			{
				return super.clone();
			}
			catch (CloneNotSupportedException e)
			{
				e.printStackTrace();
			}
			return null;
		}

		public String dump()
		{
			String lReturnValue = "";
			lReturnValue += "mDepartureDatetime: "         + mDepartureDatetime         + "\n";
			lReturnValue += "mArrivalDatetime:"            + mArrivalDatetime           + "\n";
			lReturnValue += "mPrices_BasicFare_Normal: "   + mPrices_BasicFare_Normal   + "\n";
			lReturnValue += "mPrices_BasicFare_Discount: " + mPrices_BasicFare_Discount + "\n";
			lReturnValue += "mPrices_PlusFare_Normal: "    + mPrices_PlusFare_Normal    + "\n";
			lReturnValue += "mPrices_PlusFare_Discount: "  + mPrices_PlusFare_Discount  + "\n";
			lReturnValue += "mOutboundTrip: " + ( mOutboundTrip ? "true" : "false" ) + "\n";
			return lReturnValue;
		}
	}

	public TravelData_RESULT()
	{
		mTrips = new ArrayList<TravelData_PossibleTrip>();
	}

	public String mAirline                    = "";
	public String mAirportCode_LeavingFrom    = "";   // SOF
	public String mAirportCode_GoingTo        = "";       // HHN
	public TravelData_INPUT mTravelDataInput  = null;
	public String mRecordedDatetime           = LocalDateTime.now().format( DateTimeFormatter.ofPattern( "yyyy-MM-dd HH:mm:ss" ));
	public ArrayList<TravelData_PossibleTrip> mTrips;


	String toString( TravelDataResultComposer aComposer )
	{
		if( aComposer != null )
			return aComposer.toFormattedString();
		return super.toString();
	}

	private void writeObject(java.io.ObjectOutputStream out)
			throws IOException
	{
		out.writeObject( mAirline );
		out.writeObject( mAirportCode_LeavingFrom );
		out.writeObject( mAirportCode_GoingTo );
		out.writeObject( mTravelDataInput );
		out.writeObject( mRecordedDatetime );
		out.writeInt( mTrips.size() );
		for( TravelData_PossibleTrip lTrip : mTrips )
			out.writeObject( lTrip );
	}

	private void readObject(java.io.ObjectInputStream in)
			throws IOException, ClassNotFoundException
	{
		mAirline                 = (String)in.readObject();
		mAirportCode_LeavingFrom = (String)in.readObject();
		mAirportCode_GoingTo     = (String)in.readObject();
		mTravelDataInput         = (TravelData_INPUT)in.readObject();
		mRecordedDatetime        = (String)in.readObject();

		int lSize = in.readInt();
		mTrips = new ArrayList<TravelData_PossibleTrip>();
		for( int i = 0; i < lSize; i++ )
		{
			mTrips.add(( TravelData_PossibleTrip)in.readObject());
		}
	}
}
