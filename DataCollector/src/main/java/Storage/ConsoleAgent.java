package Storage;

import PageGuest.AccomodationData_RESULT;
import PageGuest.TravelData_RESULT;

/**
 * Created by Andras on 17/03/2016.
 */
public class ConsoleAgent extends ArchiverAgent
{
	@Override
	protected void WriteData( Object aResult )
	{
		System.out.println( aResult );
	}
}
