package Util;

/**
 * Created by Andras on 28/04/2016.
 */
public class ToggledButton
{
	public ToggledButton( String aDatetime, String aAirline, String aLeavingFrom, String aGoingTo, boolean aOutbound )
	{
		mDatetime    = aDatetime;
		mAirline     = aAirline;
		mLeavingFrom = aLeavingFrom;
		mGoingTo     = aGoingTo;
		mOutbound    = aOutbound;
	}

	@Override
	public boolean equals( Object aObject )
	{
		boolean lSame = false;

		if( aObject != null && aObject instanceof ToggledButton )
		{
			ToggledButton aToggledButton = (ToggledButton)aObject;
			if( mAirline.equals( aToggledButton.getAirline() ) &&
					mDatetime.equals( aToggledButton.getDatetime() ) )
			{
				if( mOutbound == aToggledButton.mOutbound )
				{
					if( mLeavingFrom.equals( aToggledButton.getLeavingFrom() ) &&
							mGoingTo.equals( aToggledButton.getGoingTo() ) )
						lSame = true;
				}
				else
				{
					if( mLeavingFrom.equals( aToggledButton.getGoingTo() ) &&
							mGoingTo.equals( aToggledButton.getLeavingFrom() ) )
						lSame = true;
				}
			}
		}
		return lSame;
	}

	@Override
	public String toString()
	{
		return getAirline() + "|" +
				getDatetime() + "|" +
				getOutboundDepartureAirport() + "|" +
				getOutboundArrivalAirport();
	}

	@Override
	public int hashCode() {
		return toString().hashCode();
	}

	public String getOutboundDepartureAirport()
	{
		if( getOutbound())
			return mLeavingFrom;
		else
			return mGoingTo;
	}

	public String getOutboundArrivalAirport()
	{
		if( getOutbound())
			return mGoingTo;
		else
			return mLeavingFrom;
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

	public boolean getOutbound()
	{
		return mOutbound;
	}

	public void setOutbound( boolean mOutbound )
	{
		this.mOutbound = mOutbound;
	}

	private String mDatetime;
	private String mAirline;
	private String mLeavingFrom;
	private String mGoingTo;
	private boolean mOutbound;
}
