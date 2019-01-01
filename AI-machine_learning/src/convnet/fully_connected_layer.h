#ifndef __FULLY_CONNECTED_LAYER_H__
#define __FULLY_CONNECTED_LAYER_H__

#include "forward_backward_if.h"

class FullyConnectedLayer : public ForwardBackwardIF
{
    friend class FullyConnectedLayerTest;
public:
    FullyConnectedLayer();

    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mW; // Weights, kernel
    arma::mat4D mB; // Biases
    arma::mat4D mCache; // A_prev
};

#endif // __FULLY_CONNECTED_LAYER_H__
