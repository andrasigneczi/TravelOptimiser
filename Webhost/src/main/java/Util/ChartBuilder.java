package Util;

import org.apache.log4j.Logger;
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
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(ChartBuilder.class);

	private final static String mHtmlTemplate   = InitHtmlTemplate();
	private final static String mJsTemplate     = InitJsTemplate();
	private final static String mDivTemplate    = InitDivTemplate();
	private final static String mSeriesTemplate = InitSeriesTemplate();

	private final static String DISCOUNT_COLOR      = "#a0a3ee";
	private final static String BOUGHT_TICKET_COLOR = "#e510e8";
	private final static String SERIES1_COLOR       = "#7cb5ec";
	private final static String SERIES2_COLOR       = "#434348";
	private final static String SERIES3_COLOR       = "#90ed7d";
	private final static String PLOT_RADIUS         = "3";

	private String     mSelectedDepartureAirport = "-";
	private String     mSelectedArrivalAirport   = "-";
	private boolean    mReturnCheckboxChecked    = false;
	private OneWayTrip mToggledButton            = null;
	private String     mOutboundDate             = "";
	private String     mInboundDate              = "";

	// class members for builder
	private String mDate1;
	private String mDate2;
	private Hashtable<String,String>    mResult1;
	private Hashtable<String,String>    mResult2;
	private HighChartDataResultComposer mHighChartDataResultComposerOutbound;
	private HighChartDataResultComposer mHighChartDataResultComposerReturn;
	private String mHtmlTagId           = null;
	private String mSeries1             = null;
	private String mAirportFrom         = null;
	private String mAirportTo           = null;
	private String mBoughtTicketsSeries = null;
	private String mDiscountSeries      = null;
	private TravelData_INPUT mTDI       = null;

	private static String InitHtmlTemplate()
	{
		Scanner lScanner  = new Scanner(ChartBuilder.class.getClassLoader().getResourceAsStream("charts_template.html" ), "UTF-8" );
		String lHtmlTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();
		return lHtmlTemplate;
	}

	private static String InitJsTemplate()
	{
		Scanner lScanner  = new Scanner(ChartBuilder.class.getClassLoader().getResourceAsStream("charts_template.js" ), "UTF-8" );
		String lJsTemplate = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();
		return lJsTemplate;
	}

	private static String InitDivTemplate()
	{
		return "<div id=\"[CONTAINER]\" style=\"min-width: 310px; height: 400px; margin: 0 auto\"></div>";
	}

	private static String InitSeriesTemplate()
	{
		return "{\n" +
				"                name: '[SERIES.NAME]',\n" +
				"                type: '[TYPE.NAME]',\n" +
				"                color: '[COLOR]',\n" +
				"                marker: { radius: [RADIUS] },\n" +
				"                data: [\n" +
				"                [SERIES.DATA]\n" +
				"                ]\n" +
				"            }";
	}

	public ChartBuilder()
	{
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

	public String getOutboundDate()
	{
		return mOutboundDate;
	}

	public void setOutboundDate( String mOutboundDate )
	{
		this.mOutboundDate = mOutboundDate;
	}

	public String getInboundDate()
	{
		return mInboundDate;
	}

	public void setInboundDate( String mInboundDate )
	{
		this.mInboundDate = mInboundDate;
	}

	private static String IsoDatetimeToEngDate( String aDateTime )
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
		String lHeight = "100";

		if( mHighChartDataResultComposerOutbound != null )
			lHeight = String.valueOf( mHighChartDataResultComposerOutbound.getMaxValue() );

		for( TravelData_INPUT.Discount lDiscount : aDiscounts )
		{
			HighChartDataResultComposer lHCDRCExtra = new HighChartDataResultComposer();
			lHCDRCExtra.add( lDiscount.mBeginning, lHeight, new Float(1.0) );
			lHCDRCExtra.add( lDiscount.mEnding, lHeight, new Float( 1.0 ));
			lSeries += mSeriesTemplate.replace( "[SERIES.NAME]", lDiscount.mName )
					.replace( "[TYPE.NAME]", "area" )
					.replace( "[COLOR]", DISCOUNT_COLOR )
					.replace( "[RADIUS]", "1" )
					.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() ) + ",\n";
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
			lHCDRCExtra.add( lTicket.mDatetime, lTicket.mPrice, new Float( 1.0 ));
			lSeries += ",\n" + mSeriesTemplate.replace( "[SERIES.NAME]", lTicket.mName )
					.replace( "[TYPE.NAME]", "line" )
					.replace( "[COLOR]", BOUGHT_TICKET_COLOR )
					.replace( "[RADIUS]", "6" )
					.replace( "[SERIES.DATA]", lHCDRCExtra.getResult() );
		}
		return lSeries;
	}

	private String GetSeries1()
	{
		mHighChartDataResultComposerOutbound = new HighChartDataResultComposer();
		mResult1 = SQLiteDataProvider.getInstance().GetTripData( mTDI.mDepartureDatetime /*2016-07-16 06:30*/,
				mTDI.mAirline, mTDI.mAirportCode_LeavingFrom, mTDI.mAirportCode_GoingTo,
				mHighChartDataResultComposerOutbound );
		mDate1 = IsoDatetimeToEngDate( mTDI.mDepartureDatetime );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", mDate1 )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[COLOR]", SERIES1_COLOR )
				.replace( "[RADIUS]", PLOT_RADIUS )
				.replace( "[SERIES.DATA]", mResult1.get( "Result" ) );
		return lSeries;
	}

	private String GetSeries2()
	{
		mHighChartDataResultComposerReturn = new HighChartDataResultComposer();
		mResult2 = SQLiteDataProvider.getInstance()
				.GetTripData( mTDI.mReturnDatetime,
						mTDI.mAirline,
						mTDI.mAirportCode_GoingTo,
						mTDI.mAirportCode_LeavingFrom,
						mHighChartDataResultComposerReturn );
		mDate2 = IsoDatetimeToEngDate( mTDI.mReturnDatetime );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", mDate2 )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[COLOR]", SERIES2_COLOR )
				.replace( "[RADIUS]", PLOT_RADIUS )
				.replace( "[SERIES.DATA]", mResult2.get( "Result" ) );
		return lSeries;
	}

	private String GetSeries3()
	{
		String lSumResult = mHighChartDataResultComposerOutbound.Summarize( mHighChartDataResultComposerReturn );
		String lSeries = mSeriesTemplate.replace( "[SERIES.NAME]", "Sum" )
				.replace( "[TYPE.NAME]", "line" )
				.replace( "[COLOR]", SERIES3_COLOR )
				.replace( "[RADIUS]", PLOT_RADIUS )
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

	private String[] GetReturnTripHtmlContent()
	{
		String lSeries2 = GetSeries2();

		HashSet<String> lFoundCurrency = mHighChartDataResultComposerReturn.getFoundCurrency();
		String lCurrency = mTDI.mCurrency;
		if( lCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
			lCurrency = lFoundCurrency.iterator().next();

		String lSeries3 = GetSeries3();
		mDiscountSeries = GetDiscountSeries( mTDI.mDiscounts );

		String lTitle = mDate1 + " - " + mDate2 + " " + mAirportFrom + " - " + mAirportTo;
		String lSeries = mDiscountSeries + mSeries1 + ",\n" + lSeries2 + ",\n" + lSeries3 + mBoughtTicketsSeries;

		String lJS = GetTripJS( lTitle, mTDI.mAirline, lCurrency, lSeries, mHtmlTagId );
		String lDiv = mDivTemplate.replace( "[CONTAINER]", mHtmlTagId );
		return new String[] { lDiv, lJS };
	}

	private String[] GetOneWayHtmlContent()
	{
		HashSet<String> lFoundCurrency = mHighChartDataResultComposerOutbound.getFoundCurrency();
		String lCurrency = mTDI.mCurrency;
		if( lCurrency.equals( "%" ) && !lFoundCurrency.isEmpty())
			lCurrency = lFoundCurrency.iterator().next();

		mDiscountSeries = GetDiscountSeries( mTDI.mDiscounts );

		String lTitle = mDate1 + " " + mAirportFrom + " - " + mAirportTo;
		String lSeriesSum = mDiscountSeries + mSeries1 + mBoughtTicketsSeries;

		String lJS = GetTripJS(lTitle, mTDI.mAirline, lCurrency, lSeriesSum, mHtmlTagId );
		String lDiv = mDivTemplate.replace( "[CONTAINER]", mHtmlTagId );
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
		mTDI = new TravelData_INPUT();
		mTDI.mDepartureDatetime       = aDateTime1;
		mTDI.mReturnDatetime          = aDateTime2;
		mTDI.mAirline                 = aAirline;
		mTDI.mAirportCode_LeavingFrom = aAirportFrom;
		mTDI.mAirportCode_GoingTo     = aAirportTo;
		mTDI.mCurrency                = aCurrency;
		mTDI.mBoughtTickets           = aBoughtTickets;
		mTDI.mDiscounts               = aDiscounts;
		mHtmlTagId                    = aHtmlTagId;

		mSeries1 = GetSeries1();

		mAirportFrom = aAirportFrom;
		if( aAirportFrom.equals( "-" ))
			mAirportFrom = mResult1.get( "AirportCode_LeavingFrom" );

		mAirportTo = aAirportTo;
		if( aAirportTo.equals( "-" ))
			mAirportTo = mResult1.get( "AirportCode_GoingTo" );

		mBoughtTicketsSeries = GetBoughtTicketsSeries( aBoughtTickets );

		if( aOneWay )
			return GetOneWayHtmlContent();

		return GetReturnTripHtmlContent();
	}

	private String[] GenerateDivAndScriptContentsFromConfig()
	{
		ArrayList<TravelData_INPUT> lSearchList = Configuration.getInstance().getSearchList();
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
		return new String[] { lScriptCotent, lDivContent };
	}

	private String[] GenerateDivAndScriptContentsFromFavorites( String[] aContents )
	{
		Favorites lFavorites = Favorites.getInstance();
		String lScriptCotent = "";
		String lDivContent = "";
		int lContainerIndex = 0;

		for( int i = 0; i < lFavorites.size(); i++ )
		{
			OneWayTrip[] lTrips = lFavorites.get( i );
			String lDatetime2 = "";

			if( !lTrips[ 0 ].getAirline().equals( "wizzair" ) && !lTrips[ 0 ].getAirline().equals( "ryanair" ))
				continue;
			if( lTrips.length == 2 )
			{
				if( !lTrips[ 1 ].getAirline().equals( "wizzair" ) && !lTrips[ 1 ].getAirline().equals( "ryanair" ))
					continue;
				lDatetime2 = lTrips[ 1 ].getDatetime();
			}
			String lStartTag = "<img class=\"favoritestar\" src=\"/img/star_filled.png\" onclick=\"bookmarkChart2(this, '"
					+ lFavorites.getSource( i ) + "' );\"/>";
			String[] lContent = GetHtmlContent( lTrips[ 0 ].getDatetime(), lDatetime2,
					lTrips[ 0 ].getAirline(), lTrips[ 0 ].getLeavingFrom(), lTrips[ 0 ].getGoingTo(),
					"%", "Favoritecontainer" + lContainerIndex++, lDatetime2.length() == 0,
					null, null );
			lScriptCotent += lContent[ 1 ];
			lDivContent += lStartTag + lContent[ 0 ];
		}

		return new String[] { aContents[ 0 ] + lScriptCotent, aContents[ 1 ] + lDivContent };
	}

	public String GenerateHtmlContentUsingConfig()
	{
		String[] lContents1 = GenerateDivAndScriptContentsFromConfig();
		String[] lContents = GenerateDivAndScriptContentsFromFavorites( lContents1 );

		String lScriptCotent = lContents[ 0 ];
		String lDivContent = lContents[ 1 ];

		String lHtml = mHtmlTemplate.replace( "[CHART_SCRIPTS]", lScriptCotent )
				.replace( "[CHART_DIVS]", lDivContent );

		String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance()
				.GetCollectedDepartureDateList( new HtmlListFormatterButtonList(),
				mSelectedDepartureAirport, mSelectedArrivalAirport, mReturnCheckboxChecked,
						mOutboundDate, mInboundDate );
		lHtml = lHtml.replace( "[AVAILABLE_TRIPS]", lGetCollectedDepartureDateList );

		String lDepartureAirportSelector = SQLiteDataProvider.getInstance()
				.GetDepartureAirportList( new HtmlListFormatterSelect( "DepartureAirportList" ),
				mSelectedDepartureAirport);
		lHtml = lHtml.replace( "[DEPARTURE_AIRPORTS]", lDepartureAirportSelector );

		String lArrivalAirportSelector = SQLiteDataProvider.getInstance()
				.GetArrivalAirportList( new HtmlListFormatterSelect( "ArrivalAirportList" ),
				mSelectedDepartureAirport, mSelectedArrivalAirport);
		lHtml = lHtml.replace( "[ARRIVAL_AIRPORTS]", lArrivalAirportSelector );

		return lHtml;
	}

	private String DBP_ReturnCheckboxChecked( final OneWayTrip aTB )
	{
		if( mToggledButton != null )//if( a button already pushed )
		{
			if( mToggledButton.equals( aTB ))
			{ // if the toggled button was pushed again
				mToggledButton = null;
			}
			else
			{
				//  with the second button we have a return trip, display it
				String[] lHtmlContent = GetHtmlContent( mToggledButton.getDatetime(), aTB.getDatetime(), aTB.getAirline(),
						mToggledButton.getOutboundDepartureAirport(), mToggledButton.getOutboundArrivalAirport(),
						"%", "modalcontainer", false, null, null );
				if( Favorites.getInstance().contains( mToggledButton, aTB ))
					lHtmlContent[ 0 ] += "<!-- bookmarked -->";
				return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
			}
		}
		else
		{
			//  this is the first button, toggle it!
			mToggledButton = aTB;
			String lGetCollectedDepartureDateList = SQLiteDataProvider.getInstance().GetCollectedDepartureDateList( new HtmlListFormatterButtonList( mToggledButton ),
					aTB.getOutboundDepartureAirport(), aTB.getOutboundArrivalAirport(), mReturnCheckboxChecked,
					mOutboundDate, mInboundDate );
			return lGetCollectedDepartureDateList;
		}
		// recolor or filter the buttons
		return null;
	}

	private String DBP_ReturnCheckboxNotChecked( final OneWayTrip aTB )
	{
		String[] lHtmlContent = GetHtmlContent( aTB.getDatetime(), "", aTB.getAirline(),
				aTB.getOutboundDepartureAirport(), aTB.getOutboundArrivalAirport(),
				"%", "modalcontainer", true, null, null );
		if( Favorites.getInstance().contains( aTB, null ))
			lHtmlContent[ 0 ] += "<!-- bookmarked -->";
		return lHtmlContent[ 0 ] + "<script>" + lHtmlContent[ 1 ] + "</script>";
	}

	public String DateTimeButtonPushed( final String aParam )
	{
		String[] lValues = aParam.split( "\\|" );
		// lValues = airline, leavingfrom, goingto, outbound, datetime
		OneWayTrip lTB = new OneWayTrip(
				lValues[ 4 ], lValues[ 0 ],
				lValues[ 1 ], lValues[ 2 ],
				Boolean.parseBoolean( lValues[ 3 ] ));

		if( mReturnCheckboxChecked )
			return DBP_ReturnCheckboxChecked( lTB );

		return DBP_ReturnCheckboxNotChecked( lTB );
	}

	public void BookmarkTrip( String aParam )
	{
		String[] lValues = aParam.split( "\\|" );
		// lValues = airline, leavingfrom, goingto, outbound, datetime
		OneWayTrip lTB = new OneWayTrip(
				lValues[ 4 ], lValues[ 0 ],
				lValues[ 1 ], lValues[ 2 ],
				Boolean.parseBoolean( lValues[ 3 ] ));

//		OneWayTrip lTB = new OneWayTrip( mTDI.mDepartureDatetime,
//				mTDI.mAirline, mTDI.mAirportCode_LeavingFrom,
//				mTDI.mAirportCode_GoingTo, true );

		if( mToggledButton == null )
			Favorites.getInstance().add( lTB, null );
		else
			Favorites.getInstance().add( mToggledButton, lTB );
		Favorites.getInstance().SaveFavourtes();
	}

	public void UpdateBookmarkTrip( String aParam )
	{
		int lIndex = Favorites.getInstance().indexOf( aParam );
		if( lIndex >= 0 )
			Favorites.getInstance().remove( lIndex );
		else
		{
			OneWayTrip[] lTrips = Favorites.getInstance().getFromSource( aParam );
			if( lTrips.length == 1 )
				Favorites.getInstance().add( lTrips[ 0 ], null );
			else
				Favorites.getInstance().add( lTrips[ 0 ], lTrips[ 1 ] );
		}
		Favorites.getInstance().SaveFavourtes();
	}
}
