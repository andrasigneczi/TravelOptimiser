#include "neural_networkv2.h"

NeuralNetworkV2::NeuralNetworkV2( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda,
                              bool featureScaling, NeuralNetworkV2::ActivationFunction af )
    : CostAndGradient(X, y, lambda)
    , mLayerSizes(layerSizes)
    , mAF(af)
{
    if(featureScaling) {
        mX = this->featureScaling(X, true);
    }
}

arma::mat NeuralNetworkV2::sigmoid( const arma::mat& Z ) {
    return 1.0/(1.0+arma::exp(-Z));
}

arma::mat NeuralNetworkV2::tanh( const arma::mat& Z ) {
    const arma::mat pz = arma::exp(Z);
    const arma::mat nz = arma::exp(-Z);
    return (pz - nz)/(pz + nz);
}

arma::mat NeuralNetworkV2::relu( arma::mat Z ) {
    Z.elem( arma::find(Z < 0.0) ).zeros();
    return Z;
}

arma::mat NeuralNetworkV2::leaky_relu( arma::mat Z ) {
    const arma::mat Z2 = Z * 0.01;
    arma::uvec u = arma::find(Z < Z2);
    for( size_t i = 0; i < u.size(); ++i ) {
        if( Z2[i] > Z[i] ) {
            Z[i] = Z2[i];
        }
    }
    return Z;
}

void NeuralNetworkV2::initializeParametersHe() {
    srand (time(NULL));
    
    // parameters -- parameters "W1", "b1", ..., "WL", "bL":
    //               W1 -- weight matrix of shape (layers_dims[1], layers_dims[0])
    //               b1 -- bias vector of shape (layers_dims[1], 1)
    //               ...
    //               WL -- weight matrix of shape (layers_dims[L], layers_dims[L-1])
    //               bL -- bias vector of shape (layers_dims[L], 1)
    size_t L = mLayerSizes.n_cols - 1;
    for( size_t i = 1; i <=L; ++i ) {
        mParameters["W" + std::to_string(i)] = arma::randu(mLayerSizes(0,i), mLayerSizes(0,i-1)) * sqrt(2./mLayerSizes(0,i-1));
        mParameters["b" + std::to_string(i)] = arma::zeros(mLayerSizes(0,i),1);
    }
}

// X -- input data of size (n_x, m)
arma::mat NeuralNetworkV2::predict(const arma::mat& X) {

    //Using the learned parameters, predicts a class for each example in X

    // Computes probabilities using forward propagation, and classifies to 0/1 using 0.5 as the threshold.
    arma::mat A = L_model_forward(X);
    arma::mat predictions = arma::conv_to<arma::mat>::from(arma::find(A>0.5));

    return predictions;   
}

// Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID computation
arma::mat NeuralNetworkV2::L_model_forward(const arma::mat& X) {
    mCaches = std::stack<arma::mat>();
    arma::mat A = X;

    size_t L = mLayerSizes.n_cols - 1;
    // Implement [LINEAR -> RELU]*(L-1). Add "cache" to the "caches" list.
    for( size_t l = 1; l < L; ++l ) {
        A = linear_activation_forward(A, mParameters["W"+ std::to_string(l)], mParameters["b"+ std::to_string(l)], mAF);
    }
    
    // Implement LINEAR -> SIGMOID. Add "cache" to the "caches" list.
    A = linear_activation_forward(A, mParameters["W"+ std::to_string(L)], mParameters["b"+ std::to_string(L)], SIGMOID);

    //assert(AL.shape == (1,X.shape[1]))
            
    return A;
}

// Implement the forward propagation for the LINEAR->ACTIVATION layer
// A_prev -- activations from previous layer (or input data): (size of previous layer, number of examples)
// W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
// b -- bias vector, numpy array of shape (size of the current layer, 1)
// activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"
// Returns:
// A -- the output of the activation function, also called the post-activation value 
// cache -- a python dictionary containing "linear_cache" and "activation_cache";
// stored for computing the backward pass efficiently
arma::mat NeuralNetworkV2::linear_activation_forward(const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, 
                                                     NeuralNetworkV2::ActivationFunction activation) {

    arma::mat Z, A;
    mCaches.push(A_prev);
    mCaches.push(W);
    mCaches.push(b);
    if( activation == SIGMOID ) {
        Z = linear_forward(A_prev, W, b);
        A = sigmoid(Z);
    }
    else if( activation == RELU ) {
        Z = linear_forward(A_prev, W, b);
        A = relu(Z);
    }
    mCaches.push(Z);
    //assert (A.shape == (W.shape[0], A_prev.shape[1]))
    //cache = (linear_cache, activation_cache)

    return A;
}

