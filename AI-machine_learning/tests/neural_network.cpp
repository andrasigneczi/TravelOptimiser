#include <armadillo>
#include "neural_network.h"
#include <neural_network.h>
#include <neural_networkv2.h>
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>
#include <png2arma.h>
#include "qcustomplot.h"
#include <iomanip>

namespace NeuralNetwork_ns {
    
void test1();
void test2();
void test3();
void test_ex5_learningCurve();
void test_ex5_validationCurve();
void minibatch();
void nnv2_test1();
void nnv2_test2();
void nnv2_test2_continue();

void runTests() {
    //test1(); // neural network prediction
    //test2(); // neural network complex training
    //test3(); // neural network simple training
    //test_ex5_learningCurve();
    //test_ex5_validationCurve();
    //minibatch(); doesn't work
    //nnv2_test1();
    nnv2_test2();
    nnv2_test2_continue();
}


class TestYMappper : public NeuralNetwork::YMappperIF {
public:
    double fromYtoYY(double y ) override {
        //std::cout << "mapper " << num_labels << " " << y << "\n" << std::flush;
        //arma::mat yy = arma::zeros(1,num_labels);
        if( y == 0 ) {
            return 9;
        }
        return y-1;
    }
    
    double fromYYtoY( size_t index ) override {
        return index + 1; // the Octave used 1 based indexes
    }
};

void test1() {
    // neural network prediction
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
    std::cout << "Press enter to continue\n";
    std::cin.get();
    
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
    fmincgRetVal frv = fmincg(nn, initial_nn_params, 50);
    
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;
    std::cout << "Cost: " << frv.mCost;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);
    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100. << "\n";
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
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper, false, NeuralNetwork::SIGMOID);

    // Randomly initialize the weights to small values
    arma::mat initial_Theta1 = nn.randInitializeWeights(input_layer_size, hidden_layer_size1);
    arma::mat initial_Theta2 = nn.randInitializeWeights(hidden_layer_size1, num_labels);
    
    // Unroll parameters
    //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
    arma::mat initial_nn_params = join_cols( arma::vectorise( initial_Theta1 ), arma::vectorise( initial_Theta2 ));

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    // Obtain Theta1 and Theta2 back from nn_params
    std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
    arma::mat pred = nn.predict(X,thetas);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();

}

void test_ex5_learningCurve() {

    // Learning Curve for NN
    arma::mat X, y, thetaSizes;
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");
    //X = X.rows(0,1000);
    //y = y.rows(0,1000);

    thetaSizes << 400 << 20 << 10; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, 1, yMapper);
    //std::cout << "dbg2.5\n" << std::flush;
    nn.plotLearningCurve(new QCustomPlot);
}

void test_ex5_validationCurve() {

    // Learning Curve for NN
    arma::mat X, y, thetaSizes;
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    thetaSizes << 400 << 20 << 10; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, 1, yMapper);
    //std::cout << "dbg2.5\n" << std::flush;
    nn.plotValidationCurve(new QCustomPlot,10);
}

void minibatch() {
    arma::mat X, y;
    
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");

    arma::mat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size1 = 400;
    int hidden_layer_size2 = 20;
    int num_labels         = 10;
    double lambda = 0;
    int iteration = 100;
    //double alpha = 0.93;
    double alpha = 0.93;
    //int batch = X.n_rows;
    int batch = 10;
    
    thetaSizes << input_layer_size << hidden_layer_size1 << hidden_layer_size2 << num_labels; // input, hidden, output
    TestYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper, false, NeuralNetwork::TANH);

    std::vector<arma::mat> thetas;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if( 0 ) {
        thetas = nn.miniBatchGradientDescent(true,iteration,batch,alpha,true);
    } else {
        thetas = nn.extractThetas(nn.train(iteration,true));
    }
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    arma::mat pred = nn.predict(X,thetas);

    std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

