#include "CostAndGradient.h"

arma::mat CostAndGradient::featureScaling( const arma::mat oX, bool saveFactors ) {
    // Feature scaling has to be done for every single feature one by one
    arma::mat X = oX;
    mFCData = arma::zeros(X.n_cols,2);
    for( size_t i = 0; i < X.n_cols; ++i ) {
        double range = arma::as_scalar(max(X.col(i))) - arma::as_scalar(min(X.col(i)));
        double average = arma::as_scalar(mean(X.col(i)));

        if( saveFactors ) {
            mFCData(i,0) = range;
            mFCData(i,1) = average;
        }

        if( range != 0.0 ) {
            X.col(i) = (X.col(i) - average)/range;
        }
    }
    return X;
}
