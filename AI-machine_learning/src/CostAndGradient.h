#ifndef __COSTANDGRADIENT_H__
#define __COSTANDGRADIENT_H__

#include <armadillo>

class CostAndGradient {
public:

    struct RetVal {
        double cost;
        arma::mat grad;
    };
    
    CostAndGradient( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda )
    : mLayerSizes( layerSizes), mX( X ), mY( y ), mLambda( lambda ){}
    
    virtual RetVal& calc( const arma::mat& nn_params ) = 0;
    void setLambda( double lambda ) { mLambda = lambda; }
    
protected:
    const arma::mat& mLayerSizes; // input layer, hidden1, hidden2, ..., output
    const arma::mat& mX;
    const arma::mat& mY;
    double mLambda;
    RetVal mRetVal;
};

#endif // __COSTANDGRADIENT_H__