#include "svm.h"
#include <armadillo>

namespace SVM_ns {
    
void test1();

void runTests() {
    test1();
}

struct svm_problem prepare_svm_problem( const arma::mat& X, const arma::mat& y ) {
    struct svm_problem spr;
    spr.l = X.n_rows;
    spr.y = (double*)malloc(y.n_rows*sizeof(double));
    for( size_t i = 0; i < y.n_rows; ++i ) {
        spr.y[i] = y(i,0);
    }

    spr.x = (struct svm_node**)malloc(X.n_rows*sizeof(struct svm_node*));
    for( size_t i = 0; i < X.n_rows; ++i ) {
        spr.x[i] = (struct svm_node*)malloc((X.n_cols + 1)*sizeof(struct svm_node));
        for( size_t j = 0; j < X.n_cols; ++j ) {
            spr.x[i][j].index = j + 1;
            spr.x[i][j].value = X(i,j);
        }
        spr.x[i][X.n_cols].index = -1;
        spr.x[i][X.n_cols].value = 0;
    }
    return spr;
}

void test1() {
    arma::mat X,y;
    X.load("spamTrain_X.bin");
    y.load("spamTrain_y.bin");
    std::cout << "\nTraining Linear SVM (Spam Classification)\n";
    
    // You should try to change the C value below and see how the decision
    // boundary varies (e.g., try C = 1000)
    //int C = 1;
    //model = svmTrain(X, y, C, @linearKernel, 1e-3, 20);
    
    struct svm_parameter spa;
	spa.svm_type = C_SVC;
	spa.kernel_type = LINEAR;
	spa.degree = 3;	/* for poly */
	spa.gamma = 0;	/* for poly/rbf/sigmoid */
	spa.coef0 = 0;	/* for poly/sigmoid */

	/* these are for training only */
	spa.cache_size = 40; /* in MB */
	spa.eps = 0.001;	/* stopping criteria */
	spa.C=0.1;	/* for C_SVC, EPSILON_SVR and NU_SVR */
	spa.nr_weight = 0;		/* for C_SVC */
	spa.weight_label = nullptr;	/* for C_SVC */
	spa.weight = nullptr;		/* for C_SVC */
	spa.nu = 0.5;	/* for NU_SVC, ONE_CLASS, and NU_SVR */
	spa.p = 0.1;	/* for EPSILON_SVR */
	spa.shrinking = 1;	/* use the shrinking heuristics */
	spa.probability = 0; /* do probability estimates */
     
    struct svm_problem spr = prepare_svm_problem(X,y);

    struct svm_model *model = svm_train(&spr, &spa);

    //p = svmPredict(model, X);
    //double svm_predict(const struct svm_model *model, const struct svm_node *x);
    arma::mat p(y.n_rows,1);
    for( size_t i = 0; i < y.n_rows; ++i ) {
        p(i,0) = svm_predict(model, spr.x[i]);
    }

    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == y)) * 100 << "\n";
    
    arma::mat Xtest, ytest;
    Xtest.load("spamTest_Xtest.bin");
    ytest.load("spamTest_ytest.bin");

    std::cout << "\nEvaluating the trained Linear SVM on a test set ...\n";
    spr = prepare_svm_problem(Xtest,ytest);
    
    //p = svmPredict(model, Xtest);
    p = arma::mat(ytest.n_rows,1);
    for( size_t i = 0; i < ytest.n_rows; ++i ) {
        p(i,0) = svm_predict(model, spr.x[i]);
    }
    
    std::cout << "\nTest Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == ytest)) * 100 << "\n";
    
    
}

} // SVM_ns