// Implement the linear part of a layer's forward propagation.
// 
// Arguments:
// A -- activations from previous layer (or input data): (size of previous layer, number of examples)
// W -- weights matrix: numpy array of shape (size of current layer, size of previous layer)
// b -- bias vector, numpy array of shape (size of the current layer, 1)
// 
// Returns:
// Z -- the input of the activation function, also called pre-activation parameter 
// cache -- a python dictionary containing "A", "W" and "b" ; stored for computing the backward pass efficiently
arma::mat NeuralNetworkV2::linear_forward(const arma::mat& A, const arma::mat& W, const arma::mat& b) {
    arma::mat Z = W * A + b;

    //assert(Z.shape == (W.shape[0], A.shape[1]))
    //cache = (A, W, b)
    
    return Z;
}

// Arguments:
// A3 -- post-activation, output of forward propagation, of shape (output size, number of examples)
// Y -- "true" labels vector, of shape (output size, number of examples)
double NeuralNetworkV2::compute_cost_with_regularization(const arma::mat& A3, const arma::mat& Y, double lambd) {
    size_t m = Y.n_cols;
    const arma::mat& W1 = mParameters["W1"];
    const arma::mat& W2 = mParameters["W2"];
    const arma::mat& W3 = mParameters["W3"];
    
    double cross_entropy_cost = compute_cost(A3, Y); // This gives you the cross-entropy part of the cost
    double L2_regularization_cost = 1./m*lambd/2.*(arma::accu(arma::square(W1))+arma::accu(arma::square(W2)) + arma::accu(arma::square(W3)));

    double cost = cross_entropy_cost + L2_regularization_cost;
    
    return cost;
}

// Arguments:
// AL -- probability vector corresponding to your label predictions, shape (1, number of examples)
// Y -- true "label" vector (for example: containing 0 if non-cat, 1 if cat), shape (1, number of examples)
// Returns:
// cost -- cross-entropy cost
double NeuralNetworkV2::compute_cost(const arma::mat& AL, const arma::mat& Y) {
    size_t m = Y.n_cols;

    // Compute loss from aL and y.
    double cost = -1./m*arma::accu(Y * arma::log(AL) + (1.-Y)*arma::log(1.-AL));

    //cost = np.squeeze(cost)      // To make sure your cost's shape is what we expect (e.g. this turns [[17]] into 17).
    //assert(cost.shape == ())
    return cost;
}

// Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR -> SIGMOID group
// 
// Arguments:
// AL -- probability vector, output of the forward propagation (L_model_forward())
// Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
// caches -- list of caches containing:
//             every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
//             the cache of linear_activation_forward() with "sigmoid" (it's caches[L-1])
// 
// Returns:
// grads -- A dictionary with the gradients
//          grads["dA" + str(l)] = ... 
//          grads["dW" + str(l)] = ...
//          grads["db" + str(l)] = ... 
void NeuralNetworkV2::L_model_backward(const arma::mat& AL, const arma::mat& Y) {
    mGrads.clear();
    size_t L = mLayerSizes.n_cols - 1;
    //size_t m = AL.n_cols;
    //Y = Y.reshape(AL.shape) # after this line, Y is the same shape as AL
    
    // Initializing the backpropagation
    arma::mat dAL = - (Y/AL - (1 - Y)/(1 - AL));

    // Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "dAL, current_cache". Outputs: "grads["dAL-1"], grads["dWL"], grads["dbL"]
    //current_cache = caches[L-1]
    // A_prev, W, b, Z
    /*grads["dA" + str(L-1)], grads["dW" + str(L)], grads["db" + str(L)] = */linear_activation_backward(dAL, SIGMOID, L - 1);

    // Loop from l=L-2 to l=0
    for( int l = (int)L - 2; l >= 0; --l ) {
        // lth layer: (RELU -> LINEAR) gradients.
        // Inputs: "grads["dA" + str(l + 1)], current_cache". Outputs: "grads["dA" + str(l)] , grads["dW" + str(l + 1)] , grads["db" + str(l + 1)] 
        //current_cache = caches[l]
        /*dA_prev_temp, dW_temp, db_temp = */linear_activation_backward(mGrads["dA" + std::to_string(l + 1)], RELU, l);
        //grads["dA" + str(l)] = dA_prev_temp
        //grads["dW" + str(l + 1)] = dW_temp
        //grads["db" + str(l + 1)] = db_temp
    }
    
}

