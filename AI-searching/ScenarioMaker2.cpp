#include "ScenarioMaker2.h"

void ScenarioMaker2::fillPathItemIndexesWithTimetable(const Backtrack::PathInfo& pathInfo) {
	mPathItemIndexWithTimetable.clear();
	mPathItemIndexWithTimetableIndexer.clear();
	for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1 || Backtrack::pathNodeLink(pathInfo.mPath, i).mType != Connection::airplane)
			continue;
		const auto& timeTableMap = Backtrack::pathNodeTimetable(pathInfo.mPath, i);

		if (timeTableMap.size() > 0) {
			mPathItemIndexWithTimetable.push_back(i);
			mPathItemIndexWithTimetableIndexer.push_back(0);
		}
	}
}

void ScenarioMaker2::generateOneScenario(Backtrack::PathInfo& pathInfo) {

}

bool ScenarioMaker2::planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario) {

}

bool ScenarioMaker2::planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario) {

}

bool ScenarioMaker2::planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario) {

}
