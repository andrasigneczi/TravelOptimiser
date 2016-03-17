package PageGuest;

import java.util.ArrayList;

public class TravelDatas_RESULT
{
	public static class TravelDatas_PossibleTrips
	{
		public String mDepartureDaytime;    // 2016.03.25 17:10
		public String mArrivalDaytime;      // 2016.03.25 22:10
		public String mPrices;
		public String mPrices2;
		public boolean mOutboundTrip;
		//public String mWayBack_DepartureDaytime;  // 2016.03.27 17:10
		//public String mWayBack_ArrivalDaytime;    // 2016.03.27 22:10
		//public String mWayBack_Prices;
	}

	public TravelDatas_RESULT()
	{
		mTrips = new ArrayList<TravelDatas_PossibleTrips>();
	}

	public String mAirportCode_LeavingFrom;   // SOF
	public String mAirportCode_GoingTo;       // HHN
	ArrayList<TravelDatas_PossibleTrips> mTrips;
	public boolean mReturnTicket;
}
