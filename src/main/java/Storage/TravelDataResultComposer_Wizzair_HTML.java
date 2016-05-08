package Storage;

import PageGuest.TravelData_RESULT;

import java.time.LocalDateTime;

/**
 * Created by Andras on 08/05/2016.
 */
public class TravelDataResultComposer_Wizzair_HTML extends TravelDataResultComposer_HTML
{
	public TravelDataResultComposer_Wizzair_HTML( TravelData_RESULT aResult )
	{
		super( aResult );
	}

	@Override
	public LocalDateTime DateTimeCorrection( LocalDateTime aLocalDateTime )
	{
		// TODO: why must I add 1 more hour to get the right time?
		return aLocalDateTime.plusHours( 1 );
	}
}
