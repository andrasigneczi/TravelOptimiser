package HelloWorld;

import Util.StringHelper;

import java.io.*;
import java.net.CookieHandler;
import java.net.CookieManager;
import java.net.URI;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.zip.GZIPInputStream;

public class HttpClientHelloWorld {
    // one instance, reuse
    private static HttpClient httpClient;
    private final String USER_AGENT      = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36";
    private final String ACCEPT_LANGUAGE = "hu,en-US;q=0.8,en;q=0.6,de-DE;q=0.4,de;q=0.2,fr;q=0.2";
    private final String ACCEPT_ENCODING = "gzip, deflate, br";
    private final String PRAGMA          = "no-cache";
    private final String CACHE_CONTROL   = "no-cache";

    private String mCookies = "";
    private Map<Object, Object> properties = new HashMap<>();
    private int mResponseCode = 0;

    public static void main(String[] args) throws Exception {

        CookieHandler.setDefault(new CookieManager());
        httpClient = HttpClient.newBuilder()
                .cookieHandler(CookieHandler.getDefault())
                .followRedirects(HttpClient.Redirect.NORMAL)
                .version(HttpClient.Version.HTTP_2)
                .build();
        HttpClientHelloWorld obj = new HttpClientHelloWorld();

        System.out.println("Testing 1 - Send Http GET request");
        obj.sendGet();

        System.out.println("Testing 2 - Send Http POST request");
        obj.sendPost();

    }

    public void addProperties( String name, String value ) {
        properties.put(name, value);
    }

    private void sendGet() throws Exception {

        HttpRequest.Builder requestBuilder = HttpRequest.newBuilder()
                .GET()
                .uri(URI.create("https://httpbin.org/get"))
                .setHeader("User-Agent", USER_AGENT)
                .setHeader( "Accept-Language", ACCEPT_LANGUAGE )
                .setHeader( "Accept-Encoding", ACCEPT_ENCODING )
                .setHeader( "Pragma",          PRAGMA )
                .setHeader( "Cache-Control",   CACHE_CONTROL )
                .setHeader("Cookie", mCookies );
        for (Map.Entry<Object, Object> entry : properties.entrySet()) {
            requestBuilder.setHeader(entry.getKey().toString(), entry.getValue().toString());
        }
        HttpRequest request = requestBuilder.build();

        HttpResponse<byte[]> response = httpClient.send(request, HttpResponse.BodyHandlers.ofByteArray());

        // print status code
        System.out.println(response.statusCode());
        mResponseCode = response.statusCode();

        if(isContentGzipped(response)) {
            System.out.println(unzipContent(response.body()));
        } else {
            // print response body
            System.out.println(response.body());
        }
        saveCookies(response);
    }

    private void sendPost() throws Exception {

        // form parameters
        Map<Object, Object> data = new HashMap<>();
        data.put("username", "abc");
        data.put("password", "123");
        data.put("custom", "secret");
        data.put("ts", System.currentTimeMillis());


        HttpRequest.Builder requestBuilder = HttpRequest.newBuilder()
                .POST(buildFormDataFromMap(data))
                .uri(URI.create("https://httpbin.org/post"))
                .setHeader("User-Agent", USER_AGENT)
                .setHeader( "Accept-Language", ACCEPT_LANGUAGE )
                .setHeader( "Accept-Encoding", ACCEPT_ENCODING )
                .setHeader( "Pragma",          PRAGMA )
                .setHeader( "Cache-Control",   CACHE_CONTROL )
                .setHeader("Cookie", mCookies );
        for (Map.Entry<Object, Object> entry : properties.entrySet()) {
            requestBuilder.setHeader(entry.getKey().toString(), entry.getValue().toString());
        }
        requestBuilder.header("Content-Type", "application/x-www-form-urlencoded");
        HttpRequest request = requestBuilder.build();

        HttpResponse<byte[]> response = httpClient.send(request, HttpResponse.BodyHandlers.ofByteArray());

        // print status code
        System.out.println(response.statusCode());
        mResponseCode = response.statusCode();

        if(isContentGzipped(response)) {
            System.out.println(unzipContent(response.body()));
        } else {
            // print response body
            System.out.println(response.body());
        }
        saveCookies(response);
    }

    private static HttpRequest.BodyPublisher buildFormDataFromMap(Map<Object, Object> data) {
        var builder = new StringBuilder();
        for (Map.Entry<Object, Object> entry : data.entrySet()) {
            if (builder.length() > 0) {
                builder.append("&");
            }
            builder.append(URLEncoder.encode(entry.getKey().toString(), StandardCharsets.UTF_8));
            builder.append("=");
            builder.append(URLEncoder.encode(entry.getValue().toString(), StandardCharsets.UTF_8));
        }
        System.out.println(builder.toString());
        return HttpRequest.BodyPublishers.ofString(builder.toString());
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
            System.out.println( StringHelper.getTraceInformation( e ) );
        }
        return lReturnValue;
    }

    private void saveCookies( HttpResponse<byte[]> response )
    {
        List<String> allValues = response.headers().allValues("Set-Cookie");
        mCookies = String.valueOf( allValues );
    }

    public int getResponseCode()
    {
        return mResponseCode;
    }
}
