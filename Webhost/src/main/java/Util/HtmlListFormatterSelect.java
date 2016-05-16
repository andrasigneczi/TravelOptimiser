package Util;

import java.util.HashSet;

/**
 * Created by Andras on 19/04/2016.
 */
public class HtmlListFormatterSelect implements HtmlListFormatter
{
	private String mName;
	private HashSet<String> mAirports = new HashSet<String>();
	private String mSelectedValue = "";

	public HtmlListFormatterSelect( String aName )
	{
		mName = aName;
	}

	@Override
	public void add( String aDepartureAirport )
	{
		mAirports.add( aDepartureAirport );
	}

	@Override
	public void add( String[] aValues )
	{
		throw new IllegalArgumentException( "This parameterlist is not supported by HtmlListFormatterSelect" );
	}

	@Override
	public String getFormattedResult()
	{
		String lReturn = "<select name='" + mName + "' id='" + mName + "' onchange='" +
				"TO_ActionName=\"" + mName + "Changed\";TO_ActionWidget=this;$(\"#ajaxform\").submit();'>\n<option value='-'>-</option>\n";
		for( String lValue : mAirports )
		{
			if( mSelectedValue.equals( lValue ))
				lReturn += "<option value='" + lValue + "' selected>" + lValue + "</option>\n";
			else
				lReturn += "<option value='" + lValue + "'>" + lValue + "</option>\n";
		}
		lReturn += "</select>\n";
		return lReturn;
	}

	@Override
	public void setSelected( String aValue )
	{
		mSelectedValue = aValue;
	}
}
