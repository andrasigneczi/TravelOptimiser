#include "Backtrack.h"
#include <algorithm>
#include <iostream>
#include <functional>
#include <ctime>
#include <iomanip>      // std::get_time
#include <sstream> // std::istringstream
#include <time.h>
#include "ScenarioMaker.h"

#define MAXPATHLENGTH 10

std::string Backtrack::timeToString(time_t t) {
	//time_t t = time(nullptr);
	struct tm tm;
	memset(&tm, 0, sizeof(tm));
	//errno_t err = gmtime_s(&tm, &t);
	errno_t err = localtime_s(&tm, &t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %R%z");
	return oss.str();
}

time_t Backtrack::stringToTime(std::string strTime) {
	struct std::tm tm;
	memset(&tm, 0, sizeof(tm));
	//std::string strTime("2017-08-12 11:50+0300");
	std::istringstream ss(strTime);
	ss >> std::get_time(&tm, "%Y-%m-%d %R");
	size_t pos = strTime.find("+");
	int tmz = 0;
	if (pos != std::string::npos) {
		tmz = (strTime[pos + 1] - '0') * 10 + (strTime[pos + 2] - '0');
	}
	else {
		tmz = 2;
	}
	time_t t = mktime(&tm);
	t -= (tmz-1) * 60 * 60;
	//timeToString(t);
	return t;
}




std::vector<Connection> Backtrack::seachTheBestWay( Context* context ) {
    mContext.reset( context );
    
	//timeToString(time(nullptr) );
	//stringToTime();
	//return std::vector<Connection>();

    init();

    while( !mTerminated ) {
		if (isGoal())
			savePath();
		mTerminated = !genNextPath();
    }
	printAllPaths();

	std::cerr << "press enter\n";

	std::string str;
	std::getline(std::cin, str );
    return std::vector<Connection>();
}

void Backtrack::init() {
    mTerminated = true;
    // minimum a start and an end required
    if( mContext->getGoalSize() > 1 ) {
        std::string start = mContext->getGoalItem( 0 );
        const Context::CtNode* node = mContext->getNode( start );
        
        if( node->mLinks.size() > 0 ) {
            mPath.push_back(Backtrack::BtNode( node, -1 ));
            mTerminated = false;
        }
    }
}

bool Backtrack::isMatch(int pathIndex, std::string goal, Connection::Type linkType) {
	bool match = mPath[pathIndex].mCtNode->mName.compare(goal) == 0; // name is equal
	if (match && linkType != Connection::unknown && 
		mPath[pathIndex].mIndex >= 0 && linkType != mPath[pathIndex].mCtNode->mLinks[mPath[pathIndex].mIndex].mType)
		match = false;
	return match;
}

bool Backtrack::isValidPath() {
	if (mPath.size() < 3)
		return true;

	// 1) If I depart by car, I have to arrive by car
	if ((pathNodeLink(0).mType == Connection::car &&  pathNodeLink(mPath.size() - 2).mType != Connection::car) ||
		(pathNodeLink(0).mType != Connection::car &&  pathNodeLink(mPath.size() - 2).mType == Connection::car)) {
		return false;
	}

	// 2) I can use the car link type in the following cases:
	//		* between the first and the second node
	//		* in a connection following a car connection. Actually I must use it in this case.
	//		* in a connection following a parking connection.
	// 3) I can change from car to anything else, if I have a 'parking' connection.
	// 4) I can change to car only at a 'parking' connection.
	// 5) Every even parking must be the same, then the prevoius one.

	std::string parkingPlace;

#if 1
	for (size_t i = 1; i < mPath.size() - 1; ++i) {
		if (pathNodeLink(i).mType == Connection::car) {
			if (pathNodeLink(i - 1).mType != Connection::car && pathNodeLink(i - 1).mType != Connection::parking) {
//				printPath(mPath);
				return false;
			}
		}

		// car parking allowed after a car link or before a car link
		if (pathNodeLink(i).mType == Connection::parking) {
			if (parkingPlace.length() == 0) {
				parkingPlace = pathNodeName(i);
			}
			else {
				if (parkingPlace.compare(pathNodeName(i)) != 0)
					return false;
				parkingPlace = "";
			}

			if (i < mPath.size() - 1) {
				// if this link is parking, the previous or the next one must be car
				if (pathNodeLink(i - 1).mType != Connection::car && pathNodeLink(i + 1).mType != Connection::car) {
					return false;
				}
			}
			else {
				// if this link is parking, the previous one must be car
				if (pathNodeLink(i - 1).mType != Connection::car) {
					return false;
				}
			}
		}
		else {
			// if this link isn't parking, nor car, then the previos musn't be car
			if (pathNodeLink(i).mType != Connection::car && pathNodeLink(i - 1).mType == Connection::car) {
				return false;
			}
		}
	}
#endif
	return true;
}

bool Backtrack::isGoal() {
    if( mPath.size() <  mContext->getGoalSize())
        return false;
    
    int matches = 0;

	// let's check the first item, ...
	if (mPath[0].mCtNode->mName.compare(mContext->getGoalItem(0)) != 0)
		return false;

	// the last item, ...
	if (mPath[mPath.size() - 1].mCtNode->mName.compare(mContext->getLastGoalItem()) != 0)
		return false;

	if (!isValidPath())
		return false;

	// and the others
	int pathIndex = 1;
	int goalIndex = 1;
	while(pathIndex < (int)(mPath.size()) - 1 && goalIndex < (int)(mContext->getGoalSize()) - 1 ) {
        std::string goal =  mContext->getGoalItem(goalIndex);
		int separator = goal.find(":");
		Connection::Type linkType = Connection::unknown;
		if (separator != std::string::npos) {
			linkType = Connection::getType(goal.substr(separator + 1));
			goal = goal.substr(0, separator);
		}

		while (!isMatch( pathIndex, goal, linkType)) {
			++pathIndex;
			if (pathIndex == (int)mPath.size())
				return false;
		}
		++goalIndex;
		++pathIndex;
    }
	return true;
}

void Backtrack::deleteLastPathItem() {
	if (mPath.size() >= 2) {
		// before last item
		Backtrack::BtNode* btNode1 = &mPath[mPath.size() - 2];
		// last item
		Backtrack::BtNode* btNode2 = &mPath[mPath.size() - 1];

		std::string tripName = btNode1->mCtNode->mName + ":" + Connection::typeToString(btNode1->mCtNode->mLinks[btNode1->mIndex].mType) + ":" + 
			btNode2->mCtNode->mName;
		
		mInserted.erase(tripName);
	}

	mPath.erase(mPath.end() - 1);
}

bool Backtrack::genNextPath() {
	if (mPath.size() == 0) {
		return false;
	}

	if (mPath.size() == MAXPATHLENGTH) {
		// step back
		deleteLastPathItem();
		return genNextPath();
	}

	Backtrack::BtNode* btNode = &mPath[mPath.size() - 1];
	if (btNode->mCtNode->mLinks.size() > 0 && btNode->mIndex < (int)(btNode->mCtNode->mLinks.size()) - 1) {
		// step right
		btNode->mIndex += 1;
		Context::CtNode* ctNode = btNode->mCtNode->mLinks[btNode->mIndex].mNode;

		// generating the name of the from:type:to trip
		std::string tripName = btNode->mCtNode->mName + ":" + Connection::typeToString(btNode->mCtNode->mLinks[btNode->mIndex].mType) + ":" + ctNode->mName;

		// we don't want to make more than one circle, except parking
		if ( pathNodeLink(mPath.size() - 1).mType != Connection::parking && mInserted.find(tripName) != mInserted.end()) {
			return genNextPath();
		}

		mInserted.emplace(tripName);
		mPath.push_back(Backtrack::BtNode(ctNode, -1));
		return true;
	}

	// step back
	deleteLastPathItem();
	return genNextPath();
}

void Backtrack::printPath(const Backtrack::PathInfo& pathInfo) {
	for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {

		if (pathNodeIndex(pathInfo.mPath, i) >= 0) {

			std::cout << pathNodeName(pathInfo.mPath, i) << " ("
				<< Connection::typeToString(pathNodeLink(pathInfo.mPath, i).mType) << ") "
				<< "\n" << std::string(60, '-') << "\n";
		}
		else {
			std::cout << pathNodeName(pathInfo.mPath, i) << " ("
				<< pathNodeIndex(pathInfo.mPath, i) << ")"
				<< "\n" << std::string(60, '-') << "\n";
		}
	}
	std::cout << std::string(80, 'T') << std::endl;
	std::cout << std::string(80, 'T') << std::endl;


	std::cout << "cost (stay included): " << calcPathPrice(pathInfo) << "€" << std::endl;
	std::cout << "travelling time (except stay): " << calcPathTimeConsuming(pathInfo) << " hours" << std::endl;
	std::cout << std::string(30, '=');
	std::cout << std::endl;
}

void Backtrack::printPathWithScenarios(const Backtrack::PathInfo& pathInfo) {
	for (size_t scenarioIndex = 0; scenarioIndex < pathInfo.mScenarios.size(); ++scenarioIndex) {
		size_t scenarioNodeIndex = 0;
		for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {

			std::string time;
			if (pathNodeIndex(pathInfo.mPath, i) >= 0) {
				if (scenarioNodeIndex >= pathInfo.mScenarios[scenarioIndex].size()) {
					int debug = 10;
					continue;
				}
				if (pathNodeLink(pathInfo.mPath, i).mType != Connection::parking)
					time = "departure: " + timeToString(pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex]);

				std::cout << pathNodeName(pathInfo.mPath, i) << " ("
					<< Connection::typeToString(pathNodeLink(pathInfo.mPath, i).mType) << ") "
					<< time
					<< "\n" << std::string(60, '-') << "\n";
				if (pathNodeLink(pathInfo.mPath, i).mType != Connection::parking)
					++scenarioNodeIndex;
			}
			else {
				if (pathNodeLink(pathInfo.mPath, i - 1).mType != Connection::parking)
					time = "arrival: " + timeToString(pathInfo.mScenarios[scenarioIndex][scenarioNodeIndex - 1] + (time_t)(pathNodeLink(pathInfo.mPath, i - 1).mTimeConsuming * 60. * 60.));
				std::cout << pathNodeName(pathInfo.mPath, i) << " ("
					<< pathNodeIndex(pathInfo.mPath, i) << ") "
					<< time
					<< "\n" << std::string(60, '-') << "\n";
			}
		}
		std::cout << std::string(80, 'T') << std::endl;
		std::cout << std::string(80, 'T') << std::endl;
	}


	std::cout << "cost (stay included): " << calcPathPrice(pathInfo) << "€" << std::endl;
	std::cout << "travelling time (except stay): " << calcPathTimeConsuming(pathInfo) << " hours" << std::endl;
	std::cout << std::string(30, '=');
	std::cout << std::endl;
}

