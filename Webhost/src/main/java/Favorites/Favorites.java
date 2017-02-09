package Favorites;

import Util.OneWayTrip;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;

/**
 * Created by Andras on 10/06/2016.
 */
public class Favorites
{
	private static Logger mLogger = LoggerFactory.getLogger(Favorites.class);
	private ArrayList<String> mTrips = new ArrayList<>();

	private final static Favorites mInstance = new Favorites();

	private static FavouritesStorage mStorage;

	public static Favorites getInstance()
	{
		return mInstance;
	}

	private Favorites()
	{
		mStorage = new FavouriteStorage_File();
	}

	public void LoadFavourites()
	{
		mTrips = mStorage.LoadFavourites();
	}

	public void SaveFavourites()
	{
		mStorage.SaveFavourites( mTrips );
	}

	/**
	 * Store a one way or a return trip
	 * @param aTrip1 Outbound trip
	 * @param aTrip2 Inbound trip or null
	 */
	public void add( OneWayTrip aTrip1, OneWayTrip aTrip2 )
	{
		if( aTrip1 == null )
			return;
		if( aTrip2 == null )
			mTrips.add( aTrip1.toString());
		else
			mTrips.add( aTrip1.toString() + "&" + aTrip2.toString() );
	}

	/**
	 * Remove a stored one way or a return trip
	 * @param aTrip1 Outbound trip
	 * @param aTrip2 Inbound trip or null
	 */
	public void remove( OneWayTrip aTrip1, OneWayTrip aTrip2 )
	{
		String lTrip = "";
		if( aTrip1 == null )
			return;

		if( aTrip2 == null )
			lTrip = aTrip1.toString();
		else
			lTrip = aTrip1.toString() + "&" + aTrip2.toString();

		for( int i = 0; i < mTrips.size(); i++ )
		{
			if( mTrips.get( i ).equals( lTrip ))
			{
				mTrips.remove( i );
				break;
			}
		}
	}

	public void remove( int aIndex )
	{
		if( aIndex < 0 || aIndex >= mTrips.size() )
			return;
		mTrips.remove( aIndex );
	}

	public boolean contains( OneWayTrip aTrip1, OneWayTrip aTrip2 )
	{
		String lTrip = "";
		if( aTrip1 == null )
			return false;

		if( aTrip2 == null )
			lTrip = aTrip1.toString();
		else
			lTrip = aTrip1.toString() + "&" + aTrip2.toString();

		for( int i = 0; i < mTrips.size(); i++ )
		{
			if( mTrips.get( i ).indexOf( lTrip ) != -1 )
				return true;
		}
		return false;
	}

	public OneWayTrip[] getFromSource( String aTripString )
	{
		int lSeparatorIndex = aTripString.indexOf( "&" );

		if( lSeparatorIndex != -1 )
		{
			OneWayTrip lTrip1 = OneWayTrip.fromString( aTripString.substring( 0, lSeparatorIndex ));
			OneWayTrip lTrip2 = OneWayTrip.fromString( aTripString.substring( lSeparatorIndex + 1 ));
			return new OneWayTrip[] { lTrip1, lTrip2 };
		}
		else
		{
			OneWayTrip lTrip = OneWayTrip.fromString( aTripString );
			return new OneWayTrip[] { lTrip };
		}
	}

	/**
	 * Get a one way or a return trip from index
	 * @param aIndex
	 * @return
	 */
	public OneWayTrip[] get( int aIndex )
	{
		if( aIndex < 0 || aIndex >= mTrips.size() )
			return null;

		String lTripString = mTrips.get( aIndex );
		return getFromSource( lTripString );
	}

	public String getSource( int aIndex )
	{
		if( aIndex < 0 || aIndex >= mTrips.size() )
			return null;

		return mTrips.get( aIndex );
	}

	public int indexOf( String source )
	{
		for( int i = 0; i < mTrips.size(); i++ )
		{
			if( mTrips.get( i ).equals( source ))
				return i;
		}
		return -1;
	}

	public int size()
	{
		return mTrips.size();
	}

	public void RemoveAll()
	{
		mTrips = new ArrayList<>();
	}
}
