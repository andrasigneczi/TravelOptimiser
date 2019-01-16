#include <iostream>
#include <chrono>
#include <armadillo>
#include <ios>
#include <Util.h>
#include "activation.h"
#include <convnet/conv_layer.h>
#include <convnet/pool_layer.h>
#include <convnet/activation_layer.h>
#include <convnet/fully_connected_layer.h>
#include <LeNet5.h>
#include <CostAndGradient.h>
#include <neural_networkv2.h>
#include <MNIST.h>

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

void fill4D(arma::mat4D& X, double startVal, double step) {
    double val = startVal;
    for(size_t i = 0; i < X.size(); ++i) {
        for(size_t j = 0; j < X[i].n_rows; ++j) {
            for(size_t k = 0; k < X[i].n_cols; ++k) {
                for(size_t l = 0; l < X[i].n_slices; ++l) {
                    X[i](j, k, l) = val;
                    val += step;
                }
            }
        }
    }
}

class ConvLayerTest {
public:
    static void zero_pad_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 0, CNOptimizerType::GD);
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
        ConvLayer cL(0, 0, 0, 0, 2, 0, CNOptimizerType::GD);
        arma::cube a_slice_prev = arma::randn(4, 4, 3);
        arma::cube W = arma::randn(4, 4, 3);
        arma::cube b = arma::randn(1, 1, 1);
        double Z = cL.convSingleStep(a_slice_prev, W, b);
        std::cout << "Z: " << Z << "\n";
    }

    static arma::mat4D convForwardCalculation(ConvLayer& cL, arma::mat4D& A_prev) {
        // number of images
        size_t m = A_prev.size();

        // image size: n_H_prev x n_W_prev x n_C_prev
        // height
        size_t n_H_prev = A_prev[0].n_rows;

        // width
        size_t n_W_prev = A_prev[0].n_cols;

        // if it's RGB, then slices = 3, every color has its own layer
        //size_t n_C_prev = A_prev[0].n_slices;


        // filter: n_C x f_H x f_W x f_C_prev
        // number of filters
        size_t n_C      = cL.mW.size();

        // height
        size_t f_H      = cL.mW[0].n_rows;

        // width
        size_t f_W      = cL.mW[0].n_cols;

        // number of channels, must be equal to n_C_prev
        //size_t f_C_prev = cL.mW[0].n_slices;

        // mB: n_C x 1 x 1 x 1

        // Compute the dimensions of the CONV output volume.
        int n_H = (n_H_prev - f_H + 2 * cL.mPad)/cL.mStride + 1;
        int n_W = (n_W_prev - f_W + 2 * cL.mPad)/cL.mStride + 1;

        // Z conv output, array of shape (m, n_H, n_W, n_C)
        // Initialize the output volume Z with zeros.
        arma::mat4D Z(m, arma::zeros(n_H, n_W, n_C));

        // Create A_prev_pad by padding A_prev
        arma::mat4D A_prev_pad = cL.zeroPad(A_prev);

        for(size_t i = 0; i < m; ++i) {
            arma::cube& a_prev_pad_i = A_prev_pad[i];
            for(int h = 0; h < n_H; ++h) {
                for(int w = 0; w < n_W; ++w) {
                    for(size_t c = 0; c < n_C; ++c) {

                        // position on a_prev_pad_i
                        size_t vert_start = h * cL.mStride;
                        size_t vert_end = vert_start + f_H;
                        size_t horiz_start = w * cL.mStride;
                        size_t horiz_end = horiz_start + f_W;

                        // cube from a_prev_pad_i
                        arma::cube slice = a_prev_pad_i(arma::span(vert_start, vert_end - 1),
                                                        arma::span(horiz_start, horiz_end - 1),
                                                        arma::span::all);
                        Z[i](h, w, c) += cL.convSingleStep(slice, cL.mW[c], cL.mB[c]);
                    } // c
                } // w
            } // h
        } // i
        return Z;
    }

    static void initA_prev(arma::mat4D& A_prev) {
        std::vector<std::vector<int>> layer1;
        layer1.push_back({1,2,3,4,5,1});
        layer1.push_back({6,7,8,9,10,1});
        layer1.push_back({11,12,13,14,15,2});
        layer1.push_back({16,17,18,19,20,2});

        std::vector<std::vector<int>> layer2;
        layer2.push_back({-1,-2,-4, -6, -8, 1});
        layer2.push_back({0, 1, 2, 3, 4, 2});
        layer2.push_back({-10,-9,-8, -7, -6, 1});
        layer2.push_back({5, 4, 3, 2, 1, 2});

        std::vector<std::vector<int>> layer3;
        layer3.push_back({2, 1, 0, 3, 4, 1});
        layer3.push_back({-2, -1, 0, -3, -4, 2});
        layer3.push_back({6, -3, 5, -4, 1, 1});
        layer3.push_back({0, 1, 2, 0, 0, 2});

        for(int row = 0; row < 4; ++row) {
            for(int col = 0; col < 6; ++col) {
                // there is only one image
                A_prev[0](row, col, 0) = layer1[row][col];
                A_prev[0](row, col, 1) = layer2[row][col];
                A_prev[0](row, col, 2) = layer3[row][col];
            }
        }
    }

    static std::vector<std::vector<std::vector<int>>> initFilters() {
        std::vector<std::vector<int>> layer1;
        layer1.push_back({1, 0});
        layer1.push_back({1, 0});

        std::vector<std::vector<int>> layer2;
        layer2.push_back({1, 0});
        layer2.push_back({0, 1});

        std::vector<std::vector<int>> layer3;
        layer3.push_back({0, 1});
        layer3.push_back({1, 0});

        std::vector<std::vector<std::vector<int>>> filter;
        filter.push_back(layer1);
        filter.push_back(layer2);
        filter.push_back(layer3);

        return filter;
    }

    static void initW(arma::mat4D& W) {
        auto filter = initFilters();
        for(size_t w = 0; w < W.size(); ++w) { // index of filter
            for(size_t row = 0; row < W[0].n_rows; ++row) { // index of row
                for(size_t col = 0; col < W[0].n_cols; ++col) { // index of col
                    for(size_t layer = 0; layer < W[0].n_slices; ++layer) { // index of layer
                        W[w](row, col, layer) = filter[layer][row][col];
                    }
                }
            }
        }
    }

    static void initW2(arma::mat4D& W) {
        auto filter = initFilters();

        for(size_t row = 0; row < W.size(); ++row) { // index of row
            for(size_t col = 0; col < W[0].n_rows; ++col) { // index of col
                for(size_t layer = 0; layer < W[0].n_cols; ++layer) { // index of layer
                    for(size_t w = 0; w < W[0].n_slices; ++w) { // index of filter
                        W[row](col, layer, w) = filter[layer][row][col];
                    }
                }
            }
        }
    }

    static void initB(arma::mat4D& B) {
        for(size_t i = 0; i < B[0].n_slices; ++i) {
            B[0](0, 0, i) = 0;
        }
    }

    static void initB2(arma::mat4D& B) {
        for(size_t i = 0; i < B.size(); ++i) {
            B[i](0, 0, 0) = 0;
        }
    }

    static void conv_forward_test() {
        arma::arma_rng::set_seed_random();
        // n_C: number of the filters
        // n_C_prev: number of the layers/channels
        // ConvLayer(int f_H, int f_W, int n_C_prev, int n_C, int pad, int stride);
        int f_H = 2, f_W = 2, n_C_prev = 3, n_C = 4, pad = 1, stride = 2;
        ConvLayer cL(f_H, f_W, n_C_prev, n_C, pad, stride, CNOptimizerType::GD);

        // m x height x width x channels
        int m = 1, height = 4, width = 6, channels = n_C_prev;
        arma::mat4D A_prev(m, arma::cube(height, width, channels));
        initA_prev(A_prev);
        cL.mW = arma::mat4D(f_H, arma::cube(f_W, n_C_prev, n_C));
        initW2(cL.mW);
        initB(cL.mB);

        arma::mat4D Z = cL.forward(A_prev);
        std::cout << "Z size: " << size(Z) << "\n";
        std::cout << "Z: " << Z << "\n\n";

        cL.mW = arma::mat4D(n_C, arma::cube(f_H, f_W, n_C_prev));
        cL.mB = arma::mat4D(n_C, arma::cube(1, 1, 1));

        initW(cL.mW);
        initB2(cL.mB);

        arma::mat4D Z2 = convForwardCalculation(cL, A_prev);
        std::cout << "Z2 size: " << size(Z2) << "\n";
        std::cout << "Z2: " << Z2 << std::endl;
        std::cout << "equals: " << ( arma::accu(Z - Z2) == 0. ) << std::endl;
    }

    static void conv_backward_test() {
        arma::arma_rng::set_seed_random();
        ConvLayer cL(0, 0, 0, 0, 2, 2, CNOptimizerType::GD);
        arma::mat4D A_prev = arma::randn(10, 4, 4, 3);
        cL.mW = arma::randn(2, 2, 3, 8);
        cL.mB = arma::randn(1, 1, 1, 8);
        arma::mat4D Z = cL.forward(A_prev);
        arma::mat4D dval = cL.backward(Z);
    }

    static void adSlice_test() {
        ConvLayer cL(0, 0, 0, 0, 2, 2, CNOptimizerType::GD);
        arma::mat4D dW = arma::zeros(2,2,3,8);
        arma::cube val = arma::ones(2,2,3);
        cL.addSlice(dW, 7, val);
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
        fill4D(X, -2.5, 0.07);
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
        FullyConnectedLayer s(11, 20, 0, CNOptimizerType::GD);
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

    static void saveFC1(FullyConnectedLayer* layer, std::ofstream& o) {
        o <<  "linear forward: A_prev:\n" << layer->mCache << "\n";
    }
    static void saveFC2(FullyConnectedLayer* layer, std::ofstream& o) {
        o <<  "linear backward: dW:\n" << layer->mdW << "\n";
        o <<  "linear backward: db:\n" << layer->mdb << "\n";
        o <<  "linear backward: dA_prev:\n" << layer->mdA << "\n";
    }
    static void saveFC3(FullyConnectedLayer* layer, std::ofstream& o) {
        o <<  "linear backward: A_prev:\n" << layer->mCache << "\n";
        o <<  "linear backward: W:\n" << layer->mW << "\n";
        o <<  "linear backward: mLambda:\n" << layer->mLambda << "\n";
    }
    static void saveFC4(FullyConnectedLayer* layer, std::ofstream& o) {
        //Util::saveMat(o, layer->mCache);
        UNUSED(layer);
        UNUSED(o);
    }
    static void saveFC5(FullyConnectedLayer* layer, std::ofstream& o) {
        //Util::saveMat(o, layer->mCache);
        UNUSED(layer);
        UNUSED(o);
    }

    static void printWeights(FullyConnectedLayer* layer, std::ofstream& o, std::string name, int index) {
        o << "\n" << name << "\n";
        o << "size(mParameters[W" << index << "]): " << size(layer->mW) << "\n";
        o << "size(mParameters[b" << index << "]): " << size(layer->mB) << "\n";
        //o << "mParameters[W" << index << "]:\n" << layer->mW << "\n";
        //o << "mParameters[b" << index << "]:\n" << layer->mB << "\n";
    }

    static void copyWeights(FullyConnectedLayer* layer, Util::UStringMatMap& weights, int index) {
        layer->mW = weights["W" + std::to_string(index)];
        layer->mB = weights["b" + std::to_string(index)];
    }
};