// Implement the backward propagation for the LINEAR->ACTIVATION layer.
// 
// Arguments:
// dA -- post-activation gradient for current layer l 
// cache -- tuple of values (linear_cache, activation_cache) we store for computing backward propagation efficiently
// activation -- the activation to be used in this layer, stored as a text string: "sigmoid" or "relu"
// 
// Returns:
// dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
// dW -- Gradient of the cost with respect to W (current layer l), same shape as W
// db -- Gradient of the cost with respect to b (current layer l), same shape as b
void NeuralNetworkV2::linear_activation_backward(const arma::mat& dA, NeuralNetworkV2::ActivationFunction activation, size_t l) {
    //linear_cache, activation_cache = cache
    arma::mat A_prev, W, b, Z, dZ;
    Z = mCaches.top();mCaches.pop();
    b = mCaches.top();mCaches.pop();
    W = mCaches.top();mCaches.pop();
    A_prev = mCaches.top();mCaches.pop();
    
    if( activation == RELU ) {
        //dZ = relu_backward(dA, activation_cache) // dZ=dA*g'(Z)
        Z.elem( arma::find(Z >= 0.0) ).ones();
        dZ = dA % Z;
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    }
    else if( activation == SIGMOID ) {
        //dZ = sigmoid_backward(dA, activation_cache) // dZ=dA*g'(Z)
        dZ = dA % Z % (1. - Z);
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    }
    
    //return dA_prev, dW, db;
}

// Implement the linear portion of backward propagation for a single layer (layer l)
// 
// Arguments:
// dZ -- Gradient of the cost with respect to the linear output (of current layer l)
// cache -- tuple of values (A_prev, W, b) coming from the forward propagation in the current layer
// 
// Returns:
// dA_prev -- Gradient of the cost with respect to the activation (of the previous layer l-1), same shape as A_prev
// dW -- Gradient of the cost with respect to W (current layer l), same shape as W
// db -- Gradient of the cost with respect to b (current layer l), same shape as b
void NeuralNetworkV2::linear_backward(const arma::mat& dZ, const arma::mat& A_prev, const arma::mat& W, const arma::mat& b, size_t l) {
    size_t m = A_prev.n_cols;

    arma::mat dW = 1./m*dZ * A_prev.t();
    arma::mat db = 1./m*arma::sum(dZ,0);
    arma::mat dA_prev = W.t() * dZ;

    mGrads["dA" + std::to_string(l)]     = dA_prev;
    mGrads["dW" + std::to_string(l + 1)] = dW;
    mGrads["db" + std::to_string(l + 1)] = db;

    //assert (dA_prev.shape == A_prev.shape)
    //assert (dW.shape == W.shape)
    //assert (db.shape == b.shape)
    
    //return dA_prev, dW, db;
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
void NeuralNetworkV2::update_parameters(double learning_rate) {
    size_t L = mParameters.size()/2; // 2 # number of layers in the neural network

    // Update rule for each parameter. Use a for loop.
    //for l in range(L):
    for( size_t l = 0; l < L; ++l ) {
        mParameters["W" + std::to_string(l+1)] = mParameters["W" + std::to_string(l+1)] - learning_rate * mGrads["dW" + std::to_string(l+1)];
        mParameters["b" + std::to_string(l+1)] = mParameters["b" + std::to_string(l+1)] - learning_rate * mGrads["db" + std::to_string(l+1)];
    }
}

// Implements a L-layer neural network: [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID.

// Arguments:
// X -- data, numpy array of shape (number of examples, num_px * num_px * 3)
// Y -- true "label" vector (containing 0 if cat, 1 if non-cat), of shape (1, number of examples)
// layers_dims -- list containing the input size and each layer size, of length (number of layers + 1).
// learning_rate -- learning rate of the gradient descent update rule
// num_iterations -- number of iterations of the optimization loop
// print_cost -- if True, it prints the cost every 100 steps

// Returns:
//parameters -- parameters learnt by the model. They can then be used to predict.
void NeuralNetworkV2::L_layer_model(const arma::mat& X, const arma::mat& Y, double learning_rate, int num_iterations, bool verbose ) { // lr was 0.009

    //costs = []                         # keep track of cost
    
    // Parameters initialization. (≈ 1 line of code)
    initializeParametersHe();

    // Loop (gradient descent)
    for( int i = 0; i < num_iterations; ++i ) {

        // Forward propagation: [LINEAR -> RELU]*(L-1) -> LINEAR -> SIGMOID.
        arma::mat AL = L_model_forward(X);

        // Compute cost.
        double cost = compute_cost(AL, Y);

        // Backward propagation.
        L_model_backward(AL, Y);

        // Update parameters.
        update_parameters(learning_rate);

        // Print the cost every 100 training example
        if( verbose && i % 100 == 0 )
            std::cout << "Cost after iteration " << i << ", " << cost << "\n";
        //if( verbose && i % 100 == 0 )
        //    costs.append(cost)
    }
    
    // plot the cost
    //plt.plot(np.squeeze(costs))
    //plt.ylabel('cost')
    //plt.xlabel('iterations (per tens)')
    //plt.title("Learning rate =" + str(learning_rate))
    //plt.show()
}
