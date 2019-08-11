#include <iostream>
//#include "includes"
#include <mlpack/core.hpp>
#include <mlpack/methods/ann/layer/layer.hpp>
#include <mlpack/methods/ann/ffn.hpp>
#include <mlpack/core/optimizers/cne/cne.hpp>
#include <mlpack/core.hpp>
#include <mlpack/methods/logistic_regression/logistic_regression.hpp>
#include <mlpack/methods/ann/layer/layer.hpp>
#include <mlpack/methods/ann/ffn.hpp>
#include <mlpack/core/optimizers/adam/adam.hpp>
#include <mlpack/core/optimizers/adam/adamax_update.hpp>
#include <mlpack/core/optimizers/ada_grad/ada_grad.hpp>
#include <mlpack/core/optimizers/ada_delta/ada_delta.hpp>
#include <mlpack/core/optimizers/gradient_descent/gradient_descent.hpp>
#include <MNIST.h>

using namespace mlpack;
using namespace mlpack::ann;
using namespace mlpack::optimization;

void firstTraining() {
    arma::mat X, Xtest;
    arma::mat Y, Ytest;
    
    const int trainingSize = 50000;
    Mnist mnist("../convnet/mnist");
    mnist.load(Mnist::TRAINING, trainingSize);
    mnist.getTrainingData(X, Y);

    mnist.load(Mnist::TEST, 50000);
    mnist.getTestData(Xtest, Ytest);

    for (size_t i = 0; i < X.n_cols; ++i)
      X.col(i) /= norm(X.col(i), 2);

    for (size_t i = 0; i < Xtest.n_cols; ++i)
      Xtest.col(i) /= norm(Xtest.col(i), 2);
    Y += 1.;
    Ytest += 1.;
    // one-hot
    /*
    arma::mat yy = arma::ones(10, Y.n_cols);
    for(size_t i = 0; i < Y.n_cols; ++i){
        if(Y(0,i) < 0 || Y(0,i) > 9)
            exit(0);
        yy(Y(0,i), i) = 2;
    }
    */
    //X = trainData;
    //yy = trainLabels;

    std::cerr << "dbg1\n";
    std::cout << size(X) << "\n";
    std::cout << size(Y) << "\n";
    //std::cout << trainLabels << "\n";
    //std::cout << yy << "\n";

    // Initialize the network.
    FFN<NegativeLogLikelihood<>, RandomInitialization> model;

    // Add the first convolution layer.
    model.Add<Convolution<> >(
        1,  // Number of input activation maps.
        6,  // Number of output activation maps.
        5,  // Filter width.
        5,  // Filter height.
        1,  // Stride along width.
        1,  // Stride along height.
        0,  // Padding width.
        0,  // Padding height.
        28, // Input width.
        28  // Input height.
        );

    // Add first ReLU.
    //model.Add<LeakyReLU<> >();
    //model.Add<PReLU<> >();
    model.Add<ReLULayer<> >();
    //model.Add<FlexibleReLU<> >();

    // Add first pooling layer. Pools over 2x2 fields in the input.
    model.Add<MaxPooling<> >(
        2,  // Width of field.
        2,  // Height of field.
        2,  // Stride along width.
        2,  // Stride along height.
        true
        );

    // Add the second convolution layer.
    model.Add<Convolution<> >(
        6,  // Number of input activation maps.
        16, // Number of output activation maps.
        5,  // Filter width.
        5,  // Filter height.
        1,  // Stride along width.
        1,  // Stride along height.
        0,  // Padding width.
        0,  // Padding height.
        12, // Input width.
        12  // Input height.
        );

    // Add the second ReLU.
    //model.Add<LeakyReLU<> >();
    //model.Add<PReLU<> >();
    model.Add<ReLULayer<> >();
    //model.Add<FlexibleReLU<> >();

    // Add the second pooling layer.
    model.Add<MaxPooling<> >(2, 2, 2, 2, true);

    int hiddenSize = 150;
    model.Add<Linear<> >(16*4*4, hiddenSize);
    model.Add<SigmoidLayer<> >();
    //model.Add<Dropout<>>(0.6);
    //model.Add<BatchNorm<> >(80);
    model.Add<Linear<> >(hiddenSize, 10);
    model.Add<LogSoftMax<> >();
/*
    SGD<AdaMaxUpdate> optimizer(0.001, // stepSize
                  32,    // batchSize
                  //0.9,   // beta1
                  //0.999, // beta2
                              200000,     // maxIterations
                              1e-8,  // tolerance
                              true, // shuffle
                  AdaMaxUpdate(1e-8, 0.9, 0.999));

    AdaGrad optimizer(1e-3, // stepSize =
                      32, // batchSize =
                      1e-8, // epsilon =
                      200000, // maxIterations =
                      1e-8, // tolerance =
                      true); // shuffle =
*/

    //AdaDelta optimizer;
/*
    AdaDelta(const double stepSize = 1.0,
             const size_t batchSize = 32,
             const double rho = 0.95,
             const double epsilon = 1e-6,
             const size_t maxIterations = 100000,
             const double tolerance = 1e-5,
             const bool shuffle = true);
*/
    SGD<AdaDeltaUpdate> optimizer(1, // stepSize
                  32,    // batchSize
                  //0.9,   // beta1
                  //0.999, // beta2
                              40000,     // maxIterations
                              1e-8,  // tolerance
                              true, // shuffle
                  AdaDeltaUpdate());
                  
    arma::mat assignments;
    // Train the model.
    for(int i = 0; i <= 40; ++i) {
        model.Train(X, Y, optimizer);
        optimizer.ResetPolicy() = false;

        // Test set accuracy calculation
        model.Predict(Xtest, assignments);
        arma::mat p = arma::conv_to<arma::mat>::from(arma::index_max(assignments,0));
        p += 1.;
        double acct = (double)arma::accu(p==Ytest)/(double)Ytest.n_cols*100.;

        std::cout << "epoch: " << i << "\n";
        std::cout << "StepSize:" << optimizer.StepSize() << "\n";
        std::cout << "Test Set Accuracy: " << acct << "%\n";
        std::cout.flush();

        optimizer.StepSize() /= 1.01;
        optimizer.MaxIterations() += 5000;
        if(i % 10 == 0 && i > 0) optimizer.StepSize() /= 2.;
    }

    // Training set accuracy calculation
    model.Predict(X, assignments);
    arma::mat p = arma::conv_to<arma::mat>::from(arma::index_max(assignments,0));
    p += 1.;
    double acct = (double)arma::accu(p==Y)/(double)Y.n_cols*100.;
    std::cout << "Training Set Accuracy: " << acct << "%\n";

    data::Save("model.xml", "model", model, false);
}

int main(int argc, char* argv[]) {
    firstTraining();
    return 0;
}
