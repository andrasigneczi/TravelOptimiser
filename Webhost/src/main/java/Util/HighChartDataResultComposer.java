package Util;

/**
 * Created by Andras on 13/04/2016.
 */
public class HighChartDataResultComposer extends DataResultComposer
{
	private String mResult = new String();

	@Override
	public void add( String aDate, String aValue, String aCurrency )
	{
		// [Date.UTC(1970, 10, 9), 0.4]
		// 2016-04-06 04:00:51
		// 176,89 lv
		// 53 195,00 Ft

		String lValue = aValue.substring( 0, aValue.length() - aCurrency.length() ).trim();
		lValue = lValue.replace( ",", "." );
		lValue.replace( " ", "" );

		if( mResult.length() > 0 )
			mResult += ",\n";
		mResult += "[Date.parse('" + aDate + "'), " + lValue + "]";
	}

	@Override
	public String getResult()
	{
		return mResult;
	}
}
