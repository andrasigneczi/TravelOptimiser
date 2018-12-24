#include "neural_networkv2.h"
#include "neural_network/activation.h"

using namespace Activation;

class MyCerr {
public:
    template<class T>
    MyCerr& operator<<(const T x) {
        UNUSED(x);
        return *this;
    }
};

//static MyCerr CERR;
#define CERR std::cerr
static const double eps = 1e-8;

NeuralNetworkV2::NeuralNetworkV2( const arma::umat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda,
                              bool featureScaling, NeuralNetworkV2::ActivationFunction hiddenAF, 
                              NeuralNetworkV2::ActivationFunction outputAF, double keep_prob, bool batchNorm, Optimizer::Type optimizerType )
    : CostAndGradient(X, y, lambda)
    , mLayerSizes(layerSizes)
    , mHiddenLAF(hiddenAF)
    , mOuputLAF(outputAF)
    , mLastBNI(nullptr)
    , mKeepProb(keep_prob)
    , mOptimizer(optimizerType)
    , mInitializedFromFile(false)
    , mBatchNormEnabled(batchNorm)
{
    if(featureScaling) {
        mX = this->featureScaling(X, true, 0);
    }
}

NeuralNetworkV2::NeuralNetworkV2(std::string prefix)
    : CostAndGradient(arma::mat(), arma::mat(), 0)
    , mLastBNI(nullptr)
    , mOptimizer(Optimizer::Type::GD)
    , mInitializedFromFile(true)
    , mBatchNormEnabled(false)
{
    loadState(prefix);
}

void NeuralNetworkV2::initializeParametersHe() {
    srand (time(NULL));
    
    // parameters -- parameters "W1", "b1", ..., "WL", "bL":
    //               W1 -- weight matrix of shape (layers_dims[1], layers_dims[0])
    //               b1 -- bias vector of shape (layers_dims[1], 1)
    //               ...
    //               WL -- weight matrix of shape (layers_dims[L], layers_dims[L-1])
    //               bL -- bias vector of shape (layers_dims[L], 1)
    size_t L = mLayerSizes.n_cols - 1;
    for( size_t i = 1; i <=L; ++i ) {
        mParameters["W" + std::to_string(i)] = arma::randu(mLayerSizes(0,i), mLayerSizes(0,i-1)) * sqrt(2./mLayerSizes(0,i-1));
        mParameters["b" + std::to_string(i)] = arma::zeros(mLayerSizes(0,i),1);
        CERR  << __FUNCTION__ << ": W:" << size(mParameters["W" + std::to_string(i)]) << "\n";
        CERR  << __FUNCTION__ << ": b:" << size(mParameters["b" + std::to_string(i)]) << "\n";
    }
}

void NeuralNetworkV2::initializeParametersDeep() {
    srand (time(NULL));
    size_t L = mLayerSizes.n_cols - 1;

    for( size_t i = 1; i <=L; ++i ) {
        mParameters["W" + std::to_string(i)] = arma::randu(mLayerSizes(0,i), mLayerSizes(0,i-1)) * 0.01;
        mParameters["b" + std::to_string(i)] = arma::zeros(mLayerSizes(0,i),1);
        CERR  << __FUNCTION__ << ": W:" << size(mParameters["W" + std::to_string(i)]) << "\n";
        CERR  << __FUNCTION__ << ": b:" << size(mParameters["b" + std::to_string(i)]) << "\n";
    }
}

void NeuralNetworkV2::initializeBatchNorm(size_t index) {
    for(size_t i = mBatchNorm.size(); i <= index; ++i) {
        mBatchNorm.push_back(BatchNormItem());
        BatchNormItem& bi = mBatchNorm[i];
        size_t L = mLayerSizes.n_cols - 1;
        for( size_t l = 0; l <= L - 1; ++l ) {
            std::string lp1 = std::to_string(l);
            std::string lp2 = std::to_string(l + 1);
            CERR << __FUNCTION__ << " batch_norm_size: " << mParameters["W" + lp2].n_rows << "\n";
            bi["gamma" + lp1] = arma::ones(mParameters["W" + lp2].n_rows, 1);
            bi["beta" + lp1] = arma::zeros(mParameters["W" + lp2].n_rows, 1);
            bi["running_mean" + lp1] = arma::mat();
            bi["running_var" + lp1] = arma::mat();
        }
    }
    mLastBNI = &mBatchNorm[index];
}

