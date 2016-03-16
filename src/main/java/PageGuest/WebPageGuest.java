package PageGuest;

/**
 * Created by andras.igneczi on 15/03/2016.
 */
public abstract class WebPageGuest
{
	private TravelDatas_RESULT mTravelDataResult = null;
    public abstract boolean DoSearch( String aAirportCode_Way_From, String aAirportCode_Way_To,
                                      String aDepartureDate_Way_To, String aReturnDate_Way_Back );
}
