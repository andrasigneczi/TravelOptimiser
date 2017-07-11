package PageGuest;

import java.util.ArrayList;

/**
 * Created by Andras on 16/06/2017.
 */
public class AccomodationData_RESULT
{
	/*
		"Type     CHAR, / *room=R,apartment=A,hotelroom=H* /\n" +
		"Name     CHAR(128) UNIQUE,\n" +
		"Site     CHAR, / *booking.com=B, airbnb.com=A* /\n" +
		"URL      CHAR(1024),\n" +
		"CheckIn  CHAR(50),\n" +
		"CheckOut CHAR(50),\n" +
		"Price    FLOAT,\n" +
		"Adult    TINYINT,\n" +
		"Children TINYINT\n" +

	*/
	public char    mType;
	public String  mName;
	public char    mSite;
	public String  mURL;
	//public String  mCheckInDate;
	//public String  mCheckOutDate;
	public String  mCheckInPolicy;
	public String  mCheckOutPolicy;
	public Double  mPrice;
	//public Integer mAdult;
	//public Integer mChildren;
	public Double  mScore;
	public String  mAddress;
	public String  mGMapURL;
	public String  mMaxOccupancy;
	public boolean mBreakfastIncluded;
	public String  mRoomSize;
	public String  mRoomHook;

	ArrayList<AccomodationData_RESULT> mAvailableRooms = new ArrayList<>(  );
}
