package HelloWorld;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.BrowserMouseEvent;
import com.teamdev.jxbrowser.chromium.LoadURLParams;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.*;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent;
import com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode.*;
import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyEventType.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.Map;

import static com.teamdev.jxbrowser.chromium.BrowserKeyEvent.KeyCode.VK_H;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.PopupContainer;
import com.teamdev.jxbrowser.chromium.PopupHandler;
import com.teamdev.jxbrowser.chromium.PopupParams;
import com.teamdev.jxbrowser.chromium.events.DisposeEvent;
import com.teamdev.jxbrowser.chromium.events.DisposeListener;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * Created by Andras on 08/12/2018.
 */
public class JxBrowserPopup
{
	public static void main(String[] args) throws Exception
	{
		Browser browser = new Browser();
		final BrowserView view = new BrowserView(browser);

		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.add(view, BorderLayout.CENTER);
		frame.setSize(800, 600);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		browser.setPopupHandler(new PopupHandler() {
			public PopupContainer handlePopup(PopupParams params) {
				return new PopupContainer() {
					public void insertBrowser(final Browser browser, final Rectangle initialBounds) {
						SwingUtilities.invokeLater(new Runnable() {
							@Override
							public void run() {
								BrowserView popupView = new BrowserView(browser);
								popupView.setPreferredSize(new Rectangle(800,800).getSize());

								final JFrame popupFrame = new JFrame("Popup");
								popupFrame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
								popupFrame.add(popupView, BorderLayout.CENTER);
								popupFrame.pack();
								popupFrame.setLocation(initialBounds.getLocation());
								popupFrame.setVisible(true);
								popupFrame.addWindowListener(new WindowAdapter() {
									@Override
									public void windowClosing(WindowEvent e) {
										browser.dispose();
									}
								});

								browser.addDisposeListener(new DisposeListener<Browser>() {
									public void onDisposed(DisposeEvent<Browser> event) {
										popupFrame.setVisible(false);
									}
								});
							}
						});
					}
				};
			}
		});

		browser.loadURL("https://wizzair.com");
	}
}
