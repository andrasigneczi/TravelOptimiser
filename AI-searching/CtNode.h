#pragma once

#ifndef _CTNODE_H
#define _CTNODE_H
#include <vector>

#include "Connection.h"

struct CtNode {
	CtNode(std::string name, std::string timeZone) { mName = name; mTimeZone = timeZone; }

	std::string mName;
	std::string mTimeZone;
	struct Link {
		Link(Connection::Type type, CtNode* node, Duration  timeConsuming, double  distance, double  cost, const Timetable& timetable) { mType = type; mNode = node; mTimeConsuming = timeConsuming; mDistance = distance; mCost = cost; mTimetable = timetable; }
		Connection::Type mType;
		CtNode* mNode;
		Duration  mTimeConsuming;
		double  mDistance;      // in km
		double  mCost;
		Timetable mTimetable;
	};
	typedef std::vector<CtNode::Link> Links;
	Links mLinks;
};

struct nodeComparator {
	bool operator() (const CtNode* node1, const CtNode* node2) const {
		return node1->mName.compare(node2->mName) < 0;
	}
};

#endif // _CTNODE_H