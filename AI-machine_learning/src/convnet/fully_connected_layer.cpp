#include "fully_connected_layer.h"

FullyConnectedLayer::FullyConnectedLayer() {
    //for(int i = 0; i < f_H; ++i) {
    //    mW.push_back(arma::randu(f_W, n_C_prev, n_C));
    //}
    //mB.push_back(arma::randu(1, 1, n_C));

}

arma::mat4D FullyConnectedLayer::forward(arma::mat4D A_prev) {
    // arma::mat4D Z = Util::plus(W*A_prev, b);
    // return Z;
}

std::vector<arma::mat4D> FullyConnectedLayer::backward(arma::mat4D dZ) {
    // size_t m = A_prev.n_cols;
    // arma::mat4D dW = 1./m*dZ * A_prev.t() + mLambda/m*W;
    // arma::mat4D db = 1./m*arma::sum(dZ,1);
    // arma::mat4D dA_prev = W.t() * dZ;
}

void FullyConnectedLayer::saveState(std::ofstream& output) {

}

void FullyConnectedLayer::loadState(std::ifstream& input) {

}
