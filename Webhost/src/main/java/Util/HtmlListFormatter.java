package Util;

/**
 * Created by Andras on 19/04/2016.
 */
public interface HtmlListFormatter
{
	void add( String aValue );
	void add( String[] aValues );
	String getFormattedResult();
	void setSelected( String aValue );
}
