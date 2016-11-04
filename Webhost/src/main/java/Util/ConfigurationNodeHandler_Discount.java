package Util;

import org.xml.sax.Attributes;

import java.util.ArrayList;

/**
 * Created by Andras on 04/11/2016.
 */
public class ConfigurationNodeHandler_Discount extends ConfigurationNodeHandler
{
	//private HashMap<String, String> mAttributes = null;
	//private ArrayList<HashMap<String, String>> mDiscountItems = new ArrayList<>(  );
	private TravelData_INPUT.Discount mDiscount = null;
	private ArrayList<TravelData_INPUT.Discount> mDiscountItems = new ArrayList<>();

	ConfigurationNodeHandler_Discount()
	{
		super( "Discount" );
	}

	@Override
	protected void startElement_( String name, Attributes attributes )
	{
		mDiscount = new TravelData_INPUT.Discount();
		for( int i = 0; i < attributes.getLength(); i++ )
		{
			mDiscount.set( attributes.getLocalName( i ), attributes.getValue( i ));
		}
		/*
            Name="20% discount"
            Airline="Wizzair"
            Beginning="2016-05-03 00:00"
            Ending="2016-05-04 00:00"
            Percentage="20"

		 */
	}

	@Override
	protected void endElement_( String name )
	{
		if( mDiscount != null )
			mDiscountItems.add( mDiscount );
		mDiscount = null;
	}

	@Override
	protected void setValue_( String name, String value )
	{

	}

	ArrayList<TravelData_INPUT.Discount> findByAirline( String airline )
	{
		ArrayList<TravelData_INPUT.Discount> returnValue = new ArrayList<>(  );
		for( TravelData_INPUT.Discount d : mDiscountItems )
		{
			if( d.mAirline.equalsIgnoreCase( airline ))
			{
				try
				{
					returnValue.add( (TravelData_INPUT.Discount) d.clone() );
				}
				catch( CloneNotSupportedException e )
				{
					e.printStackTrace();
				}
			}
		}
		return returnValue;
	}
}
