package Util;

import Configuration.*;
import PageGuest.AccomodationData_INPUT;
import PageGuest.TravelData_INPUT;
import org.junit.Test;

import java.lang.*;
import java.lang.System;
import java.util.ArrayList;

/**
 * Created by Andras on 12/07/2016.
 */
public class ConfigurationTest
{
	@Test
	public void ParseConfigurationFileTest() throws Exception
	{
		//CurrencyHelper.Init();
		ArrayList<TravelData_INPUT> lSearchListAirlines = Configuration.getInstance().getSearchListAirlines();
		for( TravelData_INPUT lTDI : lSearchListAirlines )
		{
			System.out.println( lTDI.toString());
		}
		System.out.println( "1----" );
		ArrayList<TravelData_INPUT> lFlightList = Configuration.getInstance().getFlightList();
		for( TravelData_INPUT lTDI : lFlightList )
		{
			System.out.println( lTDI.toString());
		}
		System.out.println( "2----" );
		ArrayList<Recipient> lRecipientList = Configuration.getInstance().getRecipientList();
		for( Recipient lRecipient : lRecipientList )
		{
			System.out.println( lRecipient.toString());
		}
		System.out.println( "3----" );
		ArrayList<AccomodationData_INPUT> lSearchListAccom = Configuration.getInstance().getSearchListAccom();
		for( AccomodationData_INPUT lADI : lSearchListAccom )
		{
			System.out.println( lADI.toString());
		}
	}
}