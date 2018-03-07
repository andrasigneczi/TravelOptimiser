#include "testBarcelona.h"
#include "Backtrack.h"
#include "Timetable.h"

static Context* createContext() {
	Context* context = new Context;
	char dateBuff[100];
	std::vector<std::string> departure;

	CtNode* nodeIgel = context->createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context->createNode("Luxembourg", "+0200"); // JFK
	CtNode* nodeLUX = context->createNode("LUX", "+0200"); // airport
	CtNode* nodeCRL = context->createNode("CRL", "+0200");
	//CtNode* nodeSOF = context->createNode("SOF", "+0300");
	CtNode* nodeBCN = context->createNode("BCN", "+0200"); // El Prat
	CtNode* nodeGRO = context->createNode("GRO", "+0200"); // Girona
	CtNode* nodeREU = context->createNode("REU", "+0200"); // Reus
	CtNode* nodeBRU = context->createNode("BRU", "+0200"); // Zaventem
	CtNode* nodeHHN = context->createNode("HHN", "+0200");
	CtNode* nodeFRA = context->createNode("FRA", "+0200");
	CtNode* nodeCGN = context->createNode("CGN", "+0200");
	CtNode* nodeBarcelona = context->createNode("Barcelona", "+0200");
	Rule timetableValidFromTo( "2018-03-01", "2018-03-31" );

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY CAR FROM IGEL ********************/
	/***************************************************************************************/
	/***************************************************************************************/
	// 26 minutes, 34 km
	//context->addConnection(Connection::createCar(nodeIgel, nodeLuxembourg, 26. / 60., 34));
	context->addConnection(Connection::createCar(nodeIgel, nodeLuxembourg, 26_min, 34));
	context->addConnection(Connection::createCar(nodeLuxembourg, nodeIgel, 26_min, 34));

	// 3 hours, 215 km
	context->addConnection(Connection::createCar(nodeLuxembourg, nodeCRL, 3_hour, 215));
	context->addConnection(Connection::createCar(nodeCRL, nodeLuxembourg, 3_hour, 215));

	context->addConnection(Connection::createCar(nodeIgel, nodeHHN, 1_hour + 2_min, 77));
	context->addConnection(Connection::createCar(nodeHHN, nodeIgel, 1_hour + 2_min, 77));

	context->addConnection(Connection::createCar(nodeIgel, nodeFRA, 2_hour + 10_min, 90));
	context->addConnection(Connection::createCar(nodeFRA, nodeIgel, 2_hour + 10_min, 90));

	context->addConnection(Connection::createCar(nodeLuxembourg, nodeBRU, 3_hour + 30_min, 228));
	context->addConnection(Connection::createCar(nodeBRU, nodeLuxembourg, 3_hour + 30_min, 228));

	context->addConnection(Connection::createCar(nodeIgel, nodeCGN, 2_hour, 191));
	context->addConnection(Connection::createCar(nodeCGN, nodeIgel, 2_hour, 90));



	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** 118 BUS FROM IGEL TO LUXEMBOURG *************************/
	/***************************************************************************************/
	/***************************************************************************************/

	// 5.04 6.04 6.34 6.44 6.49 6.54 6.59 7.04
	// 7.09 7.19 7.29 7.49 7.49 8.19
	// 8.19 8.49 9.49 10.49 11.49 12.49 13.49 14.49 15.49
	// 16.49 17.49 18.49
	Timetable timetable_Igel_JFK_BUS;
	departure = { "A 05:04", "A 06:04", "A 06:34", "A 06:44", "A 06:49", "A 06:54", "A 06:59", "A 07:04", "A 07:09", 
	              "A 07:19", "A 07:29", "A 07:49", "A 07:49", "A 08:19", "A 08:19", "A 08:49", "A 09:49", "A 10:49",
	              "A 11:49", "A 12:49", "A 13:49", "A 14:49", "A 15:49", "A 16:49", "A 17:49", "A 18:49" };

	timetable_Igel_JFK_BUS.add(timetableValidFromTo);
	timetable_Igel_JFK_BUS.add( Rule( 'A', Rule::Monday, Rule::Saturday ));
	timetable_Igel_JFK_BUS.add( departure );
	timetable_Igel_JFK_BUS.setFixPrice( 5. );
	timetable_Igel_JFK_BUS.setDefaultTravelingTime( 30_min );
	
	context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** 118 BUS FROM LUXEMBOURG JFK TO IGEL *********************/
	/***************************************************************************************/
	/***************************************************************************************/
	// 8.21 9.21 10.21 11.21 12.21 13.21 14.21 15.21 16.21
	// 16.36 16.51 17.06 17.21 17.31 17.41 17.51 17.56 18.01
	// 18.11 18.21 18.36 18.51 19.21 19.51 20.21 21.21 22.21

	departure = { "A 08:21", "A 09:21", "A 10:21", "A 11:21", "A 12:21", "A 13:21", "A 14:21", "A 15:21", "A 16:21", "A 16:36", "A 16:51", "A 17:06", "A 17:21",
		"A 17:31", "A 17:41", "A 17:51", "A 17:56", "A 18:01", "A 18:11", "A 18:21", "A 18:36", "A 18:51", "A 19:21", "A 19:51", "A 20:21", "A 21:21", "A 22:21" };
	Timetable timetable_JFK_Igel_BUS;

	timetable_JFK_Igel_BUS.add(timetableValidFromTo);
	timetable_JFK_Igel_BUS.add( Rule( 'A', Rule::Monday, Rule::Saturday ));
	timetable_JFK_Igel_BUS.add( departure );
	timetable_JFK_Igel_BUS.setFixPrice( 5. );
	timetable_JFK_Igel_BUS.setDefaultTravelingTime( 30_min );

	context->addConnection(Connection::createBus(nodeLuxembourg, nodeIgel, timetable_JFK_Igel_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** 16 BUS FROM JFK TO LUX AIRPORT **************************/
	/***************************************************************************************/
	/***************************************************************************************/
	/*
	Monday: Friday : 5:30 - 23:00, every 10 minutes
	Saturday: 5:25 - 23:05, every 20 minutes
	Sunday: 5:59 - 22:59, every 30 minutes
	*/
	Timetable timetable_JFK_LUX_BUS;
	timetable_JFK_LUX_BUS.add(timetableValidFromTo);
	timetable_JFK_LUX_BUS.add( Rule( Rule::Monday, Rule::Friday, "5:30", "23:00", 10_min ));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Saturday, "5:25", "23:05", 20_min ));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Sunday, "5:59", "22:59", 30_min ));
	timetable_JFK_LUX_BUS.setFixPrice( 5. );
	timetable_JFK_LUX_BUS.setDefaultTravelingTime( 30_min );
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM LUXEMBOURG TO CRL *******/
	/***************************************************************************************/
	/***************************************************************************************/
	Timetable timetable_LUX_CRL_BUS;
	std::vector<std::string> start{ "A 01:25", "A 04:30", "A 06:20", "A 09:40", "A 11:15", "A 13:15", "A 15:30", "A 17:10", "A 19:15", "A 21:15", "A 23:40" };
	std::vector<Duration> durations{185_min, 210_min, 210_min};

	timetable_LUX_CRL_BUS.add(timetableValidFromTo);
	timetable_LUX_CRL_BUS.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_LUX_CRL_BUS.add( start );
	timetable_LUX_CRL_BUS.add( durations );
	timetable_LUX_CRL_BUS.setFixPrice( 5. );
	timetable_LUX_CRL_BUS.setDefaultTravelingTime( 3_hour + 5_min );
	context->addConnection(Connection::createBus(nodeLUX, nodeCRL, timetable_LUX_CRL_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM CRL TO LUXEMBOURG *******/
	/***************************************************************************************/
	/***************************************************************************************/
	Timetable timetable_CRL_LUX_BUS;
	start = std::vector<std::string>{ "A 01:30", "A 03:45", "A 05:25", "A 06:55", "A 09:10", "A 11:50", "A 14:05", "A 15:40", "A 17:35", "A 20:20", "A 23:30" };
	durations = {185_min, 185_min, 185_min, 200_min, 185_min, 185_min, 185_min, 200_min};

	timetable_CRL_LUX_BUS.add(timetableValidFromTo);
	timetable_CRL_LUX_BUS.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_CRL_LUX_BUS.add( start );
	timetable_CRL_LUX_BUS.add( durations );
	timetable_CRL_LUX_BUS.setFixPrice( 5. );
	timetable_CRL_LUX_BUS.setDefaultTravelingTime( 3_hour + 5_min );
	context->addConnection(Connection::createBus(nodeCRL, nodeLUX, timetable_CRL_LUX_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM IGEL TO HHN *************/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM HHN TO IGEL *******/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM IGEL TO FRANKFURT *******/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM FRANKFURT TO IGEL *******/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM IGEL TO COLOGNE *********/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM COLOGNE TO IGEL *********/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM LUXEMBOURG TO BRUSSELS **/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM BRUSSELS TO LUXEMBOURG **/
	/***************************************************************************************/
	/***************************************************************************************/

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS IN BARCELONA ************************/
	/***************************************************************************************/
	/***************************************************************************************/
	// DUMMY
	Timetable timetable_BCN_Barcelona;
	start = { "A 01:30", "A 03:45", "A 05:25", "A 06:55", "A 09:10", "A 11:50", "A 14:05", "A 15:40", "A 17:35", "A 20:20", "A 23:30" };
	durations = {185_min, 185_min, 185_min, 200_min, 185_min, 185_min, 185_min, 200_min};

	timetable_BCN_Barcelona.add(timetableValidFromTo);
	timetable_BCN_Barcelona.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_BCN_Barcelona.add( start );
	timetable_BCN_Barcelona.add( durations );
	timetable_BCN_Barcelona.setFixPrice( 5. );
	timetable_BCN_Barcelona.setDefaultTravelingTime( 3_hour + 5_min );
	context->addConnection(Connection::createBus(nodeBCN, nodeBarcelona, timetable_BCN_Barcelona));

	Timetable timetable_Barcelona_BCN;
	start = std::vector<std::string>{ "A 01:30", "A 03:45", "A 05:25", "A 06:55", "A 09:10", "A 11:50", "A 14:05", "A 15:40", "A 17:35", "A 20:20", "A 23:30" };
	durations = {185_min, 185_min, 185_min, 200_min, 185_min, 185_min, 185_min, 200_min};

	timetable_Barcelona_BCN.add(timetableValidFromTo);
	timetable_Barcelona_BCN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_Barcelona_BCN.add( start );
	timetable_Barcelona_BCN.add( durations );
	timetable_Barcelona_BCN.setFixPrice( 5. );
	timetable_Barcelona_BCN.setDefaultTravelingTime( 3_hour + 5_min );
	context->addConnection(Connection::createBus(nodeBarcelona, nodeBCN, timetable_Barcelona_BCN));



	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** FLIGHT TICKETS TO BARCELONA *****************************/
	/***************************************************************************************/
	/***************************************************************************************/

	/*
	BUD-BCN with wizzair
	BCN-FRA; BCN-CGN ryanair
	BCN-BRU, BCN-CRL ryanair
	GRO-CRL; GRO-HHN; GRO-FRA; ryanair
	REU-CRL; REU-HHN ryanair
	*/
	
	// FRA-BCN; ryanair
	// datetime, price, travelling time in hours
	Timetable timetable_FRA_BCN;
	// These prices won't be overwritten by the rules below
	timetable_FRA_BCN.add("2018-03-01 17:40", 24.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-02 17:40", 24.99, 2_hour + 20_min);

	start = std::vector<std::string>{ "A 17:40" };
	timetable_FRA_BCN.add(timetableValidFromTo);
	timetable_FRA_BCN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_FRA_BCN.add( start );
	timetable_FRA_BCN.setFixPrice( 45.99 );
	timetable_FRA_BCN.setDefaultTravelingTime( 2_hour + 20_min );
	context->addConnection(Connection::createAirplane(nodeFRA, nodeBCN, timetable_FRA_BCN));

	//BCN-FRA; ryanair
	// datetime, price, travelling time in hours
	Timetable timetable_BCN_FRA;

	start = std::vector<std::string>{ "A 20:35" };
	timetable_BCN_FRA.add(Rule("2018-03-01", "2018-03-24"));
	timetable_BCN_FRA.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_BCN_FRA.add( start );
	timetable_BCN_FRA.setFixPrice( 45.99 );
	timetable_BCN_FRA.setDefaultTravelingTime( 2_hour + 20_min );
	context->addConnection(Connection::createAirplane(nodeBCN, nodeFRA, timetable_BCN_FRA));

	// CGN - BCN, ryanair
	Timetable timetable_CGN_BCN;

	timetable_CGN_BCN.add("2018-03-01 21:25", 24.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-02 21:25", 24.99, 2_hour + 25_min);

	start = std::vector<std::string>{ "A 21:25" };
	timetable_CGN_BCN.add(Rule("2018-03-01", "2018-03-24"));
	timetable_CGN_BCN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_CGN_BCN.add( start );
	timetable_CGN_BCN.setFixPrice( 45.99 );
	timetable_CGN_BCN.setDefaultTravelingTime( 2_hour + 25_min );
	context->addConnection(Connection::createAirplane(nodeCGN, nodeBCN, timetable_CGN_BCN));

	// BCN - CGN, ryanair
	Timetable timetable_BCN_CGN;
	timetable_BCN_CGN.add("2018-03-01 18:10", 35.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-02 18:10", 35.99, 2_hour + 40_min);
	start = std::vector<std::string>{ "A 18:10" };
	timetable_BCN_CGN.add(Rule("2018-03-01", "2018-03-24"));
	timetable_BCN_CGN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_BCN_CGN.add( start );
	timetable_BCN_CGN.setFixPrice( 45.99 );
	timetable_BCN_CGN.setDefaultTravelingTime( 2_hour + 40_min );
	context->addConnection(Connection::createAirplane(nodeBCN, nodeCGN, timetable_BCN_CGN));


	// CRL - BCN ryanair
	Timetable timetable_CRL_BCN;
	timetable_CRL_BCN.add("2018-03-01 14:40", 69.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-02 14:40", 69.99, 2_hour + 5_min);
	start = std::vector<std::string>{ "A 14:40" };
	timetable_BCN_CGN.add(Rule("2018-03-01", "2018-03-24"));
	timetable_BCN_CGN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_BCN_CGN.add( start );
	timetable_BCN_CGN.setFixPrice( 45.99 );
	timetable_BCN_CGN.setDefaultTravelingTime( 2_hour + 5_min );
	context->addConnection(Connection::createAirplane(nodeCRL, nodeBCN, timetable_CRL_BCN));


	// BCN - CRL ryanair
	Timetable timetable_BCN_CRL;
	timetable_BCN_CRL.add("2018-03-01 12:00", 69.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-02 12:00", 69.99, 2_hour + 15_min);
	start = std::vector<std::string>{ "A 12:00" };
	timetable_BCN_CGN.add(Rule("2018-03-01", "2018-03-24"));
	timetable_BCN_CGN.add( Rule( 'A', Rule::Sunday, Rule::Saturday ));
	timetable_BCN_CGN.add( start );
	timetable_BCN_CGN.setFixPrice( 45.99 );
	timetable_BCN_CGN.setDefaultTravelingTime( 2_hour + 15_min );
	context->addConnection(Connection::createAirplane(nodeBCN, nodeCRL, timetable_BCN_CRL));


	// BRU - BCN ryanair
	Timetable timetable_BRU_BCN;
	timetable_BRU_BCN.add("2018-03-01 08:55", 69.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-01 13:40", 69.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-01 17:40", 69.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-02 08:55", 49.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-02 11:00", 49.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-02 17:40", 49.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-03 08:55", 71.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-03 11:00", 86.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-04 13:55", 103.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-04 17:40", 103.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-05 08:55", 59.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-05 11:00", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-05 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-06 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-06 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-06 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-07 08:55", 59.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-07 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-07 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-08 08:55", 59.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-08 13:40", 71.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-08 17:40", 49.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-09 08:55", 71.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-09 11:00", 49.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-09 17:40", 71.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-10 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-10 11:00", 49.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-11 13:55", 81.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-11 17:40", 86.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-12 08:55", 49.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-12 11:00", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-12 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-13 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-13 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-13 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-14 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-14 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-14 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-15 08:55", 49.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-15 13:40", 49.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-15 17:40", 71.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-16 08:55", 71.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-16 11:00", 59.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-16 17:40", 49.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-17 08:55", 71.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-17 11:00", 49.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-18 13:55", 49.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-18 17:40", 59.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-19 08:55", 59.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-19 11:00", 34.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-19 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-20 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-20 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-20 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-21 08:55", 21.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-21 13:40", 21.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-21 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-22 08:55", 49.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-22 13:40", 28.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-22 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-23 08:55", 49.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-23 11:00", 28.99, 2_hour);
	timetable_BRU_BCN.add("2018-03-23 17:40", 21.99, 2_hour);

	timetable_BRU_BCN.add("2018-03-24 08:55", 86.99, 2_hour+10_min);
	timetable_BRU_BCN.add("2018-03-24 11:00", 71.99, 2_hour);
	context->addConnection(Connection::createAirplane(nodeBRU, nodeBCN, timetable_BRU_BCN));

	// BCN - BRU ryanair
	Timetable timetable_BCN_BRU;
	timetable_BCN_BRU.add("2018-03-01 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-01 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-01 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-02 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-02 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-02 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-03 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-03 13:35", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-04 16:30", 59.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-04 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-05 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-05 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-05 20:15", 71.99, 2_hour + 15_min);


	timetable_BCN_BRU.add("2018-03-06 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-06 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-06 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-07 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-07 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-07 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-08 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-08 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-08 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-09 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-09 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-09 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-10 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-10 13:35", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-11 16:30", 59.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-11 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-12 06:20", 71.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-12 13:35", 59.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-12 20:15", 71.99, 2_hour + 15_min);


	timetable_BCN_BRU.add("2018-03-13 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-13 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-13 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-14 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-14 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-14 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-15 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-15 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-15 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-16 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-16 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-16 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-17 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-17 13:35", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-18 16:30", 59.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-18 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-19 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-19 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-19 20:15", 71.99, 2_hour + 15_min);


	timetable_BCN_BRU.add("2018-03-20 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-20 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-20 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-21 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-21 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-21 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-22 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-22 16:15", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-22 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-23 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-23 13:35", 71.99, 2_hour + 15_min);
	timetable_BCN_BRU.add("2018-03-23 20:15", 71.99, 2_hour + 15_min);

	timetable_BCN_BRU.add("2018-03-24 06:20", 59.99, 2_hour+10_min);
	timetable_BCN_BRU.add("2018-03-24 13:35", 71.99, 2_hour + 15_min);
	context->addConnection(Connection::createAirplane(nodeBCN, nodeBRU, timetable_BCN_BRU));

	// HHN - GRO; ryanair
	Timetable timetable_HHN_GRO;
	timetable_HHN_GRO.add("2018-03-01 19:55", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-04 09:40", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-08 19:55", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-11 09:40", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-15 19:55", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-18 09:40", 86.99, 1_hour+55_min);
	timetable_HHN_GRO.add("2018-03-22 19:55", 86.99, 1_hour+55_min);
	context->addConnection(Connection::createAirplane(nodeHHN, nodeGRO, timetable_HHN_GRO));
	
	// GRO - HHN; ryanair
	Timetable timetable_GRO_HHN;
	timetable_GRO_HHN.add("2018-03-01 17:30", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-04 07:15", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-08 17:30", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-11 07:15", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-15 17:30", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-18 07:15", 71.99, 2_hour);
	timetable_GRO_HHN.add("2018-03-22 17:30", 71.99, 2_hour);
	context->addConnection(Connection::createAirplane(nodeGRO, nodeHHN, timetable_GRO_HHN));

	// LUX-BCN; ryanair
	Timetable timetable_LUX_BCN;
	timetable_LUX_BCN.add("2018-03-02 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-04 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-05 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-07 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-08 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-11 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-12 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-14 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-16 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-18 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-19 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-21 17:50", 86.99, 1_hour+55_min);
	timetable_LUX_BCN.add("2018-03-23 17:50", 86.99, 1_hour+55_min);
	context->addConnection(Connection::createAirplane(nodeLuxembourg, nodeBCN, timetable_LUX_BCN));

	// BCN-LUX; ryanair
	Timetable timetable_BCN_LUX;
	timetable_BCN_LUX.add("2018-03-02 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-04 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-05 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-07 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-08 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-11 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-12 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-14 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-16 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-18 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-19 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-21 17:50", 86.99, 1_hour+55_min);
	timetable_BCN_LUX.add("2018-03-23 17:50", 86.99, 1_hour+55_min);
	context->addConnection(Connection::createAirplane(nodeBCN, nodeLuxembourg, timetable_BCN_LUX));

	// Lufthamsa
	// Brussels Airline

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** STAYING IN BARCELONA ************************************/
	/***************************************************************************************/
	/***************************************************************************************/

	// 250 euro with accomodation
	context->addConnection(Connection::createStay(nodeBarcelona, 250)); // spent time and money in Budapest

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT PARKING *****************************************/
	/***************************************************************************************/
	/***************************************************************************************/

	// the parking must be listed even times in the result, so I have to add half prcie
	context->addConnection(Connection::createParking(nodeCRL, 16.5)); // car parking in CRL
	context->addConnection(Connection::createParking(nodeHHN, 16.5)); // car parking in HHN
	context->addConnection(Connection::createParking(nodeFRA, 16.5)); // car parking in FRA
	context->addConnection(Connection::createParking(nodeCGN, 16.5)); // car parking in CGN
	context->addConnection(Connection::createParking(nodeBRU, 16.5)); // car parking in BRU
	context->addConnection(Connection::createParking(nodeLuxembourg, 16.5)); // car parking in BRU

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** GOAL ****************************************************/
	/***************************************************************************************/
	/***************************************************************************************/

	context->setGoal({ "Igel", "Barcelona:stay", "Igel" });
	//context->setMaxSpentTime(128.);
	//context->setDisplayMatchNumberPerScenarion(3);
	context->setMaxPathLength(10);
	context->setMinStayingTime(3_day);
	context->setMaxStayingTime(4_day);
	context->setMaxWaitingTime(10_hour);
	context->setMaxTravellingTime(12_hour);
	return context;
}

void testBarcelona() {
	Backtrack backtrack;
	auto result = backtrack.seachTheBestWay(createContext());
}