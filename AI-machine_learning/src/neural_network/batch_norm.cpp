#include "batch_norm.h"
static const double eps = 1e-8;

Util::UStringMatMap* BatchNorm::initializeEpoch(size_t index, size_t L, const Util::UStringMatMap& parameters) {
    for(size_t i = mBatchNorm.size(); i <= index; ++i) {
        mBatchNorm.push_back(BatchNormItem());
        BatchNormItem& bi = mBatchNorm[i];
        for( size_t l = 0; l <= L - 1; ++l ) {
            std::string lp1 = std::to_string(l);
            std::string lp2 = std::to_string(l + 1);
            bi["gamma" + lp1] = arma::ones(parameters.at("W" + lp2).n_rows, 1);
            bi["beta" + lp1] = arma::zeros(parameters.at("W" + lp2).n_rows, 1);
            bi["running_mean" + lp1] = arma::mat();
            bi["running_var" + lp1] = arma::mat();
        }
    }
    mLastBNI = &mBatchNorm[index];
    return mLastBNI;
}

void BatchNorm::updateParameters(size_t L, double learning_rate) {
    for(size_t i = 0; i < mBatchNorm.size(); ++i) {
        for( size_t l = 0; l < L; ++l ) {
            mBatchNorm[i]["gamma" + std::to_string(l)] -= learning_rate * mBatchNorm[i]["dgamma" + std::to_string(l)];
            mBatchNorm[i]["beta" + std::to_string(l)] -= learning_rate * mBatchNorm[i]["dbeta" + std::to_string(l)];
        }
    }
}

arma::mat BatchNorm::batchNorm_forward(const arma::mat& Z, size_t l) {
    std::string idx = std::to_string(l - 1);
    arma::mat Z_norm;
    if(!mLastBNI) {
        //arma::mat gamma = arma::ones(Z.n_rows, 1);
        //arma::mat beta = arma::zeros(Z.n_rows, 1);

        // arma::mat& gamma = mBatchNorm[l - 1]["gamma" + idx];
        // arma::mat& beta = mBatchNorm[l - 1]["beta" + idx];
        // arma::mat& running_mean = mBatchNorm[l - 1]["running_mean" + idx];
        // arma::mat& running_var  = mBatchNorm[l - 1]["running_var" + idx];

        arma::mat gamma = avgBatchParam("gamma" + idx);
        arma::mat beta = avgBatchParam("beta" + idx);
        arma::mat running_mean = avgBatchParam("running_mean" + idx);
        arma::mat running_var  = avgBatchParam("running_var" + idx);

        Z_norm = batchNorm_forward(Z, gamma, beta, running_mean, running_var);
    } else {
        //double gamma = 1.;
        //double beta = 0.001;
        arma::mat& gamma = (*mLastBNI)["gamma" + idx];
        arma::mat& beta = (*mLastBNI)["beta" + idx];
        arma::mat& running_mean = (*mLastBNI)["running_mean" + idx];
        arma::mat& running_var  = (*mLastBNI)["running_var" + idx];

        //arma::mat gamma = arma::ones(1, Z.n_cols);
        //arma::mat beta = arma::ones(1, Z.n_cols);
        Z_norm = batchNorm_forward(Z, gamma, beta, running_mean, running_var);
    }
    return Z_norm;
}

arma::mat BatchNorm::batchNorm_forward(const arma::mat& Z, const arma::mat& gamma, const arma::mat& beta, arma::mat& running_mean, arma::mat& running_var) {
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
    if(mLastBNI) {

        arma::mat mu = arma::mean(Z, 1);
        arma::mat var = arma::var(Z, 0, 1);
        arma::mat Z_norm = Util::div(Util::minus(Z, mu), sqrt(var + eps));
        arma::mat out = Util::plus(Util::mul(Z_norm, gamma), beta);

        mBNCaches.push(mu);
        mBNCaches.push(Z);
        mBNCaches.push(Z_norm);
        mBNCaches.push(var);
        mBNCaches.push(gamma);

        if(running_mean.n_rows == 0) {
            running_mean = arma::zeros(mu.n_rows, 1);
            running_var = arma::zeros(var.n_rows, 1);
        }
        running_mean = running_mean * 0.9 + mu * 0.1;
        running_var = running_var * 0.9 + var * 0.1;
        return out;
    } else {
        //return Z;
        arma::mat Z_norm = Util::div(Util::minus(Z, running_mean), sqrt(running_var + eps));
        arma::mat out = Util::plus(Util::mul(Z_norm, gamma), beta);
        return out;
    }
    return arma::mat();
}

