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
	departure = { "5:09",  "5:24",  "5:39",  "5:54",  "6:09",  "6:24",  "6:41",  "6:51",  "6:56", "7:01", "7:06",
	              "7:11",  "7:16",  "7:26",  "7:41",  "7:56",  "7:56",  "8:11",  "8:26",  "8:56", "9:54", "10:54",
	              "11:54", "12:54", "13:54", "14:54", "15:54", "16:56", "17:56", "18:54", "19:54" };
	              
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
    
    
	/*
	Monday - Friday : 5:30 - 23:00, every 10 minutes
	Saturday: 5:25 - 23:05, every 20 minutes
	Sunday: 5:59 - 22:59, every 30 minutes
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
	/*
	timetable_JFK_LUX_BUS.add( Rule::from( "2017.05.01" ), Rule::to( "2018.05.01" ));
	timetable_JFK_LUX_BUS.add( Rule::Workday, Rule( Monday-Friday, "5:30", "23:00", 10_min));
	timetable_JFK_LUX_BUS.add( Rule( Saturday,        "5:25", "23:05", 20_min));
	timetable_JFK_LUX_BUS.add( Rule( Sunday,          "5:59", "22:59", 30_min));
	timetable_JFK_LUX_BUS.add( Rule( OfficialHoliday, "5:59", "22:59", 30_min));
	*/
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));
    
}
