#include "batchnormcn.h"
static const double eps = 1e-8;

// for conv layer
BatchNormCN::BatchNormCN(int f_H, int f_W, int n_C_prev, int n_C)
: mBatchIndex(-1)
{
    
}

// for fully connected layer
BatchNormCN::BatchNormCN(int weightRows)
: mWeightRows(weightRows) 
, mBatchIndex(-1)
{
    
}

arma::mat4D BatchNormCN::forward(arma::mat4D A_prev) {
/*
    # mini-batch mean
    mean = nd.mean(X, axis=0)
    # mini-batch variance
    variance = nd.mean((X - mean) ** 2, axis=0)
    # normalize
    X_hat = (X - mean) * 1.0 / nd.sqrt(variance + eps)
    # scale and shift
    out = gamma * X_hat + beta
    */
}

arma::mat4D BatchNormCN::backward(arma::mat4D dZ) {

/*
    # extract the dimensions
    N, C, H, W = X.shape
    # mini-batch mean
    mean = nd.mean(X, axis=(0, 2, 3))
    # mini-batch variance
    variance = nd.mean((X - mean.reshape((1, C, 1, 1))) ** 2, axis=(0, 2, 3))
    # normalize
    X_hat = (X - mean.reshape((1, C, 1, 1))) * 1.0 / nd.sqrt(variance.reshape((1, C, 1, 1)) + eps)
    # scale and shift
    out = gamma.reshape((1, C, 1, 1)) * X_hat + beta.reshape((1, C, 1, 1))
*/
}

arma::mat BatchNormCN::forward(arma::mat A) {
    return A;
}

arma::mat BatchNormCN::backward(arma::mat dA) {
    return dA;
}

void BatchNormCN::saveState(std::ofstream& output) {
    UNUSED(output);
}

void BatchNormCN::loadState(std::ifstream& input) {
    UNUSED(input);
}

void BatchNormCN::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}

void BatchNormCN::initializeByBatch(size_t batchIndex) {
    for(size_t i = mBatches.size(); i <= batchIndex; ++i) {
        mBatches.push_back(Item());
        Item& bi = mBatches[i];
        bi.mGamma = arma::ones(mWeightRows, 1);
        bi.mBeta  = arma::zeros(mWeightRows, 1);
        bi.mRunningMean = arma::mat();
        bi.mRunningVar  = arma::mat();
    }
    mBatchIndex = batchIndex;
}
