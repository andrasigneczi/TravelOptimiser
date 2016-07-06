package com.traveloptimizer.browserengine;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.BrowserContext;
import com.teamdev.jxbrowser.chromium.BrowserContextParams;

/**
 * Created by Andras on 13/04/2016.
 */
public class TeamDevJxBrowser
{
	private static TeamDevJxBrowser mInstance;

	private TeamDevJxBrowser()
	{
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
		}
		return mInstance;
	}

	public Browser getJxBrowser( String aContext )
	{
		// THERE WERE PROBLEMS WITH THE CACHE AND/OR COOKIES IN CASE OF WIZZAIR MULTIBROWSER, SO i WON'T USE IT FOR AWHILE
//		BrowserContext lBrowserContext =
//				new BrowserContext(new BrowserContextParams(".\\cache\\" + aContext ));
//		return new Browser(lBrowserContext);
		return new Browser();
	}
}
