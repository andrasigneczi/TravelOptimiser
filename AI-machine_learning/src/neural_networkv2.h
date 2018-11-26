#ifndef __NEURAL_NETWORKV2_H__
#define __NEURAL_NETWORKV2_H__

#include <armadillo>
#include <vector>
#include <stack>
#include <unordered_map>
#include "CostAndGradient.h"
#include "Util.h"

class NeuralNetworkV2 final : public CostAndGradient {
    public:
    
    enum ActivationFunction {
        SIGMOID,
        RELU,
        TANH,
        LRELU,
        SOFTMAX
    };
    
    NeuralNetworkV2(const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda,
                    bool featureScaling = false, ActivationFunction hiddenAF = SIGMOID, 
                    ActivationFunction outputAF = SIGMOID, double keep_prob = 1. );

    void initializeParametersHe();
    void initializeParametersDeep();
    void initializeVelocity();
    void initializeAdam();
    arma::mat predict(const arma::mat& X, double* cost = 0, bool ignoreFeatureScaling = false);
    double accuracy(double* cost = 0);
    arma::mat L_model_forward(const arma::mat& X);
    arma::mat linear_activation_forward(const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, ActivationFunction a);
    arma::mat linear_forward(const arma::mat& A, const arma::mat& W, const arma::mat& b);
    arma::mat Dropout_Forward(const arma::mat& A);
    double compute_cost_with_regularization(const arma::mat& A3, const arma::mat& Y, ActivationFunction af);
    double compute_cost(const arma::mat& AL, const arma::mat& Y, ActivationFunction af = SIGMOID);
    void L_model_backward(const arma::mat& AL, const arma::mat& Y);
    void linear_activation_backward(const arma::mat& dA, NeuralNetworkV2::ActivationFunction activation, size_t l, const arma::mat& Y, const arma::mat& AL);
    void linear_backward(const arma::mat& dZ, const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, size_t l);
    arma::mat Dropout_Backward(const arma::mat& A);
    void update_parameters(double learning_rate);
    void update_parameters_with_momentum(double beta, double learning_rate);
    void update_parameters_with_adam(double t, double learning_rate = 0.01,
                                double beta1 = 0.9, double beta2 = 0.999,  double epsilon = 1e-8);
    void L_layer_model(const arma::mat& X, const arma::mat& Y, double learning_rate = 0.0075, int num_iterations = 3000, bool verbose = true );
    
    arma::mat sigmoid( const arma::mat& Z );
    arma::mat tanh( const arma::mat& Z );
    arma::mat relu( arma::mat Z );
    arma::mat leaky_relu( arma::mat Z );
    arma::mat softmax( arma::mat Z );
    
    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override { UNUSED(nn_params); UNUSED(costOnly); return mRetVal; };
    void miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                     std::string optimizer = "gd", double beta = 0.9, double beta1 = 0.9, double beta2 = 0.999, 
                                                     double epsilon = 1e-8 );
    bool saveState(std::string prefix);
    bool loadState(std::string prefix);
    void continueMinibatch(long long epoch);

private:    
    const arma::mat& mLayerSizes; // input layer, hidden1, hidden2, ..., output
    ActivationFunction mHiddenLAF;
    ActivationFunction mOuputLAF;
    std::unordered_map<std::string,arma::mat> mParameters;
    std::unordered_map<std::string,arma::mat> mGrads;
    std::stack<arma::mat> mCaches;
    std::stack<arma::mat> mDropOutCache;
    std::unordered_map<std::string,arma::mat> mVelocity;
    std::unordered_map<std::string,arma::mat> mAdamS;
    double mKeepProb;
    
    // minibatch parameters
    int mAdamCounter;
    size_t mBatchSize;
    double mLearningRate;
    std::string mOptimizer;
    double mBeta;
    double mBeta1;
    double mBeta2; 
    double mEpsilon;
    
};

#endif // __NEURAL_NETWORKV2_H__
