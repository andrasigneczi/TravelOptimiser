#ifndef __LOGISTIC_REGRESSION_H__
#define __LOGISTIC_REGRESSION_H__

#include <armadillo>
#include <vector>
#include "CostAndGradient.h"
#include <QtCore/QtGlobal>

class Q_DECL_EXPORT LogisticRegression : public CostAndGradient {
public:
    LogisticRegression( const arma::mat& X, const arma::mat& y, double lambda, bool featureScaling, int featureMappingDegree );
    LogisticRegression();

    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override;

    arma::mat gradientDescentWithReguralization( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration );
    // predic a value using the gradient descent
    arma::mat predict( const arma::mat& X, const arma::mat& theta, double threshold = 0.5 );
    arma::mat predict( const arma::mat& X, double threshold = 0.5 );

    double cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
    
    arma::mat learningCurve(const arma::mat& Xval, const arma::mat& Yval, double lambda, long long iteration, int stepSize);
    arma::mat validationCurve(const arma::mat& Xval, const arma::mat& Yval, long long iteration);
    
    arma::mat train(int iteration, bool verbose);
    arma::mat trainOne(double label, int iteration, bool verbose);
    arma::mat trainOneVsAll(int iteration, bool verbose = true);
    arma::mat predictOneVsAll( const arma::mat& X, const arma::mat& theta, bool copyValue );
    arma::mat predictOneVsAll( const arma::mat& X, bool copyValue );
    void saveThetaAndFeatureScaling(std::string fileNamePrefix);
    void loadThetaAndFeatureScaling(std::string fileNamePrefix);
    arma::mat validationCurveOne(double label, const arma::mat& Xval, const arma::mat& Yval, long long iteration);
    arma::mat learningCurveOne(double label, const arma::mat& Xval, const arma::mat& Yval, double lambda, long long iteration, int stepSize);
    arma::mat mapFeature(const arma::mat& X);
    void setFeatureMappingDegree(int degree) { mFeatureMappingDegree = degree; }
    double searchThreshold( const arma::mat& X, const arma::mat& Y );
private:

    long double Abs( long double x ) { return x > 0 ? x : -x; }
    arma::mat mTheta;
    int mFeatureMappingDegree;
};

#endif // __LOGISTIC_REGRESSION__
