#ifndef __LENET5_H__
#define __LENET5_H__

#include "convnet.h"

class LeNet5 : public ConvNet {
public:
    LeNet5(arma::mat4D& X, arma::mat Y, double lambda, bool featureScaling);
    LeNet5(std::string prefix);

private:
    void init();
};

#endif // __LENET5_H__
