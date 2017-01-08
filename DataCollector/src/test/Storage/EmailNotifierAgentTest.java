package Storage;

import Favorites.Favorites;
import Favorites.OneWayTrip;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Andras on 25/12/2016.
 */
public class EmailNotifierAgentTest
{
	@Test
	public void LoadNewestEarlierTripDataTest()
	{
		Favorites lFavorites = Favorites.getInstance();
		lFavorites.LoadFavourites();

		SQLiteAgent lSQLiteAgent = new SQLiteAgent();
		lSQLiteAgent.InitializeDatabase();

		EmailNotifierAgent lEmailNotifierAgent = new EmailNotifierAgent( lSQLiteAgent );

		for( int i = 0; i < lFavorites.size(); i++ )
		{
			lEmailNotifierAgent.LoadNewestEarlierTripData( lFavorites.get( i )[0] );
		}
	}
}