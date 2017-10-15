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
	CtNode* nodeSOF = context->createNode("SOF", "+0300");
	CtNode* nodeBCN = context->createNode("BCN", "+0200"); // El Prat
	CtNode* nodeGRO = context->createNode("GRO", "+0200"); // Girona
	CtNode* nodeREU = context->createNode("REU", "+0200"); // Reus
	CtNode* nodeBRU = context->createNode("BRU", "+0200"); // Zaventem
	CtNode* nodeHHN = context->createNode("HHN", "+0200");
	CtNode* nodeFRA = context->createNode("FRA", "+0200");
	CtNode* nodeCGN = context->createNode("CGN", "+0200");
	CtNode* nodeBarcelona = context->createNode("Barcelona", "+0200");


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
	departure = { "05:04", "06:04", "06:34", "06:44", "06:49", "06:54", "06:59", "07:04", "07:09", "07:19", "07:29", "07:49", "07:49", "08:19",
		"08:19", "08:49", "09:49", "10:49", "11:49", "12:49", "13:49", "14:49", "15:49", "16:49", "17:49", "18:49" };
	for (int day = 1; day <= 31; ++day) {
		for (const std::string& hour : departure) {
			if ((day - 3) % 7 == 0) { // saturday
				sprintf_s(dateBuff, "2018-03-%02d %s", day, hour.c_str());
				timetable_Igel_JFK_BUS.add(dateBuff, 5., 30_min);
			}
			else if ((day - 4) % 7 == 0) { // sunday
			}
			else {
				sprintf_s(dateBuff, "2018-03-%02d %s", day, hour.c_str());
				timetable_Igel_JFK_BUS.add(dateBuff, 5., 30_min);
			}
		}
	}
	context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** 118 BUS FROM LUXEMBOURG JFK TO IGEL *********************/
	/***************************************************************************************/
	/***************************************************************************************/
	// 8.21 9.21 10.21 11.21 12.21 13.21 14.21 15.21 16.21
	// 16.36 16.51 17.06 17.21 17.31 17.41 17.51 17.56 18.01
	// 18.11 18.21 18.36 18.51 19.21 19.51 20.21 21.21 22.21

	departure = { "08:21", "09:21", "10:21", "11:21", "12:21", "13:21", "14:21", "15:21", "16:21", "16:36", "16:51", "17:06", "17:21",
		"17:31", "17:41", "17:51", "17:56", "18:01", "18:11", "18:21", "18:36", "18:51", "19:21", "19:51", "20:21", "21:21", "22:21" };
	Timetable timetable_JFK_Igel_BUS;
	for (int day = 1; day <= 31; ++day) {
		for (const std::string& hour : departure) {
			if ((day - 3) % 7 == 0) { // saturday
				sprintf_s(dateBuff, "2018-03-%02d %s", day, hour.c_str());
				timetable_JFK_Igel_BUS.add(dateBuff, 5., 30_min);
			}
			else if ((day - 4) % 7 == 0) { // sunday
			}
			else {
				sprintf_s(dateBuff, "2018-03-%02d %s", day, hour.c_str());
				timetable_JFK_Igel_BUS.add(dateBuff, 5., 30_min);
			}
		}
	}
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeIgel, timetable_JFK_Igel_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** 16 BUS FROM JFK TO LUX AIRPORT **************************/
	/***************************************************************************************/
	/***************************************************************************************/
	/*
	Monday – Friday : 5:30 – 23:00, every 10 minutes
	Saturday: 5:25 – 23:05, every 20 minutes
	Sunday: 5:59 – 22:59, every 30 minutes
	*/
	Timetable timetable_JFK_LUX_BUS;
	for (int day = 1; day <= 31; ++day) {
		for (int hour = 0; hour < 24; ++hour) {
			if ((day - 3) % 7 == 0) { // saturday
				for (int min = 0; min < 60; min += 20) {
					sprintf_s(dateBuff, "2018-03-%02d %02d:%02d", day, hour, min );
					timetable_JFK_LUX_BUS.add(dateBuff, 5., 3_hour + 30_min);
				}
			}
			else if ((day - 4) % 7 == 0) { // sunday
				for (int min = 0; min < 60; min += 30) {
					sprintf_s(dateBuff, "2018-03-%02d %02d:%02d", day, hour, min);
					timetable_JFK_LUX_BUS.add(dateBuff, 5., 3_hour + 30_min);
				}
			}
			else {
				for (int min = 0; min < 60; min += 10) {
					sprintf_s(dateBuff, "2018-03-%02d %02d:%02d", day, hour, min);
					timetable_JFK_LUX_BUS.add(dateBuff, 5., 3_hour + 30_min);
				}
			}
		}
	}
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM LUXEMBOURG TO CRL *******/
	/***************************************************************************************/
	/***************************************************************************************/
	Timetable timetable_LUX_CRL_BUS;
	std::vector<std::string> start{ "01:25", "04:30", "06:20", "09:40", "11:15", "13:15", "15:30", "17:10", "19:15", "21:15", "23:40" };
	for (int day = 1; day <= 31; ++day) {
		for (size_t t = 0; t < start.size(); ++t) {
			sprintf_s(dateBuff, "2018-03-%02d %s", day, start[t].c_str());
			if (t == 1 || t == 2)
				timetable_LUX_CRL_BUS.add(dateBuff, 5., 3_hour + 30_min);
			else
				timetable_LUX_CRL_BUS.add(dateBuff, 5., 3_hour + 5_min);
		}
	}
	// 01:25, 3_hour + 5_min);
	// 04:30, 3_hour + 30_min
	// 06:20, 3_hour + 30_min
	// 09:40, 3_hour + 5_min
	// 11:15, 3_hour + 5_min
	// 13:15, 3_hour + 5_min
	// 15:30, 3_hour + 5_min
	// 17:10, 3_hour + 5_min
	// 19:15, 3_hour + 5_min
	// 21:15, 3_hour + 5_min
	// 23:40, 3_hour + 5_min
	context->addConnection(Connection::createBus(nodeLUX, nodeCRL, timetable_LUX_CRL_BUS));

	/***************************************************************************************/
	/***************************************************************************************/
	/***************************** AIRPORT CONNECTIONS BY BUS FROM CRL TO LUXEMBOURG *******/
	/***************************************************************************************/
	/***************************************************************************************/
	Timetable timetable_CRL_LUX_BUS;
	start = std::vector<std::string>{ "01:30", "03:45", "05:25", "06:55", "09:10", "11:50", "14:05", "15:40", "17:35", "20:20", "23:30" };
	for (int day = 1; day <= 31; ++day) {
		for (size_t t = 0; t < start.size(); ++t) {
			sprintf_s(dateBuff, "2018-03-%02d %s", day, start[t].c_str());
			if (t == 3 || t == 7)
				timetable_CRL_LUX_BUS.add(dateBuff, 5., 3_hour + 20_min);
			else
				timetable_CRL_LUX_BUS.add(dateBuff, 5., 3_hour + 5_min);
		}
	}
	// 01:30, 3_hour + 5_min);
	// 03:45, 3_hour + 5_min
	// 05:25, 3_hour + 5_min
	// 06:55, 3_hour + 20_min
	// 09:10, 3_hour + 5_min
	// 11:50, 3_hour + 5_min
	// 14:05, 3_hour + 5_min
	// 15:40, 3_hour + 20_min
	// 17:35, 3_hour + 5_min
	// 20:20, 3_hour + 5_min
	// 23:30, 3_hour + 5_min
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
	start = std::vector<std::string>{ "01:30", "03:45", "05:25", "06:55", "09:10", "11:50", "14:05", "15:40", "17:35", "20:20", "23:30" };
	for (int day = 1; day <= 31; ++day) {
		for (size_t t = 0; t < start.size(); ++t) {
			sprintf_s(dateBuff, "2018-03-%02d %s", day, start[t].c_str());
			if (t == 3 || t == 7)
				timetable_BCN_Barcelona.add(dateBuff, 5., 3_hour + 20_min);
			else
				timetable_BCN_Barcelona.add(dateBuff, 5., 3_hour + 5_min);
		}
	}
	context->addConnection(Connection::createBus(nodeBCN, nodeBarcelona, timetable_BCN_Barcelona));

	Timetable timetable_Barcelona_BCN;
	start = std::vector<std::string>{ "01:30", "03:45", "05:25", "06:55", "09:10", "11:50", "14:05", "15:40", "17:35", "20:20", "23:30" };
	for (int day = 1; day <= 31; ++day) {
		for (size_t t = 0; t < start.size(); ++t) {
			sprintf_s(dateBuff, "2018-03-%02d %s", day, start[t].c_str());
			if (t == 3 || t == 7)
				timetable_Barcelona_BCN.add(dateBuff, 5., 3_hour + 20_min);
			else
				timetable_Barcelona_BCN.add(dateBuff, 5., 3_hour + 5_min);
		}
	}
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
	timetable_FRA_BCN.add("2018-03-01 17:40", 24.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-02 17:40", 24.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-03 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-04 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-05 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-06 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-07 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-08 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-09 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-10 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-11 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-12 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-13 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-14 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-15 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-16 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-17 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-18 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-19 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-20 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-21 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-22 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-23 17:40", 45.99, 2_hour + 20_min);
	timetable_FRA_BCN.add("2018-03-24 17:40", 45.99, 2_hour + 20_min);
	context->addConnection(Connection::createAirplane(nodeFRA, nodeBCN, timetable_FRA_BCN));

	//BCN-FRA; ryanair
	// datetime, price, travelling time in hours
	Timetable timetable_BCN_FRA;
	timetable_BCN_FRA.add("2018-03-01 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-02 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-03 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-04 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-05 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-06 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-07 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-08 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-09 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-10 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-11 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-12 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-13 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-14 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-15 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-16 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-17 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-18 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-19 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-20 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-21 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-22 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-23 20:35", 45.99, 2_hour + 20_min);
	timetable_BCN_FRA.add("2018-03-24 20:35", 45.99, 2_hour + 20_min);
	context->addConnection(Connection::createAirplane(nodeBCN, nodeFRA, timetable_BCN_FRA));

	// CGN - BCN, ryanair
	Timetable timetable_CGN_BCN;
	timetable_CGN_BCN.add("2018-03-01 21:25", 24.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-02 21:25", 24.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-03 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-04 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-05 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-06 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-07 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-08 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-09 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-10 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-11 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-12 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-13 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-14 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-15 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-16 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-17 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-18 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-19 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-20 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-21 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-22 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-23 21:25", 45.99, 2_hour + 25_min);
	timetable_CGN_BCN.add("2018-03-24 21:25", 45.99, 2_hour + 25_min);
	context->addConnection(Connection::createAirplane(nodeCGN, nodeBCN, timetable_CGN_BCN));

	// BCN - CGN, ryanair
	Timetable timetable_BCN_CGN;
	timetable_BCN_CGN.add("2018-03-01 18:10", 35.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-02 18:10", 35.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-03 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-04 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-05 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-06 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-07 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-08 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-09 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-10 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-11 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-12 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-13 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-14 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-15 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-16 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-17 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-18 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-19 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-20 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-21 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-22 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-23 18:10", 45.99, 2_hour + 40_min);
	timetable_BCN_CGN.add("2018-03-24 18:10", 45.99, 2_hour + 40_min);
	context->addConnection(Connection::createAirplane(nodeBCN, nodeCGN, timetable_BCN_CGN));


	// CRL - BCN ryanair
	Timetable timetable_CRL_BCN;
	timetable_CRL_BCN.add("2018-03-01 14:40", 69.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-02 14:40", 69.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-03 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-04 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-05 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-06 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-07 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-08 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-09 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-10 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-11 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-12 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-13 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-14 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-15 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-16 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-17 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-18 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-19 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-20 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-21 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-22 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-23 14:40", 45.99, 2_hour + 5_min);
	timetable_CRL_BCN.add("2018-03-24 14:40", 45.99, 2_hour + 5_min);
	context->addConnection(Connection::createAirplane(nodeCRL, nodeBCN, timetable_CRL_BCN));


	// BCN - CRL ryanair
	Timetable timetable_BCN_CRL;
	timetable_BCN_CRL.add("2018-03-01 12:00", 69.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-02 12:00", 69.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-03 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-04 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-05 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-06 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-07 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-08 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-09 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-10 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-11 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-12 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-13 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-14 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-15 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-16 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-17 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-18 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-19 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-20 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-21 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-22 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-23 12:00", 45.99, 2_hour + 15_min);
	timetable_BCN_CRL.add("2018-03-24 12:00", 45.99, 2_hour + 15_min);
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