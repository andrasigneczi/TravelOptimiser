#include "test.h"
#include "Astar.h"
#include "Backtrack.h"
#include "Timetable.h"

static Context* createContext() {
    Context* context = new Context;

	CtNode* nodeIgel = context->createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context->createNode("Luxembourg", "+0200");
	CtNode* nodeCRL = context->createNode("CRL", "+0200");
	CtNode* nodeBUD = context->createNode("BUD", "+0200");
	CtNode* nodeHHN = context->createNode("HHN", "+0200");
	//CtNode* nodeSOF = context->createNode("SOF", "+0300");

    // 26 minutes, 34 km
    context->addConnection( Connection::createCar(nodeIgel, nodeLuxembourg, 26_min, 34 ));
    context->addConnection( Connection::createCar(nodeLuxembourg, nodeIgel, 26_min, 34 ));
	
	
	Timetable ttIgelLuxembourg;
	// price, hours
	ttIgelLuxembourg.add("2017-07-28 05:15", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 05:15", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 06:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 07:05", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 07:15", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 07:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 08:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 09:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 10:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 11:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 12:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 13:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 14:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 15:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 16:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 16:55", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:05", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:15", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:15", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:25", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:35", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 17:55", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 18:05", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 18:25", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 18:45", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 19:05", 2, 4_hour);
	ttIgelLuxembourg.add("2017-07-28 20:05", 2, 4_hour);
	// 1 hour
	context->addConnection(Connection::createBus(nodeIgel, nodeLuxembourg, ttIgelLuxembourg));

	Timetable ttLuxembourgIgel;
	// price, hours
	ttLuxembourgIgel.add("2017-07-31 05:15", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 05:15", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 06:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 07:05", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 07:15", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 07:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 08:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 09:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 10:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 11:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 12:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 13:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 14:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 15:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 16:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 16:55", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:05", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:15", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:15", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:25", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:35", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 17:55", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 18:05", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 18:25", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 18:45", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 19:05", 2, 4_hour);
	ttLuxembourgIgel.add("2017-07-31 20:05", 2, 4_hour);
	// 1 hour
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeIgel, ttLuxembourgIgel));

	// 3 hours, 215 km
    context->addConnection( Connection::createCar(nodeLuxembourg, nodeCRL, 3_hour, 215 ));
    context->addConnection( Connection::createCar(nodeCRL, nodeLuxembourg, 3_hour, 215 ));
	
	// 3 hours, 10 €
	context->addConnection(Connection::createCarpool(nodeLuxembourg, nodeCRL, 3_hour, 10));
	context->addConnection(Connection::createCarpool(nodeCRL, nodeLuxembourg, 3_hour, 10));

	// The different buses has different price.
	Timetable timetable1;
	timetable1.add("2017-07-28 06:15", 25, 4_hour);
	timetable1.add("2017-07-28 09:15", 25, 4_hour);
	timetable1.add("2017-07-28 12:15", 25, 4_hour);
	timetable1.add("2017-07-28 15:15", 5,  4_hour);
	timetable1.add("2017-07-28 18:15", 25, 4_hour);
	timetable1.add("2017-07-28 21:15", 25, 4_hour);
	timetable1.add("2017-07-29 00:15", 5,  4_hour);

	// 4 hours, 25 euro
	context->addConnection(Connection::createBus(nodeLuxembourg, nodeCRL, timetable1));

	// The different buses has different price.
	Timetable timetable2;
	timetable2.add("2017-07-28 08:15", 15, 4_hour);
	timetable2.add("2017-07-28 11:15", 15, 4_hour);
	timetable2.add("2017-07-28 14:15", 15, 4_hour);
	timetable2.add("2017-07-28 17:15", 15, 4_hour);
	timetable2.add("2017-07-28 21:15", 15, 4_hour);
	timetable2.add("2017-07-29 00:15", 15, 4_hour);
	timetable2.add("2017-07-29 03:15", 15, 4_hour);
	timetable2.add("2017-07-29 06:50", 25, 4_hour);

	context->addConnection(Connection::createBus(nodeCRL, nodeLuxembourg, timetable2));

	// The different flights has different price.
	Timetable timetable3;
	timetable3.add("2017-07-28 06:15", 50, 3_hour + 5_min);
	timetable3.add("2017-07-28 18:15", 60, 3_hour + 5_min);

    // I added the extra time (1.25h), what we have to spend at the airports; 23 euro
    context->addConnection( Connection::createAirplane(nodeCRL, nodeBUD, timetable3 ));

	// The different flights has different price.
	Timetable timetable4;
	timetable4.add("2017-07-31 08:15", 15, 3_hour + 25_min);
	timetable4.add("2017-07-31 20:50", 100, 3_hour + 25_min);

    context->addConnection( Connection::createAirplane(nodeBUD, nodeCRL, timetable4 ));

    // 55 hours, 250 euro with accomodation
    context->addConnection( Connection::createStay(nodeBUD, 250 )); // spent time and money in Budapest
	// the parking must be listed even times in the result, so I have to add half prcie
	context->addConnection( Connection::createParking(nodeCRL, 16.5 )); // car parking in CRL
	context->addConnection(Connection::createParking(nodeHHN, 11.5)); // car parking in HHN
	context->addConnection(Connection::createParking(nodeBUD, 0)); // car parking in Budapest

    // 1 hour 20 minutes, 106 km
	context->addConnection(Connection::createCar(nodeLuxembourg, nodeHHN, 1_hour + 20_min, 106));
	context->addConnection(Connection::createCar(nodeHHN, nodeLuxembourg, 1_hour + 20_min, 106));

	// 1 hour 1 minute, 77 km
	context->addConnection(Connection::createCar(nodeIgel, nodeHHN, 1_hour + 1_min, 77));
	context->addConnection(Connection::createCar(nodeHHN, nodeIgel, 1_hour + 1_min, 77));

	Timetable timetable5;
	timetable5.add("2017-07-28 09:15", 83, 2_hour + 35_min);
	
	// I added the extra time (1.25h), what we have to spend at the airports; 83 euro
	context->addConnection( Connection::createAirplane(nodeHHN, nodeBUD, timetable5));

	Timetable timetable6;
	timetable5.add("2017-07-31 10:15", 83, 2_hour + 35_min);

	// I added the extra time (1.25h), what we have to spend at the airports; 83 euro
	context->addConnection(Connection::createAirplane(nodeBUD, nodeHHN, timetable5));

    // Igel-Budapest, Budapest-Igel by car 1152 km, 12 hours with rest
    context->addConnection( Connection::createCar(nodeIgel, nodeBUD, 12_hour, 1152. ));
    context->addConnection( Connection::createCar(nodeBUD, nodeIgel, 12_hour, 1152. ));
    
    // how will I define, that if I departed from Igel to BUD, I have to come back with that?
    // Maybe I should prepare a different search for this scenario
    context->setGoal( { "Igel", "BUD:stay", "Igel" } );

	// maximum 3 days can be the trip
	//context->setMaxSpentTime( 3. * 24. );
	//context->setDisplayMatchNumberPerScenarion(3);
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
