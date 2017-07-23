#include "Backtrack.h"
#include <algorithm>
#include <iostream>

#define MAXPATHLENGTH 8

std::vector<Connection> Backtrack::seachTheBestWay( Context* context ) {
    mContext.reset( context );
    
    init();

    while( !mTerminated ) {
		if (isGoal())
			savePath();
		mTerminated = !genNextPath();
    }
	printAllPaths();

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
		Backtrack::BtNode* btNode1 = &mPath[mPath.size() - 2];
		Backtrack::BtNode* btNode2 = &mPath[mPath.size() - 1];

		std::string tripName = btNode1->mCtNode->mName + ":" + Connection::typeToString(btNode1->mCtNode->mLinks[btNode1->mIndex].mType) + ":" + 
			btNode2->mCtNode->mName;
		
		mInserted.erase(tripName);
	}

	mPath.erase(mPath.end() - 1);
}

bool Backtrack::genNextPath() {
	// I have to handle the car parking

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

		// generating the name of the from-type-to trip
		std::string tripName = btNode->mCtNode->mName + ":" + Connection::typeToString(btNode->mCtNode->mLinks[btNode->mIndex].mType) + ":" + ctNode->mName;

		if ( mInserted.find(tripName) != mInserted.end()) {
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
	for (size_t i = 0; i < path.size(); ++i) {
		const Backtrack::BtNode* btNode = &path[i];

		if (btNode->mIndex >= 0) {
			std::cout << btNode->mCtNode->mName << " ("
				<< Connection::typeToString(btNode->mCtNode->mLinks[btNode->mIndex].mType) << ")" 
				<< "\n---------------\n";
		}
		else {
			std::cout << btNode->mCtNode->mName << " ("
				<< btNode->mIndex << ")" 
				<< "\n---------------\n";
		}
	}

	std::cout << std::string( 30, '=');
	std::cout << std::endl;
}

void Backtrack::printAllPaths() {
	for (const auto& path : mMatches ) {
		printPath(path);
		std::string str;
		std::getline(std::cin, str);
	}
}

void Backtrack::savePath() {
	std::vector<Backtrack::BtNode> path = mPath;
	mMatches.push_back(path);
}
