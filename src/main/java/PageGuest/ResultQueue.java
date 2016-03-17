package PageGuest;

import java.util.ArrayList;

/**
 * Created by andras.igneczi on 17/03/2016.
 */
public class ResultQueue
{
    private Object mMutex  = null;
    ArrayList<TravelDatas_RESULT> mResultList = null;
    static ResultQueue mInstance = null;

    private ResultQueue()
    {
        mMutex = new Object();
        mResultList = new ArrayList<TravelDatas_RESULT>();
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

    public void push( TravelDatas_RESULT aResult )
    {
        synchronized( mMutex )
        {
            mResultList.add( aResult );
        }
    }

    public TravelDatas_RESULT pop()
    {
        synchronized( mMutex )
        {
            if( mResultList.size() == 0 )
                return null;
            return mResultList.remove ( 0 );
        }
    }
}
