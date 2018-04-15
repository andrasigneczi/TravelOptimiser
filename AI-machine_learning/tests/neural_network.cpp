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
    //test2();
    //test3();
    test4();
}


class TestYMappper : public CostAndGradient::YMappperIF {
public:
    arma::mat fromYtoYY(double y, size_t num_labels ) override {
        arma::mat yy = arma::zeros(1,num_labels);
        if( y == 0 ) {
            yy(0,9) = 1;
        } else {
            yy(0,y-1) = 1;
        }
        return yy;
    }
    
    double fromYYtoY( size_t index ) override {
        return index + 1; // the Octave used 1 based indexes
    }
};

void test1() {
    // neural network predict
    arma::mat X, y, Theta1, Theta2;
    
    Theta1.load("ex3weights_Theta1.bin");
    Theta2.load("ex3weights_Theta2.bin");
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");
    
    TestYMappper yMapper;
    const arma::mat thetaSizes;
    NeuralNetwork nn(thetaSizes, X, y, 0, yMapper);
    arma::mat pred = nn.predict(X, {Theta1, Theta2});
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
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
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);
    //J = nnCostFunction(nn_params, input_layer_size, hidden_layer_size, ...
    //                   num_labels, X, y, lambda);
    CostAndGradient::RetVal& rv = nn.calc(nn_params);
    
    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.287629)\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
    std::cout << "\nChecking Cost Function (w/ Regularization) ... \n";
    
    lambda = 1;
    nn.setLambda(lambda);
    rv = nn.calc(nn_params);

    std::cout << "Cost at parameters (loaded from ex4weights): " << rv.cost << " (this value should be about 0.383770)\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
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
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
    
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
    std::cout << "Press enter to continue\n";
    std::cin.get();
    


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
    fmincgRetVal frv = fmincg(nn, initial_nn_params, 200);
    
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;
    
    // Obtain Theta1 and Theta2 back from nn_params
    /*
    Theta1 = arma::reshape(frv.m_NNPparams.rows(0,hidden_layer_size * (input_layer_size + 1)-1),
                     hidden_layer_size, (input_layer_size + 1));
    
    Theta2 = arma::reshape(frv.m_NNPparams.rows((hidden_layer_size * (input_layer_size + 1)),frv.m_NNPparams.n_rows-1),
                     num_labels, (hidden_layer_size + 1));
    */
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

void test3() {
    arma::mat X, y;
    
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    arma::mat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size1 = 20;
    int num_labels         = 10;
    double lambda = 1;
    int iteration = 50;
    
    thetaSizes << input_layer_size << hidden_layer_size1 << num_labels; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);

    // Randomly initialize the weights to small values
    arma::mat initial_Theta1 = nn.randInitializeWeights(input_layer_size, hidden_layer_size1);
    arma::mat initial_Theta2 = nn.randInitializeWeights(hidden_layer_size1, num_labels);
    
    // Unroll parameters
    //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
    arma::mat initial_nn_params = join_cols( arma::vectorise( initial_Theta1 ), arma::vectorise( initial_Theta2 ));

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();

}

class COCYMappper : public CostAndGradient::YMappperIF {
public:
    arma::mat fromYtoYY(double y, size_t num_labels ) override {
        arma::mat yy = arma::zeros(1,num_labels);
        yy(0,y-2) = 1;
        return yy;
    }
    
    double fromYYtoY( size_t index ) override {
        return index + 2; // the smallest TH number is 2
    }
};


void test4() {
    arma::mat X, y;
    
    X.load("coc_trainingset.bin");
    y.load("coc_trainingset_result.bin");
    
    // multiply the training set
    for( int i = 0; i < 0; ++i ) {
        X = join_cols( X, X );
        y = join_cols( y, y );
    }
    
    // input, hidden1, ..., hddenN, output
    arma::mat thetaSizes{X.n_cols, 20, 11, 10 };
    double lambda = 1e-4;
    int iteration = 100;
    
    //thetaSizes << input_layer_size << hidden_layer_size1 << num_labels; // input, hidden, output
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);

    //std::cout << "dbg1\n";
    arma::mat initial_nn_params;
    for( size_t i = 0; i <= thetaSizes.n_cols-2; ++i ) {
        // Randomly initialize the weights to small values
        arma::mat initial_Theta = nn.randInitializeWeights(thetaSizes(0,i), thetaSizes(0,i+1));
    
        // Unroll parameters
        //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
        if( i == 0 )
            initial_nn_params = arma::vectorise( initial_Theta );
        else
            initial_nn_params = join_cols( initial_nn_params, arma::vectorise( initial_Theta ));
    }
    //std::cout << "dbg2\n";
    
/*    
    std::cout << "\nChecking Backpropagation (w/ Regularization) ... \n";
    
    //  Check gradients by running checkNNGradients
    nn.setLambda(3);
    nn.checkNNGradients(3);
    std::cout << "Press enter to continue\n";
    std::cin.get();
    nn.setLambda( lambda );
*/    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //std::cout << "dbg3\n";

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "thetaSizes: " << thetaSizes << "; lambda: " << lambda << "\n";
}

} // NeuralNetwork_ns