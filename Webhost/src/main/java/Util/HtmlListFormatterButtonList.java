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
	ArrayList<String> mDepartureDates = new ArrayList<String>();

	@Override
	public void add( String aDepartureDate )
	{
		mDepartureDates.add( aDepartureDate );
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
		for( String lValue : mDepartureDates )
		{
			LocalDateTime lDateTime = LocalDateTime.parse( lValue, lDTFormatter);
			// TODO: what if it is in different time zone?
			ZonedDateTime zdt = lDateTime.atZone( ZoneId.of("Europe/Budapest"));
			long lDepartureMiillis = zdt.toInstant().toEpochMilli();
			lClass = "departurelistbutton";

			if( lCurrentMillis + lFiveDays > lDepartureMiillis
					&& lCurrentMillis - lFiveDays < lDepartureMiillis )
			{
				lClass += " near";
			}

			lReturn += "<input class='" + lClass + "' type='button' name='departuredatetime' value='" + lValue + "'/>";
		}
		return lReturn;
	}
}
