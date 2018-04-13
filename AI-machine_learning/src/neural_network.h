#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <armadillo>
#include <vector>
#include "CostAndGradient.h"

class NeuralNetwork : public CostAndGradient {
public:
    using CostAndGradient::CostAndGradient;
    
    RetVal& calc( const arma::mat& nn_params ) override;
    RetVal& calc_old( const arma::mat& nn_params );
    //arma::mat predict( const arma::mat& X, const arma::mat& theta1, const arma::mat& theta2 );
    arma::mat predict( const arma::mat& X, const std::vector<arma::mat>& thetas );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
    arma::mat sigmoidGradient( const arma::mat& z );
    arma::mat randInitializeWeights( int L_in, int L_out );
    void checkNNGradients( double lambda = 0 );
    arma::mat debugInitializeWeights( int fan_out, int fan_in );
    arma::mat computeNumericalGradient( const arma::mat& nn_params );
    std::vector<arma::mat> extractThetas( const arma::mat& nn_params );
};

template<typename T>
T mod(T a, int n)
{
    return a - floor(a/n)*n;
}

#endif // __NEURAL_NETWORK_H__