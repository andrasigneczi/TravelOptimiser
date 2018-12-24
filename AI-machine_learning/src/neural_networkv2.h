#ifndef __NEURAL_NETWORKV2_H__
#define __NEURAL_NETWORKV2_H__

#include <armadillo>
#include <vector>
#include <stack>
#include <unordered_map>
#include "CostAndGradient.h"
#include "Util.h"
#include "neural_network/optimizer.h"

class NeuralNetworkV2 final : public CostAndGradient {
    public:
    
    enum ActivationFunction {
        SIGMOID,
        RELU,
        TANH,
        LRELU,
        SOFTMAX
    };
    
    NeuralNetworkV2(const arma::umat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda,
                    bool featureScaling = false, ActivationFunction hiddenAF = SIGMOID, 
                    ActivationFunction outputAF = SIGMOID, double keep_prob = 1., bool batchNorm = false, Optimizer::Type optimizerType = Optimizer::Type::GD );

    NeuralNetworkV2(std::string prefix);

    void initializeParametersHe();
    void initializeParametersDeep();
    void initializeBatchNorm(size_t index);

    arma::mat predict(const arma::mat& X, double* cost = 0, bool ignoreFeatureScaling = false);
    double accuracy(double* cost = 0);
    arma::mat L_model_forward(const arma::mat& X);
    arma::mat linear_activation_forward(const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, ActivationFunction a, size_t l);
    arma::mat linear_forward(const arma::mat& A, const arma::mat& W, const arma::mat& b);
    arma::mat Dropout_Forward(const arma::mat& A);
    double compute_cost_with_regularization(const arma::mat& A3, const arma::mat& Y, ActivationFunction af);
    double compute_cost(const arma::mat& AL, const arma::mat& Y, ActivationFunction af = SIGMOID);
    void L_model_backward(const arma::mat& AL, const arma::mat& Y);
    void linear_activation_backward(const arma::mat& dA, NeuralNetworkV2::ActivationFunction activation, size_t l, const arma::mat& Y);
    void linear_backward(arma::mat dZ, const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, size_t l);
    arma::mat Dropout_Backward(const arma::mat& A);
    
    arma::mat sigmoid( const arma::mat& Z );
    arma::mat tanh( const arma::mat& Z );
    arma::mat relu( arma::mat Z );
    arma::mat leaky_relu( arma::mat Z );
    arma::mat softmax( arma::mat Z );

    arma::mat batchNorm_forward(const arma::mat& Z, const arma::mat& gamma, const arma::mat& beta, arma::mat& running_mean, arma::mat& running_var);
    arma::mat batchNorm_backward(arma::mat dZ, size_t l);
    arma::mat avgBatchParam(std::string key);
    void update_batchnorm_parameters(double learning_rate);

    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override { UNUSED(nn_params); UNUSED(costOnly); return mRetVal; };
    void miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                     double beta = 0.9, double beta1 = 0.9, double beta2 = 0.999,
                                                     double epsilon = 1e-8 );
    bool saveState(std::string prefix);
    bool loadState(std::string prefix);
    void continueMinibatch(long long epoch);

private:    
    arma::umat mLayerSizes; // input layer, hidden1, hidden2, ..., output
    ActivationFunction mHiddenLAF;
    ActivationFunction mOuputLAF;
    Util::UStringMatMap mParameters;
    Util::UStringMatMap mGrads;
    std::stack<arma::mat> mCaches;
    std::stack<arma::mat> mDropOutCache;

    typedef Util::UStringMatMap BatchNormItem;
    std::vector<BatchNormItem> mBatchNorm;
    BatchNormItem* mLastBNI;
    std::stack<arma::mat> mBNCaches;

    double mKeepProb;
    
    // minibatch parameters
    size_t mBatchSize;
    double mLearningRate;
    Optimizer mOptimizer;
    bool mInitializedFromFile;
    bool mBatchNormEnabled;
};

#endif // __NEURAL_NETWORKV2_H__
