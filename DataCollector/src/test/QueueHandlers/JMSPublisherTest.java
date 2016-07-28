package QueueHandlers;

import org.junit.Test;

import javax.jms.JMSException;

import java.io.IOException;
import java.io.ObjectStreamException;
import java.io.Serializable;
import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by Andras on 27/07/2016.
 */
public class JMSPublisherTest
{
	public static class TestObject implements Serializable
	{
		private static final long serialVersionUID = 42L;
		private String mString = "Hello";
		private int    mId = 10;
		private static int mCounter = 0;

		public TestObject()
		{
			mId = mCounter++;
		}

		private void writeObject(java.io.ObjectOutputStream out)
				throws IOException
		{
			out.writeObject( mString );
			out.writeInt( mId );
		}

		private void readObject(java.io.ObjectInputStream in)
				throws IOException, ClassNotFoundException
		{
			mString = (String)in.readObject();
			mId = in.readInt();
		}

//		private void readObjectNoData()
//				throws ObjectStreamException
//		{
//
//		}

		@Override
		public String toString()
		{
			return mString + " " + mId;
		}
	}

	@Test
	public void OnePublisherMoreListenerQueue() throws JMSException, InterruptedException
	{
		final int LISTENER_COUNT = 10;
		JMSPublisher lPublisher = new JMSPublisher( "JMSTEST" );
		lPublisher.Connect();

		JMSListener[] listeners = new JMSListener[LISTENER_COUNT];
		for( int i = 0; i < LISTENER_COUNT; i++ )
		{
			listeners[ i ] = new JMSListener( "JMSTEST" );
			listeners[ i ].Connect();
		}

		for( int i = 0; i < LISTENER_COUNT; i++ )
			lPublisher.Publish( new TestObject() );
		Thread.sleep( 2000 );
		lPublisher.Disconnect();

		for( int i = 0; i < LISTENER_COUNT; i++ )
		{
			TestObject lTestObject = (TestObject)listeners[ i ].Listen();
			System.out.println( "Listener " + i + ": " + lTestObject );
		}
		Thread.sleep( 2000 );
		for( int i = 0; i < LISTENER_COUNT; i++ )
			listeners[ i ].Disconnect();
	}
}