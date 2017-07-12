package PageGuest;

import java.util.ArrayList;

/**
 * Created by Andras on 16/06/2017.
 */
public class AccomodationData_RESULT implements Cloneable
{
	/*
		"CREATE TABLE IF NOT EXISTS Flat (\n" +
		"ID       INTEGER PRIMARY KEY NOT NULL,\n" +
		"Type     CHAR, / *room=R,apartment=A,hotelroom=H* /\n" +
		"Name     CHAR(128) UNIQUE,\n" +
		"Site     CHAR, / *booking.com=B, airbnb.com=A* /\n" +
		"URL      CHAR(1024),\n" +
		"Price    FLOAT,\n" +
		"CheckInPolicy CHAR(256),\n" +
		"CheckOutPolicy CHAR(256),\n" +
		"Score CHAR(10),\n" +
		"Address CHAR(256),\n" +
		"MaxOccupancy TINYINT,\n" +
		"BreakfastIncluded CHAR,\n" +
		"RoomSize CHAR(7),\n" +
		"RoomHook CHAR(10)\n" +
	*/
	public char    mType;
	public String  mName;
	public char    mSite;
	public String  mURL;
	public String  mCheckInPolicy;
	public String  mCheckOutPolicy;
	public Double  mPrice;
	public Double  mScore;
	public String  mAddress;
	public String  mMaxOccupancy;
	public boolean mBreakfastIncluded;
	public String  mRoomSize;
	public String  mRoomHook;

	ArrayList<AccomodationData_RESULT> mAvailableRooms = new ArrayList<>(  );

	@Override
	public Object clone() throws CloneNotSupportedException
	{
		AccomodationData_RESULT ret = (AccomodationData_RESULT)super.clone();
		ret.mAvailableRooms = (ArrayList<AccomodationData_RESULT>)mAvailableRooms.clone();
		return ret;
	}
}
