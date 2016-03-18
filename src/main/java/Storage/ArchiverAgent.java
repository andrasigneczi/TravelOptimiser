package Storage;

import PageGuest.TravelData_RESULT;

/**
 * Created by Andras on 17/03/2016.
 */
public abstract class ArchiverAgent
{
	private ArchiverAgent mNextAgent = null;
	final public void setNextAgent( ArchiverAgent aAgent )
	{
		mNextAgent = aAgent;
	}

	abstract protected void WriteData( TravelData_RESULT aResult );

	public void Archive( final TravelData_RESULT aResult )
	{
		if( aResult == null )
			return;
		WriteData( aResult );
		if( mNextAgent != null )
			mNextAgent.Archive( aResult );
	}
}
