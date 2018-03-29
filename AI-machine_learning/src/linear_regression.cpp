#include "linear_regression.h"

arma::mat GradientDescent::calc( const arma::mat& dataSet, const arma::mat& theta, double alpha, long long iteration, long double threshold /*=0 */) {
    // cleaning of the Feature Scaling vector
    mFCData.clear();
    
    // The  last column of the dataset is the result column
    arma::mat Y = dataSet.col(dataSet.n_cols - 1);
    
    // number of the training datas
    int m = Y.n_rows;
    
    // input training feature dataset
    arma::mat X = dataSet.cols(0,dataSet.n_cols-2);

    // Feature scaling has to be done for every single feature one by one
    for( size_t i = 0; i < X.n_cols; ++i ) {
        FCData fcData;
        fcData.range   = arma::as_scalar(max(X.col(i))) - arma::as_scalar(min(X.col(i)));
        fcData.average = arma::as_scalar(mean(X.col(i)));

        if( fcData.range > 1.0 ) {
            X.col(i) = (X.col(i) - fcData.average)/(fcData.range);
            mFCData.push_back(fcData);
        }
    }

    // let's insert a column filled with ones
    X.insert_cols(0, arma::ones<arma::mat>(m,1));

    mTheta = theta;
    long double s = as_scalar(sum(abs(mTheta)));
    long long i;
    for( i = 0; i < iteration; ++i ) {
        arma::mat delta = (X * mTheta - Y).t();

        //T(0) = as_scalar(T(0) - alpha/m*delta*X.col(0));
        //T(1) = as_scalar(T(1) - alpha/m*delta*X.col(1));
        mTheta = mTheta - (alpha/m*delta*X).t();
        if( threshold > 0.0 && i % 1000 == 0 ) {
            long double news = as_scalar(sum(abs(mTheta)));
            if( Abs(news - s) < threshold)
                break;
            s = news;
        }
    }

    std::cout << "iteration: " << i << "\n";
    return mTheta;
}

double GradientDescent::predict( const arma::rowvec input ) {
    if( input.n_cols != mFCData.size())
        throw std::string("Invalid input data size for prediction\n");
    double retV = mTheta(0);
    for( size_t i = 0; i < input.n_cols; ++i ) {
        retV += (input(i) - mFCData[ i ].average)/mFCData[ i ].range*mTheta(i + 1);
    }
    return retV;
}

arma::mat NormalEquation::calc( const arma::mat& dataSet ) {
    // theta = (X.t()*X).i()*X.t()*y

    // The  last column of the dataset is the result column
    arma::mat Y = dataSet.col(dataSet.n_cols - 1);

    // number of the training datas
    int m = Y.n_rows;

    // input training feature dataset
    arma::mat X = dataSet.cols(0,dataSet.n_cols-2);

    // let's insert a column filled with ones
    X.insert_cols(0, arma::ones<arma::mat>(m,1));
    
    mTheta = (X.t()*X).i()*X.t()*Y;
    return mTheta;
}

double NormalEquation::predict( const arma::rowvec input ) {
    arma::rowvec vals = input;
    vals.insert_cols( 0, arma::ones(1,1));
    return as_scalar(vals * mTheta);
}
