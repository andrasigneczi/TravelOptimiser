#ifndef __CNOPTIMIZER_H__
#define __CNOPTIMIZER_H__

#include <armadillo>

class CNOptimizer
{
public:
    enum Type {
        GD,
        MOMENTUM,
        ADAM
    };


    CNOptimizer(Type optimizerType, arma::mat& W, arma::mat& B, arma::mat& dW, arma::mat& db);
    void updateParameters(double learning_rate, double beta,
                          double beta1, double beta2,  double epsilon);

private:
    void update_parameters_with_gd(double learning_rate);
    void update_parameters_with_momentum(double learning_rate, double beta);
    void update_parameters_with_adam(double learning_rate, double beta1, double beta2,  double epsilon);


    arma::mat& mW; // Weights, kernel
    arma::mat& mB; // Biases

    arma::mat mdW;
    arma::mat mdb;

    // Optimizer parmeters
    Type mOptimizerType;
    int mAdamCounter;
    double mBeta;
    double mBeta1;
    double mBeta2;
    double mEpsilon;

    arma::mat mdWVelocity;
    arma::mat mdbVelocity;
    arma::mat mdWAdamS;
    arma::mat mdbAdamS;
};

#endif // CNOPTIMIZER_H
