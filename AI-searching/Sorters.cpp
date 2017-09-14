#include "Sorters.h"
#include <iostream>
#include <assert.h>
#include <algorithm>

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
	int i = 0;
	for (const Path& path : mEvaluatedPaths) {
		if (i == count)
			break;
		for (const Item& item : path.mItems) {
			std::cout << item.mNameAndType;
			if (item.mType != Connection::parking)
				std::cout << "departure: " << Backtrack::timeToString(item.mDeparture, item.mTimeZone);
			std::cout << std::endl;
			if (item.mType == Connection::stay)
				std::cout << "staying time: " << item.mTimeConsuming << " days" << std::endl;
			std::cout << std::string(80, '-') << std::endl;
		}
		std::cout << "cost (stay included): " << path.mSumPrice << "€" << std::endl;
		std::cout << "travelling time (except stay): " << path.mSumTravellingTime << " hours" << std::endl;
		std::cout << std::string(80, '-') << std::endl;
		std::cout << std::string(100, '=') << std::endl;
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
				assert(scenarioNodeIndex < pathInfo.mScenarios[scenarioIndex].size());
				if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType != Connection::parking)
					pathItem.mDeparture = pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex];

				pathItem.mType = Backtrack::pathNodeLink(pathInfo.mPath, i).mType;
				pathItem.mTimeZone = pathInfo.mPath[i].mCtNode->mTimeZone;
				pathItem.mNameAndType = Backtrack::pathNodeName(pathInfo.mPath, i) + " ("
					+ Connection::typeToString(pathItem.mType) + ") ";
					
				if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType != Connection::parking)
					++scenarioNodeIndex;

				if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::car)
					path.mSumPrice += Backtrack::pathNodeLink(pathInfo.mPath, i).mDistance * fuelPricePerKm;
				else if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::airplane || Backtrack::pathNodeLink(pathInfo.mPath, i).mType == Connection::bus)
					path.mSumPrice += Backtrack::pathNodeLink(pathInfo.mPath, i).mTimetable.getPrice(pathItem.mDeparture);
				else
					path.mSumPrice += Backtrack::pathNodeLink(pathInfo.mPath, i).mCost;

				if (Backtrack::pathNodeLink(pathInfo.mPath, i).mType != Connection::stay) {
					path.mSumTravellingTime += Backtrack::pathNodeLink(pathInfo.mPath, i).mTimeConsuming;
				}
			}
			else {
				if (Backtrack::pathNodeLink(pathInfo.mPath, i - 1).mType != Connection::parking)
					pathItem.mDeparture = pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex - 1] + (time_t)(Backtrack::pathNodeLink(pathInfo.mPath, i - 1).mTimeConsuming * 60. * 60.);
				pathItem.mNameAndType = Backtrack::pathNodeName(pathInfo.mPath, i) + " ("
					+ std::to_string( Backtrack::pathNodeIndex(pathInfo.mPath, i)) + ") ";
				pathItem.mTimeZone = pathInfo.mPath[i].mCtNode->mTimeZone;
			}
			path.mItems.push_back(pathItem);
		}
		mEvaluatedPaths.push_back(path);
	}
	calcStayTime();
}

void Sorter::calcStayTime() {
	for (Path& path : mEvaluatedPaths) {
		double sumStayTime = 0;
		for (auto it = path.mItems.begin(); it != path.mItems.end(); ++it ) {
			if ((*it).mType == Connection::stay) {
				if (it != path.mItems.end()) {
					auto next = std::next(it, 1);
					// calculated in days
					it->mTimeConsuming = ((double)next->mDeparture - it->mDeparture) / 3600.0 / 24.0;
					sumStayTime += it->mTimeConsuming;
				}
			}
		}
		path.mSumStayTime = sumStayTime;
	}
}

bool SorterByTravellingCost::comparePathPrice(const Sorter::Path& path1, const Sorter::Path& path2) {
	if (path1.mSumPrice == path2.mSumPrice)
		return path1.mSumStayTime > path2.mSumStayTime;
	return path1.mSumPrice < path2.mSumPrice;
}

bool SorterByTravellingTime::compareTravellingTime(const Sorter::Path& path1, const Sorter::Path& path2) {
	if (path1.mSumPrice == path2.mSumPrice)
		return path1.mSumStayTime > path2.mSumStayTime;
	return path1.mSumTravellingTime < path2.mSumTravellingTime;
}

void SorterByTravellingCost::sort() {
	std::sort(mEvaluatedPaths.begin(), mEvaluatedPaths.end(), comparePathPrice);
}

void SorterByTravellingTime::sort() {
	std::sort(mEvaluatedPaths.begin(), mEvaluatedPaths.end(), compareTravellingTime);
}
