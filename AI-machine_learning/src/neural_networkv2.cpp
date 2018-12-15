#include "neural_networkv2.h"

NeuralNetworkV2::NeuralNetworkV2( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda,
                              bool featureScaling, NeuralNetworkV2::ActivationFunction hiddenAF, 
                              NeuralNetworkV2::ActivationFunction outputAF, double keep_prob )
    : CostAndGradient(X, y, lambda)
    , mLayerSizes(layerSizes)
    , mHiddenLAF(hiddenAF)
    , mOuputLAF(outputAF)
    , mKeepProb(keep_prob)
{
    if(featureScaling) {
        mX = this->featureScaling(X, true, 0);
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
    // A = np.maximum(0,Z)
    Z.elem( arma::find(Z < 0.0) ).zeros();
    return Z;
}

arma::mat NeuralNetworkV2::leaky_relu( arma::mat Z ) {
    //const arma::mat Z2 = Z * 0.01;
    //arma::uvec u = arma::find(Z < Z2);
    //for( size_t i = 0; i < u.size(); ++i ) {
    //    if( Z2[u[i]] > Z[u[i]] ) {
    //        Z[u[i]] = Z2[u[i]];
    //    }
    //}
    Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    return Z;
}

arma::mat NeuralNetworkV2::softmax( arma::mat Z ) {
    // exps = np.exp(Z - np.max(Z))
    // A = exps / np.sum(exps, axis=1, keepdims=True)    
    std::cerr << __FUNCTION__ << ": dbg1\n";
    arma::mat exps = arma::exp(Util::broadcast_minus(Z,arma::max(Z)));
    //arma::mat exps = arma::exp(Z-Z.max()));
    std::cerr << __FUNCTION__ << ": dbg2\n";
    exps = Util::broadcast_div(exps,arma::sum(exps, 1));
    std::cerr << __FUNCTION__ << ": dbg3\n";

    //arma::mat exps = arma::exp(Z);
    //exps = Util::broadcast_div(exps,arma::sum(exps, 1));
    
    return exps;
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
        std::cerr << __FUNCTION__ << ": W:" << size(mParameters["W" + std::to_string(i)]) << "\n";
        std::cerr << __FUNCTION__ << ": b:" << size(mParameters["b" + std::to_string(i)]) << "\n";
    }
}

void NeuralNetworkV2::initializeParametersDeep() {
    srand (time(NULL));
    size_t L = mLayerSizes.n_cols - 1;

    for( size_t i = 1; i <=L; ++i ) {
        mParameters["W" + std::to_string(i)] = arma::randu(mLayerSizes(0,i), mLayerSizes(0,i-1)) * 0.01;
        mParameters["b" + std::to_string(i)] = arma::zeros(mLayerSizes(0,i),1);
        std::cerr << __FUNCTION__ << ": W:" << size(mParameters["W" + std::to_string(i)]) << "\n";
        std::cerr << __FUNCTION__ << ": b:" << size(mParameters["b" + std::to_string(i)]) << "\n";
    }
}

// for momentum
void NeuralNetworkV2::initializeVelocity() {

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

    
    size_t L = mLayerSizes.n_cols - 1;
    mVelocity.empty();
    
    // Initialize velocity
    for( size_t l = 0; l <L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        mVelocity["dW" + lp1] = arma::zeros(size(mParameters["W" + lp1]));
        mVelocity["db" + lp1] = arma::zeros(size(mParameters["b" + lp1]));
    }
}

void NeuralNetworkV2::initializeAdam() {
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


    size_t L = mLayerSizes.n_cols - 1;
    mVelocity.empty();
    mAdamS.empty();
    
    for( size_t l = 0; l <L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        mVelocity["dW" + lp1] = arma::zeros(size(mParameters["W" + lp1]));
        mVelocity["db" + lp1] = arma::zeros(size(mParameters["b" + lp1]));
        mAdamS["dW" + lp1]    = arma::zeros(size(mParameters["W" + lp1]));
        mAdamS["db" + lp1]    = arma::zeros(size(mParameters["b" + lp1]));
    }
}

