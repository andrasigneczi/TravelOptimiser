package Favorites;

import Util.Util;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 10/10/2016.
 */
public class FavouriteStorage_File implements FavouritesStorage
{
	private static Logger mLogger = LoggerFactory.getLogger(FavouriteStorage_File.class);

	private final static String mFileName = "favourite_flights.txt";

	@Override
	public TreeSet<String> LoadFavourites()
	{
		TreeSet<String> lTrips = new TreeSet<>(new TripStringComparator());
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
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
			return lTrips;
		}
		catch( java.util.NoSuchElementException e )
		{
			lScanner.close();
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
			return lTrips;
		}

		Pattern lReg = Pattern.compile( "^(.+)$", Pattern.MULTILINE );
		Matcher lMatch = lReg.matcher( lContent );
		while( lMatch.find() )
		{
			String lRow = lMatch.group().toString().trim();
			lTrips.add( lRow );
		}
		return lTrips;
	}

	@Override
	public void SaveFavourites( TreeSet<String> aTrips )
	{
		try
		{
			final PrintWriter writer = new PrintWriter( mFileName, "UTF-8" );
			aTrips.stream().forEach( (trip) -> writer.println(trip) );
			writer.close();
		}
		catch( FileNotFoundException e )
		{
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
		}
		catch( UnsupportedEncodingException e )
		{
			mLogger.error( "Favourite loading error: " + Util.getTraceInformation( e ));
		}
	}
}
