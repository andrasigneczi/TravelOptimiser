package PageGuest;

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
	public String  mCheckIn;
	public String  mCheckOut;
	public Float   mPrice;
	public Integer mAdult;
	public Integer mChildren;
}
