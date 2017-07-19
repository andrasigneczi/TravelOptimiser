package Storage;

import PageGuest.AccomodationData_RESULT;
import PageGuest.TravelDataResultComposer;
import PageGuest.TravelData_RESULT;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Scanner;

/**
 * Created by Andras on 17/03/2016.
 */
public class FileWriterAgent extends ArchiverAgent
{
	private String mFileName = "database.txt";

	public FileWriterAgent()
	{

	}

	public FileWriterAgent( String aFileName )
	{
		if( aFileName != null )
			mFileName = aFileName;
	}

	@Override
	protected void WriteData( TravelData_RESULT aResult )
	{
		TravelDataResultComposer_HTML lComposer = (TravelDataResultComposer_HTML)TravelDataResultComposer.Create( aResult, "html" );
		try
		{
			String lTableBodyAndClosingTags = lComposer.toFormattedString() + lComposer.getClosingTags();
			if (!Files.exists(Paths.get(mFileName)))
			{
				String lContent = lComposer.getTableHeader() + lTableBodyAndClosingTags;
				Files.write( Paths.get( mFileName ), lContent.getBytes(), StandardOpenOption.CREATE_NEW );
			}
			else
			{
				Scanner lScanner = new Scanner( new File( mFileName ), "UTF-8" );
				String lContent = lScanner.useDelimiter( "\\A" ).next();
				lScanner.close();

				lContent = lContent.substring( 0, lContent.indexOf( "</body>")) + lTableBodyAndClosingTags;
				Files.write( Paths.get( mFileName ), lContent.getBytes(), StandardOpenOption.TRUNCATE_EXISTING );
			}
		}
		catch( IOException e )
		{
			e.printStackTrace();
		}
	}
	@Override
	protected void WriteData( AccomodationData_RESULT aResult )
	{

	}
}
