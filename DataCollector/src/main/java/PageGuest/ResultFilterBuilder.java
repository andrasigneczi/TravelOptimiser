package PageGuest;

/**
 * Created by Andras on 01/10/2016.
 */
public class ResultFilterBuilder
{
	private static ResultFilter mFilter = null;

	public enum ResultFilterType
	{
		Day
	}

	public static void Create( final ResultFilterType aType )
	{
		switch( aType )
		{
			case Day:
				mFilter = new DayResultFilter();
				break;
		}
	}

	public static ResultFilter Release()
	{
		ResultFilter lResult = mFilter;
		mFilter = null;
		return lResult;
	}

	public static void set( final String aAttributeName, final String aAttributeValue )
	{
		mFilter.set( aAttributeName, aAttributeValue );
	}
}
