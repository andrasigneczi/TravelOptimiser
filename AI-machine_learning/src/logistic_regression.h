#ifndef __LOGISTIC_REGRESSION__
#define __LOGISTIC_REGRESSION__

#include <armadillo>
#include <vector>

class LogisticRegression {
public:
    arma::mat gradientDescent( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, long long iteration );
    arma::mat gradientDescentWithReguralization( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration );
    // predic a value using the gradient descent
    arma::mat predict( const arma::mat& X, const arma::mat& theta );

    double cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta );
    double cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta );
    arma::mat gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
    
private:
    long double Abs( long double x ) { return x > 0 ? x : -x; }
    arma::mat mTheta;
};

#endif // __LOGISTIC_REGRESSION__