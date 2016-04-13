package www;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;

/**
 * Created by Andras on 08/04/2016.
 */
@RestController
public class WebService
{
	@RequestMapping( "/" )
	public String index() throws IOException
	{
		return "Hello World!";
	}
}
