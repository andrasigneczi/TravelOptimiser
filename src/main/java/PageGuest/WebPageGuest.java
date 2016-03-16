package PageGuest;

import java.util.Hashtable;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by andras.igneczi on 15/03/2016.
 */
public abstract class WebPageGuest
{
    private Hashtable<String, String> mAirports;
	protected TravelDatas_INPUT  mTravelDataInput = null;
    protected TravelDatas_RESULT mTravelDataResult = null;
    protected SearchState mSearchState = null;

    public abstract boolean DoSearch( String aAirportCode_Way_From, String aAirportCode_Way_To,
                                      String aDepartureDate_Way_To, String aReturnDate_Way_Back );

    public WebPageGuest()
    {
        InitAirportList();
    }

    private void InitAirportList()
    {
        Scanner lScanner = new Scanner( getClass().getClassLoader().getResourceAsStream( "airports.txt" ), "UTF-8" );
        String lAirports = lScanner.useDelimiter( "\\A" ).next();
        lScanner.close();

        mAirports = new Hashtable<String, String>();
        Pattern reg = Pattern.compile( "^(.+)$", Pattern.MULTILINE );
        Matcher m = reg.matcher( lAirports );

        while( m.find() )
        {
            String lRow = m.group().toString().trim();
            if( lRow.startsWith( "#" ) )
                continue;

            String lAirporCode = lRow.substring( 0, 3 );
            String lAirporName = lRow.substring( 4 );
            mAirports.put( lAirporCode, lAirporName );
        }
    }

    public String getAirportName( String aCode )
    {
        return mAirports.get( aCode );
    }

    public void setSearchState( SearchState aSearchState )
    {
        mSearchState = aSearchState;
    }

    public SearchState getSearchState()
    {
        return mSearchState;
    }
}
