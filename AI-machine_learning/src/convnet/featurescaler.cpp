#include "featurescaler.h"

arma::mat FeatureScaler::featureScaling( const arma::mat oX, bool saveFactors, int axis ) {
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

arma::mat FeatureScaler::applyFeatureScalingValues(arma::mat X, int axis) {
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

arma::mat4D FeatureScaler::featureScaling(const arma::mat4D X4D, bool saveFactors, int axis) {
    arma::SizeMat4D s = size(X4D);

    arma::mat X(X4D[0].n_rows * X4D[0].n_cols * X4D[0].n_slices, X4D.size());
    for(size_t i = 0; i < X4D.size(); ++i) {
        X.col(i) = arma::vectorise(X4D[i]);
    }

    arma::mat scaled = featureScaling(X, saveFactors, axis);

    arma::mat4D retv = arma::mat4D(s.a);

    for(size_t i = 0; i < scaled.n_cols; ++i) {
        retv[i] = arma::join_slices(retv[i], scaled.col(i));
        retv[i].reshape(s.b, s.c, s.d);
    }
    return retv;
}

arma::mat4D FeatureScaler::applyFeatureScalingValues(arma::mat4D X4D, int axis) {
    arma::SizeMat4D s = size(X4D);

    arma::mat X(X4D[0].n_rows * X4D[0].n_cols * X4D[0].n_slices, X4D.size());
    for(size_t i = 0; i < X4D.size(); ++i) {
        X.col(i) = arma::vectorise(X4D[i]);
    }

    arma::mat applied = applyFeatureScalingValues(X, axis);

    arma::mat4D retv = arma::mat4D(s.a);

    for(size_t i = 0; i < applied.n_cols; ++i) {
        retv[i] = arma::join_slices(retv[i], applied.col(i));
        retv[i].reshape(s.b, s.c, s.d);
    }
    return retv;
}
