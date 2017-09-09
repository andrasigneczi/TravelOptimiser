#pragma once

#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "Connection.h"
#include <vector>
#include <string>
#include <unordered_map>
//#include <unordered_set>
#include <set>
#include "CtNode.h"

class Context {

public:
	~Context();
    void addConnection( Connection c );
    void setGoal( std::vector<std::string> stops );

	CtNode* createNode(std::string name);

    const std::vector<std::string>& getGoal() const { return mGoal; }
    const std::string& getGoalItem( int index ) const { return mGoal.at( index ); }
    const std::string& getLastGoalItem() const { return mGoal.at( mGoal.size() - 1 ); }
    const size_t getGoalSize() const { return mGoal.size(); }
	const CtNode* getNode(const std::string name) const;
    
private:
    void createNode( Connection c );
    
    std::vector<Connection> mConnections;
    std::vector<std::string> mGoal;

    std::set<CtNode*, nodeComparator> mNodes;
};

#endif // _CONTEXT_H
