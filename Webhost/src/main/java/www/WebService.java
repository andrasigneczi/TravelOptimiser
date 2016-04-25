package www;

import Util.*;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.context.request.WebRequest;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Andras on 08/04/2016.
 */
@RestController
public class WebService
{
	private String mHtmlTemplate;
	private String mJsTemplate;
	private String mDivTemplate;
	private String mSeriesTemplate;

	private String mSelectedDepartureAirport = "-";
	private String mSelectedArrivalAirport   = "-";
	private boolean mReturnCheckboxChecked   = false;

	public WebService()
	{
		Scanner lScanner  = new Scanner(getClass().getClassLoader().getResourceAsStream("charts_template.html" ), "UTF-8" );
		mHtmlTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();

		lScanner  = new Scanner(getClass().getClassLoader().getResourceAsStream("charts_template.js" ), "UTF-8" );
		mJsTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();

		mDivTemplate = "<div id=\"[CONTAINER]\" style=\"min-width: 310px; height: 400px; margin: 0 auto\"></div>";
		mSeriesTemplate = "{\n" +
				"                name: '[SERIES.NAME]',\n" +
				"                data: [\n" +
				"                [SERIES.DATA]\n" +
				"                ]\n" +
				"            }";
	}

	private String IsoDatetimeToEngDate( String aDateTime )
	{
		//String lDate = aDateTime.substring( 0, 10 );
		/*
		StringBuffer lReturn = new StringBuffer();
		IntStream
				.range( 0, lDate.length() - 1 )
				.forEach( s -> lReturn.append( lDate.charAt( lDate.length() - 1 - s ) ) );
		*/
		LocalDateTime lLocalDateTime = LocalDateTime.parse(aDateTime, DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm"));
		return String.format( "%02d.%02d.%04d %02d:%02d", lLocalDateTime.getDayOfMonth(),
				lLocalDateTime.getMonthValue(), lLocalDateTime.getYear(), lLocalDateTime.getHour(), lLocalDateTime.getMinute() );
	}

	private String [] GetHtmlContent( String aDateTime1, String aDateTime2, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency, String aHtmlTagId, boolean aOneWay )
	{
		String lResult1 = SQLiteDataProvider.getInstance().GetTripData( aDateTime1/*2016-07-16 06:30*/, aAirline, aAirportFrom, aAirportTo, aCurrency, new HighChartDataResultComposer() );
		String lDate1 = IsoDatetimeToEngDate( aDateTime1 );
		String lSeries1 = mSeriesTemplate.replace( "[SERIES.NAME]", lDate1 )
				.replace( "[SERIES.DATA]", lResult1 );

		String lJS;
		if( !aOneWay )
		{
			String lResult2 = SQLiteDataProvider.getInstance().GetTripData( aDateTime2/*2016-07-19 08:30*/, aAirline, aAirportTo, aAirportFrom, aCurrency, new HighChartDataResultComposer() );
			String lDate2 = IsoDatetimeToEngDate( aDateTime2 );
			String lSeries2 = mSeriesTemplate.replace( "[SERIES.NAME]", lDate2 )
					.replace( "[SERIES.DATA]", lResult2 );

			lJS = mJsTemplate.replace( "[TITLE]", lDate1 + " - " + lDate2 + " " + aAirportFrom + " - " + aAirportTo )
					.replace( "[SUBTITLE]", aAirline )
					.replace( "[DEVIZA]", aCurrency )
					.replace( "[SERIES]", lSeries1 + ",\n" + lSeries2 )
					.replace( "[CONTAINER]", aHtmlTagId );
			String lDiv = mDivTemplate.replace( "[CONTAINER]", aHtmlTagId );
			return new String[] { lDiv, lJS };
		}
		else
		{
			lJS = mJsTemplate.replace( "[TITLE]", lDate1 + " " + aAirportFrom + " - " + aAirportTo )
					.replace( "[SUBTITLE]", aAirline )
					.replace( "[DEVIZA]", aCurrency )
					.replace( "[SERIES]", lSeries1 )
					.replace( "[CONTAINER]", aHtmlTagId );
		}
		String lDiv = mDivTemplate.replace( "[CONTAINER]", aHtmlTagId );
		return new String[] { lDiv, lJS };
	}

	private String GenHtmlContentUsingConfig()
	{
		ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
		String lScriptCotent = "";
		String lDivContent = "";
		int lContainerIndex = 0;
		for( TravelData_INPUT lTDI : lSearchList )
		{
			if( !lTDI.mAirline.equals( "wizzair" ))
				continue;

			lTDI.mReturnTicket = ( lTDI.mReturnDatetime.length() != 0 );
			String[] lContent = GetHtmlContent( lTDI.mDepartureDatetime, lTDI.mReturnDatetime, lTDI.mAirline,
					lTDI.mAirportCode_LeavingFrom, lTDI.mAirportCode_GoingTo,
					lTDI.mCurrency, "container" + lContainerIndex++, !lTDI.mReturnTicket );
			lScriptCotent += lContent[ 1 ];
			lDivContent += lContent[ 0 ];
		}
		String  lHtml = mHtmlTemplate.replace( "[CHART_SCRIPTS]", lScriptCotent )
				.replace( "[CHART_DIVS]", lDivContent );

		String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList(),
				mSelectedDepartureAirport, mSelectedArrivalAirport, mReturnCheckboxChecked );
		lHtml = lHtml.replace( "[AVAILABLE_TRIPS]", lGetCollectedDepartureDateList );

		String lDepartureAirportSelector = SQLiteDataProvider.getInstance().GetDepartureAirportList( new HtmlListFormatterSelect( "DepartureAirportList" ),
				mSelectedDepartureAirport);
		lHtml = lHtml.replace( "[DEPARTURE_AIRPORTS]", lDepartureAirportSelector );

		String lArrivalAirportSelector = SQLiteDataProvider.getInstance().GetArrivalAirportList( new HtmlListFormatterSelect( "ArrivalAirportList" ),
				mSelectedDepartureAirport, mSelectedArrivalAirport);
		lHtml = lHtml.replace( "[ARRIVAL_AIRPORTS]", lArrivalAirportSelector );

		return lHtml;
	}

