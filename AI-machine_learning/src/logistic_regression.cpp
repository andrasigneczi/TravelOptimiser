#include "logistic_regression.h"
#include <stdio.h>
#include <fmincg.h>
#include "Util.h"

const arma::mat dummy;
LogisticRegression::LogisticRegression( const arma::mat& X, const arma::mat& y, double lambda, bool featureScaling, const int featureMappingDegree )
    : CostAndGradient( X, y, lambda ), mFeatureMappingDegree(featureMappingDegree) {

    if(featureScaling) {
        mX = this->featureScaling(X, true);
    }

    mX = this->mapFeature(mX);
}

LogisticRegression::LogisticRegression()
    : CostAndGradient( dummy, dummy, 0 ), mFeatureMappingDegree(0) {

}

arma::mat LogisticRegression::gradientDescentWithReguralization( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double alpha, double lambda, long long iteration ) {
    // number of the training datas
    double m = y.n_rows;
    mTheta = theta;
    
    for( long long i = 0; i < iteration; ++i ) {
        arma::mat delta = (sigmoid(X,mTheta) - y).t();
        
        mTheta(0) = mTheta(0) - arma::as_scalar((alpha/m*delta*X.col(0)).t());
        
        for( size_t j = 1; j < mTheta.n_rows; ++j )
            mTheta(j) = mTheta(j) - arma::as_scalar( alpha*( (1/m*delta*X.col(j)).t() + lambda/m*mTheta(j) ) );
        if( i % 100 == 0 ) {
            std::cout << "iteration: " << i << "\r" << std::flush;
        }
    }
    return mTheta;
}

arma::mat LogisticRegression::predict( const arma::mat& X, const arma::mat& theta ) {
    double m = X.n_rows; // Number of training examples
    arma::mat p = arma::zeros(m, 1);

    arma::mat X2 = X;
    if( mFCData.n_rows > 0 ) {
        for( size_t i = 0; i < X2.n_cols; ++i ) {
            if( mFCData(i,0) != 0)
                X2.col(i) = (X2.col(i) - mFCData(i,1))/(mFCData(i,0));
        }
    }

    // change elements of A greater than 0.5 to 1
    p.elem( arma::find( sigmoid(X2,theta) >= 0.5 ) ).ones();
    return p;
}

double LogisticRegression::cost( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    // z = X*theta;
    // h = 1/(1+e^(-z));
    // J = 1/m*(-y'*log(h)-(1-y)'*log(1-h)) + lambda/2/m*sum(theta(2:size(theta)).^2);

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    return 1.0/m*as_scalar(-y.t()*arma::log(h)-(1.0-y).t()*arma::log(1.0-h))
    + lambda/2.0/m*arma::as_scalar(arma::sum(arma::pow(theta.rows(1,theta.n_rows-1),2)));
}

arma::mat LogisticRegression::gradient( const arma::mat& X, const arma::mat& y, const arma::mat& theta, double lambda ) {
    //grad(1)=sum(1/m*(h-y)'*X(1));
    //for i=2:size(theta)
    //  grad(i)=1/m*(h-y)'*X(:,i) + lambda/m*theta(i);
    //end;

    const arma::mat h = sigmoid( X, theta );
    double m = X.n_rows;
    
    arma::mat grad(theta.n_rows,1);
    grad(0) = arma::as_scalar(arma::sum((1/m*(h-y).t()*X.col(0))));
    
    for( size_t i = 1; i < theta.n_rows; ++i ) {
      grad(i) = arma::as_scalar(1/m*(h-y).t()*X.col(i) + lambda/m*theta(i));
    }
    return grad;
}

arma::mat LogisticRegression::sigmoid( const arma::mat& X, const arma::mat& theta ) {
    const arma::mat z = -X*theta;
    return 1.0/(1.0+arma::exp(z));
}

arma::mat LogisticRegression::learningCurve(const arma::mat& Xval, const arma::mat& Yval, double lambda, long long iteration, int stepSize) {
    arma::mat retv = arma::zeros(mX.n_rows, 3);
    arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
    arma::mat XvalC = featureScaling(Xval, false);
    for( size_t m = 0; m < mX.n_rows; m += stepSize ) {
        std::cout << "Lerarning curve step number " << m << "\r" << std::flush;
        arma::mat X = mX.rows(0,m);
        arma::mat Y = mY.rows(0,m);
        //arma::mat theta = lr.gradientDescentWithReguralization( X, Y, initial_theta, alpha, lambda, iteration );
        LogisticRegression lr(X, Y, lambda, false,false);
        fmincgRetVal rv = fmincg(lr,initial_theta,iteration,false);
        //std:: cout << theta;
        //break;

        retv(m,0) = m;
        retv(m,1) = cost( X, Y, rv.m_NNPparams, 0 );
        retv(m,2) = cost( XvalC, Yval, rv.m_NNPparams, 0 );
    }
    return retv;
}

