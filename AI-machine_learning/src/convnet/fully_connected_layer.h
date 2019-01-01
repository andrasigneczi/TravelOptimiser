#ifndef __FULLY_CONNECTED_LAYER_H__
#define __FULLY_CONNECTED_LAYER_H__

#include "forward_backward_if.h"

class FullyConnectedLayer : public ForwardBackwardIF
{
    friend class FullyConnectedLayerTest;
public:
     // size_H: number if output connections
     // size_W: number if input connections
    FullyConnectedLayer(int size_H, int size_W, double lambda = 1e+6);

    arma::mat4D forward(arma::mat4D A_prev) override { UNUSED(A_prev); return arma::mat4D(); };
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override { UNUSED(dZ); return {arma::mat4D()}; };

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;

    void updateParameters(double learningRate) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat mW; // Weights, kernel
    arma::mat mB; // Biases
    arma::mat mCache; // A_prev
    double mLambda;

    arma::mat mdW;
    arma::mat mdb;
    arma::mat mdA;
};

#endif // __FULLY_CONNECTED_LAYER_H__
