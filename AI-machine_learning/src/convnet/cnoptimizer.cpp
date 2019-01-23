#include "cnoptimizer.h"

template<class Storage>
CNOptimizer<Storage>::CNOptimizer(CNOptimizerType optimizerType, Storage& W, Storage& B, Storage& dW, Storage& db)
    : mW(W)
    , mB(B)
    , mdW(dW)
    , mdb(db)
{
    mOptimizerType = optimizerType;

    switch(mOptimizerType) {
        case GD:
            break;
        case ADAM:
            mdWVelocity = arma::zeros(size(mW));
            mdbVelocity = arma::zeros(size(mB));
            mdWAdamS = arma::zeros(size(mW));
            mdbAdamS = arma::zeros(size(mB));
            mAdamCounter = 0;
            break;
        case MOMENTUM:
            mdWVelocity = arma::zeros(size(mW));
            mdbVelocity = arma::zeros(size(mB));
            break;
    }
}

template<class Storage>
void CNOptimizer<Storage>::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) {
    // gradient descent

    switch(mOptimizerType) {
        case GD:
            update_parameters_with_gd(learning_rate);
            break;
        case ADAM:
            update_parameters_with_adam(learning_rate, beta1, beta2, epsilon, batch_size);
            break;
        case MOMENTUM:
            update_parameters_with_momentum(learning_rate, beta);
            break;
    }
}

template<class Storage>
void CNOptimizer<Storage>::update_parameters_with_gd(double learning_rate) {
    mW = mW - learning_rate * mdW;
    mB = mB - learning_rate * mdb;
}

template<class Storage>
void CNOptimizer<Storage>::update_parameters_with_momentum(double learning_rate, double beta) {
    mdWVelocity = beta * mdWVelocity + (1.-beta) * mdW;
    mdbVelocity = beta * mdbVelocity + (1.-beta) * mdb;

    mW = mW - learning_rate * mdWVelocity;
    mB = mB - learning_rate * mdbVelocity;
}

template<class Storage>
void CNOptimizer<Storage>::update_parameters_with_adam(double learning_rate, double beta1, double beta2,  double epsilon, int batch_size) {
    Storage v_corrected_dW;
    Storage v_corrected_db;
    Storage s_corrected_dW;
    Storage s_corrected_db;

    ++mAdamCounter;
    /*
    alpha = alpha * np.sqrt(1 - np.power(beta2, self.timestamp)) / (1 - np.power(beta1, self.timestamp))
    self.m_kernel = beta1 * self.m_kernel + (1 - beta1) * (self.delta_K + (zeta*self.kernel/batch_size))
    self.m_bias = beta1 * self.m_bias + (1 - beta1) * self.delta_b
    self.v_kernel = beta2 * self.v_kernel + (1 - beta2) * np.square((self.delta_K + (zeta*self.kernel/batch_size)))
    self.v_bias = beta2 * self.v_bias + (1 - beta2) * np.square(self.delta_b)

    self.kernel -= np.divide(alpha * self.m_kernel, (np.sqrt(self.v_kernel) + fudge_factor))
    self.bias -= np.divide(alpha * self.m_bias, (np.sqrt(self.v_bias) + fudge_factor))
     */

    std::cerr << "CNOptimizer<Storage>::" << __FUNCTION__ << ": dbg1\n";
    // Moving average of the gradients. Inputs: "v, grads, beta1". Output: "v".
    mdWVelocity = beta1 * mdWVelocity + (1.-beta1) * mdW;
    mdbVelocity = beta1 * mdbVelocity + (1.-beta1) * mdb;

    std::cerr << "CNOptimizer<Storage>::" << __FUNCTION__ << ": dbg2\n";

    // Compute bias-corrected first moment estimate. Inputs: "v, beta1, t". Output: "v_corrected".
    v_corrected_dW = mdWVelocity/(1.-pow(beta1,mAdamCounter));
    v_corrected_db = mdbVelocity/(1.-pow(beta1,mAdamCounter));

    std::cerr << "CNOptimizer<Storage>::" << __FUNCTION__ << ": dbg3\n";

    // Moving average of the squared gradients. Inputs: "s, grads, beta2". Output: "s".
    mdWAdamS = beta2 * mdWAdamS + (1.-beta2) * arma::pow(mdW, 2);
    mdbAdamS = beta2 * mdbAdamS + (1.-beta2) * arma::pow(mdb, 2);

    std::cerr << "CNOptimizer<Storage>::" << __FUNCTION__ << ": dbg4\n";

    // Compute bias-corrected second raw moment estimate. Inputs: "s, beta2, t". Output: "s_corrected".
    s_corrected_dW = mdWAdamS/(1.-pow(beta2,mAdamCounter));
    s_corrected_db = mdbAdamS/(1.-pow(beta2,mAdamCounter));

    std::cerr << "CNOptimizer<Storage>::" << __FUNCTION__ << ": dbg5\n";

    // Update parameters. Inputs: "parameters, learning_rate, v_corrected, s_corrected, epsilon". Output: "parameters".
    mW = mW - learning_rate * v_corrected_dW / arma::sqrt(s_corrected_dW + epsilon);
    mB = mB - learning_rate * v_corrected_db / arma::sqrt(s_corrected_db + epsilon);
}
