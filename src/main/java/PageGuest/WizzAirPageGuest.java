package PageGuest;

import com.teamdev.jxbrowser.chromium.Browser;
import com.teamdev.jxbrowser.chromium.dom.*;
import com.teamdev.jxbrowser.chromium.events.FinishLoadingEvent;
import com.teamdev.jxbrowser.chromium.events.LoadAdapter;
import com.teamdev.jxbrowser.chromium.swing.BrowserView;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Andras on 15/03/2016.
 */
public class WizzAirPageGuest implements WebPageGuest
{
	public WizzAirPageGuest()
	{

	}

	public boolean OpenStartPage()
	{
		return false;
	}

	public boolean DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
		final Browser browser = new Browser();
		BrowserView view = new BrowserView(browser);

		//final JTextField addressBar = new JTextField("http://www.teamdev.com/jxbrowser");
		//final JTextField addressBar = new JTextField("http://www.momondo.com");
		final JTextField addressBar = new JTextField("http://www.wizzair.com");
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
			public void onFinishLoadingFrame(FinishLoadingEvent event) {
				if (event.isMainFrame())
				{
					DOMDocument document = event.getBrowser().getDocument();
					//DOMElement element = document.findElement( By.xpath("//textarea"));
					//DOMTextAreaElement textArea = (DOMTextAreaElement) element;

					// source
					DOMElement elementTextSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation" ) );
					DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
					textInputSource.setValue( "Szófia (SOF)" );

					DOMElement elementIdSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation" ) );
					DOMInputElement hiddenInputSource = (DOMInputElement)elementIdSource;
					hiddenInputSource.setValue( "SOF" );

					// target
					String lTargetInputId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
					DOMElement elementTextTarget = document.findElement( By.id( lTargetInputId ) );
					DOMInputElement textInputTarget = (DOMInputElement)elementTextTarget;
					textInputTarget.setValue( "Frankfurt Hahn (HHN)" );

					DOMElement elementIdTarget = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ) );
					DOMInputElement hiddenInputTarget = (DOMInputElement)elementIdTarget;
					hiddenInputTarget.setValue( "HHN" );

					// departure date
					DOMElement elementIdDepartureDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate" ) );
					DOMInputElement inputDepartureDate = (DOMInputElement)elementIdDepartureDate;
					inputDepartureDate.setValue( "2016.07.21." );

					// arrival date
					DOMElement elementIdReturnDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate" ) );
					DOMInputElement inputReturnDate = (DOMInputElement)elementIdReturnDate;
					inputReturnDate.setValue( "2016.07.23." );

					// click the button
					DOMNode link = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ButtonSubmit" ) );
					if( link != null )
					{
						link.click();
					}
				}
			}
		});


		browser.loadURL(addressBar.getText());
		return false;
	}
}
