#include "Context.h"
#include <assert.h>
#include "Connection.h"

Context::~Context() {
	for (auto ctnode : mNodes) {
		delete ctnode;
	}
}


void Context::addConnection( Connection c ) {
    //mConnections.push_back( c );
	if (c.mNode2 != nullptr) {
		auto it = mConnections.find(c.mNode1->mName);
		if (it != mConnections.end()) {
			if (c.mNode2 != nullptr) {
				it->second.emplace(c.mNode2->mName);
			}
		}
		else {
			std::set<std::string> newSet;
			newSet.emplace(c.mNode2->mName);
			mConnections.emplace(c.mNode1->mName, newSet);
		}
	}
    createNode( c );
}


CtNode* Context::createNode(std::string name, std::string timeZone) {
	CtNode node(name, timeZone);
	auto it = mNodes.find(&node);
	if (it == mNodes.end()) {
		CtNode* node = new CtNode(name, timeZone);
		auto insIt = mNodes.emplace(node);
		if (insIt.second) {
			it = insIt.first;
		}
	}
	return *it;
}

void Context::setGoal( std::vector<std::string> stops ) {
    mGoal = stops;
}

void Context::createNode( Connection c ) {
    auto it = mNodes.find( c.mNode1 );
    if( it == mNodes.end()) {
		assert(0);
	}
    
	if (c.mConnectionType == Connection::stay || c.mConnectionType == Connection::parking) {
		(*it)->mLinks.push_back({ c.mConnectionType, *it, c.mTimeConsuming, c.mDistance, c.mCost, c.mTimetable });
		return;
	}

    auto it2 = mNodes.find( c.mNode2 );
    if( it2 == mNodes.end()) {
		assert(0);
	}

    (*it)->mLinks.push_back({ c.mConnectionType, *it2, c.mTimeConsuming, c.mDistance, c.mCost, c.mTimetable });
}

const CtNode* Context::getNode(const std::string name) const {
	CtNode node( name, "" );
	auto it = mNodes.find(&node); 
	if (it == mNodes.end()) 
		return nullptr; 
	return *it; 
}

bool Context::isConnected(std::string name1, std::string name2) {
	auto it = mConnections.find(name1);
	if (it != mConnections.end()) {
		return it->second.find(name2) != it->second.end();
	}
	return false;
}
