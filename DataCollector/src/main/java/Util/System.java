package Util;

/**
 * Created by Andras on 27/07/2016.
 */
public class System
{
	public static String env( String key, String defaultValue ) {
		String rc = java.lang.System.getenv(key);
		if (rc == null)
			return defaultValue;
		return rc;
	}
}
