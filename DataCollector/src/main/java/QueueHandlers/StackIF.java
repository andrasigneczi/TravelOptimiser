package QueueHandlers;

/**
 * Created by Andras on 05/08/2016.
 */
interface StackIF<E>
{
	int isEmpty();
	E pop();
	void push( E aItem );
}
