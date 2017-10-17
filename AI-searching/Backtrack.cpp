#include "Backtrack.h"
#include <algorithm>
#include <iostream>
#include <functional>
#include <ctime>
#include <iomanip>      // std::get_time
#include <sstream> // std::istringstream
#include <time.h>
#include "ScenarioMaker2.h"
#include <assert.h>
#include "Sorters.h"
#include <string.h>
#include <stddef.h>

#ifdef __LINUX__
typedef int errno_t;

namespace std {
	
	struct __unspecified { 
		operator char*() {
			return nullptr;
		}
		
		operator bool&() {
			return b;
		}
		
		bool b;
		std::tm* tmb;
		const char* fmt;
	};
	
	std::string put_time( struct tm* tm, const char* format ) {
		char foo[124];
	
		if(0 < strftime(foo, sizeof(foo), format, tm))
			return std::string( foo );
		std::cerr << "Something went wrong1\n";
		return std::string();
	}
	
	template< class CharT >
	__unspecified get_time( std::tm* tmb, const CharT* fmt ) {
          __unspecified ret;
          ret.fmt = fmt;
          ret.tmb = tmb;
          return ret;
	}
	
	std::istringstream& operator>>( std::istringstream& in, __unspecified un ) {
		char buff[256];
		in.getline(buff, 256);
		
          if(strptime(buff, un.fmt, un.tmb) == NULL) {
          	std::cerr << "Something went wrong2: " << buff << " " << un.fmt << std::endl;
          }
		
		//std::cerr << v << std::endl;
		return in;
	}
	
}

	errno_t gmtime_s(struct tm *result,const time_t *timep) {
		if( gmtime_r(timep, result) != nullptr )
			return 0;
		return 1;
	}
#endif

std::vector<Connection> Backtrack::seachTheBestWay( Context* context ) {
    mContext.reset( context );
    
	//timeToString(time(nullptr) );
	//stringToTime();
	//return std::vector<Connection>();

    init();

    while( !mTerminated ) {
		if (isGoal(context))
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
        const CtNode* node = mContext->getNode( start );
        
        if( node->mLinks.size() > 0 ) {
            mPath.push_back(Backtrack::BtNode( node, -1 ));
            mTerminated = false;
        }
    }
}

bool Backtrack::isMatch(const Path& path, int pathIndex, std::string goal, Connection::Type linkType) {
	bool match = path[pathIndex].mCtNode->mName.compare(goal) == 0; // name is equal
	if (match && linkType != Connection::unknown && 
		path[pathIndex].mIndex >= 0 && linkType != path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex].mType)
		match = false;
	return match;
}

bool Backtrack::isMinimal(const Path& path, Context* context, int level /*= 0*/) {
	// I want to remove those path which contains unnecessary ways, e.g.: Igel, Luxembourg, HHN, .... Luxembourg is useless here.
/*
	size_t h = genHash(path);
	if (h == 339287363) {
		int debug = 10;
	}
*/
	// If a path is goal, and it remains being a goal after I removed a node, then this path isn't minimal, it is invalid.
#if 1
	for (size_t i = 1; i < path.size() - 1; ++i) {
		Path newPath = genPathWithoutOneItem(path, i);
		if (newPath.size() == 0)
			continue;
		if (checkGoalCondition(newPath, context)) {
			/*
			std::cout << "The following path isn't minimal:\n";
			printPath(path);
			std::cout << "Hash: " << h << std::endl;
			*/
			return false;
		}
		if (level == 0 && !isMinimal(newPath, context, level + 1)) {
			/*
			std::cout << "The following path isn't minimal:\n";
			printPath(path);
			std::cout << "Hash: " << h << std::endl;
			*/
			return false;
		}
	}
#endif
	return true;
}

Backtrack::Path Backtrack::genPathWithoutOneItem(const Path& path, size_t index) {
	Path newPath;
	for (size_t i = 0; i < path.size(); ++i) {
		if (index == i) {
			bool linked = false;
			// path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex];
			// path[pathIndex].mIndex = ?
			const CtNode::Links& prevLinks = newPath[i - 1].mCtNode->mLinks;
			for (size_t l = 0; l < prevLinks.size(); ++l) {
				const CtNode::Link& link = prevLinks[l];
				if (link.mNode == path[i + 1].mCtNode) {
					newPath[i - 1].mIndex = l;
					linked = true;
					break;
				}
			}
			if (!linked) {
				return Path();
			}
		}
		else {
			newPath.push_back(path.at(i));
		}
	}
	return newPath;
}

