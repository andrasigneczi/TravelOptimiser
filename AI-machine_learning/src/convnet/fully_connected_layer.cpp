#include "fully_connected_layer.h"

// size_H: number if output connections
// size_W: number if input connections
FullyConnectedLayer::FullyConnectedLayer(int size_H, int size_W, double lambda) {
    mW = arma::randu(size_H, size_W) * sqrt(2./size_W);
    mB = arma::zeros(size_H,1);
    mLambda = lambda;
}

arma::mat FullyConnectedLayer::forward(arma::mat A_prev) {
    mCache = A_prev;
    std::cerr << __FUNCTION__ << ": A_prev:" << size(A_prev) << "\n";
    std::cerr << __FUNCTION__ << ": mW:" << size(mW) << "\n";
    std::cerr << __FUNCTION__ << ": mB:" << size(mB) << "\n";
    return Util::plus(mW * A_prev, mB);
}

arma::mat FullyConnectedLayer::backward(arma::mat dZ) {
    arma::mat& A_prev = mCache;
    size_t m = A_prev.n_cols;
    mdW = 1./m*dZ * A_prev.t() + mLambda/m*mW;
    mdb = 1./m*arma::sum(dZ,1);
    mdA = mW.t() * dZ;
    return mdA;
}

void FullyConnectedLayer::updateParameters(double learningRate) {
    // gradient descent
    mW = mW - learningRate * mdW;
    mB = mB - learningRate * mdb;
}

void FullyConnectedLayer::saveState(std::ofstream& output) {
    UNUSED(output);
}

void FullyConnectedLayer::loadState(std::ifstream& input) {
    UNUSED(input);
}
