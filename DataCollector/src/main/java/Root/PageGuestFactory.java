package Root;

import PageGuest.*;

/**
 * Created by Andras on 15/03/2016.
 */
public class PageGuestFactory
{
	public static PageGuest Create( String PageType )
	{
		if( PageType.equalsIgnoreCase( "wizzair" ))
		{
			return new WizzAirPageGuest201911();
		}
		else if( PageType.equalsIgnoreCase( "wizzairtimetable" ))
		{
			return new WizzAirPageGuestTimetable();
		}
		else if( PageType.equalsIgnoreCase( "ryanair" ))
		{
			return new RyanAirPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "momondo" ))
		{
			return new MomondoPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "flibco" ))
		{
			return new FlibcoPageGuest();
		}
		else if( PageType.equalsIgnoreCase( "bulgarianair" ))
		{
			return new BulgarianAirPageGuest();
		}
		return null;
	}
}
