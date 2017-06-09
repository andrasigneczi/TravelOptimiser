package PageGuestTest;

import Configuration.Configuration;
import PageGuest.PageGuest;
import PageGuest.TravelData_INPUT;
import Root.PageGuestFactory;
import Util.CurrencyHelper;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Andras on 19/05/2016.
 */
public class RyanAirPageGuestTest
{
	@Test
	public void doSearch() throws Exception
	{
		CurrencyHelper.Init();
		Configuration lConfiguration = Configuration.getInstance();
		PageGuest lGuestR = PageGuestFactory.Create( "RyanAir" );
		Thread.sleep( 1000 );
		lGuestR.stop();

		// By airportcode
		// public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )

		// by name
		lGuestR.DoSearchByAirportName( "bari", "paris (",
				"2017.01.01.", "2017.02.02." );
		TravelData_INPUT lResult = lGuestR.popSearchQueue();

		assertNotNull( "The search request isn't in the queue", lResult );
		assertTrue( "Outbound airport is wrong 1", lResult.mAirportCode_LeavingFrom.equals( "BRI" ));
		assertTrue( "Inbound airport is wrong 1", lResult.mAirportCode_GoingTo.equals( "BVA" ));

		lGuestR.DoSearchByAirportName( "Prag", "Rome (C",
				"2017.01.01.", "2017.02.02." );
		lResult = lGuestR.popSearchQueue();
		assertNotNull( "The search request isn't in the queue", lResult );
		assertTrue( "Outbound airport is wrong 2", lResult.mAirportCode_LeavingFrom.equals( "PRG" ));
		assertTrue( "Inbound airport is wrong 2", lResult.mAirportCode_GoingTo.equals( "CIA" ));
	}

}