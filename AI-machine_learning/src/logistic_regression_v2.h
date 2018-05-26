#ifndef __LOGISTIC_REGRESSION_V2_H__
#define __LOGISTIC_REGRESSION_V2_H__

#include <armadillo>
#include <vector>
#include <QtCore/QtGlobal>
#include <string>

class Q_DECL_EXPORT FeatureMapper {
public:
    FeatureMapper( const arma::mat& X, int degree );
    ~FeatureMapper();
    void doMapping(size_t batchSize);
    arma::mat get(size_t index);
    size_t getColNum(){ return mColNum; }

private:
    const arma::mat& mX;
    int mDegree;
    std::string mTempId;
    std::vector<std::string> mFileNames;
    size_t mBatchSize;
    size_t mColNum;
};

class Q_DECL_EXPORT LogisticRegressionV2
{
public:
    LogisticRegressionV2( const arma::mat& X, const arma::mat& y, double lambda, bool featureScaling, int featureMappingDegree,
                          size_t batchSize );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta ) {return 1.0/(1.0+arma::exp(-X*theta));}
    arma::mat miniBatchGradientDescent( bool initTheta, double alpha, long long iteration );
    void saveThetaAndFeatureScaling( std::string fileNamePrefix );
    std::vector<arma::mat> loadThetaAndFeatureScaling( std::string fileNamePrefix );

    /*
    arma::mat trainOneVsAll( int iteration, bool verbose = true, bool calcAccuracy = true );
    arma::mat predictOneVsAll( const arma::mat& X, const arma::mat& theta, bool copyValue );

    double accuracy();
*/
    arma::mat featureScaling( const arma::mat& X, bool saveFactors );

private:
    arma::mat mX;
    arma::mat mY;
    arma::mat mFCData;
    double mLambda;
    size_t mBatchSize;
    FeatureMapper mFM;
    arma::mat mTheta;
};

#endif // __LOGISTIC_REGRESSION_V2_H__
