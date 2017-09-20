#pragma once

#ifndef _SCENARIOMAKER_H
#define _SCENARIOMAKER_H

#include "Backtrack.h"

class ScenarioMaker {
public:
	ScenarioMaker(Backtrack& backtrack);
	void generateAllTheScenarios();

private:
	void fillPathItemIndexesWithTimetable(const Backtrack::PathInfo& pathInfo);
	void generateOneScenario(Backtrack::PathInfo& pathInfo);
	bool incTimetableIndexer(const Backtrack::PathInfo& pathInfo);
	bool planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario);
	bool planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario);
	bool planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario);

private:
	Backtrack& mBacktrack;
	std::vector<size_t> mPathItemIndexWithTimetable; // index of the path item which has timetable values
	std::vector<size_t> mPathItemIndexWithTimetableIndexer; // index of an item in the timetable
};

#endif
