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
    //test1();
    test2();
}

void test1() {
    // neural network predict
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

void test2() {
    // neural network training
    
    arma::mat X, y, Theta1, Theta2;
    
    Theta1.load("ex3weights_Theta1.bin");
    Theta2.load("ex3weights_Theta2.bin");
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    //nn_params = [Theta1(:) ; Theta2(:)];
    arma::mat nn_params = join_cols( arma::vectorise( Theta1 ), arma::vectorise( Theta2 ));
    double lambda = 0;
    
    std::cout << "Feedforward Using Neural Network ...\n";
    arma::mat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size = 25;
    int num_labels        = 10;
    
    thetaSizes << input_layer_size << hidden_layer_size << num_labels; // input, hidden, output
    NeuralNetwork nn(thetaSizes, X, y, lambda);
    //J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
    //                   num_labels, X, y, lambda);
    CostAndGradient::RetVal& rv = nn.calc(nn_params);
    
    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.287629)\n";
    
    
    std::cout << "\nChecking Cost Function (w/ Regularization) ... \n";
    
    lambda = 1;
    nn.setLambda(lambda);
    rv = nn.calc(nn_params);

    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.383770)\n";
    
    
    std::cout << "\nEvaluating sigmoid gradient...\n";
    
    arma::mat testV = {-1, -0.5, 0, 0.5, 1 };
    arma::mat g = nn.sigmoidGradient( testV );
    std::cout << "Sigmoid gradient evaluated at [-1 -0.5 0 0.5 1]:\n";
    std::cout << g << "\n";
    
    
    // Randomly initialize the weights to small values
    arma::mat initial_Theta1 = nn.randInitializeWeights(input_layer_size, hidden_layer_size);
    arma::mat initial_Theta2 = nn.randInitializeWeights(hidden_layer_size, num_labels);
    
    // Unroll parameters
    //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
    arma::mat initial_nn_params = join_cols( arma::vectorise( initial_Theta1 ), arma::vectorise( initial_Theta2 ));

    std::cout << "\nChecking Backpropagation... \n";
    //  Check gradients by running checkNNGradients
    nn.checkNNGradients();
    
    
    std::cout << "\nChecking Backpropagation (w/ Regularization) ... \n";
    
    //  Check gradients by running checkNNGradients
    lambda = 3;
    nn.setLambda(lambda);
    nn.checkNNGradients(lambda);
    
    // Also output the costFunction debugging values
    //debug_J  = nnCostFunction(nn_params, input_layer_size, ...
    //                          hidden_layer_size, num_labels, X, y, lambda);

    //J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
    //                   num_labels, X, y, lambda);
    rv = nn.calc(nn_params);
    
    std::cout << "\nCost at (fixed) debugging parameters (w/ lambda = " << lambda << "): " << rv.cost <<
             "\n(for lambda = 3, this value should be about 0.576051)\n";
    


    std::cout << "\nTraining Neural Network... \n";
    
    //  After you have completed the assignment, change the MaxIter to a larger
    //  value to see how more training helps.
    //options = optimset('MaxIter', 50);
    
    //  You should also try different values of lambda
    lambda = 1;
    nn.setLambda(lambda);
    // Create "short hand" for the cost function to be minimized
    //costFunction = @(p) nnCostFunction(p, ...
    //                                   input_layer_size, ...
    //                                   hidden_layer_size, ...
    //                                   num_labels, X, y, lambda);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    // Now, costFunction is a function that takes in only one argument (the
    // neural network parameters)
    //[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);
    fmincgRetVal frv = fmincg(nn, initial_nn_params, 50);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;
    
    // Obtain Theta1 and Theta2 back from nn_params
    Theta1 = arma::reshape(nn_params.rows(0,hidden_layer_size * (input_layer_size + 1)-1),
                     hidden_layer_size, (input_layer_size + 1));
    
    Theta2 = arma::reshape(nn_params.rows((hidden_layer_size * (input_layer_size + 1)),nn_params.n_rows-1),
                     num_labels, (hidden_layer_size + 1));
 
    arma::mat pred = nn.predict(X,Theta1, Theta2);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
}

} // NeuralNetwork_ns