#include "convnet.h"
#include "convnet/activation_layer.h"

ConvNet::ConvNet(arma::mat4D& X, arma::mat Y, double lambda) 
: mX(X)
, mY(Y)
, mLambda(lambda)
{

}

ConvNet::ConvNet(std::string prefix)
{
    UNUSED(prefix);
}

ConvNet::~ConvNet()
{
    for(ForwardBackwardIF* layer : mLayers) {
        delete layer;
    }
}

arma::mat ConvNet::forward(arma::mat4D X) {
    arma::mat X2;
    bool fD = true;
    mFlattenedSizes = std::stack<size_t>();
    
    LayerNameVisitor layerNameVisitor;
    // Az utolsó layert is meg kell hívni (softmax)?
    for(ForwardBackwardIF* layer : mLayers) {
        if(layer->is4D()) {
            if(!fD) {
                // reshape mat ==> mat4D
                X = reshape(X2);
                fD = true;
            }
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": before layer forward1: " << X << "\n";
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg1 " << layerNameVisitor.getNameStr(layer) << " input size: " << size(X) << "\n";
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": X: " << X << "\n";
            X = layer->forward(X);
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg2 " << layerNameVisitor.getNameStr(layer) << " output size: " << size(X) << "\n";
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": X: " << X << "\n";
        } else {
            if(fD) {
                // vectorize mat4D ==> mat
                std::cerr << "ConvNet::" << __FUNCTION__ << ": before flatten: " << size(X) << "\n";
                X2 = flatten(X);
                std::cerr << "ConvNet::" << __FUNCTION__ << ": after flatten: " << size(X2) << "\n";
                fD = false;
            }
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": before layer forward2: " << X2 << "\n";
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg3 " << layerNameVisitor.getNameStr(layer) << " input size: " << size(X2) << "\n";
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": X2: " << X2 << "\n";
            X2 = layer->forward(X2);
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg4 " << layerNameVisitor.getNameStr(layer) << " output size: " << size(X2) << "\n";
            //std::cerr << "ConvNet::" << __FUNCTION__ << ": X2: " << X2 << "\n";
        }
    }
    return X2;
}

void ConvNet::backward(arma::mat AL, arma::mat Y) {
    arma::mat4D AL2;
    bool fD = false;
    
    // Initializing the backpropagation from neural network v2
    AL = - (Y/AL - (1. - Y)/(1. - AL));
    
    //AL = Y;

    for(size_t i = mLayers.size(); i >= 1; --i) {
        ForwardBackwardIF* layer = mLayers[i - 1];
        if(layer->is4D()) {
            if(!fD) {
                // reshape mat ==> mat4D
                std::cerr << "ConvNet::" << __FUNCTION__ << ": before reshape: " << size(AL) << "\n";
                AL2 = reshape(AL);
                std::cerr << "ConvNet::" << __FUNCTION__ << ": after reshape: " << size(AL2) << "\n";
                fD = true;
            }
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg1 input size: " << size(AL2) << "\n";
            AL2 = layer->backward(AL2);
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg2 output size: " << size(AL2) << "\n";
        } else {
            if(fD) {
                // vectorize mat4D ==> mat
                std::cerr << "ConvNet::" << __FUNCTION__ << ": before flatten: " << size(AL2) << "\n";
                AL = flatten(AL2);
                std::cerr << "ConvNet::" << __FUNCTION__ << ": after flatten: " << size(AL) << "\n";
                fD = false;
            }
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg3 input size: " << size(AL) << "\n";
            AL = layer->backward(AL);
            std::cerr << "ConvNet::" << __FUNCTION__ << ": dbg4 output size: " << size(AL) << "\n";
        }
    }
}

arma::mat ConvNet::flatten(const arma::mat4D& X) {
    mFlattenedSizes.push(X[0].n_rows);
    mFlattenedSizes.push(X[0].n_cols);
    mFlattenedSizes.push(X[0].n_slices);
    arma::mat retv(X[0].n_rows * X[0].n_cols * X[0].n_slices, X.size());
    for(size_t i = 0; i < X.size(); ++i) {
        retv.col(i) = arma::vectorise(X[i]);
    }
    return retv;
}

arma::mat4D ConvNet::reshape(const arma::mat& X) {
    size_t slice   = mFlattenedSizes.top(); mFlattenedSizes.pop();
    size_t f_W     = mFlattenedSizes.top(); mFlattenedSizes.pop();
    size_t f_H     = mFlattenedSizes.top(); mFlattenedSizes.pop();
    
    arma::mat4D retv = arma::mat4D(X.n_cols);
    
    for(size_t i = 0; i < X.n_cols; ++i) {
        retv[i] = arma::join_slices(retv[i], X.col(i));
        retv[i].reshape(f_H, f_W, slice);
    }
    return retv;
}

