#ifndef _ASTAR_H
#define _ASTAR_H

#include "AI.h"

class Astar : public AI {

public:
    std::vector<Connection> seachTheBestWay( Context* context ) override;
    
};

#endif // ASTAR
