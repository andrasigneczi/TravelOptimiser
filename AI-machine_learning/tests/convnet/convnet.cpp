#include <iostream>
#include <chrono>
#include <armadillo>
#include <ios>
#include "Util.h"
#include "activation.h"
#include "convnet/conv_layer.h"
#include "convnet/pool_layer.h"
#include "convnet/activation_layer.h"
#include "convnet/fully_connected_layer.h"

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

void findTest() {
    arma::mat X;
    X << -1. << -2. << 3. << arma::endr <<
    4. << -5. << -6. << arma::endr <<
    7. << -8. << 9. << arma::endr <<
    -10. << 11. << 12. << arma::endr;
    std::cout << X << "\n";
    std::cout << arma::find(X == -5) << "\n";

    arma::cube Y = arma::randu(2,2,2);
    std::cout << Y << "\n";
    std::cout << arma::find(Y < 0.5) << "\n";
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

    static void conv_backward_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 2);
        arma::mat4D A_prev = arma::randn(10, 4, 4, 3);
        cL.mW = arma::randn(2, 2, 3, 8);
        cL.mB = arma::randn(1, 1, 1, 8);
        arma::mat4D Z = cL.forward(A_prev);
        arma::mat4D dval = cL.backward(Z);
    }

    static void adSlice_test() {
        ConvLayer cL(0, 0, 0, 0, 2, 2);
        arma::mat4D dW = arma::zeros(2,2,3,8);
        arma::cube val = arma::ones(2,2,3);
        cL.addSlice(dW, 1, val);
        std::cout << dW << "\n";
    }
};

class PoolLayerTest {

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

    static void pool_backward_test() {
        arma::arma_rng::set_seed_random();
        PoolLayer cL1(2, 2, 1, PoolLayer::AVG);
        PoolLayer cL2(2, 2, 1, PoolLayer::MAX);
        arma::mat4D A_prev = arma::randn(5, 5, 3, 2);
        arma::mat4D A1 = cL1.forward(A_prev);
        arma::mat4D A2 = cL2.forward(A_prev);

        arma::mat4D dA1 = arma::randn(5, 4, 2, 2);
        arma::mat4D dA1_prev = cL1.backward(dA1);
        arma::mat4D dA2_prev = cL2.backward(dA1);

        std::cout << "A1: " << dA1_prev << "\n";
        std::cout << "A2: " << dA2_prev << "\n";
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
};

class ActivationLayerTest {
public:
    static arma::mat4D initTestVal() {
        arma::mat4D X(5, arma::cube(4,3,2));
        double x = -2.5;
        for(size_t i = 0; i < X.size(); ++i){
            for(size_t j = 0; j < X[i].n_rows; ++j){
                for(size_t k = 0; k < X[i].n_cols; ++k){
                    for(size_t l = 0; l < X[i].n_slices; ++l){
                        X[i](j, k, l) = x;
                        x += 0.07;
                    }
                }
            }
        }
        return X;
    }

    static void activation_test(ForwardBackwardIF& act, std::string label) {
        arma::mat4D X = initTestVal();
        arma::mat4D result = act.forward(X);
        std::cout << label << " forward result:\n";
        std::cout << result;
        std::cout << std::endl;
        std::cout << "\n" << label << " backward result:\n";
        arma::mat4D result2 = act.backward(result); // dZ = dA % activation_backward()
        std::cout << result2 << std::endl << std::endl;
    }

    static void sigmoid_test() {
        Sigmoid s;
        activation_test(s, "Sigmoid");
    }

    static void relu_test() {
        Relu s;
        activation_test(s, "Relu");
    }

    static void tanh_test() {
        Tanh s;
        activation_test(s, "Tanh");
    }

    static void lrelu_test() {
        LeakyRelu s;
        activation_test(s, "Leaky Relu");
    }

    static void softmax_test() {
        Softmax s;
        arma::mat X;
        X << -0.1 << -0.7 << 0.1 << 0.7 << arma::endr <<
             -0.51 << -0.49 << 0.51 << 0.49;
        arma::mat result = s.forward(X);
        std::cout << "Softmax forward result:\n";
        std::cout << result;
        std::cout << std::endl;
        std::cout << "\nSoftmax backward result:\n";
        arma::mat result2 = s.backward(result);
        std::cout << result2 << std::endl << std::endl;
    }
};

class FullyConnectedLayerTest {
public:
    static void fully_connected_test() {
        FullyConnectedLayer s(11, 20);
        arma::mat X;

        X << -10.5 << -5.1 << -3.1 << -0.5 << -0.1 << 0 << 0.1 << 0.5 << 3.1 << 5.1 << 10.6 << -10.5 << -5.1 << -3.1 << -0.5 << -0.1 << 0 << 0.1 << 0.5 << 3.1 << arma::endr <<
        -10.5 << -5.1 << -3.1 << -0.5 << -0.1 << 0 << 0.1 << -10.5 << -5.1 << -3.1 << -0.5 << -0.1 << 0.5 << 3.1 << 5.1 << 10.6 << 0 << 0.1 << 0.5 << 3.1;

        s.mW = arma::mat(11,20);
        s.mB = arma::mat(11,1);
        s.mW.fill(0.13);
        s.mB.fill(0.1);

        arma::mat result = s.forward(X.t());
        std::cout << "FC forward result:\n";
        std::cout << result.t();
        std::cout << std::endl;
        std::cout << "\nFC backward result:\n";
        arma::mat result2 = s.backward(result);
        std::cout << result2.t() << std::endl << std::endl;
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
    //ConvLayerTest::pool_backward_test();
    //findTest();
    ActivationLayerTest::sigmoid_test();
    ActivationLayerTest::relu_test();
    ActivationLayerTest::tanh_test();
    ActivationLayerTest::lrelu_test();
    ActivationLayerTest::softmax_test();
    FullyConnectedLayerTest::fully_connected_test();
}

