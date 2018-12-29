#ifndef __ACTIVATION_H__
#define __ACTIVATION_H__

#include <armadillo>

namespace Activation
{
    arma::mat sigmoid( const arma::mat& Z );
    arma::mat tanh( const arma::mat& Z );
    arma::mat relu( arma::mat Z );
    arma::mat leaky_relu( arma::mat Z );
    arma::mat softmax( arma::mat Z );

    arma::mat sigmoid_backward( const arma::mat& gZ );
    arma::mat tanh_backward( const arma::mat& gZ );
    arma::mat relu_backward( arma::mat gZ );
    arma::mat leaky_relu_backward( arma::mat gZ );
    arma::mat softmax_backward( const arma::mat& Y, const arma::mat& gZ );

} // namespace Activation

#endif // ACTIVATION_H
