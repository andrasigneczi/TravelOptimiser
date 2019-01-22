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
class Dropout;

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
    virtual void visit(Dropout*){}
};

enum IFName {
    CONV,
    SIGMOID,
    RELU,
    TANH,
    LEAKY_RELU,
    SOFTMAX,
    POOL,
    FULLY_CONNECTED,
    DROPOUT,
    UNKNOWN
};

class ForwardBackwardIF {
public:
    virtual ~ForwardBackwardIF(){}
    virtual arma::mat4D forward(arma::mat4D X) = 0;
    virtual arma::mat4D backward(arma::mat4D dX) = 0;

    virtual arma::mat forward(arma::mat X) = 0; //{ UNUSED(X); return arma::mat(); }
    virtual arma::mat backward(arma::mat dX) = 0; //{ UNUSED(dX); return arma::mat(); }

    virtual bool is4D() = 0;
    
    virtual void updateParameters(double learning_rate, double beta,
                                  double beta1, double beta2,  double epsilon, int batch_size) = 0;

    virtual void accept(Visitor&){}
    virtual double getWeightSquareSum() { return 0; }
    
    virtual void saveState(std::ofstream& output) = 0;
    virtual void loadState(std::ifstream& input) = 0;
};

class LayerNameVisitor final : public Visitor {
public:
        LayerNameVisitor() : mName(IFName::UNKNOWN) {}

        virtual void visit(Softmax*)             final { mName = IFName::SOFTMAX; }
        virtual void visit(Sigmoid*)             final { mName = IFName::SIGMOID; }
        virtual void visit(Tanh*)                final { mName = IFName::TANH; }
        virtual void visit(Relu*)                final { mName = IFName::RELU; }
        virtual void visit(LeakyRelu*)           final { mName = IFName::LEAKY_RELU; }
        virtual void visit(FullyConnectedLayer*) final { mName = IFName::FULLY_CONNECTED; }
        virtual void visit(ConvLayer*)           final { mName = IFName::CONV; }
        virtual void visit(PoolLayer*)           final { mName = IFName::POOL; }
        virtual void visit(Dropout*)             final { mName = IFName::DROPOUT; }

        virtual IFName getName(ForwardBackwardIF* fBIF) final { fBIF->accept(*this); return mName; }

        virtual std::string getNameStr(ForwardBackwardIF* fBIF) final {
            fBIF->accept(*this);
            switch(mName) {
            case CONV:            return "CONV"; break;
            case SIGMOID:         return "SIGMOID"; break;
            case RELU:            return "RELU"; break;
            case TANH:            return "TANH"; break;
            case LEAKY_RELU:      return "LEAKY_RELU"; break;
            case SOFTMAX:         return "SOFTMAX"; break;
            case POOL:            return "POOL"; break;
            case FULLY_CONNECTED: return "FULLY_CONNECTED"; break;
            case DROPOUT:         return "DROPOUT"; break;
            case UNKNOWN:         return "UNKNOWN"; break;
            }
            return "UNKNOWN";
        }
private:
        IFName mName;
};

#endif // __FORWARD_BACKWARD_IF_H__
