#include "cnoptimizer.h"

CNOptimizer::CNOptimizer(CNOptimizer::Type optimizerType, arma::mat& W, arma::mat& B, arma::mat& dW, arma::mat& db)
    : mW(W)
    , mB(B)
    , mdW(dW)
    , mdb(db)
{
    mOptimizerType = optimizerType;

    switch(mOptimizerType) {
        case GD:
            break;
        case ADAM:
            mdWAdamS = arma::zeros(size(mW));
            mdbAdamS = arma::zeros(size(mB));
            mAdamCounter = 0;
            //break;
        case MOMENTUM:
            mdWVelocity = arma::zeros(size(mW));
            mdbVelocity = arma::zeros(size(mB));
            break;
    }
}

void CNOptimizer::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    // gradient descent

    switch(mOptimizerType) {
        case GD:
            update_parameters_with_gd(learning_rate);
            break;
        case ADAM:
            update_parameters_with_adam(learning_rate, beta1, beta2, epsilon);
            break;
        case MOMENTUM:
            update_parameters_with_momentum(learning_rate, beta);
            break;
    }
}

void CNOptimizer::update_parameters_with_gd(double learning_rate) {
    mW = mW - learning_rate * mdW;
    mB = mB - learning_rate * mdb;
}

void CNOptimizer::update_parameters_with_momentum(double learning_rate, double beta) {
    mdWVelocity = beta * mdWVelocity + (1.-beta) * mdW;
    mdbVelocity = beta * mdbVelocity + (1.-beta) * mdb;

    mW = mW - learning_rate * mdWVelocity;
    mB = mB - learning_rate * mdbVelocity;
}

void CNOptimizer::update_parameters_with_adam(double learning_rate, double beta1, double beta2,  double epsilon) {
    arma::mat v_corrected_dW;
    arma::mat v_corrected_db;
    arma::mat s_corrected_dW;
    arma::mat s_corrected_db;

    // Moving average of the gradients. Inputs: "v, grads, beta1". Output: "v".
    mdWVelocity = beta1 * mdWVelocity + (1.-beta1) * mdW;
    mdbVelocity = beta1 * mdbVelocity + (1.-beta1) * mdb;

    // Compute bias-corrected first moment estimate. Inputs: "v, beta1, t". Output: "v_corrected".
    v_corrected_dW = mdWVelocity/(1.-pow(beta1,mAdamCounter));
    v_corrected_db = mdbVelocity/(1.-pow(beta1,mAdamCounter));
    // Moving average of the squared gradients. Inputs: "s, grads, beta2". Output: "s".
    mdWAdamS = beta2 * mdWAdamS + (1.-beta2) * arma::pow(mdW,2.);
    mdbAdamS = beta2 * mdbAdamS + (1.-beta2) * arma::pow(mdb,2.);

    // Compute bias-corrected second raw moment estimate. Inputs: "s, beta2, t". Output: "s_corrected".
    s_corrected_dW = mdWAdamS/(1.-pow(beta2,mAdamCounter));
    s_corrected_db = mdbAdamS/(1.-pow(beta2,mAdamCounter));

    // Update parameters. Inputs: "parameters, learning_rate, v_corrected, s_corrected, epsilon". Output: "parameters".
    mW = mW - learning_rate * v_corrected_dW / arma::sqrt(s_corrected_dW + epsilon);
    mB = mB - learning_rate * v_corrected_db / arma::sqrt(s_corrected_db + epsilon);
}
