#pragma once

#ifndef _CTNODE_H
#define _CTNODE_H
#include <vector>

#include "Connection.h"

struct CtNode {
	CtNode(std::string name) { mName = name; }

	std::string mName;
	struct Link {
		Link(Connection::Type type, CtNode* node, double  timeConsuming, double  distance, double  cost, Timetable timetable) { mType = type; mNode = node; mTimeConsuming = timeConsuming; mDistance = distance; mCost = cost; mTimetable = timetable; }
		Connection::Type mType;
		CtNode* mNode;
		double  mTimeConsuming; // in hour
		double  mDistance;      // in km
		double  mCost;
		Timetable mTimetable;
	};
	std::vector<CtNode::Link> mLinks;
};

struct nodeComparator {
	bool operator() (const CtNode* node1, const CtNode* node2) const {
		return node1->mName.compare(node2->mName) < 0;
	}
};

#endif // _CTNODE_H