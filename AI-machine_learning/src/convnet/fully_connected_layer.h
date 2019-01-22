#ifndef __FULLY_CONNECTED_LAYER_H__
#define __FULLY_CONNECTED_LAYER_H__

#include "forward_backward_if.h"
#include "layerobserver.h"
#include "cnoptimizer.h"
#include <memory>

class FullyConnectedLayer : public ForwardBackwardIF, public LayerSubject
{
    friend class FullyConnectedLayerTest;
public:
     // size_H: number if output connections
     // size_W: number if input connections
    FullyConnectedLayer(int size_H, int size_W, double lambda, CNOptimizerType optimizerType);

    arma::mat4D forward(arma::mat4D A_prev) override { UNUSED(A_prev); return arma::mat4D(); };
    arma::mat4D backward(arma::mat4D dZ) override { UNUSED(dZ); return {arma::mat4D()}; };

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return false; }
    void updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) override;
    void accept(Visitor& visitor) override { visitor.visit(this); }
    double getWeightSquareSum() override { return arma::accu(arma::square(mW)); }
    
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
    std::unique_ptr<CNOptimizer<arma::mat>> mOptimizer;
};

#endif // __FULLY_CONNECTED_LAYER_H__
