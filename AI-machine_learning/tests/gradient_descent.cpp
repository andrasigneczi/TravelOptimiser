#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include "gradient_descent.h"
#include <gradient_descent.h>

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
    H = gd.calc( dataSet, H, alpha, 1500 );
    std::cout << "H: " << H << std::endl;
}