// X -- input data of size (n_x, m)
arma::mat NeuralNetworkV2::predict(const arma::mat& X, double* cost, bool ignoreFeatureScaling) {

    //Using the learned parameters, predicts a class for each example in X

    ActivationFunction temp = mOuputLAF;
    mOuputLAF = ActivationFunction::SOFTMAX;
    
    arma::mat X2;
    if(!ignoreFeatureScaling && mFCData.n_cols > 0) {
        X2 = applyFeatureScalingValues(X,0);
    } else {
        X2 = X;
    }
    
    // no drop out during the prediction
    const double keep_prob = mKeepProb;
    mKeepProb = 1.;
    arma::mat A = L_model_forward(X2);
    if(cost){
        CERR  << __FUNCTION__ << ": dbg1\n";
        *cost = compute_cost_with_regularization(A, mY, mOuputLAF);
    }
    arma::mat p = arma::conv_to<arma::mat>::from(arma::index_max(A,0));
    mKeepProb = keep_prob;
    mOuputLAF = temp;
    return p;   
}

double NeuralNetworkV2::accuracy(double* cost) {
    arma::mat p = predict(mX, cost, true);
    arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(mY,0));
    return (double)arma::accu(p==temp)/(double)mY.n_cols*100.;
}

// Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID computation
arma::mat NeuralNetworkV2::L_model_forward(const arma::mat& X) {
    mCaches = std::stack<arma::mat>();
    mBNCaches = std::stack<arma::mat>();

    arma::mat A = X;

    CERR  << __FUNCTION__ << ": dbg1\n";
    size_t L = mLayerSizes.n_cols - 1;
    // Implement [LINEAR -> RELU]*(L-1). Add "cache" to the "caches" list.
    for( size_t l = 1; l < L; ++l ) {
        if(l > 1 && mKeepProb != 1.) A = Dropout_Forward(A);
        A = linear_activation_forward(A, mParameters["W"+ std::to_string(l)], mParameters["b"+ std::to_string(l)], mHiddenLAF, l);
    }
    CERR  << __FUNCTION__ << ": dbg2\n";
    if(mKeepProb != 1.) A = Dropout_Forward(A);
    // Implement LINEAR -> SIGMOID. Add "cache" to the "caches" list.
    A = linear_activation_forward(A, mParameters["W"+ std::to_string(L)], mParameters["b"+ std::to_string(L)], mOuputLAF, L);

    CERR  << __FUNCTION__ << ": dbg3\n";
    //assert(AL.shape == (1,X.shape[1]))
            
    return A;
}

arma::mat NeuralNetworkV2::batchNorm_forward(const arma::mat& Z, const arma::mat& gamma, const arma::mat& beta, arma::mat& running_mean, arma::mat& running_var) {
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

        CERR << __FUNCTION__ << ": var: " << size(var) << "\n";
        CERR << __FUNCTION__ << ": Z_norm: " << size(Z_norm) << "\n";
        CERR << __FUNCTION__ << ": gamma: " << size(gamma) << "\n";
        CERR << __FUNCTION__ << ": beta: " << size(beta) << "\n";


        mBNCaches.push(mu);
        mBNCaches.push(Z);
        mBNCaches.push(Z_norm);
        mBNCaches.push(var);
        mBNCaches.push(gamma);

        if(running_mean.n_rows == 0) {
            running_mean = arma::zeros(mu.n_rows, 1);
            running_var = arma::zeros(var.n_rows, 1);
        }
        CERR << __FUNCTION__ << " running_mean: " << size(running_mean) << "\n";
        running_mean = running_mean * 0.9 + mu * 0.1;
        CERR << __FUNCTION__ << " running_var: " << size(running_var) << "\n";
        running_var = running_var * 0.9 + var * 0.1;
        CERR << __FUNCTION__ << " Done\n";
        return out;
    } else {
        //return Z;
        CERR << __FUNCTION__ << " running_mean: " << size(running_mean) << "\n";
        CERR << __FUNCTION__ << " running_var: " << size(running_var) << "\n";
        CERR << __FUNCTION__ << " Z: " << size(Z) << "\n";
        arma::mat Z_norm = Util::div(Util::minus(Z, running_mean), sqrt(running_var + eps));
        CERR << __FUNCTION__ << " Z_norm: " << size(Z_norm) << "\n";
        arma::mat out = Util::plus(Util::mul(Z_norm, gamma), beta);
        CERR << __FUNCTION__ << " Done2\n";
        return out;
    }
    return arma::mat();
}

