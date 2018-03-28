#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <armadillo>
#include "gradient_descent.h"

int main () {
    /*
    using namespace boost::numeric::ublas;
    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j)
            m (i, j) = 3 * i + j;
    std::cout << m << std::endl;
    
    identity_matrix<double> idm(3);
    //std::cout << m/m << std::endl;
    
    arma::mat A = arma::randu<arma::mat>(5,5);
    arma::mat B = arma::randu<arma::mat>(5,5);
  
    std::cout << A*B.i() << std::endl;
    arma::mat C = (A*B.i()).t();
    std::cout << C << std::endl;
    
    std::cout << C.max() << std::endl;    
    std::cout << C.col(1) << std::endl;    
    */
    gradientDescentCalc();
}
