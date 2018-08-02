#include "CostAndGradient.h"

arma::mat CostAndGradient::featureScaling( const arma::mat oX, bool saveFactors, int axis ) {
    // Feature scaling has to be done for every single feature one by one
    arma::mat X = oX;
    if( axis == 1 ) {
        mFCData = arma::zeros(X.n_cols,2);
        for( size_t i = 0; i < X.n_cols; ++i ) {
            double range = arma::as_scalar(max(X.col(i))) - arma::as_scalar(min(X.col(i)));
            double average = arma::as_scalar(mean(X.col(i)));
    
            if( range == 0 )
                range = 1;
    
            if( saveFactors ) {
                mFCData(i,0) = range;
                mFCData(i,1) = average;
            }
    
            X.col(i) = (X.col(i) - average)/range;
        }
    } else {
        mFCData = arma::zeros(2, X.n_rows);
        for( size_t i = 0; i < X.n_rows; ++i ) {
            double range = arma::as_scalar(max(X.row(i))) - arma::as_scalar(min(X.row(i)));
            double average = arma::as_scalar(mean(X.row(i)));
    
            if( range == 0 )
                range = 1;
    
            if( saveFactors ) {
                mFCData(0,i) = range;
                mFCData(1,i) = average;
            }
    
            X.row(i) = (X.row(i) - average)/range;
        }
    }
    return X;
}

arma::mat CostAndGradient::applyFeatureScalingValues(arma::mat X, int axis) {
    if( axis == 1 ) {
        if( mFCData.n_rows > 0 ) {
            for( size_t i = 0; i < X.n_cols; ++i ) {
                if( mFCData(i,0) != 0)
                    X.col(i) = (X.col(i) - mFCData(i,1))/(mFCData(i,0));
            }
        }
    } else {
        if( mFCData.n_cols > 0 ) {
            for( size_t i = 0; i < X.n_rows; ++i ) {
                if( mFCData(0,i) != 0)
                    X.row(i) = (X.row(i) - mFCData(1,i))/(mFCData(0,i));
            }
        }
    }
    return X;
}
