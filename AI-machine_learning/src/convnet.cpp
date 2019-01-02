#include "convnet.h"

ConvNet::ConvNet()
{

}

ConvNet::ConvNet(std::string prefix)
{

}

arma::mat ConvNet::forward(arma::mat4D X) {
    arma::mat X2;
    bool fD = true;
    
    // Az utolsó layert is meg kell hívni (softmax)?
    for(ForwardBackwardIF* layer : mLayers) {
        if(layer->is4D()) {
            if(!fD) {
                // reshape mat ==> mat4D
                // X = reshape(X2);
                fD = true;
            }
            X = layer->forward(X);
        } else {
            if(fD) {
                // reshape mat ==> mat4D
                // X2 = arma::vectorize(X);
                fD = false;
            }
            X2 = layer->forward(X2);
        }
    }
    return X2;
}

void ConvNet::backward(arma::mat AL, arma::mat Y) {
    arma::mat4D AL2;
    bool fD = false;
    
    for(size_t i = mLayers.size() - 1; i >= 1; --i) {
        ForwardBackwardIF* layer = mLayers[i - 1];
        if(layer->is4D()) {
            if(!fD) {
                // reshape mat ==> mat4D
                // X2 = reshape(X);
                fD = true;
            }
            AL2 = layer->backward(AL2);
        } else {
            if(fD) {
                // reshape mat ==> mat4D
                // X = arma::vectorize(X2);
                fD = false;
            }
            AL = layer->backward(AL);
        }
    }
}