arma::mat NeuralNetworkV2::batchNorm_backward(arma::mat dZ, size_t l) {
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

    CERR << __FUNCTION__ << ": 0 l: " << l << "\n";
    CERR << __FUNCTION__ << ": 1 Z: " << size(Z) << "\n";
    CERR << __FUNCTION__ << ": 2 mu: " << size(mu) << "\n";
    arma::mat Z_mu = Util::minus(Z, mu);
    CERR << __FUNCTION__ << ": 3 Z_mu: " << size(Z_mu) << "\n";
    arma::mat std_inv = 1. / sqrt(var + eps);
    CERR << __FUNCTION__ << ": 4 std_inv: " << size(std_inv) << "\n";
    CERR << __FUNCTION__ << ": 5 gamma: " << size(gamma) << "\n";
    CERR << __FUNCTION__ << ": 6 dZ: " << size(dZ) << "\n";
    arma::mat dZ_norm = Util::mul(dZ, gamma);
    CERR << __FUNCTION__ << ": 7 dZ_norm: " << size(dZ_norm) << "\n";
    arma::mat dvar = Util::mul(arma::sum(dZ_norm % Z_mu, 1) * -.5, arma::pow(std_inv, 3));
    CERR << __FUNCTION__ << ": 8 dvar: " << size(dvar) << "\n";
    arma::mat dmu = Util::plus(Util::mul(dvar, arma::mean(Z_mu * -2., 1)),
                                         arma::sum(Util::mul(dZ_norm, -std_inv), 1));
    CERR << __FUNCTION__ << ": 9 dmu: " << size(dmu) << "\n";
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

arma::mat NeuralNetworkV2::Dropout_Forward(const arma::mat& A) {
    // D1 = np.random.rand(A1.shape[0],A1.shape[1])      # Step 1: initialize matrix D1 = np.random.rand(..., ...)
    // D1 = (D1 < keep_prob)                             # Step 2: convert entries of D1 to 0 or 1 (using keep_prob as the threshold)
    // A1 = A1 * D1                                      # Step 3: shut down some neurons of A1
    // A1 = A1 / keep_prob                               # Step 4: scale the value of neurons that haven't been shut down
    CERR  << __FUNCTION__ << " dbg1\n";
    arma::mat D = arma::randu(size(A));
    CERR  << __FUNCTION__ << " dbg2\n";
    arma::uvec cond1 = arma::find(D < mKeepProb);
    CERR  << __FUNCTION__ << " dbg3\n";
    arma::uvec cond2 = arma::find(D >= mKeepProb);
    CERR  << __FUNCTION__ << " dbg4\n";
    D.elem(cond1).fill(1.);
    CERR  << __FUNCTION__ << " dbg5\n";
    D.elem(cond2).fill(0.);
    CERR  << __FUNCTION__ << " dbg6\n";
    mDropOutCache.push(D);
    return (A % D) / mKeepProb;
}

arma::mat NeuralNetworkV2::Dropout_Backward(const arma::mat& dA) {
    // dA2 = dA2 * D2          # Step 1: Apply mask D2 to shut down the same neurons as during the forward propagation
    // dA2 = dA2 / keep_prob   # Step 2: Scale the value of neurons that haven't been shut down
    arma::mat D = mDropOutCache.top();mDropOutCache.pop();
    return (dA % D)/mKeepProb;
}

// Implement the forward propagation for the LINEAR->ACTIVATION layer
// A_prev -- activations from previous layer (or input data): (size of previous layer, number of examples)
// W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
// b -- bias vector, numpy array of shape (size of the current layer, 1)
// activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"
// Returns:
// A -- the output of the activation function, also called the post-activation value 
// cache -- a python dictionary containing "linear_cache" and "activation_cache";
// stored for computing the backward pass efficiently
arma::mat NeuralNetworkV2::linear_activation_forward(const arma::mat& A_prev, const arma::mat& W, const arma::mat& b,
                                                     NeuralNetworkV2::ActivationFunction activation, size_t l) {

    arma::mat Z, A;
    CERR  << __FUNCTION__ << ": dbg1\n";

    Z = linear_forward(A_prev, W, b);

    if(mBatchNormEnabled) {
        CERR << __FUNCTION__ << ": Z.size(): " << size(Z) << "\n";
        std::string idx = std::to_string(l - 1);
        CERR << __FUNCTION__ << ": l: " << idx << "\n";
        if(!mLastBNI) {
            CERR << __FUNCTION__ << ": mLastBNI empty!!!\n";
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
            CERR << __FUNCTION__ << ": gamma.size(): " << size(gamma) << "\n";
            CERR << __FUNCTION__ << ": gamma: " << gamma << "\n";
            CERR << __FUNCTION__ << ": beta: " << beta << "\n";
            CERR << __FUNCTION__ << ": running_mean: " << running_mean << "\n";
            CERR << __FUNCTION__ << ": running_var: " << running_var << "\n";

            Z = batchNorm_forward(Z, gamma, beta, running_mean, running_var);
        } else {
            //double gamma = 1.;
            //double beta = 0.001;
            arma::mat& gamma = (*mLastBNI)["gamma" + idx];
            arma::mat& beta = (*mLastBNI)["beta" + idx];
            arma::mat& running_mean = (*mLastBNI)["running_mean" + idx];
            arma::mat& running_var  = (*mLastBNI)["running_var" + idx];

            CERR << __FUNCTION__ << ": gamma.size(): " << size(gamma) << "\n";
            //arma::mat gamma = arma::ones(1, Z.n_cols);
            //arma::mat beta = arma::ones(1, Z.n_cols);
            Z = batchNorm_forward(Z, gamma, beta, running_mean, running_var);
        }
    }

    mCaches.push(A_prev);
    mCaches.push(W);
    mCaches.push(b);


    if( activation == SIGMOID ) {
        CERR  << __FUNCTION__ << ": dbg3\n";
        A = sigmoid(Z);
    } else if( activation == RELU ) {
        CERR  << __FUNCTION__ << ": dbg5\n";
        A = relu(Z);
    } else if( activation == TANH ) {
        CERR  << __FUNCTION__ << ": dbg5\n";
        A = tanh(Z);
    } else if( activation == SOFTMAX ) {
        CERR  << __FUNCTION__ << ": dbg5\n";
        A = softmax(Z);
    } else if( activation == LRELU ) {
        CERR  << __FUNCTION__ << ": dbg5\n";
        A = leaky_relu(Z);
    }
    CERR  << __FUNCTION__ << ": dbg6\n";
    mCaches.push(A);
    //assert (A.shape == (W.shape[0], A_prev.shape[1]))
    //cache = (linear_cache, activation_cache)

    return A;
}

// Implement the linear part of a layer's forward propagation.
// 
// Arguments:
// A -- activations from previous layer (or input data): (size of previous layer, number of examples)
// W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
// b -- bias vector, numpy array of shape (size of the current layer, 1)
// 
// Returns:
// Z -- the input of the activation function, also called pre-activation parameter 
// cache -- a python dictionary containing "A", "W" and "b" ; stored for computing the backward pass efficiently
arma::mat NeuralNetworkV2::linear_forward(const arma::mat& A, const arma::mat& W, const arma::mat& b) {
    CERR  << __FUNCTION__ << ": dbg1\n";
    CERR  << "W: " << size(W) << "\nA: " << size(A) << "\nb: " << size(b) << "\n";
    //arma::mat Z = W * A + b; // broadcast
    arma::mat Z;
    if(mBatchNormEnabled) {
        Z = W*A;
    } else {
        Z = Util::plus(W*A, b);
    }
    CERR  << __FUNCTION__ << ": dbg2\n";
    //assert(Z.shape == (W.shape[0], A.shape[1]))
    //cache = (A, W, b)
    
    return Z;
}

// Arguments:
// A3 -- post-activation, output of forward propagation, of shape (output size, number of examples)
// Y -- "true" labels vector, of shape (output size, number of examples)
double NeuralNetworkV2::compute_cost_with_regularization(const arma::mat& AL, const arma::mat& Y, ActivationFunction af) {
    double m = (double)Y.n_cols;
    double cross_entropy_cost = compute_cost(AL, Y, af); // This gives you the cross-entropy part of the cost
    double L2_regularization_cost = 0;
    if( mLambda != 0. ){
        size_t L = mParameters.size()/2;
        for(size_t l = 1; l <= L; ++l) {
            L2_regularization_cost += arma::accu(arma::square(mParameters["W" + std::to_string(l)]));
        }
        L2_regularization_cost = 1./m*mLambda/2.*(L2_regularization_cost);
    }
    return cross_entropy_cost + L2_regularization_cost;
}

// Arguments:
// AL -- probability vector corresponding to your label predictions, shape (1, number of examples)
// Y -- true "label" vector (for example: containing 0 if non-cat, 1 if cat), shape (1, number of examples)
// Returns:
// cost -- cross-entropy cost
double NeuralNetworkV2::compute_cost(const arma::mat& AL, const arma::mat& Y, ActivationFunction af) {
    double m = (double)Y.n_cols;
    double cost = 0;
    
    if(af == SOFTMAX) {
        arma::mat maxY = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
        CERR  << __FUNCTION__ << " maxY: " << size(maxY) << "\n";
        arma::mat ALt = arma::zeros(1,AL.n_cols);
        for( size_t i=0; i < m; ++i ) {
            ALt(0, i) = AL(maxY(0,i), i);
        }
        //cost = np.sum(-np.log(AL[Y.argmax(axis=0),range(m)]))/m;
        CERR  << __FUNCTION__ << " " << arma::accu(-arma::log(ALt)) << "\n";
        cost = arma::accu(-arma::log(ALt))/(double)m;
        
        //- nd.sum(y * nd.log(yhat+1e-6)
        //cost = -arma::accu(Y % arma::log(AL+1e-6))/m;
    } else {
        // Compute loss from aL and y.
        cost = -1./m*arma::accu(Y % arma::log(AL) + (1.-Y)%arma::log(1.-AL));
    }
    
    //cost = np.squeeze(cost)      // To make sure your cost's shape is what we expect (e.g. this turns [[17]] into 17).
    //assert(cost.shape == ())
    CERR  << __FUNCTION__ << ": " << cost << "\n";
    return cost;
}

// Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR -> SIGMOID group
// 
// Arguments:
// AL -- probability vector, output of the forward propagation (L_model_forward())
// Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
// caches -- list of caches containing:
//             every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
//             the cache of linear_activation_forward() with "sigmoid" (it's caches[L-1])
// 
// Returns:
// grads -- A dictionary with the gradients
//          grads["dA" + str(l)] = ... 
//          grads["dW" + str(l)] = ...
//          grads["db" + str(l)] = ... 
void NeuralNetworkV2::L_model_backward(const arma::mat& AL, const arma::mat& Y) {
    mGrads.clear();
    size_t L = mLayerSizes.n_cols - 1;
    //size_t m = AL.n_cols;
    //Y = Y.reshape(AL.shape) # after this line, Y is the same shape as AL
    
    // Initializing the backpropagation
    arma::mat dAL = - (Y/AL - (1. - Y)/(1. - AL));

    // Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "dAL, current_cache". Outputs: "grads["dAL-1"], grads["dWL"], grads["dbL"]
    //current_cache = caches[L-1]
    // A_prev, W, b, Z
    /*grads["dA" + str(L-1)], grads["dW" + str(L)], grads["db" + str(L)] = */linear_activation_backward(dAL, mOuputLAF, L - 1, Y);

    // Loop from l=L-2 to l=0
    for( int l = (int)L - 2; l >= 0; --l ) {
        // lth layer: (RELU -> LINEAR) gradients.
        // Inputs: "grads["dA" + str(l + 1)], current_cache". Outputs: "grads["dA" + str(l)] , grads["dW" + str(l + 1)] , grads["db" + str(l + 1)] 
        //current_cache = caches[l]
        arma::mat dA  = mGrads["dA" + std::to_string(l + 1)];
        if(mKeepProb != 1.) dA = Dropout_Backward(dA);
        /*dA_prev_temp, dW_temp, db_temp = */linear_activation_backward(dA, mHiddenLAF, l, Y);

        //grads["dA" + str(l)] = dA_prev_temp
        //grads["dW" + str(l + 1)] = dW_temp
        //grads["db" + str(l + 1)] = db_temp
    }
    
}

// Implement the backward propagation for the LINEAR->ACTIVATION layer.
// 
// Arguments:
// dA -- post-activation gradient for current layer l 
// cache -- tuple of values (linear_cache, activation_cache) we store for computing backward propagation efficiently
// activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"
// 
// Returns:
// dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
// dW -- Gradient of the cost with respect to W (current layer l), same shape as W
// db -- Gradient of the cost with respect to b (current layer l), same shape as b
void NeuralNetworkV2::linear_activation_backward(const arma::mat& dA, NeuralNetworkV2::ActivationFunction activation, size_t l,
                                                 const arma::mat& Y) {
    //linear_cache, activation_cache = cache
    arma::mat A_prev, W, b, gZ, dZ;
    gZ = mCaches.top();mCaches.pop();
    b = mCaches.top();mCaches.pop();
    W = mCaches.top();mCaches.pop();
    A_prev = mCaches.top();mCaches.pop();
    
    CERR  << __FUNCTION__ << " dbg1\n";
    CERR  << "gZ:" << size(gZ) << "\n";
    CERR  << "Y:" << size(Y) << "\n";
    CERR  << "dA:" << size(dA) << "\n";

    if( activation == RELU ) {
        //dZ = np.multiply(dA, np.int64(activation_cache > 0))
        dZ = dA % relu_backward(gZ);
        CERR  << "relu dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == SIGMOID ) {
        //dZ = sigmoid_backward(dA, activation_cache) // dZ=dA*g'(Z)
        dZ = dA % sigmoid_backward(gZ);
        CERR  << "sigmoid dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == TANH ) {
        //dZ = dA % (1. - arma::square(gZ));
        dZ = dA % tanh_backward(gZ);
        CERR  << "tanh dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == SOFTMAX ) {

        // coursera: dZ = Yhat - y
        //dZ = AL - Y;
        arma::mat dZ = softmax_backward(Y, gZ);
        CERR  << "softmax dZ:" << size(dZ) << "\n";
        linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == LRELU ) {
        dZ = dA % leaky_relu_backward(gZ);
        linear_backward(dZ, A_prev, W, b, l);
    }
    
    //return dA_prev, dW, db;
}

// Implement the linear portion of backward propagation for a single layer (layer l)
// 
// Arguments:
// dZ -- Gradient of the cost with respect to the linear output (of current layer l)
// cache -- tuple of values (A_prev, W, b) coming from the forward propagation in the current layer
// 
// Returns:
// dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
// dW -- Gradient of the cost with respect to W (current layer l), same shape as W
// db -- Gradient of the cost with respect to b (current layer l), same shape as b
void NeuralNetworkV2::linear_backward(arma::mat dZ, const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, size_t l) {
    size_t m = A_prev.n_cols;

    if(mLastBNI && mBatchNormEnabled) {
        dZ = batchNorm_backward(dZ, l);
    }

    CERR  << __FUNCTION__ << " dZ: " << size(dZ) << "\n";
    CERR  << __FUNCTION__ << " A_prev: " << size(A_prev) << "\n";
    CERR  << __FUNCTION__ << " W: " << size(W) << "\n";
    arma::mat dW = 1./m*dZ * A_prev.t() + mLambda/m*W;
    arma::mat db = 1./m*arma::sum(dZ,1);
    arma::mat dA_prev = W.t() * dZ;

    mGrads["dA" + std::to_string(l)]     = dA_prev;
    mGrads["dW" + std::to_string(l + 1)] = dW;
    mGrads["db" + std::to_string(l + 1)] = db;

    UNUSED(b);
    UNUSED(l);
    //assert (dA_prev.shape == A_prev.shape)
    //assert (dW.shape == W.shape)
    //assert (db.shape == b.shape)
    
    //return dA_prev, dW, db;
}

void NeuralNetworkV2::update_batchnorm_parameters(double learning_rate) {
    for(size_t i = 0; i < mBatchNorm.size(); ++i) {
        for( size_t l = 0; l < mLayerSizes.n_cols - 1; ++l ) {
            mBatchNorm[i]["gamma" + std::to_string(l)] -= learning_rate * mBatchNorm[i]["dgamma" + std::to_string(l)];
            mBatchNorm[i]["beta" + std::to_string(l)] -= learning_rate * mBatchNorm[i]["dbeta" + std::to_string(l)];
        }
    }
}

void NeuralNetworkV2::miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                double beta, double beta1, double beta2,
                                                double epsilon ) {
    if(!mInitializedFromFile) {
        mBatchSize = batchSize;
        mLearningRate = learning_rate;

        initializeParametersHe();

        mOptimizer.initialize(mLayerSizes.n_cols - 1, mParameters);
    }

    arma::mat dataset = arma::mat(1,mY.n_cols);
    for(size_t t = 0; t < mY.n_cols;++t) dataset(0,t) = t;

    for( long long i = 0; i < epoch; ++i ) {
        dataset = shuffle(dataset,1);
        for( size_t index = 0; ;++index) {
            size_t l = index * batchSize;
            size_t l_end = l + batchSize - 1;

            if( l >= mX.n_cols )
                break;

            if( l_end >= mX.n_cols )
                l_end = mX.n_cols - 1;
                
            arma::mat X = arma::mat(mX.n_rows,l_end - l + 1);
            arma::mat Y = arma::mat(mY.n_rows,l_end - l + 1);

            //mX = XSave.cols(l, l_end);
            //mY = YSave.cols(l, l_end);
            for(size_t t = l; t <= l_end;++t){
                X.col(t-l) = mX.col(dataset(0,t));
                Y.col(t-l) = mY.col(dataset(0,t));
            }

            if(mBatchNormEnabled) {
                initializeBatchNorm(index);
            }
            CERR  << __FUNCTION__ << " X.size(): " << size(X) << "\n";
            CERR  << __FUNCTION__ << " Y.size(): " << size(Y) << "\n";
            CERR  << __FUNCTION__ << " dbg1\n";
            // Forward propagation: [LINEAR -> RELU]*(L-1) -> LINEAR -> SIGMOID.
            arma::mat AL = L_model_forward(X);
            CERR  << __FUNCTION__ << " dbg2\n";
            // Compute cost.
            //double cost = compute_cost(AL, mY);
            CERR  << __FUNCTION__ << " dbg3\n";
            // Backward propagation.
            L_model_backward(AL, Y);
            CERR  << __FUNCTION__ << " dbg4\n";
            // Update parameters.
            mOptimizer.updateParameters(mParameters, mGrads, learning_rate, beta, beta1, beta2,  epsilon);

            if(mBatchNormEnabled) {
                update_batchnorm_parameters(learning_rate);
            }
            
            CERR  << __FUNCTION__ << " dbg5\n";
        }
        mLastBNI = nullptr;

        // Print the cost every 100 training example
        if( i % 10 == 0 ){
            double cost=0;
            double acc = accuracy(&cost);
            std::cout << "Iteration: " << i << "; Accuracy: " << acc << "%; " << cost << "\n";
            if(acc == 100. || std::isnan(cost)) {
                break;
            }
        }
    }
}

