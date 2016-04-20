package Util;

import java.util.HashSet;

/**
 * Created by Andras on 19/04/2016.
 */
public class HtmlListFormatterSelect implements HtmlListFormatter
{
	private HashSet<String> mAirports = new HashSet<String>();

	@Override
	public void add( String aDepartureAirport )
	{
		mAirports.add( aDepartureAirport );
	}

	@Override
	public String getFormattedResult()
	{
		String lReturn = "<select name='DepartureAirportList' id='DepartureAirportList' onchange='" +
				"var pb = document.getElementById( \"pushedbutton\" );pb.value=this.id;$(\"#ajaxform\").submit();'>\n<option value='-'>-</option>\n";
		for( String lValue : mAirports )
		{
			lReturn += "<option value='" + lValue + "'>" + lValue + "</option>\n";
		}
		lReturn += "</select>\n";
		return lReturn;
	}
}