arma::mat LogisticRegression::validationCurve(const arma::mat& Xval, const arma::mat& Yval, long long iteration) {
    std::vector<double> lambda_vec{0, 0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 1, 3, 10};
    arma::mat retv = arma::zeros(lambda_vec.size(), 3);
    arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
    arma::mat XvalC = featureScaling(Xval, false);
    for( size_t i = 0; i < lambda_vec.size(); ++i ) {
        std::cout << "Validation curve step number " << i << "\r" << std::flush;
        setLambda(lambda_vec[i]);
        //arma::mat theta = lr.gradientDescentWithReguralization( Xtraining, Ytraining, initial_theta, alpha, lambda_vec[i], iteration );
        fmincgRetVal rv = fmincg(*this,initial_theta,iteration,false);

        retv(i,0) = lambda_vec[i];
        retv(i,1) = cost( mX, mY, rv.m_NNPparams, 0 );
        retv(i,2) = cost( XvalC, Yval, rv.m_NNPparams, 0 );
    }
    return retv;
}

CostAndGradient::RetVal& LogisticRegression::calc( const arma::mat& nn_params, bool costOnly ) {
    const arma::mat& theta = nn_params;

    const arma::mat z = -mX*theta;
    
    // cost calculation
    const arma::mat h = 1.0/(1.0+arma::exp(z));
    double m = mX.n_rows;
    mRetVal.cost = 1.0/m*as_scalar(-mY.t()*arma::log(h)-(1.0-mY).t()*arma::log(1.0-h))
    + mLambda/2.0/m*arma::as_scalar(arma::sum(arma::pow(theta.rows(1,theta.n_rows-1),2)));

    if( costOnly ) {
        return mRetVal;
    }
    // gradient calculation
    mRetVal.grad = arma::mat(theta.n_rows,1);
    mRetVal.grad(0) = arma::as_scalar(arma::sum((1/m*(h-mY).t()*mX.col(0))));
    
    for( size_t i = 1; i < theta.n_rows; ++i ) {
      mRetVal.grad(i) = arma::as_scalar(1/m*(h-mY).t()*mX.col(i) + mLambda/m*theta(i));
    }

    return mRetVal;
}

arma::mat LogisticRegression::trainOneVsAll(size_t num_labels, int iteration, bool verbose) {
/*
    m = size(X, 1);
    n = size(X, 2);
    all_theta = zeros(num_labels, n + 1);
    X = [ones(m, 1) X];
    
    for i=1:num_labels
        initial_theta = zeros(n + 1, 1);
        options = optimset('GradObj', 'on', 'MaxIter', 50);
        temp = fmincg (@(t)(lrCostFunction(t, X, (y==i), lambda)), initial_theta, options);
        all_theta(i,:) = temp';
    end;
*/ 
    mTheta = arma::zeros(num_labels, mX.n_cols + 1);
    arma::mat XSave = mX;
    arma::mat YSave = mY;
    mX.insert_cols(0,arma::ones(mX.n_rows,1));
    
    for( size_t i = 0; i < num_labels; ++i ) {
        arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
        // exchanging the values to zero, if it isn't equals to i, otherwise it will be 1
        mY = arma::conv_to<arma::mat>::from(arma::all( (YSave == i), 1 ));
        fmincgRetVal frv = fmincg(*this, initial_theta, iteration, verbose);
        if(verbose)
            std::cout << std::endl;
        mTheta.row(i) = frv.m_NNPparams.t();
    }
    mX = XSave;
    mY = YSave;
    return mTheta;
}

arma::mat LogisticRegression::trainOne(double label, int iteration, bool verbose) {
    arma::mat XSave = mX;
    arma::mat YSave = mY;
    mX.insert_cols(0,arma::ones(mX.n_rows,1));

    arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
    // exchanging the values to zero, if it isn't equals to i, otherwise it will be 1
    mY = arma::conv_to<arma::mat>::from(arma::all( (YSave == label), 1 ));
    fmincgRetVal frv = fmincg(*this, initial_theta, iteration, verbose);
    if(verbose)
        std::cout << std::endl;
    mTheta = frv.m_NNPparams;
    mX = XSave;
    mY = YSave;
    return mTheta;
}

