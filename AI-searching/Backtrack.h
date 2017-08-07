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

    std::vector<Connection> seachTheBestWay( Context* context ) override;
	static double calcPathPrice(const std::vector<Backtrack::BtNode>& path);
	static double calcPathTimeConsuming(const std::vector<Backtrack::BtNode>& path);
	static bool comparePathPrice(const std::vector<Backtrack::BtNode>& path1, const std::vector<Backtrack::BtNode>& path2);
	static bool compareTravellingTime(const std::vector<Backtrack::BtNode>& path1, const std::vector<Backtrack::BtNode>& path2);

private:
	void init();
    bool isGoal();
    bool genNextPath();
	bool isValidPath();

	void printPath(const std::vector<Backtrack::BtNode>& path );
	void printAllPaths();
	void savePath();
	bool isMatch(int pathIndex, std::string goal, Connection::Type linkType);
	void deleteLastPathItem();

	const std::string& pathNodeName(int pathIndex) { return mPath[ pathIndex ].mCtNode->mName;  }
	static const std::string& pathNodeName(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mCtNode->mName; }
	int pathNodeIndex(int pathIndex) { return mPath[pathIndex].mIndex; }
	static int pathNodeIndex(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mIndex; }
	const Context::CtNode::Link& pathNodeLink(int pathIndex) { return mPath[pathIndex].mCtNode->mLinks[mPath[pathIndex].mIndex];  }
	static const Context::CtNode::Link& pathNodeLink(const std::vector<Backtrack::BtNode>& path, int pathIndex) { return path[pathIndex].mCtNode->mLinks[path[pathIndex].mIndex]; }

    std::vector<Backtrack::BtNode> mPath;
	std::vector<std::vector<Backtrack::BtNode>> mMatches;
	std::vector<Backtrack::BtNode> mAlreadyUsedPath;
    bool mTerminated;
	std::set<std::string> mInserted;
};

#endif // BACKTRACK