class ConvNetTest {
    static arma::mat4D initTestVal() {
        // batch: 15
        // image 32x32x1
        arma::mat4D X(15, arma::cube(32,32,1));
        fill4D(X, -20.5, 0.07);
        return X;
    }

public:
    static void forward_backward_test() {
        arma::mat4D X = initTestVal();
        arma::mat Y(10, 15);
        for(int i = 0; i < 15; ++i) {
            Y(i % 10, i) = 1;
        }
        
        
        ConvNet convNet(X, Y, 1e-8);
        
        // No. of filters: 6
        // Filter size: 5x5
        // Padding: 0
        // Stride: 1
        // Input image: 32x32x1
        //ConvLayer* convLayer = new ConvLayer(5, 5, 1, 6, 0, 1);

        // No. of filters: 6
        // Filter size: 2x2
        // Stride: 2
        // where are the 6 filters?
        //PoolLayer* poolLayer = new PoolLayer(2, 2, 2, PoolLayer::AVG);

        //PoolLayer AVG
        //Sigmoid
        //FullyConnectedLayer
        //Sigmoid
        //Softmax
        
        //FullyConnectedLayer* fullyConnectedLayer = new FullyConnectedLayer(40, 196 * 6);
        
        
        ConvLayer* convLayer1 = new ConvLayer(5, 5, 1, 6, 0, 1, CNOptimizerType::GD);
        Relu* relu1 = new Relu(true);
        PoolLayer* poolLayer1 = new PoolLayer(2, 2, 2, PoolLayer::MAX);

        ConvLayer* convLayer2 = new ConvLayer(5, 5, 6, 16, 0, 1, CNOptimizerType::GD);
        Relu* relu2 = new Relu(true);
        PoolLayer* poolLayer2 = new PoolLayer(2, 2, 2, PoolLayer::MAX);
        
        // 120x400 invalid 576x15
        FullyConnectedLayer* fullyConnectedLayer3 = new FullyConnectedLayer(120, 400, 0, CNOptimizerType::GD);
        Sigmoid* sigmoid3 = new Sigmoid(false);

        FullyConnectedLayer* fullyConnectedLayer4 = new FullyConnectedLayer(84, 120, 0, CNOptimizerType::GD);
        Sigmoid* sigmoid4 = new Sigmoid(false);
        
        FullyConnectedLayer* fullyConnectedLayer5 = new FullyConnectedLayer(10, 84, 0, CNOptimizerType::GD);
        //Softmax* softmax5 = new Softmax();
        Sigmoid* sigmoid5 = new Sigmoid(false);

        convNet << convLayer1 << relu1 << poolLayer1 
        << convLayer2 << relu2 << poolLayer2 
        << fullyConnectedLayer3 << sigmoid3
        << fullyConnectedLayer4 << sigmoid4
        << fullyConnectedLayer5 << sigmoid5; //softmax5;
        
        // arma::mat retv = convNet.forward(X);
        // std::cout << "ConvNet forward result:" << retv << "\n";
        // 
        // std::cout << "cost: " << convNet.compute_cost_with_regularization(retv, Y) << "\n";
        // 
        // convNet.backward(retv, Y);
        convNet.miniBatchGradientDescent(15, 15, 1., 0.001, 0, 0, 0, 0);
    }

