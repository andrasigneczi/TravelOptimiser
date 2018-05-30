#include <anomaly_detection.h>
#include "anomaly_detection.h"
#include <armadillo>
#include <math.h>

namespace AnomalyDetection_ns {
    
    void test1();

void runTests() {
    test1();
}

void estimateGaussian(const arma::mat& X, arma::mat& mu, arma::mat& sigma2) {
    // Useful variables
    size_t m, n;
    m = X.n_rows;
    n = X.n_cols;
    
    // You should return these values correctly
    mu = arma::zeros(n, 1);
    sigma2 = arma::zeros(n, 1);
    
    // Instructions: Compute the mean of the data and the variances
    //               In particular, mu(i) should contain the mean of
    //               the data for the i-th feature and sigma2(i)
    //               should contain variance of the i-th feature.
    //

    for( size_t i = 0; i <n; ++i ) {
      mu(i) = mean(X.col(i));
    }

    for( size_t i = 0; i <n; ++i ) {
      sigma2(i) = sum(pow((X.col(i) - mu(i)),2))/(double)m;
    }
}

arma::mat multivariateGaussian(arma::mat X, const arma::mat& mu, arma::mat Sigma2) {
// MULTIVARIATEGAUSSIAN Computes the probability density function of the
// multivariate gaussian distribution.
//     p = MULTIVARIATEGAUSSIAN(X, mu, Sigma2) Computes the probability 
//     density function of the examples X under the multivariate gaussian 
//     distribution with parameters mu and Sigma2. If Sigma2 is a matrix, it is
//     treated as the covariance matrix. If Sigma2 is a vector, it is treated
//     as the \sigma^2 values of the variances in each dimension (a diagonal
//     covariance matrix)
// 

    double k = (double)mu.n_rows;
    
    if((Sigma2.n_cols == 1) || (Sigma2.n_rows == 1)) {
        Sigma2 = arma::diagmat(Sigma2);
    }
    //std::cout << Sigma2 << std::endl;
    
    arma::mat mu2 = arma::vectorise(mu).t();
    
    //std::cout << "X: " << size(X) << std::endl;
    //std::cout << "mu2: " << size(mu2) << std::endl;

    for( size_t i = 0; i < X.n_rows; ++i )
        X.row(i) -= mu2;

    //std::cout << "dbg MG1\n";
    arma::mat p = pow((2. * M_PI),(- k / 2.)) * pow(arma::det(Sigma2), (-0.5)) *
        exp(-0.5 * sum( (X * arma::pinv(Sigma2))% X, 1));
    //std::cout << "dbg MG2\n";
    return p;
}

#ifndef __x86_64__
typedef arma::enable_if2<true, const arma::mtOp<unsigned int, arma::Mat<double>, arma::op_rel_eq> >::result my_op_typ;
arma::mat operator&(const my_op_typ& x, const my_op_typ& y ) {
    arma::mat X = arma::conv_to<arma::mat>::from(x);
    arma::mat Y = arma::conv_to<arma::mat>::from(y);

    //std::cout << size(X) << "\n";
    //std::cout << size(Y) << "\n";

    arma::mat retval(X.n_rows,X.n_cols);

    for( size_t i = 0; i < X.n_rows; ++i ) {
        for( size_t j = 0; j < X.n_cols; ++j ) {
            retval(i,j) = ((int)X(i,j)&(int)Y(i,j));
        }
    }
    return retval;
}
#else
typedef arma::enable_if2<true, const arma::mtOp<long long unsigned int, arma::Mat<double>, arma::op_rel_eq> >::result my_op_typ2;
arma::mat operator&(const my_op_typ2& x, const my_op_typ2& y ) {
    arma::mat X = arma::conv_to<arma::mat>::from(x);
    arma::mat Y = arma::conv_to<arma::mat>::from(y);

    //std::cout << size(X) << "\n";
    //std::cout << size(Y) << "\n";

    arma::mat retval(X.n_rows,X.n_cols);

    for( size_t i = 0; i < X.n_rows; ++i ) {
        for( size_t j = 0; j < X.n_cols; ++j ) {
            retval(i,j) = ((int)X(i,j)&(int)Y(i,j));
        }
    }
    return retval;
}
#endif
void selectThreshold( const arma::mat& yval, const arma::mat& pval, double& bestEpsilon, double& bestF1 ) {
    // SELECTTHRESHOLD Find the best threshold (epsilon) to use for selecting
    // outliers
    //    [bestEpsilon bestF1] = SELECTTHRESHOLD(yval, pval) finds the best
    //    threshold to use for selecting outliers based on the results from a
    //    validation set (pval) and the ground truth (yval).
    // 
    
    bestEpsilon = 0;
    bestF1 = 0;
    double F1 = 0;
    
    double stepsize = as_scalar(arma::max(pval) - arma::min(pval)) / 1000.;
    //std::cout << "stepsize:" << stepsize << "\n";
    for( double epsilon = as_scalar(arma::min(pval)); epsilon <= as_scalar(arma::max(pval)); epsilon += stepsize ) {
        
        // ====================== YOUR CODE HERE ======================
        // Instructions: Compute the F1 score of choosing epsilon as the
        //               threshold and place the value in F1. The code at the
        //               end of the loop will compare the F1 score for this
        //               choice of epsilon and set it to be the best epsilon if
        //               it is better than the current choice of epsilon.
        //               
        // Note: You can use predictions = (pval < epsilon) to get a binary vector
        //       of 0's and 1's of the outlier predictions
    
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
    
        // =============================================================
    
        if( F1 > bestF1 ){
           bestF1 = F1;
           bestEpsilon = epsilon;
        }
    }
}

void test1() {
    arma::mat X, Xval, yval;
    
    X.load( "ex8data1_X.bin");
    Xval.load( "ex8data1_Xval.bin");
    yval.load( "ex8data1_yval.bin");

    //  Estimate my and sigma2
    //[mu sigma2] = estimateGaussian(X);
    arma::mat mu, sigma2;
    estimateGaussian(X,mu,sigma2);

    //  Returns the density of the multivariate normal at each data point (row) 
    //  of X
    arma::mat p = multivariateGaussian(X, mu, sigma2);
    //std::cout << mu << "\n" <<sigma2 <<"\n";
    //std::cout << "dbg5\n" << p;
    //  Now you will find a good epsilon threshold using a cross-validation set
    //  probabilities given the estimated Gaussian distribution
    // 
    
    arma::mat pval = multivariateGaussian(Xval, mu, sigma2);
    //std::cout <<pval;
    
    //[epsilon F1] = selectThreshold(yval, pval);
    double epsilon, F1;
    selectThreshold(yval, pval, epsilon, F1);
    printf("Best epsilon found using cross-validation: %e\n", epsilon);
    printf("Best F1 on Cross Validation Set:  %f\n", F1);
    printf("   (you should see a value epsilon of about 8.99e-05)\n");
    printf("   (you should see a Best F1 value of  0.875000)\n\n");
    
    //  Find the outliers in the training set and plot the
    //outliers = find(p < epsilon);

    //  We will now use the code from the previous part and apply it to a 
    //  harder problem in which more features describe each datapoint and only 
    //  some features indicate whether a point is an outlier.
    //
    
    //  Loads the second dataset. You should now have the
    //  variables X, Xval, yval in your environment
    X.load( "ex8data2_X.bin");
    Xval.load( "ex8data2_Xval.bin");
    yval.load( "ex8data2_yval.bin");
    
    //  Apply the same steps to the larger dataset
    //[mu sigma2] = estimateGaussian(X);
    estimateGaussian(X,mu,sigma2);
    //std::cout << "dbg1\n";
    //  Training set 
    p = multivariateGaussian(X, mu, sigma2);

    //std::cout << "dbg2\n";
    //  Cross-validation set
    pval = multivariateGaussian(Xval, mu, sigma2);
    //std::cout << "dbg3\n";
    //  Find the best threshold
    //[epsilon F1] = selectThreshold(yval, pval);
    selectThreshold(yval, pval, epsilon, F1);
    //std::cout << "dbg4\n";
    
    printf("Best epsilon found using cross-validation: %e\n", epsilon);
    printf("Best F1 on Cross Validation Set:  %f\n", F1);
    printf("   (you should see a value epsilon of about 1.38e-18)\n");
    printf("   (you should see a Best F1 value of 0.615385)\n");
    std::cout << "# Outliers found: " << as_scalar(sum(p < epsilon)) << "\n\n";

}

} // AnomalyDetection_ns
