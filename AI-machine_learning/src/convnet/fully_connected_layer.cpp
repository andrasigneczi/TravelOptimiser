#include "fully_connected_layer.h"

// size_H: number if output connections
// size_W: number if input connections
FullyConnectedLayer::FullyConnectedLayer(int size_H, int size_W, double lambda, CNOptimizer::Type optimizerType)
    : mOptimizer(optimizerType, mW, mB, mdW, mdb){
    mW = arma::randu(size_H, size_W) * sqrt(2./size_W);
    mB = arma::zeros(size_H,1);
    mLambda = lambda;
}

arma::mat FullyConnectedLayer::forward(arma::mat A_prev) {
    mCache = A_prev;
    std::cerr << __FUNCTION__ << ": A_prev:" << size(A_prev) << "\n";
    std::cerr << __FUNCTION__ << ": mW:" << size(mW) << "\n";
    std::cerr << __FUNCTION__ << ": mB:" << size(mB) << "\n";

    checkPoint(0);

    return Util::plus(mW * A_prev, mB);
}

arma::mat FullyConnectedLayer::backward(arma::mat dZ) {

    checkPoint(1, &dZ);

    arma::mat& A_prev = mCache;
    size_t m = A_prev.n_cols;
    mdW = 1./m*dZ * A_prev.t() + mLambda/m*mW;
    mdb = 1./m*arma::sum(dZ,1);
    mdA = mW.t() * dZ;

    checkPoint(2);

    return mdA;
}

void FullyConnectedLayer::updateParameters(double learning_rate /*= 0.01*/, double beta /*= 0.9*/,
                                           double beta1 /*= 0.9*/, double beta2 /*= 0.999*/,  double epsilon /*= 1e-8*/) {
    mOptimizer.updateParameters(learning_rate, beta, beta1, beta2,  epsilon);
}

void FullyConnectedLayer::saveState(std::ofstream& output) {
    UNUSED(output);
}

void FullyConnectedLayer::loadState(std::ifstream& input) {
    UNUSED(input);
}
