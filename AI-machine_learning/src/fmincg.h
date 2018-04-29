#ifndef __FMINCG_H__
#define __FMINCG_H__

#include <armadillo>
#include "CostAndGradient.h"

/*
costFunction = @(p) nnCostFunction(p, input_layer_size, hidden_layer_size, num_labels, X, y, lambda);
[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);
*/

struct fmincgRetVal {
    arma::mat m_NNPparams;
    arma::mat mCost;
    int mI;
};

fmincgRetVal fmincg( CostAndGradient& f, arma::mat X, int maxIter, bool verbose = true );

#endif
