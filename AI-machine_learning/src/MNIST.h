#ifndef __MNIST_H__
#define __MNIST_H__

#include "Util.h"
#include <iostream>

class Mnist {
public:
    enum Type {
        TRAINING,
        TEST
    };
    
    Mnist(std::string folderName);
    void load(Type type, size_t num);
    
    void getTrainingData(arma::mat4D& X, arma::mat& Y);
    void getTestData(arma::mat4D& X, arma::mat& Y);

    void getTrainingData(arma::mat& X, arma::mat& Y);
    void getTestData(arma::mat& X, arma::mat& Y);

    void begin(int batchSize);
    void isEnd();
    void next(arma::mat4D& X, arma::mat& Y);

    void printTestImage(int index);
private:
    uint32_t readBigEndian(std::ifstream& stream);
    
    const std::string mTrainingImgFileName;
    const std::string mTrainingLabelFileName;
    const std::string mTestImgFileName;
    const std::string mTestLabelFileName;

    arma::mat4D mX;
    arma::mat   mY;
    arma::mat4D mXtest;
    arma::mat   mYtest;
};

#endif // __MNIST_H__
