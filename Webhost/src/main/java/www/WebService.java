package www;

import Util.DataProvider;
import Util.HighChartDataResultComposer;
import Util.SQLiteDataProvider;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Andras on 08/04/2016.
 */
@RestController
public class WebService
{
	@RequestMapping( "/" )
	public String index() throws IOException
	{
		Scanner lScanner  = new Scanner(getClass().getClassLoader().getResourceAsStream("charts_template.html" ), "UTF-8" );
		String  lHtml = lScanner.useDelimiter( "\\A" ).next();
		lScanner.close();

		/* Template format
		[TITLE] 06.08.2016 - 09.08.2016 SOF - HHN
		[SUBTITLE] wizzair
		[DEVIZA] lv € Ft
		[SERIES1.NAME] 06.08.2016
		[SERIES2.NAME] 09.08.2016
		[SERIES1.DATA] [Date.UTC(1970, 9, 29), 0], ...
		[SERIES2.DATA] [Date.UTC(1970, 10, 9), 0.4], ...
		 */

		String lResult1 = SQLiteDataProvider.getInstance().GetData( "2016-07-16 %", "wizzair", "SOF", "HHN", "lv", new HighChartDataResultComposer() );
		String lResult2 = SQLiteDataProvider.getInstance().GetData( "2016-07-19 %", "wizzair", "HHN", "SOF", "lv", new HighChartDataResultComposer() );

		lHtml = lHtml.replace( "[TITLE]", "16.07.2016 - 19.07.2016 SOF - HHN" );
		lHtml = lHtml.replace( "[SUBTITLE]", "wizzair" );
		lHtml = lHtml.replace( "[DEVIZA]", "lv" );
		lHtml = lHtml.replace( "[SERIES1.NAME]", "16.07.2016" );
		lHtml = lHtml.replace( "[SERIES2.NAME]", "19.07.2016" );
		lHtml = lHtml.replace( "[SERIES1.DATA]", lResult1 );
		lHtml = lHtml.replace( "[SERIES2.DATA]", lResult2 );
		//SQLiteDataProvider.getInstance().ConnectionClose();
		return lHtml;
	}
}
