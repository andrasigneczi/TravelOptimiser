#ifndef CONVNET_H
#define CONVNET_H
#include "convnet/forward_backward_if.h"

/*
 * Layer types
 *  - Convolution
 *  - Pooling
 *  - Fully connected
 *
 * Conv:
 *  number of filters: fc
 *  img: n x n x nc,
 *  filter: f x f x (nc * fc),
 *  padding: p,
 *  stride: s,
 *  utput size: floor((n + 2p - f) / s + 1) x floor((n + 2p - f) / s + 1) x fc
 *
 * Pool: max, avarage
 *  img: nh x nw x nc,
 *  filer: f x f x (nc * fc),
 *  stride: s,
 *  output: floor((nh - f) / s + 1) x floor((nw - f) / s + 1) x (nc * fc)
 *
 * FC:
 *  input: flattened conv layer's
 *
 * Model:
 *  Conv << Relu << MaxPool << Conv << Relu << MaxPool << Fc << Sigmoid << Fc << Sigmoid << Softmax
 *
 * Every step must be an Object, which stores its own cache. So, the backward step will be easy.
 * arma::cube 3D matrix
 * 4D: vector<arma::cube>
 */

class ConvNet
{
public:
    ConvNet();
    ConvNet(std::prefix);
    ConvNet& operator<<(ForwardBackwardIF* obj) { mLayers.push_back(obj); return *this; }

    void miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                    double beta, double beta1, double beta2,
                                                    double epsilon );
    arma::mat4D forward(arma::mat4D X);
    void backward(arma::mat4D AL, arma::mat Y);

    bool saveState(std::string prefix);
    bool loadState(std::string prefix);
    void continueMinibatch(long long epoch);

    arma::mat predict(const arma::mat& X, double* cost = 0, bool ignoreFeatureScaling = false);
    double accuracy(double* cost = 0);

    double compute_cost_with_regularization(const arma::mat& A3, const arma::mat& Y, ActivationFunction af);
    double compute_cost(const arma::mat& AL, const arma::mat& Y, ActivationFunction af = SIGMOID);

private:
    std::vector<ForwardBackwardIF*> mLayers;
};

#endif // CONVNET_H
