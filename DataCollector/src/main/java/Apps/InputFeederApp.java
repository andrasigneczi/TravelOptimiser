package Apps;

import PageGuest.PageGuest;
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
		mLogger.trace( "InputFeeder start" );
		try
		{
			HashMap<String, JMSPublisher> lPublishers = new HashMap<>();

			ArrayList<TravelData_INPUT> lSearchList = Util.Configuration.getInstance().getSearchList();
			for( TravelData_INPUT lTDI : lSearchList )
			{
				PageGuest.DateValidity lValidity = ValidateDate(lTDI.mDepartureDay, lTDI.mReturnDay);

				if( lValidity == PageGuest.DateValidity.INVALID_COMBINATION )
				{
					mLogger.warn("DoSearch: the departure date (" + lTDI.mDepartureDay + ") and/or the return date " +
							lTDI.mReturnDay + " invalid!");
					continue;
				}

				if( lValidity == PageGuest.DateValidity.ONLY_THE_RETURN_DATE_VALID )
				{
					// we will use only the return date
					String lTemp = lTDI.mAirportCode_LeavingFrom;
					lTDI.mAirportCode_LeavingFrom = lTDI.mAirportCode_GoingTo;
					lTDI.mAirportCode_GoingTo = lTemp;
					lTDI.mDepartureDay = lTDI.mReturnDay;
					lTDI.mReturnDay = "";
					lTDI.mReturnTicket = false;
				}
				else if( lValidity == PageGuest.DateValidity.BOTH_OF_THEM_VALID )
				{
					if (lTDI.mReturnDay.length() == 0)
						lTDI.mReturnTicket = false;
					else
						lTDI.mReturnTicket = true;
				}

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
		mLogger.trace( "InputFeeder end" );
	}
}