// X -- input data of size (n_x, m)
arma::mat NeuralNetworkV2::predict(const arma::mat& X, double* cost, bool ignoreFeatureScaling) {

    //Using the learned parameters, predicts a class for each example in X

    ActivationFunction temp = mOuputLAF;
    mOuputLAF = ActivationFunction::SOFTMAX;
    
    arma::mat X2;
    if(!ignoreFeatureScaling && mFCData.n_cols > 0) {
        X2 = applyFeatureScalingValues(X,0);
    } else {
        X2 = X;
    }
    
    // no drop out during the prediction
    const double keep_prob = mKeepProb;
    mKeepProb = 1.;
    arma::mat A = L_model_forward(X2);
    if(cost){
        std::cerr << __FUNCTION__ << ": dbg1\n";
        *cost = compute_cost_with_regularization(A, mY, mOuputLAF);
    }
    arma::mat p = arma::conv_to<arma::mat>::from(arma::index_max(A,0));
    mKeepProb = keep_prob;
    mOuputLAF = temp;
    return p;   
}

double NeuralNetworkV2::accuracy(double* cost) {
    arma::mat p = predict(mX, cost, true);
    arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(mY,0));
    return (double)arma::accu(p==temp)/(double)mY.n_cols*100.;
}

// Implement forward propagation for the [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID computation
arma::mat NeuralNetworkV2::L_model_forward(const arma::mat& X) {
    mCaches = std::stack<arma::mat>();
    arma::mat A = X;

    std::cerr << __FUNCTION__ << ": dbg1\n";
    size_t L = mLayerSizes.n_cols - 1;
    // Implement [LINEAR -> RELU]*(L-1). Add "cache" to the "caches" list.
    for( size_t l = 1; l < L; ++l ) {
        if(l > 1 && mKeepProb != 1.) A = Dropout_Forward(A);
        A = linear_activation_forward(A, mParameters["W"+ std::to_string(l)], mParameters["b"+ std::to_string(l)], mHiddenLAF);
    }
    std::cerr << __FUNCTION__ << ": dbg2\n";
    if(mKeepProb != 1.) A = Dropout_Forward(A);
    // Implement LINEAR -> SIGMOID. Add "cache" to the "caches" list.
    A = linear_activation_forward(A, mParameters["W"+ std::to_string(L)], mParameters["b"+ std::to_string(L)], mOuputLAF);

    std::cerr << __FUNCTION__ << ": dbg3\n";
    //assert(AL.shape == (1,X.shape[1]))
            
    return A;
}

arma::mat NeuralNetworkV2::Dropout_Forward(const arma::mat& A) {
    // D1 = np.random.rand(A1.shape[0],A1.shape[1])      # Step 1: initialize matrix D1 = np.random.rand(..., ...)
    // D1 = (D1 < keep_prob)                             # Step 2: convert entries of D1 to 0 or 1 (using keep_prob as the threshold)
    // A1 = A1 * D1                                      # Step 3: shut down some neurons of A1
    // A1 = A1 / keep_prob                               # Step 4: scale the value of neurons that haven't been shut down
    std::cerr << __FUNCTION__ << " dbg1\n";
    arma::mat D = arma::randu(size(A));
    std::cerr << __FUNCTION__ << " dbg2\n";
    arma::uvec cond1 = arma::find(D < mKeepProb);
    std::cerr << __FUNCTION__ << " dbg3\n";
    arma::uvec cond2 = arma::find(D >= mKeepProb);
    std::cerr << __FUNCTION__ << " dbg4\n";
    D.elem(cond1).fill(1.);
    std::cerr << __FUNCTION__ << " dbg5\n";
    D.elem(cond2).fill(0.);
    std::cerr << __FUNCTION__ << " dbg6\n";
    mDropOutCache.push(D);
    return (A % D) / mKeepProb;
}

arma::mat NeuralNetworkV2::Dropout_Backward(const arma::mat& dA) {
    // dA2 = dA2 * D2          # Step 1: Apply mask D2 to shut down the same neurons as during the forward propagation
    // dA2 = dA2 / keep_prob   # Step 2: Scale the value of neurons that haven't been shut down
    arma::mat D = mDropOutCache.top();mDropOutCache.pop();
    return (dA % D)/mKeepProb;
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
    
    std::cerr << __FUNCTION__ << ": dbg1\n";
    
    Z = linear_forward(A_prev, W, b);
    if( activation == SIGMOID ) {
        std::cerr << __FUNCTION__ << ": dbg3\n";
        A = sigmoid(Z);
    } else if( activation == RELU ) {
        std::cerr << __FUNCTION__ << ": dbg5\n";
        A = relu(Z);
    } else if( activation == TANH ) {
        std::cerr << __FUNCTION__ << ": dbg5\n";
        A = tanh(Z);
    } else if( activation == SOFTMAX ) {
        std::cerr << __FUNCTION__ << ": dbg5\n";
        A = softmax(Z);
    } else if( activation == LRELU ) {
        std::cerr << __FUNCTION__ << ": dbg5\n";
        A = leaky_relu(Z);
    }
    std::cerr << __FUNCTION__ << ": dbg6\n";
    mCaches.push(A);
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
    std::cerr << __FUNCTION__ << ": dbg1\n";
    std::cerr << "W: " << size(W) << "\nA: " << size(A) << "\nb: " << size(b) << "\n";
    //arma::mat Z = W * A + b; // broadcast
    arma::mat Z = Util::broadcast_plus(W*A, b);
    std::cerr << __FUNCTION__ << ": dbg2\n";
    //assert(Z.shape == (W.shape[0], A.shape[1]))
    //cache = (A, W, b)
    
    return Z;
}

