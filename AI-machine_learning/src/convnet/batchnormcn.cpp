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

arma::mat4D BatchNormCN::forward(arma::mat4D Z) {
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

arma::mat4D BatchNormCN::backward(arma::mat4D dZ) {
}

arma::mat BatchNormCN::forward(arma::mat Z) {
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
/*
def batchnorm_forward(X, gamma, beta):
    mu = np.mean(X, axis=0)
    var = np.var(X, axis=0)

    X_norm = (X - mu) / np.sqrt(var + 1e-8)
    out = gamma * X_norm + beta

    cache = (X, X_norm, mu, var, gamma, beta)

    return out, cache, mu, var
*/
/*
    def batchnorm_forward(x, gamma, beta, eps):
      mu = np.mean(x)
      var = np.var(x)
      xhat = (x - mu) / np.sqrt(var + eps)
      y = gamma * xhat + beta
      return y
*/
    if(mBatchIndex == -1) {
        arma::mat gamma = avgBatchParam(GAMMA);
        arma::mat beta = avgBatchParam(BETA);
        arma::mat running_mean = avgBatchParam(RUNNING_MEAN);
        arma::mat running_var  = avgBatchParam(RUNNING_VAR);

        arma::mat Z_norm = Util::div(Util::minus(Z, running_mean), sqrt(running_var + eps));
        arma::mat out = Util::plus(Util::mul(Z_norm, gamma), beta);
        return out;
    } else {
        Item& batchItem = mBatches[mBatchIndex];
        arma::mat mu = arma::mean(Z, 1);
        arma::mat var = arma::var(Z, 0, 1);
        arma::mat Z_norm = Util::div(Util::minus(Z, mu), sqrt(var + eps));
        arma::mat out = Util::plus(Util::mul(Z_norm, batchItem.mGamma), batchItem.mBeta);

        mCache.push(mu);
        mCache.push(Z);
        mCache.push(Z_norm);
        mCache.push(var);
        //mCache.push(gamma);

        if(batchItem.mRunningMean.n_rows == 0) {
            batchItem.mRunningMean = arma::zeros(mu.n_rows, 1);
            batchItem.mRunningVar = arma::zeros(var.n_rows, 1);
        }
        batchItem.mRunningMean = batchItem.mRunningMean * 0.9 + mu * 0.1;
        batchItem.mRunningVar = batchItem.mRunningVar * 0.9 + var * 0.1;
        return out;
    }
    return arma::mat();
}

arma::mat BatchNormCN::backward(arma::mat dZ) {
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
    Item& batchItem = mBatches[mBatchIndex];
    //arma::mat gamma  = mBNCaches.top();mBNCaches.pop();
    arma::mat var    = mCache.top();mCache.pop();
    arma::mat Z_norm = mCache.top();mCache.pop();
    arma::mat Z      = mCache.top();mCache.pop();
    arma::mat mu     = mCache.top();mCache.pop();

    //double D = (double)Z.n_rows;
    double D = (double)Z_norm.n_cols;

    arma::mat Z_mu = Util::minus(Z, mu);
    arma::mat std_inv = 1. / sqrt(var + eps);
    arma::mat dZ_norm = Util::mul(dZ, batchItem.mGamma);
    arma::mat dvar = Util::mul(arma::sum(dZ_norm % Z_mu, 1) * -.5, arma::pow(std_inv, 3));
    arma::mat dmu = Util::plus(Util::mul(dvar, arma::mean(Z_mu * -2., 1)),
                                         arma::sum(Util::mul(dZ_norm, -std_inv), 1));
    dZ = Util::plus(Util::mul(dZ_norm, std_inv) + (Util::mul(Z_mu, dvar * 2.) / D), (dmu / D));

    batchItem.mdGamma = arma::sum(dZ % Z_norm, 1);
    batchItem.mdBeta = arma::sum(dZ, 1);

/*
    using namespace Util;
    //dx = (gamma*istd/N) * (N*dout - xhat*dgamma - dbeta)
    CERR << __FUNCTION__ << ": 1 gamma: " << size(gamma) << "\n";
    CERR << __FUNCTION__ << ": 2 var: " << size(var) << "\n";
    CERR << __FUNCTION__ << ": 3 dZ: " << size(dZ) << "\n";
    CERR << __FUNCTION__ << ": 4 Z_norm: " << size(Z_norm) << "\n";
    CERR << __FUNCTION__ << ": 5 dgamma: " << size(dgamma) << "\n";
    CERR << __FUNCTION__ << ": 6 dbeta: " << size(dbeta) << "\n";
    dZ = mul(gamma % arma::sqrt(var + eps) / D, minus(dZ * D - mul(Z_norm, dgamma), dbeta));
*/

    return dZ; //, dgamma, dbeta
}

void BatchNormCN::saveState(std::ofstream& output) {
    UNUSED(output);
}

void BatchNormCN::loadState(std::ifstream& input) {
    UNUSED(input);
}

void BatchNormCN::updateParameters(double learning_rate, double beta, double beta1, double beta2, double epsilon/*, int batch_size*/) {
    for(size_t i = 0; i < mBatches.size(); ++i) {
        mBatches[i].mGamma -= learning_rate * mBatches[i].mdGamma;
        mBatches[i].mBeta  -= learning_rate * mBatches[i].mdBeta;
    }
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

arma::mat BatchNormCN::avgBatchParam(BatchNormCN::Param param) {
    if(mBatches.size() == 0) {
        return arma::mat();
    }

    arma::mat retV;
    for(size_t i = 0; i < mBatches.size(); ++i) {
        switch(param) {
        case GAMMA:        retV += mBatches[i].mGamma;
        case BETA:         retV += mBatches[i].mBeta;
        case RUNNING_MEAN: retV += mBatches[i].mRunningMean;
        case RUNNING_VAR:  retV += mBatches[i].mRunningVar;
        case DGAMMA:       retV += mBatches[i].mdGamma;
        case DBETA:        retV += mBatches[i].mdBeta;
        }
    }
    return retV / (double)mBatches.size();
}
