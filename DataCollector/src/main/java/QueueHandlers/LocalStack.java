package QueueHandlers;

import org.apache.log4j.Logger;

import java.util.Stack;

/**
 * Created by Andras on 05/08/2016.
 */
public class LocalStack<E> implements StackIF<E>
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( LocalStack.class);
	private Object mMutex  = new Object();

	Stack<E> mList = new Stack<>();

	@Override
	public int isEmpty()
	{
		synchronized( mMutex )
		{
			return mList.size();
		}
	}

	@Override
	public E pop()
	{
		synchronized( mMutex )
		{
			return mList.pop();
		}
	}

	@Override
	public void push( E aItem )
	{
		synchronized( mMutex )
		{
			mList.push( aItem );
		}
	}
}
