package PageGuest;

import QueueHandlers.*;
import Util.StringHelper;
import org.apache.log4j.Logger;

import javax.jms.JMSException;
import java.io.Serializable;
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
	protected      StackIF<TravelData_INPUT>   mSearchQueue;
	protected      Object                      mMutex = new Object();
	protected      Thread                      mThread;

	public enum FareType
	{
		Normal,
		Business
	};

	public PageGuest(String aAirline)
	{
		mAirline = aAirline;
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
	public abstract void stop();

	protected boolean ValidateDate( String aDepartureDay, String aReturnDay )
	{
		try
		{
			DateTimeFormatter lFormatter = DateTimeFormatter.ofPattern( "yyyy.MM.dd." );
			LocalDate lDepartureDay = LocalDate.parse( aDepartureDay, lFormatter );
			if( LocalDate.now().isAfter( lDepartureDay ) )
			{
				return false;
			}

			if( aReturnDay.length() == 0 )
				return true;

			LocalDate lReturnDay = LocalDate.parse( aReturnDay, lFormatter );
			if( lReturnDay.isBefore( lDepartureDay ) )
				return false;
			return true;
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
		return false;
	}

	public String getThreadName()
	{
		return mThread.getName();
	}
}
