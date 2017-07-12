package ConfigurationTest;

import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

import static org.junit.Assert.*;

/**
 * Created by Andras on 12/07/2017.
 */
public class RecipientTest
{
	class CCC implements Cloneable {

		public Object clone() throws CloneNotSupportedException
		{
			CCC ret = (CCC)super.clone();
			ret.mHM = (HashMap<String, CCC>)mHM.clone();
			return ret;
		}

		public CCC( String name ) { mName = name; }

		public String mName;
		public HashMap<String, CCC> mHM = new HashMap<String, CCC>();
	}

	@Test
	public void cloneTest() throws Exception
	{
		CCC aHM1 = new CCC( "Name1" );
		aHM1.mHM.put( "t1", new CCC( "t2" ));

		CCC aHM2 = (CCC)aHM1.clone();

		aHM2.mName = "Name2";
		aHM2.mHM.put( "t3", new CCC( "t4" ));

		System.out.println( "aHM1:" + aHM1.mName );
		for( Map.Entry<String, CCC> entry : aHM1.mHM.entrySet()) {
			System.out.println( entry.getKey() + ";" + ((CCC)entry.getValue()).mName);
		}

		System.out.println( "aHM2:" + aHM2.mName );
		for( Map.Entry<String, CCC> entry : aHM2.mHM.entrySet()) {
			System.out.println( entry.getKey() + ";" + ((CCC)entry.getValue()).mName);
		}
	}

}