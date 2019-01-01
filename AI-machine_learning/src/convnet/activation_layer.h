#ifndef __ACTIVATION_LAYER_H__
#define __ACTIVATION_LAYER_H__

#include "forward_backward_if.h"

class Sigmoid : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
};

class Relu : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
};

class Tanh : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
};

class LeakyRelu : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D mCache; // A
};

class Softmax : public ForwardBackwardIF {
    friend class ActivationLayerTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override { UNUSED(A_prev); return arma::mat4D(); };
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override { UNUSED(dZ); return {arma::mat4D()}; };

    virtual arma::mat forward(arma::mat X) override;

    // Actually we don't need this function
    virtual arma::mat backward(arma::mat dX) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;
private:
    arma::mat mCache; //mY;
};

#endif // __ACTIVATION_LAYER_H__