    static void loadTrainingset(const uint sampleCount, arma::mat4D& X4D, arma::mat& xx, arma::mat& yy, int& num_labels) {
        srand (time(NULL));
        arma::mat X, y, Xt, yt, Xtraining, Ytraining, Xval, Yval;

        std::cout << "Loading training set and test set\n";

        X.load("../TH_plus_BG_trainingset.bin");
        y.load("../TH_plus_BG_trainingset_result.bin");

        if(X.n_rows > sampleCount) {
            X = X.rows(0, sampleCount - 1);
            y = y.rows(0, sampleCount - 1);
        }
        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);
        X = Xtraining;
        y = Ytraining;
        Xt = Xval;
        yt = Yval;

        std::cout << "Training set original size: " << size(X) << "\n";
        std::cout << "Test set size: " << size(Xt) << "\n";
        std::cout << "Training label set size: " << size(y) << "\n";
        std::cout << "Test label result set size: " << size(yt) << "\n";

        // Conversion to the new format
        X = X.t();
        Xt = Xt.t();

        // finding the minimum and maximum label values
        int minYVal = 100000;
        int maxYVal = 0;

        for(size_t i = 0; i < y.n_rows; ++i){
            if(y(i,0) < minYVal) {
                minYVal = y(i,0);
            }
            if(y(i,0) > maxYVal) {
                maxYVal = y(i,0);
            }
        }
        for(size_t i = 0; i < yt.n_rows; ++i){
            if(yt(i,0) < minYVal) {
                minYVal = yt(i,0);
            }
            if(yt(i,0) > maxYVal) {
                maxYVal = yt(i,0);
            }
        }

