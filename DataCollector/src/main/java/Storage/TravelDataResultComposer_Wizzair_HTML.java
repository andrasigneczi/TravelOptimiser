package Storage;

import PageGuest.TravelData_RESULT;
import Util.DatetimeHelper;

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
		return DatetimeHelper.WizzAirDatetimeCorrection( aLocalDateTime );
	}
}