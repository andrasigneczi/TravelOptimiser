#ifndef __FORWARD_BACKWARD_IF_H__
#define __FORWARD_BACKWARD_IF_H__

#include <iostream>
#include <vector>
#include <armadillo>

class ForwardBackwardIF {
public:

    virtual std::vector<arma::cube> forward(std::vector<arma::cube> X) = 0;
    virtual std::vector<arma::cube> backward(std::vector<arma::cube> dX) = 0;

    virtual void saveState(std::ofstream& output) = 0;
    virtual void loadState(std::ifstream& input) = 0;

};

#endif // __FORWARD_BACKWARD_IF_H__
