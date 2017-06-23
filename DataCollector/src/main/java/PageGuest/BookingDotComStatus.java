package PageGuest;

import com.teamdev.jxbrowser.chromium.dom.DOMDocument;

import java.util.Stack;

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
		HOTEL_PAGE_IS_PARSED
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
			case EMPTY: mStatus = Status.STARTING;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void mainFrameLoaded( BookingDotComPageGuest guest, DOMDocument aDocument )
	{
		switch( mStatus )
		{
			case STARTING:              mStatus = Status.START_PAGE_LOADED;  guest.FillTheForm( aDocument ); break;
			case SEARCHING:             mStatus = Status.RESULT_PAGE_LOADED; guest.ParseTheResult( aDocument ); break;
			case NEXT_PAGE_LOADING:     mStatus = Status.NEXT_PAGE_LOADED;   guest.ParseTheResult( aDocument ); break;
			case OPENING_A_HOTEL_PAGE:  mStatus = Status.HOTEL_PAGE_LOADED;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void fillingTheForm( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case START_PAGE_LOADED: mStatus = Status.FILLING_THE_FORM;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void formIsFilled( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case FILLING_THE_FORM: mStatus = Status.FORM_IS_FILLED;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void searching( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case FORM_IS_FILLED: mStatus = Status.SEARCHING;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void parsingTheResult( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case RESULT_PAGE_LOADED: mStatus = Status.PARSING_THE_RESULTS;  break;
			case NEXT_PAGE_LOADED:  mStatus = Status.PARSING_THE_RESULTS;  break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}

	public void parsingFinished( BookingDotComPageGuest guest )
	{
		switch( mStatus )
		{
			case PARSING_THE_RESULTS:
				mStatus = Status.PARSING_HAS_FINISHED;
				if( guest.pageNext())
					mStatus = Status.NEXT_PAGE_LOADING;
				else
					mStatus = Status.THE_SEARCHING_READY;
				break;
			default:
				throw new RuntimeException( "Illegal status!" );
		}
	}
}
