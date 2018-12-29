#include <iostream>
#include <chrono>
#include <armadillo>
#include <ios>
#include "Util.h"
#include "activation.h"
#include "convnet/conv_layer.h"
#include "convnet/pool_layer.h"

using namespace Activation;
using namespace Util;

void sigmoidTest() {
    arma::mat X;
    X << 1. << 2. << 3. << arma::endr <<
    4. << 5. << 6. << arma::endr <<
    7. << 8. << 9. << arma::endr <<
    10. << 11. << 12. << arma::endr;

    arma::mat result = sigmoid(X);
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    std::cout << "Sigmoid result:\n";
    result.raw_print(std::cout, "");
    std::cout << std::endl;

    std::cout << "\nSigmoid backward result:\n";
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    (result % sigmoid_backward(result)).raw_print(std::cout);
    std::cout << std::endl;
}

void reluTest() {
    arma::mat X;
    X << -1. << -2. << 3. << arma::endr <<
    4. << -5. << -6. << arma::endr <<
    7. << -8. << 9. << arma::endr <<
    -10. << 11. << 12. << arma::endr;

    arma::mat result = relu(X);
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    std::cout << "Relu result:\n";
    result.raw_print(std::cout, "");
    std::cout << std::endl;

    std::cout << "\nRelu backward result:\n";
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    (result % relu_backward(result)).raw_print(std::cout);
    std::cout << std::endl;
}

void softmaxTest() {
    arma::mat X;
    X << -1. << -2. << 3. << arma::endr <<
    4. << -5. << -6. << arma::endr <<
    7. << -8. << 9. << arma::endr <<
    -10. << 11. << 12. << arma::endr;

    arma::mat result = softmax(X);
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    std::cout << "softmax result:\n";
    result.raw_print(std::cout, "");
    std::cout << std::endl;

    std::cout << "\nsoftmax backward result:\n";
    std::cout.precision(11);
    std::cout.setf(std::ios::scientific);
    softmax_backward(result, result).raw_print(std::cout);
    std::cout << std::endl;
}

class ConvLayerTest {
public:
    static void zero_pad_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 0);
        arma::mat4D v(4, arma::randn(3, 3, 2));
        arma::mat4D v_pad = cL.zeroPad(v);
        std::cout.precision(11);
        std::cout.setf(std::ios::scientific);
        std::cout << "Zero Pad 2:\n";
        v[1](arma::span(1), arma::span::all, arma::span::all).raw_print(std::cout);
        v_pad[1](arma::span(1), arma::span::all, arma::span::all).raw_print(std::cout);
        std::cout << std::endl;
    }

    static void conv_single_step_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 0);
        arma::cube a_slice_prev = arma::randn(4, 4, 3);
        arma::cube W = arma::randn(4, 4, 3);
        arma::cube b = arma::randn(1, 1, 1);
        double Z = cL.convSingleStep(a_slice_prev, W, b);
        std::cout << "Z: " << Z << "\n";
    }

    static void conv_forward_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 2);
        arma::mat4D A_prev = arma::randn(10, 4, 4, 3);
        cL.mW = arma::randn(2, 2, 3, 8);
        cL.mB = arma::randn(1, 1, 1, 8);
        arma::mat4D Z = cL.forward(A_prev);
        std::cout << "Z: " << Z << "\n";
        std::cout << Z[3](arma::span(2),arma::span(1), arma::span::all) << "\n";
    }

    static void pool_forward_test() {
        arma::arma_rng::set_seed_random();
        PoolLayer cL1(3, 3, 2, PoolLayer::AVG);
        PoolLayer cL2(3, 3, 2, PoolLayer::MAX);
        arma::mat4D A_prev = arma::randn(2, 4, 4, 3);
        arma::mat4D A1 = cL1.forward(A_prev);
        arma::mat4D A2 = cL2.forward(A_prev);
        std::cout << "A1: " << A1 << "\n";
        std::cout << "A2: " << A2 << "\n";
    }

    static void conv_backward_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 2);
        arma::mat4D A_prev = arma::randn(10, 4, 4, 3);
        cL.mW = arma::randn(2, 2, 3, 8);
        cL.mB = arma::randn(1, 1, 1, 8);
        arma::mat4D Z = cL.forward(A_prev);
        std::vector<arma::mat4D> dval = cL.backward(Z);
    }

    static void adSlice_test() {
        ConvLayer cL(0, 0, 0, 0, 2, 2);
        arma::mat4D dW = arma::zeros(2,2,3,8);
        arma::cube val = arma::ones(2,2,3);
        cL.addSlice(dW, 1, val);
        std::cout << dW << "\n";
    }

    static void createMaskFromWindow_test() {
        PoolLayer cL(3, 3, 2, PoolLayer::MAX);
        arma::mat X(2, 3);
        X << 1 << 2 << 3 << arma::endr << 4 << 5 << 6;
        std::cout << X << "\n";
        X = cL.createMaskFromWindow(X);
        std::cout << X << "\n";
    }

    static void distributeValue_test() {
        PoolLayer cL(3, 3, 2, PoolLayer::MAX);
        arma::mat X = cL.distributeValue(2, 2, 2);
        std::cout << X << "\n";
    }

    static void pool_backward_test() {
        arma::arma_rng::set_seed_random();
        PoolLayer cL1(2, 2, 1, PoolLayer::AVG);
        PoolLayer cL2(2, 2, 1, PoolLayer::MAX);
        arma::mat4D A_prev = arma::randn(5, 5, 3, 2);
        arma::mat4D A1 = cL1.forward(A_prev);
        arma::mat4D A2 = cL2.forward(A_prev);

        arma::mat4D dA1 = arma::randn(5, 4, 2, 2);
        arma::mat4D dA1_prev = cL1.backward(dA1)[0];
        arma::mat4D dA2_prev = cL2.backward(dA1)[0];

        std::cout << "A1: " << dA1_prev << "\n";
        std::cout << "A2: " << dA2_prev << "\n";
    }
};

void convLayerTest() {
    //ConvLayerTest::zero_pad_test();
    //ConvLayerTest::conv_single_step_test();
    //ConvLayerTest::conv_forward_test();
    //ConvLayerTest::pool_forward_test();
    //ConvLayerTest::conv_backward_test();
    //ConvLayerTest::adSlice_test();
    //ConvLayerTest::createMaskFromWindow_test();
    //ConvLayerTest::distributeValue_test();
    ConvLayerTest::pool_backward_test();
}