double Backtrack::calcPathPrice(const Backtrack::PathInfo& pathInfo ) {
	double priece = 0;
	double fuelPricePerKm = 46. / 228. / 2.;
	for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {
		if (pathNodeIndex(pathInfo.mPath,i) != -1) {
			if (pathNodeLink(pathInfo.mPath,i).mType == Connection::car)
				priece += pathNodeLink(pathInfo.mPath,i).mDistance * fuelPricePerKm;
			else if (pathNodeLink(pathInfo.mPath, i).mType == Connection::airplane || pathNodeLink(pathInfo.mPath, i).mType == Connection::bus)
				priece += pathNodeLink(pathInfo.mPath, i).mTimetable.getFirstPrice();
			else
				priece += pathNodeLink(pathInfo.mPath, i).mCost;
		}
	}
	return priece;
}

double Backtrack::calcPathTimeConsuming(const Backtrack::PathInfo& pathInfo) {
	double sum = 0;
	for (size_t i = 0; i < pathInfo.mPath.size(); ++i) {
		if (pathNodeIndex(pathInfo.mPath,i) != -1 && pathNodeLink(pathInfo.mPath,i).mType != Connection::stay) {
			sum += pathNodeLink(pathInfo.mPath, i).mTimeConsuming;
		}
	}
	return sum;
}

