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
	Context() 
		: mMaxSpentTime(0)
		, mDisplayMatchNumberPerScenarion(100000)
		, mMaxPathLength(10)
		, mMaxStayingTime(0)
		, mMinStayingTime(0)
		, mMaxWaitingTime(0)
		, mMaxTravellingTime(0){}

	~Context();
	void addConnection(Connection c);
	void setGoal(std::vector<std::string> stops);

	CtNode* createNode(std::string name, std::string timeZone);

	const std::vector<std::string>& getGoal() const { return mGoal; }
	const std::string& getGoalItem(int index) const { return mGoal.at(index); }
	const std::string& getLastGoalItem() const { return mGoal.at(mGoal.size() - 1); }
	size_t getGoalSize() const { return mGoal.size(); }
	const CtNode* getNode(const std::string name) const;

	void setMaxSpentTime(Duration maxSpentTime) { mMaxSpentTime = maxSpentTime.getSec(); } // in hours
	const Duration getMaxSpentTime() const { return Duration( mMaxSpentTime ); }

	void setDisplayMatchNumberPerScenarion(int n) { mDisplayMatchNumberPerScenarion = n; }
	int getDisplayMatchNumberPerScenarion() const { return mDisplayMatchNumberPerScenarion; }

	bool isConnected(std::string name1, std::string name2);

	void setMaxPathLength(int maxPathLength) { mMaxPathLength = maxPathLength; };
	int getMaxPathLength() const { return mMaxPathLength; }

	void setMaxStayingTime(Duration d) { mMaxStayingTime = d.getSec(); };
	Duration getMaxStayingTime() const { return Duration( mMaxStayingTime ); }

	void setMinStayingTime(Duration d) { mMinStayingTime = d.getSec(); };
	Duration getMinStayingTime() const { return Duration( mMinStayingTime ); }

	void setMaxWaitingTime(Duration d) { mMaxWaitingTime = d.getSec(); };
	Duration getMaxWaitingTime() const { return Duration( mMaxWaitingTime ); }

	void setMaxTravellingTime(Duration d) { mMaxTravellingTime = d.getSec(); };
	Duration getTravellingTime() const { return Duration( mMaxTravellingTime ); }
private:
    void createNode( Connection c );
    
	std::map<std::string, std::set<std::string>> mConnections;
    std::vector<std::string> mGoal;

    std::set<CtNode*, nodeComparator> mNodes;
	time_t mMaxSpentTime;
	int mDisplayMatchNumberPerScenarion;
	int mMaxPathLength;
	time_t mMaxStayingTime;
	time_t mMinStayingTime;
	time_t mMaxWaitingTime;
	time_t mMaxTravellingTime;
};

#endif // _CONTEXT_H
