package Storage;

import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;
import org.apache.commons.lang3.StringEscapeUtils;

import java.util.ArrayList;

/**
 * Created by Andras on 18/03/2016.
 */
public class TravelDataResultComposer_HTML extends TravelDataResultComposer
{
	public TravelDataResultComposer_HTML(  TravelData_RESULT aResult )
	{
		super( aResult );
	}

	public String getTableHeader()
	{
		String lHead = "";
		lHead += "<html>\n";
		lHead += "<head>\n";
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
		lBody += "<table border=1>\n";
		lBody += "<tr><th colspan=3>checking date &#45;" + lSEUtils.escapeHtml4( mResult.mAirlines ) + " &#45;" + mResult.mAirportCode_LeavingFrom + "&nbsp;&#61;&#62;" + mResult.mAirportCode_GoingTo + "</th></tr>\n";

		// Outbound
		for( TravelData_RESULT.TravelData_PossibleTrips lTrip : mResult.mTrips )
		{
			if( !lTrip.mOutboundTrip )
				continue;

			lBody += "<tr><td>" + lSEUtils.escapeHtml4( lTrip.mDepartureDaytime ) + " &#45;&#62; " +
					lSEUtils.escapeHtml4( lTrip.mArrivalDaytime ) + "</td><td>" +
					lSEUtils.escapeHtml4( lTrip.mPrices ) + "</td><td>" +
					lSEUtils.escapeHtml4( lTrip.mPrices2 ) + "</td></tr>\n";
		}
		lBody += "</table></br></br>\n";

		if( !mResult.mReturnTicket )
			return lBody;

		lBody += "<table border=1>\n";
		lBody += "<tr><th colspan=3>checking date &#45;" + lSEUtils.escapeHtml4( mResult.mAirlines ) + " &#45;" + mResult.mAirportCode_GoingTo + "&nbsp;&#61;&#62;" + mResult.mAirportCode_LeavingFrom + "</th></tr>\n";

		// Return
		for( TravelData_RESULT.TravelData_PossibleTrips lTrip : mResult.mTrips )
		{
			if( lTrip.mOutboundTrip )
				continue;
			lBody += "<tr><td>" + lSEUtils.escapeHtml4( lTrip.mDepartureDaytime ) + " &#45;&#62; " +
					lSEUtils.escapeHtml4( lTrip.mArrivalDaytime ) + "</td><td>" +
					lSEUtils.escapeHtml4( lTrip.mPrices ) + "</td><td>" +
					lSEUtils.escapeHtml4( lTrip.mPrices2 ) + "</td></tr>\n";
		}
		lBody += "</table></br></br>";
		return lBody;
	}

	public String getClosingTags()
	{
		return "</body>\n</html>";
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


<html>
<head>
</head>
<body>
<table>
<tr><th colspan=3>checking date - Wizzair - SOF - CRL </th></tr>
<tr><td>departure datetime -> arrival date time</td><td>prices1</td><td>prices2</td></tr>
</table>
</body>
</html>
 */