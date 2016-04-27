package Util;

import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Andras on 13/04/2016.
 */
public class HighChartDataResultComposer extends DataResultComposer
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(HighChartDataResultComposer.class);

	//private String mResult = new String();
	// if 3 or more value one by one are the same in the list, only the first one and the last one will be displayed
	private ArrayList<Double> mValues;
	private ArrayList<String> mDates;
	private HashSet<String> mFoundCurrency;

	public HighChartDataResultComposer()
	{
		mValues = new ArrayList<>( );
		mDates = new ArrayList<>( );
		mFoundCurrency = new HashSet<>( );
	}

	@Override
	public void add( String aDate, String aValue, String aCurrency )
	{
		// [Date.UTC(1970, 10, 9), 0.4]
		// 2016-04-06 04:00:51
		// 176,89 lv
		// 53 195,00 Ft

		String lValue = "";
		int lPos = aValue.length() - 1;
		char lActChar = aValue.charAt( lPos );
		while( lActChar < '0' || lActChar > '9' )
		{
			lPos--;
			lActChar = aValue.charAt( lPos );
		}
		lValue = aValue.substring( 0, lPos + 1 ).trim();
		String lCurrency = aValue.substring( lPos + 1 ).trim();

		if( !aCurrency.equals( "%" )&& !aCurrency.equals( lCurrency ))
			mLogger.warn( "Illegal currency (" + lCurrency + ") in chart. Expected currency is " + aCurrency );

		mFoundCurrency.add( lCurrency );

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

		if( mFoundCurrency.size() > 1 )
			mLogger.warn( "More different currency in the chart!" );
		return lResult;
	}

	public HashSet<String> getFoundCurrency()
	{
		return mFoundCurrency;
	}
}
