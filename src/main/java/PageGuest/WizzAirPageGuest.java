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
		// Odaút
		// <b class="flights-header-title"><i class="ft-icon ft-icon--outbound-flight"></i>odaút</b>
		// Indulás és érkezés

		/* fejléc */
		/*
		<div class="flight-row"><div class="flight-data flight-date">Indulás és érkezés</div><div class="flight-data fare-type fare-type--basic"><div class="fare-type-header"><h3 class="fare-type-title">Basic<span class="fare-type-info js-tooltip" data-tooltip-content="#fare-type-basic-tooltip-1"></span></h3><ul class="fare-type-ssrs"><li><i class="ft-icon ft-icon--CheckIn"></i></li><li><i class="ft-icon ft-icon--SmallCabinBag"></i></li></ul></div><div class="hide" id="fare-type-basic-tooltip-1"><p>A Basic viteldíj tartalmazza:
		</p><ul class="fare-type--basic fare-type-ssrs fare-type-ssrs--vertical"><li><i class="ft-icon ft-icon--FlightTicket"></i><span>Repülőjegy</span></li><li><i class="ft-icon ft-icon--CheckIn"></i><span>Internetes utasfelvétel</span></li><li><i class="ft-icon ft-icon--SmallCabinBag"></i><span>1 kisméretű kézipoggyász</span></li></ul></div><div class="fare-type-variants"><div class="flight-data fare-type-variant">normál ár</div><div class="flight-data fare-type-variant fare-type-variant--wdc">WIZZ Discount Club<span class="fare-type-info js-tooltip" data-tooltip-content="#wizz-club-tooltip" data-tooltip-direction="top"></span></div></div></div><div class="hide" id="fare-type-plus-tooltip-1"><p>A Plus viteldíj tartalmazza:
		</p><ul class="fare-type-ssrs fare-type-ssrs--vertical"><li><i class="ft-icon ft-icon--FlightTicket"></i><span>Repülőjegy</span></li><li><i class="ft-icon ft-icon--SeatSelection"></i><span>Ülőhelyválasztás, ide értve az első sorban lévő vagy a nagyobb lábterű ülőhelyeket is<br><span></span></span></li><li><i class="ft-icon ft-icon--WizzFlex"></i><span>WIZZ Flex a rugalmas járatmódosítások érdekében<br><span></span></span></li><li><i class="ft-icon ft-icon--AirportCheckIn"></i><span>Ingyenes&nbsp;reptéri vagy internetes utasfelvétel<br><span></span></span></li><li><i class="ft-icon ft-icon--PriorityComfort"></i><span>WIZZ Priority Boarding elsőbbségi beszállás<br><span>
			Egy darab további kisméretű személyes csomag a fedélzeten
			</span></span></li><li><i class="ft-icon ft-icon--CabinBaggage"></i><span>1 nagyméretű kézipoggyász<br><span></span></span></li><li><i class="ft-icon ft-icon--Baggage"></i><span>1 feladott poggyász max. 32 kg-ig<br><span></span></span></li></ul></div><div class="flight-data fare-type fare-type--plus"><div class="fare-type-header"><h3 class="fare-type-title">Plus<span class="fare-type-info js-tooltip" data-tooltip-content="#fare-type-plus-tooltip-1"></span></h3><ul class="fare-type-ssrs"><li><i class="ft-icon ft-icon--SeatSelection"></i></li><li><i class="ft-icon ft-icon--PriorityComfort"></i></li><li><i class="ft-icon ft-icon--WizzFlex"></i></li><li><i class="ft-icon ft-icon--AirportCheckIn"></i></li><li><i class="ft-icon ft-icon--CabinBaggage"></i></li><li><i class="ft-icon ft-icon--Baggage"></i></li></ul></div><div class="fare-type-variants"><div class="flight-data fare-type-variant">normál ár</div><div class="flight-data fare-type-variant fare-type-variant--wdc">WIZZ Discount Club<span class="fare-type-info js-tooltip" data-tooltip-content="#wizz-club-tooltip" data-tooltip-direction="top"></span></div></div></div></div>
		*/
		// <div class="flight-row"><div class="flight-data flight-date"><span data-flight-departure="2016-06-30T05:00:00" data-flight-arrival="2016-06-30T06:50:00">Cs, jún. 30.</span><br><b>6:00 → 7:50</b></div><div class="flight-data flight-fare-container selectFlightTooltip"><label for="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare2" class="flight flight-data flight-fare flight-radio flight-fare-type--basic flight-fare--active"><span class="custom-radio  input-nowizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare2" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~B~~BREG~REG1~~3~X|W6~4327~ ~~SOF~06/30/2016 06:00~CRL~06/30/2016 07:50~" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-nowizzclub "></span>99,99 lv</label><label for="" class="flight flight-data flight-fare flight-radio flight-fare--wdc flight-fare-type--basic flight-fare--passive"><span class="custom-radio  input-wizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare1" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~BW~~BWZZC~WZZC~~3~X|W6~4327~ ~~SOF~06/30/2016 06:00~CRL~06/30/2016 07:50~" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-wizzclub "></span>79,99 lv</label></div><div class="flight flight-data flight-fare-container selectFlightTooltip"><label for="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare2PLUS" class="flight flight-data flight-fare flight-radio flight-fare-type--plus flight-fare--active"><span class="custom-radio  input-nowizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare2PLUS" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~B~~BREG~REG1~~3~X|W6~4327~ ~~SOF~06/30/2016 06:00~CRL~06/30/2016 07:50~|PLUS" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-nowizzclub "></span>221,09 lv</label><label for="" class="flight flight-data flight-fare flight-radio flight-fare--wdc flight-fare-type--plus flight-fare--passive"><span class="custom-radio  input-wizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare1PLUS" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~BW~~BWZZC~WZZC~~3~X|W6~4327~ ~~SOF~06/30/2016 06:00~CRL~06/30/2016 07:50~|PLUS" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-wizzclub "></span>201,09 lv</label></div></div>
		// <div class="flight-row disabled"><div class="flight-data flight-date"><span data-flight-departure="" data-flight-arrival="">P, júl. 1.</span></div><div class="flight flight-data flight-fare-container"><div class="flight-data flight-data--block">A megadott napon nem találhatók járatok.</div></div><div class="flight flight-data flight-fare-container"><div class="flight-data flight-data--block">A megadott napon nem találhatók járatok.</div></div></div>
		// <div class="flight-row"><div class="flight-data flight-date"><span data-flight-departure="2016-07-02T05:00:00" data-flight-arrival="2016-07-02T06:50:00">Szo, júl. 2.</span><br><b>6:00 → 7:50</b></div><div class="flight-data flight-fare-container selectFlightTooltip"><label for="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare4" class="flight flight-data flight-fare flight-radio flight-fare-type--basic flight-fare--active"><span class="custom-radio  input-nowizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare4" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~B~~BREG~REG1~~3~X|W6~4327~ ~~SOF~07/02/2016 06:00~CRL~07/02/2016 07:50~" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-nowizzclub "></span>99,99 lv</label><label for="" class="flight flight-data flight-fare flight-radio flight-fare--wdc flight-fare-type--basic flight-fare--passive"><span class="custom-radio  input-wizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare3" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~BW~~BWZZC~WZZC~~3~X|W6~4327~ ~~SOF~07/02/2016 06:00~CRL~07/02/2016 07:50~" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-wizzclub "></span>79,99 lv</label></div><div class="flight flight-data flight-fare-container selectFlightTooltip"><label for="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare4PLUS" class="flight flight-data flight-fare flight-radio flight-fare-type--plus flight-fare--active"><span class="custom-radio  input-nowizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare4PLUS" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~B~~BREG~REG1~~3~X|W6~4327~ ~~SOF~07/02/2016 06:00~CRL~07/02/2016 07:50~|PLUS" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-nowizzclub "></span>221,09 lv</label><label for="" class="flight flight-data flight-fare flight-radio flight-fare--wdc flight-fare-type--plus flight-fare--passive"><span class="custom-radio  input-wizzclub "><input id="ControlGroupRibbonSelectView_AvailabilityInputRibbonSelectView_RadioButtonMkt1Fare3PLUS" type="radio" name="ControlGroupRibbonSelectView$AvailabilityInputRibbonSelectView$Market1" value="0~BW~~BWZZC~WZZC~~3~X|W6~4327~ ~~SOF~07/02/2016 06:00~CRL~07/02/2016 07:50~|PLUS" requirederror="Kérjük, válasszon viteldíjat." data-validation-required="true" data-validation-common-message="selectflight-0" class=" input-wizzclub "></span>201,09 lv</label></div></div>


		// Visszaút
		// <b class="flights-header-title"><i class="ft-icon ft-icon--inbound-flight"></i>visszaút</b>
		// Indulás és érkezés

	}
}
