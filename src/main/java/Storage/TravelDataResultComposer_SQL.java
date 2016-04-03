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
				"AND NearbyAirports=" + mResult.mTravelDataInput.mNearbyAirports + ";";
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
				mResult.mTravelDataInput.mNearbyAirports +
				");\n";
		return lSQL;
	}

	public String getTravelDataResultRecordIdString( int aSearchId )
	{
		String lSql;

		lSql = "SELECT ID FROM TravelDataResult WHERE Airline='" +
				Util.StringHelper.escapeSQL( mResult.mAirline ) + "' " +
				"AirportCode_LeavingFrom='" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_LeavingFrom ) + "' " +
				"AirportCode_GoingTo='" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_GoingTo ) + "' " +
				"Search_ID=" + aSearchId + ";";
		return lSql;
	}

	public String insertTravelDataResultString( int aSearchId )
	{
		String lSQL ="INSERT INTO TravelDataResult (\n" +
				"AirportCode_LeavingFrom, AirportCode_GoingTo, Search_ID) \n" +
				"VALUES(\n '" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_LeavingFrom ) + "', '" +
				Util.StringHelper.escapeSQL( mResult.mAirportCode_GoingTo ) + "', " +
				aSearchId + ");\n";
		return lSQL;
	}

	public String insertTravelDataResult_PossibleTrips( int aTravelDataResultId )
	{
		return "";
	}

	public String toFormattedString()
	{

		return null;
	}
}
