package Util;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 10/06/2016.
 */
public class Favorites
{
	private ArrayList<String> mTrips = new ArrayList<>();
	private final static String mFileName = "favourite_flights.txt";

	private final static Favorites mInstance = new Favorites();

	public static Favorites getInstance()
	{
		return mInstance;
	}

	private Favorites()
	{

	}

	public void LoadFavourites()
	{
		mTrips = new ArrayList<>();
		Scanner lScanner = null;
		String lContent;
		try
		{
			lScanner = new Scanner( new File( mFileName ), "UTF-8" ).useDelimiter( "\\A" );
			lContent = lScanner.next();
			lScanner.close();
		}
		catch( FileNotFoundException e )
		{
			e.printStackTrace();
			return;
		}

		Pattern lReg = Pattern.compile( "^(.+)$", Pattern.MULTILINE );
		Matcher lMatch = lReg.matcher( lContent );
		while( lMatch.find() )
		{
			String lRow = lMatch.group().toString().trim();
			mTrips.add( lRow );
		}
	}

	public void SaveFavourtes()
	{
		try
		{
			final PrintWriter writer = new PrintWriter( mFileName, "UTF-8" );
			mTrips.stream().forEach( (trip) -> writer.println(trip) );
			writer.close();
		}
		catch( FileNotFoundException e )
		{
			e.printStackTrace();
		}
		catch( UnsupportedEncodingException e )
		{
			e.printStackTrace();
		}
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
			if( mTrips.get( i ).equals( lTrip ))
				return true;
		}
		return false;
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
		int lSeparatorIndex = lTripString.indexOf( "&" );

		if( lSeparatorIndex != -1 )
		{
			OneWayTrip lTrip1 = OneWayTrip.fromString( lTripString.substring( 0, lSeparatorIndex ));
			OneWayTrip lTrip2 = OneWayTrip.fromString( lTripString.substring( lSeparatorIndex + 1 ));
			return new OneWayTrip[] { lTrip1, lTrip2 };
		}
		else
		{
			OneWayTrip lTrip = OneWayTrip.fromString( lTripString );
			return new OneWayTrip[] { lTrip };
		}
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
