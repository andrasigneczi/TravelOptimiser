#ifndef _BACKTRACK_H
#define _BACKTRACK_H

#include "AI.h"

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

	void printPath();
	bool checkIfAlreadyInserted(const Context::CtNode* ctNode, int index);

    std::vector<Backtrack::BtNode> mPath;
	std::vector<Backtrack::BtNode> mAlreadyUsedPath;
    bool mTerminated;
};

#endif // BACKTRACK
