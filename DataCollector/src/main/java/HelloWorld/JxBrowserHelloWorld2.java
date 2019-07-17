package HelloWorld;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JxBrowserHelloWorld2 {

	// ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation
	// ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation
	public static void HelloWorld() throws Exception {
		final Browser browser = new Browser();
		BrowserView view = new BrowserView(browser);

		//final JTextField addressBar = new JTextField("http://www.teamdev.com/jxbrowser");
		//final JTextField addressBar = new JTextField("http://www.momondo.com");
		//final JTextField addressBar = new JTextField("http://www.google.com");
		final JTextField addressBar = new JTextField("https://www.wizzair.com");
		addressBar.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				browser.loadURL(addressBar.getText());
			}
		});

		JPanel addressPane = new JPanel(new BorderLayout());
		addressPane.add(new JLabel(" URL: "), BorderLayout.WEST);
		addressPane.add(addressBar, BorderLayout.CENTER);

		JFrame frame = new JFrame("JxBrowser - Hello World");
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.add(addressPane, BorderLayout.NORTH);
		frame.add(view, BorderLayout.CENTER);
		frame.setSize(800, 500);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		browser.addLoadListener(new LoadAdapter() {
			@Override
			public void onStartLoadingFrame(StartLoadingEvent event) {
				if (event.isMainFrame()) {
					System.out.println("Main frame has started loading");
				}
			}

			@Override
			public void onProvisionalLoadingFrame(ProvisionalLoadingEvent event) {
				if (event.isMainFrame()) {
					System.out.println("Provisional load was committed for a frame");
				}
			}

			@Override
			public void onFinishLoadingFrame(FinishLoadingEvent event) {
				if (event.isMainFrame()) {
					System.out.println("Main frame has finished loading");
				}
			}

			@Override
			public void onFailLoadingFrame(FailLoadingEvent event) {
				NetError errorCode = event.getErrorCode();
				if (event.isMainFrame()) {
					System.out.println("Main frame has failed loading: " + errorCode);
				}
			}

			@Override
			public void onDocumentLoadedInFrame(FrameLoadEvent event) {
				System.out.println("Frame document is loaded.");
			}

			@Override
			public void onDocumentLoadedInMainFrame(LoadEvent event) {
				System.out.println("Main frame document is loaded.");
			}
		});


		browser.loadURL(addressBar.getText());
	}
}
