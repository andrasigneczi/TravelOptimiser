#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include "logistic_regression.h"
#include <logistic_regression.h>

using namespace LogisticRegression;

namespace LogisticRegression {
void test1();
void test2();

void runTests() {
    test1();
    test2();
}

void test1() {
    arma::mat dataSet;
    dataSet.load( "../Octave/machine-learning-ex2/ex2/ex2data1.txt" );

    // The  last column of the dataset is the result column
    arma::mat y = dataSet.col(dataSet.n_cols - 1);
 
     // number of the training datas
    double m = y.n_rows;
    // input training feature dataset
    arma::mat X = dataSet.cols(0,dataSet.n_cols-2);
    double n = X.n_cols;

    // let's insert a column filled with ones
    X.insert_cols(0, arma::ones<arma::mat>(m,1));
    
    // Initialize fitting parameters
    arma::mat initial_theta = arma::zeros(n + 1, 1);

    // Compute and display initial cost and gradient
    LogisticRegression::CostFunctionJ costFJ;
    double cost = costFJ.calc(X, y, initial_theta);
    arma::mat grad = costFJ.grad(X, y, initial_theta);
    
    std::cout << "Cost at initial theta (zeros): " << cost << std::endl;
    std::cout << "Expected cost (approx): 0.693" << std::endl;

    std::cout << "Gradient at initial theta (zeros): \n";
    std::cout << grad << "\n";
    std::cout << "Expected gradients (approx):\n -0.1000\n -12.0092\n -11.2628\n";
    
    // Compute and display cost and gradient with non-zero theta
    arma::mat test_theta;
    test_theta << -24 << arma::endr << 0.2 << arma::endr << 0.2;
    
    cost = costFJ.calc(X, y, test_theta);
    grad = costFJ.grad(X, y, test_theta);
    
    std::cout << "\nCost at test theta: " << cost << std::endl;
    std::cout << "Expected cost (approx): 0.218\n";
    std::cout << "Gradient at test theta: \n";
    std::cout << grad << "\n";
    std::cout << "Expected gradients (approx):\n 0.043\n 2.566\n 2.647\n";
    
    LogisticRegression::GradientDescent gd;
    arma::mat theta = gd.calc( X, y, initial_theta, 0.003, 1.2E+7, 1.0E-13 );
    std::cout << "\nGradient descent:\n";
    std::cout << "Expected cost (approx): 0.203\n";
    std::cout << "theta: " << theta <<"\n";
    std::cout << "Expected theta (approx):\n";
    std::cout << " -25.161\n 0.206\n 0.201\n";

    //  Predict probability for a student with score 45 on exam 1 
    //  and score 85 on exam 2 
    arma::mat st = {1,45,85};
    double prob = arma::as_scalar(costFJ.sigmoid( st, theta));
    std::cout << "For a student with scores 45 and 85, we predict an admission probability of " << prob << "\n";
    std::cout << "Expected value: 0.775 +/- 0.002\n\n";
    
    // Compute accuracy on our training set
    arma::mat p = gd.predict(X,theta);
    std::cout << "Train Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == y)) << "\n";
    std::cout << "Expected accuracy (approx): 89.0\n";

}

arma::mat mapFeature( const arma::mat& X1, const arma::mat& X2 ) {
    arma::mat out = arma::ones(X1.n_rows, 1);
    
    // let's insert a column filled with ones
    //X.insert_cols(0, arma::ones<arma::mat>(m,1));

    int degree = 6;
    for( int i = 1; i <= degree; ++i ){
        for( int j = 0; j <= i; ++j ) {
            //out(:, end+1) = (X1.^(i-j)).*(X2.^j);
            out.insert_cols(out.n_cols, arma::pow(X1,i-j) % arma::pow(X2,j));
        }
    }
    return out;
}

void test2() {
    arma::mat dataSet;
    dataSet.load( "../Octave/machine-learning-ex2/ex2/ex2data2.txt" );
    
    // The  last column of the dataset is the result column
    arma::mat y = dataSet.col(dataSet.n_cols - 1);
 
    // input training feature dataset
    arma::mat X = dataSet.cols(0,dataSet.n_cols-2);

    X = mapFeature( X.col(0), X.col(1));
    double n = X.n_cols;
    
    // Initialize fitting parameters
    arma::mat initial_theta = arma::zeros(n, 1);
    double lambda = 1.0;
    // Compute and display initial cost and gradient
    LogisticRegression::CostFunctionJ costFJ;
    double cost = costFJ.calc(X, y, initial_theta, lambda);
    arma::mat grad = costFJ.grad(X, y, initial_theta, lambda);
    
    std::cout << "Cost at initial theta (zeros): " << cost << std::endl;
    std::cout << "Expected cost (approx): 0.693" << std::endl;

    std::cout << "Gradient at initial theta (zeros) - first five values only: \n";
    std::cout << grad.rows(0,4) << "\n";
    std::cout << "Expected gradients (approx) - first five values only:\n 0.0085\n 0.0188\n 0.0001\n 0.0503\n 0.0115\n";

    // Compute and display cost and gradient with all-ones theta and lambda = 10
    arma::mat test_theta = arma::ones(n,1);

    cost = costFJ.calc(X, y, test_theta,10);
    grad = costFJ.grad(X, y, test_theta,10);
    
    std::cout << "\nCost at test theta (with lambda = 10): " << cost << "\n";
    std::cout << "Expected cost (approx): 3.16\n";
    std::cout << "Gradient at test theta - first five values only:\n";
    std::cout << grad.rows(0,4) << "\n";
    std::cout << "Expected gradients (approx) - first five values only:\n";
    std::cout << " 0.3460\n 0.1614\n 0.1948\n 0.2269\n 0.0922\n";
    

    std::cout << "\nGradient descent with lambda:\n";
    initial_theta = arma::zeros(n, 1);
    LogisticRegression::GradientDescent gd;
    arma::mat theta = gd.calcL( X, y, initial_theta, 0.0006, 1.0, 1.2E+6, 1.0E-13 );

    // Compute accuracy on our training set
    arma::mat p = gd.predict(X,theta);
    std::cout << "Train Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == y)) << "\n";
    std::cout << "Expected accuracy (with lambda = 1): 83.1 (approx)\n";
}

} // namespace LogisticRegression