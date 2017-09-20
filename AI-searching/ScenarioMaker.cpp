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
		auto& timetable = Backtrack::pathNodeTimetable(pathInfo.mPath, mPathItemIndexWithTimetable[i]);
		auto& timetableIT = std::next(timetable.begin(), mPathItemIndexWithTimetableIndexer[i]);
		time_t t = timetableIT->first;

//		std::cout << "generateAllTheScenarios: " << timetableIT->first << "; " << Backtrack::timeToString(t) << "; price: " << timetableIT->second << std::endl;

		bool planWasOK = true;
		if (i == 0) {
//			std::cout << "debug: 0...i\n";
			// 0. timetable előtti elemek tervezése
			planWasOK &= planBackwards(pathInfo, t, mPathItemIndexWithTimetable[i] - 1, scenario);
//			std::cout << "scenariocount1: " << scenario.size() << "\n";
		}
		if (!planWasOK)
			return;

		// i. elem a timetableből jön
		scenario.push_back(t);
/*
		std::cout << "debug: " << Backtrack::pathNodeName(pathInfo.mPath, mPathItemIndexWithTimetable[i]) // source node name
			<< " (" << Connection::typeToString( Backtrack::pathNodeLink(pathInfo.mPath, mPathItemIndexWithTimetable[i]).mType )
			<< ") ==> " 
			<< Backtrack::pathNodeLink(pathInfo.mPath, mPathItemIndexWithTimetable[i]).mNode->mName // target node name
			<< " " << Backtrack::pathNodeLink(pathInfo.mPath, mPathItemIndexWithTimetable[i]).mTimeConsuming << "\n";
		std::cout << "scenariocount2: " << scenario.size() << "\n";
*/
		const CtNode::Link& ctNodeI = Backtrack::pathNodeLink(pathInfo.mPath, mPathItemIndexWithTimetable[i]);
		if(ctNodeI.mType == Connection::airplane || ctNodeI.mType == Connection::bus )
			t += (time_t)(timetableIT->second.mTimeConsuming * 60. * 60.);
		else
			t += (time_t)(ctNodeI.mTimeConsuming * 60. * 60.);

		if ( i < mPathItemIndexWithTimetable.size() - 1) {
//			std::cout << "debug: i...i+1\n";
			// i....i+1 közötti elemek tervezése
			auto& timetable2 = Backtrack::pathNodeTimetable(pathInfo.mPath, mPathItemIndexWithTimetable[i + 1]);
			auto& timetableIT2 = std::next(timetable2.begin(), mPathItemIndexWithTimetableIndexer[i + 1]);
			//time_t t2 = Backtrack::stringToTime(timetableIT2->first) + (time_t)(Backtrack::pathNodeLink(pathInfo.mPath, mPathItemIndexWithTimetableIndexer[i + 1]).mTimeConsuming * 60. * 60.);
			time_t t2 = timetableIT2->first;
			planWasOK &= planMiddle(pathInfo, t, mPathItemIndexWithTimetable[i] + 1, t2, mPathItemIndexWithTimetable[i+1] - 1, scenario);
//			std::cout << "scenariocount3: " << scenario.size() << "\n";
		}
		else if ( i == mPathItemIndexWithTimetable.size() - 1) {
//			std::cout << "debug: i...end\n";
			// utolsó timetable utáni elemek tervezése
			planWasOK &= planForwards(pathInfo, t, mPathItemIndexWithTimetable[i] + 1, scenario);
//			std::cout << "scenariocount4: " << scenario.size() << "\n";
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
		currentTime -= (time_t)(Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming * 60. * 60.);
		scenario.insert(scenario.begin(), currentTime);
	}


	return retVal;
}

bool ScenarioMaker::planForwards(Backtrack::PathInfo& pathInfo, time_t t, int firstIndex, Backtrack::Scenario& scenario) {
	bool retVal = true;

	time_t currentTime = t;
	for (int i = firstIndex; i < (int)pathInfo.mPath.size(); ++i) {
		if (Backtrack::pathNodeIndex(pathInfo.mPath, i) == -1)
			continue;

		if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::parking)
			continue;

		// time_t in seconds, time consuming in hours
		scenario.push_back(currentTime);
		currentTime += (time_t)(Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming * 60. * 60.);
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
		currentTime += (time_t)(Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming * 60. * 60.);
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
