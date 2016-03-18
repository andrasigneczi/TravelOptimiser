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

		mTravelDataInput = new TravelData_INPUT();
		mTravelDataInput.mAirlines                = "wizzair";
		mTravelDataInput.mAirportCode_LeavingFrom = aFrom;
		mTravelDataInput.mAirportCode_GoingTo     = aTo;
		mTravelDataInput.mDepartureDay            = aDepartureDate;
		mTravelDataInput.mReturnDay               = aReturnDate;
		mTravelDataInput.mReturnTicket            = true;

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
		String lAirportLabel = getAirportName( mTravelDataInput.mAirportCode_LeavingFrom ) +  " (" + mTravelDataInput.mAirportCode_LeavingFrom + ")";
		textInputSource.setValue( lAirportLabel );

		// we have to fill the hidden fields as well
		DOMElement elementIdSource = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_OriginStation" ) );
		DOMInputElement hiddenInputSource = (DOMInputElement)elementIdSource;
		hiddenInputSource.setValue( mTravelDataInput.mAirportCode_LeavingFrom );

		// target
		String lTargetInputId = "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_AutocompleteDestinationStation";
		DOMElement elementTextTarget = document.findElement( By.id( lTargetInputId ) );
		DOMInputElement textInputTarget = (DOMInputElement)elementTextTarget;
		lAirportLabel = getAirportName( mTravelDataInput.mAirportCode_GoingTo ) +  " (" + mTravelDataInput.mAirportCode_GoingTo + ")";
		textInputTarget.setValue( lAirportLabel );

		// we have to fill the hidden fields as well
		DOMElement elementIdTarget = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DestinationStation" ) );
		DOMInputElement hiddenInputTarget = (DOMInputElement)elementIdTarget;
		hiddenInputTarget.setValue( mTravelDataInput.mAirportCode_GoingTo );

		// departure date
		DOMElement elementIdDepartureDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_DepartureDate" ) );
		DOMInputElement inputDepartureDate = (DOMInputElement)elementIdDepartureDate;
		inputDepartureDate.setValue( mTravelDataInput.mDepartureDay );

		// arrival date
		DOMElement elementIdReturnDate = document.findElement( By.id( "ControlGroupRibbonAnonNewHomeView_AvailabilitySearchInputRibbonAnonNewHomeView_ReturnDate" ) );
		DOMInputElement inputReturnDate = (DOMInputElement)elementIdReturnDate;
		inputReturnDate.setValue( mTravelDataInput.mReturnDay );
	}

	private void CollectDatas_ParseTheRows( DOMElement aFlightBodyElement, boolean aOutbound )
	{
		java.util.List<DOMElement> lRows = aFlightBodyElement.findElements( By.className( "flight-row" ) );
		int lRowElementIndex = 0;
		for( DOMElement lRowElement : lRows )
		{
			if( lRowElementIndex == 0 )
			{
				// header of the table
			}
			else
			{
				// rows of the table with useful datas
				TravelData_RESULT.TravelData_PossibleTrips lTrip = new TravelData_RESULT.TravelData_PossibleTrips();
				lTrip.mOutboundTrip = aOutbound;
				java.util.List<DOMNode> lCells = lRowElement.getChildren();

				int lCellIndex = 0;
				for( DOMNode lCell : lCells )
				{
					if( lCellIndex == 0 )
					{
						// TODO: separate the departure and arrival dates; language handling
						// class: flight-data flight-date
						//          <span data-flight-departure="2016-04-08T07:45:00" data-flight-arrival="2016-04-08T09:40:00">Fri, 08 Apr</span>
						lTrip.mDepartureDaytime = lCell.getTextContent();
						lTrip.mArrivalDaytime = lCell.getTextContent();
					}
					else if( lCellIndex == 1 )
					{
						// class: flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						lTrip.mPrices = lCell.getTextContent();
					}
					else if( lCellIndex == 2 )
					{
						// class: flight flight-data flight-fare-container selectFlightTooltip
						//       getChildren() getInnerText()
						//       or: price somewhere after "input-nowizzclub" and "input-wizzclub"

						// TODO: separate the prices; currency handling
						lTrip.mPrices2 = lCell.getTextContent();
					}
					lCellIndex++;
				}
				mTravelDataResult.mTrips.add( lTrip );
			}
			lRowElementIndex++;
		}
	}

	private void CollectDatas(DOMDocument document)
	{
		mTravelDataResult = new TravelData_RESULT();
		mTravelDataResult.mAirportCode_GoingTo = mTravelDataInput.mAirportCode_GoingTo;
		mTravelDataResult.mAirportCode_LeavingFrom = mTravelDataInput.mAirportCode_LeavingFrom;

		java.util.List<DOMElement> lFlightsBodyElements = document.findElements( By.className( "flights-body" ) );
		int lBodyElementIndex = 0;
		for( DOMElement lFlightBodyElement : lFlightsBodyElements )
		{
			if( lBodyElementIndex == 0 )
			{
				// Outbound trip
				CollectDatas_ParseTheRows( lFlightBodyElement, true );
			}
			else if( lBodyElementIndex == 1 )
			{
				// Return element
				CollectDatas_ParseTheRows( lFlightBodyElement, false );
			}
			lBodyElementIndex++;
		}

		ResultQueue.getInstance().push( mTravelDataResult );
	}
}
