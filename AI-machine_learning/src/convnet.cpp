#include "convnet.h"
#include "convnet/activation_layer.h"
#include "convnet/dropout.h"
#include "convnet/batchnormcn.h"

ConvNet::ConvNet(arma::mat4D& X, arma::mat Y, double lambda, bool featureScaling)
: mY(Y)
, mLambda(lambda)
, mFeatureScaling(featureScaling)
, mAccuracy(0)
, mCost(0)
, mInitializedFromFile(false)
{
    if(mFeatureScaling) {
        mX = mFeatureScaler.featureScaling(X, true, 0);
    } else {
        mX = X;
    }
}

ConvNet::ConvNet(std::string prefix)
: mInitializedFromFile(true)
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
    
    LayerNameVisitor layerNameVisitor;
    // Initializing the backpropagation from neural network v2, for sigmoid output
    if(layerNameVisitor.getName(mLayers[mLayers.size() - 1]) == IFName::SOFTMAX) {
        AL = Y;
    } else {
        AL = - (Y/AL - (1. - Y)/(1. - AL));
    }

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
        // Softmax loss:
        // self.loss = (-output * np.log(Y + epsilon)).sum() / Y.shape[0]

        //or: - nd.sum(y * nd.log(yhat+1e-6)
        // np.sum(-np.log(AL[range(m),Y.argmax(axis=1)]))/m
        cost = arma::accu(-Y % arma::log(AL + 1e-6))/(double)m;
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
arma::mat ConvNet::predict(const arma::mat4D& X) {
    arma::mat4D X2;
    if(mFeatureScaling) {
        X2 = mFeatureScaler.applyFeatureScalingValues(X,0);
    } else {
        X2 = X;
    }

    // no drop out during the prediction
    const int keepProb = mKeepProb;
    mKeepProb = 1.0;
    arma::mat p = halfMiniBatch(X2);
    mKeepProb = keepProb;
    return p;
}

double ConvNet::accuracy(double* cost) {
    if(cost) {
        *cost = mCost;
    }
    return mAccuracy;
}

void ConvNet::miniBatchGradientDescent( long long epoch, size_t batchSize, double keep_prob,
                                                double learning_rate,
                                                double beta, double beta1, double beta2,
                                                double epsilon ) {
    //if(!mInitializedFromFile) {
    //    mBatchSize = batchSize;
    //    mLearningRate = learning_rate;

    //    initializeParametersHe();

    //    mOptimizer.initialize(mLayerSizes.n_cols - 1, mParameters);
    //}
    mKeepProb = keep_prob;
    initDroputLayers();
    mBatchSize = batchSize;
    //mBatchNormEnabled;
    mCost = 0;
    mAccuracy = 0;

    arma::mat dataset = arma::mat(1,mY.n_cols);
    for(size_t t = 0; t < mY.n_cols;++t) dataset(0,t) = t;

    for( long long i = 0; i < epoch; ++i ) {
        
        arma::mat prediction;
        double cost = 0;
        dataset = shuffle(dataset,1);
        std::vector<double> subAccuracy;

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

            if(mBatchNormEnabled) {
                initBatchNormLayers(index);
            }

            std::cerr  << "ConvNet::" << __FUNCTION__ << " X.size(): " << size(X) << "\n";
            std::cerr  << "ConvNet::" << __FUNCTION__ << " Y.size(): " << size(Y) << "\n";
            //std::cerr  << "ConvNet::" << __FUNCTION__ << " X: " << X << "\n";
            arma::mat AL = forward(X);
            //std::cerr  << "ConvNet::" << __FUNCTION__ << " AL: " << AL << "\n";
            //CERR  << __FUNCTION__ << " dbg2\n";

            // Compute cost.
            cost += compute_cost_with_regularization(AL, Y) * (double)Y.n_cols;
            prediction = arma::conv_to<arma::mat>::from(arma::index_max(AL,0));
            arma::mat maxIndex = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
            subAccuracy.push_back((double)arma::accu(prediction == maxIndex)/(double)Y.n_cols*100.);

            std::cout << "Step: " << index << "; Batch accuracy: " << subAccuracy.back() << "\n";

            //CERR  << __FUNCTION__ << " dbg3\n";
            // Backward propagation.
            backward(AL, Y);
            std::cerr  << "ConvNet::" << __FUNCTION__ << " dbg4\n";
            // Update parameters.
            //mOptimizer.updateParameters(mParameters, mGrads, learning_rate, beta, beta1, beta2,  epsilon);
            updateParameters(learning_rate, beta, beta1, beta2,  epsilon, X.size());

            //if(mBatchNormEnabled) { mBatchNorm.updateParameters(mLayerSizes.n_cols - 1, learning_rate); }
            
            std::cerr  << "ConvNet::" << __FUNCTION__ << " dbg5\n";
        }
        //mBatchNorm.setTrainOff();

        // Print the cost in every epoch
        mCost = cost / (double)mY.n_cols;
        mAccuracy = 0;
        std::for_each(subAccuracy.begin(), subAccuracy.end(), [this](const double x){ mAccuracy += x; });
        mAccuracy /=  subAccuracy.size();
        std::cout << "Learning rate: " << learning_rate << "\n";
        std::cout << "Iteration: " << i << "; Accuracy: " << mAccuracy << "%; Cost with regularization: " << mCost << "\n";
        if(mAccuracy == 100. || std::isnan(mCost)) {
            break;
        }
    }
    mLearningRate = learning_rate;
}

arma::mat ConvNet::halfMiniBatch(arma::mat4D& X4D) {
    arma::mat prediction;
    for( size_t index = 0; ;++index) {
        size_t l = index * mBatchSize;
        size_t l_end = l + mBatchSize - 1;

        if( l >= X4D.size() )
            break;

        if(index % 100 == 0) {
            std::cout << "index: " << index << "\n";
        }

        if( l_end >= X4D.size() )
            l_end = X4D.size() - 1;

        arma::mat4D X(l_end - l + 1);

        for(size_t t = l; t <= l_end;++t){
            X[t-l] = X4D[t];
        }

        arma::mat AL = forward(X);
        prediction = arma::join_rows(prediction, arma::conv_to<arma::mat>::from(arma::index_max(AL,0)));
    }
    return prediction;
}

void ConvNet::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) {
    for(ForwardBackwardIF* layer : mLayers) {
        layer->updateParameters(learning_rate, beta, beta1, beta2,  epsilon, batch_size);
    }
}

void ConvNet::initDroputLayers() {
    DropoutVisitor v(mKeepProb);
    for(ForwardBackwardIF* layer : mLayers) {
        layer->accept(v);
    }
}

void ConvNet::initBatchNormLayers(int epoch) {
    BatchNormVisitor v(epoch);
    for(ForwardBackwardIF* layer : mLayers) {
        layer->accept(v);
    }
}

/*

Learning rate decay:
--------------------

alpha = 1/(1 + decay_rate*epoch_num)*alpha0
e.g decay_rate=1, alpha0=0.2, epoch_num=current epoch index

Exponential decay:
------------------
alpha=pow(0.95,epuch_num)*alpha0

manual decay
------------
continueMinibatch should receive the alpha parameter

*/
