package PageGuest;

import Storage.AccomodationDataResultComposer_SQLite;
import Storage.TravelDataResultComposer_HTML;
import Storage.TravelDataResultComposer_SQLite;

import java.time.LocalDateTime;

/**
 * Created by Andras on 18/07/2017.
 */
public abstract class AccomodationDataResultComposer
{
	protected AccomodationData_RESULT mResult;

	protected AccomodationDataResultComposer( AccomodationData_RESULT aResult )
	{
		mResult = aResult;
	}

	public abstract String toFormattedString();

	protected LocalDateTime DateTimeCorrection( LocalDateTime aLocalDateTime )
	{
		return aLocalDateTime;
	}

	public static AccomodationDataResultComposer Create( AccomodationData_RESULT aResult, String aType )
	{
		if( aType.equalsIgnoreCase( "sqlite" ))
		{
//			if( aResult.mAirline.equalsIgnoreCase( "wizzair" ) )
//				return new TravelDataResultComposer_Wizzair_SQLite( aResult );
//			else
			return new AccomodationDataResultComposer_SQLite( aResult );
		}
		else if( aType.equalsIgnoreCase( "html" ))
		{
//			if( aResult.mAirline.equalsIgnoreCase( "wizzair" ) )
//				return new TravelDataResultComposer_Wizzair_HTML( aResult );
//			else
			//return new TravelDataResultComposer_HTML( aResult );
		}
		return null;
	}
}
