package Util;

/**
 * Created by Andras on 13/04/2016.
 */
public class SQLiteComposer implements SQLComposer
{
	public SQLiteComposer()
	{

	}

	public String GetTripQuery( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo )
	{
		String lQueryTemplate =
				"SELECT\n" +
				"    Airline,\n" +
				"    AirportCode_LeavingFrom,\n" +
				"    AirportCode_GoingTo,\n" +
                "    Currency_Price_In_Euro, \n" +
				"    OutboundTrip,\n" +
				"\tDepartureDatetime,\n" +
				"\tArrivalDatetime,\n" +
				"\tPrices_BasicFare_Discount,\n" +
				"\tPrices_BasicFare_Normal,\n" +
				"\tSearchDatetime,\n" +
				"\tSearch_ID\n" +
				"FROM\n" +
				"\tTravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT\n" +
				"WHERE\n" +
				"\tTDR.ID=TDR_PT.TravelDataResult_ID\n" +
				"\tAND TDR_PT.DepartureDatetime like '[DDATETIME]'\n" +
				"\tAND TDR.Airline = '[AIRLINE]'\n" +
				"\tAND ((\n" +
				"\t\tTDR.AirportCode_LeavingFrom like '[AIRPORT_FROM]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo like '[AIRPORT_TO]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='true'\n" +
				"\t) OR (\n" +
				"\t\tTDR.AirportCode_LeavingFrom like '[AIRPORT_TO]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo like '[AIRPORT_FROM]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='false'\n" +
				"\t))\n" +
				"ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;\n";

		if( aAirportFrom.equals( "-" ))
			aAirportFrom = "%";

		if( aAirportTo.equals( "-" ))
			aAirportTo = "%";

		String lReturnValue = lQueryTemplate.replace( "[DDATETIME]", aDateTime ).replace( "[AIRLINE]", aAirline )
				.replace( "[AIRPORT_FROM]", aAirportFrom ).replace( "[AIRPORT_TO]", aAirportTo );

		System.out.println( lReturnValue );
		return lReturnValue;
	}

	public String GetTripDateListQuery( String aSelectedDepartureAirport,
	                                    String aSelectedArrivalAirport,
	                                    boolean aReturnCheckboxChecked,
	                                    String  aOutboundDate,
	                                    String  aInboundDate )
	{
		final String lQueryTemlate =
				"SELECT\n" +
				"DISTINCT Airline,\n" +
				"\tDepartureDatetime, \n" +
				"\tAirportCode_LeavingFrom, \n" +
				"\tAirportCode_GoingTo, \n" +
				"\tOutboundTrip \n" +
				"FROM\n" +
				"\tTravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT\n" +
				"WHERE\n" +
				"\tTDR.ID=TDR_PT.TravelDataResult_ID\n" +
				"\tAND ((\n" +
				"\t\tTDR.AirportCode_LeavingFrom LIKE '[DEPARTURE_AIRPORT]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo LIKE '[ARRIVAL_AIRPORT]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='true'\n" +
				"\t\t[OUTBOUND_DATE]\n" +
				"\t) OR (\n" +
				"\t\tTDR.AirportCode_LeavingFrom LIKE '[ARRIVAL_AIRPORT]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo LIKE '[DEPARTURE_AIRPORT]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='false'\n" +
				"\t\t[INBOUND_DATE]\n" +
				"\t))\n" +
				"ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;\n";

		String lReturnValue = lQueryTemlate;
		if( aReturnCheckboxChecked )
		{
			lReturnValue = lReturnValue.replace( "\t\tAND TDR_PT.OutboundTrip='false'\n", "" );
			lReturnValue = lReturnValue.replace( "\t\tAND TDR_PT.OutboundTrip='true'\n", "" );
		}

		if( aInboundDate.length() > 0 && aOutboundDate.length() > 0 )
		{
			lReturnValue = lReturnValue.replace( "[OUTBOUND_DATE]", "AND DepartureDatetime LIKE '" + aOutboundDate + "%'" );
			lReturnValue = lReturnValue.replace( "[INBOUND_DATE]",  "AND DepartureDatetime LIKE '" + aInboundDate  + "%'" );
		}
		else if( aOutboundDate.length() > 0 )
		{
			lReturnValue = lReturnValue.replace( "[OUTBOUND_DATE]", "AND DepartureDatetime LIKE '" + aOutboundDate + "%'" );
			lReturnValue = lReturnValue.replace( "[INBOUND_DATE]",  "AND DepartureDatetime LIKE '" + aOutboundDate + "%'" );
		}

		lReturnValue = lReturnValue.replace( "[OUTBOUND_DATE]", "" );
		lReturnValue = lReturnValue.replace( "[INBOUND_DATE]", "" );

		if( aSelectedDepartureAirport.length() > 1 && aSelectedArrivalAirport.length() > 1 )
		{
			lReturnValue = lReturnValue.replace( "[DEPARTURE_AIRPORT]", aSelectedDepartureAirport )
					.replace( "[ARRIVAL_AIRPORT]", aSelectedArrivalAirport );
			System.out.println( lReturnValue );
			return lReturnValue;
		}
		else if( aSelectedDepartureAirport.length() > 1 )
		{
			lReturnValue = lReturnValue.replace( "[DEPARTURE_AIRPORT]", aSelectedDepartureAirport )
					.replace( "[ARRIVAL_AIRPORT]", "%" );
			System.out.println( lReturnValue );
			return lReturnValue;
		}
		else if( aSelectedArrivalAirport.length() > 1 )
		{
			lReturnValue = lReturnValue.replace( "[DEPARTURE_AIRPORT]", "%" )
					.replace( "[ARRIVAL_AIRPORT]", aSelectedArrivalAirport );
			System.out.println( lReturnValue );
			return lReturnValue;
		}

		lReturnValue = lReturnValue.replace( "[DEPARTURE_AIRPORT]", "%" )
				.replace( "[ARRIVAL_AIRPORT]", "%" );

		System.out.println( lReturnValue );
		return lReturnValue;
	}

	public String GetDepartureAirportListQuery()
	{
		return "SELECT DISTINCT AirportCode_LeavingFrom,AirportCode_GoingTo, OutboundTrip " +
				"FROM " +
				"TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT " +
				"WHERE " +
				"TDR.ID=TDR_PT.TravelDataResult_ID";
	}

	public String GetArrivalAirportListQuery( String aSelectedDepartureAirport )
	{
		return GetDepartureAirportListQuery();
	}
}
