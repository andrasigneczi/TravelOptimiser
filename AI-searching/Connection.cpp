#include "Connection.h"

Connection::Connection( std::string node1, std::string node2, Type type, double timeConsuming, double distance, double cost ) {
    mNode1 = node1;
    mNode2 = node2;
    mConnectionType = type;
    mTimeConsuming = timeConsuming;
    mDistance = distance;
    mCost = cost;
}

// cost calculated from the distance and the fuel price/km
Connection Connection::createCar( std::string node1, std::string node2, double timeConsuming, double distance ) {
    return Connection( node1, node2, car, timeConsuming, distance, 0 );
}

// cost is the ticket and additional prices
Connection Connection::createAirplane( std::string node1, std::string node2, double timeConsuming, double cost ) {
    return Connection( node1, node2, airplane, timeConsuming, 0, cost );
}

// e.g. staying in a hotel or waiting at the airport
Connection Connection::createStay( std::string node, double timeConsuming, double cost ) {
    return Connection( node, "", stay, timeConsuming, 0, cost );
}

// the distance doesn't matter
Connection Connection::createBus( std::string node1, std::string node2, double timeConsuming, double cost ) {
    return Connection( node1, node2, bus, timeConsuming, 0, cost );
}

// the distance doesn't matter
Connection Connection::createTaxi( std::string node1, std::string node2, double timeConsuming, double cost ) {
    return Connection( node1, node2, taxi, timeConsuming, 0, cost );
}

// frobably it's free of charge
Connection Connection::createOnFoot( std::string node1, std::string node2, double timeConsuming ) {
    return Connection( node1, node2, car, timeConsuming, 0, 0 );
}

Connection::Type Connection::getType(std::string name) {
	if (name.compare("car") == 0) {
		return car;
	}
	else if (name.compare("bus") == 0) {
		return bus;
	}
	else if (name.compare("taxi") == 0) {
		return taxi;
	}
	else if (name.compare("airplane") == 0) {
		return airplane;
	}
	else if (name.compare("on_foot") == 0) {
		return on_foot;
	}
	else if (name.compare("stay") == 0) {
		return stay;
	}
	//else if (name.compare("unknown") == 0) {
	//	return unknown;
	//}
	return unknown;
}

std::string Connection::typeToString(Connection::Type type) {
	switch (type) {
	case car: return "car"; break;
	case bus: return "bus"; break;
	case taxi: return "taxi"; break;
	case airplane: return "airplane"; break;
	case on_foot: return "on_foot"; break;
	case stay: return "stay"; break;
	case unknown: return "unknown"; break;
	}
	return "";
}
