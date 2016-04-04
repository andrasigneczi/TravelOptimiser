import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class XmlHelloWorld
{
	public static void Test()
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
						throws SAXException {

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

			File file = new File("test.xml");
			InputStream inputStream= new FileInputStream(file);
			Reader reader = new InputStreamReader(inputStream,"UTF-8");

			InputSource is = new InputSource(reader);
			is.setEncoding("UTF-8");

			saxParser.parse(is, handler);


		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
