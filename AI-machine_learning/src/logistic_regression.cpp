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

arma::mat GradientDescent::calcL( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration, long double threshold /*=0 */) {
    // number of the training datas
    double m = y.n_rows;
    
    mTheta = theta;
    
    CostFunctionJ cf;
    double cost = cf.calc(X,y,theta,lambda);
    std::cout << "cost0 with lambda: " << cost << std::endl;
    for( long long i = 0; i < iteration; ++i ) {
        arma::mat delta = (cf.sigmoid(X,mTheta) - y).t();
        
        mTheta(0) = mTheta(0) - arma::as_scalar((alpha/m*delta*X.col(0)).t());
        
        for( long j = 1; j < mTheta.n_rows; ++j )
            mTheta(j) = mTheta(j) - arma::as_scalar( alpha*( (1/m*delta*X.col(j)).t() + lambda/m*mTheta(j) ) );
        //mTheta = mTheta - (alpha/m*delta*X).t();

        double cost2 = cf.calc(X,y,mTheta,lambda);
        if( i % 10000 == 0 ) {
            std::cout << i << " " << "cost2 with lambda: " << cost2 << std::endl;
        }
        if( i > 100000 && cost2 < cost && threshold != 0 && cost - cost2 < threshold )
            break;
        cost = cost2;
    }

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

double CostFunctionJ::calc( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    // z = X*theta;
    // h = 1/(1+e^(-z));
    // J = 1/m*(-y'*log(h)-(1-y)'*log(1-h)) + lambda/2/m*sum(theta(2:size(theta)).^2);

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*as_scalar(-y.t()*arma::log(h)-(1.0-y).t()*arma::log(1.0-h))
    + lambda/2.0/m*arma::as_scalar(arma::sum(arma::pow(theta.rows(1,theta.n_rows-1),2)));
}

arma::mat CostFunctionJ::grad( const arma::mat& X, const arma::mat& y, const arma::mat& theta ) {
    // grad=1/m*(h-y)'*X;    
    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*(h-y).t()*X;
}

arma::mat CostFunctionJ::grad( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    //grad(1)=sum(1/m*(h-y)'*X(1));
    //for i=2:size(theta)
    //  grad(i)=1/m*(h-y)'*X(:,i) + lambda/m*theta(i);
    //end;

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    
    arma::mat grad(theta.n_rows,1);
    // the sum is wrong below, that's why the transpose is necessary
    grad(0) = arma::as_scalar(arma::sum((1/m*(h-y).t()*X.col(0))));
    
    for( size_t i = 1; i < theta.n_rows; ++i ) {
      grad(i) = arma::as_scalar(1/m*(h-y).t()*X.col(i) + lambda/m*theta(i));
    }
    return grad;
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
