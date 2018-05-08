#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include "qcustomplot.h"
#include <armadillo>

namespace Util {
    
    std::string trim(const std::string& str);
    void plotMatrix( QCustomPlot* customPlot, const arma::mat& matrix );
    void removeDuplication(arma::mat& dataset);
    void prepareTrainingAndValidationSet(const arma::mat& X, const arma::mat& y, arma::mat& Xtraining, arma::mat& Ytraining, arma::mat& Xval, arma::mat& Yval);
    
} // namespace Util

#endif // __UTIL_H__
