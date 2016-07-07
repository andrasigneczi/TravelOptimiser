package www;

import Util.*;
import org.springframework.beans.factory.annotation.Autowired;
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
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

/**
 * Created by Andras on 08/04/2016.
 */
@RestController
public class WebService
{
	private ChartBuilder mBuilder;
	private String mLastPushButtonParams;

	public WebService()
	{
		mBuilder = new ChartBuilder();
	}

	private String GenHtmlContentUsingConfig()
	{
		return mBuilder.GenerateHtmlContentUsingConfig();
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
		SQLiteDataProvider.getInstance().OpenANewerDatabaseFile();
		return GenHtmlContentUsingConfig();
	}

	@RequestMapping( value = "/ajaxrequest", method = { RequestMethod.POST }, params = { "id", "param" } )
	public String action1( @RequestParam( "id" ) String aId, @RequestParam( "param" ) String aParam, HttpServletRequest httpRequest, WebRequest request )
	{
		if( aId.equals( "DepartureAirportListChanged" ))
			mBuilder.setSelectedDepartureAirport( aParam );
		else if( aId.equals( "ArrivalAirportListChanged" ))
			mBuilder.setSelectedArrivalAirport( aParam );
		else if( aId.equals( "ReturnTripChanged" ))
		{
			mBuilder.setReturnCheckboxChecked( !aParam.equals( "false" ));
			mBuilder.setToggledButton( null );
			if( mBuilder.isReturnCheckboxChecked() )
				return "";
		}
		else if( aId.equals( "DateTimeButtonPushed" ))
		{
			String lReturnValue = mBuilder.DateTimeButtonPushed( aParam );
			if( lReturnValue != null )
			{
				mLastPushButtonParams = aParam;
				// mBuilder.isReturnCheckboxChecked()
				// mBuilder.getToggledButton()
				// mLastModalChartParams = aParam;
				return lReturnValue;
			}
		}
		else if( aId.equals( "OutboundDateChanged" ))
			mBuilder.setOutboundDate( aParam );
		else if( aId.equals( "InboundDateChanged" ))
			mBuilder.setInboundDate( aParam );
		else if( aId.equals( "bookmarkChart" ))
		{
			if( aParam.equals( "on" ))
			{
				mBuilder.BookmarkTrip( mLastPushButtonParams );
			}
			else
			{
				// TODO
			}
			return "";
		}
		else if( aId.equals( "bookmarkChart2" ))
		{
			mBuilder.UpdateBookmarkTrip( aParam );
			return "";
		}

		String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance()
				.GetCollectedDepartureDateList( new HtmlListFormatterButtonList( mBuilder.getToggledButton() ),
						mBuilder.getSelectedDepartureAirport(), mBuilder.getSelectedArrivalAirport(),
						mBuilder.isReturnCheckboxChecked(), mBuilder.getOutboundDate(), mBuilder.getInboundDate() );

		return lGetCollectedDepartureDateList;
	}
}
