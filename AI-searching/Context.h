#pragma once

#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "Connection.h"
#include <vector>
#include <string>
//#include <unordered_map>
#include <map>
//#include <unordered_set>
#include <set>
#include "CtNode.h"

class Context {

public:
	Context() : mMaxSpentTime(0.0), mDisplayMatchNumberPerScenarion( 1000 ) {}
	~Context();
	void addConnection(Connection c);
	void setGoal(std::vector<std::string> stops);

	CtNode* createNode(std::string name, std::string timeZone);

	const std::vector<std::string>& getGoal() const { return mGoal; }
	const std::string& getGoalItem(int index) const { return mGoal.at(index); }
	const std::string& getLastGoalItem() const { return mGoal.at(mGoal.size() - 1); }
	const size_t getGoalSize() const { return mGoal.size(); }
	const CtNode* getNode(const std::string name) const;

	void setMaxSpentTime(double maxSpentTime) { mMaxSpentTime = maxSpentTime; } // in hours
	const double getMaxSpentTime() const { return mMaxSpentTime; }

	void setDisplayMatchNumberPerScenarion(int n) { mDisplayMatchNumberPerScenarion = n;  }
	const int getDisplayMatchNumberPerScenarion() const { return mDisplayMatchNumberPerScenarion; }
	bool isConnected(std::string name1, std::string name2);

private:
    void createNode( Connection c );
    
	std::map<std::string, std::set<std::string>> mConnections;
    std::vector<std::string> mGoal;

    std::set<CtNode*, nodeComparator> mNodes;
	double mMaxSpentTime;
	int mDisplayMatchNumberPerScenarion;
};

#endif // _CONTEXT_H
