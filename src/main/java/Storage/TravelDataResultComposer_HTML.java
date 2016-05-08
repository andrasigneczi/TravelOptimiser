package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import org.apache.commons.lang3.StringEscapeUtils;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 18/03/2016.
 */
public class TravelDataResultComposer_HTML extends TravelDataResultComposer
{
	private DateTimeFormatter mFormatterWizzair;
	private String [] mMonthNames;

	public TravelDataResultComposer_HTML(  TravelData_RESULT aResult )
	{
		super( aResult );
		mFormatterWizzair = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
		mMonthNames = new String[] { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	}

	public String getTableHeader()
	{
		String lHead = "";
		lHead += "<html>\n";
		lHead += "<head>\n";
		lHead += "<meta charset=\"UTF-8\">\n";
		lHead += "</head>\n";
		lHead += "<body>\n";

		return lHead;
	}

	public String toFormattedString()
	{
		/*
		aResult.mAirlines;
		aResult.mDepartureDaytime;    // 2016.03.25 17:10
		aResult.mArrivalDaytime;      // 2016.03.25 22:10
		aResult.mPrices;
		aResult.mPrices2;
		aResult.mOutboundTrip;
		aResult.mAirportCode_LeavingFrom;   // SOF
		aResult.mAirportCode_GoingTo;       // HHN
		aResult.mReturnTicket;
*/
		StringEscapeUtils lSEUtils = new StringEscapeUtils();
		String lBody = "";
		String lCheckingDate = LocalDateTime.now().format( DateTimeFormatter.ISO_LOCAL_DATE );
		lBody += "<div style=\"float:left;\"><table border=1>\n";
		lBody += "<tr><th colspan=3>" + lCheckingDate + " &#45;" + lSEUtils.escapeHtml4( mResult.mTravelDataInput.mAirline ) + " &#45;" + mResult.mTravelDataInput.mAirportCode_LeavingFrom + "→" + mResult.mTravelDataInput.mAirportCode_GoingTo + "</th></tr>\n";

		// Outbound
		for( TravelData_RESULT.TravelData_PossibleTrips lTrip : mResult.mTrips )
		{
			if( !lTrip.mOutboundTrip )
				continue;

			lBody += toFormattedString_Trip( lTrip );
		}

		lBody += "</table></div>\n";
		if( !mResult.mTravelDataInput.mReturnTicket )
		{
			lBody += "<div></div>";
			return lBody;
		}

		lBody += "<table border=1>\n";
		lBody += "<tr><th colspan=3>" + lSEUtils.escapeHtml4( mResult.mTravelDataInput.mAirline ) + " &#45;" + mResult.mTravelDataInput.mAirportCode_GoingTo + "→" + mResult.mTravelDataInput.mAirportCode_LeavingFrom + "</th></tr>\n";

		// Return
		for( TravelData_RESULT.TravelData_PossibleTrips lTrip : mResult.mTrips )
		{
			if( lTrip.mOutboundTrip )
				continue;
			lBody += toFormattedString_Trip( lTrip );
		}
		lBody += "</table></br></br>\n";
		return lBody;
	}

	private String toFormattedString_Trip( TravelData_RESULT.TravelData_PossibleTrips aTrip )
	{
		StringEscapeUtils lSEUtils = new StringEscapeUtils();
		ArrayList<String> lNormalizedDatetimes = NormalizeDatetimes( FormatDatetime( aTrip.mDepartureDatetime ), FormatDatetime( aTrip.mArrivalDatetime ));
		String lBody = "<tr><td nowrap>" + lSEUtils.escapeHtml4( lNormalizedDatetimes.get( 0 )) + "</br>" +
				lSEUtils.escapeHtml4( lNormalizedDatetimes.get( 1 )) + "→" +
				lSEUtils.escapeHtml4( lNormalizedDatetimes.get( 2 )) + "</td><td>BASIC</br>" +
				lSEUtils.escapeHtml4( aTrip.mPrices_BasicFare_Normal ) + " &#47; " +
				lSEUtils.escapeHtml4( aTrip.mPrices_BasicFare_Discount ) +
				"</td><td>PLUS</br>" +
				lSEUtils.escapeHtml4( aTrip.mPrices_PlusFare_Normal ) + " &#47; " +
				lSEUtils.escapeHtml4( aTrip.mPrices_PlusFare_Discount ) + "</td></tr>\n";

		return lBody;
	}

	public String getClosingTags()
	{
		return "</body>\n</html>\n";
	}

	private String FormatDatetime( String aValue)
	{
		LocalDateTime lLocalDateTime = LocalDateTime.parse(aValue, mFormatterWizzair);

		lLocalDateTime = DateTimeCorrection( lLocalDateTime );

		// Unfortunatelly the month won't be get in short format
		DateTimeFormatter lNewFormat = DateTimeFormatter.ofPattern( "E, dd (M) H:mm" );

		String lNewValue = lLocalDateTime.format( lNewFormat );

		Pattern reg = Pattern.compile( "\\(\\d{1,2}\\)" );
		Matcher m = reg.matcher( lNewValue );

		while( m.find() )
		{
			String lRow = m.group().toString().trim();
			String lIndex = lRow.replace( "(", "" );
			lIndex = lIndex.replace( ")", "" );
			lNewValue = lNewValue.replace( lRow, mMonthNames[ Integer.parseInt( lIndex ) - 1 ] );
		}
		return lNewValue;
	}

	private ArrayList<String> NormalizeDatetimes( String aDeparture, String aArrival )
	{
		// Fri, 08 Jul 20:40; Fri, 08 Jul 22:40
		/*
		String lDate = "";
		for( int i = 0; i < aDeparture.length() && i < aArrival.length(); i++ )
		{
			if( aDeparture.charAt( i ) == aArrival.charAt( i ))
				lDate += aDeparture.charAt( i );
			else
				break;
		}
		*/
		String lDate = aDeparture.substring( 0, 11 );
		if( !lDate.equals( aArrival.substring( 0, 11 )))
			lDate = "";
		ArrayList<String> lReturn = new ArrayList<String>();
		lReturn.add( lDate.trim() );
		lReturn.add( aDeparture.substring( lDate.length() ).trim() );
		lReturn.add( aArrival.substring( lDate.length() ).trim() );
		return lReturn;
	}
}
/*

Return ticket
----------------------------------------------------------------------------------------------------------
airlines     | from -> to                                 | retrun to -> from                         |
----------------------------------------------------------------------------------------------------------
             | departure datetime -> arrival date time    | departure datetime -> arrival date time   |
----------------------------------------------------------------------------------------------------------
checked date |  prices1           | prices2               | prices1           | prices2               |
----------------------------------------------------------------------------------------------------------
checked date |  prices1           | prices2               | prices1           | prices2               |
----------------------------------------------------------------------------------------------------------
checked date |  prices1           | prices2               | prices1           | prices2               |
----------------------------------------------------------------------------------------------------------

One way ticket
-----------------------------------------------------------
airlines     | from -> to                                 |
-----------------------------------------------------------
             | departure datetime -> arrival date time    |
-----------------------------------------------------------
checked date |  prices1           | prices2               |
-----------------------------------------------------------
checked date |  prices1           | prices2               |
-----------------------------------------------------------
checked date |  prices1           | prices2               |
-----------------------------------------------------------

--------------------------------------------------------------
checking date airlines  from -> to Outbound                  |
-----------------------------------------------------------
departure datetime -> arrival date time |  prices1 | prices2 |
--------------------------------------------------------------
departure datetime -> arrival date time |  prices1 | prices2 |
--------------------------------------------------------------
departure datetime -> arrival date time |  prices1 | prices2 |
--------------------------------------------------------------

 */