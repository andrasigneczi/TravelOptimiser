package PageGuestTest;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Andras on 13/06/2017.
 */
public class BookingDotComPageGuestTest
{
	@Test
	public void init() throws Exception
	{
		BookingDotComPageGuest test = new BookingDotComPageGuest();
		test.Init();
		test.WaitForFinish();
	}
}