package StorageTest;

import Favorites.Favorites;
import Favorites.OneWayTrip;
import Storage.EmailNotifierAgent;
import Storage.SQLiteAgent;
import Util.GMailSender;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.junit.Assert.assertTrue;

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
		GMailSender lGmailSender = new GMailSender();
		EmailNotifierAgent lEmailNotifierAgent = new EmailNotifierAgent( lSQLiteAgent, lGmailSender );

		for( int i = 0; i < lFavorites.size(); i++ )
		{
			lEmailNotifierAgent.LoadNewestEarlierTripData( lFavorites.get( i )[0] );
		}
	}

	@Test
	public void PriceTest()
	{
		double aPriceDrop = 1.000E-08;
		double mNewPrice = 34.24345546646;
		final double mPriceDropTreshold = 10000;
		Double lPriceDropTresholdDouble = Double.parseDouble( "10" );
		assertFalse( lPriceDropTresholdDouble <= aPriceDrop );

		Double lPriceLimitDouble = Double.parseDouble( "20" );
		assertFalse( lPriceLimitDouble >= mNewPrice );

		assertFalse( mPriceDropTreshold <= aPriceDrop );
	}
}