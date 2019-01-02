#ifndef __ACTIVATION_LAYER_H__
#define __ACTIVATION_LAYER_H__

#include "forward_backward_if.h"

class Sigmoid : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    Sigmoid(bool fD = true) : m4D(fD) {}
    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return m4D; }
    void updateParameters(double learningRate) override { UNUSED(learningRate); };

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
    arma::mat mCache2; // A
    bool m4D;
};

class Relu : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    Relu(bool fD = true) : m4D(fD) {}
    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return m4D; }
    void updateParameters(double learningRate) override { UNUSED(learningRate); };

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
    arma::mat mCache2; // A
    bool m4D;
};

class Tanh : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    Tanh(bool fD = true) : m4D(fD) {}
    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return m4D; }
    void updateParameters(double learningRate) override { UNUSED(learningRate); };

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
    arma::mat mCache2; // A
    bool m4D;
};

class LeakyRelu : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    LeakyRelu(bool fD = true) : m4D(fD) {}
    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return m4D; }
    void updateParameters(double learningRate) override { UNUSED(learningRate); };

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
    arma::mat mCache2; // A
    bool m4D;
};

class Softmax : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override { UNUSED(A_prev); return arma::mat4D(); };
    arma::mat4D backward(arma::mat4D dZ) override { UNUSED(dZ); return {arma::mat4D()}; };

    arma::mat forward(arma::mat X) override;

    // Actually we don't need this function
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return false; }
    void updateParameters(double learningRate) override { UNUSED(learningRate); };

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;
private:
    arma::mat mCache; //mY;
};

#endif // __ACTIVATION_LAYER_H__
