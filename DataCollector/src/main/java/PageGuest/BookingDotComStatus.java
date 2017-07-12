package PageGuest;

import com.teamdev.jxbrowser.chromium.dom.DOMDocument;

/**
 * Created by Andras on 22/06/2017.
 */
public class BookingDotComStatus
{
	public enum Status {
		EMPTY,
		STARTING,
		START_PAGE_LOADED,
		FILLING_THE_FORM,
		FORM_IS_FILLED,
		SEARCHING,
		RESULT_PAGE_LOADED,
		PARSING_THE_RESULTS,
		PARSING_HAS_FINISHED,
		NEXT_PAGE_LOADING,
		NEXT_PAGE_LOADED,
		THE_SEARCHING_READY,

		OPENING_A_HOTEL_PAGE,
		HOTEL_PAGE_LOADED,
		PARSING_A_HOTEL_PAGE,
		HOTEL_PAGE_IS_PARSED,

		APPLYING_A_FILTER,
		FILTERED_PAGE_LOADED,

		DONE
	}

	private Status mStatus;
	Status getStatus() { return mStatus; }

	public BookingDotComStatus()
	{
		mStatus = Status.EMPTY;
	}

	public void starting( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case EMPTY:
			case THE_SEARCHING_READY: mStatus = Status.STARTING;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void mainFrameLoaded( BookingDotComPageGuest guest, DOMDocument aDocument )
	{
		switch( mStatus )
		{
			case STARTING:              mStatus = Status.START_PAGE_LOADED;   guest.FillTheForm( aDocument ); break;
			case SEARCHING:             mStatus = Status.RESULT_PAGE_LOADED;  guest.ApplyFilter( aDocument ); break;
			case APPLYING_A_FILTER:     mStatus = Status.FILTERED_PAGE_LOADED; guest.ApplyFilter( aDocument ); break;
			case NEXT_PAGE_LOADING:     mStatus = Status.NEXT_PAGE_LOADED;    guest.ParseTheResult( aDocument ); break;
			case OPENING_A_HOTEL_PAGE:  mStatus = Status.HOTEL_PAGE_LOADED;   guest.ParseAHotelPage( aDocument ); break;
			//case THE_SEARCHING_READY:  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void fillingTheForm( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case START_PAGE_LOADED: mStatus = Status.FILLING_THE_FORM;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void formIsFilled( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case FILLING_THE_FORM: mStatus = Status.FORM_IS_FILLED;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void searching( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case FORM_IS_FILLED: mStatus = Status.SEARCHING;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void parsingTheResult( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case RESULT_PAGE_LOADED:   mStatus = Status.PARSING_THE_RESULTS;  break;
			case NEXT_PAGE_LOADED:     mStatus = Status.PARSING_THE_RESULTS;  break;
			case FILTERED_PAGE_LOADED:  mStatus = Status.PARSING_THE_RESULTS;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void parsingFinished( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case PARSING_THE_RESULTS:
				mStatus = Status.PARSING_HAS_FINISHED;
				if( guest.pageNext())
				{
					mStatus = Status.NEXT_PAGE_LOADING;
				}
				else
				{
					if( guest.openTheNextHotel())
					{
						mStatus = Status.OPENING_A_HOTEL_PAGE;
					}
					else
					{
						mStatus = Status.THE_SEARCHING_READY;
						guest.printTheMatches();
						guest.startANewSearch();
					}
				}
				break;
			case PARSING_A_HOTEL_PAGE:
				mStatus = Status.HOTEL_PAGE_IS_PARSED;
				if( guest.openTheNextHotel())
				{
					mStatus = Status.OPENING_A_HOTEL_PAGE;
				}
				else
				{
					mStatus = Status.THE_SEARCHING_READY;
					guest.printTheMatches();
					guest.startANewSearch();
				}
				break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void parsingAHotelPage( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case HOTEL_PAGE_LOADED: mStatus = Status.PARSING_A_HOTEL_PAGE;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}

	public void Done( BookingDotComPageGuest guest )
	{
		mStatus = Status.DONE;
	}

	public void ApplyAFilter( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case RESULT_PAGE_LOADED:   mStatus = Status.APPLYING_A_FILTER;  break;
			case FILTERED_PAGE_LOADED: mStatus = Status.APPLYING_A_FILTER;  break;
			default:
				throw new RuntimeException( "Illegal status: " + mStatus );
		}
	}
}