// Arguments:
// A3 -- post-activation, output of forward propagation, of shape (output size, number of examples)
// Y -- "true" labels vector, of shape (output size, number of examples)
double ConvNet::compute_cost_with_regularization(const arma::mat& AL, const arma::mat& Y) {
    double m = (double)Y.n_cols;
    double cross_entropy_cost = compute_cost(AL, Y); // This gives you the cross-entropy part of the cost
    double L2_regularization_cost = 0;
    if( mLambda != 0. ){
        for(size_t l = 0; l < mLayers.size(); ++l) {
            //L2_regularization_cost += arma::accu(arma::square(mParameters["W" + std::to_string(l)]));
            L2_regularization_cost += mLayers[l]->getWeightSquareSum();
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
double ConvNet::compute_cost(const arma::mat& AL, const arma::mat& Y) {
    double m = (double)Y.n_cols;
    double cost = 0;
    
    LayerNameVisitor v;
    if( v.getName(mLayers[mLayers.size() - 1]) == IFName::SOFTMAX) {
    //if(true) {
        // Softmax loss:
        // self.loss = (-output * np.log(Y + epsilon)).sum() / Y.shape[0]

        arma::mat maxY = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
        //CERR  << __FUNCTION__ << " maxY: " << size(maxY) << "\n";
        arma::mat ALt = arma::zeros(1,AL.n_cols);
        for( size_t i=0; i < m; ++i ) {
            ALt(0, i) = AL(maxY(0,i), i);
        }
        //cost = np.sum(-np.log(AL[Y.argmax(axis=0),range(m)]))/m;
        //CERR  << __FUNCTION__ << " " << arma::accu(-arma::log(ALt)) << "\n";
        cost = arma::accu(-arma::log(ALt))/(double)m;
        
        //- nd.sum(y * nd.log(yhat+1e-6)
        //cost = -arma::accu(Y % arma::log(AL+1e-6))/m;
    } else {
        // Compute loss from aL and y.
        cost = -1./m*arma::accu(Y % arma::log(AL) + (1.-Y)%arma::log(1.-AL));
    }
    
    //cost = np.squeeze(cost)      // To make sure your cost's shape is what we expect (e.g. this turns [[17]] into 17).
    //assert(cost.shape == ())
    //CERR  << __FUNCTION__ << ": " << cost << "\n";
    return cost;
}

// X -- input data of size (n_x, m)
arma::mat ConvNet::predict(const arma::mat4D& X, double* cost) {

    // no drop out during the prediction
    arma::mat A = forward(X);
    //Softmax softmax;
    //A = softmax.forward(A);
    if(cost){
        // CERR  << __FUNCTION__ << ": dbg1\n";
        *cost = compute_cost_with_regularization(A, mY);
    }
    arma::mat p = arma::conv_to<arma::mat>::from(arma::index_max(A,0));
    return p;   
}

double ConvNet::accuracy(double* cost) {
    arma::mat p = predict(mX, cost);
    arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(mY,0));
    return (double)arma::accu(p==temp)/(double)mY.n_cols*100.;
}

void ConvNet::miniBatchGradientDescent( long long epoch, size_t batchSize, double learning_rate,
                                                double beta, double beta1, double beta2,
                                                double epsilon ) {
    //if(!mInitializedFromFile) {
    //    mBatchSize = batchSize;
    //    mLearningRate = learning_rate;

    //    initializeParametersHe();

    //    mOptimizer.initialize(mLayerSizes.n_cols - 1, mParameters);
    //}

    arma::mat dataset = arma::mat(1,mY.n_cols);
    for(size_t t = 0; t < mY.n_cols;++t) dataset(0,t) = t;

    for( long long i = 0; i < epoch; ++i ) {
        dataset = shuffle(dataset,1);
        for( size_t index = 0; ;++index) {
            size_t l = index * batchSize;
            size_t l_end = l + batchSize - 1;

            if( l >= mX.size() )
                break;

            if( l_end >= mX.size() )
                l_end = mX.size() - 1;
                
            //arma::mat X = arma::mat(mX.n_rows,l_end - l + 1);
            //arma::mat Y = arma::mat(mY.n_rows,l_end - l + 1);
            arma::mat4D X(l_end - l + 1);
            arma::mat Y = arma::mat(mY.n_rows,l_end - l + 1);

            //mX = XSave.cols(l, l_end);
            //mY = YSave.cols(l, l_end);
            for(size_t t = l; t <= l_end;++t){
                X[t-l] = mX[dataset(0,t)];
                Y.col(t-l) = mY.col(dataset(0,t));
            }

            // if(mBatchNormEnabled) { mBatchNorm.initializeEpoch(index, mLayerSizes.n_cols - 1, mParameters); }

            std::cerr  << "ConvNet::" << __FUNCTION__ << " X.size(): " << size(X) << "\n";
            std::cerr  << "ConvNet::" << __FUNCTION__ << " Y.size(): " << size(Y) << "\n";
            //std::cerr  << "ConvNet::" << __FUNCTION__ << " X: " << X << "\n";
            arma::mat AL = forward(X);
            //std::cerr  << "ConvNet::" << __FUNCTION__ << " AL: " << AL << "\n";
            //CERR  << __FUNCTION__ << " dbg2\n";
            // Compute cost.
            //double cost = compute_cost(AL, mY);
            //CERR  << __FUNCTION__ << " dbg3\n";
            // Backward propagation.
            backward(AL, Y);
            std::cerr  << "ConvNet::" << __FUNCTION__ << " dbg4\n";
            // Update parameters.
            //mOptimizer.updateParameters(mParameters, mGrads, learning_rate, beta, beta1, beta2,  epsilon);
            updateParameters(learning_rate, beta, beta1, beta2,  epsilon);

            //if(mBatchNormEnabled) { mBatchNorm.updateParameters(mLayerSizes.n_cols - 1, learning_rate); }
            
            std::cerr  << "ConvNet::" << __FUNCTION__ << " dbg5\n";
        }
        //mBatchNorm.setTrainOff();

        // Print the cost every 100 training example
        if( i % 10 == 0 ){
            double cost=0;
            double acc = accuracy(&cost);
            std::cout << "Iteration: " << i << "; Accuracy: " << acc << "%; " << cost << "\n";
            if(acc == 100. || std::isnan(cost)) {
                break;
            }
        }
    }
}

void ConvNet::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    for(ForwardBackwardIF* layer : mLayers) {
        layer->updateParameters(learning_rate, beta, beta1, beta2,  epsilon);
    }
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
}
