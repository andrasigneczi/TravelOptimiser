#include "Sorters.h"
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <sstream> // std::ostringstream

void Sorter::printMathes( int count ) {
	for (size_t i = 0; i < mBacktrack.getMatches().size(); ++i) {
		const auto& pathInfo = mBacktrack.getMatches()[i];
		//printPath(pathInfo);
		if (pathInfo.mScenarios.size() > 0) {
			//printPathWithScenarios(pathInfo);
			extractPathWithScenarios(pathInfo);
		}
	}
	sort();

	double maxSpentTime = mBacktrack.getContext()->getMaxSpentTime().getHour();
	double maxStayTime = mBacktrack.getContext()->getMaxStayingTime().getDay();
	double minStayTime = mBacktrack.getContext()->getMinStayingTime().getDay();
	double maxWaitingTime = mBacktrack.getContext()->getMaxWaitingTime().getHour();
	double maxTravellingTime = mBacktrack.getContext()->getTravellingTime().getHour();

	int i = 0;
	for (const Path& path : mEvaluatedPaths) {
		if (i == count)
			break;

		Duration timeSpent = path.mSumTravellingTime + path.mSumStayTime;
		if (maxSpentTime > 0.0 && timeSpent.getHour() > maxSpentTime)
			continue;
		bool valid = true;
		std::ostringstream oneResult;
		for (const Item& item : path.mItems) {
			oneResult << item.mNameAndType;
			if (item.mType != Connection::parking)
				oneResult << "departure: " << Backtrack::timeToString(item.mDeparture, item.mTimeZone);
			oneResult << std::endl;

			if (item.mType == Connection::stay) {

				if (maxStayTime > 0.001 && item.mTimeConsuming.getDay() > maxStayTime) {
					valid = false;
					break;
				}

				if (minStayTime > 0.001 && item.mTimeConsuming.getDay() < minStayTime) {
					valid = false;
					break;
				}

				oneResult << "staying time: " << item.mTimeConsuming.getDay() << " days" << std::endl;
			}
			oneResult << std::string(80, '-') << std::endl;
		}

		if (maxWaitingTime > 0.001 && path.mSumWaitingTime.getHour() > maxWaitingTime) {
			valid = false;
		}
		if (maxTravellingTime > 0.001 && path.mSumTravellingTime.getHour() > maxTravellingTime) {
			valid = false;
		}
		oneResult << "cost (stay included): " << path.mSumPrice << "�" << std::endl;
		oneResult << "travelling time (except stay): " << path.mSumTravellingTime.getHour() << " hours" << std::endl;
		oneResult << "waiting time: " << path.mSumWaitingTime.getHour() << " hours" << std::endl;
		oneResult << "full time consuming: " << timeSpent.getHour() << " hours \n";
		oneResult << "hash: " << path.mHash << std::endl;
		oneResult << std::string(80, '-') << std::endl;
		oneResult << std::string(100, '=') << std::endl;

		if (valid) {
			std::cout << oneResult.str();
		}
		++i;
	}
}

void Sorter::extractPathWithScenarios(const Backtrack::PathInfo& pathInfo) {
	const double fuelPricePerKm = 46. / 228. / 2.;
	for (size_t scenarioIndex = 0; scenarioIndex < pathInfo.mScenarios.size(); ++scenarioIndex) {
		size_t scenarioNodeIndex = 0;
		Path path;
		for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {
			Item pathItem;
			
			if (Backtrack::pathNodeIndex(pathInfo.mPath, i) >= 0) {
				const CtNode::Link& nodeLink = Backtrack::pathNodeLink(pathInfo.mPath, i);
				assert(scenarioNodeIndex < pathInfo.mScenarios[scenarioIndex].size());
				if (nodeLink.mType != Connection::parking)
					pathItem.mDeparture = pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex];

				pathItem.mType = nodeLink.mType;
				pathItem.mTimeZone = pathInfo.mPath[i].mCtNode->mTimeZone;
				pathItem.mNameAndType = Backtrack::pathNodeName(pathInfo.mPath, i) + " ("
					+ Connection::typeToString(pathItem.mType) + ") ";
					
				if (nodeLink.mType != Connection::parking)
					++scenarioNodeIndex;

				if (nodeLink.mType == Connection::car)
					path.mSumPrice += nodeLink.mDistance * fuelPricePerKm;
				else if (nodeLink.mType == Connection::airplane || nodeLink.mType == Connection::bus)
					path.mSumPrice += nodeLink.mTimetable.getPrice(pathItem.mDeparture);
				else
					path.mSumPrice += nodeLink.mCost;

				if (nodeLink.mType != Connection::stay && nodeLink.mType != Connection::parking) {
					if (nodeLink.mType == Connection::airplane || nodeLink.mType == Connection::bus) {
						pathItem.mTimeConsuming = nodeLink.mTimetable.getTimeConsuming(pathItem.mDeparture);
						path.mSumTravellingTime += pathItem.mTimeConsuming;
					}
					else {
						pathItem.mTimeConsuming = nodeLink.mTimeConsuming;
						path.mSumTravellingTime += nodeLink.mTimeConsuming;
					}
					assert(pathItem.mTimeConsuming.getSec() >= 0);
				}
			}
			else {
				if (Backtrack::pathNodeLink(pathInfo.mPath, i - 1).mType != Connection::parking) {
					pathItem.mDeparture = pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex];
				}
				pathItem.mNameAndType = Backtrack::pathNodeName(pathInfo.mPath, i) + " ("
					+ std::to_string( Backtrack::pathNodeIndex(pathInfo.mPath, i)) + ") ";
				pathItem.mTimeZone = pathInfo.mPath[i].mCtNode->mTimeZone;
			}
			path.mItems.push_back(pathItem);
		}
		mEvaluatedPaths.push_back(path);
	}
	hash();
	calcStayTime();
	calcWaitingTime();
}

