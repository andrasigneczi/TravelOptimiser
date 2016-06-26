package PageGuest;

import Root.PageGuestFactory;
import Util.CurrencyHelper;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Andras on 19/05/2016.
 */
public class WizzAirPageGuestTest
{
	@Test
	public void doSearch() throws Exception
	{
		CurrencyHelper.Init();
		Util.Configuration lConfiguration = Util.Configuration.getInstance();
		PageGuest lGuestW = PageGuestFactory.Create( "Wizzair" );
		Thread.sleep( 1000 );
		lGuestW.stop();

		// By airportcode
		// public void DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )

		// by name
		lGuestW.DoSearchByAirportName( "bari", "Brüsszel",
				"2017.01.01.", "2017.02.02." );
		TravelData_INPUT lResult = lGuestW.popSearchQueue();

		assertNotNull( "The search request isn't in the queue", lResult );
		assertTrue( "Outbound airport is wrong 1", lResult.mAirportCode_LeavingFrom.equals( "BRI" ));
		assertTrue( "Inbound airport is wrong 1", lResult.mAirportCode_GoingTo.equals( "CRL" ));

		lGuestW.DoSearchByAirportName( "palma", "Párizs",
				"2017.01.01.", "2017.02.02." );
		lResult = lGuestW.popSearchQueue();
		assertNotNull( "The search request isn't in the queue", lResult );
		assertTrue( "Outbound airport is wrong 2", lResult.mAirportCode_LeavingFrom.equals( "PMI" ));
		assertTrue( "Inbound airport is wrong 2", lResult.mAirportCode_GoingTo.equals( "BVA" ));
	}
}