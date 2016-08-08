package QueueHandlers;

/**
 * Created by Andras on 05/08/2016.
 */
public interface StackIF<E>
{
	int isEmpty();
	E pop();
	void push( E aItem );
	void setQueueName( String aQueueName );
}
