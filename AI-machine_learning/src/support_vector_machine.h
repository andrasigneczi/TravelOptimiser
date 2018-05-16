#ifndef __SUPPORT_VECTOR_MACHINE_H__
#define __SUPPORT_VECTOR_MACHINE_H__

#include <svm.h>
#include <armadillo>
#include <vector>
#include "CostAndGradient.h"
#include <QtCore/QtGlobal>
#include <memory>
#include "Util.h"

class  Q_DECL_EXPORT support_vector_machine : public CostAndGradient
{
public:
    support_vector_machine( const arma::mat& X, const arma::mat& y, bool featureScaling, int featureMappingDegree );
    support_vector_machine();
    ~support_vector_machine();

    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override { UNUSED(&nn_params);UNUSED(costOnly);return mRetVal; }
    
    struct svm_model* train();
    arma::mat predict( const arma::mat& X, struct svm_model* model );
    struct svm_parameter& getParameter() { return mSvmParameter; }
    void saveFeatureScaling(std::string fileNamePrefix);
    void loadFeatureScaling(std::string fileNamePrefix);
    
private:
    struct svm_problem prepare_svm_problem( const arma::mat& X, const arma::mat& y );
    void freeAllocations();
    
    int mFeatureMappingDegree;
    struct svm_problem mSvmProblem;
    struct svm_parameter mSvmParameter;
    
    std::vector<void*> mAllocatedMemPtrs;
    std::vector<struct svm_model*> mGeneratedModels;
};

#endif // __SUPPORT_VECTOR_MACHINE_H__
