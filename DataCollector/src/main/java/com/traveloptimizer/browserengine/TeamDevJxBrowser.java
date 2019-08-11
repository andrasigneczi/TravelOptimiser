package com.traveloptimizer.browserengine;

import com.teamdev.jxbrowser.chromium.*;

/**
 * Created by Andras on 13/04/2016.
 */
public class TeamDevJxBrowser
{
	private static TeamDevJxBrowser mInstance;

	private TeamDevJxBrowser()
	{
	}

	public static void init() {
		BrowserCore.initialize();
	}

	public static TeamDevJxBrowser getInstance()
	{
		if (mInstance != null)
		{
			return mInstance;
		}

		synchronized(TeamDevJxBrowser.class)
		{
			if (mInstance != null)
			{
				return mInstance;
			}
			mInstance = new TeamDevJxBrowser();
			String[] switches = { "--lang=hu", "--remote-debugging-port=9222", "--user-data-dir=remote-profile",
			"--autoplay-policy=no-user-gesture-required"};
			BrowserPreferences.setChromiumSwitches( switches );
		}
		return mInstance;
	}

	public Browser getJxBrowser( String aContext )
	{
		// THERE WERE PROBLEMS WITH THE CACHE AND/OR COOKIES IN CASE OF WIZZAIR MULTIBROWSER, SO I WON'T USE IT FOR AWHILE
//		BrowserContext lBrowserContext =
//				new BrowserContext(new BrowserContextParams(".\\cache\\" + aContext ));
//		return new Browser(lBrowserContext);
		return new Browser( BrowserType.HEAVYWEIGHT );
	}
}
