#include "LeNet5.h"
#include "convnet/activation_layer.h"
#include "convnet/fully_connected_layer.h"
#include "convnet/pool_layer.h"
#include "convnet/conv_layer.h"


LeNet5::LeNet5(arma::mat4D& X, arma::mat Y, double lambda)
: ConvNet(X, Y, lambda)
{
    init();
}

LeNet5::LeNet5(std::string prefix)
: ConvNet(prefix)
{
    init();
}

void LeNet5::init() {
    ConvLayer* convLayer1 = new ConvLayer(5, 5, 1, 6, 0, 1);
    Relu* relu1 = new Relu(true);
    PoolLayer* poolLayer1 = new PoolLayer(2, 2, 2, PoolLayer::MAX);

    ConvLayer* convLayer2 = new ConvLayer(5, 5, 6, 16, 0, 1);
    Relu* relu2 = new Relu(true);
    PoolLayer* poolLayer2 = new PoolLayer(2, 2, 2, PoolLayer::MAX);
    
    // 120x400 invalid 576x15
    FullyConnectedLayer* fullyConnectedLayer3 = new FullyConnectedLayer(120, 400);
    Sigmoid* sigmoid3 = new Sigmoid(false);

    FullyConnectedLayer* fullyConnectedLayer4 = new FullyConnectedLayer(84, 120);
    Sigmoid* sigmoid4 = new Sigmoid(false);
    
    FullyConnectedLayer* fullyConnectedLayer5 = new FullyConnectedLayer(10, 84);
    //Softmax* softmax5 = new Softmax();
    Sigmoid* sigmoid5 = new Sigmoid(false);

    *this << convLayer1 << relu1 << poolLayer1 
    << convLayer2 << relu2 << poolLayer2 
    << fullyConnectedLayer3 << sigmoid3
    << fullyConnectedLayer4 << sigmoid4
    << fullyConnectedLayer5 << sigmoid5; //softmax5;
}
