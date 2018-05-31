#include "anomaly_detection.h"

AnomalyDetection::AnomalyDetection( const arma::mat& X, const arma::mat& Xval, const arma::mat& yval ) {
    estimateGaussian( X );
    arma::mat p = multivariateGaussian( X );
    arma::mat pval = multivariateGaussian( Xval );
    selectThreshold( yval, pval );
}

arma::mat AnomalyDetection::getOutliers( const arma::mat& X ) {
    arma::mat p = multivariateGaussian( X );
    return arma::conv_to<arma::mat>::from( p < mEpsilon );
}

void AnomalyDetection::estimateGaussian( const arma::mat& X ) {
    // Useful variables
    size_t m, n;
    m = X.n_rows;
    n = X.n_cols;

    // You should return these values correctly
    mMu = arma::zeros(n, 1);
    mSigma2 = arma::zeros(n, 1);

    // Compute the mean of the data and the variances
    // In particular, mu(i) should contain the mean of
    // the data for the i-th feature and sigma2(i)
    // should contain variance of the i-th feature.

    for( size_t i = 0; i <n; ++i ) {
      mMu(i) = mean(X.col(i));
    }

    for( size_t i = 0; i <n; ++i ) {
      mSigma2(i) = sum(pow((X.col(i) - mMu(i)),2))/(double)m;
    }

}

arma::mat AnomalyDetection::multivariateGaussian( arma::mat X ) {
    // MULTIVARIATEGAUSSIAN Computes the probability density function of the
    // multivariate gaussian distribution.
    //     p = MULTIVARIATEGAUSSIAN(X, mu, Sigma2) Computes the probability
    //     density function of the examples X under the multivariate gaussian
    //     distribution with parameters mu and Sigma2. If Sigma2 is a matrix, it is
    //     treated as the covariance matrix. If Sigma2 is a vector, it is treated
    //     as the \sigma^2 values of the variances in each dimension (a diagonal
    //     covariance matrix)
    //

    double k = (double)mMu.n_rows;

    if((mSigma2.n_cols == 1) || (mSigma2.n_rows == 1)) {
        mSigma2 = arma::diagmat(mSigma2);
    }

    arma::mat mu2 = arma::vectorise(mMu).t();

    for( size_t i = 0; i < X.n_rows; ++i )
        X.row(i) -= mu2;

    arma::mat p = pow((2. * M_PI),(- k / 2.)) * pow(arma::det(mSigma2), (-0.5)) *
        exp(-0.5 * sum( (X * arma::pinv(mSigma2))% X, 1));
    return p;
}

arma::mat operator&(const my_op_typ& x, const my_op_typ& y ) {
    arma::mat X = arma::conv_to<arma::mat>::from(x);
    arma::mat Y = arma::conv_to<arma::mat>::from(y);

    arma::mat retval(X.n_rows,X.n_cols);

    for( size_t i = 0; i < X.n_rows; ++i ) {
        for( size_t j = 0; j < X.n_cols; ++j ) {
            retval(i,j) = ((int)X(i,j)&(int)Y(i,j));
        }
    }
    return retval;
}

void AnomalyDetection::selectThreshold( const arma::mat& yval, const arma::mat& pval ) {
    // SELECTTHRESHOLD Find the best threshold (epsilon) to use for selecting
    // outliers
    //    [bestEpsilon bestF1] = SELECTTHRESHOLD(yval, pval) finds the best
    //    threshold to use for selecting outliers based on the results from a
    //    validation set (pval) and the ground truth (yval).
    //

    mEpsilon = 0;
    mF1 = 0;
    double F1 = 0;

    double stepsize = as_scalar(arma::max(pval) - arma::min(pval)) / 1000.;
    for( double epsilon = as_scalar(arma::min(pval)); epsilon <= as_scalar(arma::max(pval)); epsilon += stepsize ) {

        // Compute the F1 score of choosing epsilon as the
        // threshold and place the value in F1. The code at the
        // end of the loop will compare the F1 score for this
        // choice of epsilon and set it to be the best epsilon if
        // it is better than the current choice of epsilon.

        arma::mat predictions = arma::conv_to<arma::mat>::from(pval < epsilon);

        double fp = as_scalar(sum((predictions == 1) & (yval == 0)));
        double tp = as_scalar(sum((predictions == 1) & (yval == 1)));
        double fn = as_scalar(sum((predictions == 0) & (yval == 1)));

        double prec, rec;

        if( tp + fp != 0){
          prec = tp / (tp+fp);
        }else{
            prec = 0;
        }

        if( tp+fn != 0){
          rec = tp / (tp+fn);
        }else{
          rec = 0;
        }

        if( prec+rec != 0){
          F1 = 2 * prec * rec / (prec+rec);
        }else{
          F1 = 0;
        }

        if( F1 > mF1 ){
           mF1 = F1;
           mEpsilon = epsilon;
        }
    }
}
