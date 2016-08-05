package QueueHandlers;

import PageGuest.PageGuest;
import PageGuest.TravelData_INPUT;
import PageGuest.TravelData_RESULT;
import Util.StringHelper;
import org.apache.log4j.Logger;

import javax.jms.JMSException;
import java.io.Serializable;
import java.util.ArrayList;

/**
 * Created by andras.igneczi on 17/03/2016.
 */
public class ResultQueue
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger( ResultQueue.class);

    private Object mMutex  = null;
    private ArrayList<TravelData_RESULT> mResultList = null;
    private static ResultQueue mInstance = null;

    public enum RESULT_QUEUE_TYPE {
        ARRAY,
        JMS
    };

    private static RESULT_QUEUE_TYPE mQueueType = RESULT_QUEUE_TYPE.ARRAY;
    private static String mQueueName = "";

    private ResultQueue()
    {
        mMutex = new Object();
        mResultList = new ArrayList<TravelData_RESULT>();
    }

    public static ResultQueue getInstance()
    {
        if (mInstance != null)
        {
            return mInstance;
        }

        synchronized(ResultQueue.class)
        {
            if (mInstance != null)
            {
                return mInstance;
            }
            mInstance = new ResultQueue();
        }
        return mInstance;
    }

    public static void setQueueType( RESULT_QUEUE_TYPE aQueueType, String aQueueName )
    {
        mQueueType = aQueueType;
        mQueueName = aQueueName;
    }

    public void push( TravelData_RESULT aResult )
    {
        synchronized( mMutex )
        {
            if( mQueueType == RESULT_QUEUE_TYPE.ARRAY )
            {
                mResultList.add( aResult );
            }
            else
            {
                JMSPublisher lJMSPublisher = new JMSPublisher( mQueueName );
                try
                {
                    lJMSPublisher.Connect();
                    lJMSPublisher.Publish( aResult );
                    lJMSPublisher.Disconnect();
                }
                catch( JMSException e )
                {
                    e.printStackTrace();
                }
            }
        }
    }

    public TravelData_RESULT pop()
    {
        synchronized( mMutex )
        {
            if( mQueueType == RESULT_QUEUE_TYPE.ARRAY )
            {
                if( mResultList.size() == 0 )
                    return null;
                return mResultList.remove( 0 );
            }
            else if( mQueueType == RESULT_QUEUE_TYPE.JMS )
            {
                if( mResultList.size() > 0 )
                    return mResultList.remove( 0 );
                Transferm_Item_From_JMS_To_ResultList();
                if( mResultList.size() > 0 )
                    return mResultList.remove( 0 );
            }
            return null;
        }
    }

    private void Transferm_Item_From_JMS_To_ResultList()
    {
        JMSListener jmsListener = new JMSListener( mQueueName );
        try
        {
            jmsListener.Connect();
            Serializable obj = jmsListener.Listen();
            if( obj != null )
            {
                if( obj instanceof TravelData_RESULT )
                {
                    // when we ask the size/isempty, we will get an item because of the receive methode
                    mResultList.add( (TravelData_RESULT) obj );
                }
                else
                {
                    mLogger.warn( "Illegal message in the " + mQueueName + " message queue!" );
                }
            }
            jmsListener.Disconnect();
        }
        catch( JMSException e )
        {
            mLogger.error( StringHelper.getTraceInformation( e ) );
        }
    }

    public int isEmpty()
    {
        synchronized( mMutex )
        {
            if( mQueueType == RESULT_QUEUE_TYPE.ARRAY )
            {
                return mResultList.size();
            }
            else if( mQueueType == RESULT_QUEUE_TYPE.JMS )
            {
                if( mResultList.size() > 0 )
                    return mResultList.size();
                Transferm_Item_From_JMS_To_ResultList();
                return mResultList.size();
            }
            return 0;
        }
    }
}
