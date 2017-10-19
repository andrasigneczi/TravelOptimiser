#include "ScenarioMaker.h"
#include <iostream>
#include <assert.h>

/*
Igel (car)
------------------------------------------------------------
Luxembourg (car)
------------------------------------------------------------
CRL (parking)
------------------------------------------------------------
CRL (airplane)
------------------------------------------------------------
BUD (stay)
------------------------------------------------------------
BUD (airplane)
------------------------------------------------------------
CRL (parking)
------------------------------------------------------------
CRL (car)
------------------------------------------------------------
Luxembourg (car)
------------------------------------------------------------
Igel (-1)
------------------------------------------------------------

*/

ScenarioMaker::ScenarioMaker(Backtrack& backtrack)
: mBacktrack( backtrack )
{

}

void ScenarioMaker::generateAllTheScenarios() {
	for (size_t i = 0; /*i < 3 &&*/ i < mBacktrack.getMatches().size(); ++i) {
		auto& pathInfo = mBacktrack.getMatches()[i];
		pathInfo.mScenarios.clear();
		fillPathItemIndexesWithTimetable(pathInfo);
		do {
			generateOneScenario(pathInfo);
		} while (incTimetableIndexer(pathInfo));
	}
}

void ScenarioMaker::fillPathItemIndexesWithTimetable(const Backtrack::PathInfo& pathInfo) {
	mPathItemIndexWithTimetable.clear();
	mPathItemIndexWithTimetableIndexer.clear();
	for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1)
			continue;
		const auto& timeTableMap = Backtrack::pathNodeTimetable(pathInfo.mPath, i);

		if (timeTableMap.size() > 0 ) {
			mPathItemIndexWithTimetable.push_back(i);
			mPathItemIndexWithTimetableIndexer.push_back(0);
		}
	}
}

void ScenarioMaker::generateOneScenario(Backtrack::PathInfo& pathInfo) {

	if (mPathItemIndexWithTimetableIndexer.size() == 0) {
		return;
	}

	Backtrack::Scenario scenario;

	for (size_t i = 0; i < mPathItemIndexWithTimetable.size(); ++i) {
		
		// The index of the node with timetable
		const int timetableIndex_1 = mPathItemIndexWithTimetable[i];
		// The index of the item in the timetable of node indexed with timetableIndex_1.
		const int timetableIndexer_1 = mPathItemIndexWithTimetableIndexer[i];

		auto& timetable = Backtrack::pathNodeTimetable(pathInfo.mPath, timetableIndex_1);
		auto timetableIT = std::next(timetable.begin(), timetableIndexer_1);
		time_t t = timetableIT->first;

		bool planWasOK = true;
		if (i == 0) {
			// 0. timetable előtti elemek tervezése
			planWasOK &= planBackwards(pathInfo, t, timetableIndex_1 - 1, scenario);
		}
		if (!planWasOK)
			return;

		// i. elem a timetableből jön
		scenario.push_back(t);
		const CtNode::Link& ctNodeI = Backtrack::pathNodeLink(pathInfo.mPath, timetableIndex_1);
		if(ctNodeI.mType == Connection::airplane || ctNodeI.mType == Connection::bus )
			t += timetableIT->second.mTimeConsuming;
		else
			t += ctNodeI.mTimeConsuming.getSec();

		if ( i < mPathItemIndexWithTimetable.size() - 1) {
			// i....i+1 közötti elemek tervezése
			// mi van, ha nincs köztük más elem?

			const int timetableIndex_2 = mPathItemIndexWithTimetable[i + 1];
			const int timetableIndexer_2 = mPathItemIndexWithTimetableIndexer[i + 1];

			auto& timetable2 = Backtrack::pathNodeTimetable(pathInfo.mPath, timetableIndex_2);
			auto timetableIT2 = std::next(timetable2.begin(), timetableIndexer_2);
			time_t t2 = timetableIT2->first;
			planWasOK &= planMiddle(pathInfo, t, timetableIndex_1 + 1, t2, timetableIndex_2 - 1, scenario);
		}
		else if ( i == mPathItemIndexWithTimetable.size() - 1) {
			// utolsó timetable utáni elemek tervezése
			planWasOK &= planForwards(pathInfo, t, timetableIndex_1 + 1, scenario);
		}

		if (!planWasOK)
			return;
	}
	pathInfo.mScenarios.push_back(scenario);
}

bool ScenarioMaker::planBackwards(Backtrack::PathInfo& pathInfo, time_t t, int lastIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;
	time_t currentTime = t;
	for (int i = lastIndex; i >= 0; --i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1)
			continue;

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		// time_t in seconds, time consuming in hours
		currentTime -= Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming.getSec();
		scenario.insert(scenario.begin(), currentTime);
	}


	return retVal;
}

bool ScenarioMaker::planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;

	time_t currentTime = t;
	for (int i = firstIndex; i < (int)pathInfo.mPath.size(); ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1) {
			scenario.push_back(currentTime);
			continue;
		}

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		// time_t in seconds, time consuming in hours
		scenario.push_back(currentTime);
		currentTime += Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming.getSec();
	}

	return retVal;
}

bool ScenarioMaker::planMiddle(Backtrack::PathInfo& pathInfo, time_t t1, int firstIndex, time_t t2, int lastIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;

	time_t currentTime = t1;
	for (int i = firstIndex; i <= lastIndex; ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1)
			continue;

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		const auto& timeTableMap = Backtrack::pathNodeTimetable(pathInfo.mPath, i);
		assert(timeTableMap.size() == 0);

		scenario.push_back(currentTime);
		currentTime += Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming.getSec();
	}
	
	if (currentTime > t2)
		retVal = false;
	return retVal;
}

bool ScenarioMaker::incTimetableIndexer(const Backtrack::PathInfo& pathInfo) {
	size_t actPos = 0;
	bool retVal = false;
	while (actPos < mPathItemIndexWithTimetable.size()) {
		++mPathItemIndexWithTimetableIndexer[actPos];
		const auto& timeTableMap = Backtrack::pathNodeTimetable(pathInfo.mPath, mPathItemIndexWithTimetable[actPos]);
		if (timeTableMap.size() <= mPathItemIndexWithTimetableIndexer[actPos]) {
			mPathItemIndexWithTimetableIndexer[actPos] = 0;
			++actPos;
		}
		else {
			retVal = true;
			break;
		}
	}
	return retVal;
}
