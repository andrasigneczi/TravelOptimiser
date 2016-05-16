package Util;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Andras on 18/04/2016.
 */
public class HtmlListFormatterButtonList implements HtmlListFormatter
{
	OneWayTrip mToggledButton = null;
	// String[] datetime, airline, AirportCode_LeavingFrom, AirportCode_GoingTo, OutboundTrip
	//ArrayList<String[]> mDepartureDates = new ArrayList<String[]>();
	ArrayList<OneWayTrip> mDepartureDates = new ArrayList<>();

			// The database can define a trip two different ways because of the outboundtrip flag,
	// so I have to make the frips unique here.
	HashSet<OneWayTrip> mTrips = new HashSet<>();

	public HtmlListFormatterButtonList()
	{
		super();
	}

	public HtmlListFormatterButtonList( OneWayTrip aToggledButton )
	{
		mToggledButton = aToggledButton;
	}

	@Override
	public void add( String aDepartureDate )
	{
		throw new IllegalArgumentException( "This parameterlist is not supported by HtmlListFormatterButtonList" );
	}

	@Override
	public void add( String[] aValues )
	{
		OneWayTrip lTB = new OneWayTrip(
				aValues[ 0 ], aValues[ 1 ],
				aValues[ 2 ], aValues[ 3 ],
				Boolean.parseBoolean( aValues[ 4 ] ) );

		if( mTrips.contains( lTB ))
			return;

		mTrips.add( lTB );
		mDepartureDates.add( lTB );
	}

	@Override
	public String getFormattedResult()
	{
		String lReturn = "";
		DateTimeFormatter lDTFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
		LocalDateTime lNow = LocalDateTime.now();

		long lCurrentMillis = System.currentTimeMillis();
		long lToggleDepartureMiillis = -1;

		if( mToggledButton != null )
		{
			LocalDateTime lToggleDateTime = LocalDateTime.parse( mToggledButton.getDatetime(), lDTFormatter);
			// TODO: what if it is in different time zone?
			ZonedDateTime lTDT = lToggleDateTime.atZone( ZoneId.of("Europe/Budapest"));
			lToggleDepartureMiillis = lTDT.toInstant().toEpochMilli();
		}

		String lClass = "";
		final long lFiveDays = 5 * 24 * 3600 * 1000;
		for( OneWayTrip lTB : mDepartureDates )
		{
			LocalDateTime lDateTime = LocalDateTime.parse( lTB.getDatetime(), lDTFormatter);
			// TODO: what if it is in different time zone?
			ZonedDateTime zdt = lDateTime.atZone( ZoneId.of("Europe/Budapest"));
			long lDepartureMiillis = zdt.toInstant().toEpochMilli();

			lClass = "departurelistbutton";

			if( lCurrentMillis + lFiveDays > lDepartureMiillis
					&& lCurrentMillis - lFiveDays < lDepartureMiillis )
			{
				lClass += " near";
			}

			if( mToggledButton != null )
			{
				/*
					Ekkor minden olyan gomb átszineződik, amelyikhez olyan járat tartozik,
					aminek induló reptere megegyezik a megnyomott gomb érkező repterével,
					valamint az indulás dátum és időpont legalább 1 órával a megnyomott
					gomb érkezési dátum és időpontja után van. A többi gomb legyen inaktív.
				 */

				if( mToggledButton.equals( lTB ))
				{
					lClass += " active";
				}
				else
				{
					if( lToggleDepartureMiillis > lDepartureMiillis )
						continue;

					if( !mToggledButton.getOutboundArrivalAirport().equals( lTB.getOutboundDepartureAirport()))
						continue;
				}
			}

			lReturn += "<input data-toggle='buttonlist-tooltip' class='btn btn-default " + lClass + "' type='button' name='departuredatetime' " +
					"value='" + lTB.getDatetime() + "' " +
					"onclick='TO_ActionName=\"DateTimeButtonPushed\";TO_ActionValue=\"" + lTB.getAirline() +
					"|" + lTB.getLeavingFrom() + "|" + lTB.getGoingTo() + "|" + lTB.getOutbound() +
					"\";TO_ActionWidget=this;$(\"#ajaxform\").submit();'" +
					" title='" + lTB.getAirline() + ", " + lTB.getOutboundDepartureAirport() + "," + lTB.getOutboundArrivalAirport() + "'/>";
		}
		return lReturn;
	}

	@Override
	public void setSelected( String aValue )
	{

	}
}
