package PageGuest;

import java.util.ArrayList;

public class TravelData_RESULT
{
	public static class TravelData_PossibleTrip implements Cloneable
	{
		public String mDepartureDatetime          = "";    // 2017-01-04T17:25
		public String mArrivalDatetime            = "";    // 2017-01-04T17:25
		public String mPrices_BasicFare_Normal    = "";
		public String mPrices_BasicFare_Discount  = "";
		public String mPrices_PlusFare_Normal     = "";
		public String mPrices_PlusFare_Discount   = "";
		public boolean mOutboundTrip              = false;

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
	}

	public TravelData_RESULT()
	{
		mTrips = new ArrayList<TravelData_PossibleTrip>();
	}

	public String mAirline                    = "";
	public String mAirportCode_LeavingFrom    = "";   // SOF
	public String mAirportCode_GoingTo        = "";       // HHN
	public TravelData_INPUT mTravelDataInput  = null;
	public ArrayList<TravelData_PossibleTrip> mTrips;
	//public boolean mReturnTicket;

	String toString( TravelDataResultComposer aComposer )
	{
		if( aComposer != null )
			return aComposer.toFormattedString();
		return super.toString();
	}
}
