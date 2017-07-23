#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "Connection.h"
#include <vector>
#include <string>
#include <unordered_map>

class Context {

public:
    void addConnection( Connection c );
    void setGoal( std::vector<std::string> stops );
    
    struct CtNode {
        CtNode( std::string name ) { mName = name; }
        
        std::string mName;
        struct Link {
            Link( Connection::Type type, CtNode* node, double  timeConsuming, double  distance, double  cost ) { mType = type; mNode = node; mTimeConsuming = timeConsuming; mDistance = distance; mCost = cost; }
            Connection::Type mType;
            CtNode* mNode;
            double  mTimeConsuming; // in hour
            double  mDistance;      // in km
            double  mCost;
            
		};
        std::vector<Context::CtNode::Link> mLinks;
    };

    const std::vector<std::string>& getGoal() const { return mGoal; }
    const std::string& getGoalItem( int index ) const { return mGoal.at( index ); }
    const std::string& getLastGoalItem() const { return mGoal.at( mGoal.size() - 1 ); }
    const size_t getGoalSize() const { return mGoal.size(); }
    const CtNode* getNode( const std::string name ) const { auto it = mNodes.find( name ); if( it == mNodes.end()) return nullptr; return it->second; }
    
private:
    void createNode( Connection c );
    
    std::vector<Connection> mConnections;
    std::vector<std::string> mGoal;
    std::unordered_map<std::string, CtNode*> mNodes;
};

#endif // _CONTEXT_H