bool Backtrack::isValidPath(const Path& path) {
	if (path.size() < 3)
		return true;

	// 1) If I depart by car, I have to arrive by car
	if ((pathNodeLink(path,0).mType == Connection::car &&  pathNodeLink(path, path.size() - 2).mType != Connection::car) ||
		(pathNodeLink(path,0).mType != Connection::car &&  pathNodeLink(path, path.size() - 2).mType == Connection::car)) {
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
	// the last pathnode's index is -1 (there is no link from there), so we don't use it.
	for (size_t i = 1; i < path.size() - 1; ++i) {
		const CtNode::Link& currentLink = pathNodeLink(path, i);
		const CtNode::Link& prevLink = pathNodeLink(path, i - 1);
		if (currentLink.mType == Connection::car) {
			if (prevLink.mType != Connection::car && prevLink.mType != Connection::parking) {
				return false;
			}
			if (prevLink.mType == Connection::parking)
				parkingPlace = "";
		}

		// car parking allowed after a car link or before a car link
		if (currentLink.mType == Connection::parking) {
			if (parkingPlace.length() == 0) {
				if (prevLink.mType != Connection::car) {
					return false;
				}
				parkingPlace = pathNodeName(path, i);
			}
			else {
				if (parkingPlace.compare(pathNodeName(path, i)) != 0)
					return false;
				parkingPlace = "";
			}

			if (i < path.size() - 1) {
				// if this link is parking, the previous or the next one must be car
				if (prevLink.mType != Connection::car && pathNodeLink(path, i + 1).mType != Connection::car) {
					return false;
				}
			}
			else {
				// if this link is parking, the previous one must be car
				if (prevLink.mType != Connection::car) {
					return false;
				}
			}
		}
		else {
			// if this link isn't parking, nor car, then the previos musn't be car
			if (currentLink.mType != Connection::car && prevLink.mType == Connection::car) {
				return false;
			}
		}
	}
#endif
	return true;
}

bool Backtrack::isGoal(Context* context) const {
	return checkGoalCondition( mPath, context ) && isMinimal( mPath, context );
}

bool Backtrack::checkGoalCondition(const Path& path, Context* context) {
	if( path.size() <  context->getGoalSize())
        return false;
    
	// let's check the first item, ...
	if (path[0].mCtNode->mName.compare(context->getGoalItem(0)) != 0)
		return false;

	// the last item, ...
	if (path[path.size() - 1].mCtNode->mName.compare(context->getLastGoalItem()) != 0)
		return false;

	if (!isValidPath(path))
		return false;

	// and the others
	int pathIndex = 1;
	int goalIndex = 1;
	while(pathIndex < (int)(path.size()) - 1 && goalIndex < (int)(context->getGoalSize()) - 1 ) {
        std::string goal =  context->getGoalItem(goalIndex);
		size_t separator = goal.find(":");
		Connection::Type linkType = Connection::unknown;
		if (separator != std::string::npos) {
			linkType = Connection::getType(goal.substr(separator + 1));
			goal = goal.substr(0, separator);
		}

		while (!isMatch( path, pathIndex, goal, linkType)) {
			++pathIndex;
			if (pathIndex == (int)path.size())
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

	if (mPath.size() == (size_t)mContext->getMaxPathLength()) {
		// step back
		deleteLastPathItem();
		return genNextPath();
	}

	Backtrack::BtNode* btNode = &mPath[mPath.size() - 1];
	if (btNode->mCtNode->mLinks.size() > 0 && btNode->mIndex < (int)(btNode->mCtNode->mLinks.size()) - 1) {
		// step right
		btNode->mIndex += 1;
		CtNode* ctNode = btNode->mCtNode->mLinks[btNode->mIndex].mNode;

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

void Backtrack::printAllPaths() {
	ScenarioMaker2 scenarioMaker(*this);
	scenarioMaker.generateAllTheScenarios();
	
	std::cout << std::string(100, '*') << "\n*         results ordered by travelling cost:\n" << std::string(100, '*') << std::endl;
	SorterByTravellingCost sorterByTravellingCost(*this);
	sorterByTravellingCost.printMathes(mContext->getDisplayMatchNumberPerScenarion());

	std::cout << std::string(100, '*') << "\n*         results ordered by travelling time:\n" << std::string(100, '*') << std::endl;
	SorterByTravellingTime sorterByTravellingTime(*this);
	sorterByTravellingTime.printMathes(mContext->getDisplayMatchNumberPerScenarion());

	std::cout << std::string(100, '*') << "\n*         results ordered by staying time:\n" << std::string(100, '*') << std::endl;
	SorterByStayingTime sorterByStayingTime(*this);
	sorterByStayingTime.printMathes(mContext->getDisplayMatchNumberPerScenarion());
}

void Backtrack::savePath() {
	PathInfo pathInfo;
	pathInfo.mPath = mPath;
	pathInfo.mHash = genHash(pathInfo.mPath);
	mMatches.push_back(pathInfo);
}

const size_t Backtrack::genHash(const Backtrack::Path& path) {
	std::string hashStr;
	for (size_t i = 0; i < path.size(); ++i) {
		hashStr += path[i].mCtNode->mName;
	}
	return std::hash<std::string>()(hashStr);
}

std::string Backtrack::timeToString(time_t t, std::string timeZone) {
	struct tm tm;
	memset(&tm, 0, sizeof(tm));

	size_t pos = timeZone.find("+");
	int tmz = 0;
	if (pos != std::string::npos) {
		tmz = ((timeZone[pos + 1] - '0') * 10 + (timeZone[pos + 2] - '0')) * 3600;
		tmz += ((timeZone[pos + 3] - '0') * 10 + (timeZone[pos + 4] - '0')) * 60;
	}
	else {
		tmz = 2 * 3600;
	}

	t += tmz;
	/*errno_t err = */gmtime_s(&tm, &t);
	//errno_t err = localtime_s(&tm, &t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %R");
	oss << timeZone;
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
	t -= (tmz - 1) * 60 * 60;
	//timeToString(t);
	return t;
}

// for debugging
void Backtrack::printPath(const Backtrack::Path& path) {
	for (size_t i = 0; i < path.size(); ++i) {

		if (pathNodeIndex(path, i) >= 0) {

			std::cout << pathNodeName(path, i) << " ("
				<< Connection::typeToString(pathNodeLink(path, i).mType) << ") "
				<< "\n" << std::string(60, '-') << "\n";
		}
		else {
			std::cout << pathNodeName(path, i) << " ("
				<< pathNodeIndex(path, i) << ")"
				<< "\n" << std::string(60, '-') << "\n";
		}
	}
	std::cout << std::string(80, 'T') << std::endl;
	std::cout << std::string(80, 'T') << std::endl;


	std::cout << std::string(30, '=');
	std::cout << std::endl;
}
