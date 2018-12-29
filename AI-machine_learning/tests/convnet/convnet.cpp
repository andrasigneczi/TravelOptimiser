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
        std::vector<arma::cube> v(4, arma::randn(3, 3, 2));
        std::vector<arma::cube> v_pad = cL.zeroPad(v);
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
        std::vector<arma::cube> A_prev = arma::randn(10, 4, 4, 3);
        cL.mW = arma::randn(2, 2, 3, 8);
        cL.mB = arma::randn(1, 1, 1, 8);
        std::vector<arma::cube> Z = cL.forward(A_prev);
        std::cout << "Z: " << Z << "\n";
        std::cout << Z[3](arma::span(2),arma::span(1), arma::span::all) << "\n";
    }

    static void pool_forward_test() {
        arma::arma_rng::set_seed_random();
        PoolLayer cL1(3, 3, 2, PoolLayer::AVG);
        PoolLayer cL2(3, 3, 2, PoolLayer::MAX);
        std::vector<arma::cube> A_prev = arma::randn(2, 4, 4, 3);
        std::vector<arma::cube> A1 = cL1.forward(A_prev);
        std::vector<arma::cube> A2 = cL2.forward(A_prev);
        std::cout << "A1: " << A1 << "\n";
        std::cout << "A2: " << A2 << "\n";
    }
};

void convLayerTest() {
    //ConvLayerTest::zero_pad_test();
    //ConvLayerTest::conv_single_step_test();
    //ConvLayerTest::conv_forward_test();
    ConvLayerTest::pool_forward_test();
}

