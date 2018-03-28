#include "gradient_descent.h"

arma::mat GradientDescent::calc( const arma::mat& dataSet, const arma::mat& theta, double alpha, int iteration ) {
    arma::mat Y = dataSet.col(dataSet.n_cols - 1);
    int m = Y.n_rows;
    
    arma::mat X = dataSet.cols(0,dataSet.n_cols-2);

    double maxv = as_scalar(max(X));
    double minv = as_scalar(min(X));
    double average = as_scalar(mean(X));

    if( maxv-minv > 1. ) {
        X = (X - average)/(maxv-minv);
    }
    
    X.insert_cols(0, arma::ones<arma::mat>(m,1));

    std::cout << X << std::endl;
    
    arma::mat T = theta;
    for( int i = 0; i < iteration; ++i ) {
        arma::mat delta = (X * T - Y).t();

        //T(0) = as_scalar(T(0) - alpha/m*delta*X.col(0));
        //T(1) = as_scalar(T(1) - alpha/m*delta*X.col(1));
        T = T - (alpha/m*delta*X).t();
    }
    
    if( maxv-minv > 1. ) {
        T(0) -= T(1)*average/(maxv-minv);
        T(1) /= (maxv-minv);
    }
    return T;
}
