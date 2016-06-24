package Storage;

import PageGuest.TravelData_RESULT;
import Util.DatetimeHelper;

import java.time.LocalDateTime;

/**
 * Created by Andras on 08/05/2016.
 */
public class TravelDataResultComposer_Wizzair_LiteSQL extends TravelDataResultComposer_LiteSQL
{
	public TravelDataResultComposer_Wizzair_LiteSQL( TravelData_RESULT aResult )
	{
		super( aResult );
	}

	@Override
	public LocalDateTime DateTimeCorrection( LocalDateTime aLocalDateTime )
	{
		return DatetimeHelper.WizzAirDatetimeCorrection( aLocalDateTime );
	}
}
