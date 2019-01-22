#ifndef __CNOPTIMIZER_H__
#define __CNOPTIMIZER_H__

#include <armadillo>

enum CNOptimizerType {
    GD,
    MOMENTUM,
    ADAM
};

template<class Storage>
class CNOptimizer
{
public:
    CNOptimizer(CNOptimizerType optimizerType, Storage& W, Storage& B, Storage& dW, Storage& db);
    void updateParameters(double learning_rate, double beta,
                          double beta1, double beta2,  double epsilon, int batch_size);

private:
    void update_parameters_with_gd(double learning_rate);
    void update_parameters_with_momentum(double learning_rate, double beta);
    void update_parameters_with_adam(double learning_rate, double beta1, double beta2,  double epsilon, int batch_size);


    Storage& mW; // Weights, kernel
    Storage& mB; // Biases

    Storage& mdW;
    Storage& mdb;

    // Optimizer parmeters
    CNOptimizerType mOptimizerType;
    int mAdamCounter;
    double mBeta;
    double mBeta1;
    double mBeta2;
    double mEpsilon;

    Storage mdWVelocity;
    Storage mdbVelocity;
    Storage mdWAdamS;
    Storage mdbAdamS;
};

#include "cnoptimizer.cpp"

#endif // CNOPTIMIZER_H
