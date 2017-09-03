#include "Context.h"

Context::~Context() {
	for (auto pair : mNodes) {
		delete pair.second;
	}
}

void Context::addConnection( Connection c ) {
    mConnections.push_back( c );
    createNode( c );
}

void Context::setGoal( std::vector<std::string> stops ) {
    mGoal = stops;
}

void Context::createNode( Connection c ) {
    auto it = mNodes.find( c.mNode1 );
    if( it == mNodes.end()) {
        CtNode* node = new CtNode( c.mNode1 );
        auto insIt = mNodes.emplace( c.mNode1, node );
		if (insIt.second) {
			it = insIt.first;
		}
    }
    
	if (c.mConnectionType == Connection::stay || c.mConnectionType == Connection::parking) {
		it->second->mLinks.push_back({ c.mConnectionType, it->second, c.mTimeConsuming, c.mDistance, c.mCost, c.mTimetable });
		return;
	}

    auto it2 = mNodes.find( c.mNode2 );
    if( it2 == mNodes.end()) {
        CtNode* node = new CtNode( c.mNode2 );
		auto insIt = mNodes.emplace( c.mNode2, node );
		if (insIt.second) {
			it2 = insIt.first;
		}
	}

    it->second->mLinks.push_back({ c.mConnectionType, it2->second, c.mTimeConsuming, c.mDistance, c.mCost, c.mTimetable });
}
