#pragma once

#ifndef _SCENARIOMAKER_H
#define _SCENARIOMAKER_H

#include "Backtrack.h"

class ScenarioMaker {
public:
	ScenarioMaker(Backtrack& backtrack);
	virtual void generateAllTheScenarios();

protected:
	virtual void fillPathItemIndexesWithTimetable(const Backtrack::PathInfo& pathInfo);
	virtual void generateOneScenario(Backtrack::PathInfo& pathInfo);
	virtual bool incTimetableIndexer(const Backtrack::PathInfo& pathInfo);
	virtual bool planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario);
	virtual bool planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario);
	virtual bool planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario);

protected:
	Backtrack& mBacktrack;
	std::vector<size_t> mPathItemIndexWithTimetable; // index of the path item which has timetable values
	std::vector<size_t> mPathItemIndexWithTimetableIndexer; // index of an item in the timetable
};

#endif
