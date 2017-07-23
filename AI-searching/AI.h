#ifndef _AI_H
#define _AI_H

#include "Connection.h"
#include "Context.h"
#include <vector>
#include <string>
#include <memory>

class AI {

public:
    virtual std::vector<Connection> seachTheBestWay( Context* context ) = 0;
    
protected:

    std::unique_ptr<Context> mContext;
};

#endif // BACKTRACK
