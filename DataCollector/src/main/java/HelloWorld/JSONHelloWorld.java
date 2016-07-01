package HelloWorld;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.ByteArrayInputStream;
import java.net.URI;
import java.net.URISyntaxException;

class JSONHelloWorld {

	static String mTestJsonString = "\n" +
			"{\"currency\":\"EUR\",\"currPrecision\":2,\"trips\":[{\"origin\":\"DUB\",\"destination\":\"FAO\",\"dates\":[{\"dateOut\":\"2017-01-04T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-04T17:25:00.000\",\"2017-01-04T20:25:00.000\"],\"timeUTC\":[\"2017-01-04T17:25:00.000Z\",\"2017-01-04T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/04/2017 17:25~FAO~01/04/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-05T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-05T06:25:00.000\",\"2017-01-05T09:25:00.000\"],\"timeUTC\":[\"2017-01-05T06:25:00.000Z\",\"2017-01-05T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/05/2017 06:25~FAO~01/05/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-06T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-06T17:25:00.000\",\"2017-01-06T20:25:00.000\"],\"timeUTC\":[\"2017-01-06T17:25:00.000Z\",\"2017-01-06T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/06/2017 17:25~FAO~01/06/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-07T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-07T06:25:00.000\",\"2017-01-07T09:25:00.000\"],\"timeUTC\":[\"2017-01-07T06:25:00.000Z\",\"2017-01-07T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/07/2017 06:25~FAO~01/07/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-08T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-08T17:25:00.000\",\"2017-01-08T20:25:00.000\"],\"timeUTC\":[\"2017-01-08T17:25:00.000Z\",\"2017-01-08T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/08/2017 17:25~FAO~01/08/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-09T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-09T17:25:00.000\",\"2017-01-09T20:25:00.000\"],\"timeUTC\":[\"2017-01-09T17:25:00.000Z\",\"2017-01-09T20:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/09/2017 17:25~FAO~01/09/2017 20:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]},{\"dateOut\":\"2017-01-10T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7032\",\"time\":[\"2017-01-10T06:25:00.000\",\"2017-01-10T09:25:00.000\"],\"timeUTC\":[\"2017-01-10T06:25:00.000Z\",\"2017-01-10T09:25:00.000Z\"],\"duration\":\"03:00\",\"faresLeft\":-1,\"flightKey\":\"FR~7032~ ~~DUB~01/10/2017 06:25~FAO~01/10/2017 09:25~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~W~~WZ14LOW~BO14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":50.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":50.9900}]},\"businessFare\":{\"fareKey\":\"0~W~~W14LBUS~BS14~~1~X\",\"fareClass\":\"W\",\"fares\":[{\"type\":\"ADT\",\"amount\":124.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":124.9900}]}}]}]},{\"origin\":\"FAO\",\"destination\":\"DUB\",\"dates\":[{\"dateOut\":\"2016-07-31T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7031\",\"time\":[\"2016-07-31T06:45:00.000\",\"2016-07-31T09:40:00.000\"],\"timeUTC\":[\"2016-07-31T05:45:00.000Z\",\"2016-07-31T08:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7031~ ~~FAO~07/31/2016 06:45~DUB~07/31/2016 09:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~K~~K14HIGH~BO14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":133.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":133.9900}]},\"businessFare\":{\"fareKey\":\"0~K~~K14HBUS~BS14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":219.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":219.9900}]}},{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-07-31T09:45:00.000\",\"2016-07-31T12:40:00.000\"],\"timeUTC\":[\"2016-07-31T08:45:00.000Z\",\"2016-07-31T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":5,\"flightKey\":\"FR~7035~ ~~FAO~07/31/2016 09:45~DUB~07/31/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~K~~K14HIGH~BO14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":133.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":133.9900}]},\"businessFare\":{\"fareKey\":\"0~K~~K14HBUS~BS14~~1~X\",\"fareClass\":\"K\",\"fares\":[{\"type\":\"ADT\",\"amount\":219.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":219.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-07-31T16:55:00.000\",\"2016-07-31T19:50:00.000\"],\"timeUTC\":[\"2016-07-31T15:55:00.000Z\",\"2016-07-31T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7033~ ~~FAO~07/31/2016 16:55~DUB~07/31/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-01T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-01T09:45:00.000\",\"2016-08-01T12:40:00.000\"],\"timeUTC\":[\"2016-08-01T08:45:00.000Z\",\"2016-08-01T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/01/2016 09:45~DUB~08/01/2016 12:40~\",\"infantsLeft\":15,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-01T16:55:00.000\",\"2016-08-01T19:50:00.000\"],\"timeUTC\":[\"2016-08-01T15:55:00.000Z\",\"2016-08-01T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":2,\"flightKey\":\"FR~7033~ ~~FAO~08/01/2016 16:55~DUB~08/01/2016 19:50~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~B~~B14HIGH~BO14~~1~X\",\"fareClass\":\"B\",\"fares\":[{\"type\":\"ADT\",\"amount\":240.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":240.9900}]},\"businessFare\":{\"fareKey\":\"0~B~~B14HBUS~BS14~~1~X\",\"fareClass\":\"B\",\"fares\":[{\"type\":\"ADT\",\"amount\":334.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":334.9900}]}}]},{\"dateOut\":\"2016-08-02T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-02T09:45:00.000\",\"2016-08-02T12:40:00.000\"],\"timeUTC\":[\"2016-08-02T08:45:00.000Z\",\"2016-08-02T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/02/2016 09:45~DUB~08/02/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-02T16:55:00.000\",\"2016-08-02T19:50:00.000\"],\"timeUTC\":[\"2016-08-02T15:55:00.000Z\",\"2016-08-02T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":4,\"flightKey\":\"FR~7033~ ~~FAO~08/02/2016 16:55~DUB~08/02/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-03T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-03T09:45:00.000\",\"2016-08-03T12:40:00.000\"],\"timeUTC\":[\"2016-08-03T08:45:00.000Z\",\"2016-08-03T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/03/2016 09:45~DUB~08/03/2016 12:40~\",\"infantsLeft\":15,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-03T16:55:00.000\",\"2016-08-03T19:50:00.000\"],\"timeUTC\":[\"2016-08-03T15:55:00.000Z\",\"2016-08-03T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7033~ ~~FAO~08/03/2016 16:55~DUB~08/03/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}}]},{\"dateOut\":\"2016-08-04T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-04T09:45:00.000\",\"2016-08-04T12:40:00.000\"],\"timeUTC\":[\"2016-08-04T08:45:00.000Z\",\"2016-08-04T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7035~ ~~FAO~08/04/2016 09:45~DUB~08/04/2016 12:40~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-04T16:55:00.000\",\"2016-08-04T19:50:00.000\"],\"timeUTC\":[\"2016-08-04T15:55:00.000Z\",\"2016-08-04T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":3,\"flightKey\":\"FR~7033~ ~~FAO~08/04/2016 16:55~DUB~08/04/2016 19:50~\",\"infantsLeft\":14,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-05T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-05T09:45:00.000\",\"2016-08-05T12:40:00.000\"],\"timeUTC\":[\"2016-08-05T08:45:00.000Z\",\"2016-08-05T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7035~ ~~FAO~08/05/2016 09:45~DUB~08/05/2016 12:40~\",\"infantsLeft\":16,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-05T16:55:00.000\",\"2016-08-05T19:50:00.000\"],\"timeUTC\":[\"2016-08-05T15:55:00.000Z\",\"2016-08-05T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":-1,\"flightKey\":\"FR~7033~ ~~FAO~08/05/2016 16:55~DUB~08/05/2016 19:50~\",\"infantsLeft\":12,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}}]},{\"dateOut\":\"2016-08-06T00:00:00.000\",\"flights\":[{\"flightNumber\":\"FR 7031\",\"time\":[\"2016-08-06T06:25:00.000\",\"2016-08-06T09:20:00.000\"],\"timeUTC\":[\"2016-08-06T05:25:00.000Z\",\"2016-08-06T08:20:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":5,\"flightKey\":\"FR~7031~ ~~FAO~08/06/2016 06:25~DUB~08/06/2016 09:20~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~E~~E14HIGH~BO14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":155.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":155.9900}]},\"businessFare\":{\"fareKey\":\"0~E~~E14HBUS~BS14~~1~X\",\"fareClass\":\"E\",\"fares\":[{\"type\":\"ADT\",\"amount\":239.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":239.9900}]}},{\"flightNumber\":\"FR 7035\",\"time\":[\"2016-08-06T09:45:00.000\",\"2016-08-06T12:40:00.000\"],\"timeUTC\":[\"2016-08-06T08:45:00.000Z\",\"2016-08-06T11:40:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":1,\"flightKey\":\"FR~7035~ ~~FAO~08/06/2016 09:45~DUB~08/06/2016 12:40~\",\"infantsLeft\":17,\"regularFare\":{\"fareKey\":\"0~L~~L14HIGH~BO14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":180.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":180.9900}]},\"businessFare\":{\"fareKey\":\"0~L~~L14HBUS~BS14~~1~X\",\"fareClass\":\"L\",\"fares\":[{\"type\":\"ADT\",\"amount\":269.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":269.9900}]}},{\"flightNumber\":\"FR 7033\",\"time\":[\"2016-08-06T16:55:00.000\",\"2016-08-06T19:50:00.000\"],\"timeUTC\":[\"2016-08-06T15:55:00.000Z\",\"2016-08-06T18:50:00.000Z\"],\"duration\":\"02:55\",\"faresLeft\":3,\"flightKey\":\"FR~7033~ ~~FAO~08/06/2016 16:55~DUB~08/06/2016 19:50~\",\"infantsLeft\":18,\"regularFare\":{\"fareKey\":\"0~F~~F14HIGH~BO14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":209.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":209.9900}]},\"businessFare\":{\"fareKey\":\"0~F~~F14HBUS~BS14~~1~X\",\"fareClass\":\"F\",\"fares\":[{\"type\":\"ADT\",\"amount\":299.9900,\"count\":1,\"hasDiscount\":false,\"publishedFare\":299.9900}]}}]}]}],\"serverTimeUTC\":\"2016-05-13T13:37:25.500Z\"}";

	public enum FareType
	{
		Normal,
		Business
	};

	private static void ParseFares( JSONObject aFares, FareType aFareType )
	{
		JSONArray lFares = aFares.getJSONArray( "fares" );
		for( int lFareIndex = 0; lFareIndex < lFares.length(); lFareIndex++ )
		{
			JSONObject lFare = lFares.getJSONObject(lFareIndex);
			double lAmount = lFare.getDouble( "amount" );
			continue;
		}
	}

	private static void ParseTrip( JSONObject aTrip )
	{
		String lOrigin = aTrip.getString( "origin" );
		String lDestination = aTrip.getString( "destination" );
		JSONArray lDates = aTrip.getJSONArray( "dates" );
		for( int lDateIndex = 0; lDateIndex < lDates.length(); lDateIndex++ )
		{
			JSONObject lDate = lDates.getJSONObject( lDateIndex );
			String lDateOut = lDate.getString( "dateOut" );
			JSONArray lFlights = lDate.getJSONArray( "flights" );
			for( int lFlightIndex = 0; lFlightIndex < lFlights.length(); lFlightIndex++ )
			{
				JSONObject lFlight = lFlights.getJSONObject( lFlightIndex );
				JSONArray lTime = lFlight.getJSONArray( "time" );
				// departure lTime.getString( 0 )
				// arrival lTime.getString( 1 )

				JSONObject lRegularFare = lFlight.getJSONObject( "regularFare" );
				JSONObject lBusinessFare = lFlight.getJSONObject( "regularFare" );

				ParseFares( lRegularFare, FareType.Normal );
				ParseFares( lBusinessFare, FareType.Business );
			}
		}
	}

	public static void main(String[] args){
		//URI uri = new URI("http://someserver/data.json");
		String lUrl = "https://desktopapps.ryanair.com/en-gb/availability?ADT=1&CHD=0&DateIn=2016-07-31&DateOut=2017-01-04&Destination=FAO&FlexDaysIn=6&FlexDaysOut=6&INF=0&Origin=DUB&RoundTrip=true&TEEN=0";
		URI uri = null;
		JSONTokener tokener = null;
//		try
		{
//			uri = new URI(lUrl);
//			if( false ) tokener = new JSONTokener(uri.toURL().openStream());
			tokener = new JSONTokener(new ByteArrayInputStream( mTestJsonString.getBytes() ));
			JSONObject root = new JSONObject( tokener );
			String lCurrency = root.getString( "currency" );
			JSONArray lTrips = root.getJSONArray( "trips" );

			for( int lTripIndex = 0; lTripIndex < lTrips.length(); lTripIndex++ )
			{
				ParseTrip( lTrips.getJSONObject( lTripIndex ) );
			}

			// Object json = new JSONTokener(response).nextValue();
		}
//		catch( URISyntaxException e )
//		{
//			e.printStackTrace();
//		}
//		catch( java.net.MalformedURLException e )
//		{
//			e.printStackTrace();
//		}
//		catch( java.io.IOException e )
//		{
//			e.printStackTrace();
//		}

	}
}