#ifndef __COSTANDGRADIENT_H__
#define __COSTANDGRADIENT_H__

#include <armadillo>

class CostAndGradient {
public:
    struct RetVal {
        double cost;
        arma::mat grad;
    };
    
    CostAndGradient( const arma::mat& X, const arma::mat& y, double lambda )
    : mX( X ), mY( y ), mLambda( lambda ){}
    
    virtual RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) = 0;
    void setLambda( double lambda ) { mLambda = lambda; }
    
protected:
    arma::mat mX;
    arma::mat mY;
    double mLambda;
    RetVal mRetVal;
};

#endif // __COSTANDGRADIENT_H__
