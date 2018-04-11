#include "neural_network.h"

CostAndGradient::RetVal NeuralNetwork::calc( const arma::mat& /*nn_params*/ ) {
    CostAndGradient::RetVal rv;
    return rv;
}

arma::mat NeuralNetwork::predict( const arma::mat& X, const arma::mat& theta1, const arma::mat& theta2 ) {
    size_t m = X.n_rows;
    arma::mat p = arma::zeros(m, 1);
    arma::mat XX = arma::ones(m, 1);
    XX.insert_cols(1,X);
    arma::mat s=sigmoid(XX,theta1.t());
    s.insert_cols(0,arma::ones(s.n_rows,1));
    arma::mat s2=sigmoid(s,theta2.t());
    arma::mat M = arma::max(s2,1);
    for( size_t i=0; i < m; ++i ) {
        p(i,0) = as_scalar(arma::find( s2.row(i)==M(i,0) )) + 1;
    }
    //std::cout << M.rows(1000,1200);
    return p;
}

arma::mat NeuralNetwork::sigmoid( const arma::mat& X, const arma::mat& theta ) {
    const arma::mat z = -X*theta;
    return 1.0/(1.0+arma::exp(z));
}
