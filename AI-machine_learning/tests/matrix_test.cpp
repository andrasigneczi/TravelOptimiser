#include "linear_regression.h"
#include "logistic_regression.h"

int main () {
    //returnMatrix.save( "testmatrix.txt", arma::raw_ascii );
    //std::cout << returnMatrix;
    //LinearRegression::gradientDescentCalc();
    //std::cout << std::string( 80, '-' ) << std::endl;
    LogisticRegression::runTests();
}
