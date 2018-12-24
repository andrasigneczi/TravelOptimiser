#include "optimizer.h"

Optimizer::Optimizer(Type type)
    : mType(type)
    , mAdamCounter(0)
{

}

void Optimizer::initialize(size_t L, Util::UStringMatMap& parameters) {
    switch(mType) {
    case GD:
        break;
    case MOMENTUM:
        initializeVelocity(L, parameters);
        break;
    case ADAM:
        initializeAdam(L, parameters);
        break;
    }
}

// for momentum
void Optimizer::initializeVelocity(size_t L, Util::UStringMatMap& parameters) {

    // Initializes the velocity as a python dictionary with:
    //             - keys: "dW1", "db1", ..., "dWL", "dbL"
    //             - values: numpy arrays of zeros of the same shape as the corresponding gradients/parameters.
    // Arguments:
    // parameters -- python dictionary containing your parameters.
    //                 parameters['W' + str(l)] = Wl
    //                 parameters['b' + str(l)] = bl
    //
    // Returns:
    // v -- python dictionary containing the current velocity.
    //                 v['dW' + str(l)] = velocity of dWl
    //                 v['db' + str(l)] = velocity of dbl


    mVelocity.empty();

    // Initialize velocity
    for( size_t l = 0; l <L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        mVelocity["dW" + lp1] = arma::zeros(size(parameters["W" + lp1]));
        mVelocity["db" + lp1] = arma::zeros(size(parameters["b" + lp1]));
    }
}

void Optimizer::initializeAdam(size_t L, Util::UStringMatMap& parameters) {
    // Initializes v and s as two python dictionaries with:
    //             - keys: "dW1", "db1", ..., "dWL", "dbL"
    //             - values: numpy arrays of zeros of the same shape as the corresponding gradients/parameters.
    //
    // Arguments:
    // parameters -- python dictionary containing your parameters.
    //                 parameters["W" + str(l)] = Wl
    //                 parameters["b" + str(l)] = bl
    //
    // Returns:
    // v -- python dictionary that will contain the exponentially weighted average of the gradient.
    //                 v["dW" + str(l)] = ...
    //                 v["db" + str(l)] = ...
    // s -- python dictionary that will contain the exponentially weighted average of the squared gradient.
    //                 s["dW" + str(l)] = ...
    //                 s["db" + str(l)] = ...


    mVelocity.empty();
    mAdamS.empty();

    for( size_t l = 0; l <L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        mVelocity["dW" + lp1] = arma::zeros(size(parameters["W" + lp1]));
        mVelocity["db" + lp1] = arma::zeros(size(parameters["b" + lp1]));
        mAdamS["dW" + lp1]    = arma::zeros(size(parameters["W" + lp1]));
        mAdamS["db" + lp1]    = arma::zeros(size(parameters["b" + lp1]));
    }
}

void Optimizer::updateParameters(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate /*= 0.01*/,
                                 double beta /*= 0.9*/, double beta1 /*= 0.9*/, double beta2 /*= 0.999*/,  double epsilon /*= 1e-8*/) {
    switch(mType) {
    case GD:
        update_parameters_with_gd(parameters, grads, learning_rate);
        break;
    case MOMENTUM:
        update_parameters_with_momentum(parameters, grads, learning_rate, beta);
        break;
    case ADAM:
        ++mAdamCounter;
        update_parameters_with_adam(parameters, grads, learning_rate, beta1, beta2,  epsilon);
        break;
    }
}

// Update parameters using gradient descent
//
// Arguments:
// parameters -- python dictionary containing your parameters
// grads -- python dictionary containing your gradients, output of L_model_backward
//
// Returns:
// parameters -- python dictionary containing your updated parameters
//               parameters["W" + str(l)] = ...
//               parameters["b" + str(l)] = ...
void Optimizer::update_parameters_with_gd(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate) {
    size_t L = parameters.size()/2; // 2 # number of layers in the neural network

    // Update rule for each parameter. Use a for loop.
    //for l in range(L):
    for( size_t l = 0; l < L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        parameters["W" + lp1] = parameters["W" + lp1] - learning_rate * grads["dW" + lp1];
        parameters["b" + lp1] = parameters["b" + lp1] - learning_rate * grads["db" + lp1];
    }
}

void Optimizer::update_parameters_with_momentum(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate, double beta){
    // Arguments:
    // parameters -- python dictionary containing your parameters:
    //                 parameters['W' + str(l)] = Wl
    //                 parameters['b' + str(l)] = bl
    // grads -- python dictionary containing your gradients for each parameters:
    //                 grads['dW' + str(l)] = dWl
    //                 grads['db' + str(l)] = dbl
    // v -- python dictionary containing the current velocity:
    //                 v['dW' + str(l)] = ...
    //                 v['db' + str(l)] = ...
    // beta -- the momentum hyperparameter, scalar
    // learning_rate -- the learning rate, scalar
    //
    // Returns:
    // parameters -- python dictionary containing your updated parameters
    // v -- python dictionary containing your updated velocities

    size_t L = parameters.size()/2;

    // Momentum update for each parameter
    for( size_t l = 0; l < L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        // compute velocities
        mVelocity["dW" +  lp1] = beta * mVelocity["dW" +  lp1] + (1.-beta) * grads["dW" +  lp1];
        mVelocity["db" +  lp1] = beta * mVelocity["db" +  lp1] + (1.-beta) * grads["db" +  lp1];
        // update parameters
        parameters["W" +  lp1] = parameters["W" +  lp1] - learning_rate * mVelocity["dW" +  lp1];
        parameters["b" +  lp1] = parameters["b" +  lp1] - learning_rate * mVelocity["db" +  lp1];
    }
}

