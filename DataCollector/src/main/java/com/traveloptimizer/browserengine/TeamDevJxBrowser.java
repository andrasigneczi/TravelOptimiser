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
		BrowserContext lBrowserContext = new BrowserContext(new BrowserContextParams(".\\cache\\" + aContext ));
		return new Browser(lBrowserContext);
	}
}
