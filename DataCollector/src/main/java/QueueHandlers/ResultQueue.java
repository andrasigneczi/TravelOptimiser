package QueueHandlers;

import PageGuest.TravelData_RESULT;
import org.apache.log4j.Logger;

/**
 * Created by andras.igneczi on 17/03/2016.
 */
public class ResultQueue
{
    private static org.apache.log4j.Logger mLogger = Logger.getLogger( ResultQueue.class);

    private StackIF<Object> mResultList = null;
    private static ResultQueue mInstance = null;

    public enum RESULT_QUEUE_TYPE {
        ARRAY,
        JMS
    };

    private static RESULT_QUEUE_TYPE mQueueType = RESULT_QUEUE_TYPE.ARRAY;
    private static String mQueueName = "__default";

    private ResultQueue( RESULT_QUEUE_TYPE aQueueType )
    {
        if( aQueueType == RESULT_QUEUE_TYPE.ARRAY )
            mResultList = new LocalStack<>();
        else if( aQueueType == RESULT_QUEUE_TYPE.JMS )
            mResultList = new JMSStack<>();
        mResultList.setQueueName( mQueueName );
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
            mInstance = new ResultQueue( mQueueType );
        }
        return mInstance;
    }

	/**
     * This function has to be called before the firt getInstance in case of JMS
     * @param aQueueType
     * @param aQueueName
     */
    public static void setQueueType( RESULT_QUEUE_TYPE aQueueType, String aQueueName )
    {
        mQueueType = aQueueType;
        mQueueName = aQueueName.toLowerCase();
    }

    public void push( Object aResult )
    {
        mResultList.push( aResult );
    }

    public Object pop()
    {
        return mResultList.pop();
    }

    public int isEmpty()
    {
        return mResultList.isEmpty();
    }
}
