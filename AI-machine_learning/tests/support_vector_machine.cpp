#include <support_vector_machine.h>
#include <armadillo>

namespace SVM_ns {
    
void test1();

void runTests() {
    test1();
}

void test1() {
    arma::mat X,y;
    X.load("spamTrain_X.bin");
    y.load("spamTrain_y.bin");
    std::cout << "\nTraining Linear SVM (Spam Classification)\n";
    
    support_vector_machine svm(X,y,false,0);
    
    struct svm_parameter& spa = svm.getParameter();
	spa.kernel_type = LINEAR;
	spa.C=0.1;	/* for C_SVC, EPSILON_SVR and NU_SVR */
    struct svm_model *model = svm.train();

    arma::mat p = svm.predict(X, model);

    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == y)) * 100 << "\n";
    
    arma::mat Xtest, ytest;
    Xtest.load("spamTest_Xtest.bin");
    ytest.load("spamTest_ytest.bin");

    std::cout << "\nEvaluating the trained Linear SVM on a test set ...\n";
    p = svm.predict(Xtest, model);
    std::cout << "\nTest Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == ytest)) * 100 << "\n";
}

} // SVM_ns