// calculate the stay time in days
void Sorter::calcStayTime() {
	for (Path& path : mEvaluatedPaths) {
		Duration sumStayTime;
		for (auto it = path.mItems.begin(); it != path.mItems.end(); ++it ) {
			auto next = std::next(it, 1);
			if (it->mType == Connection::stay && next != path.mItems.end()) {
				// calculated in days
				it->mTimeConsuming = ((double)next->mDeparture - it->mDeparture) / 3600.0 / 24.0;
				assert(it->mTimeConsuming.getSec() >= 0);
				sumStayTime += it->mTimeConsuming;
			}
		}
		path.mSumStayTime = sumStayTime;
	}
}

void Sorter::calcWaitingTime() {
	for (Path& path : mEvaluatedPaths) {
		double sumWaitingTime = 0.0;
		for (auto it = path.mItems.begin(); it != path.mItems.end(); ++it) {
			auto next = std::next(it, 1);
			if (next != path.mItems.end() && it->mType != Connection::parking && next->mType != Connection::parking) {
				// calculated in hours
				double timeConsuming = it->mTimeConsuming.getHour();
				//if (it->mType == Connection::stay)
				//	timeConsuming *= 24.0;
				assert(timeConsuming > 0.0);
				double waitingTime = ((double)(next->mDeparture - it->mDeparture)) / 3600.0 - timeConsuming;
				assert(waitingTime >= -0.00001);
				if(waitingTime > 0.0 )
					sumWaitingTime += waitingTime;
			}
		}
		path.mSumWaitingTime = sumWaitingTime;
	}
}

void Sorter::hash() {
	for (Path& path : mEvaluatedPaths) {
		std::string hashStr;
		for (auto it = path.mItems.begin(); it != path.mItems.end(); ++it) {
			hashStr += it->mNameAndType + std::to_string( it->mDeparture );
		}
		path.mHash = std::hash<std::string>()(hashStr);
	}
}

bool SorterByTravellingCost::comparePathPrice(const Sorter::Path& path1, const Sorter::Path& path2) {
	// First point of view
	if (path1.mSumPrice != path2.mSumPrice)
		return path1.mSumPrice < path2.mSumPrice;

	// Second point of view
	if (path1.mSumWaitingTime != path2.mSumWaitingTime)
		return path1.mSumWaitingTime < path2.mSumWaitingTime;

	// Third point of view
	if (path1.mSumStayTime != path2.mSumStayTime)
		return path1.mSumStayTime > path2.mSumStayTime;

	// Fourth point of view
	return path1.mSumTravellingTime < path2.mSumTravellingTime;
}

bool SorterByTravellingTime::compareTravellingTime(const Sorter::Path& path1, const Sorter::Path& path2) {
	if (path1.mSumTravellingTime != path2.mSumTravellingTime)
		return path1.mSumTravellingTime < path2.mSumTravellingTime;

	if (path1.mSumWaitingTime != path2.mSumWaitingTime)
		return path1.mSumWaitingTime < path2.mSumWaitingTime;

	if (path1.mSumStayTime != path2.mSumStayTime)
		return path1.mSumStayTime > path2.mSumStayTime;

	return path1.mSumPrice < path2.mSumPrice;
}

bool SorterByStayingTime::compareStayingTime(const Sorter::Path& path1, const Sorter::Path& path2) {
	if (path1.mSumStayTime != path2.mSumStayTime)
		return path1.mSumStayTime > path2.mSumStayTime;

	if (path1.mSumWaitingTime != path2.mSumWaitingTime)
		return path1.mSumWaitingTime < path2.mSumWaitingTime;

	if (path1.mSumTravellingTime != path2.mSumTravellingTime)
		return path1.mSumTravellingTime < path2.mSumTravellingTime;

	return path1.mSumPrice < path2.mSumPrice;
}

void SorterByTravellingCost::sort() {
	std::sort(mEvaluatedPaths.begin(), mEvaluatedPaths.end(), comparePathPrice);
}

void SorterByTravellingTime::sort() {
	std::sort(mEvaluatedPaths.begin(), mEvaluatedPaths.end(), compareTravellingTime);
}

void SorterByStayingTime::sort() {
	std::sort(mEvaluatedPaths.begin(), mEvaluatedPaths.end(), compareStayingTime);
}
