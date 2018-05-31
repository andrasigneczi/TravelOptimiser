#include <anomaly_detection.h>
#include "anomaly_detection.h"
#include <armadillo>
#include <math.h>

namespace AnomalyDetection_ns {
    
    void test1();

void runTests() {
    test1();
}


void test1() {
    arma::mat X, Xval, yval;
    
    X.load( "ex8data1_X.bin");
    Xval.load( "ex8data1_Xval.bin");
    yval.load( "ex8data1_yval.bin");

    AnomalyDetection ad(X, Xval, yval);

    printf("Best epsilon found using cross-validation: %e\n", ad.getBestEpsilon());
    printf("Best F1 on Cross Validation Set:  %f\n", ad.getBestF1());
    printf("   (you should see a value epsilon of about 8.99e-05)\n");
    printf("   (you should see a Best F1 value of  0.875000)\n\n");
    
    //  We will now use the code from the previous part and apply it to a 
    //  harder problem in which more features describe each datapoint and only 
    //  some features indicate whether a point is an outlier.
    
    //  Loads the second dataset. You should now have the
    //  variables X, Xval, yval in your environment
    X.load( "ex8data2_X.bin");
    Xval.load( "ex8data2_Xval.bin");
    yval.load( "ex8data2_yval.bin");
    
    AnomalyDetection ad2(X, Xval, yval);

    printf("Best epsilon found using cross-validation: %e\n", ad2.getBestEpsilon());
    printf("Best F1 on Cross Validation Set:  %f\n", ad2.getBestF1());
    printf("   (you should see a value epsilon of about 1.38e-18)\n");
    printf("   (you should see a Best F1 value of 0.615385)\n");
    std::cout << "# Outliers found: " << sum(ad2.getOutliers(X)) << "\n\n";

}

} // AnomalyDetection_ns