bool Backtrack::comparePathPrice(const Backtrack::PathInfo& pathInfo1, const Backtrack::PathInfo& pathInfo2) {
	return pathInfo1.mSumPrice < pathInfo2.mSumPrice;
}

bool Backtrack::compareTravellingTime(const Backtrack::PathInfo& pathInfo1, const Backtrack::PathInfo& pathInfo2) {
	return pathInfo1.mSumTime < pathInfo2.mSumTime;
}

void Backtrack::printAllPaths() {

	for (size_t i = 0; i < mMatches.size(); ++i) {
		mMatches[i].mSumPrice = Backtrack::calcPathPrice(mMatches[i]);
		mMatches[i].mSumTime = Backtrack::calcPathTimeConsuming(mMatches[i]);
	}

	ScenarioMaker scenarioMaker(*this);
	std::cout << "results ordered by travelling cost:\n";
	sort(mMatches.begin(), mMatches.end(), comparePathPrice);
	scenarioMaker.generateAllTheScenarios();
	for (size_t i = 0; i < 3 && i < mMatches.size(); ++i) {
		const auto& pathInfo = mMatches[i];
		//printPath(pathInfo);
		printPathWithScenarios(pathInfo);
	}
	std::cout << std::endl << std::endl;
	std::cout << "results ordered by travelling time:\n";
	sort(mMatches.begin(), mMatches.end(), compareTravellingTime);
	scenarioMaker.generateAllTheScenarios();
	for (size_t i = 0; i < 3 && i < mMatches.size(); ++i) {
		const auto& pathInfo = mMatches[i];
		printPath(pathInfo);
		printPathWithScenarios(pathInfo);
	}
}

void Backtrack::savePath() {
	PathInfo pathInfo;
	pathInfo.mPath = mPath;
	pathInfo.mHash = genHash(pathInfo.mPath);
	mMatches.push_back(pathInfo);
}

const size_t Backtrack::genHash(const std::vector<Backtrack::BtNode>& path) {
	std::string hashStr;
	for (size_t i = 0; i < path.size(); ++i) {
		hashStr += path[i].mCtNode->mName;
	}
	return std::hash<std::string>()(hashStr);
}
