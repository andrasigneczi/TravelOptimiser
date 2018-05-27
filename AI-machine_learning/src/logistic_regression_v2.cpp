#include "logistic_regression_v2.h"
#include <stdio.h>
#include "Util.h"
#include <chrono>
#include <fstream>
#include <iterator>

FeatureMapper::FeatureMapper( const arma::mat& X, int degree )
    : mX(X), mDegree(degree) {
    mTempId = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    mColNum = mX.n_cols + 1;
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
    } else {
        arma::mat X = mX;
        X.insert_cols(0,arma::ones(X.n_rows,1));

        std::string fileName = (std::string("mapped_feature_x_0_") + mTempId + ".bin");
        X.save(fileName.c_str());
        mFileNames.push_back(fileName);
    }
}

void FeatureMapper::deleteMappedFiles() {
    std::for_each(mFileNames.begin(),mFileNames.end(), [](const std::string& name){ remove(name.c_str()); });
}

arma::mat FeatureMapper::get(size_t index) {
    if(index >= mFileNames.size())
        return arma::mat();

    arma::mat X;
    X.load(mFileNames[index]);
    return X;
}

void FeatureMapper::saveFeatureMappedFileNames( std::string fileNamePrefix ) {
    std::ofstream output_file(fileNamePrefix + "_feature_maps_file_names.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(mFileNames.begin(), mFileNames.end(), output_iterator);
}

void FeatureMapper::loadFeatureMappedFileNames( std::string fileNamePrefix ) {
    std::ifstream is(fileNamePrefix + "_feature_maps_file_names.txt");
    std::istream_iterator<std::string> start(is), end;
    mFileNames = std::vector<std::string>(start, end);
    arma::mat X = get(0);
    mBatchSize = X.n_rows;
    mColNum = X.n_cols;
}

LogisticRegressionV2::LogisticRegressionV2( const arma::mat& X, const arma::mat& y, bool featureScaling, int featureMappingDegree, size_t batchSize )
    : mX(X), mY(y), mBatchSize(batchSize), mFM(mX,featureMappingDegree){

    if(featureScaling) {
        mX = this->featureScaling(mX, true);
    }

    mFM.doMapping(batchSize);
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

arma::mat LogisticRegressionV2::miniBatchGradientDescent( bool initTheta, double alpha, double lambda, long long iteration ) {
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
                mTheta(j) = mTheta(j) - arma::as_scalar( alpha*( (1./(double)X.n_rows*delta*X.col(j)).t() + lambda/(double)X.n_rows*mTheta(j)));
        }

        std::cout << "mini-batch iteration: " << i + 1 << "                       \r" << std::flush;
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

void LogisticRegressionV2::saveCurrentStatus(std::string fileNamePrefix) {
    saveThetaAndFeatureScaling(fileNamePrefix);
    saveFeatureMappedFileNames(fileNamePrefix);
    mY.save(fileNamePrefix + "_y.bin");

    int degree = mFM.getDegree();
    std::ofstream output(fileNamePrefix +"_other.bin", std::ios::binary | std::ios::trunc | std::ios::out);
    output.write((const char*)&degree, sizeof(degree));
}

void LogisticRegressionV2::loadCurrentStatus(std::string fileNamePrefix) {
    loadThetaAndFeatureScaling(fileNamePrefix);
    loadFeatureMappedFileNames(fileNamePrefix);
    mBatchSize = mFM.getBatchSize();
    mY.load(fileNamePrefix + "_y.bin");

    std::ifstream input(fileNamePrefix +"_other.bin", std::ios::binary | std::ios::in);
    int degree;
    input.read((char*)&degree, sizeof(degree));
    mFM.setDegree(degree);
}

arma::mat LogisticRegressionV2::evaluate( const arma::mat& theta, size_t m ) {
    arma::mat q = arma::zeros(m, 1);

    for( size_t index = 0; ;++index) {
        arma::mat X = mFM.get(index);
        if(X.n_rows == 0)
            break;

        size_t l = index * mBatchSize;
        size_t l_end = l + X.n_rows - 1;
        q.rows(l,l_end) = sigmoid(X,theta);
    }
    return q;
}

double LogisticRegressionV2::accuracy(double threshold) {
    arma::mat p = evaluate(mTheta, mY.n_rows);

    //p.elem( arma::find( p >= threshold ) ).ones();
    p = arma::conv_to<arma::mat>::from(arma::all( (p >= threshold), 1 ));
    return arma::mean(arma::conv_to<arma::colvec>::from(p == mY)) * 100.;
}

arma::mat LogisticRegressionV2::predict( const arma::mat& X, double threshold ) {
    arma::mat X2 = X;
    if(mFCData.n_rows > 0) {
        X2 = applyFeatureScalingValues(X2);
    }
    FeatureMapper fm(X2,mFM.getDegree());
    fm.doMapping(mBatchSize);

    arma::mat p = arma::zeros(X2.n_rows, 1);
    for( size_t index = 0; ;++index) {
        arma::mat XX = fm.get(index);
        if(XX.n_rows == 0)
            break;

        size_t l = index * mBatchSize;
        size_t l_end = l + XX.n_rows - 1;
        p.rows(l,l_end) = sigmoid(XX,mTheta);
    }
    fm.deleteMappedFiles();
    return arma::conv_to<arma::mat>::from(arma::all( (p >= threshold), 1 ));
}

arma::mat LogisticRegressionV2::applyFeatureScalingValues(arma::mat X) {
    if( mFCData.n_rows > 0 ) {
        for( size_t i = 0; i < X.n_cols; ++i ) {
            if( mFCData(i,0) != 0)
                X.col(i) = (X.col(i) - mFCData(i,1))/(mFCData(i,0));
        }
    }
    return X;
}
