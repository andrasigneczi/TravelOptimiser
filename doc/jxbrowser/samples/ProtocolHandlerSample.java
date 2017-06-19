/*
 * Copyright (c) 2000-2017 TeamDev Ltd. All rights reserved.
 * TeamDev PROPRIETARY and CONFIDENTIAL.
 * Use is subject to license terms.
 */

import com.teamdev.jxbrowser.chromium.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;

/**
 * This sample demonstrates how to register a custom protocol handler
 * to replace response data from a web server.
 */
public class ProtocolHandlerSample {
    public static void main(String[] args) {
        Browser browser = new Browser();
        BrowserView view = new BrowserView(browser);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.add(view, BorderLayout.CENTER);
        frame.setSize(700, 500);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        BrowserContext browserContext = browser.getContext();
        ProtocolService protocolService = browserContext.getProtocolService();
        protocolService.setProtocolHandler("https", new ProtocolHandler() {
            @Override
            public URLResponse onRequest(URLRequest request) {
                URLResponse response = new URLResponse();
                String html = "<html><body><p>Hello there!</p></body></html>";
                response.setData(html.getBytes());
                response.getHeaders().setHeader("Content-Type", "text/html");
                return response;
            }
        });

        browser.loadURL("https://google.com/");
    }
}
