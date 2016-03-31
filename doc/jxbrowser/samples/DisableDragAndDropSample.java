/*
 * Copyright (c) 2000-2015 TeamDev Ltd. All rights reserved.
 * TeamDev PROPRIETARY and CONFIDENTIAL.
 * Use is subject to license terms.
 */

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.BrowserType;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.teamdev.jxbrowser.chromium.swing.internal.LightWeightWidget;

import javax.swing.*;
import java.awt.*;

/**
 * The sample demonstrates how to disable functionality that allows dragging
 * links from the loaded web page.
 */
public class DisableDragAndDropSample {
    public static void main(String[] args) {
        Browser browser = new Browser(BrowserType.LIGHTWEIGHT);
        BrowserView view = new BrowserView(browser);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.add(view, BorderLayout.CENTER);
        frame.setSize(800, 600);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        LightWeightWidget lightWeightWidget = (LightWeightWidget) view.getComponent(0);
        if (lightWeightWidget.isDragAndDropEnabled()) {
            // Now you cannot drag and drop links from the loaded web page.
            lightWeightWidget.setDragAndDropEnabled(false);
        }

        browser.loadURL("http://www.google.com");
    }
}
