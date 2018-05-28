#ifndef __LOGISTIC_REGRESSION_V2_H__
#define __LOGISTIC_REGRESSION_V2_H__

#include <armadillo>
#include <vector>
#include <QtCore/QtGlobal>
#include <string>
#include <set>

class Q_DECL_EXPORT FeatureMapper {
public:
    FeatureMapper( const arma::mat& X, int degree );
    FeatureMapper() : mX(dummy) {}
    void doMapping(size_t batchSize);
    arma::mat get(size_t index);
    size_t getColNum(){ return mColNum; }
    void deleteMappedFiles();
    void saveFeatureMappedFileNames( std::string fileNamePrefix );
    void loadFeatureMappedFileNames( std::string fileNamePrefix );
    size_t getBatchSize() { return mBatchSize; }
    int getDegree() { return mDegree; }
    void setDegree(int degree) { mDegree = degree; }

private:
    const arma::mat& mX;
    int mDegree;
    std::string mTempId;
    std::vector<std::string> mFileNames;
    size_t mBatchSize;
    size_t mColNum;
    const arma::mat dummy;
};

class Q_DECL_EXPORT LogisticRegressionV2
{
public:
    LogisticRegressionV2( const arma::mat& X, const arma::mat& y, bool featureScaling, int featureMappingDegree,
                          size_t batchSize );
    LogisticRegressionV2(){}
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta ) {return 1.0/(1.0+arma::exp(-X*theta));}
    arma::mat miniBatchGradientDescent( bool initTheta, double alpha, double lambda, long long iteration );
    arma::mat miniBatchGradientDescentOneVsAll( bool initTheta, double alpha, double lambda, long long iteration );
    void saveThetaAndFeatureScaling( std::string fileNamePrefix );
    std::vector<arma::mat> loadThetaAndFeatureScaling( std::string fileNamePrefix );
    void deleteMappedFiles() { mFM.deleteMappedFiles(); }
    void saveFeatureMappedFileNames( std::string fileNamePrefix ) { mFM.saveFeatureMappedFileNames(fileNamePrefix); }
    void loadFeatureMappedFileNames( std::string fileNamePrefix ) { mFM.loadFeatureMappedFileNames(fileNamePrefix); }
    void saveCurrentStatus(std::string fileNamePrefix);
    void loadCurrentStatus(std::string fileNamePrefix);
    double accuracy(double threshold = 0.5);
    double accuracyOneVsAll(bool copyValue);
    arma::mat predict( const arma::mat& X, double threshold = 0.5 );
    arma::mat predictOneVsAll( const arma::mat& X );

    arma::mat featureScaling( const arma::mat& X, bool saveFactors );

private:
    arma::mat evaluate( const arma::mat& theta, size_t m );
    arma::mat applyFeatureScalingValues(arma::mat X);

    arma::mat mX;
    arma::mat mY;
    arma::mat mFCData;
    size_t mBatchSize;
    FeatureMapper mFM;
    arma::mat mTheta;
    std::vector<double> mLabels;
};

#endif // __LOGISTIC_REGRESSION_V2_H__
