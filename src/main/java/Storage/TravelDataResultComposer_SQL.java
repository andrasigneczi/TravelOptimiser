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

	public String toFormattedString()
	{
		String lSQL;

		lSQL = "SELECT ID FROM Search WHERE AirportCode_LeavingFrom=\"" + mResult.mTravelDataInput.mAirportCode_LeavingFrom + "\" " +
											"AND AirportCode_GoingTo=\"" + mResult.mTravelDataInput.mAirportCode_GoingTo + "\" " +
											"AND DepartureDay=\"" + mResult.mTravelDataInput.mDepartureDay + "\" "+
											"AND ReturnDay=\"" + mResult.mTravelDataInput.mReturnDay + "\" " +
											"AND AdultNumber=\"" + mResult.mTravelDataInput.mAdultNumber + "\" " +
											"AND ChildNumber=\"" + mResult.mTravelDataInput.mChildNumber + "\" " +
											"AND InfantNumber=\"" + mResult.mTravelDataInput.mInfantNumber + "\" " +
											"AND NearbyAirports=\"" + mResult.mTravelDataInput.mNearbyAirports + "\";";
		// if ID exists, then INSERT INTO Search_datetime
		// else INSERT INTO Search, after that INSERT INTO Search_datetime
		// TravelDataResult
		// TravelDataResult_PossibleTrips

		lSQL = "INSERT INTO Search(\n" +
				"AirportCode_LeavingFrom,\n" +
				"AirportCode_GoingTo,\n" +
				"DepartureDay,\n" +
				"ReturnDay,\n" +
				"AdultNumber,\n" +
				"ChildNumber,\n" +
				"InfantNumber,\n" +
				"NearbyAirports)\n" +
				"VALUES(\n" +
				");\n";

		//mResult.mTravelDataInput.mAirline;
		//mResult.mTravelDataInput.mAirportCode_LeavingFrom;
		//mResult.mTravelDataInput.mAirportCode_GoingTo;

		return null;
	}
}
