package Storage;

import PageGuest.AccomodationDataResultComposer;
import PageGuest.AccomodationData_RESULT;
import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import Util.CurrencyHelper;

import java.time.format.DateTimeFormatter;

/**
 * Created by Andras on 13/07/2017.
 */
public class AccomodationDataResultComposer_SQLite extends AccomodationDataResultComposer
{
	public AccomodationDataResultComposer_SQLite( AccomodationData_RESULT aResult )
	{
		super( aResult );
	}

	@Override
	public String toFormattedString()
	{
		return null;
	}

	public String getSearchRecordIdString()
	{
		String lSql;

		lSql = "SELECT ID FROM AccomodationSearch WHERE Type='" +
				Util.StringHelper.escapeSQL( "" + mResult.mAccomodationData_INPUT.mType ) + "' " +
				"AND Site='" +
				Util.StringHelper.escapeSQL( "" + mResult.mAccomodationData_INPUT.mSite ) + "' " +
				"AND CheckIn='" +
				Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCheckIn ) + "' "+
				"AND CheckOut='" +
				Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCheckOut ) + "' " +
				"AND PriceLimit=" +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mPriceLimit )) + " " +
				"AND City='" +
				Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCity ) + "' " +
				"AND Filters='" +
				Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mFilters ) + "' " +
				"AND RoomNumber=" +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mRoomNumber )) + " " +
				"AND AdultNumber=" +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mAdultNumber )) + " " +
				"AND ChildrenNumber=" +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mChildrenNumber )) + " " +
				"AND ChildrenAge='" +
				Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mChildrenAge.toString()) + "';\n";

		return lSql;
	}

	public String insertNewSearchString()
	{
		String lSQL = "INSERT INTO AccomodationSearch(\n" +
				"Type,\n" +
				"Site,\n" +
				"SearchURL,\n" +
				"CheckIn,\n" +
				"CheckOut,\n" +
				"PriceLimit,\n" +
				"City,\n" +
				"Filters," +
				"RoomNumber," +
				"AdultNumber," +
				"ChildrenNumber," +
				"ChildrenAge)\n" +
				"VALUES(\n" +
				"'" + Util.StringHelper.escapeSQL( "" + mResult.mAccomodationData_INPUT.mType ) + "', " +
				"'" + Util.StringHelper.escapeSQL( "" + mResult.mAccomodationData_INPUT.mSite ) + "', " +
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mSearchURL ) + "', "+
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCheckIn ) + "', " +
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCheckOut ) + "', " +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mPriceLimit )) + ", " +
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mCity ) + "', " +
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mFilters ) + "', " +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mRoomNumber )) + ", " +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mAdultNumber )) + ", " +
				Util.StringHelper.escapeSQL( String.valueOf( mResult.mAccomodationData_INPUT.mChildrenNumber )) + ", " +
				"'" + Util.StringHelper.escapeSQL( mResult.mAccomodationData_INPUT.mChildrenAge.toString() ) + "');\n";
		return lSQL;
	}

	public String getAccomodationDataResultRecordIdString( int aSearchId )
	{
		String lSql;

		lSql = "SELECT ID FROM Accomodation WHERE Name='" +
				Util.StringHelper.escapeSQL( mResult.mName ) + "' AND " +
				"Type='" + mResult.mType + "' AND " +
				"Site='" + mResult.mSite + "' AND " +
				"AccomodationSearch_ID=" + aSearchId + ";";
		return lSql;
	}

	public String insertAccomodationDataResultString( int aSearchId )
	{
		String lSQL ="INSERT INTO Accomodation (\n" +
				"Type, Name, Site, URL, Score, Address, CheckInPolicy, CheckOutPolicy, AccomodationSearch_ID) \n" +
				"VALUES(\n '" +
				mResult.mType +
				"', '" + Util.StringHelper.escapeSQL( mResult.mName ) +
				"', '" + mResult.mSite +
				"', '" + Util.StringHelper.escapeSQL( mResult.mURL ) +
				"', " + mResult.mScore +
				", '" + Util.StringHelper.escapeSQL( mResult.mAddress ) +
				"', '" + Util.StringHelper.escapeSQL( mResult.mCheckInPolicy ) +
				"', '" + Util.StringHelper.escapeSQL( mResult.mCheckOutPolicy ) +
				"', " + aSearchId + ");\n";
		return lSQL;
	}

	public String insertAccomodationDataResult_AvailableRooms( AccomodationData_RESULT.Room aRoom,
	                                                    int aAccomodationDataResultId,
	                                                    String recordedDatetime )
	{
		String lSQL = "INSERT INTO Room (\n" +
				"\tName         ,\n" +
				"\tPrice           ,\n" +
				"\tRoomSize   ,\n" +
				"\tRoomHook ,\n" +
				"\tMaxOccupancy    ,\n" +
				"\tBreakfastIncluded  ,\n" +
				"\tCancellationPolicy    ,\n" +
				"\tAccomodation_ID       )\n" +
				"VALUES(\n'" + Util.StringHelper.escapeSQL( aRoom.mName )+ "', " +
				String.valueOf( aRoom.mPrice ) + ", '" +
				Util.StringHelper.escapeSQL( aRoom.mRoomSize ) + "', '" +
				Util.StringHelper.escapeSQL( aRoom.mRoomHook ) + "', " +
				aRoom.mMaxOccupancy + ", '" +
				( aRoom.mBreakfastIncluded ? "Y" : "N" ) + "', '" +
				Util.StringHelper.escapeSQL( aRoom.mCancellationPolicy ) + "', " +
				aAccomodationDataResultId + ");\n";
		return lSQL;
	}
}
