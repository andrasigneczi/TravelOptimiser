package Util;

import org.apache.log4j.Logger;

import java.util.*;

/**
 * Created by Andras on 13/04/2016.
 */
public class HighChartDataResultComposer extends DataResultComposer
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(HighChartDataResultComposer.class);

	//private String mResult = new String();
	// if 3 or more value one by one are the same in the list, only the first one and the last one will be displayed
	private ArrayList<Double>  mValues;
	private ArrayList<String>  mDates;
	private ArrayList<Double>  mUnfilteredValues;
	private ArrayList<Double>  mCurrencyPriceInEuro;
	private ArrayList<String>  mUnfilteredDates;
	private HashSet<String>    mFoundCurrency;
	private double             mMaxValue = Double.MIN_VALUE;
	//private boolean           mCurrency_Price_In_Euro_Is_Null = false;

	public HighChartDataResultComposer()
	{
		mValues              = new ArrayList<>( );
		mDates               = new ArrayList<>( );
		mUnfilteredValues    = new ArrayList<>( );
		mUnfilteredDates     = new ArrayList<>( );
		mCurrencyPriceInEuro = new ArrayList<>( );
		mFoundCurrency       = new HashSet<>( );
	}

	@Override
	public void add( String aDate, String aValueInOriginalCurrency, Float aOriginalCurrencyMultiplerToEuro )
	{
		// [Date.UTC(1970, 10, 9), 0.4]
		// 2016-04-06 04:00:51
		// 176,89 lv
		// 53 195,00 Ft

		String lValue = "";
		int lPos = aValueInOriginalCurrency.length() - 1;
		char lActChar = aValueInOriginalCurrency.charAt( lPos );
		while( lActChar < '0' || lActChar > '9' )
		{
			lPos--;
			lActChar = aValueInOriginalCurrency.charAt( lPos );
		}
		lValue = aValueInOriginalCurrency.substring( 0, lPos + 1 ).trim();
		String lCurrency = aValueInOriginalCurrency.substring( lPos + 1 ).trim();

//		if( !aCurrency.equals( "%" )&& !aCurrency.equals( lCurrency ))
//			mLogger.warn( "Illegal currency (" + lCurrency + ") in chart. Expected currency is " + aCurrency );

		mFoundCurrency.add( lCurrency );

		lValue = lValue.replace( ",", "." );
		//lValue = lValue.replace( " ", "" );
		StringBuffer lBuffer = new StringBuffer();
		for( int i = 0; i < lValue.length(); i++ )
			if(( lValue.charAt( i ) >= '0' && lValue.charAt( i ) <= '9') ||
				lValue.charAt( i ) == '.' )
				lBuffer.append( lValue.charAt( i ));
		double lDValue = Double.parseDouble( lBuffer.toString() );
		if( aOriginalCurrencyMultiplerToEuro != null
				&& mUnfilteredDates.size() == mCurrencyPriceInEuro.size()
				&& aOriginalCurrencyMultiplerToEuro > 0.0 )
		{
			lDValue *= (double)aOriginalCurrencyMultiplerToEuro;
			mCurrencyPriceInEuro.add( (double)aOriginalCurrencyMultiplerToEuro );
		}
		else
		{
			// Some fixes for older data, where the program didn't store the currency multipler
			if( lCurrency.equals( "€" ))
			{
				mCurrencyPriceInEuro.add( 1.0 );
			}
			else if( lCurrency.equals( "lv" ))
			{
				if( aOriginalCurrencyMultiplerToEuro == null )
				{
					final double lCurrencyMultiplerToEuro = 0.511763;
					lDValue *= lCurrencyMultiplerToEuro;
					mCurrencyPriceInEuro.add( lCurrencyMultiplerToEuro );
				}
			}
		}

		aDate = aDate.replace( " ", "T" );
		mUnfilteredDates.add( aDate );
		mUnfilteredValues.add( lDValue );
		addDates( mDates, mValues, aDate, lDValue );
	}

	/**
	 * If the algorithm find three identical currency value one after another,
	 * it will remove the middle one. Two value identical if their difference less than 0.7.
	 * @param aDatesArray
	 * @param aValuesArray
	 * @param aDate
	 * @param aValue
	 */
	private void addDates( ArrayList<String> aDatesArray, ArrayList<Double> aValuesArray, String aDate, Double aValue )
	{
		if( aValuesArray.size() < 2 )
		{
			aDatesArray.add( aDate );
			aValuesArray.add( aValue );
		}
		else
		{
			final double lLastValue = aValuesArray.get( aValuesArray.size() - 1 ).doubleValue();
			final double lPenultimateValue = aValuesArray.get( aValuesArray.size() - 2 ).doubleValue();
			final double lThreshold = 0.7;
			//if( lPenultimateValue == lLastValue && lLastValue == aValue )
			if( Math.abs( lPenultimateValue - lLastValue ) < lThreshold && Math.abs( lLastValue - aValue ) < lThreshold )
			{
				aDatesArray.set( aValuesArray.size() - 1, aDate );
				aValuesArray.set( aValuesArray.size() - 1, aValue );
			}
			else
			{
				aDatesArray.add( aDate );
				aValuesArray.add( aValue );
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
			if( mValues.get( i ) > mMaxValue )
				mMaxValue = mValues.get( i );
			lResult += "[Date.parse('" + mDates.get( i ) + "'), " + mValues.get( i ) + "]";
		}

		if( mFoundCurrency.size() > 1 )
			mLogger.warn( "More different currency in the chart!" );
		return lResult;
	}

	public HashSet<String> getFoundCurrency()
	{
		if( mUnfilteredDates.size() == mCurrencyPriceInEuro.size())
		{
			HashSet<String> lRetun = new HashSet<String>();
			lRetun.add( "€" );
			return lRetun;
		}
		return mFoundCurrency;
	}

	private class SummarizeNode
	{
		private double mValue;
		private int mAddCount;

		public double getValue()
		{
			return mValue;
		}

		public int getAddCount()
		{
			return mAddCount;
		}

		public SummarizeNode( double aValue )
		{
			mValue = aValue;
			mAddCount = 0;
		}

		public void add( double aValue )
		{
			mValue += aValue;
			mAddCount++;
		}
	}

	/**
	 * This function generates the chart values of two charts. It ignores those points of charts
	 * which date axis is different.
	 * @param lComposer
	 * @return
	 */
	public String Summarize( HighChartDataResultComposer lComposer )
	{
		// Collect points of the recent chart into a hashtable
		Hashtable<String,SummarizeNode> lDatesHash = new Hashtable<>();
		for( int i = 0; i < mUnfilteredDates.size(); i++ )
			lDatesHash.put( mUnfilteredDates.get( i ), new SummarizeNode( mUnfilteredValues.get( i )));

		// add values of those points from tha parameter chart, which date is equal
		for( int i = 0; i < lComposer.mUnfilteredDates.size(); i++ )
		{
			if( lDatesHash.containsKey( lComposer.mUnfilteredDates.get( i )))
				lDatesHash.get( lComposer.mUnfilteredDates.get( i )).add( lComposer.mUnfilteredValues.get( i ));
		}

		ArrayList<Double> lValuesList = new ArrayList<Double>();
		ArrayList<String> lDatesList  = new ArrayList<String>();

		SortedSet<String> keys = new TreeSet<String>(lDatesHash.keySet());
		for (String key : keys)
		{
			// ignore those points, which has single value, wasn't summarize with an other one
			if( lDatesHash.get( key ).getAddCount() != 1 )
				continue;
			addDates( lDatesList, lValuesList, key, lDatesHash.get( key ).getValue());
		}

		String lResult = "";
		for( int i = 0; i < lValuesList.size(); i++ )
		{
			if( lResult.length() > 0 )
				lResult += ",\n";
			if( lValuesList.get( i ) > mMaxValue )
				mMaxValue = lValuesList.get( i );
			lResult += "[Date.parse('" + lDatesList.get( i ) + "'), " + lValuesList.get( i ) + "]";
		}

		return lResult;
	}

	public double getMaxValue()
	{
		return mMaxValue;
	}
}
