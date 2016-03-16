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
public class WizzAirPageGuest extends WebPageGuest
{
	public WizzAirPageGuest()
	{
		super();
	}

	public boolean OpenStartPage()
	{
		return false;
	}

	public boolean DoSearch( String aFrom, String aTo, String aDepartureDate, String aReturnDate )
	{
		new SearchStateInit().doAction( this );

		final Browser browser = new Browser();
		BrowserView view = new BrowserView(browser);

		mTravelDataInput = new TravelDatas_INPUT();
		mTravelDataInput.mAirportCode_Way_From = aFrom;
		mTravelDataInput.mAirportCode_Way_To   = aTo;
		mTravelDataInput.mWay_From_Departure_Day = aDepartureDate;
		mTravelDataInput.mWay_Back_Departure_Day = aReturnDate;
		mTravelDataInput.mReturnTicket = true;

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

		JFrame frame = new JFrame("Travel Optimizer");
		frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		frame.add(addressPane, BorderLayout.NORTH);
		frame.add(view, BorderLayout.CENTER);
		frame.setSize(1152, 864);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		browser.addLoadListener(new LoadAdapter() {
			@Override
			public void onFinishLoadingFrame(FinishLoadingEvent event) {
				// A click után újra bejövök ide, erre ügyelni kell!!!!
				if (event.isMainFrame())
				{
					DOMDocument document = event.getBrowser().getDocument();
					if( !getSearchState().toString().equals( "SearchStateInit" ))
					{
						CollectDatas( document );
						new SearchStateSearchingFinished().doAction( getSearchState().getWebPageGuest() );
						return;
					}
					new SearchStateSearching().doAction( getSearchState().getWebPageGuest() );

					FillTheForm(document);

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

	private void FillTheForm(DOMDocument document)
	{
		//DOMElement element = document.findElement( By.xpath("//textarea"));
		//DOMTextAreaElement textArea = (DOMTextAreaElement) element;

		// source
		DOMElement elementTextSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteOriginStation" ) );
		DOMInputElement textInputSource = (DOMInputElement)elementTextSource;
		String lAirportLabel = getAirportName( mTravelDataInput.mAirportCode_Way_From ) +  " (" + mTravelDataInput.mAirportCode_Way_From + ")";
		textInputSource.setValue( lAirportLabel );


		DOMElement elementIdSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation" ) );
		DOMInputElement hiddenInputSource = (DOMInputElement)elementIdSource;
		hiddenInputSource.setValue( mTravelDataInput.mAirportCode_Way_From );

		// target
		String lTargetInputId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
		DOMElement elementTextTarget = document.findElement( By.id( lTargetInputId ) );
		DOMInputElement textInputTarget = (DOMInputElement)elementTextTarget;
		lAirportLabel = getAirportName( mTravelDataInput.mAirportCode_Way_To ) +  " (" + mTravelDataInput.mAirportCode_Way_To + ")";
		textInputTarget.setValue( lAirportLabel );

		DOMElement elementIdTarget = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ) );
		DOMInputElement hiddenInputTarget = (DOMInputElement)elementIdTarget;
		hiddenInputTarget.setValue( mTravelDataInput.mAirportCode_Way_To );

		// departure date
		DOMElement elementIdDepartureDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate" ) );
		DOMInputElement inputDepartureDate = (DOMInputElement)elementIdDepartureDate;
		inputDepartureDate.setValue( mTravelDataInput.mWay_From_Departure_Day );

		// arrival date
		DOMElement elementIdReturnDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate" ) );
		DOMInputElement inputReturnDate = (DOMInputElement)elementIdReturnDate;
		inputReturnDate.setValue( mTravelDataInput.mWay_Back_Departure_Day );
	}

	private void CollectDatas(DOMDocument document)
	{

	}
}