bool NeuralNetworkV2::saveState(std::string prefix) {
    std::ofstream output(prefix +"_state.bin", std::ios::binary | std::ios::trunc | std::ios::out);
    Util::saveMat(output, mX);
    Util::saveMat(output, mY);
    Util::saveMat(output, mLayerSizes);
    Util::saveMat(output, mFCData);
    Util::saveStringUMap(output, mParameters);
    Util::saveStringUMap(output, mGrads);
    Util::saveVectorStringUMap(output, mBatchNorm);

    output.write((const char*)&mHiddenLAF,    sizeof(mHiddenLAF));
    output.write((const char*)&mOuputLAF,     sizeof(mOuputLAF));
    output.write((const char*)&mKeepProb,     sizeof(mKeepProb));
    output.write((const char*)&mLambda,       sizeof(mLambda));
    output.write((const char*)&mBatchSize,    sizeof(mBatchSize));
    output.write((const char*)&mLearningRate, sizeof(mLearningRate));
    output.write((const char*)&mBatchNormEnabled, sizeof(mBatchNormEnabled));

    mOptimizer.saveState(output);
    return true;
}

bool NeuralNetworkV2::loadState(std::string prefix) {
    std::ifstream input(prefix +"_state.bin", std::ios::binary | std::ios::in);
    mX = Util::loadMat(input);
    mY = Util::loadMat(input);
    mLayerSizes = Util::loadUMat(input);
    mFCData = Util::loadMat(input);
    Util::loadStringUMap(input, mParameters);
    Util::loadStringUMap(input, mGrads);
    Util::loadVectorStringUMap(input, mBatchNorm);

    input.read((char*)&mHiddenLAF,    sizeof(mHiddenLAF));
    input.read((char*)&mOuputLAF,     sizeof(mOuputLAF));
    input.read((char*)&mKeepProb,     sizeof(mKeepProb));
    input.read((char*)&mLambda,       sizeof(mLambda));
    input.read((char*)&mBatchSize,    sizeof(mBatchSize));
    input.read((char*)&mLearningRate, sizeof(mLearningRate));
    input.read((char*)&mBatchNormEnabled, sizeof(mBatchNormEnabled));
    mOptimizer.loadState(input);
    return true;
}

void NeuralNetworkV2::continueMinibatch(long long epoch) {
    double cost=0;
    double acc = accuracy(&cost);
    std::cout << "Before the first iteration: Accuracy: " << acc << "%; " << cost << "\n";
    if(acc != 100. && !std::isnan(cost)) {
        miniBatchGradientDescent(epoch, mBatchSize, mLearningRate, mOptimizer.beta(), mOptimizer.beta1(),
                                 mOptimizer.beta2(), mOptimizer.epsilon());
    }
}

arma::mat NeuralNetworkV2::avgBatchParam(std::string key) {
    if(mBatchNorm.size() == 0) {
        return arma::mat();
    }

    arma::mat retV = mBatchNorm[0][key];
    for(size_t i = 1; i < mBatchNorm.size(); ++i) {
        retV += mBatchNorm[i][key];
    }
    CERR  << __FUNCTION__ << ": key: " << key << "\n";
    return retV / (double)mBatchNorm.size();
}
