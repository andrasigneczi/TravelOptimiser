#ifndef __COSTANDGRADIENT_H__
#define __COSTANDGRADIENT_H__

#include <armadillo>
#include <QtCore/QtGlobal>

class Q_DECL_EXPORT CostAndGradient {
public:
    struct RetVal {
        double cost;
        arma::mat grad;
    };
    
    CostAndGradient( const arma::mat& X, const arma::mat& y, double lambda )
    : mX( X ), mY( y ), mLambda( lambda ){}
    
    virtual RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) = 0;
    void setLambda( double lambda ) { mLambda = lambda; }

    virtual arma::mat featureScaling( const arma::mat X, bool saveFactors );

protected:
    arma::mat mX;
    arma::mat mY;
    double mLambda;
    RetVal mRetVal;
    arma::mat mFCData;
};

#endif // __COSTANDGRADIENT_H__
