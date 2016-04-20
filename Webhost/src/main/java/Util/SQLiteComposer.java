package Util;

/**
 * Created by Andras on 13/04/2016.
 */
public class SQLiteComposer implements SQLComposer
{
	public SQLiteComposer()
	{

	}

	public String GetTripQuery( String aDateTime, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency )
	{
		String lQueryTemplate =
				"SELECT\n" +
				"    Airline,\n" +
				"    AirportCode_LeavingFrom,\n" +
				"    AirportCode_GoingTo,\n" +
				"    OutboundTrip,\n" +
				"\tDepartureDatetime,\n" +
				"\tArrivalDatetime,\n" +
				"\tPrices_BasicFare_Discount,\n" +
				"\tSearchDatetime,\n" +
				"\tSearch_ID\n" +
				"FROM\n" +
				"\tTravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT\n" +
				"WHERE\n" +
				"\tTDR.ID=TDR_PT.TravelDataResult_ID\n" +
				"\tAND TDR_PT.DepartureDatetime like '[DDATETIME]'\n" +
				"\tAND TDR.Airline = '[AIRLINE]'\n" +
				"\tAND ((\n" +
				"\t\tTDR.AirportCode_LeavingFrom='[AIRPORT_FROM]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo='[AIRPORT_TO]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='true'\n" +
				"\t) OR (\n" +
				"\t\tTDR.AirportCode_LeavingFrom='[AIRPORT_TO]'\n" +
				"\t\tAND TDR.AirportCode_GoingTo='[AIRPORT_FROM]'\n" +
				"\t\tAND TDR_PT.OutboundTrip='false'\n" +
				"\t))\n" +
				"AND Prices_BasicFare_Discount LIKE '% " + aCurrency + "'\n" +
				"ORDER BY DepartureDatetime ASC, OutboundTrip DESC, SearchDatetime ASC;\n";

		return lQueryTemplate.replace( "[DDATETIME]", aDateTime ).replace( "[AIRLINE]", aAirline )
				.replace( "[AIRPORT_FROM]", aAirportFrom ).replace( "[AIRPORT_TO]", aAirportTo );
	}

	public String GetTripDateListQuery()
	{
		return "SELECT DISTINCT(DepartureDatetime) FROM TravelDataResult_PossibleTrips ORDER BY 1 ASC;";
	}

	public String GetDepartureAirportListQuery()
	{
		return "SELECT DISTINCT AirportCode_LeavingFrom,AirportCode_GoingTo, OutboundTrip " +
				"FROM " +
				"TravelDataResult TDR, TravelDataResult_PossibleTrips TDR_PT " +
				"WHERE " +
				"TDR.ID=TDR_PT.TravelDataResult_ID";
	}
}
