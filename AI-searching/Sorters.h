#pragma once

#ifndef _SORTERS_H
#define _SORTERS_H

#include "Backtrack.h"

class Sorter {
public:
	Sorter(Backtrack& backtrack) : mBacktrack(backtrack) {}
	virtual void printMathes( int count );

protected:
	virtual void sort() = 0;
	virtual void extractPathWithScenarios(const Backtrack::PathInfo& pathInfo);

	// The item stores a node (city) name, a link (travel) type,
	// the time consuming to the next node, the departure time,
	// the cost of the travelling
	//..............................................
	//............/------\.....................
	//............|..CRL.|........................
	//............\------/..........................
	//...............|..............................
	//...............|.car 250 km...................
	//...............|..............................
	//..............................................
	struct Item {
		std::string mNameAndType; // e.g.: BUD (airplane)
		time_t  mDeparture; // e.g.: 2017-07-31 15:45+0200
		Duration  mTimeConsuming;
		double  mCost;
		Connection::Type mType;
		std::string mTimeZone;
	};

	struct Path {
	public:
		Path() : mSumPrice(0), mSumTravellingTime(0), mSumStayTime(0), mSumWaitingTime(0){}
		std::vector<Item> mItems;
		double mSumPrice;
		Duration mSumTravellingTime; // in hours
		Duration mSumStayTime; // in days
		Duration mSumWaitingTime; // in hours
		size_t mHash;
	};
	void calcStayTime();
	// the empty time between the end of the previous travel and the begin of the next one.
	void calcWaitingTime();
	std::vector<Path> mEvaluatedPaths;
	void hash();

	Backtrack& mBacktrack;
};

class SorterByTravellingCost : public Sorter {
public:
	using Sorter::Sorter;
	virtual void sort();

	static bool comparePathPrice(const Sorter::Path& path1, const Sorter::Path& path2);

private:
};

class SorterByTravellingTime : public Sorter {
public:
	using Sorter::Sorter;
	virtual void sort();

	static bool compareTravellingTime(const Sorter::Path& path, const Sorter::Path& path2);
};

class SorterByStayingTime : public Sorter {
public:
	using Sorter::Sorter;
	virtual void sort();

	static bool compareStayingTime(const Sorter::Path& path, const Sorter::Path& path2);
};

#endif