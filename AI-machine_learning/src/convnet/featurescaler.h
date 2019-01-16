#ifndef __FEATURESCALER_H__
#define __FEATURESCALER_H__

#include <armadillo>
#include <QtCore/QtGlobal>
#include "Util.h"

class Q_DECL_EXPORT FeatureScaler
{
public:

    virtual arma::mat featureScaling(const arma::mat X, bool saveFactors, int axis = 1);
    virtual arma::mat applyFeatureScalingValues(arma::mat X, int axis = 1);

    virtual arma::mat4D featureScaling(const arma::mat4D X, bool saveFactors, int axis = 1);
    virtual arma::mat4D applyFeatureScalingValues(arma::mat4D X, int axis = 1);

private:
    arma::mat mFCData;
};

#endif // __FEATURESCALER_H__
