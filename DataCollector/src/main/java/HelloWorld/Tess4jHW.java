package HelloWorld;

import java.io.File;
import net.sourceforge.tess4j.*;
import net.sourceforge.tess4j.util.LoadLibs;

/**
 * Created by Andras on 28/04/2016.
 */
public class Tess4jHW
{
	public static void main(String[] args) {
		File imageFile = new File("c:\\Users\\Andras\\IdeaProjects\\TravelOptimizer-ryanair\\test3.png");
		//ITesseract instance = new Tesseract();  // JNA Interface Mapping
		ITesseract instance = new Tesseract1(); // JNA Direct Mapping

		File tessDataFolder = LoadLibs.extractTessResources("tessdata");

		//Set the tessdata path
		instance.setDatapath(tessDataFolder.getAbsolutePath());

		try {
			String result = instance.doOCR(imageFile);
			System.out.println(result);
		} catch (TesseractException e) {
			System.err.println(e.getMessage());
		}
	}
}
