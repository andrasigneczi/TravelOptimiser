#include "testTimetable.h"
#include "Timetable.h"
#include "Context.h"
#include "TimeHelper.h"

void testTimetable() {
	std::vector<std::string> departure;
    
   	std::cerr << "dbg testTimetable 1\n";

	Context* context = new Context;
	CtNode* nodeIgel = context->createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context->createNode("Luxembourg", "+0200"); // JFK
	CtNode* nodeLUX = context->createNode("LUX", "+0200"); // airport

   	std::cerr << "dbg testTimetable 2\n";

	Timetable timetable_Igel_JFK_BUS;
	// A = hétfő-péntek munkanapokon
	// X = hétfő-szombat munkanapokon
	// S = szombat
	departure = { "A 5:09",  "A 5:24",  "A 5:39",  "A 5:54",  "A 6:09",  "A 6:24",  "A 6:41",  "A 6:51",  "A 6:56", "A 7:01", "A 7:06",
	              "A 7:11",  "A 7:16",  "A 7:26",  "A 7:41",  /*"A 7:56",*/  "S 7:56",  "A 8:11",  "A 8:26",  "A 8:56", "A 9:54", "X 10:54",
	              "A 11:54", "A 12:54", "X 13:54", "A 14:54", "A 15:54", "X 16:56", "A 17:56", "A 18:54", "A 19:54" };

	timetable_Igel_JFK_BUS.add( Rule( "2017-05-01", "2018-05-01" ));
	timetable_Igel_JFK_BUS.add( Rule( 'A', Rule::Monday, Rule::Friday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'X', Rule::Monday, Rule::Saturday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'S', Rule::Saturday ));
	timetable_Igel_JFK_BUS.add( departure );
	timetable_Igel_JFK_BUS.setFixPrice( 2. );
	timetable_Igel_JFK_BUS.setFixTravellingTime( 30_min );

   	std::cerr << "dbg testTimetable 3\n";

	//context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS));
	Connection c1 = Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS);
	const Timetable& t1 = c1.getTimetable();
    
    for( auto& i : t1.getTimetableData()) {
    	//std::cerr << "dbg testTimetable 4: " << TimeHelper::timeToString( i.first, "+0200" ) << ";"  << i.second.mPrice << ";" << i.second.mTimeConsuming << std::endl;	
    }
   	
    
	/*
	Monday - Friday : 5:30 - 23:00, every 10 minutes
	Saturday: 5:25 - 23:05, every 20 minutes
	Sunday: 5:59 - 22:59, every 30 minutes
	*/
	Timetable timetable_JFK_LUX_BUS;

	timetable_JFK_LUX_BUS.add( Rule( "2017-05-01", "2018-05-01" ));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Monday, Rule::Friday, Rule::Workday, "5:30", "23:00", 10_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Saturday,        "5:25", "23:05", 20_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Sunday,          "5:59", "22:59", 30_min));
	//timetable_JFK_LUX_BUS.add( Rule( Rule::PublicHoliday,   "5:59", "22:59", 30_min));
	timetable_JFK_LUX_BUS.setFixPrice( 2. );
	timetable_JFK_LUX_BUS.setFixTravellingTime( 15_min );

   	std::cerr << "dbg testTimetable 5\n";

	// context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));
	Connection c2 = Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS);
   	const Timetable& t2 = c2.getTimetable();
    for( auto& i : t2.getTimetableData()) {
    	std::cerr << "dbg testTimetable 5: " << TimeHelper::timeToString( i.first, "+0200" ) << ";"  << i.second.mPrice << ";" << i.second.mTimeConsuming << std::endl;	
    }
   	
   	std::cerr << "dbg testTimetable 6\n";
   	
   	time_t s2t = TimeHelper::stringToTime("2018-05-01 06:09+0200");
   	std::cerr << TimeHelper::timeToString( s2t, "+0200" ) << std::endl;

   	s2t = TimeHelper::stringToTime("2017-08-12 11:50+0300");
   	std::cerr << TimeHelper::timeToString( s2t, "+0300" ) << std::endl;
   	
   	Date date;
   	date = "2018-05-01";
   	std::cerr << "weekday: " << date.getWDay() << std::endl;
	std::cerr << "year: " << date.getYear() << std::endl;
	std::cerr << "month: " << date.getMonth() << std::endl;
	std::cerr << "day: " << date.getDay() << std::endl;
}
