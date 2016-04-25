package Util;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * Created by Andras on 18/04/2016.
 */
public class HtmlListFormatterButtonList implements HtmlListFormatter
{
	// String[] datetime, airportcode
	ArrayList<String[]> mDepartureDates = new ArrayList<String[]>();

	@Override
	public void add( String aDepartureDate )
	{
		throw new IllegalArgumentException( "This parameterlist is not supported by HtmlListFormatterButtonList" );
	}

	@Override
	public void add( String[] aValues )
	{
		mDepartureDates.add( aValues );
	}

	@Override
	public String getFormattedResult()
	{
		String lReturn = "";
		DateTimeFormatter lDTFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
		LocalDateTime lNow = LocalDateTime.now();

		long lCurrentMillis = System.currentTimeMillis();

		String lClass = "";
		final long lFiveDays = 5 * 24 * 3600 * 1000;
		for( String[] lValue : mDepartureDates )
		{
			LocalDateTime lDateTime = LocalDateTime.parse( lValue[0], lDTFormatter);
			// TODO: what if it is in different time zone?
			ZonedDateTime zdt = lDateTime.atZone( ZoneId.of("Europe/Budapest"));
			long lDepartureMiillis = zdt.toInstant().toEpochMilli();
			lClass = "departurelistbutton";

			if( lCurrentMillis + lFiveDays > lDepartureMiillis
					&& lCurrentMillis - lFiveDays < lDepartureMiillis )
			{
				lClass += " near";
			}

			lReturn += "<input class='" + lClass + "' type='button' name='departuredatetime' value='" + lValue[ 0 ] + "' " +
					"onclick='TO_ActionName=\"DateTimeButtonPushed\";TO_ActionValue=\"" + lValue[ 1 ]+ "\";TO_ActionWidget=this;$(\"#ajaxform\").submit();'/>";
		}
		return lReturn;
	}

	@Override
	public void setSelected( String aValue )
	{

	}
}
