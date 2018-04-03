#include "logistic_regression.h"
#include <stdio.h>

using namespace LogisticRegression;

namespace LogisticRegression {

// Feature Scaling Data
struct FCData{
    double range;
    double average;
};

arma::mat GradientDescent::calc( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, long long iteration, long double threshold /*=0 */) {
    // number of the training datas
    double m = y.n_rows;
    
    mTheta = theta;
    
    /*
    // Feature scaling has to be done for every single feature one by one
    for( size_t i = 1; i < X.n_cols; ++i ) {
        FCData fcData;
        fcData.range   = arma::as_scalar(max(X.col(i))) - arma::as_scalar(min(X.col(i)));
        fcData.average = arma::as_scalar(mean(X.col(i)));

        if( fcData.range > 1.0 ) {
            X.col(i) = (X.col(i) - fcData.average)/(fcData.range);
            //mFCData.push_back(fcData);
        }
    }
    */
    CostFunctionJ cf;
    double cost = cf.calc(X,y,theta);
    std::cout << "cost0: " << cost << std::endl;
    for( long long i = 0; i < iteration; ++i ) {
        arma::mat delta = (cf.sigmoid(X,mTheta) - y).t();
        //T(0) = as_scalar(T(0) - alpha/m*delta*X.col(0));
        //T(1) = as_scalar(T(1) - alpha/m*delta*X.col(1));
        mTheta = mTheta - (alpha/m*delta*X).t();
        double cost2 = cf.calc(X,y,mTheta);
        if( i % 10000 == 0 ) {
            std::cout << i << " " << "cost2: " << cost2 << std::endl;
        }
        if( i > 100000 && cost2 < cost && threshold != 0 && cost - cost2 < threshold )
            break;
        cost = cost2;
        //for( long j = 0; j < mTheta.n_rows; ++j )
        //    mTheta(j) = mTheta(j) - arma::as_scalar(alpha/m*delta*X.col(j));
    }

    //mTheta = mTheta - alpha/m*X.t()*( 1./(1.+arma::exp(-X * mTheta)) - y );

    return mTheta;
}

arma::mat GradientDescent::predict( const arma::mat& X, const arma::mat& theta ) {
    double m = X.n_rows; // Number of training examples
    arma::mat p = arma::zeros(m, 1);
    
    CostFunctionJ cf;

    // change elements of A greater than 0.5 to 1
    p.elem( arma::find( cf.sigmoid(X,theta) >= 0.5 ) ).ones();
    return p;
}

double CostFunctionJ::calc( const arma::mat& X, const arma::mat& y, const arma::mat& theta ) {
    // z = X*theta;
    // h = 1/(1+e^(-z));
    // J = 1/m*(-y'*log(h)-(1-y)'*log(1-h));
    
    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*as_scalar(-y.t()*arma::log(h)-(1.0-y).t()*arma::log(1.0-h));
}

arma::mat CostFunctionJ::grad( const arma::mat& X, const arma::mat& y, const arma::mat& theta ) {
    // grad=1/m*(h-y)'*X;    
    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*(h-y).t()*X;
}

arma::mat CostFunctionJ::sigmoid( const arma::mat& X, const arma::mat& theta ) {
    const arma::mat z = -X*theta;
    return 1.0/(1.0+arma::exp(z));
    /*
    arma::mat grad( z.n_rows, z.n_cols);
    for( size_t i = 0; i < z.n_rows; ++i ) {
        for( size_t j = 0; j < z.n_cols; ++j ) {
            grad(i,j) = 1.0/(1.0 + exp(z(i,j)));
        }
    }
    return grad;
    */
}
} // namespace LogisticRegression
