package com.traveloptimizer.browserengine;

import com.teamdev.jxbrowser.chromium.Browser;

/**
 * Created by Andras on 13/04/2016.
 */
public class TeamDevJxBrowser
{
	private static TeamDevJxBrowser mInstance;
	private Browser mJxBrowser;

	private TeamDevJxBrowser()
	{
		mJxBrowser = new Browser();
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

	public Browser getJxBrowser()
	{
		return mJxBrowser;
	}
}
