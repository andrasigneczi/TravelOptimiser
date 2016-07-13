package Util;

import PageGuest.TravelData_INPUT;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by Andras on 12/07/2016.
 */
public class ConfigurationTest
{
	@Test
	public void ParseConfigurationFileTest() throws Exception
	{
		CurrencyHelper.Init();
		ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
		for( TravelData_INPUT lTDI : lSearchList )
		{
			if( lTDI.mDepartureDay.equals( "2016.09.09." ))
			{
				lTDI = lTDI;
			}
		}
	}
}