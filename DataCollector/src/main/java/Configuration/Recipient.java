package Configuration;

import java.util.HashMap;

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
		return super.clone();
	}

	public String get( String key )
	{
		String lowerKey = key.toLowerCase();
		if( mAttributes.containsKey( lowerKey ))
			return mAttributes.get( lowerKey );

		return null;
	}
}
