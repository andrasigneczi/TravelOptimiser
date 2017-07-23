#include "Backtrack.h"
#include <algorithm>
#include <iostream>

std::vector<Connection> Backtrack::seachTheBestWay( Context* context ) {
    mContext.reset( context );
    
    init();
	printPath();
    while( !mTerminated && !isGoal()) {
		mTerminated = !genNextPath();
		printPath();
    }

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
		while (mPath[pathIndex].mCtNode->mName.compare(goal) != 0) {
			++pathIndex;
			if (pathIndex == (int)mPath.size())
				return false;
		}
		++goalIndex;
		++pathIndex;
    }
	return true;
}

bool Backtrack::checkIfAlreadyInserted(const Context::CtNode* ctNode, int index ) {
	for (size_t i = 0; i < mPath.size(); ++i) {
		if (mPath[i].mCtNode == ctNode && mPath[i].mIndex <= index) {
			return true;
		}
	}
	return false;
}

bool Backtrack::genNextPath() {
	if (mPath.size() == 0) {
		return false;
	}

	Backtrack::BtNode* btNode = &mPath[mPath.size() - 1];
	if (btNode->mCtNode->mLinks.size() > 0 && btNode->mIndex < (int)(btNode->mCtNode->mLinks.size()) - 1) {
		// step right
		btNode->mIndex += 1;
		Context::CtNode* ctNode = btNode->mCtNode->mLinks[btNode->mIndex].mNode;
		if (checkIfAlreadyInserted(ctNode, btNode->mIndex)) {
			return genNextPath();
		}
		mPath.push_back(Backtrack::BtNode(ctNode, -1));
		return true;
	}

	// step back
	mPath.erase(mPath.end() - 1);
	return genNextPath();
}
/*
bool Backtrack::genNextPath() {
	Backtrack::BtNode* btNode = &mPath[mPath.size() - 1];
	if (btNode->mCtNode->mLinks.size() > 0) {
		btNode->mIndex += 1;
		Context::CtNode* ctNode = btNode->mCtNode->mLinks[btNode->mIndex].mNode;
		mPath.push_back(Backtrack::BtNode(ctNode, -1));
		return true;
	} 

	while (true) {
		// step back and ...
		mPath.erase(mPath.end() - 1);

		if (mPath.size() == 0)
			return false;

		// step right
		btNode = &mPath[mPath.size() - 1];
		if (btNode->mIndex < btNode->mCtNode->mLinks.size() - 1) {
			btNode->mIndex += 1;
			Context::CtNode* ctNode = btNode->mCtNode->mLinks[btNode->mIndex].mNode;
			mPath.push_back(Backtrack::BtNode(ctNode, -1));
			break;
		}
	}

	return true;
}
*/

void Backtrack::printPath() {
	for (size_t i = 0; i < mPath.size(); ++i) {
		Backtrack::BtNode* btNode = &mPath[i];
		std::cout << btNode->mCtNode->mName << " (" << btNode->mIndex << ")" << "\n---------------\n";
	}

	std::cout << std::string( 30, '=');
	std::cout << std::endl;
}