void nnv2_test1() {
    arma::mat X, y;
    
    X.load("ex3data1_X.bin");
    y.load("ex3data1_y.bin");
    X = X.t();
    arma::mat yy = arma::zeros(10, X.n_cols);
    std::cerr << "dbg1\n";
    for(size_t i = 0; i < y.n_rows; ++i){
        yy(y(i,0)-1,i) = 1;
    }
    std::cerr << "dbg2\n";
    arma::umat thetaSizes;
    int input_layer_size  = 400;
    int hidden_layer_size2 = 20;
    int num_labels         = 10;
    double lambda = 0;
    int iteration = 600;
    //double alpha = 0.3;
    double alpha = 0.001;
    //int batch = X.n_rows;
    int batch = 32;
    
    thetaSizes << input_layer_size << hidden_layer_size2 << num_labels; // input, hidden, output
    NeuralNetworkV2 nn(thetaSizes, X, yy, lambda, false, NeuralNetworkV2::TANH, NeuralNetworkV2::SIGMOID);
    std::cerr << "dbg3\n";

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    nn.miniBatchGradientDescent(iteration,batch,alpha, NeuralNetworkV2::ADAM);
    //nn.L_layer_model(X,yy,alpha,iteration,true);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    //arma::mat pred = nn.predict(X);
    //std::cout << "Training Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100 << "\n";
    std::cout << "Training Set Accuracy: " << nn.accuracy() << "%\n";
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

void nnv2_test2() {
    arma::mat X, y, Xt, yt, Xtraining, Ytraining, Xval, Yval;

    std::cout << "Loading training set and test set\n";

    X.load("TH_plus_BG_trainingset.bin");
    y.load("TH_plus_BG_trainingset_result.bin");

    // I use only the first 3000 item for this test
    const uint sampleCount = 7000;
    if(X.n_rows > sampleCount) {
        X = X.rows(0, sampleCount);
        y = y.rows(0, sampleCount);
    }

    std::cout << "Data set size: " << X.n_rows << "\n";
    std::cout << "Prepare training and validation set...\n";
    Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);
    X = Xtraining;
    y = Ytraining;
    Xt = Xval;
    yt = Yval;

    std::cout << "Training set size: " << size(X) << "\n";
    std::cout << "Test set size: " << size(Xt) << "\n";
    std::cout << "Training label set size: " << size(y) << "\n";
    std::cout << "Test label result set size: " << size(yt) << "\n";

    // Conversion to the new format
    X = X.t();
    Xt = Xt.t();
    
    // finding the minimum and maximum y values
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

    int num_labels = maxYVal - minYVal + 1;
    arma::mat yy = arma::zeros(num_labels, y.n_rows);
    for(size_t i = 0; i < y.n_rows; ++i){
        yy(y(i,0) - minYVal,i) = 1;
    }
    arma::mat yyt = arma::zeros(num_labels, yt.n_rows);
    for(size_t i = 0; i < yt.n_rows; ++i){
        yyt(yt(i,0) - minYVal,i) = 1;
    }
    
    arma::umat thetaSizes;
    int input_layer_size  = X.n_rows;
    int hidden_layer_size2 = 100;
    double lambda = 0; //0.5;
    int iteration = 20;
    //double alpha = 0.3;
    double alpha = 0.001;
    //int batch = X.n_rows;
    int batch = 32;
    double keep_prob = .6; // drop out
    NeuralNetworkV2::Optimizer optimization = NeuralNetworkV2::ADAM;
    thetaSizes << input_layer_size << hidden_layer_size2 << num_labels; // input, hidden, output
    
    std::cout << "Training result set size: " << size(yy) << "\n";
    std::cout << "Test result set size: " << size(yyt) << "\n";
    std::cout << "Optimization: " << optimization << "\n";
    std::cout << "Lambda: " << lambda << "\n";
    std::cout << "Iteration: " << iteration << "\n";
    std::cout << "Keep prob: " << keep_prob << "\n";
    std::cout << "Batch size: " << batch << "\n";
    std::cout << "Layer sizes: " << thetaSizes << "\n";
    std::cout << std::endl;
    
    NeuralNetworkV2 nn(thetaSizes, X, yy, lambda, true, NeuralNetworkV2::TANH, NeuralNetworkV2::SIGMOID, keep_prob);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    nn.miniBatchGradientDescent(iteration, batch, alpha, optimization);
    //nn.L_layer_model(X,yy,alpha,iteration,true);
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    std::cout << "Training Set Accuracy: " << nn.accuracy() << "%\n";
    
    arma::mat pred = nn.predict(Xt);
    arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(yyt,0));
    double acct = (double)arma::accu(pred==temp)/(double)yyt.n_cols*100.;
    
    std::cout << "Test Set Accuracy: " << acct << "%\n";

    // saving test set to test again after continuing
    Xt.save("Xt_saved.bin");
    yyt.save("yyt_saved.bin");

    std::cout << "Press enter to continue\n";
    nn.saveState("nn2_test");
    std::cin.get();
    
}

void nnv2_test2_continue() {
    std::cout << "Continue minibatch\n";

    NeuralNetworkV2 nn("nn2_test");
    nn.continueMinibatch(100);

    // loading test set
    arma::mat Xt, yyt;
    Xt.load("Xt_saved.bin");
    yyt.load("yyt_saved.bin");

    arma::mat pred = nn.predict(Xt);
    arma::mat temp = arma::conv_to<arma::mat>::from(arma::index_max(yyt,0));
    double acct = (double)arma::accu(pred==temp)/(double)yyt.n_cols*100.;

    std::cout << "Test Set Accuracy: " << acct << "%\n";
    std::cout << "Press enter to continue\n";
    nn.saveState("nn2_test");
    std::cin.get();
}

} // NeuralNetwork_ns
