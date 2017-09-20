#include "testTimeZone.h"
#include "Backtrack.h"
#include "Timetable.h"

static Context* createContext() {
	Context* context = new Context;

	CtNode* nodeIgel = context->createNode("Igel", "+0200");
	CtNode* nodeLuxembourg = context->createNode("Luxembourg", "+0200");
	CtNode* nodeCRL = context->createNode("CRL", "+0200");
	CtNode* nodeSOF = context->createNode("SOF", "+0300");



	// 26 minutes, 34 km
	context->addConnection(Connection::createCar(nodeIgel, nodeLuxembourg, 26. / 60., 34));
	context->addConnection(Connection::createCar(nodeLuxembourg, nodeIgel, 26. / 60., 34));


	// 3 hours, 215 km
	context->addConnection(Connection::createCar(nodeLuxembourg, nodeCRL, 3., 215));
	context->addConnection(Connection::createCar(nodeCRL, nodeLuxembourg, 3., 215));



	// The different flights has different price.
	Timetable timetable3;
	timetable3.add("2017-07-28 06:15", 50, 1 + 5. / 6. + 1.25);
	timetable3.add("2017-07-28 18:15", 60, 1 + 5. / 6. + 1.25);
	timetable3.add("2017-07-31 06:15", 50, 1 + 5. / 6. + 1.25);
	timetable3.add("2017-07-31 18:15", 60, 1 + 5. / 6. + 1.25);
	timetable3.add("2017-08-02 06:15", 50, 1 + 5. / 6. + 1.25);
	timetable3.add("2017-08-02 18:15", 60, 1 + 5. / 6. + 1.25);

	// I added the extra time (1.25h), what we have to spend at the airports; 23 euro
	context->addConnection(Connection::createAirplane(nodeCRL, nodeSOF, timetable3));

	// The different flights has different price.
	Timetable timetable4;
	timetable4.add("2017-07-31 08:15", 15, 2 + 1. / 6. + 1.25);
	timetable4.add("2017-07-31 20:50", 100, 2 + 1. / 6. + 1.25);
	timetable4.add("2017-08-01 08:15", 15, 2 + 1. / 6. + 1.25);
	timetable4.add("2017-08-01 20:50", 100, 2 + 1. / 6. + 1.25);
	timetable4.add("2017-08-02 08:15", 15, 2 + 1. / 6. + 1.25);
	timetable4.add("2017-08-02 20:50", 100, 2 + 1. / 6. + 1.25);

	context->addConnection(Connection::createAirplane(nodeSOF, nodeCRL, timetable4));


	// 55 hours, 250 euro with accomodation
	context->addConnection(Connection::createStay(nodeSOF, 250)); // spent time and money in Budapest
	// the parking must be listed even times in the result, so I have to add half prcie
	context->addConnection(Connection::createParking(nodeCRL, 16.5)); // car parking in CRL


	context->setGoal({ "Igel", "SOF:stay", "Igel" });
	//context->setMaxSpentTime(128.);
	//context->setDisplayMatchNumberPerScenarion(3);
	return context;
}

void testTimeZone() {
	Backtrack backtrack;
	auto result = backtrack.seachTheBestWay(createContext());

}