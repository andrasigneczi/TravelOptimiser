/*
 * Copyright (c) 2000-2015 TeamDev Ltd. All rights reserved.
 * TeamDev PROPRIETARY and CONFIDENTIAL.
 * Use is subject to license terms.
 */

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.BrowserType;
import com.teamdev.jxbrowser.chromium.Callback;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.teamdev.jxbrowser.chromium.swing.internal.LightWeightWidget;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.RenderedImage;
import java.io.File;

/**
 * The sample demonstrates how to get screen shot of the web page
 * and save it as PNG image file.
 */
public class HTMLToImageSample {
    public static void main(String[] args) throws Exception {
        // #1 Create Browser instance
        Browser browser = new Browser(BrowserType.LIGHTWEIGHT);
        BrowserView view = new BrowserView(browser);

        // #2 Set the required view size
        browser.setSize(1280, 1024);

        // Wait until Chromium resizes view
        Thread.sleep(500);

        // #3 Load web page and wait until web page is loaded completely
        Browser.invokeAndWaitFinishLoadingMainFrame(browser, new Callback<Browser>() {
            @Override
            public void invoke(Browser browser) {
                browser.loadURL("https://teamdev.com");
            }
        });

        // Wait until Chromium renders web page content
        Thread.sleep(500);

        // #4 Get java.awt.Image of the loaded web page.
        LightWeightWidget lightWeightWidget = (LightWeightWidget) view.getComponent(0);
        Image image = lightWeightWidget.getImage();
        ImageIO.write((RenderedImage) image, "PNG", new File("teamdev.com.png"));

        // Dispose Browser instance
        browser.dispose();
    }
}
