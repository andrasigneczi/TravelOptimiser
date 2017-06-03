package PageGuest;

import org.junit.Test;

/**
 * Created by Andras on 19/06/2016.
 */
public class WizzAirPageGuestTimetableTest
{
	@Test
	public void fillTheForm() throws Exception
	{
		PageGuest.WizzAirPageGuestTimeTable test = new PageGuest.WizzAirPageGuestTimeTable( true );
		TravelData_INPUT aTravelDataInput = new TravelData_INPUT();
		aTravelDataInput.mAirline = "wizzair";
		aTravelDataInput.mAirportCode_LeavingFrom = "CRL";
		aTravelDataInput.mAirportCode_GoingTo = "BUD";
		aTravelDataInput.mDepartureDay = "2016.03.03.";
		aTravelDataInput.mReturnDay = "2016.03.30.";
		aTravelDataInput.mAdultNumber = "1";
		aTravelDataInput.mInfantNumber = "0";
		aTravelDataInput.mChildNumber = "0";
		test.FillTheForm( aTravelDataInput );
	}

}