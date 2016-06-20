package Util;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Andras on 19/06/2016.
 */
public class DatetimeHelperTest
{
	@Test
	public void convertFromWizzairJSONStoredFormat() throws Exception
	{
		String lResult = DatetimeHelper.ConvertFromWizzairJSONStoredFormat( "20160103 8:33" );
		assertTrue( lResult.equals( "2016-01-03T08:33:00" ) );

		lResult = DatetimeHelper.ConvertFromWizzairJSONStoredFormat( "20160103 18:33" );
		assertTrue( lResult.equals( "2016-01-03T18:33:00" ) );
	}

}