// Arguments:
// A3 -- post-activation, output of forward propagation, of shape (output size, number of examples)
// Y -- "true" labels vector, of shape (output size, number of examples)
double NeuralNetworkV2::compute_cost_with_regularization(const arma::mat& AL, const arma::mat& Y, ActivationFunction af) {
    double m = (double)Y.n_cols;
    double cross_entropy_cost = compute_cost(AL, Y, af); // This gives you the cross-entropy part of the cost
    double L2_regularization_cost = 0;
    if( mLambda != 0. ){
        size_t L = mParameters.size()/2;
        for(size_t l = 1; l <= L; ++l) {
            L2_regularization_cost += arma::accu(arma::square(mParameters["W" + std::to_string(l)]));
        }
        L2_regularization_cost = 1./m*mLambda/2.*(L2_regularization_cost);
    }
    return cross_entropy_cost + L2_regularization_cost;
}

// Arguments:
// AL -- probability vector corresponding to your label predictions, shape (1, number of examples)
// Y -- true "label" vector (for example: containing 0 if non-cat, 1 if cat), shape (1, number of examples)
// Returns:
// cost -- cross-entropy cost
double NeuralNetworkV2::compute_cost(const arma::mat& AL, const arma::mat& Y, ActivationFunction af) {
    double m = (double)Y.n_cols;
    double cost = 0;
    
    if(af == SOFTMAX) {
        arma::mat maxY = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
        std::cerr << __FUNCTION__ << " maxY: " << size(maxY) << "\n";
        arma::mat ALt = arma::zeros(1,AL.n_cols);
        for( size_t i=0; i < m; ++i ) {
            ALt(0, i) = AL(maxY(0,i), i);
        }
        //cost = np.sum(-np.log(AL[Y.argmax(axis=0),range(m)]))/m;
        std::cerr << __FUNCTION__ << " " << arma::accu(-arma::log(ALt)) << "\n";
        cost = arma::accu(-arma::log(ALt))/(double)m;
        
        //- nd.sum(y * nd.log(yhat+1e-6)
        //cost = -arma::accu(Y % arma::log(AL+1e-6))/m;
    } else {
        // Compute loss from aL and y.
        cost = -1./m*arma::accu(Y % arma::log(AL) + (1.-Y)%arma::log(1.-AL));
    }
    
    //cost = np.squeeze(cost)      // To make sure your cost's shape is what we expect (e.g. this turns [[17]] into 17).
    //assert(cost.shape == ())
    std::cerr << __FUNCTION__ << ": " << cost << "\n";
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
    arma::mat dAL = - (Y/AL - (1. - Y)/(1. - AL));

    // Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "dAL, current_cache". Outputs: "grads["dAL-1"], grads["dWL"], grads["dbL"]
    //current_cache = caches[L-1]
    // A_prev, W, b, Z
    /*grads["dA" + str(L-1)], grads["dW" + str(L)], grads["db" + str(L)] = */linear_activation_backward(dAL, mOuputLAF, L - 1, Y, AL);

    // Loop from l=L-2 to l=0
    for( int l = (int)L - 2; l >= 0; --l ) {
        // lth layer: (RELU -> LINEAR) gradients.
        // Inputs: "grads["dA" + str(l + 1)], current_cache". Outputs: "grads["dA" + str(l)] , grads["dW" + str(l + 1)] , grads["db" + str(l + 1)] 
        //current_cache = caches[l]
        arma::mat dA  = mGrads["dA" + std::to_string(l + 1)];
        if(mKeepProb != 1.) dA = Dropout_Backward(dA);
        /*dA_prev_temp, dW_temp, db_temp = */linear_activation_backward(dA, mHiddenLAF, l, Y, AL);
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
void NeuralNetworkV2::linear_activation_backward(const arma::mat& dA, NeuralNetworkV2::ActivationFunction activation, size_t l,
                                                 const arma::mat& Y, const arma::mat& AL) {
    //linear_cache, activation_cache = cache
    arma::mat A_prev, W, b, gZ, dZ;
    gZ = mCaches.top();mCaches.pop();
    b = mCaches.top();mCaches.pop();
    W = mCaches.top();mCaches.pop();
    A_prev = mCaches.top();mCaches.pop();
    
    std::cerr << __FUNCTION__ << " dbg1\n";
    std::cerr << "gZ:" << size(gZ) << "\n";
    std::cerr << "Y:" << size(Y) << "\n";
    std::cerr << "dA:" << size(dA) << "\n";
    
    if( activation == RELU ) {
        //dZ = np.multiply(dA, np.int64(activation_cache > 0))
        gZ.elem( arma::find(gZ > 0.0) ).ones();
        gZ.elem( arma::find(gZ <= 0.0) ).zeros();
        dZ = dA % gZ;
        std::cerr << "relu dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == SIGMOID ) {
        //dZ = sigmoid_backward(dA, activation_cache) // dZ=dA*g'(Z)
        dZ = dA % gZ % (1. - gZ);
        std::cerr << "sigmoid dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == TANH ) {
        //dZ = dA % (1. - arma::square(gZ));
        dZ = dA % (1. - arma::pow(gZ,2));
        std::cerr << "tanh dZ:" << size(dZ) << "\n";
        /*dA_prev, dW, db = */linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == SOFTMAX ) {

        size_t m = Y.n_cols;
        //gZ[Y.argmax(axis=0),range(m)] -= 1
        std::cerr << __FUNCTION__ << " softmax dbg1\n";
        arma::mat maxS = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
        arma::mat dZ = gZ;
        std::cerr << __FUNCTION__ << " softmax dbg2\n";
        std::cerr << "maxS:" << size(maxS) << "\n";
        for(size_t i = 0; i < m; ++i){
            //gZ[maxS(0,i), i] -= 1;
            dZ(maxS(0,i),i) -= 1;
        }
        std::cerr << __FUNCTION__ << " softmax dbg3\n";
        dZ = dZ/(double)m;

        // coursera: dZ = Yhat - y
        //dZ = AL - Y;
        
        std::cerr << "softmax dZ:" << size(dZ) << "\n";
        linear_backward(dZ, A_prev, W, b, l);
    } else if( activation == LRELU ) {
        gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
        gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
        dZ = dA % gZ;
        linear_backward(dZ, A_prev, W, b, l);
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

    std::cerr << __FUNCTION__ << " dZ: " << size(dZ) << "\n";
    std::cerr << __FUNCTION__ << " A_prev: " << size(dZ) << "\n";
    std::cerr << __FUNCTION__ << " W: " << size(W) << "\n";
    arma::mat dW = 1./m*dZ * A_prev.t() + mLambda/m*W;
    arma::mat db = 1./m*arma::sum(dZ,1);
    arma::mat dA_prev = W.t() * dZ;

    mGrads["dA" + std::to_string(l)]     = dA_prev;
    mGrads["dW" + std::to_string(l + 1)] = dW;
    mGrads["db" + std::to_string(l + 1)] = db;

    UNUSED(b);
    UNUSED(l);
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
        std::string lp1 = std::to_string(l+1);
        std::cerr << __FUNCTION__ << ":" << " W" + lp1 << ":" << size(mParameters["W" + lp1])<< "\n";
        std::cerr << __FUNCTION__ << ":" << " b" + lp1 << ":" << size(mParameters["b" + lp1])<< "\n";
        std::cerr << __FUNCTION__ << ":" << " dW" + lp1 << ":" << size(mGrads["dW" + lp1])<< "\n";
        std::cerr << __FUNCTION__ << ":" << " db" + lp1 << ":" << size(mGrads["db" + lp1])<< "\n";
        mParameters["W" + lp1] = mParameters["W" + lp1] - learning_rate * mGrads["dW" + lp1];
        mParameters["b" + lp1] = mParameters["b" + lp1] - learning_rate * mGrads["db" + lp1];
    }
}

void NeuralNetworkV2::update_parameters_with_momentum(double beta, double learning_rate){
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

    size_t L = mParameters.size()/2;
    
    // Momentum update for each parameter
    for( size_t l = 0; l < L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        // compute velocities
        mVelocity["dW" +  lp1] = beta * mVelocity["dW" +  lp1] + (1.-beta) * mGrads["dW" +  lp1];
        mVelocity["db" +  lp1] = beta * mVelocity["db" +  lp1] + (1.-beta) * mGrads["db" +  lp1];
        // update parameters
        mParameters["W" +  lp1] = mParameters["W" +  lp1] - learning_rate * mVelocity["dW" +  lp1];
        mParameters["b" +  lp1] = mParameters["b" +  lp1] - learning_rate * mVelocity["db" +  lp1];
    }
}

void NeuralNetworkV2::update_parameters_with_adam(double t, double learning_rate,
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

    std::cerr << __FUNCTION__ << " dbg1\n";
    
    size_t L = mParameters.size()/2;
    arma::mat v_corrected_dW;
    arma::mat v_corrected_db;
    arma::mat s_corrected_dW;
    arma::mat s_corrected_db;
    
    // Perform Adam update on all parameters
    for( size_t l = 0; l < L; ++l ) {
        std::string lp1 = std::to_string(l+1);
        std::cerr << __FUNCTION__ << " dbg2\n";
        // Moving average of the gradients. Inputs: "v, grads, beta1". Output: "v".
        mVelocity["dW" + lp1] = beta1 * mVelocity["dW" + lp1] + (1.-beta1) * mGrads["dW" + lp1];
        std::cerr << __FUNCTION__ << " dbg3\n";
        mVelocity["db" + lp1] = beta1 * mVelocity["db" + lp1] + (1.-beta1) * mGrads["db" + lp1];
        std::cerr << __FUNCTION__ << " dbg4\n";
        
        // Compute bias-corrected first moment estimate. Inputs: "v, beta1, t". Output: "v_corrected".
        v_corrected_dW = mVelocity["dW" + lp1]/(1.-pow(beta1,t));
        v_corrected_db = mVelocity["db" + lp1]/(1.-pow(beta1,t));
        std::cerr << __FUNCTION__ << " dbg5\n";
        // Moving average of the squared gradients. Inputs: "s, grads, beta2". Output: "s".
        mAdamS["dW" + lp1] = beta2 * mAdamS["dW" + lp1] + (1.-beta2) * arma::pow(mGrads["dW" + lp1],2.);
        mAdamS["db" + lp1] = beta2 * mAdamS["db" + lp1] + (1.-beta2) * arma::pow(mGrads["db" + lp1],2.);
        std::cerr << __FUNCTION__ << " dbg6\n";
        
        // Compute bias-corrected second raw moment estimate. Inputs: "s, beta2, t". Output: "s_corrected".
        s_corrected_dW = mAdamS["dW" + lp1]/(1.-pow(beta2,t));
        s_corrected_db = mAdamS["db" + lp1]/(1.-pow(beta2,t));
        std::cerr << __FUNCTION__ << " dbg7\n";
        
        // Update parameters. Inputs: "parameters, learning_rate, v_corrected, s_corrected, epsilon". Output: "parameters".
        mParameters["W" + lp1] = mParameters["W" + lp1] - learning_rate * v_corrected_dW / arma::sqrt(s_corrected_dW + epsilon);
        mParameters["b" + lp1] = mParameters["b" + lp1] - learning_rate * v_corrected_db / arma::sqrt(s_corrected_db + epsilon);
        std::cerr << __FUNCTION__ << " dbg8\n";
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
    std::cerr << "dbg4\n";
    // Loop (gradient descent)
    for( int i = 0; i < num_iterations; ++i ) {

        // Forward propagation: [LINEAR -> RELU]*(L-1) -> LINEAR -> SIGMOID.
        arma::mat AL = L_model_forward(X);
        std::cerr << "dbg5\n";
        // Compute cost.
        double cost = compute_cost(AL, Y);
        std::cerr << "dbg6\n";
        // Backward propagation.
        L_model_backward(AL, Y);
        std::cerr << "dbg7\n";
        // Update parameters.
        update_parameters(learning_rate);
        std::cerr << "dbg8\n";
        // Print the cost every 100 training example
        if( verbose && i % 100 == 0 ){
            std::cout << "Cost after iteration " << i << ", " << cost << "\n";
            std::cout << "\tAccuracy: " << accuracy() << "%\n";
        }
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

void NeuralNetworkV2::miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                std::string optimizer, double beta, double beta1, double beta2, 
                                                double epsilon ) {
    int adam_counter = 0;
    initializeParametersHe();
    
    // Initialize the optimizer
    if( optimizer == "gd" )
        ; // no initialization required for gradient descent
    else if( optimizer == "momentum" )
        initializeVelocity();
    else if( optimizer == "adam" )
        initializeAdam();
    
    arma::mat dataset = arma::mat(1,mY.n_cols);
    for(size_t t = 0; t < mY.n_cols;++t) dataset(0,t) = t;

    for( long long i = 0; i < epoch; ++i ) {
        shuffle(dataset,1);
        for( size_t index = 0; ;++index) {
            size_t l = index * batchSize;
            size_t l_end = l + batchSize - 1;

            if( l >= mX.n_cols )
                break;

            if( l_end >= mX.n_cols )
                l_end = mX.n_cols - 1;
                
            arma::mat X = arma::mat(mX.n_rows,l_end - l + 1);
            arma::mat Y = arma::mat(mY.n_rows,l_end - l + 1);

            //mX = XSave.cols(l, l_end);
            //mY = YSave.cols(l, l_end);
            for(size_t t = l; t <= l_end;++t){
                X.col(t-l) = mX.col(dataset(0,t));
                Y.col(t-l) = mY.col(dataset(0,t));
            }
            std::cerr << __FUNCTION__ << " dbg1\n";
            // Forward propagation: [LINEAR -> RELU]*(L-1) -> LINEAR -> SIGMOID.
            arma::mat AL = L_model_forward(X);
            std::cerr << __FUNCTION__ << " dbg2\n";
            // Compute cost.
            //double cost = compute_cost(AL, mY);
            std::cerr << __FUNCTION__ << " dbg3\n";
            // Backward propagation.
            L_model_backward(AL, Y);
            std::cerr << __FUNCTION__ << " dbg4\n";
            // Update parameters.
            if( optimizer == "gd")
                update_parameters(learning_rate);
            else if( optimizer == "momentum")
                update_parameters_with_momentum(beta,learning_rate);
            else if( optimizer == "adam" ) {
                ++adam_counter;
                update_parameters_with_adam(adam_counter, learning_rate, beta1, beta2,  epsilon);
            }
            
            std::cerr << __FUNCTION__ << " dbg5\n";
        }
    
        // Print the cost every 100 training example
        if( i % 100 == 0 ){
            double cost=0;
            double acc = accuracy(&cost);
            std::cout << "Iteration: " << i << "; Accuracy: " << acc << "%; " << cost << "\n";
        }
    }
}

bool NeuralNetworkV2::saveState(std::string prefix) {
    mX.save((prefix + "_x.bin").c_str());
    mY.save((prefix + "_y.bin").c_str());
    mLayerSizes.save((prefix + "_layersizes.bin").c_str());
    mFCData.save((prefix + "_fcdata.bin").c_str());

    std::ofstream output(prefix +"_other.bin", std::ios::binary | std::ios::trunc | std::ios::out);
    output.write((const char*)&mHiddenLAF,    sizeof(mHiddenLAF));
    output.write((const char*)&mOuputLAF,     sizeof(mOuputLAF));
    output.write((const char*)&mKeepProb,     sizeof(mKeepProb));
    output.write((const char*)&mLambda,       sizeof(mLambda));
    output.write((const char*)&mAdamCounter,  sizeof(mAdamCounter));
    output.write((const char*)&mBatchSize,    sizeof(mBatchSize));
    output.write((const char*)&mLearningRate, sizeof(mLearningRate));
    output.write((const char*)&mBeta,         sizeof(mBeta));
    output.write((const char*)&mBeta1,        sizeof(mBeta1));
    output.write((const char*)&mBeta2,        sizeof(mBeta2));
    output.write((const char*)&mEpsilon,      sizeof(mEpsilon));
    size_t temp = mOptimizer.size();
    output.write((const char*)&temp,      sizeof(temp));
    output.write((const char*)mOptimizer.c_str(),      temp);
    /*
    mParameters;
    mGrads;
    mVelocity;
    mAdamS;
    */
    return true;
}

bool NeuralNetworkV2::loadState(std::string prefix) {
    return true;
}

void NeuralNetworkV2::continueMinibatch(long long epoch) {
}
