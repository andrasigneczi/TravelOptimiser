#ifndef __COSTANDGRADIENT_H__
#define __COSTANDGRADIENT_H__

#include <armadillo>

class CostAndGradient {
public:

    struct RetVal {
        double cost;
        arma::mat grad;
    };
    
    CostAndGradient( const arma::mat& thetaSizes, const arma::mat& X, const arma::mat& y, double lambda )
    : mThetaSizes( thetaSizes), mX( X ), mY( y ), mLambda( lambda ){}
    
    virtual RetVal calc( const arma::mat& nn_params ) = 0;
    
    const arma::mat& mThetaSizes;
    const arma::mat& mX;
    const arma::mat& mY;
    const double mLambda;
};

#endif // __COSTANDGRADIENT_H__