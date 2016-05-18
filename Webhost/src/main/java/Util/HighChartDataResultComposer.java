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
	private ArrayList<Double> mValues;
	private ArrayList<String> mDates;
	private ArrayList<Double> mUnfilteredValues;
	private ArrayList<String> mUnfilteredDates;
	private HashSet<String> mFoundCurrency;

	public HighChartDataResultComposer()
	{
		mValues = new ArrayList<>( );
		mDates = new ArrayList<>( );
		mUnfilteredValues = new ArrayList<>( );
		mUnfilteredDates = new ArrayList<>( );
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
		//lValue = lValue.replace( " ", "" );
		StringBuffer lBuffer = new StringBuffer();
		for( int i = 0; i < lValue.length(); i++ )
			if(( lValue.charAt( i ) >= '0' && lValue.charAt( i ) <= '9') ||
				lValue.charAt( i ) == '.' )
				lBuffer.append( lValue.charAt( i ));
		double lDValue = Double.parseDouble( lBuffer.toString() );

		aDate = aDate.replace( " ", "T" );
		mUnfilteredDates.add( aDate );
		mUnfilteredValues.add( lDValue );
//		if( mValues.size() < 2 )
//		{
//			mDates.add( aDate );
//			mValues.add( lDValue );
//		}
//		else
//		{
//			if( mValues.get( mValues.size() - 2 ).doubleValue() == mValues.get( mValues.size() - 1 ).doubleValue()
//					&& mValues.get( mValues.size() - 1 ).doubleValue() == lDValue )
//			{
//				mDates.set( mValues.size() - 1, aDate );
//				mValues.set( mValues.size() - 1, lDValue );
//			}
//			else
//			{
//				mDates.add( aDate );
//				mValues.add( lDValue );
//			}
//		}
		addDates( mDates, mValues, aDate, lDValue );
	}

	private void addDates( ArrayList<String> aDatesArray, ArrayList<Double> aValuesArray, String aDate, Double aValue )
	{
		if( aValuesArray.size() < 2 )
		{
			aDatesArray.add( aDate );
			aValuesArray.add( aValue );
		}
		else
		{
			if( aValuesArray.get( aValuesArray.size() - 2 ).doubleValue() == aValuesArray.get( aValuesArray.size() - 1 ).doubleValue()
					&& aValuesArray.get( aValuesArray.size() - 1 ).doubleValue() == aValue )
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

	public String Summarize( HighChartDataResultComposer lComposer )
	{
		Hashtable<String,Double> lDatesHash = new Hashtable<>();
		for( int i = 0; i < mUnfilteredDates.size(); i++ )
			lDatesHash.put( mUnfilteredDates.get( i ), mUnfilteredValues.get( i ));

		for( int i = 0; i < lComposer.mUnfilteredDates.size(); i++ )
		{
			if( lDatesHash.containsKey( lComposer.mUnfilteredDates.get( i )))
				lDatesHash.replace( lComposer.mUnfilteredDates.get( i ), lComposer.mUnfilteredValues.get( i ) + lDatesHash.get( lComposer.mUnfilteredDates.get( i ) ));
			else
				lDatesHash.put( lComposer.mUnfilteredDates.get( i ), lComposer.mUnfilteredValues.get( i ));
		}

		ArrayList<Double> lValuesList = new ArrayList<Double>();
		ArrayList<String> lDatesList  = new ArrayList<String>();

		SortedSet<String> keys = new TreeSet<String>(lDatesHash.keySet());
		for (String key : keys)
		{
			addDates( lDatesList, lValuesList, key, lDatesHash.get( key ));
		}

		String lResult = "";
		for( int i = 0; i < lValuesList.size(); i++ )
		{
			if( lResult.length() > 0 )
				lResult += ",\n";
			lResult += "[Date.parse('" + lDatesList.get( i ) + "'), " + lValuesList.get( i ) + "]";
		}

		return lResult;
	}
}
