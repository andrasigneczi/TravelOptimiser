import PageGuest.TravelData_INPUT;
import PageGuest.TravelData_RESULT;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.*;
import java.util.ArrayList;

/**
 * Created by Andras on 05/04/2016.
 */
public class Configuration
{
	private Object mMutex  = null;
	private static Configuration mInstance = null;
	private int mDelayBeforeClick = 10;
	ArrayList<TravelData_INPUT> mSearchList = null;

	private Configuration()
	{
		mMutex = new Object();
		mSearchList = new ArrayList<TravelData_INPUT>();
	}

	public static Configuration getInstance()
	{
		if (mInstance != null)
		{
			return mInstance;
		}

		synchronized(Configuration.class)
		{
			if (mInstance != null)
			{
				return mInstance;
			}
			mInstance = new Configuration();
		}
		return mInstance;
	}

	private void ParseConfigurationFile()
	{
		try {

			SAXParserFactory factory = SAXParserFactory.newInstance();
			SAXParser saxParser = factory.newSAXParser();

			DefaultHandler handler = new DefaultHandler() {

				boolean bLeavingFrom = false;
				boolean bGoingTo = false;
				boolean bDepartureDay = false;
				boolean bReturnDay = false;

				public void startElement(String uri, String localName,
				                         String qName, Attributes attributes)
						throws SAXException
				{

					/*
					attributes.getName(0)
					attributes.getValue(0)
					attributes.getLength()
					 */
					System.out.println("Start Element :" + qName);

					if (qName.equalsIgnoreCase("LeavingFrom")) {
						bLeavingFrom = true;
					}

					if (qName.equalsIgnoreCase("GoingTo")) {
						bGoingTo = true;
					}

					if (qName.equalsIgnoreCase("DepartureDay")) {
						bDepartureDay = true;
					}

					if (qName.equalsIgnoreCase("ReturnDay")) {
						bReturnDay = true;
					}
				}

				public void endElement(String uri, String localName,
				                       String qName)
						throws SAXException {

					System.out.println("End Element :" + qName);

				}

				public void characters(char ch[], int start, int length)
						throws SAXException {

					System.out.println(new String(ch, start, length));


					if (bLeavingFrom) {
						System.out.println("LeavingFrom : "
								+ new String(ch, start, length));
						bLeavingFrom = false;
					}

					if (bGoingTo) {
						System.out.println("GoingTo : "
								+ new String(ch, start, length));
						bGoingTo = false;
					}

					if (bDepartureDay) {
						System.out.println("DepartureDay : "
								+ new String(ch, start, length));
						bDepartureDay = false;
					}

					if (bReturnDay) {
						System.out.println("ReturnDay : "
								+ new String(ch, start, length));
						bReturnDay = false;
					}

				}

			};

			//File file = new File("test.xml");
			//InputStream inputStream= new FileInputStream(file);
			InputStream inputStream = getClass().getClassLoader().getResourceAsStream( "config.xml" );
			Reader reader = new InputStreamReader(inputStream,"UTF-8");

			InputSource is = new InputSource(reader);
			is.setEncoding("UTF-8");

			saxParser.parse(is, handler);


		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
