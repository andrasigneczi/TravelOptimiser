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
		std::string mNameAndType;
		time_t  mDeparture;
		double  mTimeConsuming; // in hour
		double  mCost;
		//Connection::Type mType;
	};

	struct Path {
	public:
		std::vector<Item> mItems;
		double mSumPrice;
		double mSumTime;
	};

	std::vector<Path> mEvaluatedPaths;

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

#endif