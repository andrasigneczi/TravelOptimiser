#ifndef __LINEAR_REGRESSION__

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include <vector>

namespace LinearRegression {

class GradientDescent {

public:
    // Feature Scaling Data
    struct FCData{
        double range;
        double average;
    };
    
    // calculating the gradient descent
    arma::mat calc( const arma::mat& dataSet, const arma::mat& theta, double alpha, long long iteration, long double threshold = 0.0 );
    // predic a value using the gradient descent
    double predict( const arma::rowvec input );
    
private:
    long double Abs( long double x ) { return x > 0 ? x : -x; }
    std::vector<FCData> mFCData;
    arma::mat mTheta;
};

class NormalEquation {
public:
    arma::mat calc( const arma::mat& dataSet );
    // predic a value using the gradient descent
    double predict( const arma::rowvec input );
    
private:
    arma::mat mTheta;
};

class CostFunctionJ {
public:
    double calc( const arma::mat& dataSet, const arma::mat& theta );
};

} // namespace LinearRegression

#endif // __LINEAR_REGRESSION__