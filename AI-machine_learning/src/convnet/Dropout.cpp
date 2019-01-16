#include "Dropout.h"

arma::mat Dropout::forward(arma::mat A) {
    // D1 = np.random.rand(A1.shape[0],A1.shape[1])      # Step 1: initialize matrix D1 = np.random.rand(..., ...)
    // D1 = (D1 < keep_prob)                             # Step 2: convert entries of D1 to 0 or 1 (using keep_prob as the threshold)
    // A1 = A1 * D1                                      # Step 3: shut down some neurons of A1
    // A1 = A1 / keep_prob                               # Step 4: scale the value of neurons that haven't been shut down
    arma::mat D = arma::randu(size(A));
    arma::uvec cond1 = arma::find(D < mKeepProb);
    arma::uvec cond2 = arma::find(D >= mKeepProb);
    D.elem(cond1).fill(1.);
    D.elem(cond2).fill(0.);
    mCache = D;
    return (A % D) / mKeepProb;
}

arma::mat Dropout::backward(arma::mat dA) {
    // dA2 = dA2 * D2          # Step 1: Apply mask D2 to shut down the same neurons as during the forward propagation
    // dA2 = dA2 / keep_prob   # Step 2: Scale the value of neurons that haven't been shut down
    return (dA % mCache)/mKeepProb;
}

void Dropout::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Dropout::loadState(std::ifstream& input) {
    UNUSED(input);
}

void Dropout::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}
