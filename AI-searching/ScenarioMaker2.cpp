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

bool ScenarioMaker2::planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;
	time_t currentTime = t;
	for (int i = lastIndex; i >= 0; --i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1)
			continue;

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		const auto& timeTable = Backtrack::pathNodeLink(pathInfo.mPath, i).mTimetable;
		if(timeTable.getTimetable().size() > 0) {
			time_t t = timeTable.searchLessBeginningPlusTimeConsuming(currentTime);
			if (t == 0) {
				retVal = false;
				break;
			}
		    currentTime = t;
		} else {
    		// time_t in seconds, time consuming in hours
    		currentTime -= Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming.getSec();
		}
		scenario.insert(scenario.begin(), currentTime);
	}
	return retVal;
}

bool ScenarioMaker2::planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;

	time_t currentTime = t;
	for (int i = firstIndex; i < (int)pathInfo.mPath.size(); ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1) {
			// The last item
			scenario.push_back(currentTime);
			continue;
		}

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		const auto& timeTable = Backtrack::pathNodeLink(pathInfo.mPath, i).mTimetable;
		
		if(timeTable.getTimetable().size() > 0) {
			std::pair<time_t, time_t> retv = timeTable.searchGreaterBeginning( currentTime );
			if (retv.first == 0) {
				retVal = false;
				break;
			}
		    scenario.push_back(retv.first);
		    currentTime = retv.first + retv.second;
		} else {
    		// time_t in seconds, time consuming in hours
    		scenario.push_back(currentTime);
    		currentTime += Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming.getSec();
		}
	}

	return retVal;
}

bool ScenarioMaker2::planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;

	time_t currentTimeFw = t1;
	time_t currentTimeBw = t2;
	// Let's plan forwards and backwards at the same time
	int fw = firstIndex;
	int bw = lastIndex;
	Backtrack::Scenario bwScenario;
	while( fw <= bw) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, fw) == -1 || Backtrack::pathNodeLink(pathInfo.mPath, fw).mType == Connection::parking) {
			++fw;
			continue;
		}
		if (Backtrack::pathNodeIndex(pathInfo.mPath, bw) == -1 || Backtrack::pathNodeLink(pathInfo.mPath, bw).mType == Connection::parking) {
			--bw;
			continue;
		}

		const auto& timeTableFw = Backtrack::pathNodeLink(pathInfo.mPath, fw).mTimetable;

		if (timeTableFw.getTimetable().size() > 0) {
			std::pair<time_t, time_t> retv = timeTableFw.searchGreaterBeginning(currentTimeFw);
			if (retv.first == 0) {
				return false;
			}
			scenario.push_back(retv.first);
			currentTimeFw = retv.first + retv.second;
		}
		else {
			scenario.push_back(currentTimeFw);
			currentTimeFw += Backtrack::pathNodeLink(pathInfo.mPath, fw).mTimeConsuming.getSec();
		}

		if (bw-fw>0) {
			const auto& timeTableBw = Backtrack::pathNodeLink(pathInfo.mPath, bw).mTimetable;
			if (timeTableBw.getTimetable().size() > 0) {
				time_t t = timeTableBw.searchLessBeginningPlusTimeConsuming(currentTimeBw);
				if (t == 0) {
					return false;
				}
				currentTimeBw = t;
			}
			else {
				// time_t in seconds, time consuming in hours
				currentTimeBw -= Backtrack::pathNodeLink(pathInfo.mPath, bw).mTimeConsuming.getSec();
			}
			bwScenario.insert(bwScenario.begin(), currentTimeBw);
		}
		++fw;
		--bw;
	}
	
	if (currentTimeFw > currentTimeBw)
		return false;

	for (auto t : bwScenario) {
		scenario.push_back(t);
	}
	return retVal;
}
