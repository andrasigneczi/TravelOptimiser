package Util;

import org.xml.sax.Attributes;

import java.lang.reflect.Array;

/**
 * Created by Andras on 04/11/2016.
 */
public abstract class ConfigurationNodeHandler
{
	private ConfigurationNodeHandler mNext = null;
	private final String handlerName;

	ConfigurationNodeHandler( String name )
	{
		handlerName = name;
	}

	public void startElement( String name, Attributes attributes )
	{
		if( name.compareToIgnoreCase( handlerName ) == 0 )
		{
			startElement_( name, attributes );
		}
		else
		{
			if( mNext != null )
				mNext.startElement( name, attributes );
		}
	}

	public void endElement( String name )
	{
		if( name.compareToIgnoreCase( handlerName ) == 0 )
		{
			endElement_( name );
		}
		else
		{
			if( mNext != null )
				mNext.endElement( name );
		}

	}
	public void setValue( String name, String value )
	{
		if( name.compareToIgnoreCase( handlerName ) == 0 )
		{
			setValue_( name, value );
		}
		else
		{
			if( mNext != null )
				mNext.setValue( name, value );
		}

	}

	public void add( ConfigurationNodeHandler next ) {
		mNext = next;
	}

	protected abstract void startElement_( String name, Attributes attributes );
	protected abstract void endElement_( String name );
	protected abstract void setValue_( String name, String value );
}
