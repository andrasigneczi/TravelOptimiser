#ifndef __FORWARD_BACKWARD_IF_H__
#define __FORWARD_BACKWARD_IF_H__

#include <iostream>
#include <vector>
#include <armadillo>
#include "Util.h"

class Sigmoid;
class Tanh;
class Softmax;
class Relu;
class LeakyRelu;
class FullyConnectedLayer;
class PoolLayer;
class ConvLayer;

class Visitor {
public:
    virtual void visit(Sigmoid*){}
    virtual void visit(Tanh*){}
    virtual void visit(Softmax*){}
    virtual void visit(Relu*){}
    virtual void visit(LeakyRelu*){}
    virtual void visit(FullyConnectedLayer*){}
    virtual void visit(PoolLayer*){}
    virtual void visit(ConvLayer*){}
};

enum IFName {
    CONV,
    SIGMOID,
    RELU,
    TANH,
    LEAKY_RELU,
    SOFTMAX,
    POOL,
    FULLY_CONNECTED
};

class ForwardBackwardIF {
public:
    virtual ~ForwardBackwardIF(){}
    virtual arma::mat4D forward(arma::mat4D X) = 0;
    virtual arma::mat4D backward(arma::mat4D dX) = 0;

    virtual arma::mat forward(arma::mat X) = 0; //{ UNUSED(X); return arma::mat(); }
    virtual arma::mat backward(arma::mat dX) = 0; //{ UNUSED(dX); return arma::mat(); }

    virtual bool is4D() = 0;
    
    virtual void updateParameters(double learningRate) = 0; //{ UNUSED(learningRate); };

    virtual void accept(Visitor&){}
    virtual double getWeightSquareSum() { return 0; }
    
    virtual void saveState(std::ofstream& output) = 0;
    virtual void loadState(std::ifstream& input) = 0;
};

#endif // __FORWARD_BACKWARD_IF_H__
