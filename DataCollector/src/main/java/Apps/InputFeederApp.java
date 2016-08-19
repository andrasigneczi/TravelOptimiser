package Apps;

import PageGuest.TravelData_INPUT;
import QueueHandlers.JMSPublisher;
import Root.PageGuestFactory;
import Util.CurrencyHelper;
import Util.StringHelper;
import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.HashMap;

import static PageGuest.PageGuest.ValidateDate;

/**
 * Created by Andras on 02/08/2016.
 */
public class InputFeederApp
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( InputFeederApp.class);

	public static void Run()
	{
		try
		{
			HashMap<String, JMSPublisher> lPublishers = new HashMap<>();

			ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
			for( TravelData_INPUT lTDI : lSearchList )
			{
				if( !ValidateDate( lTDI.mDepartureDay, lTDI.mReturnDay ))
				{
					mLogger.warn( "DoSearch: the departure date (" + lTDI.mDepartureDay + ") or the return date " +
							lTDI.mReturnDay + " expired!" );
					continue;
				}

				if( lTDI.mReturnDay.length() == 0 )
					lTDI.mReturnTicket = false;

				if( !lPublishers.containsKey( lTDI.mAirline ))
					lPublishers.put( lTDI.mAirline, new JMSPublisher( lTDI.mAirline ));
				JMSPublisher lJMSPublisher = lPublishers.get( lTDI.mAirline );
				lJMSPublisher.Connect();
				lJMSPublisher.Publish( lTDI );
				lJMSPublisher.Disconnect();
			}
		}
		catch (Exception e)
		{
			mLogger.error( "Unhandled exception: " + StringHelper.getTraceInformation( e ));
		}
	}
}
