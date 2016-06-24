//package Root;
//
//import java.io.BufferedReader;
//import java.io.DataOutputStream;
//import java.io.InputStreamReader;
//import java.net.HttpURLConnection;
//import java.net.URL;
//
///**
// * Created by andras.igneczi on 10/03/2016.
// */
//public class HttpRequest
//{
//    private final String USER_AGENT = "Mozilla/5.0";
//    private int mResponseCode = 0;
//
//    /**
//     *
//     * @param aUrl
//     * @param aTimeout
//     * @return response string
//     * @throws Exception
//     */
//    public String sendGet(String aUrl, int aTimeout) throws Exception {
//
//        //String url = "http://www.google.com/search?q=mkyong";
//
//        URL obj = new URL(aUrl);
//        HttpURLConnection conn = (HttpURLConnection) obj.openConnection();
//        conn.setFollowRedirects( true );
//        HttpURLConnection.setFollowRedirects(true);
//        if( aTimeout > 0 ) {
//            conn.setConnectTimeout(aTimeout);
//        }
//
//        // optional default is GET
//        conn.setRequestMethod("GET");
//
//        //add request header
//        conn.setRequestProperty("User-Agent", USER_AGENT);
//        conn.addRequestProperty("Accept-Language", "en-US,en;q=0.8");
//        //conn.addRequestProperty("User-Agent", "Mozilla");
//        conn.addRequestProperty("Referer", "google.com");
//
//        mResponseCode = conn.getResponseCode();
//        //System.out.println("\nSending 'GET' request to URL : " + aUrl);
//        //System.out.println("Response Code : " + mResponseCode);
//
//
//
//        boolean redirect = false;
//
//        // normally, 3xx is redirect
//
//        if (mResponseCode != HttpURLConnection.HTTP_OK) {
//            if (mResponseCode == HttpURLConnection.HTTP_MOVED_TEMP
//                    || mResponseCode == HttpURLConnection.HTTP_MOVED_PERM
//                    || mResponseCode == HttpURLConnection.HTTP_SEE_OTHER)
//                redirect = true;
//        }
//
//        System.out.println("Response Code ... " + mResponseCode);
//
//        if (redirect) {
//
//            // get redirect url from "location" header field
//            String newUrl = conn.getHeaderField("Location");
//
//            // get the cookie if need, for login
//            String cookies = conn.getHeaderField("Set-Cookie");
//
//            // open the new connnection again
//            conn = (HttpURLConnection) new URL(newUrl).openConnection();
//            conn.setRequestProperty("Cookie", cookies);
//            conn.addRequestProperty("Accept-Language", "en-US,en;q=0.8");
//            conn.addRequestProperty("User-Agent", "Mozilla");
//            conn.addRequestProperty("Referer", "google.com");
//
//            System.out.println("Redirect to URL : " + newUrl);
//
//        }
//
//        StringBuffer response = new StringBuffer();
//
//        try
//        {
//            BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
//            String inputLine;
//
//            while ((inputLine = in.readLine()) != null) {
//                response.append(inputLine);
//            }
//            in.close();
//        }
//        catch ( java.io.FileNotFoundException e )
//        {
//            e.printStackTrace();
//        }
//        catch (java.io.IOException e )
//        {
//            e.printStackTrace();
//        }
//
//        //print result
//        //System.out.println(response.toString());
//        return response.toString();
//    }
//
//    /**
//     *
//     * @param aUrl
//     * @param aPostData
//     * @return
//     * @throws Exception
//     */
//    public String sendPost( String aUrl, String aPostData ) throws Exception {
//
//        //String url = "https://selfsolve.apple.com/wcResults.do";
//        URL obj = new URL(aUrl);
//        //HttpsURLConnection con = (HttpsURLConnection) obj.openConnection();
//        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
//
//        //add reuqest header
//        con.setRequestMethod("POST");
//        con.setRequestProperty("User-Agent", USER_AGENT);
//        con.setRequestProperty("Accept-Language", "en-US,en;q=0.5");
//
//
//        //String urlParameters = "sn=C02G8416DRJM&cn=&locale=&caller=&num=12345";
//
//        // Send post request
//        con.setDoOutput(true);
//
//        DataOutputStream wr = new DataOutputStream(con.getOutputStream());
//        wr.writeBytes(aPostData /*urlParameters*/);
//        wr.flush();
//        wr.close();
//
//        mResponseCode = con.getResponseCode();
//        System.out.println("\nSending 'POST' request to URL : " + aUrl);
//        System.out.println("Post parameters : " + aPostData/*urlParameters*/);
//        System.out.println("Response Code : " + mResponseCode);
//
//        StringBuffer response = new StringBuffer();
//        try
//        {
//            BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
//            String inputLine;
//
//            while ((inputLine = in.readLine()) != null) {
//                response.append(inputLine);
//            }
//            in.close();
//        }
//        catch ( java.io.FileNotFoundException e )
//        {
//            // e.printStackTrace();
//        }
//        catch (java.io.IOException e )
//        {
//            // e.printStackTrace();
//        }
//
//        //print result
//        //System.out.println(response.toString());
//        return response.toString();
//    }
//
//    public int getResponseCode()
//    {
//        return mResponseCode;
//    }
//}
