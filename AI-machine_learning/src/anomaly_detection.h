#ifndef __ANOMALY_DETECTION_H__
#define __ANOMALY_DETECTION_H__

#include <armadillo>
#include <QtCore/QtGlobal>

class Q_DECL_EXPORT AnomalyDetection {
public:
    AnomalyDetection( const arma::mat& X, const arma::mat& Xval, const arma::mat& yval );
    arma::mat getOutliers( const arma::mat& X );
    double getBestEpsilon() const { return mEpsilon; }
    double getBestF1() const { return mF1; }
private:
    void estimateGaussian( const arma::mat& X );
    arma::mat multivariateGaussian( arma::mat X );
    void selectThreshold( const arma::mat& yval, const arma::mat& pval );

    arma::mat mMu;
    arma::mat mSigma2;
    double mEpsilon;
    double mF1;
};

#if ARMA_VERSION_MAJOR == 4
typedef arma::enable_if2<true, const arma::mtOp<unsigned int, arma::Mat<double>, arma::op_rel_eq> >::result my_op_typ;
#else
typedef arma::enable_if2<true, const arma::mtOp<long long unsigned int, arma::Mat<double>, arma::op_rel_eq> >::result my_op_typ;
#endif
extern arma::mat operator&(const my_op_typ& x, const my_op_typ& y );

#endif // __ANOMALY_DETECTION_H__
