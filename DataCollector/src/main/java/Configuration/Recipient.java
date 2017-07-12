package Configuration;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * Created by Andras on 26/12/2016.
 */
public class Recipient implements Cloneable
{
	private HashMap<String, String> mAttributes = new HashMap<>(  );

	public void set( String aName, String aValue )
	{
		mAttributes.put( aName.toLowerCase(), aValue );
	}

	public Object clone() throws CloneNotSupportedException
	{
		Recipient ret = (Recipient)super.clone();
		ret.mAttributes = (HashMap<String, String>)mAttributes.clone();
		return ret;
	}

	public String get( String key )
	{
		String lowerKey = key.toLowerCase();
		if( mAttributes.containsKey( lowerKey ))
			return mAttributes.get( lowerKey );

		return null;
	}

	@Override
	public String toString()
	{
		String lRetValue = "";
		Set<String> lKeySet = mAttributes.keySet();

		for( String key : lKeySet )
		{
			lRetValue += key + ": " + mAttributes.get( key ) + "\n";
		}
		return lRetValue;
	}
}
