package PageGuest;

import Util.DatetimeHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;

/**
 * Created by Andras on 01/10/2016.
 */
public class DayResultFilter implements ResultFilter
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( DayResultFilter.class);

	enum Methods { Accept, Deny };
	enum Directions { Outbound, Inbound, Both };

	private String mAffectedDays = "";
	private Methods mMethod = Methods.Accept;
	private ArrayList<DayOfWeek> mDays = null;
	private Directions mDirection = Directions.Both;

	/**
	 * Expected date format: YYYY-MM-DD
	 * If a the Method is Accept, the day will pass the test, if the day is
	 * equal with one of the affected days.
	 * If a the Method is Deny, the day will pass the test, if it is
	 * not among the affected days.
	 * @param aDay
	 * @return
	 */
	@Override
	public boolean testADay( String aDay, boolean aOutbound )
	{
		if( aOutbound && mDirection == Directions.Inbound )
			return true;

		if( !aOutbound && mDirection == Directions.Outbound )
			return true;

		String lDateArray[] = aDay.split( "-" );
		LocalDate lDate = LocalDate.of( StringHelper.parseInt( lDateArray[ 0 ], 0 ),
				StringHelper.parseInt( lDateArray[ 1 ], 0 ),
				StringHelper.parseInt( lDateArray[ 2 ], 0 ));

		boolean lDayAccepted = false;
		int lDifferenceCount = 0;
		for( int i = 0; i < mDays.size(); i++ )
		{
			if( mDays.get( i ) == lDate.getDayOfWeek())
			{
				if( mMethod == Methods.Accept )
				{
					lDayAccepted = true;
					break;
				}
				else
				{
					if( mMethod == Methods.Deny )
					{
						break;
					}
				}
			}
			else
			{
				lDifferenceCount++;
			}
		}

		if( mMethod == Methods.Deny && lDifferenceCount == mDays.size() )
		{
			lDayAccepted = true;
		}

		return lDayAccepted;
	}

//	@Override
//	public boolean isTestPassed( TravelData_RESULT.TravelData_PossibleTrip aTrip )
//	{
//		// aTrip.mDepartureDatetime
//		// aTrip.mArrivalDatetime
//
//		boolean lDepartureDayAccepted = true;
//		if( mDirection == Directions.Both || mDirection == Directions.Outbound )
//			lDepartureDayAccepted = testADay( aTrip.mDepartureDatetime );
//
//		boolean lArrivalDayAccepted = true;
//		if( aTrip.mArrivalDatetime.length() > 0 )
//		{
//			if( mDirection == Directions.Both || mDirection == Directions.Inbound )
//				lArrivalDayAccepted = testADay( aTrip.mArrivalDatetime );
//		}
//		return false;
//	}

	@Override
	public void set( String aAttributeName, String aAttributeValue )
	{
		if( aAttributeName.equalsIgnoreCase( "AffectedDays" ))
		{
			mDays = DatetimeHelper.ConvertDayList( aAttributeValue );
		}
		else if( aAttributeName.equalsIgnoreCase( "Method" ))
		{
			if( aAttributeValue.equalsIgnoreCase( "Accept" ))
			{
				mMethod = Methods.Accept;
			}
			else
			{
				if( aAttributeValue.equalsIgnoreCase( "Deny" ))
					mMethod = Methods.Deny;
				else
					mLogger.warn( "Illegal method name: " + aAttributeValue );
			}
		}
		else if( aAttributeName.equalsIgnoreCase( "AffectedDirection" ))
		{
			if( aAttributeValue.equalsIgnoreCase( "Both" ) )
			{
				mDirection = Directions.Both;
			}
			else if( aAttributeValue.equalsIgnoreCase( "Outbound" ) )
			{
				mDirection = Directions.Outbound;
			}
			else if( aAttributeValue.equalsIgnoreCase( "Inbound" ) )
			{
				mDirection = Directions.Inbound;
			}
		}
	}
}
