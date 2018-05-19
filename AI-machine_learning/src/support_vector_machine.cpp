#include "support_vector_machine.h"
#include <set>

static const arma::mat dummy;
support_vector_machine::support_vector_machine( const arma::mat& X, const arma::mat& y, bool featureScaling, const int featureMappingDegree )
    : CostAndGradient( X, y, 0 ), mFeatureMappingDegree(featureMappingDegree) {

    if(featureScaling) {
        mX = this->featureScaling(X, true);
    }

    //mX = this->mapFeature(mX);
    
    mSvmProblem = prepare_svm_problem(mX,mY);
    mX = arma::mat(); // some free memory
    
	mSvmParameter.svm_type = C_SVC;
	mSvmParameter.kernel_type = RBF;
	mSvmParameter.degree = 3;	/* for poly */
	mSvmParameter.gamma = 0.0001;	/* for poly/rbf/sigmoid */
	mSvmParameter.coef0 = 0;	/* for poly/sigmoid */

	/* these are for training only */
	mSvmParameter.cache_size = 400; /* in MB */
	mSvmParameter.eps = 0.001;	/* stopping criteria */
	mSvmParameter.C=0.1;	/* for C_SVC, EPSILON_SVR and NU_SVR */
	mSvmParameter.nr_weight = 0;		/* for C_SVC */
	mSvmParameter.weight_label = nullptr;	/* for C_SVC */
	mSvmParameter.weight = nullptr;		/* for C_SVC */
	mSvmParameter.nu = 0.5;	/* for NU_SVC, ONE_CLASS, and NU_SVR */
	mSvmParameter.p = 0.1;	/* for EPSILON_SVR */
	mSvmParameter.shrinking = 1;	/* use the shrinking heuristics */
	mSvmParameter.probability = 0; /* do probability estimates */
    
}

support_vector_machine::support_vector_machine()
    : CostAndGradient( dummy, dummy, 0 ), mFeatureMappingDegree(0) {

}

support_vector_machine::~support_vector_machine() {
    freeAllocations();
}

void support_vector_machine::freeAllocations() {
    for_each(mAllocatedMemPtrs.begin(), mAllocatedMemPtrs.end(), [](void*ptr){ free(ptr); });
    mAllocatedMemPtrs.clear();
    for_each(mGeneratedModels.begin(), mGeneratedModels.end(), [](struct svm_model*model){ svm_free_model_content(model);svm_free_and_destroy_model(&model); });
}

struct svm_problem support_vector_machine::prepare_svm_problem( const arma::mat& X, const arma::mat& y ) {
    struct svm_problem spr;
    spr.l = X.n_rows;
    spr.y = (double*)malloc(y.n_rows*sizeof(double));
    mAllocatedMemPtrs.push_back(spr.y);
    for( size_t i = 0; i < y.n_rows; ++i ) {
        spr.y[i] = y(i,0);
    }

    spr.x = (struct svm_node**)malloc(X.n_rows*sizeof(struct svm_node*));
    mAllocatedMemPtrs.push_back(spr.x);
    for( size_t i = 0; i < X.n_rows; ++i ) {
        spr.x[i] = (struct svm_node*)malloc((X.n_cols + 1)*sizeof(struct svm_node));
        mAllocatedMemPtrs.push_back(spr.x[i]);
        for( size_t j = 0; j < X.n_cols; ++j ) {
            spr.x[i][j].index = j + 1;
            spr.x[i][j].value = X(i,j);
        }
        spr.x[i][X.n_cols].index = -1;
        spr.x[i][X.n_cols].value = 0;
    }
    return spr;
}

struct svm_model* support_vector_machine::train() {
    struct svm_model* model = svm_train(&mSvmProblem, &mSvmParameter);
    mGeneratedModels.push_back(model);
    return model;
}

arma::mat support_vector_machine::predict( const arma::mat& X, struct svm_model* model ) {
    double m = X.n_rows;
    arma::mat p = arma::zeros(m, 1);

    arma::mat X2 = X;
    if( mFCData.n_rows > 0 ) {
        for( size_t i = 0; i < X2.n_cols; ++i ) {
            if( mFCData(i,0) != 0)
                X2.col(i) = (X2.col(i) - mFCData(i,1))/(mFCData(i,0));
        }
    }

    //X2 = mapFeature(X2);
    
    struct svm_problem problem = prepare_svm_problem(X2,p);
    for( size_t i = 0; i < X2.n_rows; ++i ){
        std::cout << (i+1) << "/" << X2.n_rows << "\r" << std::flush;
        p(i,0) = svm_predict(model, problem.x[i]);
    }
    return p;
}

void support_vector_machine::saveFeatureScaling(std::string fileNamePrefix) {
    mFCData.save((fileNamePrefix + "_fcdata.bin").c_str());
}

void support_vector_machine::loadFeatureScaling(std::string fileNamePrefix) {
    mFCData.load((fileNamePrefix + "_fcdata.bin").c_str());
}
