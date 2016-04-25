package Util;

import java.util.ArrayList;

/**
 * Created by Andras on 13/04/2016.
 */
public class HighChartDataResultComposer extends DataResultComposer
{
	//private String mResult = new String();
	// if 3 or more value one by one are the same in the list, only the first one and the last one will be displayed
	private ArrayList<Double> mValues;
	private ArrayList<String> mDates;

	public HighChartDataResultComposer()
	{
		mValues = new ArrayList<>( );
		mDates = new ArrayList<>( );
	}

	@Override
	public void add( String aDate, String aValue, String aCurrency )
	{
		// [Date.UTC(1970, 10, 9), 0.4]
		// 2016-04-06 04:00:51
		// 176,89 lv
		// 53 195,00 Ft

		String lValue = "";
		if( aCurrency.equals( "%" ))
		{
			int lPos = aValue.length() - 1;
			char lActChar = aValue.charAt( lPos );
			while( lActChar < '0' || lActChar > '9' )
			{
				lPos--;
				lActChar = aValue.charAt( lPos );
			}
			lValue = aValue.substring( 0, lPos + 1 ).trim();
		}
		else
		{
			lValue = aValue.substring( 0, aValue.length() - aCurrency.length() ).trim();
		}

		lValue = lValue.replace( ",", "." );
		lValue.replace( " ", "" );
		double lDValue = Double.parseDouble( lValue );

		if( mValues.size() < 2 )
		{
			mDates.add( aDate );
			mValues.add( lDValue );
		}
		else
		{
			if( mValues.get( mValues.size() - 2 ).doubleValue() == mValues.get( mValues.size() - 1 ).doubleValue()
					&& mValues.get( mValues.size() - 1 ).doubleValue() == lDValue )
			{
				mDates.set( mValues.size() - 1, aDate );
				mValues.set( mValues.size() - 1, lDValue );
			}
			else
			{
				mDates.add( aDate );
				mValues.add( lDValue );
			}
		}
	}

	@Override
	public String getResult()
	{
		String lResult = "";
		for( int i = 0; i < mValues.size(); i++ )
		{
			if( lResult.length() > 0 )
				lResult += ",\n";
			lResult += "[Date.parse('" + mDates.get( i ) + "'), " + mValues.get( i ) + "]";
		}
		return lResult;
	}
}
