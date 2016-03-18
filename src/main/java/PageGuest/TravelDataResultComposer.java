package PageGuest;

/**
 * Created by Andras on 18/03/2016.
 */
public abstract class TravelDataResultComposer
{
	protected TravelData_RESULT mResult;

	public TravelDataResultComposer( TravelData_RESULT aResult )
	{
		mResult = aResult;
	}

	public abstract String toFormattedString();
}
