package www;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
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

		return lHtml;
	}
}
