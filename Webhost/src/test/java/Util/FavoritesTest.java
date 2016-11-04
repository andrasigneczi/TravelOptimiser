package Util;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by Andras on 12/06/2016.
 */
public class FavoritesTest
{
	@Before
	public void setUp()
	{
		Favorites.getInstance().RemoveAll();
	}

	@Test
	public void add() throws Exception
	{
		OneWayTrip lT1 = new OneWayTrip( "2016-01-01 18:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT2 = new OneWayTrip( "2016-02-01 19:30", "wizzair", "BUD", "CRL", false );
		Favorites lFavorites = Favorites.getInstance();
		assertNotNull( "Favorite instance is null", lFavorites );
		lFavorites.add( lT1, lT2 );
		assertEquals( "Favorite doesn't contain my trips", 1, lFavorites.size() );
	}

	@Test
	public void removeOne() throws Exception
	{
		OneWayTrip lT1 = new OneWayTrip( "2016-01-01 18:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT2 = new OneWayTrip( "2016-02-01 19:30", "wizzair", "BUD", "CRL", false );
		Favorites lFavorites = Favorites.getInstance();
		assertNotNull( "Favorite instance is null", lFavorites );
		lFavorites.add( lT1, lT2 );
		assertEquals( "Favorite doesn't contain my trips", 1, lFavorites.size() );
		lFavorites.remove( lT1, lT2 );
		assertEquals( "Favorite still contains my trips", 0, lFavorites.size() );
	}

	private Favorites prepareSomeWays()
	{
		OneWayTrip lT1 = new OneWayTrip( "2016-01-01 18:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT2 = new OneWayTrip( "2016-02-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT3 = new OneWayTrip( "2016-03-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT4 = new OneWayTrip( "2016-04-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT5 = new OneWayTrip( "2016-05-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT6 = new OneWayTrip( "2016-06-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT7 = new OneWayTrip( "2016-07-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT8 = new OneWayTrip( "2016-08-01 19:30", "wizzair", "BUD", "CRL", false );
		Favorites lFavorites = Favorites.getInstance();
		assertNotNull( "Favorite instance is null", lFavorites );
		lFavorites.add( lT1, lT2 );
		lFavorites.add( lT3, lT4 );
		lFavorites.add( lT5, lT6 );
		lFavorites.add( lT7, null );
		lFavorites.add( lT8, null );
		return lFavorites;
	}

	@Test
	public void removeMore() throws Exception
	{
		OneWayTrip lT1 = new OneWayTrip( "2016-01-01 18:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT2 = new OneWayTrip( "2016-02-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT3 = new OneWayTrip( "2016-03-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT4 = new OneWayTrip( "2016-04-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT5 = new OneWayTrip( "2016-05-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT6 = new OneWayTrip( "2016-06-01 19:30", "wizzair", "BUD", "CRL", false );
		OneWayTrip lT7 = new OneWayTrip( "2016-07-01 19:30", "wizzair", "BUD", "CRL", true );
		OneWayTrip lT8 = new OneWayTrip( "2016-08-01 19:30", "wizzair", "BUD", "CRL", false );
		Favorites lFavorites = Favorites.getInstance();
		assertNotNull( "Favorite instance is null", lFavorites );
		lFavorites.add( lT1, lT2 );
		lFavorites.add( lT3, lT4 );
		lFavorites.add( lT5, lT6 );
		lFavorites.add( lT7, null );
		lFavorites.add( lT8, null );

		assertEquals( "Favorite doesn't contain my trips", 5, lFavorites.size() );
		lFavorites.remove( lT1, lT2 );
		assertEquals( "Favorite still contains my trips", 4, lFavorites.size() );
		lFavorites.remove( lT8, null );
		assertEquals( "Favorite still contains my trips", 3, lFavorites.size() );

		String lTString1 = lT1.toString() + "&" + lT2.toString();
		String lTString2 = lT8.toString();
		for( int i = 0; i < lFavorites.size(); i++ )
		{
			OneWayTrip[] lTrips = lFavorites.get( i );
			assertNotNull( "lTrips must be none null", lTrips );
			assertTrue( "Length must be 1 or 2", lTrips.length == 1 || lTrips.length == 2 );
			if( lTrips.length == 1 )
			{
				assertFalse( "The trip was removed", lTrips[ 0 ].toString().equals( lTString2 ) );
			}
			else
			{
				assertFalse( "The trip was removed", (lTrips[ 0 ].toString() + "&" + lTrips[ 1 ].toString()).equals( lTString1 ) );
			}
		}
	}

	@Test
	public void loadAndSave() throws Exception
	{
		Favorites lFavorites = prepareSomeWays();
		lFavorites.SaveFavourites();
		assertTrue( "Favorite file does not exist.", new java.io.File( "favourite_flights.txt" ).exists() );

		int lOldSize = lFavorites.size();

		ArrayList<OneWayTrip[]> lTrips = new ArrayList<>();
		for( int i = 0; i < lFavorites.size(); i++ )
		{
			lTrips.add( lFavorites.get( i ));
		}

		lFavorites.LoadFavourites();
		assertEquals( "The loaded list size does not equal with the new size", lOldSize, lFavorites.size() );

		for( int i = 0; i < lFavorites.size(); i++ )
		{
			OneWayTrip[] lTrip1 = lFavorites.get( i );
			OneWayTrip[] lTrip2 = lTrips.get( i );
			assertEquals( "The trip at index " + i + " is not equals", lTrip1.length, lTrip2.length );

			if( lTrip1.length == 1 )
			{
				assertTrue( "The two trips are not the same", lTrip1[ 0 ].toString().equals( lTrip2[ 0 ].toString() ) );
			}
			else
			{
				assertTrue( "The two trips are not the same", (lTrip1[ 0 ].toString() + "&" + lTrip1[ 1 ].toString())
						.equals( lTrip2[ 0 ].toString() + "&" + lTrip2[ 1 ].toString() ) );
			}

		}
	}

}