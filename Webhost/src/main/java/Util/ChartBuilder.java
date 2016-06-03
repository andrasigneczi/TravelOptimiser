package Util;

import org.springframework.beans.factory.annotation.Autowire;
import org.springframework.context.annotation.Bean;

import java.lang.annotation.Annotation;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Scanner;

/**
 * Created by Andras on 29/05/2016.
 */
public class ChartBuilder
{
	private final String mHtmlTemplate;
	private final String mJsTemplate;
	private final String mDivTemplate;
	private final String mSeriesTemplate;

	private String mSelectedDepartureAirport = "-";
	private String mSelectedArrivalAirport   = "-";
	private boolean mReturnCheckboxChecked   = false;
	private OneWayTrip mToggledButton = null;

	// local variables for builder
	private String mDate1;
	private String mDate2;
	private Hashtable<String,String> mResult1;
	private Hashtable<String,String> mResult2;
	private HighChartDataResultComposer mHighChartDataResultComposerOutbound;
	private HighChartDataResultComposer mHighChartDataResultComposerReturn;

	private class InputParameters
	{
		public TravelData_INPUT mTDI       = null;
		public String mHtmlTagId           = null;
		public String mSeries1             = null;
		public String mAirportFrom         = null;
		public String mAirportTo           = null;
		public String mBoughtTicketsSeries = null;
		public String mDiscountSeries      = null;
	}

