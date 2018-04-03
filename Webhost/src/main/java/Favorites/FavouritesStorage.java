package Favorites;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.TreeSet;

/**
 * Created by Andras on 10/10/2016.
 */
public interface FavouritesStorage
{
	public TreeSet<String> LoadFavourites();
	public void SaveFavourites( TreeSet<String> aTrips );
	public class TripStringComparator implements Comparator<String>
	{
		public int compare(String s1, String s2) {
			int i1 = s1.indexOf( '|' );
			int i2 = s1.indexOf( '|', i1 + 1 );
			int i3 = s2.indexOf( '|' );
			int i4 = s2.indexOf( '|', i3 + 1 );
			return s1.substring( i1, i2 ).compareToIgnoreCase( s2.substring( i3,i4 ));
		}
	}
}
