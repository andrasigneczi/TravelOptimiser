#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include "linear_regression.h"
#include <linear_regression.h>

void gradientDescentCalc() {
    //arma::mat X = {{1,1}, {2,2}, {3,3}};
    arma::mat dataSet;
/*
    dataSet << 1 << 1 << arma::endr
    << 2 << 2 << arma::endr
    << 3 << 3 << arma::endr;
*/
    dataSet << 100. << 120. << arma::endr
    << 200. << 80. << arma::endr
    << 300. << 99. << arma::endr
    << 400. << 110. << arma::endr
    << 500. << 100. << arma::endr
    << 600. << 130. << arma::endr
    << 700. << 70. << arma::endr;
    
    arma::mat H;
    H << 0. << arma::endr << 0.;
    double alpha = 0.1;
    GradientDescent gd;
    //H = gd.calc( dataSet, H, alpha, 15000, 1.00393e-05 );
    std::cout << "Gradient Descent:\n";
    std::cout << std::string(80,'-') << std::endl;
    H = gd.calc( dataSet, H, alpha, 1500 );
    std::cout << "H: " << H;
    std::cout << "prediction: 55; " << gd.predict( {55 } ) << "\n";
    std::cout << "prediction: 255; " << gd.predict( {255 } ) << "\n";
    std::cout << "prediction: 1255; " << gd.predict( {1255} ) << "\n";
    
    NormalEquation ne;
    
    H = ne.calc( dataSet );
    std::cout << "\nNormal Equation:\n";
    std::cout << std::string(80,'-') << std::endl;
    std::cout << "H: " << H;
    std::cout << "prediction: 55; " << ne.predict( {55 } ) << "\n";
    std::cout << "prediction: 255; " << ne.predict( {255 } ) << "\n";
    std::cout << "prediction: 1255; " << ne.predict( {1255} ) << "\n";
}