	@RequestMapping( "/" )
	public String index() throws IOException
	{
		/* Template format
		[TITLE] 06.08.2016 - 09.08.2016 SOF - HHN
		[SUBTITLE] wizzair
		[DEVIZA] lv € Ft
		[SERIES1.NAME] 06.08.2016
		[SERIES2.NAME] 09.08.2016
		[SERIES1.DATA] [Date.UTC(1970, 9, 29), 0], ...
		[SERIES2.DATA] [Date.UTC(1970, 10, 9), 0.4], ...
		 */
/*
		String [] lContent1 = GetHtmlContent( "2016-07-16 06:30", "2016-07-19 08:30", "wizzair", "SOF", "HHN", "lv", "container1", false );
		String [] lContent2 = GetHtmlContent( "2016-08-06 06:30", "2016-08-09 08:30", "wizzair", "SOF", "HHN", "lv", "container2", false );
		String [] lContent3 = GetHtmlContent( "2016-04-15 20:45", "", "wizzair", "CRL", "BUD", "€", "container3", true );

		String  lHtml = mHtmlTemplate.replace( "[CHART_SCRIPTS]", lContent1[ 1 ] + lContent2[ 1 ] + lContent3[ 1 ] )
				.replace( "[CHART_DIVS]", lContent1[ 0 ] + lContent2[ 0 ] + lContent3[ 0 ] );
		return lHtml;
*/
		return GenHtmlContentUsingConfig();
	}

	@RequestMapping( value = "/ajaxrequest", method = { RequestMethod.POST }, params = { "id", "param" } )
	public String action1( @RequestParam( "id" ) String aId, @RequestParam( "param" ) String aParam, HttpServletRequest httpRequest, WebRequest request )
	{
		if( aId.equals( "DepartureAirportListChanged" ))
			mSelectedDepartureAirport = aParam;
		else if( aId.equals( "ArrivalAirportListChanged" ))
			mSelectedArrivalAirport = aParam;
		else if( aId.equals( "ReturnTrip" ))
			mReturnCheckboxChecked = !aParam.equals( "0" );
		else if( aId.equals( "DateTimeButtonPushed" ))
		{
			String[] lValues = aParam.split( "\\|" );
			// String [] GetHtmlContent( String aDateTime1, String aDateTime2, String aAirline, String aAirportFrom, String aAirportTo, String aCurrency, String aHtmlTagId, boolean aOneWay )
			String [] lHtmlContent = GetHtmlContent( lValues[ 1 ], "", lValues[ 0 ], lValues[ 2 ], lValues[ 3 ], "%", "modalcontainer", true );
			return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
		}

		String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList(),
				mSelectedDepartureAirport, mSelectedArrivalAirport, mReturnCheckboxChecked );

		return lGetCollectedDepartureDateList;
	}
}
