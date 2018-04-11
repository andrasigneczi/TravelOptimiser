#include <armadillo>
#include "neural_network.h"
#include <neural_network.h>
#include <fmincg.h>

namespace NeuralNetwork_ns {
    
void test1();
void test2();
void test3();
void test4();

void runTests() {
    test1();
}

void test1() {
    arma::mat X, y, Theta1, Theta2;
    
    Theta1.load("ex3weights_Theta1.bin");
    Theta2.load("ex3weights_Theta2.bin");
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");
    
    const arma::mat thetaSizes;
    NeuralNetwork nn(thetaSizes, X, y, 0);
    arma::mat pred = nn.predict(X, Theta1, Theta2);
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
}
    
} // NeuralNetwork_ns