package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;

/**
 * Created by Andras on 30/03/2016.
 */
public class TravelDataResultComposer_SQL extends TravelDataResultComposer
{
	public TravelDataResultComposer_SQL( TravelData_RESULT aResult )
	{
		super( aResult );
	}

	public String getSearchRecordIdString()
	{
		String lSql;

		lSql = "SELECT ID FROM Search WHERE AirportCode_LeavingFrom='" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAirportCode_LeavingFrom ) + "' " +
				"AND AirportCode_GoingTo='" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAirportCode_GoingTo ) + "' " +
				"AND DepartureDay='" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mDepartureDay ) + "' "+
				"AND ReturnDay='" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mReturnDay ) + "' " +
				"AND AdultNumber=" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAdultNumber ) + " " +
				"AND ChildNumber=" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mChildNumber ) + " " +
				"AND InfantNumber=" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mInfantNumber ) + " " +
				"AND NearbyAirports=" + (mResult.mTravelDataInput.mNearbyAirports ? 1 : 0) + ";";
		return lSql;
	}

	public String insertNewSearchString()
	{
		String lSQL = "INSERT INTO Search(\n" +
				"AirportCode_LeavingFrom,\n" +
				"AirportCode_GoingTo,\n" +
				"DepartureDay,\n" +
				"ReturnDay,\n" +
				"AdultNumber,\n" +
				"ChildNumber,\n" +
				"InfantNumber,\n" +
				"NearbyAirports)\n" +
				"VALUES(\n'" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAirportCode_LeavingFrom ) + "', '" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAirportCode_GoingTo ) + "', '" +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mDepartureDay ) + "', '"+
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mReturnDay ) + "', " +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mAdultNumber ) + ", " +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mChildNumber ) + ", " +
				Util.StringHelper.escapeSQL( mResult.mTravelDataInput.mInfantNumber ) + ", " +
				( mResult.mTravelDataInput.mNearbyAirports ? 1 : 0 )+
				");\n";
		return lSQL;
	}

	public String getTravelDataResultRecordIdString( int aSearchId )
	{
		String lSql;

		lSql = "SELECT ID FROM TravelDataResult WHERE Airline='" +
				Util.StringHelper.escapeSQL( mResult.mAirline ) + "' AND " +
				"AirportCode_LeavingFrom='" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_LeavingFrom ) + "' AND " +
				"AirportCode_GoingTo='" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_GoingTo ) + "' AND " +
				"Search_ID=" + aSearchId + ";";
		return lSql;
	}

	public String insertTravelDataResultString( int aSearchId )
	{
		String lSQL ="INSERT INTO TravelDataResult (\n" +
				"Airline, AirportCode_LeavingFrom, AirportCode_GoingTo, Search_ID) \n" +
				"VALUES(\n '" +
				Util.StringHelper.escapeSQL( mResult.mAirline + "', '" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_LeavingFrom ) + "', '" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_GoingTo ) + "', " +
				aSearchId + ");\n";
		return lSQL;
	}

	public String insertTravelDataResult_PossibleTrips( TravelData_RESULT.TravelData_PossibleTrips aTrip,  int aTravelDataResultId )
	{
		String lSQL = "INSERT INTO TravelDataResult_PossibleTrips (\n" +
				"\tDepartureDatetime         ,\n" +     // 2016.03.25 17:10
				"\tArrivalDatetime           ,\n" +     // 2016.03.25 22:10
				"\tPrices_BasicFare_Normal   ,\n" +
				"\tPrices_BasicFare_Discount ,\n" +
				"\tPrices_PlusFare_Normal    ,\n" +
				"\tPrices_PlusFare_Discount  ,\n" +
				"\tOutboundTrip              ,\n" +
				"\tSearchDatetime            ,\n" +
				"\tTravelDataResult_ID       )\n" +
				"VALUES(\n'" + aTrip.mDepartureDatetime + "', '" +
				aTrip.mArrivalDatetime + "', '" +
				aTrip.mPrices_BasicFare_Normal + "', '" +
				aTrip.mPrices_BasicFare_Discount + "', '" +
				aTrip.mPrices_PlusFare_Normal + "', '" +
				aTrip.mPrices_PlusFare_Discount + "', '" +
				aTrip.mOutboundTrip + "', " +
				"date('now')," +
				aTravelDataResultId + ");\n";


		return lSQL;
	}

	public String toFormattedString()
	{

		return null;
	}
}
