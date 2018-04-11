#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <armadillo>
#include <vector>
#include "CostAndGradient.h"

class NeuralNetwork : public CostAndGradient {
public:
    using CostAndGradient::CostAndGradient;
    
    RetVal calc( const arma::mat& nn_params ) override;
    arma::mat predict( const arma::mat& X, const arma::mat& theta1, const arma::mat& theta2 );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
};

#endif // __NEURAL_NETWORK_H__