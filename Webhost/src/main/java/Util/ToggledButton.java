package Util;

/**
 * Created by Andras on 28/04/2016.
 */
public class ToggledButton
{
	public ToggledButton( String aDatetime, String aAirline, String aLeavingFrom, String aGoingTo )
	{
		mDatetime    = aDatetime;
		mAirline     = aAirline;
		mLeavingFrom = aLeavingFrom;
		mGoingTo     = aGoingTo;
	}

	public boolean equals( ToggledButton aToggledButton )
	{
		if( mAirline.equals( aToggledButton.getAirline()) &&
				mDatetime.equals( aToggledButton.getDatetime()) &&
				mLeavingFrom.equals( aToggledButton.getLeavingFrom() ) &&
				mGoingTo.equals( aToggledButton.getGoingTo() ))
		{
			return true;
		}
		return false;
	}

	public String getDatetime()
	{
		return mDatetime;
	}

	public void setDatetime( String aDatetime )
	{
		this.mDatetime = aDatetime;
	}

	public String getAirline()
	{
		return mAirline;
	}

	public void setAirline( String aAirline )
	{
		this.mAirline = aAirline;
	}

	public String getLeavingFrom()
	{
		return mLeavingFrom;
	}

	public void setLeavingFrom( String aLeavingFrom )
	{
		this.mLeavingFrom = aLeavingFrom;
	}

	public String getGoingTo()
	{
		return mGoingTo;
	}

	public void setGoingTo( String aGoingTo )
	{
		this.mGoingTo = aGoingTo;
	}

	private String mDatetime;
	private String mAirline;
	private String mLeavingFrom;
	private String mGoingTo;
}
