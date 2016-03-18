package Storage;

import PageGuest.TravelData_RESULT;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

/**
 * Created by Andras on 17/03/2016.
 */
public class FileWriterAgent extends ArchiverAgent
{
	String mFileName = "database.txt";

	@Override
	protected void WriteData( TravelData_RESULT aResult )
	{
		String lMessage = "";
		try
		{
			if (!Files.exists(Paths.get(mFileName)))
				Files.write( Paths.get(mFileName), lMessage.getBytes(), StandardOpenOption.CREATE_NEW);
			else
				Files.write(Paths.get(mFileName), lMessage.getBytes(), StandardOpenOption.APPEND);
		}
		catch( IOException e )
		{
			e.printStackTrace();
		}
	}
}
