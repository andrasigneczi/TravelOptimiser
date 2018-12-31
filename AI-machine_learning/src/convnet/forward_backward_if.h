#ifndef __FORWARD_BACKWARD_IF_H__
#define __FORWARD_BACKWARD_IF_H__

#include <iostream>
#include <vector>
#include <armadillo>
#include "Util.h"

class ForwardBackwardIF {
public:

    virtual arma::mat4D forward(arma::mat4D X) = 0;
    virtual std::vector<arma::mat4D> backward(arma::mat4D dX) = 0;

    virtual arma::mat forward(arma::mat X) { UNUSED(X); return arma::mat(); }
    virtual arma::mat backward(arma::mat dX) { UNUSED(dX); return arma::mat(); }

    virtual void saveState(std::ofstream& output) = 0;
    virtual void loadState(std::ifstream& input) = 0;

};

#endif // __FORWARD_BACKWARD_IF_H__
