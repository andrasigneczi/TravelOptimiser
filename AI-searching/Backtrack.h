#pragma once

#ifndef _BACKTRACK_H
#define _BACKTRACK_H

#include "AI.h"
#include <set>
#include "CtNode.h"

class Backtrack : public AI {

public:
	struct BtNode {
	    BtNode( const CtNode* node, int index ) : mCtNode( node), mIndex( index ) {}
	    const CtNode* mCtNode;
	    int mIndex; // index of Node::mLinks
	};

	typedef std::vector<Backtrack::BtNode> Path;

	// One scenario is a time vector. The index of the items are used to index the item of the PathInfo::mPath on a special way.
	typedef std::vector<time_t> Scenario;

	struct PathInfo {
		Path mPath;
		std::vector<Scenario> mScenarios;
		size_t mHash;
		double mSumPrice;
		double mSumTime;
	};

	std::vector<PathInfo>& getMatches() { return mMatches; }

    std::vector<Connection> seachTheBestWay( Context* context ) override;

	static const std::string& pathNodeName(const Path& path, int pathIndex) { return path[pathIndex].mCtNode->mName; }
	static int pathNodeIndex(const Path& path, int pathIndex) { return path[pathIndex].mIndex; }
	static const CtNode::Link& pathNodeLink(const Path& path, int pathIndex) { return path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex]; }
	static const Timetable::TimetableData& pathNodeTimetable(const Path& path, int pathIndex) { return path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex].mTimetable.getTimetableData(); }

private:
	void init();
    bool isGoal(Context* context ) const;
	static bool checkGoalCondition( const Path& path, Context* context);
    bool genNextPath();
	static bool isValidPath(const Path& path);
	static bool isMinimal(const Path& path, Context* context, int level = 0);
	static Path genPathWithoutOneItem(const Path& path, size_t index);

	void printAllPaths();
	void savePath();
	static bool isMatch(const Path& path, int pathIndex, std::string goal, Connection::Type linkType);
	void deleteLastPathItem();
	static void printPath(const Path& pathInfo);
	
	const std::string& pathNodeName(int pathIndex) { return mPath[ pathIndex ].mCtNode->mName;  }
	int pathNodeIndex(int pathIndex) { return mPath[pathIndex].mIndex; }
	const CtNode::Link& pathNodeLink(int pathIndex) { return mPath[pathIndex].mCtNode->mLinks[mPath[pathIndex].mIndex];  }
	static size_t genHash(const Path& path);

	Path mPath;
	std::vector<PathInfo> mMatches;
    bool mTerminated;
	std::set<std::string> mInserted;
};

#endif // BACKTRACK
