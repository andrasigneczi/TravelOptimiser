#ifndef __LOGISTIC_REGRESSION__

#include <armadillo>
#include <vector>

namespace LogisticRegression {
    
class GradientDescent {

public:
    // calculating the gradient descent
    arma::mat calc( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, long long iteration, long double threshold = 0.0 );
    arma::mat calc( arma::mat X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration, long double threshold = 0.0 );
    // predic a value using the gradient descent
    arma::mat predict( const arma::mat& X, const arma::mat& theta );
    
private:
    long double Abs( long double x ) { return x > 0 ? x : -x; }
    arma::mat mTheta;
};

class CostFunctionJ {
public:
    double calc( const arma::mat& X, const arma::mat& y, const arma::mat& theta );
    double calc( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat grad( const arma::mat& X, const arma::mat& y, const arma::mat& theta );
    arma::mat grad( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
};

} // namespace LogisticRegression
#endif // __LOGISTIC_REGRESSION__