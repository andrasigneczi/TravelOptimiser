package Storage;

import PageGuest.TravelData_RESULT;
import org.junit.Test;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import static org.junit.Assert.*;

/**
 * Created by Andras on 26/05/2016.
 */
public class TravelDataResultComposer_Wizzair_LiteSQLTest
{
	@Test
	public void dateTimeCorrection() throws Exception
	{
		TravelData_RESULT lTDR = new  TravelData_RESULT();
		TravelDataResultComposer_Wizzair_LiteSQL lTDRC_W = new TravelDataResultComposer_Wizzair_LiteSQL( lTDR );

		DateTimeFormatter mFormatterWizzair;
		mFormatterWizzair = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
		String aValue = "2017-07-01T11:11:11"; // summer, + 1h necessary

		LocalDateTime lLocalDateTime = LocalDateTime.parse(aValue, mFormatterWizzair);
		lLocalDateTime = lTDRC_W.DateTimeCorrection( lLocalDateTime );
		assertTrue( lLocalDateTime.toString().equals( "2017-07-01T12:11:11" ));

		aValue = "2017-11-01T11:11:11"; // winter, + 0h
		lLocalDateTime = LocalDateTime.parse(aValue, mFormatterWizzair);
		lLocalDateTime = lTDRC_W.DateTimeCorrection( lLocalDateTime );
		assertTrue( lLocalDateTime.toString().equals( "2017-11-01T11:11:11" ));
	}

}