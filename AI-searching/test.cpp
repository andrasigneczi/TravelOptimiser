#include "Astar.h"
#include "Backtrack.h"

Context* createContext() {
    Context* context = new Context;
    // createCar( std::string node1, std::string node2, float timeConsuming, float distance );
    // createAirplane( std::string node1, std::string node2, float timeConsuming, float cost );
    // createStay( std::string node, float timeConsuming, float cost );

    // 26 minutes
    context->addConnection( Connection::createCar( "Igel", "Luxembourg", 26./60., 34 ));
    context->addConnection( Connection::createCar( "Luxembourg", "Igel", 26./60., 34 ));
    // 3 hours
    context->addConnection( Connection::createCar( "Luxembourg", "CRL", 3., 215 ));
    context->addConnection( Connection::createCar( "CRL", "Luxembourg", 3., 215 ));
	
	// 3 hours, 10 €
	context->addConnection(Connection::createCarpool("Luxembourg", "CRL", 3., 10));
	context->addConnection(Connection::createCarpool("CRL", "Luxembourg", 3., 10));
	
	// 4 hours, 25 €
	context->addConnection(Connection::createBus("Luxembourg", "CRL", 4., 25));
	context->addConnection(Connection::createBus("CRL", "Luxembourg", 4., 25));

    // I added the extra time (1.25h), what we have to spend at the airports
    context->addConnection( Connection::createAirplane( "CRL", "BUD", 1 + 5./6. + 1.25, 23 )); 
    context->addConnection( Connection::createAirplane( "BUD", "CRL", 2 + 1./6. + 1.25, 23 ));
    // 55 hours
    context->addConnection( Connection::createStay( "BUD", 55, 250 )); // spent time and money in Budapest
    context->addConnection( Connection::createParking( "CRL", 0, 33 )); // car parking in CRL
    context->addConnection( Connection::createParking( "HHN", 0, 23 )); // car parking in HHN
    
    // 1 hour 20 minutes
	context->addConnection(Connection::createCar("Luxembourg", "HHN", 1.33, 106));
	context->addConnection(Connection::createCar("HHN", "Luxembourg", 1.33, 106));

	// 1 hour 1 minute
	context->addConnection(Connection::createCar("Igel", "HHN", 1.03, 77));
	context->addConnection(Connection::createCar("HHN", "Igel", 1.03, 77));

    // I added the extra time (1.25h), what we have to spend at the airports
    context->addConnection( Connection::createAirplane( "HHN", "BUD",  1.33 + 1.25, 83 ));
    context->addConnection( Connection::createAirplane( "BUD", "HHN",  1.33 + 1.25, 83 ));
    
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