arma::mat BatchNorm::batchNorm_backward(arma::mat dZ, size_t l) {
/*
    def batchnorm_backward(dout, cache):
        X, X_norm, mu, var, gamma, beta = cache

        N, D = X.shape

        X_mu = X - mu
        std_inv = 1. / np.sqrt(var + 1e-8)

        dX_norm = dout * gamma
        dvar = np.sum(dX_norm * X_mu, axis=0) * -.5 * std_inv**3
        dmu = np.sum(dX_norm * -std_inv, axis=0) + dvar * np.mean(-2. * X_mu, axis=0)

        dX = (dX_norm * std_inv) + (dvar * 2 * X_mu / N) + (dmu / N)
        dgamma = np.sum(dout * X_norm, axis=0)
        dbeta = np.sum(dout, axis=0)

        return dX, dgamma, dbeta
*/

/*
Faster version:
https://costapt.github.io/2016/07/09/batch-norm-alt/

def batchnorm_backward_alt(dout, cache):
  gamma, xhat, istd = cache
  N, _ = dout.shape

  dbeta = np.sum(dout, axis=0)
  dgamma = np.sum(xhat * dout, axis=0)
  dx = (gamma*istd/N) * (N*dout - xhat*dgamma - dbeta)

  return dx, dgamma, dbeta
*/
    arma::mat gamma  = mBNCaches.top();mBNCaches.pop();
    arma::mat var    = mBNCaches.top();mBNCaches.pop();
    arma::mat Z_norm = mBNCaches.top();mBNCaches.pop();
    arma::mat Z      = mBNCaches.top();mBNCaches.pop();
    arma::mat mu     = mBNCaches.top();mBNCaches.pop();

    //double D = (double)Z.n_rows;
    double D = (double)Z_norm.n_cols;

    arma::mat Z_mu = Util::minus(Z, mu);
    arma::mat std_inv = 1. / sqrt(var + eps);
    arma::mat dZ_norm = Util::mul(dZ, gamma);
    arma::mat dvar = Util::mul(arma::sum(dZ_norm % Z_mu, 1) * -.5, arma::pow(std_inv, 3));
    arma::mat dmu = Util::plus(Util::mul(dvar, arma::mean(Z_mu * -2., 1)),
                                         arma::sum(Util::mul(dZ_norm, -std_inv), 1));
    dZ = Util::plus(Util::mul(dZ_norm, std_inv) + (Util::mul(Z_mu, dvar * 2.) / D), (dmu / D));

    arma::mat dgamma = arma::sum(dZ % Z_norm, 1);
    arma::mat dbeta = arma::sum(dZ, 1);

    std::string lstr = std::to_string(l);
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
    (*mLastBNI)["dgamma" + lstr] = dgamma;
    (*mLastBNI)["dbeta" + lstr] = dbeta;

    return dZ; //, dgamma, dbeta

}

arma::mat BatchNorm::avgBatchParam(std::string key) {
    if(mBatchNorm.size() == 0) {
        return arma::mat();
    }

    arma::mat retV = mBatchNorm[0][key];
    for(size_t i = 1; i < mBatchNorm.size(); ++i) {
        retV += mBatchNorm[i][key];
    }
    return retV / (double)mBatchNorm.size();
}

void BatchNorm::saveState(std::ofstream& output) {
    Util::saveVectorStringUMap(output, mBatchNorm);
}

void BatchNorm::loadState(std::ifstream& input) {
    Util::loadVectorStringUMap(input, mBatchNorm);
}
