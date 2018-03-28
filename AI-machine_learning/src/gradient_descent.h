#ifndef __GRADIENT_DESCENT__

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include <vector>

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

#endif // __GRADIENT_DESCENT__