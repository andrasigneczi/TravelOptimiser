#ifndef _BACKTRACK_H
#define _BACKTRACK_H

#include "AI.h"
#include <set>

class Backtrack : public AI {

public:
	struct BtNode {
	    BtNode( const Context::CtNode* node, int index ) : mCtNode( node), mIndex( index ) {}
	    const Context::CtNode* mCtNode;
	    int mIndex; // index of Context::Node::mLinks
	};

	// One scenario is a time vector. The index of the items are used to index the item of the PathInfo::mPath.
	typedef std::vector<time_t> Scenario;

	struct PathInfo {
		std::vector<Backtrack::BtNode> mPath;
		std::vector<Scenario> mScenarios;
		size_t mHash;
		double mSumPrice;
		double mSumTime;
	};

	std::vector<PathInfo>& getMatches() { return mMatches; }

    std::vector<Connection> seachTheBestWay( Context* context ) override;
	static bool comparePathPrice(const PathInfo& pathInfo1, const PathInfo& pathInfo2);
	static bool compareTravellingTime(const PathInfo& pathInfo1, const PathInfo& pathInfo2);

	static const std::string& pathNodeName(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mCtNode->mName; }
	static int pathNodeIndex(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mIndex; }
	static const Context::CtNode::Link& pathNodeLink(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex]; }
	static const std::map<std::string, double>& pathNodeTimetable(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex].mTimetable.getTimetable(); }
	static std::string Backtrack::timeToString(time_t t);
	static time_t Backtrack::stringToTime(std::string strTime);

private:
	void init();
    bool isGoal();
    bool genNextPath();
	bool isValidPath();

	void printPath(const PathInfo& path );
	void printPathWithScenarios(const PathInfo& path);
	void printAllPaths();
	void savePath();
	bool isMatch(int pathIndex, std::string goal, Connection::Type linkType);
	void deleteLastPathItem();
	
	const std::string& pathNodeName(int pathIndex) { return mPath[ pathIndex ].mCtNode->mName;  }
	int pathNodeIndex(int pathIndex) { return mPath[pathIndex].mIndex; }
	const Context::CtNode::Link& pathNodeLink(int pathIndex) { return mPath[pathIndex].mCtNode->mLinks[mPath[pathIndex].mIndex];  }
	static const size_t genHash(const std::vector<Backtrack::BtNode>& path);
	static double calcPathPrice(const PathInfo& pathInfo);
	static double calcPathTimeConsuming(const PathInfo& pathInfo);

	

    std::vector<Backtrack::BtNode> mPath;
	std::vector<PathInfo> mMatches;
    bool mTerminated;
	std::set<std::string> mInserted;
};

#endif // BACKTRACK