void Optimizer::update_parameters_with_adam(Util::UStringMatMap& parameters, Util::UStringMatMap& grads, double learning_rate,
                                double beta1, double beta2,  double epsilon) {
    //Update parameters using Adam
    //
    //Arguments:
    //parameters -- python dictionary containing your parameters:
    //                parameters['W' + str(l)] = Wl
    //                parameters['b' + str(l)] = bl
    //grads -- python dictionary containing your gradients for each parameters:
    //                grads['dW' + str(l)] = dWl
    //                grads['db' + str(l)] = dbl
    //v -- Adam variable, moving average of the first gradient, python dictionary
    //s -- Adam variable, moving average of the squared gradient, python dictionary
    //learning_rate -- the learning rate, scalar.
    //beta1 -- Exponential decay hyperparameter for the first moment estimates
    //beta2 -- Exponential decay hyperparameter for the second moment estimates
    //epsilon -- hyperparameter preventing division by zero in Adam updates

    //Returns:
    //parameters -- python dictionary containing your updated parameters
    //v -- Adam variable, moving average of the first gradient, python dictionary
    //s -- Adam variable, moving average of the squared gradient, python dictionary

    size_t L = parameters.size()/2;
    arma::mat v_corrected_dW;
    arma::mat v_corrected_db;
    arma::mat s_corrected_dW;
    arma::mat s_corrected_db;

    // Perform Adam update on all parameters
    for( size_t l = 0; l < L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        // Moving average of the gradients. Inputs: "v, grads, beta1". Output: "v".
        mVelocity["dW" + lp1] = beta1 * mVelocity["dW" + lp1] + (1.-beta1) * grads["dW" + lp1];
        mVelocity["db" + lp1] = beta1 * mVelocity["db" + lp1] + (1.-beta1) * grads["db" + lp1];

        // Compute bias-corrected first moment estimate. Inputs: "v, beta1, t". Output: "v_corrected".
        v_corrected_dW = mVelocity["dW" + lp1]/(1.-pow(beta1,mAdamCounter));
        v_corrected_db = mVelocity["db" + lp1]/(1.-pow(beta1,mAdamCounter));
        // Moving average of the squared gradients. Inputs: "s, grads, beta2". Output: "s".
        mAdamS["dW" + lp1] = beta2 * mAdamS["dW" + lp1] + (1.-beta2) * arma::pow(grads["dW" + lp1],2.);
        mAdamS["db" + lp1] = beta2 * mAdamS["db" + lp1] + (1.-beta2) * arma::pow(grads["db" + lp1],2.);

        // Compute bias-corrected second raw moment estimate. Inputs: "s, beta2, t". Output: "s_corrected".
        s_corrected_dW = mAdamS["dW" + lp1]/(1.-pow(beta2,mAdamCounter));
        s_corrected_db = mAdamS["db" + lp1]/(1.-pow(beta2,mAdamCounter));

        // Update parameters. Inputs: "parameters, learning_rate, v_corrected, s_corrected, epsilon". Output: "parameters".
        parameters["W" + lp1] = parameters["W" + lp1] - learning_rate * v_corrected_dW / arma::sqrt(s_corrected_dW + epsilon);
        parameters["b" + lp1] = parameters["b" + lp1] - learning_rate * v_corrected_db / arma::sqrt(s_corrected_db + epsilon);
    }
}

void Optimizer::saveState(std::ofstream& output) {
    Util::saveStringUMap(output, mVelocity);
    Util::saveStringUMap(output, mAdamS);

    output.write((const char*)&mAdamCounter,  sizeof(mAdamCounter));
    output.write((const char*)&mBeta,         sizeof(mBeta));
    output.write((const char*)&mBeta1,        sizeof(mBeta1));
    output.write((const char*)&mBeta2,        sizeof(mBeta2));
    output.write((const char*)&mEpsilon,      sizeof(mEpsilon));
}

void Optimizer::loadState(std::ifstream& input) {
    Util::loadStringUMap(input, mVelocity);
    Util::loadStringUMap(input, mAdamS);

    input.read((char*)&mAdamCounter,  sizeof(mAdamCounter));
    input.read((char*)&mBeta,         sizeof(mBeta));
    input.read((char*)&mBeta1,        sizeof(mBeta1));
    input.read((char*)&mBeta2,        sizeof(mBeta2));
    input.read((char*)&mEpsilon,      sizeof(mEpsilon));
}
