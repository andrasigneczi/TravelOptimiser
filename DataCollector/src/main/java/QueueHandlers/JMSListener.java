package QueueHandlers;

import org.apache.qpid.jms.JmsConnectionFactory;

import javax.jms.*;

import java.io.Serializable;

import static Util.System.env;

/**
 * Created by Andras on 26/07/2016.
 */
public class JMSListener
{
	private final String user     = env( "ACTIVEMQ_USER",     "admin"     );
	private final String password = env( "ACTIVEMQ_PASSWORD", "password"  );
	private final String host     = env( "ACTIVEMQ_HOST",     "localhost" );
	private final int    port     = Integer.parseInt( env( "ACTIVEMQ_PORT", "5672" ));
	private final String mTopic;

	private Connection      mConnection;
	private Session         mSession;
	private MessageConsumer mConsumer;

	public JMSListener( String aTopic )
	{
		mTopic = aTopic;
	}

	public void Connect() throws JMSException
	{
		String connectionURI = "amqp://" + host + ":" + port;

		JmsConnectionFactory factory = new JmsConnectionFactory(connectionURI);

		mConnection = factory.createConnection(user, password);
		mConnection.start();
		mSession = mConnection.createSession(false, Session.AUTO_ACKNOWLEDGE);

		Destination destination = mSession.createQueue(mTopic);

		mConsumer = mSession.createConsumer(destination);
	}

	public void Disconnect() throws JMSException
	{
		mConnection.close();
	}

	public Serializable Listen() throws JMSException
	{
		System.out.println("Waiting for messages...");

		Message msg = mConsumer.receive( 1000 );
		if (msg instanceof ObjectMessage)
		{
			return ((ObjectMessage) msg).getObject();
		}
		else
		{
			System.out.println("Unexpected message type: " + msg.getClass());
		}
		return null;
	}
}

