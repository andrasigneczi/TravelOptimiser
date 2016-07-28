package QueueHandlers;

import org.apache.qpid.jms.JmsConnectionFactory;

import javax.jms.*;

import java.io.Serializable;
import java.util.concurrent.atomic.AtomicInteger;

import static Util.System.env;
import static org.apache.qpid.jms.provider.amqp.AmqpSupport.TOPIC_PREFIX;

/**
 * Created by Andras on 26/07/2016.
 */
public class JMSPublisher
{
	private final String user     = env( "ACTIVEMQ_USER",     "admin"     );
	private final String password = env( "ACTIVEMQ_PASSWORD", "password"  );
	private final String host     = env( "ACTIVEMQ_HOST",     "localhost" );
	private final int    port     = Integer.parseInt( env( "ACTIVEMQ_PORT", "5672" ));
	private final String mTopic;

	private MessageProducer mProducer;
	private Connection      mConnection;
	private Session         mSession;
	private AtomicInteger   mMessageId = new AtomicInteger(Integer.MIN_VALUE);

	public JMSPublisher( String aTopic )
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

		Destination destination = null;
		destination = mSession.createQueue(mTopic);

		mProducer = mSession.createProducer(destination);
		mProducer.setDeliveryMode(DeliveryMode.NON_PERSISTENT);
	}

	public void Disconnect() throws JMSException
	{
		mConnection.close();
	}

	public void Publish( Serializable aObject ) throws JMSException
	{
		ObjectMessage msg = mSession.createObjectMessage( aObject );
		msg.setIntProperty( "id", mMessageId.getAndIncrement());
		mProducer.send(msg);
		//mProducer.send(mSession.createTextMessage("SHUTDOWN"));
	}
}
