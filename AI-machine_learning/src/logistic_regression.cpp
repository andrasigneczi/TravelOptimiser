#include "logistic_regression.h"
#include <stdio.h>

// Feature Scaling Data
struct FCData{
    double range;
    double average;
};

arma::mat LogisticRegression::gradientDescent( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double alpha, long long iteration ) {
    // number of the training datas
    double m = y.n_rows;
    mTheta = theta;
    
    for( long long i = 0; i < iteration; ++i ) {
        arma::mat delta = (sigmoid(X,mTheta) - y).t();
        mTheta = mTheta - (alpha/m*delta*X).t();
        if( i % 10000 == 0 ) {
            std::cout << "iteration: " << i << std::endl;
        }
    }
    return mTheta;
}

arma::mat LogisticRegression::gradientDescentWithReguralization( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration ) {
    // number of the training datas
    double m = y.n_rows;
    mTheta = theta;
    
    for( long long i = 0; i < iteration; ++i ) {
        arma::mat delta = (sigmoid(X,mTheta) - y).t();
        
        mTheta(0) = mTheta(0) - arma::as_scalar((alpha/m*delta*X.col(0)).t());
        
        for( long j = 1; j < mTheta.n_rows; ++j )
            mTheta(j) = mTheta(j) - arma::as_scalar( alpha*( (1/m*delta*X.col(j)).t() + lambda/m*mTheta(j) ) );
        if( i % 10000 == 0 ) {
            std::cout << "iteration: " << i << std::endl;
        }
    }
    return mTheta;
}

arma::mat LogisticRegression::predict( const arma::mat& X, const arma::mat& theta ) {
    double m = X.n_rows; // Number of training examples
    arma::mat p = arma::zeros(m, 1);
    
    // change elements of A greater than 0.5 to 1
    p.elem( arma::find( sigmoid(X,theta) >= 0.5 ) ).ones();
    return p;
}

double LogisticRegression::cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta ) {
    // z = X*theta;
    // h = 1/(1+e^(-z));
    // J = 1/m*(-y'*log(h)-(1-y)'*log(1-h));
    
    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*as_scalar(-y.t()*arma::log(h)-(1.0-y).t()*arma::log(1.0-h));
}

double LogisticRegression::cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    // z = X*theta;
    // h = 1/(1+e^(-z));
    // J = 1/m*(-y'*log(h)-(1-y)'*log(1-h)) + lambda/2/m*sum(theta(2:size(theta)).^2);

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*as_scalar(-y.t()*arma::log(h)-(1.0-y).t()*arma::log(1.0-h))
    + lambda/2.0/m*arma::as_scalar(arma::sum(arma::pow(theta.rows(1,theta.n_rows-1),2)));
}

arma::mat LogisticRegression::gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta ) {
    // grad=1/m*(h-y)'*X;    
    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*(h-y).t()*X;
}

arma::mat LogisticRegression::gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    //grad(1)=sum(1/m*(h-y)'*X(1));
    //for i=2:size(theta)
    //  grad(i)=1/m*(h-y)'*X(:,i) + lambda/m*theta(i);
    //end;

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    
    arma::mat grad(theta.n_rows,1);
    grad(0) = arma::as_scalar(arma::sum((1/m*(h-y).t()*X.col(0))));
    
    for( size_t i = 1; i < theta.n_rows; ++i ) {
      grad(i) = arma::as_scalar(1/m*(h-y).t()*X.col(i) + lambda/m*theta(i));
    }
    return grad;
}

arma::mat LogisticRegression::sigmoid( const arma::mat& X, const arma::mat& theta ) {
    const arma::mat z = -X*theta;
    return 1.0/(1.0+arma::exp(z));
}

CostAndGradient::RetVal LogisticRegressionV2::calc( const arma::mat& nn_params ) {
    CostAndGradient::RetVal retVal;

    const arma::mat& theta = nn_params;

    const arma::mat z = -mX*theta;
    
    // cost calculation
    const arma::mat h = 1.0/(1.0+arma::exp(z));
    double m = mX.n_rows;
    retVal.cost = 1.0/m*as_scalar(-mY.t()*arma::log(h)-(1.0-mY).t()*arma::log(1.0-h))
    + mLambda/2.0/m*arma::as_scalar(arma::sum(arma::pow(theta.rows(1,theta.n_rows-1),2)));

    // gradient calculation
    retVal.grad = arma::mat(theta.n_rows,1);
    retVal.grad(0) = arma::as_scalar(arma::sum((1/m*(h-mY).t()*mX.col(0))));
    
    for( size_t i = 1; i < theta.n_rows; ++i ) {
      retVal.grad(i) = arma::as_scalar(1/m*(h-mY).t()*mX.col(i) + mLambda/m*theta(i));
    }

    return retVal;
}
