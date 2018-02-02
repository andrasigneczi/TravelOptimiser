#include "testTimetable.h"
#include "Timetable.h"
#include "Context.h"

void testTimetable() {
	char dateBuff[100];
	std::vector<std::string> departure;
    
	Context* context = new Context;
	CtNode* nodeIgel = context->createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context->createNode("Luxembourg", "+0200"); // JFK
	CtNode* nodeLUX = context->createNode("LUX", "+0200"); // airport

	Timetable timetable_Igel_JFK_BUS;
	// A = hétfő-péntek munkanapokon
	// X = hétfő-szombat munkanapokon
	// S = szombat
	departure = { "A 5:09",  "A 5:24",  "A 5:39",  "A 5:54",  "A 6:09",  "A 6:24",  "A 6:41",  "A 6:51",  "A 6:56", "A 7:01", "A 7:06",
	              "A 7:11",  "A 7:16",  "A 7:26",  "A 7:41",  "A 7:56",  "S 7:56",  "A 8:11",  "A 8:26",  "A 8:56", "A 9:54", "X 10:54",
	              "A 11:54", "A 12:54", "X 13:54", "A 14:54", "A 15:54", "X 16:56", "A 17:56", "A 18:54", "A 19:54" };
/*	              
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
*/
	timetable_Igel_JFK_BUS.add( Rule( "2017.05.01", "2018.05.01" ));
	timetable_Igel_JFK_BUS.add( Rule( 'A', Rule::Monday, Rule::Friday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'X', Rule::Monday, Rule::Saturday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'S', Rule::Saturday ));
	timetable_Igel_JFK_BUS.add( departure );
	timetable_Igel_JFK_BUS.setFixPrice( 2. );
	timetable_Igel_JFK_BUS.setFixTravellingTime( 30_min );

	context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS));
    
    
	/*
	Monday - Friday : 5:30 - 23:00, every 10 minutes
	Saturday: 5:25 - 23:05, every 20 minutes
	Sunday: 5:59 - 22:59, every 30 minutes
	*/
	Timetable timetable_JFK_LUX_BUS;
/*	
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
*/
	timetable_JFK_LUX_BUS.add( Rule( "2017.05.01", "2018.05.01" ));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Monday, Rule::Friday, Rule::Workday, "5:30", "23:00", 10_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Saturday,        "5:25", "23:05", 20_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Sunday,          "5:59", "22:59", 30_min));
	//timetable_JFK_LUX_BUS.add( Rule( Rule::PublicHoliday,   "5:59", "22:59", 30_min));
	timetable_JFK_LUX_BUS.setFixPrice( 2. );
	timetable_JFK_LUX_BUS.setFixTravellingTime( 15_min );

	context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));
    
}
