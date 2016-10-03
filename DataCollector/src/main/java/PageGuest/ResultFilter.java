package PageGuest;

/**
 * Created by Andras on 01/10/2016.
 */
public interface ResultFilter
{
	boolean testADay( String aDay, boolean aOutbound );
	void set( final String aAttributeName, final String aAttributeValue );
}
