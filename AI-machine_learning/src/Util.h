#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include "qcustomplot.h"
#include <armadillo>
#include <QtCore/QtGlobal>

namespace Util {
    
    Q_DECL_EXPORT std::string trim(const std::string& str);
    Q_DECL_EXPORT void plotMatrix( QCustomPlot* customPlot, const arma::mat& matrix );
    Q_DECL_EXPORT void removeDuplication(arma::mat& dataset);
    Q_DECL_EXPORT void prepareTrainingAndValidationSet(const arma::mat& X, const arma::mat& y, arma::mat& Xtraining, arma::mat& Ytraining, arma::mat& Xval, arma::mat& Yval);
    Q_DECL_EXPORT arma::mat mapFeature( arma::mat X1, arma::mat X2 );
    
} // namespace Util

#endif // __UTIL_H__
