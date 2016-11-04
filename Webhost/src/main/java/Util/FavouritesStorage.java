package Util;

import java.util.ArrayList;

/**
 * Created by Andras on 10/10/2016.
 */
public interface FavouritesStorage
{
	public ArrayList<String> LoadFavourites();
	public void SaveFavourites( ArrayList<String> aTrips );
}
