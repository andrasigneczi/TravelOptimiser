#include "gradient_descent.h"

arma::mat GradientDescent::calc( const arma::mat& dataSet, const arma::mat& theta, double alpha ) {
    arma::mat Y = dataSet.col(1);
    int m = Y.n_rows;
    
    arma::mat X = dataSet.col(0);

    double maxv = as_scalar(max(X));
    double minv = as_scalar(min(X));
    double average = as_scalar(mean(X));

    if( maxv-minv > 1. ) {
        X = (X - average)/(maxv-minv);
    }
    
    X.insert_cols(0, arma::ones<arma::mat>(m,1));

    std::cout << X << std::endl;
    
    arma::mat H = theta;
    for( int i = 0; i < 1500; ++i ) {
        arma::mat delta = (X * H - Y).t();

        //H(0) = as_scalar(H(0) - alpha/m*delta*X.col(0));
        //H(1) = as_scalar(H(1) - alpha/m*delta*X.col(1));
        H = H - (alpha/m*delta*X).t();
    }
    
    if( maxv-minv > 1. ) {
        H(0) -= H(1)*average/(maxv-minv);
        H(1) /= (maxv-minv);
    }
    return H;
}
