package Util;

import PageGuest.WizzAirPageGuest201609;
import com.sun.mail.iap.ByteArray;
import com.sun.org.apache.xerces.internal.impl.io.UTF8Reader;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONTokener;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLPeerUnverifiedException;
import java.io.*;
import java.lang.*;
import java.lang.System;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.security.cert.Certificate;
import java.util.List;
import java.util.Map;
import java.util.zip.GZIPInputStream;

public class HttpRequest
{
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( HttpRequest.class);

	private final String USER_AGENT      = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36";
	private final String ACCEPT_LANGUAGE = "hu,en-US;q=0.8,en;q=0.6,de-DE;q=0.4,de;q=0.2,fr;q=0.2";
	private final String ACCEPT_ENCODING = "gzip, deflate, br";
	private final String CONTENT_TYPE    = "application/json";
	private final String ACCEPT          = "application/json, text/plain, */*";
	private final String REFERER         = "https://wizzair.com/";
	private final String AUTHORITY       = "be.wizzair.com";
	private final String ORIGIN          = "https://wizzair.com";

	private int mResponseCode = 0;

    /**
     *
     * @param aUrl
     * @param aTimeout
     * @return response string
     * @throws Exception
     */
    public String sendGet(String aUrl, int aTimeout) throws Exception {

        //String url = "http://www.google.com/search?q=mkyong";

        URL obj = new URL(aUrl);
        HttpURLConnection conn = (HttpURLConnection) obj.openConnection();
        conn.setFollowRedirects( true );
        HttpURLConnection.setFollowRedirects(true);
        if( aTimeout > 0 ) {
            conn.setConnectTimeout(aTimeout);
        }

        // optional default is GET
        conn.setRequestMethod("GET");

        //add request header
	    conn.setRequestProperty( "User-Agent",      USER_AGENT );
	    conn.setRequestProperty( "Accept-Language", ACCEPT_LANGUAGE );
	    conn.setRequestProperty( "Accept-Encoding", ACCEPT_ENCODING );
	    conn.setRequestProperty( "Accept",          ACCEPT );
	    conn.setRequestProperty( "Referer",         REFERER );
	    conn.setRequestProperty( "Authority",       AUTHORITY );
	    conn.setRequestProperty( "Origin",          ORIGIN );
	    //conn.setRequestProperty( "Content-Length",  String.valueOf(aPostData.length()));
	    conn.setRequestProperty( "Pragma",          "no-cache" );
	    conn.setRequestProperty( "Cache-Control",   "no-cache" );
	    conn.setUseCaches( false );

        mResponseCode = conn.getResponseCode();
        //System.out.println("\nSending 'GET' request to URL : " + aUrl);
        //System.out.println("Response Code : " + mResponseCode);



        boolean redirect = false;

        // normally, 3xx is redirect

        if (mResponseCode != HttpURLConnection.HTTP_OK) {
            if (mResponseCode == HttpURLConnection.HTTP_MOVED_TEMP
                    || mResponseCode == HttpURLConnection.HTTP_MOVED_PERM
                    || mResponseCode == HttpURLConnection.HTTP_SEE_OTHER)
                redirect = true;
        }

        //java.lang.System.out.println("Response Code ... " + mResponseCode);

        if (redirect) {

            // get redirect url from "location" header field
            String newUrl = conn.getHeaderField("Location");

            // get the cookie if need, for login
            String cookies = conn.getHeaderField("Set-Cookie");

            // open the new connnection again
            conn = (HttpURLConnection) new URL(newUrl).openConnection();
            conn.setRequestProperty("Cookie", cookies);
	        conn.setRequestProperty( "User-Agent",      USER_AGENT );
	        conn.setRequestProperty( "Accept-Language", ACCEPT_LANGUAGE );
	        conn.setRequestProperty( "Accept-Encoding", ACCEPT_ENCODING );
	        conn.setRequestProperty( "Accept",          ACCEPT );
	        conn.setRequestProperty( "Referer",         REFERER );
	        conn.setRequestProperty( "Authority",       AUTHORITY );
	        conn.setRequestProperty( "Origin",          ORIGIN );
	        //conn.setRequestProperty( "Content-Length",  String.valueOf(aPostData.length()));
	        conn.setRequestProperty( "Pragma",          "no-cache" );
	        conn.setRequestProperty( "Cache-Control",   "no-cache" );
	        conn.setUseCaches( false );

	        //java.lang.System.out.println("Redirect to URL : " + newUrl);

        }

	    print_all_headers( conn );
	    return readResponse( conn );
    }

