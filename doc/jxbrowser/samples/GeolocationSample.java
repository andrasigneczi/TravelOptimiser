/*
 * Copyright (c) 2000-2017 TeamDev Ltd. All rights reserved.
 * TeamDev PROPRIETARY and CONFIDENTIAL.
 * Use is subject to license terms.
 */

import com.teamdev.jxbrowser.chromium.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;

import static com.teamdev.jxbrowser.chromium.PermissionStatus.DENIED;
import static com.teamdev.jxbrowser.chromium.PermissionStatus.GRANTED;

/**
 * The sample demonstrates how to enable Geolocation API in Chromium engine.
 */
public class GeolocationSample {
    public static void main(String[] args) {
        BrowserPreferences.setChromiumVariable("GOOGLE_API_KEY", "My API Key");
        BrowserPreferences.setChromiumVariable("GOOGLE_DEFAULT_CLIENT_ID", "My Client ID");
        BrowserPreferences.setChromiumVariable("GOOGLE_DEFAULT_CLIENT_SECRET", "My Client Secret");

        Browser browser = new Browser();
        BrowserView view = new BrowserView(browser);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.add(view, BorderLayout.CENTER);
        frame.setSize(700, 500);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        browser.setPermissionHandler(new PermissionHandler() {
            @Override
            public PermissionStatus onRequestPermission(PermissionRequest request) {
                PermissionType type = request.getPermissionType();
                return type == PermissionType.GEOLOCATION ? GRANTED : DENIED;
            }
        });

        browser.loadURL("http://html5demos.com/geo");
    }
}
