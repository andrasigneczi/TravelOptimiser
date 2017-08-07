#include "Backtrack.h"
#include <algorithm>
#include <iostream>

#define MAXPATHLENGTH 10

std::vector<Connection> Backtrack::seachTheBestWay( Context* context ) {
    mContext.reset( context );
    
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

void Backtrack::printPath( const std::vector<Backtrack::BtNode>& path ) {
	//int parkingCounter = 0;
	for (size_t i = 0; i < path.size(); ++i) {
		//const Backtrack::BtNode* btNode = &path[i];

		if (pathNodeIndex(path,i) >= 0) {
			std::cout << pathNodeName(path,i) << " ("
				<< Connection::typeToString(pathNodeLink(path,i).mType) << ")" 
				<< "\n---------------\n";
		}
		else {
			std::cout << pathNodeName(path,i) << " ("
				<< pathNodeIndex(path,i) << ")" 
				<< "\n---------------\n";
		}
	}

	std::cout << "cost (stay included): " << calcPathPrice(path) << "€" << std::endl;
	std::cout << "travelling time (except stay): " << calcPathTimeConsuming(path) << " hours" << std::endl;
	std::cout << std::string( 30, '=');
	std::cout << std::endl;
}

double Backtrack::calcPathPrice(const std::vector<Backtrack::BtNode>& path ) {
	double priece = 0;
	double fuelPricePerKm = 46. / 228. / 2.;
	for (size_t i = 0; i < path.size(); ++i) {
		if (pathNodeIndex(path,i) != -1) {
			if (pathNodeLink(path,i).mType == Connection::car)
				priece += pathNodeLink(path,i).mDistance * fuelPricePerKm;
			else if (pathNodeLink(path, i).mType == Connection::airplane || pathNodeLink(path, i).mType == Connection::bus)
				priece += pathNodeLink(path, i).mTimetable.getFirstPrice();
			else
				priece += pathNodeLink(path, i).mCost;
		}
	}
	return priece;
}

double Backtrack::calcPathTimeConsuming(const std::vector<Backtrack::BtNode>& path) {
	double sum = 0;
	for (size_t i = 0; i < path.size(); ++i) {
		if (pathNodeIndex(path,i) != -1 && pathNodeLink(path,i).mType != Connection::stay) {
			sum += pathNodeLink(path, i).mTimeConsuming;
		}
	}
	return sum;
}

bool Backtrack::comparePathPrice(const std::vector<Backtrack::BtNode>& path1, const std::vector<Backtrack::BtNode>& path2) {
	return Backtrack::calcPathPrice(path1) < Backtrack::calcPathPrice(path2);
}

bool Backtrack::compareTravellingTime(const std::vector<Backtrack::BtNode>& path1, const std::vector<Backtrack::BtNode>& path2) {
	return Backtrack::calcPathTimeConsuming(path1) < Backtrack::calcPathTimeConsuming(path2);
}

void Backtrack::printAllPaths() {

	std::cout << "results ordered by travelling cost:\n";
	sort(mMatches.begin(), mMatches.end(), comparePathPrice);
	for (size_t i = 0; i < 3 && i < mMatches.size(); ++i) {
		const auto& path = mMatches[i];
		printPath(path);
		//std::string str;
		//std::getline(std::cin, str);
	}
	std::cout << std::endl << std::endl;
	std::cout << "results ordered by travelling time:\n";
	sort(mMatches.begin(), mMatches.end(), compareTravellingTime);
	for (size_t i = 0; i < 3 && i < mMatches.size(); ++i) {
		const auto& path = mMatches[i];
		printPath(path);
		//std::string str;
		//std::getline(std::cin, str);
	}
}

void Backtrack::savePath() {
	std::vector<Backtrack::BtNode> path = mPath;
	mMatches.push_back(path);
}
