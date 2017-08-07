#include "Astar.h"
#include "Backtrack.h"
#include "Timetable.h"

Context* createContext() {
    Context* context = new Context;
    // createCar( std::string node1, std::string node2, float timeConsuming, float distance );
    // createAirplane( std::string node1, std::string node2, float timeConsuming, float cost );
    // createStay( std::string node, float timeConsuming, float cost );

    // 26 minutes, 34 km
    context->addConnection( Connection::createCar( "Igel", "Luxembourg", 26./60., 34 ));
    context->addConnection( Connection::createCar( "Luxembourg", "Igel", 26./60., 34 ));
    // 3 hours, 215 km
    context->addConnection( Connection::createCar( "Luxembourg", "CRL", 3., 215 ));
    context->addConnection( Connection::createCar( "CRL", "Luxembourg", 3., 215 ));
	
	// 3 hours, 10 ʉcontext->addConnection(Connection::createCarpool("Luxembourg", "CRL", 3., 10));
	context->addConnection(Connection::createCarpool("CRL", "Luxembourg", 3., 10));

	// The different buses has different price.
	Timetable timetable1;
	timetable1.add("2017.07.31. 06:15", 25);
	timetable1.add("2017.07.31. 18:15", 5);

	// 4 hours, 25 euro
	context->addConnection(Connection::createBus("Luxembourg", "CRL", 4.0, timetable1));

	// The different buses has different price.
	Timetable timetable2;
	timetable1.add("2017.07.28. 08:15", 15);
	timetable1.add("2017.07.28. 20:50", 25);

	context->addConnection(Connection::createBus("CRL", "Luxembourg", 4.0, timetable2));

	// The different flights has different price.
	Timetable timetable3;
	timetable3.add("2017.07.31. 06:15", 50);
	timetable3.add("2017.07.31. 18:15", 60);

    // I added the extra time (1.25h), what we have to spend at the airports; 23 euro
    context->addConnection( Connection::createAirplane( "CRL", "BUD", 1 + 5./6. + 1.25, timetable3 )); 

	// The different flights has different price.
	Timetable timetable4;
	timetable4.add("2017.07.28. 08:15", 15);
	timetable4.add("2017.07.28. 20:50", 100);

    context->addConnection( Connection::createAirplane( "BUD", "CRL", 2 + 1./6. + 1.25, timetable4 ));

    // 55 hours, 250 euro with accomodation
    context->addConnection( Connection::createStay( "BUD", 55, 250 )); // spent time and money in Budapest
	// the parking must be listed even times in the result, so I have to add half prcie
	context->addConnection( Connection::createParking( "CRL", 0, 16.5 )); // car parking in CRL
	context->addConnection(Connection::createParking("HHN", 0, 11.5)); // car parking in HHN
	context->addConnection(Connection::createParking("BUD", 0, 0)); // car parking in Budapest

    // 1 hour 20 minutes, 106 km
	context->addConnection(Connection::createCar("Luxembourg", "HHN", 1.33, 106));
	context->addConnection(Connection::createCar("HHN", "Luxembourg", 1.33, 106));

	// 1 hour 1 minute, 77 km
	context->addConnection(Connection::createCar("Igel", "HHN", 1.03, 77));
	context->addConnection(Connection::createCar("HHN", "Igel", 1.03, 77));

	Timetable timetable5;
	timetable5.add("2017.07.28. 08:15", 83);
	
	// I added the extra time (1.25h), what we have to spend at the airports; 83 euro
	context->addConnection( Connection::createAirplane( "HHN", "BUD",  1.33 + 1.25, timetable5));

	Timetable timetable6;
	timetable5.add("2017.07.31. 08:15", 83);

	// I added the extra time (1.25h), what we have to spend at the airports; 83 euro
	context->addConnection(Connection::createAirplane("BUD", "HHN", 1.33 + 1.25, timetable5));

    // Igel-Budapest, Budapest-Igel by car 1152 km, 12 hours with rest
    context->addConnection( Connection::createCar( "Igel", "BUD", 12, 1152 ));
    context->addConnection( Connection::createCar( "BUD", "Igel", 12, 1152 ));
    
    // how will I define, that if I departed from Igel to BUD, I have to come back with that?
    // Maybe I should prepare a different search for this scenario
    context->setGoal( { "Igel", "BUD:stay", "Igel" } );
    return context;
}

void testBacktrack() {
    Backtrack backtrack;
    auto result = backtrack.seachTheBestWay( createContext());
}

void testAstar() {
    Astar aStar;
    auto result = aStar.seachTheBestWay( createContext());
}