    /**
     *
     * @param aUrl
     * @param aPostData
     * @return
     * @throws Exception
     */
    public String sendPost( String aUrl, String aPostData ) throws IOException
    {

        URL obj = new URL(aUrl);
	    HttpURLConnection conHttp   = (HttpURLConnection)obj.openConnection();
	    HttpsURLConnection conHttps = null;
	    if( aUrl.startsWith( "https://" ))
		    conHttps = (HttpsURLConnection)conHttp;

        //add reuqest header
        conHttp.setRequestMethod( "POST" );
        conHttp.setRequestProperty( "User-Agent",      USER_AGENT );
        conHttp.setRequestProperty( "Accept-Language", ACCEPT_LANGUAGE );
	    conHttp.setRequestProperty( "Accept-Encoding", ACCEPT_ENCODING );
	    conHttp.setRequestProperty( "Content-Type",    CONTENT_TYPE );
	    conHttp.setRequestProperty( "Accept",          ACCEPT );
	    conHttp.setRequestProperty( "Referer",         REFERER );
	    conHttp.setRequestProperty( "Authority",       AUTHORITY );
	    conHttp.setRequestProperty( "Origin",          ORIGIN );
	    conHttp.setRequestProperty( "Content-Length",  String.valueOf(aPostData.length()));
	    conHttp.setRequestProperty( "Pragma",          "no-cache" );
	    conHttp.setRequestProperty( "Cache-Control",   "no-cache" );
	    conHttp.setUseCaches( false );

        // Send post request
        conHttp.setDoOutput( true );

        DataOutputStream wr = new DataOutputStream( conHttp.getOutputStream());
        wr.writeBytes( aPostData );
        wr.flush();
        wr.close();

        mResponseCode = conHttp.getResponseCode();
	    mLogger.trace( "Sending 'POST' request to URL : " + aUrl );
	    mLogger.trace( "Post parameters : " + aPostData/*urlParameters*/ );
	    mLogger.trace( "Response Code : " + mResponseCode );

	    if( mResponseCode == 404 )
	    {
		    mLogger.warn( "Post request returned with reponsecode 404!" );
		    return "";
	    }

	    print_all_headers( conHttp );
	    print_https_cert( conHttps );

	    return readResponse( conHttp );
    }

	private String readResponse( HttpURLConnection conHttp ) throws IOException
	{
		InputStream inputStream = conHttp.getInputStream();
		int available = inputStream.available();
		byte[] response = new byte[ available ];
		int readCount = inputStream.read( response );

		if( available != readCount )
		{
			int iDebug = 10;
		}

		String lReturnValue = "";
		if( isContentGzipped( conHttp ))
		{
			ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream( response );
			GZIPInputStream gzis = new GZIPInputStream( byteArrayInputStream );
			InputStreamReader reader = new InputStreamReader( gzis );
			BufferedReader in = new BufferedReader( reader );

			String readed;
			try
			{
				while( ( readed = in.readLine() ) != null )
					lReturnValue += readed;
			}
			catch ( java.io.EOFException e )
			{
				mLogger.warn( StringHelper.getTraceInformation( e ) );
			}
		}
		else
		{
			lReturnValue = new String(response, StandardCharsets.UTF_8);
		}
		return lReturnValue;

	}

	public boolean isContentGzipped( HttpURLConnection con )
	{
		Map<String, List<String>> map = con.getHeaderFields();
		if( map.containsKey( "Content-Encoding" ) && String.valueOf( map.get( "Content-Encoding" )).equals( "[gzip]" ))
			return true;
		return false;
	}

	private void print_all_headers( HttpURLConnection con )
	{
		//get all headers
		Map<String, List<String>> map = con.getHeaderFields();
		for (Map.Entry<String, List<String>> entry : map.entrySet()) {
			mLogger.trace("Key : " + entry.getKey() +
					" ,Value : " + entry.getValue());
		}
	}

	private void print_https_cert( HttpsURLConnection con ) throws IOException
	{
		if( con != null )
		{
			try
			{
				if( con.getResponseCode() == 404 )
					return;

				mLogger.trace("Response Code : " + con.getResponseCode());
				mLogger.trace("Cipher Suite : " + con.getCipherSuite());

				Certificate[] certs = con.getServerCertificates();
				for(Certificate cert : certs)
				{
					mLogger.trace("Cert Type : " + cert.getType());
					mLogger.trace("Cert Hash Code : " + cert.hashCode());
					mLogger.trace("Cert Public Key Algorithm : "
							+ cert.getPublicKey().getAlgorithm());
					mLogger.trace("Cert Public Key Format : "
							+ cert.getPublicKey().getFormat());
					mLogger.trace("\n");
				}

			}
			catch (SSLPeerUnverifiedException e)
			{
				mLogger.error( StringHelper.getTraceInformation( e ));
			}
			catch (IOException e)
			{
				mLogger.error( StringHelper.getTraceInformation( e ));
			}
			catch( IllegalStateException e )
			{
				mLogger.error( StringHelper.getTraceInformation( e ));
			}
		}
	}

    public int getResponseCode()
    {
        return mResponseCode;
    }
}
