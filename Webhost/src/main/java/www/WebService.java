package www;

import Util.DataProvider;
import Util.DataResultComposer;
import Util.HighChartDataResultComposer;
import Util.SQLiteDataProvider;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.IntStream;

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
		String lResult1 = SQLiteDataProvider.getInstance().GetData( aDateTime1/*2016-07-16 06:30*/, aAirline, aAirportFrom, aAirportTo, aCurrency, new HighChartDataResultComposer() );
		String lDate1 = IsoDatetimeToEngDate( aDateTime1 );
		String lSeries1 = mSeriesTemplate.replace( "[SERIES.NAME]", lDate1 )
				.replace( "[SERIES.DATA]", lResult1 );

		String lJS;
		if( !aOneWay )
		{
			String lResult2 = SQLiteDataProvider.getInstance().GetData( aDateTime2/*2016-07-19 08:30*/, aAirline, aAirportTo, aAirportFrom, aCurrency, new HighChartDataResultComposer() );
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
		String lResult1 = SQLiteDataProvider.getInstance().GetData( "2016-07-16 %", "wizzair", "SOF", "HHN", "lv", new HighChartDataResultComposer() );
		String lResult2 = SQLiteDataProvider.getInstance().GetData( "2016-07-19 %", "wizzair", "HHN", "SOF", "lv", new HighChartDataResultComposer() );

		String lJS = lJsTemplate.replace( "[TITLE]", "16.07.2016 - 19.07.2016 SOF - HHN" )
								.replace( "[SUBTITLE]", "wizzair" )
								.replace( "[DEVIZA]", "lv" )
								.replace( "[SERIES1.NAME]", "16.07.2016" )
								.replace( "[SERIES2.NAME]", "19.07.2016" )
								.replace( "[SERIES1.DATA]", lResult1 )
								.replace( "[SERIES2.DATA]", lResult2 )
								.replace( "[CONTAINER]", "container1" );
		String lDiv = lDivTemplate.replace( "[CONTAINER]", "container1" );

		//SQLiteDataProvider.getInstance().ConnectionClose();

		String  lHtml = lHtmlTemplate.replace( "[CHART_SCRIPTS]", lJS )
				.replace( "[CHART_DIVS]", lDiv );
*/
		String [] lContent1 = GetHtmlContent( "2016-07-16 06:30", "2016-07-19 08:30", "wizzair", "SOF", "HHN", "lv", "container1", false );
		String [] lContent2 = GetHtmlContent( "2016-08-06 06:30", "2016-08-09 08:30", "wizzair", "SOF", "HHN", "lv", "container2", false );
		String [] lContent3 = GetHtmlContent( "2016-04-15 20:45", "", "wizzair", "CRL", "BUD", "€", "container3", true );

		String  lHtml = mHtmlTemplate.replace( "[CHART_SCRIPTS]", lContent1[ 1 ] + lContent2[ 1 ] + lContent3[ 1 ] )
				.replace( "[CHART_DIVS]", lContent1[ 0 ] + lContent2[ 0 ] + lContent3[ 0 ] );
		return lHtml;
	}
}
