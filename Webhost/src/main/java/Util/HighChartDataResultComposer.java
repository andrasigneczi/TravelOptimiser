package Util;

import org.apache.log4j.Logger;

import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
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
	private int                mFoundCurrencyCount;
	private ArrayList<String>  mUnfilteredDates;
	private HashSet<String>    mFoundCurrency;
	private double             mMaxValue = Double.MIN_VALUE;
	//private boolean           mCurrency_Price_In_Euro_Is_Null = false;
	private String             mMostLeftDate  = "";
	private String             mMostRightDate = "";

	public HighChartDataResultComposer()
	{
		mValues              = new ArrayList<>( );
		mDates               = new ArrayList<>( );
		mUnfilteredValues    = new ArrayList<>( );
		mUnfilteredDates     = new ArrayList<>( );
		mFoundCurrencyCount  = 0;
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
				&& mUnfilteredDates.size() == mFoundCurrencyCount
				&& aOriginalCurrencyMultiplerToEuro > 0.0 )
		{
			lDValue *= (double)aOriginalCurrencyMultiplerToEuro;
			mFoundCurrencyCount++;
		}
		else
		{
			// Some fixes for older data, where the program didn't store the currency multipler
			if( lCurrency.equals( "€" ))
			{
				mFoundCurrencyCount++;
			}
			else if( lCurrency.equals( "lv" ))
			{
				if( aOriginalCurrencyMultiplerToEuro == null )
				{
					final double lCurrencyMultiplerToEuro = 0.511763;
					lDValue *= lCurrencyMultiplerToEuro;
					mFoundCurrencyCount++;
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
			if( i == 0 )
				mMostLeftDate = mDates.get( i );
			if( i == mValues.size() - 1 )
				mMostRightDate = mDates.get( i );
		}

		if( mFoundCurrency.size() > 1 )
			mLogger.warn( "More different currency in the chart!" );
		return lResult;
	}

	public HashSet<String> getFoundCurrency()
	{
		if( mUnfilteredDates.size() == mFoundCurrencyCount )
		{
			HashSet<String> lRetun = new HashSet<String>();
			lRetun.add( "€" );
			return lRetun;
		}
		return mFoundCurrency;
	}

	enum NodeSource
	{
		FirstList,
		SecondList,
		BothList
	};

	private final static DateTimeFormatter mFormatter = DateTimeFormatter.ofPattern( "yyyy-MM-dd'T'HH:mm:ss" );

	private class DatetimeNode
	{
		private LocalDateTime mDatetime;
		private NodeSource    mSource;
		private double        mValue;

		public DatetimeNode( String aDatetime, NodeSource aSource, double aValue )
		{
			mDatetime = LocalDateTime.parse( aDatetime, mFormatter );
			mSource   = aSource;
			mValue    = aValue;
		}

		public void setSource( NodeSource aSource )
		{
			mSource = aSource;
		}

		public NodeSource getSource()
		{
			return mSource;
		}

		public LocalDateTime getDatetime()
		{
			return mDatetime;
		}

		public double getValue()
		{
			return mValue;
		}

		public void add( double aValue )
		{
			mValue += aValue;
		}
	}

	/*
	1. The values of the two unfilteredDates has to be merged into a DateTime Hashtable-be. Every item has to be marked
	   related to the source list.
	2. Create a sorted set from the Hastable.
	3. Compare every key (datetime) with it's neighbours from the sortedset.
	4. If two neighbour point came from different lists and the difference between them is less then 10 minutes,
	   they are a couple in the Summarized list.
	 */
	public String Summarize( HighChartDataResultComposer lComposer )
	{
		Hashtable<String,DatetimeNode> lDatesHash = new Hashtable<>();
		for( int i = 0; i < mUnfilteredDates.size(); i++ )
			lDatesHash.put( mUnfilteredDates.get( i ),
					new DatetimeNode( mUnfilteredDates.get( i ), NodeSource.FirstList, mUnfilteredValues.get( i ) ));

		for( int i = 0; i < lComposer.mUnfilteredDates.size(); i++ )
		{
			if( lDatesHash.containsKey( lComposer.mUnfilteredDates.get( i )))
			{
				DatetimeNode lTemp = lDatesHash.get( lComposer.mUnfilteredDates.get( i ));
				lTemp.setSource( NodeSource.BothList );
				lTemp.add( lComposer.mUnfilteredValues.get( i ) );
			}
			else
			{
				lDatesHash.put( lComposer.mUnfilteredDates.get( i ),
						new DatetimeNode( lComposer.mUnfilteredDates.get( i ), NodeSource.SecondList, lComposer.mUnfilteredValues.get( i ) )
				);
			}
		}

		ArrayList<Double> lValuesList = new ArrayList<Double>();
		ArrayList<String> lDatesList  = new ArrayList<String>();

		SortedSet<String> keys = new TreeSet<String>(lDatesHash.keySet());
		String lPrevKey = null;
		for (String key : keys)
		{
			if( lPrevKey == null )
			{
				lPrevKey = key;
			}
			else
			{
				DatetimeNode lNode1 = lDatesHash.get( lPrevKey );
				DatetimeNode lNode2 = lDatesHash.get( key );

				if( lNode1.getSource() == NodeSource.BothList )
				{
					addDates( lDatesList, lValuesList, lPrevKey, lDatesHash.get( lPrevKey ).getValue() );
				}
				else
				{
					if( lNode2.getSource() != NodeSource.BothList
							&& lNode1.getSource() != lNode2.getSource() )
					{
						if( Duration.between( lNode1.getDatetime(), lNode2.getDatetime() ).getSeconds() <= 300 )
						{
							addDates( lDatesList, lValuesList, lPrevKey,
									lDatesHash.get( lPrevKey ).getValue() + lDatesHash.get( key ).getValue()
							);
						}
					}
				}

				lPrevKey = key;
			}
		}

		if( lPrevKey != null )
		{
			DatetimeNode lNode1 = lDatesHash.get( lPrevKey );
			if( lNode1.getSource() == NodeSource.BothList )
				addDates( lDatesList, lValuesList, lPrevKey, lDatesHash.get( lPrevKey ).getValue());
		}

		String lResult = "";
		for( int i = 0; i < lValuesList.size(); i++ )
		{
			if( lResult.length() > 0 )
				lResult += ",\n";
			if( lValuesList.get( i ) > mMaxValue )
				mMaxValue = lValuesList.get( i );
			lResult += "[Date.parse('" + lDatesList.get( i ) + "'), " + lValuesList.get( i ) + "]";
			if( i == 0 )
				mMostLeftDate = lDatesList.get( i );
			if( i == mValues.size() - 1 )
				mMostRightDate = lDatesList.get( i );
		}

		return lResult;
	}

	public double getMaxValue()
	{
		return mMaxValue;
	}

	public String getMostLeftDate(){
		return mMostLeftDate;
	}

	public String getMostRightDate(){
		return mMostRightDate;
	}
}