arma::mat LogisticRegression::predictOneVsAll( const arma::mat& X, const arma::mat& theta, bool copyValue ) {
/*
    m = size(X, 1);
    num_labels = size(all_theta, 1);
    
    p = zeros(size(X, 1), 1);
    
    % Add ones to the X data matrix
    X = [ones(m, 1) X];
    
    % Hint: This code can be done all vectorized using the max function.
    %       In particular, the max function can also return the index of the 
    %       max element, for more information see 'help max'. If your examples 
    %       are in rows, then, you can use max(A, [], 2) to obtain the max 
    %       for each row.
    %       
    
    s=sigmoid(X*(all_theta'));
    M=max(s,[],2);
    for i=1:m
        p(i) = find(s(i,:)==M(i));
    end;
*/
    double m = X.n_rows;
    arma::mat p = arma::zeros(m, (copyValue?2:1));

    arma::mat X2 = X;
    if( mFCData.n_rows > 0 ) {
        for( size_t i = 0; i < X2.n_cols; ++i ) {
            if( mFCData(i,0) != 0)
                X2.col(i) = (X2.col(i) - mFCData(i,1))/(mFCData(i,0));
        }
    }

    X2 = mapFeature(X2);
    X2.insert_cols(0,arma::ones(m,1));
    arma::mat s = sigmoid(X2,theta.t());
    arma::mat M = arma::max(s,1);
    for( size_t i = 0; i < X.n_rows; ++i ){
        arma::uvec result = arma::find(s.row(i) == M(i,0));
        p(i,0) = result(0,0);
        if(copyValue)
            p(i,1) = M(i,0);
    }
    return p;
}

arma::mat LogisticRegression::predictOneVsAll( const arma::mat& X, bool copyValue ) {
    return predictOneVsAll(X,mTheta,copyValue);
}

void LogisticRegression::saveThetaAndFeatureScaling(std::string fileNamePrefix) {
    mTheta.save((fileNamePrefix + "_theta.bin").c_str());
    mFCData.save((fileNamePrefix + "_fcdata.bin").c_str());
}

void LogisticRegression::loadThetaAndFeatureScaling(std::string fileNamePrefix) {
    mTheta.load((fileNamePrefix + "_theta.bin").c_str());
    mFCData.load((fileNamePrefix + "_fcdata.bin").c_str());
}

arma::mat LogisticRegression::validationCurveOne(double label, const arma::mat& Xval, const arma::mat& Yval, long long iteration) {
    std::vector<double> lambda_vec{0, 0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 1, 3, 10};
    arma::mat retv = arma::zeros(lambda_vec.size(), 3);
    //arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
    arma::mat XvalC = featureScaling(Xval, false);
    XvalC = mapFeature(XvalC);
    XvalC.insert_cols(0,arma::ones(XvalC.n_rows,1));
    arma::mat YvalC = arma::conv_to<arma::mat>::from(arma::all( (Yval == label), 1 ));
    arma::mat YC = arma::conv_to<arma::mat>::from(arma::all( (mY == label), 1 ));
    arma::mat X = join_rows(arma::ones(mX.n_rows,1), mX);

    for( size_t i = 0; i < lambda_vec.size(); ++i ) {
        std::cout << "Validation curve step number " << i << "\r" << std::flush;
        setLambda(lambda_vec[i]);
        arma::mat theta = trainOne(label, iteration, false);

        retv(i,0) = lambda_vec[i];
        retv(i,1) = cost( X, YC, theta, 0 );
        retv(i,2) = cost( XvalC, YvalC, theta, 0 );
    }
    return retv;
}

arma::mat LogisticRegression::learningCurveOne(double label, const arma::mat& Xval, const arma::mat& Yval, double lambda, long long iteration, int stepSize) {
    arma::mat retv = arma::zeros(mX.n_rows, 3);
    //arma::mat initial_theta = arma::zeros(mX.n_cols, 1);
    arma::mat XvalC = featureScaling(Xval, false);
    XvalC = mapFeature(XvalC);
    XvalC.insert_cols(0,arma::ones(XvalC.n_rows,1));
    arma::mat YvalC = arma::conv_to<arma::mat>::from(arma::all( (Yval == label), 1 ));
    for( size_t m = 0; m < mX.n_rows; m += stepSize ) {
        std::cout << "Lerarning curve step number " << m << "\r" << std::flush;
        arma::mat X = mX.rows(0,m);
        arma::mat Y = mY.rows(0,m);
        LogisticRegression lr(X, Y, lambda, false, false);
        arma::mat theta = lr.trainOne(label, iteration, false);
        //std:: cout << theta;
        //break;

        X.insert_cols(0,arma::ones(X.n_rows,1));
        arma::mat YC = arma::conv_to<arma::mat>::from(arma::all( (Y == label), 1 ));
        retv(m,0) = m;
        retv(m,1) = cost( X, YC, theta, 0 );
        retv(m,2) = cost( XvalC, YvalC, theta, 0 );
    }
    return retv;
}

arma::mat LogisticRegression::mapFeature(const arma::mat& X) {
    if( mFeatureMappingDegree > 0 ) {
        size_t pos = X.n_cols/2;
        //X2 = join_rows( X2, Util::mapFeature(X2.cols(pos-13,pos), X2.cols(pos+1, pos + 14)));
        return Util::mapFeature(X.cols(0,pos-1), X.cols(pos, X.n_cols - 1), mFeatureMappingDegree);
    }
    return X;
}
