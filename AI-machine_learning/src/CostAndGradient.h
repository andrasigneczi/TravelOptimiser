#ifndef __COSTANDGRADIENT_H__
#define __COSTANDGRADIENT_H__

#include <armadillo>

class CostAndGradient {
public:
    static const double NOT_FOUND;
    
    struct RetVal {
        double cost;
        arma::mat grad;
    };
    
    class YMappperIF {
    public:
        virtual double fromYtoYY(double y ) = 0;
        virtual double fromYYtoY( size_t index ) = 0;
    };
    
    CostAndGradient( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda, YMappperIF& yMappper )
    : mLayerSizes( layerSizes), mX( X ), mY( y ), mLambda( lambda ), mYMappper( yMappper ){}
    
    virtual RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) = 0;
    void setLambda( double lambda ) { mLambda = lambda; }
    
protected:
    const arma::mat& mLayerSizes; // input layer, hidden1, hidden2, ..., output
    const arma::mat& mX;
    const arma::mat& mY;
    double mLambda;
    RetVal mRetVal;
    YMappperIF& mYMappper;
};

#endif // __COSTANDGRADIENT_H__
