#include "linear_regression.h"
#include "logistic_regression.h"
#include <iostream>
#include <chrono>

int main () {
    LinearRegression::gradientDescentCalc();
    std::cout << std::string( 80, '-' ) << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    LogisticRegression_ns::runTests();

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
}
