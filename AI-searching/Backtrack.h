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
    
private:
	void init();
    bool isGoal();
    bool genNextPath();

	void printPath(const std::vector<Backtrack::BtNode>& path );
	void printAllPaths();
	void savePath();
	bool isMatch(int pathIndex, std::string goal, Connection::Type linkType);
	void deleteLastPathItem();

    std::vector<Backtrack::BtNode> mPath;
	std::vector<std::vector<Backtrack::BtNode>> mMatches;
	std::vector<Backtrack::BtNode> mAlreadyUsedPath;
    bool mTerminated;
	std::set<std::string> mInserted;
};

#endif // BACKTRACK
