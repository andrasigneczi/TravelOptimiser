#include "logistic_regression_v2.h"
#include <stdio.h>
#include "Util.h"
#include <chrono>

FeatureMapper::FeatureMapper( const arma::mat& X, int degree )
    : mX(X), mDegree(degree) {
    mTempId = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    mColNum = mX.n_cols;
}

void FeatureMapper::doMapping(size_t batchSize) {
    mBatchSize = batchSize;

    if( mDegree > 0 ) {

        if(batchSize > mX.n_rows) {
            batchSize = mX.n_rows;
        }

        size_t pos = mX.n_cols/2;
        size_t index = 0;
        for( size_t r = 0; r < mX.n_rows; ) {
            std::cout << "Feature mapping: " << r << "-" << r + batchSize << "\n";
            size_t endr = r + batchSize - 1;
            arma::mat X1 = mX.rows(r, endr).cols(0,pos-1);
            arma::mat X2 = mX.rows(r, endr).cols(pos, mX.n_cols - 1);
            arma::mat m = Util::mapFeature(X1, X2, mDegree);

            m.insert_cols(0,arma::ones(m.n_rows,1));
            mColNum = m.n_cols;

            std::string fileName = (std::string("mapped_feature_x_") + std::to_string(index) + "_" + mTempId + ".bin");
            m.save(fileName.c_str());
            mFileNames.push_back(fileName);

            r += batchSize;
            if( r + batchSize >= mX.n_rows )
                batchSize = mX.n_rows - r;
            ++index;
        }
    }
}

FeatureMapper::~FeatureMapper() {
    std::for_each(mFileNames.begin(),mFileNames.end(), [](const std::string& name){ remove(name.c_str()); });
}

arma::mat FeatureMapper::get(size_t index) {
    if( mDegree > 0 ) {
        if(index >= mFileNames.size())
            return arma::mat();

        arma::mat X;
        X.load(mFileNames[index]);
        return X;
    }
    size_t r = index * mBatchSize;
    if( r >= mX.n_rows )
        return arma::mat();

    size_t rEnd = r + mBatchSize - 1;
    if( rEnd >= mX.n_rows )
        rEnd = mX.n_rows - 1;

    return mX.rows(r, rEnd);
}

LogisticRegressionV2::LogisticRegressionV2( const arma::mat& X, const arma::mat& y, double lambda, bool featureScaling, int featureMappingDegree, size_t batchSize )
    : mX(X), mY(y), mLambda(lambda), mBatchSize(batchSize), mFM(mX,featureMappingDegree){

    if(featureScaling) {
        mX = this->featureScaling(mX, true);
    }

    if( featureMappingDegree > 0 ) {
        mFM.doMapping(batchSize);
    }
}

arma::mat LogisticRegressionV2::featureScaling( const arma::mat& oX, bool saveFactors ) {
    // Feature scaling has to be done for every single feature one by one
    arma::mat X = oX;
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
    return X;
}

arma::mat LogisticRegressionV2::miniBatchGradientDescent( bool initTheta, double alpha, long long iteration ) {
    if( initTheta ) {
        mTheta = arma::zeros(mFM.getColNum(), 1);
    }

    for( long long i = 0; i < iteration; ++i ) {

        for( size_t index = 0; ;++index) {
            arma::mat X = mFM.get(index);
            if(X.n_rows == 0)
                break;

            size_t l = index * mBatchSize;
            size_t l_end = l + X.n_rows - 1;

            arma::mat delta = (sigmoid(X,mTheta) - mY.rows(l,l_end)).t();

            mTheta(0) = mTheta(0) - arma::as_scalar((alpha/(double)X.n_rows*delta*X.col(0)).t());

            for( size_t j = 1; j < mTheta.n_rows; ++j )
                mTheta(j) = mTheta(j) - arma::as_scalar( alpha*( (1./(double)X.n_rows*delta*X.col(j)).t()));
        }

        std::cout << "mini-batch iteration: " << i << "                       \r" << std::flush;
    }
    return mTheta;
}

void LogisticRegressionV2::saveThetaAndFeatureScaling(std::string fileNamePrefix) {
    mTheta.save((fileNamePrefix + "_theta.bin").c_str());
    mFCData.save((fileNamePrefix + "_fcdata.bin").c_str());
}

std::vector<arma::mat> LogisticRegressionV2::loadThetaAndFeatureScaling(std::string fileNamePrefix) {
    mTheta.load((fileNamePrefix + "_theta.bin").c_str());
    mFCData.load((fileNamePrefix + "_fcdata.bin").c_str());
    return std::vector<arma::mat>{mTheta, mFCData};
}
