package PageGuest;

import QueueHandlers.*;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Andras on 13/05/2016.
 */
public abstract class PageGuest
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger(PageGuest.class);
	private final  String                      mAirline;
	private        Hashtable<String, String>   mAirports;
	protected      TravelData_RESULT           mTravelDataResult = null;
	protected      StackIF<Object>             mSearchQueue;
	protected      Object                      mMutex = new Object();
	protected      Thread                      mThread;
	protected      boolean                     mThreadStopped = true;

	public enum FareType
	{
		Normal,
		Business
	};

	public enum DateValidity
	{
		INVALID_COMBINATION,
		BOTH_OF_THEM_VALID,
		ONLY_THE_RETURN_DATE_VALID
	};

	public PageGuest(String aAirline)
	{
		mAirline = aAirline;
		if( mAirline != null )
			InitAirportList();
	}

	private void InitAirportList()
	{
		Scanner lScanner = new Scanner(
				getClass().getClassLoader().getResourceAsStream("airports_" + mAirline + ".txt"), "UTF-8");
		String lAirports = lScanner.useDelimiter("\\A").next();
		lScanner.close();

		mAirports = new Hashtable<String, String>();
		Pattern reg = Pattern.compile("^(.+)$", Pattern.MULTILINE);
		Matcher m   = reg.matcher(lAirports);

		while (m.find())
		{
			String lRow = m.group().toString().trim();
			if (lRow.startsWith("#"))
			{
				continue;
			}

			String lAirporCode = lRow.substring(0, 3);
			String lAirporName = lRow.substring(4);
			mAirports.put(lAirporCode, lAirporName);
		}
	}

	protected Hashtable<String, String> getAirports()
	{
		return mAirports;
	}

	public String getAirline()
	{
		return mAirline;
	}

	public String getAirportName(String aCode)
	{
		return getAirports().get(aCode);
	}

	public String getAirportCode( String aName )
	{
		if( aName.length() == 0 )
			return "";

		String lAirportCode = "";
		String lName = aName.toLowerCase();
		Set<Map.Entry<String,String>> lEntrySet = getAirports().entrySet();
		for( Map.Entry<String,String> lEntry : lEntrySet )
		{
			if( lEntry.getValue().toLowerCase().startsWith( lName ))
			{
				lAirportCode = lEntry.getKey();
				break;
			}
		}

		if( lAirportCode.length() != 3 )
		{
			mLogger.error( "Unknown airport: " + aName );
			return "";
		}

		if( !getAirportName( lAirportCode ).toLowerCase().startsWith( aName.toLowerCase() ))
		{
			mLogger.error( "Airport name isn't unequivocal : " + aName );
			return "";
		}
		return lAirportCode;

	}

	static protected void Sleep(int aValue)
	{
		try
		{
			Thread.sleep(aValue);
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
		}
	}

	public abstract void DoSearch(String aAirportCode_Way_From, String aAirportCode_Way_To,
	                              String aDepartureDate_Way_To, String aReturnDate_Way_Back);

	public void DoSearchByAirportName( String aAirportName_Way_From, String aAirportName_Way_To,
	                                   String aDepartureDate_Way_To, String aReturnDate_Way_Back )
	{
		String aAirportCode_Way_From = getAirportCode( aAirportName_Way_From );
		if( aAirportCode_Way_From.length() != 3 )
			return;

		String aAirportCode_Way_To = getAirportCode( aAirportName_Way_To );
		if( aAirportCode_Way_To.length() != 3 )
			return;
		DoSearch( aAirportCode_Way_From, aAirportCode_Way_To, aDepartureDate_Way_To, aReturnDate_Way_Back );
	}

	public abstract void DoSearchFromConfig();

	public void stop()
	{
		mThreadStopped = true;
		try
		{
			mThread.join();
		}
		catch (InterruptedException e)
		{
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
		System.out.println("stop()");
	}

	public static DateValidity ValidateDate( String aDepartureDay, String aReturnDay )
	{
		try
		{
			DateTimeFormatter lFormatter = DateTimeFormatter.ofPattern( "yyyy.MM.dd." );
			LocalDate lDepartureDay = LocalDate.parse( aDepartureDay, lFormatter );
			if( LocalDate.now().isAfter( lDepartureDay ) )
			{
				if( aReturnDay.length() != 0 )
				{
					LocalDate lReturnDay = LocalDate.parse( aReturnDay, lFormatter );
					if( !LocalDate.now().isAfter( lReturnDay ) )
						return DateValidity.ONLY_THE_RETURN_DATE_VALID;
				}
				return DateValidity.INVALID_COMBINATION;
			}

			if( aReturnDay.length() == 0 )
				return DateValidity.BOTH_OF_THEM_VALID;

			LocalDate lReturnDay = LocalDate.parse( aReturnDay, lFormatter );
			if( lReturnDay.isBefore( lDepartureDay ) )
				return DateValidity.INVALID_COMBINATION;
			return DateValidity.BOTH_OF_THEM_VALID;
		}
		catch( Exception e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
		return DateValidity.INVALID_COMBINATION;
	}

	public String getThreadName()
	{
		return mThread.getName();
	}

	public Object popSearchQueue()
	{
		return mSearchQueue.pop();
	}

	public void WaitForFinish()
	{
		mLogger.trace( "begin, thread name: " + getThreadName());
		try
		{
			mThread.join();
		}
		catch( InterruptedException e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ));
		}
		mLogger.trace( "end, thread name: " + getThreadName());
	}
}