        std::cout << "Minumum and maximum y values: " << minYVal << ";" << maxYVal << std::endl;

        num_labels = maxYVal - minYVal + 1;
        yy = arma::zeros(num_labels, y.n_rows);
        for(size_t i = 0; i < y.n_rows; ++i){
            yy(y(i,0) - minYVal,i) = 1;
        }
        arma::mat yyt = arma::zeros(num_labels, yt.n_rows);
        for(size_t i = 0; i < yt.n_rows; ++i){
            yyt(yt(i,0) - minYVal,i) = 1;
        }

        // feature scaling
        class CG : public CostAndGradient {
        public:
            CG(arma::mat&a, arma::mat& b) : CostAndGradient(a,b,0) {}
            RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override {UNUSED(nn_params); UNUSED(costOnly); return mRetVal;}
        };
        arma::mat dummy1, dummy2;
        CG cg(dummy1, dummy2);
        X = cg.featureScaling(X, false, 0);

        // arma::mat X ==> arma::mat4D X
        X4D = arma::mat4D(X.n_cols);
        for(size_t i = 0; i < X.n_cols; ++i) {
            X4D[i] = arma::join_slices(X4D[i], X.col(i));
            X4D[i].reshape(24, 24, 1);
        }
        xx = X;

        std::cout << "Training set converted (4D) size: " << size(X4D) << "\n";
        std::cout << "Training result set size: " << size(yy) << "\n";
        std::cout << "Test result set size: " << size(yyt) << "\n";
    }

    static void ConvNet_test() {
        arma::mat4D X4D;
        arma::mat xx;
        arma::mat yy;
        int num_labels = 0;
        loadTrainingset(132, X4D, xx, yy, num_labels);

        ConvNet convNet(X4D, yy, 0);

        //ConvLayer* convLayer1 = new ConvLayer(5, 5, 1, 6, 0, 1);
        //Sigmoid* relu1 = new Sigmoid(true);
        //PoolLayer* poolLayer1 = new PoolLayer(2, 2, 2, PoolLayer::MAX);
        //
        //ConvLayer* convLayer2 = new ConvLayer(5, 5, 6, 16, 0, 1);
        //Sigmoid* relu2 = new Sigmoid(true);
        //PoolLayer* poolLayer2 = new PoolLayer(2, 2, 2, PoolLayer::MAX);

        FullyConnectedLayer* fullyConnectedLayer4 = new FullyConnectedLayer(4, 576, 0, CNOptimizerType::GD);
        Sigmoid* sigmoid4 = new Sigmoid(false);

        FullyConnectedLayer* fullyConnectedLayer5 = new FullyConnectedLayer(num_labels, 4, 0, CNOptimizerType::GD);
        //Softmax* softmax5 = new Softmax();
        Sigmoid* sigmoid5 = new Sigmoid(false);

        // convNet << convLayer1 << relu1 << poolLayer1
        // << convLayer2 << relu2 << poolLayer2
        // << fullyConnectedLayer4 << sigmoid4
        // << fullyConnectedLayer5 << sigmoid5; //softmax5;

        convNet << fullyConnectedLayer4 << sigmoid4
        << fullyConnectedLayer5 << sigmoid5; //softmax5;

        convNet.miniBatchGradientDescent(10, 132, 1., 0.0001, 0, 0, 0, 0);
    }

    static void flatten_test() {
        arma::mat4D X4D = arma::randn(5, 6, 7, 8);
        arma::mat yy;
        ConvNet convNet(X4D, yy, 0);
        std::cout << "X4D: " << size(X4D) << "\n";
        arma::mat flattened = convNet.flatten(X4D);
        std::cout << "flattened: " << size(flattened) << "\n";
        arma::mat4D X4D2 = convNet.reshape(flattened);
        std::cout << "X4D2: " << size(X4D2) << "\n";
        std::cout << "equals: " << (arma::accu(X4D2 - X4D) == 0) << "\n";
    }

    class NNv2Observer : public LayerObserver {
    public:
        NNv2Observer(NeuralNetworkV2* layer, std::ofstream& o, std::string name)
            : LayerObserver(layer)
            , mLayer(layer)
            , mOut(o)
            , mName(name) {
        }

        void notify(int state) override {

            mOut << "\n" << mName << " : state : " << state << "\n";

            switch(state) {
            case 0: // parameters are initialized, I will save them for the convnet
                mParameters = mLayer->mParameters;
                mOut << "mParameters.size(): " << mParameters.size() << "\n";

                mOut << "size(mParameters[W1]): " << size(mParameters["W1"]) << "\n";
                mOut << "size(mParameters[b1]): " << size(mParameters["b1"]) << "\n";
                //mOut << "mParameters[W1]:\n" << mParameters["W1"] << "\n";
                //mOut << "mParameters[b1]:\n" << mParameters["b1"] << "\n";

                mOut << "size(mParameters[W2]): " << size(mParameters["W2"]) << "\n";
                mOut << "size(mParameters[b2]): " << size(mParameters["b2"]) << "\n";
                //mOut << "mParameters[W2]:\n" << mParameters["W2"] << "\n";
                //mOut << "mParameters[b2]:\n" << mParameters["Wb"] << "\n";
                break;
            case 1: ; break;
            case 2: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear forward: A_prev:\n" << *p << "\n";
            }
                break;
            case 3: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward dZ:\n" << *p << "\n";
            }
                break;
            case 4: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward dW:\n" << *p << "\n";
            }
                break;
            case 5: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward db:\n" << *p << "\n";
            }
                break;
            case 6: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward dA_prev:\n" << *p << "\n";
            }
                break;
            case 7: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward A_prev:\n" << *p << "\n";
            }
                break;
            case 8: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward W:\n" << *p << "\n";
                mOut <<  "linear backward mLambda:\n" << mLayer->mLambda << "\n";
            }
                break;
            }
        }

        Util::UStringMatMap& getWeights() {return mParameters; }

    private:
        NeuralNetworkV2* mLayer;
        std::ofstream& mOut;
        std::string mName;
        Util::UStringMatMap mParameters;
    };

    class FCObserver : public LayerObserver {
    public:
        FCObserver(FullyConnectedLayer* layer, std::ofstream& o, std::string name)
            : LayerObserver(layer)
            , mLayer(layer)
            , mOut(o)
            , mName(name) {
        }

        void notify(int state) override {

            mOut << "\n" << mName << " : state : " << state << "\n";

            switch(state) {
            case 0: FullyConnectedLayerTest::saveFC1(mLayer, mOut); break;
            case 1: {
                arma::mat* p = (arma::mat*)mLayer->getLocVar();
                mOut <<  "linear backward dZ:\n" << *p << "\n";
                FullyConnectedLayerTest::saveFC3(mLayer, mOut);
            }
                break;
            case 2: FullyConnectedLayerTest::saveFC2(mLayer, mOut); break;
            }
        }

    private:
        FullyConnectedLayer* mLayer;
        std::ofstream& mOut;
        std::string mName;
    };


    static void NNv2_vs_ConvNet_test() {
        arma::mat4D X4D;
        arma::mat xx;
        arma::mat yy;
        int num_labels = 0;
        loadTrainingset(400, X4D, xx, yy, num_labels);

        // ----------------------------------------
        // Neural Network v2 with one hidden layer
        // ----------------------------------------
        arma::umat thetaSizes;
        int input_layer_size  = xx.n_rows;
        int hidden_layer_size2 = 90;
        double lambda = 0.001; //0.5; // reguralization
        int iteration = 2000;
        //double alpha = 0.3;
        double alpha = 0.001; // learning rate
        double beta = 0.9, beta1 = 0.9, beta2 = 0.999,  epsilon = 1e-8;
        int batch = 32;
        double keep_prob = 1.; // drop out
        CNOptimizerType optimization = CNOptimizerType::ADAM;
        Optimizer::Type nnv2optimization = Optimizer::Type::ADAM;
        bool batchNorm = false;
        bool featureScaling = false;
        thetaSizes << input_layer_size << hidden_layer_size2 << num_labels; // input, hidden, output

        NeuralNetworkV2 nn(thetaSizes, xx, yy, lambda, featureScaling, NeuralNetworkV2::TANH, NeuralNetworkV2::SOFTMAX,
                           keep_prob, batchNorm, nnv2optimization);
        //std::ofstream osNNv2("NNv2Debug.txt", std::ios::binary | std::ios::trunc | std::ios::out);
        //NNv2Observer obNNv2(&nn, osNNv2, "Neural Network v2");
        std::cout << std::string(80, '*') << "\n";
        std::cout << "Neural Network v2\n";
        std::cout << std::string(80, '*') << "\n";
        //nn.miniBatchGradientDescent(iteration, batch, alpha);
        //std::cout << "Training Set Accuracy: " << nn.accuracy() << "%\n";
        //arma::mat pred = nn.predict(Xt);
        //arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(yyt,0));
        //double acct = (double)arma::accu(pred==temp)/(double)yyt.n_cols*100.;
        //std::cout << "Test Set Accuracy: " << acct << "%\n";

        // ----------------------------------------
        // ConvNet with two fully connected layers
        // ----------------------------------------
        ConvNet convNet(X4D, yy, lambda);

        std::cerr << "ConvNetTest::" << __FUNCTION__ << ": dbg1\n";

        ConvLayer* convLayer1 = new ConvLayer(5, 5, 1, 6, 0, 1, optimization);
        Relu* relu1 = new Relu(true);
        PoolLayer* poolLayer1 = new PoolLayer(2, 2, 2, PoolLayer::MAX);

        std::cerr << "ConvNetTest::" << __FUNCTION__ << ": dbg2\n";

        ConvLayer* convLayer2 = new ConvLayer(5, 5, 6, 16, 0, 1, optimization);
        Relu* relu2 = new Relu(true);
        PoolLayer* poolLayer2 = new PoolLayer(2, 2, 2, PoolLayer::MAX);

        std::cerr << "ConvNetTest::" << __FUNCTION__ << ": dbg3\n";

        FullyConnectedLayer* fullyConnectedLayer4 = new FullyConnectedLayer(hidden_layer_size2, 144, lambda, optimization);
        Sigmoid* sigmoid4 = new Sigmoid(false);

        std::cerr << "ConvNetTest::" << __FUNCTION__ << ": dbg4\n";

        FullyConnectedLayer* fullyConnectedLayer5 = new FullyConnectedLayer(num_labels, hidden_layer_size2, lambda, optimization);
        Softmax* sigmoid5 = new Softmax;

        std::cerr << "ConvNetTest::" << __FUNCTION__ << ": dbg5\n";

        std::cout << std::string(80, '*') << "\n";
        std::cout << "ConvNet\n";
        std::cout << std::string(80, '*') << "\n";

        convNet << convLayer1 << relu1 << poolLayer1 << convLayer2 << relu2 << poolLayer2
                << fullyConnectedLayer4 << sigmoid4
        << fullyConnectedLayer5 << sigmoid5; //softmax5;

        //std::ofstream osFC("ConvNetDebug.txt", std::ios::binary | std::ios::trunc | std::ios::out);
        //FCObserver ob1(fullyConnectedLayer4, osFC, "FC Layer 1");
        //FCObserver ob2(fullyConnectedLayer5, osFC, "FC Layer 2");
        //
        //osFC << "mParameters.size(): " << 2 << "\n";
        //FullyConnectedLayerTest::printWeights(fullyConnectedLayer4, osFC, "FC Layer 1", 1);
        //FullyConnectedLayerTest::printWeights(fullyConnectedLayer5, osFC, "FC Layer 2", 2);
        //FullyConnectedLayerTest::copyWeights(fullyConnectedLayer4, obNNv2.getWeights(), 1);
        //FullyConnectedLayerTest::copyWeights(fullyConnectedLayer5, obNNv2.getWeights(), 2);

        convNet.miniBatchGradientDescent(iteration, batch, keep_prob, alpha, beta, beta1, beta2, epsilon);
        std::cout << "Training Set Accuracy: " << convNet.accuracy() << "%\n";

        // 0. prepare the same image for training
        // 1. weight and bias initialization with the same values
        // open one file for the NNv2 and one for ConvNet
        // the ovservers have to save everything
        // 2. compare the results
    }
    
    static void MNIST_test() {
        Mnist mnist("./mnist");
        mnist.load(Mnist::TRAINING);
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
    //ActivationLayerTest::sigmoid_test();
    //ActivationLayerTest::relu_test();
    //ActivationLayerTest::tanh_test();
    //ActivationLayerTest::lrelu_test();
    //ActivationLayerTest::softmax_test();
    //FullyConnectedLayerTest::fully_connected_test();
    //ConvNetTest::forward_backward_test();
    //ConvNetTest::flatten_test();
    //ConvNetTest::ConvNet_test();
    //ConvNetTest::NNv2_vs_ConvNet_test();
    ConvNetTest::MNIST_test();
}

