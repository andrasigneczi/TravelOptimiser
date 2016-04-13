package www;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * Created by Andras on 08/04/2016.
 */
@SpringBootApplication
public class Application
{
	public static void main(String[] args) {
		Util.Configuration lConfiguration = Util.Configuration.getInstance();
		/*ApplicationContext ctx = */SpringApplication.run(Application.class, args);
	}
}
