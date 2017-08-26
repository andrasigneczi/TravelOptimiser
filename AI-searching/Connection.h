#ifndef _CONNECTION_H
#define _CONNECTION_H

// Can be several connection type between two nodes: bus, car, airplane, taxi, on foot.
// All of the connections has time and money expense.
// If we spend some time in a hotel or in a city, it's also a connection.
// Every connection has a direction, because the cost and the lasting of the trip can be different.

#include <string>
#include "Timetable.h"

class Connection {
public:

    enum Type {
        car,
        bus,
        taxi,
        airplane,
        on_foot,
        stay, // in a city, in a hotel, at the airport, etc.
		parking,
		carpool,
		unknown
    };
    
    // cost calculated from the distance and the fuel price/km
	static Connection createCar(std::string node1, std::string node2, double timeConsuming, double distance);
	static Connection createCarpool(std::string node1, std::string node2, double timeConsuming, double cost);

    // cost is the ticket and additional prices
    static Connection createAirplane( std::string node1, std::string node2, double timeConsuming, Timetable timetable );
    
    // e.g. staying in a hotel or waiting at the airport
	static Connection createStay(std::string node, double timeConsuming, double cost);
	static Connection createParking(std::string node, double cost);

    // the distance doesn't matter
    static Connection createBus( std::string node1, std::string node2, double timeConsuming, Timetable timetable );

    // the distance doesn't matter
    static Connection createTaxi( std::string node1, std::string node2, double timeConsuming, double cost );
    
    // frobably it's free of charge
    static Connection createOnFoot( std::string node1, std::string node2, double timeConsuming );

	static Type getType(std::string name);
	static std::string typeToString(Connection::Type type);

	std::string mNode1; // name, e.g. Igel
	std::string mNode2; // name, e.g. Luxmbourg

	Type   mConnectionType;
	double  mTimeConsuming; // in hour
	double  mDistance;      // in km
	double  mCost;
	Timetable mTimetable;

private:
    Connection( std::string node1, std::string node2, Type type, double timeConsuming, double distance, double cost );

};

#endif // _CONNECTION_H
