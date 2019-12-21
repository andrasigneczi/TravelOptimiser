package Util;

import org.apache.log4j.Logger;

import java.io.*;
import java.net.CookieHandler;
import java.net.CookieManager;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;
import java.util.zip.GZIPInputStream;
import java.util.regex.Matcher;

public class DCHttpClient {
	private static org.apache.log4j.Logger mLogger = Logger.getLogger( HttpRequest.class);

	// one instance, reuse
	private static HttpClient httpClient = null;
	private final String USER_AGENT      = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36";
	private final String ACCEPT_LANGUAGE = "hu,en-US;q=0.8,en;q=0.6,de-DE;q=0.4,de;q=0.2,fr;q=0.2";
	private final String ACCEPT_ENCODING = "gzip, deflate, br";
	private final String PRAGMA          = "no-cache";
	private final String CACHE_CONTROL   = "no-cache";

	private List<String> mCookies;
	private Map<Object, Object> properties = new HashMap<>();
	private int mResponseCode = 0;

	public DCHttpClient() {
		if(httpClient == null) {
			CookieHandler.setDefault(new CookieManager());
			httpClient = HttpClient.newBuilder()
					.cookieHandler(CookieHandler.getDefault())
					.followRedirects(HttpClient.Redirect.NORMAL)
					.version(HttpClient.Version.HTTP_2)
					.build();
		}
	}
	public DCHttpClient(HttpClient.Version v) {

		if(httpClient == null) {
			CookieHandler.setDefault(new CookieManager());
			httpClient = HttpClient.newBuilder()
					.cookieHandler(CookieHandler.getDefault())
					.followRedirects(HttpClient.Redirect.NORMAL)
					.version(v)
					.build();
		}
	}

	public void addProperties( String name, String value ) {
		properties.put(name, value);
	}

	public String sendGet(String url) throws Exception {

		HttpRequest.Builder requestBuilder = HttpRequest.newBuilder()
				.GET()
				.uri(URI.create(url))
				.setHeader("User-Agent", USER_AGENT)
				.setHeader( "Accept-Language", ACCEPT_LANGUAGE )
				.setHeader( "Accept-Encoding", ACCEPT_ENCODING )
				.setHeader( "Pragma",          PRAGMA )
				.setHeader( "Cache-Control",   CACHE_CONTROL );
				//.setHeader("Cookie", mCookies );
		for (Map.Entry<Object, Object> entry : properties.entrySet()) {
			requestBuilder.setHeader(entry.getKey().toString(), entry.getValue().toString());
		}
		addCookies(requestBuilder);
		HttpRequest request = requestBuilder.build();

		HttpResponse<byte[]> response = httpClient.send(request, HttpResponse.BodyHandlers.ofByteArray());

		// print status code
		//System.out.println(response.statusCode());
		mResponseCode = response.statusCode();
		mLogger.trace("response: " + response.toString());
		mLogger.trace("isgzipped: " + String.valueOf(isContentGzipped(response)));

		String returnValue;
		if(isContentGzipped(response)) {
			returnValue = unzipContent(response.body());
		} else {
			returnValue = response.body().toString();
		}
		saveCookies(response);
		mLogger.trace("GET RETURN VALUE: " + returnValue);
		return returnValue;
	}

	public String sendPost(String url, String parameters) throws IOException, InterruptedException {

		mLogger.trace("sendPost dbg1: " + parameters);
		HttpRequest.Builder requestBuilder = HttpRequest.newBuilder()
				.POST(HttpRequest.BodyPublishers.ofString(parameters))
				.uri(URI.create(url))
				.setHeader("User-Agent", USER_AGENT)
				.setHeader( "Accept-Language", ACCEPT_LANGUAGE )
				.setHeader( "Accept-Encoding", ACCEPT_ENCODING )
				.setHeader( "Pragma",          PRAGMA )
				.setHeader( "Cache-Control",   CACHE_CONTROL );
				//.setHeader("Cookie", mCookies );
		for (Map.Entry<Object, Object> entry : properties.entrySet()) {
			requestBuilder.setHeader(entry.getKey().toString(), entry.getValue().toString());
		}
		addCookies(requestBuilder);
		mLogger.trace("sendPost dbg2");
		HttpRequest request = requestBuilder.build();
		mLogger.trace("sendPost dbg3");

		HttpResponse<byte[]> response = httpClient.send(request, HttpResponse.BodyHandlers.ofByteArray());
		mLogger.trace("sendPost dbg4");

		// print status code
		//System.out.println(response.statusCode());
		mResponseCode = response.statusCode();
		mLogger.trace("sendPost dbg5");

		//mLogger.trace("POST RESPONSE HEADERS: " + response.headers().toString());
		//mLogger.trace("POST RESPONSE BODY length: " + response.body().length);
		//mLogger.trace("POST RESPONSE BODY: " + response.body().toString());
		writeByte(response.body());
		mLogger.trace("sendPost dbg6");

		String returnValue;
		if(isContentGzipped(response)) {
			returnValue = unzipContent(response.body());
		} else {
			returnValue = response.body().toString();
		}
		mLogger.trace("sendPost dbg7");

		saveCookies(response);
		mLogger.trace("POST RETURN VALUE: " + returnValue);
		return returnValue;
	}

	private void writeByte(byte[] bytes)
	{
		try {
			File file = new File("POST-BODY.txt");
			// Initialize a pointer
			// in file using OutputStream
			OutputStream
					os
					= new FileOutputStream(file, true);

			// Starts writing the bytes in it
			os.write(bytes);
			mLogger.trace("Successfully"
					+ " byte inserted");

			// Close the file
			os.close();
		}

		catch (Exception e) {
			mLogger.error("Exception: " + e);
		}
	}

	private boolean isContentGzipped( HttpResponse<byte[]> response )
	{
		List<String> allValues = response.headers().allValues("Content-Encoding");
		if( String.valueOf( allValues ).equals( "[gzip]" ))
			return true;
		return false;
	}

	private String unzipContent(byte[] content) throws IOException {
		ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream( content );
		GZIPInputStream gzis = new GZIPInputStream( byteArrayInputStream );
		InputStreamReader reader = new InputStreamReader( gzis );
		BufferedReader in = new BufferedReader( reader );

		String readed;
		String lReturnValue = "";
		try
		{
			while( ( readed = in.readLine() ) != null )
				lReturnValue += readed;
		}
		catch ( java.io.EOFException e )
		{
			mLogger.error( StringHelper.getTraceInformation( e ) );
		}
		return lReturnValue;
	}

	private void saveCookies( HttpResponse<byte[]> response )
	{
		mCookies = response.headers().allValues("Set-Cookie");
		mLogger.trace("COOKIES:" + String.valueOf( mCookies ));
	}

	public int getResponseCode()
	{
		return mResponseCode;
	}

	private void addCookies(HttpRequest.Builder requestBuilder) {
		if(mCookies == null) return;
		for(String pair : mCookies ) {
			Pattern reg = Pattern.compile( "(.+?)=(.+?);" );
			Matcher m = reg.matcher( pair );
			while (m.find()) {
				if(m.group(1).equals("RequestVerificationToken")) {
					requestBuilder.setHeader("X-RequestVerificationToken", m.group(2));
					mLogger.trace("New X-RequestVerificationToken:" + m.group(2));
					break;
				}
			}
		}
		for(String pair : mCookies ) {
			mLogger.trace("cookie: '" + pair + "'");
			requestBuilder.header("Cookie", pair);
		}
		mLogger.trace("addCookies end");
	}
}

