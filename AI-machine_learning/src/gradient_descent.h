#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>

#ifndef __GRADIENT_DESCENT__

class GradientDescent {

public:
    arma::mat calc( const arma::mat& dataSet, const arma::mat& theta, double alpha, int iteration );

private:
    
};

#endif // __GRADIENT_DESCENT__