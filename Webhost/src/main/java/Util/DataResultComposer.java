package Util;

/**
 * Created by Andras on 13/04/2016.
 */
public abstract class DataResultComposer
{
	public abstract void add( String aDate, String aValue, Float aOriginalCurrencyToEuro );
	public abstract String getResult();
}
