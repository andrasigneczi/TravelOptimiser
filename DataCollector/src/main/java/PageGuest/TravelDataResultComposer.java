package PageGuest;

import Storage.TravelDataResultComposer_HTML;
import Storage.TravelDataResultComposer_SQLite;

import java.time.LocalDateTime;

/**
 * Created by Andras on 18/03/2016.
 */
public abstract class TravelDataResultComposer
{
	protected TravelData_RESULT mResult;

	protected TravelDataResultComposer( TravelData_RESULT aResult )
	{
		mResult = aResult;
	}

	public abstract String toFormattedString();

	protected LocalDateTime DateTimeCorrection( LocalDateTime aLocalDateTime )
	{
		return aLocalDateTime;
	}

	public static TravelDataResultComposer Create( TravelData_RESULT aResult, String aType )
	{
		if( aType.equalsIgnoreCase( "sqlite" ))
		{
//			if( aResult.mAirline.equalsIgnoreCase( "wizzair" ) )
//				return new TravelDataResultComposer_Wizzair_SQLite( aResult );
//			else
				return new TravelDataResultComposer_SQLite( aResult );
		}
		else if( aType.equalsIgnoreCase( "html" ))
		{
//			if( aResult.mAirline.equalsIgnoreCase( "wizzair" ) )
//				return new TravelDataResultComposer_Wizzair_HTML( aResult );
//			else
				return new TravelDataResultComposer_HTML( aResult );
		}
		return null;
	}
}
