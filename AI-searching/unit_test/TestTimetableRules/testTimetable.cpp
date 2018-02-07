#include "testTimetable.h"
#include "Timetable.h"
#include "Context.h"
#include "TimeHelper.h"

static const std::vector<std::string> publicHolidays_Luxembourg = { "2018-01-01", "2018-03-30", "2018-04-02", "2018-05-01", "2018-05-10", "2018-05-21", "2018-06-23",
	"2018-08-15", "2018-11-01", "2018-12-25", "2018-12-26"
};

static const std::vector<std::string> extraWorkdays_Luxembourg = { "2018-01-06", "2018-03-19", "2018-04-04", "2018-04-07" };

static void testHeader( std::string name ) {
	std::cout << std::endl;
	std::cout << std::string( name.length() + 4, '*' ) << "\n";
	std::cout << "* " << name << " *\n";
	std::cout << std::string( name.length() + 4, '*' ) << "\n";
}

void testTimetable_type1() {
	testHeader( "Timetable test 1" );
	
	std::vector<std::string> departure;
    
	Context context;
	CtNode* nodeIgel = context.createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context.createNode("Luxembourg", "+0200"); // JFK

	Timetable timetable_Igel_JFK_BUS;
	// A = Monday-Friday workdays
	// X = Monday-Saturday workdays
	// S = Saturday
	departure = { "A 5:09",  "A 5:24",  "A 5:39",  "A 5:54",  "A 6:09",  "A 6:24",  "A 6:41",  "A 6:51",  "A 6:56", "A 7:01", "A 7:06",
	              "A 7:11",  "A 7:16",  "A 7:26",  "A 7:41",  "A 7:56",  "S 7:46",  "A 8:11",  "A 8:26",  "A 8:56", "A 9:54", "X 10:54",
	              "A 11:54", "A 12:54", "X 13:54", "A 14:54", "A 15:54", "X 16:56", "A 17:56", "A 18:54", "A 19:54" };

	timetable_Igel_JFK_BUS.add( Rule( "2018-01-01", "2018-01-02" ));
	timetable_Igel_JFK_BUS.add( Rule( 'A', Rule::Monday, Rule::Friday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'X', Rule::Monday, Rule::Saturday, Rule::Workday ));
	timetable_Igel_JFK_BUS.add( Rule( 'S', Rule::Saturday ));
	timetable_Igel_JFK_BUS.add( departure );
	timetable_Igel_JFK_BUS.setFixPrice( 2. );
	timetable_Igel_JFK_BUS.setFixTravellingTime( 30_min );
	timetable_Igel_JFK_BUS.addPublicHolidays( publicHolidays_Luxembourg );
	timetable_Igel_JFK_BUS.addExtraWorkdays( extraWorkdays_Luxembourg );
	
	//context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS));
	Connection c1 = Connection::createBus(nodeIgel, nodeLuxembourg, timetable_Igel_JFK_BUS);
	const Timetable& t1 = c1.getTimetable();
    
    for( auto& i : t1.getTimetableData()) {
    	std::cout << "departure: " << TimeHelper::timeToString( i.first, "+0200" ) << " ; ";
    	std::cout << "price: " << i.second.mPrice << " ; ";
    	std::cout << "time-consuming: " << i.second.mTimeConsuming << std::endl;	
    }
}

void testTimetable_type2() {
   
	testHeader( "Timetable test 2" );
	Context context;
	CtNode* nodeLuxembourg = context.createNode("Luxembourg", "+0200"); // JFK
	CtNode* nodeLUX = context.createNode("LUX", "+0200"); // airport
	/*
	Monday - Friday : 5:30 - 23:00, every 10 minutes
	Saturday: 5:25 - 23:05, every 20 minutes
	Sunday: 5:59 - 22:59, every 30 minutes
	*/
	Timetable timetable_JFK_LUX_BUS;

	timetable_JFK_LUX_BUS.add( Rule( "2018-01-01", "2018-01-02" ));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Monday, Rule::Friday, Rule::Workday, "5:30", "23:00", 10_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Saturday,        "5:25", "23:05", 20_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::Sunday,          "5:59", "22:59", 30_min));
	timetable_JFK_LUX_BUS.add( Rule( Rule::PublicHoliday,   "5:49", "22:49", 2_hour));
	timetable_JFK_LUX_BUS.setFixPrice( 2. );
	timetable_JFK_LUX_BUS.setFixTravellingTime( 15_min );
	timetable_JFK_LUX_BUS.addPublicHolidays( publicHolidays_Luxembourg );
	timetable_JFK_LUX_BUS.addExtraWorkdays( extraWorkdays_Luxembourg );

	// context->addConnection(Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS));
	Connection c2 = Connection::createBus(nodeLuxembourg, nodeLUX, timetable_JFK_LUX_BUS);
   	const Timetable& t2 = c2.getTimetable();

    for( auto& i : t2.getTimetableData()) {
    	std::cout << "departure: " << TimeHelper::timeToString( i.first, "+0200" ) << " ; ";
    	std::cout << "price: " << i.second.mPrice << " ; ";
    	std::cout << "time-consuming: " << i.second.mTimeConsuming << std::endl;	
    }
}

void testTimehelper() {
	testHeader( "TimeHelper test" );
	const char* date1 = "2018-05-01 06:09+0200";
   	time_t s2t = TimeHelper::stringToTime(date1);
   	std::cout << date1 << "\n";
   	std::cout << TimeHelper::timeToString( s2t, "+0200" ) << std::endl;

	const char* date2 = "2017-08-12 11:50+0300";
   	s2t = TimeHelper::stringToTime(date2);
   	std::cout << date2 << "\n";
   	std::cout << TimeHelper::timeToString( s2t, "+0300" ) << std::endl;
}

void testDate() {
	
	testHeader( "Date test" );
	
   	Date date;
   	date = "2018-05-01";
   	Date date2 ( "2018-04-30" );
   	Date date3 ( "2018-05-02" );
   	std::cout << "weekday: " << date.getWDay() << std::endl;
	std::cout << "year: " << date.getYear() << std::endl;
	std::cout << "month: " << date.getMonth() << std::endl;
	std::cout << "day: " << date.getDay() << std::endl;
	
	if( date > date2 ) {
		std::cout << "OK1\n";
	}
	if( date < date3 ) {
		std::cout << "OK2\n";
	}
	if( date == date ) {
		std::cout << "OK3\n";
	}
	Date date4 = date;
	if( date == date4 ) {
		std::cout << "OK4\n";
	}

	if( date < date2 ) {
		std::cout << "FAIL1\n";
	}
	if( date > date3 ) {
		std::cout << "FAIL2\n";
	}
	
	if( date != date ) {
		std::cout << "FAIL3\n";
	}
	
	if( date != date4 ) {
		std::cout << "FAIL4\n";
	}
	
	std::set<Date> set;
	set.insert( date );
	set.insert( date2 );
	set.insert( date3 );
	set.insert( date4 );
	if( set.find( Date( "2018-05-01" )) == set.end()) {
		std::cout << "FAIL5\n";
	}
	if( set.find( Date( "2018-05-02" )) == set.end()) {
		std::cout << "FAIL6\n";
	}
	if( set.find( Date( "2018-04-30" )) == set.end()) {
		std::cout << "FAIL7\n";
	}
	if( set.find( Date( "2018-05-01" )) != set.end()) {
		std::cout << "OK5\n";
	}
	if( set.find( Date( "2018-05-02" )) != set.end()) {
		std::cout << "OK6\n";
	}
	if( set.find( Date( "2018-04-30" )) != set.end()) {
		std::cout << "OK7\n";
	}
}
