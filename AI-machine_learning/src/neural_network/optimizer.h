#ifndef __OPTIMIZER_H__
#define __OPTIMIZER_H__

#include "Util.h"

class Optimizer
{
public:
    enum Type {
        GD,
        MOMENTUM,
        ADAM
    };

    Optimizer(Type type);
    void initialize(size_t L, Util::UStringMatMap& parameters);
    void updateParameters(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate = 0.01, double beta = 0.9,
                          double beta1 = 0.9, double beta2 = 0.999,  double epsilon = 1e-8);
    void saveState(std::ofstream& output);
    void loadState(std::ifstream& input);

    double beta() const { return mBeta; }
    double beta1() const { return mBeta1; }
    double beta2() const { return mBeta2; }
    double epsilon() const { return mEpsilon; }

private:
    void initializeVelocity(size_t L, Util::UStringMatMap& parameters);
    void initializeAdam(size_t L, Util::UStringMatMap& parameters);

    void update_parameters_with_gd(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate);
    void update_parameters_with_momentum(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate, double beta);
    void update_parameters_with_adam(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate = 0.01, double beta1 = 0.9, double beta2 = 0.999,  double epsilon = 1e-8);

    Type mType;
    int mAdamCounter;
    double mBeta;
    double mBeta1;
    double mBeta2;
    double mEpsilon;

    Util::UStringMatMap mVelocity;
    Util::UStringMatMap mAdamS;
};

#endif // OPTIMIZER_H
