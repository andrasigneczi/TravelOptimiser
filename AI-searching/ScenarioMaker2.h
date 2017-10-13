#pragma once

#ifndef _SCENARIOMAKER2_H
#define _SCENARIOMAKER2_H

#include "ScenarioMaker.h"

class ScenarioMaker2 : public ScenarioMaker {
public:
	using ScenarioMaker::ScenarioMaker;

	void fillPathItemIndexesWithTimetable(const Backtrack::PathInfo& pathInfo) override;
	void generateOneScenario(Backtrack::PathInfo& pathInfo) override;
	bool planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario) override;
	bool planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario) override;
	bool planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario) override;
};

#endif
