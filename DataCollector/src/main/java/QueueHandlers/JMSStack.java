package QueueHandlers;

import Util.StringHelper;
import org.apache.log4j.Logger;

import javax.jms.JMSException;
import java.io.Serializable;

/**
 * Created by Andras on 05/08/2016.
 */
public class JMSStack<E> implements StackIF<E>
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( LocalStack.class);
	private Object mMutex  = new Object();
	private String mQueueName = "__default";
	private E mCache = null;

	public void setQueueType( String aQueueName )
	{
		mQueueName = aQueueName;
	}

	@Override
	public int isEmpty()
	{
		Transferm_Item_From_JMS_To_ResultList();
		if( mCache != null )
			return 1;
		return 0;
	}

	@Override
	public E pop()
	{
		E lReturn = null;
		Transferm_Item_From_JMS_To_ResultList();
		if( mCache != null )
		{
			lReturn = mCache;
			mCache = null;
		}
		return lReturn;
	}

	@Override
	public void push( E aItem )
	{
		synchronized( mMutex )
		{
			JMSPublisher lJMSPublisher = new JMSPublisher( mQueueName );
			try
			{
				lJMSPublisher.Connect();
				lJMSPublisher.Publish( (Serializable)aItem );
				lJMSPublisher.Disconnect();
			}
			catch( JMSException e )
			{
				e.printStackTrace();
			}
		}
	}

	private void Transferm_Item_From_JMS_To_ResultList()
	{
		if( mCache != null )
			return;

		JMSListener jmsListener = new JMSListener( mQueueName );
		try
		{
			jmsListener.Connect();
			Serializable obj = jmsListener.Listen();

			if( obj != null )
			{
				try
				{
					// when we ask the size/isempty, we will get an item because of the receive methode
					mCache = (E) obj;
				}
				catch( ClassCastException e)
				{
					mLogger.error( "Illegal message in the " + mQueueName + " message queue!\n" + StringHelper.getTraceInformation( e ));
				}
			}
			jmsListener.Disconnect();
		}
		catch( JMSException e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
	}
}