	public ChartBuilder()
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
				"                type: '[TYPE.NAME]',\n" +
				"                data: [\n" +
				"                [SERIES.DATA]\n" +
				"                ]\n" +
				"            }";
	}

	public String getSelectedDepartureAirport()
	{
		return mSelectedDepartureAirport;
	}

	public void setSelectedDepartureAirport( String aSelectedDepartureAirport )
	{
		this.mSelectedDepartureAirport = aSelectedDepartureAirport;
	}

	public String getSelectedArrivalAirport()
	{
		return mSelectedArrivalAirport;
	}

	public void setSelectedArrivalAirport( String aSelectedArrivalAirport )
	{
		this.mSelectedArrivalAirport = aSelectedArrivalAirport;
	}

	public boolean isReturnCheckboxChecked()
	{
		return mReturnCheckboxChecked;
	}

	public void setReturnCheckboxChecked( boolean aReturnCheckboxChecked )
	{
		this.mReturnCheckboxChecked = aReturnCheckboxChecked;
	}

	public OneWayTrip getToggledButton()
	{
		return mToggledButton;
	}

	public void setToggledButton( OneWayTrip aToggledButton )
	{
		this.mToggledButton = aToggledButton;
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

	private String GetDiscountSeries( final ArrayList<TravelData_INPUT.Discount> aDiscounts )
	{
		if( aDiscounts == null )
			return "";

		String lSeries = "";
		for( TravelData_INPUT.Discount lDiscount : aDiscounts )
		{
			HighChartDataResultComposer lHCDRCExtra = new HighChartDataResultComposer();
			lHCDRCExtra.add( lDiscount.mBeginning, "100", "%" );
			lHCDRCExtra.add( lDiscount.mEnding, "100", "%" );
			lSeries += ",\n" + mSeriesTemplate.replace( "[SERIES.NAME]", lDiscount.mName )
					.replace( "[TYPE.NAME]", "area" )
					.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() );
		}
		return lSeries;
	}

	private String GetBoughtTicketsSeries( final ArrayList<TravelData_INPUT.BoughtTicket> aBoughtTickets )
	{
		if( aBoughtTickets == null )
			return "";

		String lSeries = "";
		for( TravelData_INPUT.BoughtTicket lTicket : aBoughtTickets )
		{
			HighChartDataResultComposer lHCDRCExtra = new HighChartDataResultComposer();
			lHCDRCExtra.add( lTicket.mDatetime, lTicket.mPrice, "%" );
			lSeries += ",\n" + mSeriesTemplate.replace( "[SERIES.NAME]", lTicket.mName )
					.replace( "[TYPE.NAME]", "line" )
					.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() );
		}
		return lSeries;
	}

	private String GetSeries1( final String aDateTime1, final String aAirline,
	                           final String aAirportFrom, final String aAirportTo,
	                           final String aCurrency)
	{

		mHighChartDataResultComposerOutbound = new HighChartDataResultComposer();
		mResult1 = SQLiteDataProvider.getInstance().GetTripData( aDateTime1/*2016-07-16 06:30*/, aAirline,
				aAirportFrom, aAirportTo, aCurrency, mHighChartDataResultComposerOutbound );
		mDate1 = IsoDatetimeToEngDate( aDateTime1 );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", mDate1 )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[SERIES.DATA]", mResult1.get( "Result" ) );
		return lSeries;
	}

	private String GetSeries2(final InputParameters aIParams )
	{
		mHighChartDataResultComposerReturn = new HighChartDataResultComposer();
		mResult2 = SQLiteDataProvider.getInstance()
				.GetTripData( aIParams.mTDI.mReturnDatetime,
						aIParams.mTDI.mAirline,
						aIParams.mTDI.mAirportCode_GoingTo,
						aIParams.mTDI.mAirportCode_LeavingFrom,
						aIParams.mTDI.mCurrency,
						mHighChartDataResultComposerReturn );
		mDate2 = IsoDatetimeToEngDate( aIParams.mTDI.mReturnDatetime );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", mDate2 )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[SERIES.DATA]", mResult2.get( "Result" ) );
		return lSeries;
	}

	private String GetSeries3()
	{
		String lSumResult = mHighChartDataResultComposerOutbound.Summarize( mHighChartDataResultComposerReturn );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", "Sum" )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[SERIES.DATA]", lSumResult );
		return lSeries;
	}

	private String GetTripJS( String aTitle, String aSubtitle, String aCurrency, String aSeries, String aContainer )
	{
		String lJS = mJsTemplate.replace( "[TITLE]", aTitle )
				.replace( "[SUBTITLE]", aSubtitle )
				.replace( "[DEVIZA]", aCurrency )
				.replace( "[SERIES]", aSeries )
				.replace( "[CONTAINER]", aContainer );
		return lJS;
	}

	private String[] GetReturnTripHtmlContent( final InputParameters aIParams )
	{
		String lSeries2 = GetSeries2( aIParams );

		HashSet<String> lFoundCurrency = mHighChartDataResultComposerReturn.getFoundCurrency();
		String lCurrency = aIParams.mTDI.mCurrency;
		if( lCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
			lCurrency = lFoundCurrency.iterator().next();

		String lSeries3 = GetSeries3();

		String lTitle = mDate1 + " - " + mDate2 + " " + aIParams.mAirportFrom + " - " + aIParams.mAirportTo;
		String lSeries = aIParams.mSeries1 + ",\n" + lSeries2 + ",\n" + lSeries3 + aIParams.mBoughtTicketsSeries + aIParams.mDiscountSeries;

		String lJS = GetTripJS( lTitle, aIParams.mTDI.mAirline, lCurrency, lSeries, aIParams.mHtmlTagId );
		String lDiv = mDivTemplate.replace( "[CONTAINER]", aIParams.mHtmlTagId );
		return new String[] { lDiv, lJS };
	}

	private String[] GetOneWayHtmlContent( final InputParameters aIParams )
	{
		HashSet<String> lFoundCurrency = mHighChartDataResultComposerOutbound.getFoundCurrency();
		String lCurrency = aIParams.mTDI.mCurrency;
		if( lCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
			lCurrency = lFoundCurrency.iterator().next();

		String lTitle = mDate1 + " " + aIParams.mAirportFrom + " - " + aIParams.mAirportTo;
		String lSeriesSum = aIParams.mSeries1 + aIParams.mBoughtTicketsSeries + aIParams.mDiscountSeries;

		String lJS = GetTripJS(lTitle, aIParams.mTDI.mAirline, lCurrency, lSeriesSum, aIParams.mHtmlTagId );
		String lDiv = mDivTemplate.replace( "[CONTAINER]", aIParams.mHtmlTagId );
		return new String[] { lDiv, lJS };
	}

	/**
	 *
	 * @param aDateTime1      first trip's departure day
	 * @param aDateTime2      return trip's departure day
	 * @param aAirline        airline
	 * @param aAirportFrom    departure airport
	 * @param aAirportTo      arrival airport
	 * @param aCurrency       currency of the tickets' price
	 * @param aHtmlTagId      a string for the modal window
	 * @param aOneWay         one way or return ticket
	 * @return String [], first element the div of the chart, second element the javascript of the chart
	 */
	private String [] GetHtmlContent( final String aDateTime1, final String aDateTime2,
	                                  final String aAirline, final String aAirportFrom,
	                                  final String aAirportTo, final String aCurrency,
	                                  final String aHtmlTagId, final boolean aOneWay,
	                                  final ArrayList<TravelData_INPUT.BoughtTicket> aBoughtTickets,
	                                  final ArrayList<TravelData_INPUT.Discount> aDiscounts )
	{
		InputParameters lIParams = new InputParameters();
		lIParams.mTDI = new TravelData_INPUT();
		lIParams.mTDI.mDepartureDatetime       = aDateTime1;
		lIParams.mTDI.mReturnDatetime          = aDateTime2;
		lIParams.mTDI.mAirline                 = aAirline;
		lIParams.mTDI.mAirportCode_LeavingFrom = aAirportFrom;
		lIParams.mTDI.mAirportCode_GoingTo     = aAirportTo;
		lIParams.mTDI.mCurrency                = aCurrency;
		lIParams.mTDI.mBoughtTickets           = aBoughtTickets;
		lIParams.mTDI.mDiscounts               = aDiscounts;
		lIParams.mHtmlTagId                    = aHtmlTagId;

		lIParams.mSeries1 = GetSeries1( aDateTime1, aAirline, aAirportFrom, aAirportTo, aCurrency );

		lIParams.mAirportFrom = aAirportFrom;
		if( aAirportFrom.equals( "-" ))
			lIParams.mAirportFrom = mResult1.get( "AirportCode_LeavingFrom" );

		lIParams.mAirportTo = aAirportTo;
		if( aAirportTo.equals( "-" ))
			lIParams.mAirportTo = mResult1.get( "AirportCode_GoingTo" );

		lIParams.mBoughtTicketsSeries = GetBoughtTicketsSeries( aBoughtTickets );
		lIParams.mDiscountSeries = GetDiscountSeries( aDiscounts );

		if( aOneWay )
			return GetOneWayHtmlContent( lIParams );

		return GetReturnTripHtmlContent( lIParams );
	}

	public String GenerateHtmlContentUsingConfig()
	{
		ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
		String lScriptCotent = "";
		String lDivContent = "";
		int lContainerIndex = 0;
		for( TravelData_INPUT lTDI : lSearchList )
		{
			if( !lTDI.mAirline.equals( "wizzair" ) && !lTDI.mAirline.equals( "ryanair" ))
				continue;

			lTDI.mReturnTicket = ( lTDI.mReturnDatetime.length() != 0 );
			String[] lContent = GetHtmlContent( lTDI.mDepartureDatetime, lTDI.mReturnDatetime, lTDI.mAirline,
					lTDI.mAirportCode_LeavingFrom, lTDI.mAirportCode_GoingTo,
					lTDI.mCurrency, "container" + lContainerIndex++, !lTDI.mReturnTicket,
					lTDI.mBoughtTickets, lTDI.mDiscounts );
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

	public String DateTimeButtonPushed( String aParam )
	{
		String[] lValues = aParam.split( "\\|" );
		// lValues = airline, leavingfrom, goingto, outbound, datetime
		OneWayTrip lTB = new OneWayTrip(
				lValues[ 4 ], lValues[ 0 ],
				lValues[ 1 ], lValues[ 2 ],
				Boolean.parseBoolean( lValues[ 3 ] ));

		if( mReturnCheckboxChecked )
		{
			if( mToggledButton != null )//if( a button already pushed )
			{
				if( mToggledButton.equals( lTB ))
				{ // if the toggled button was pushed again
					mToggledButton = null;
				}
				else
				{
					//  with the second button we have a return trip, display it
					String[] lHtmlContent = GetHtmlContent( mToggledButton.getDatetime(), lTB.getDatetime(), lTB.getAirline(),
							mToggledButton.getOutboundDepartureAirport(), mToggledButton.getOutboundArrivalAirport(),
							"%", "modalcontainer", false, null, null );
					return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
				}
			}
			else
			{
				//  this is the first button, toggle it!
				mToggledButton = lTB;
				String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList( mToggledButton ),
						lTB.getOutboundDepartureAirport(), lTB.getOutboundArrivalAirport(), mReturnCheckboxChecked );
				return lGetCollectedDepartureDateList;
			}
			// recolor or filter the buttons
		}
		else
		{
			String[] lHtmlContent = GetHtmlContent( lTB.getDatetime(), "", lTB.getAirline(),
					lTB.getOutboundDepartureAirport(), lTB.getOutboundArrivalAirport(),
					"%", "modalcontainer", true, null, null );
			return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
		}
		return null;
	}
}
