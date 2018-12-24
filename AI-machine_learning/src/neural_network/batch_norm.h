#ifndef BATCH_NORM_H
#define BATCH_NORM_H

#include "Util.h"
#include <stack>

class BatchNorm
{
public:
    Util::UStringMatMap* initializeEpoch(size_t index, size_t L, const Util::UStringMatMap& parameters);
    void updateParameters(size_t L, double learning_rate);
    arma::mat batchNorm_forward(const arma::mat& Z, size_t l);
    arma::mat batchNorm_backward(arma::mat dZ, size_t l);
    arma::mat avgBatchParam(std::string key);

    void saveState(std::ofstream& output);
    void loadState(std::ifstream& input);

    void setTrainOff() { mLastBNI = nullptr; }
    bool isTrainOff() const { return !mLastBNI; }
private:
    arma::mat batchNorm_forward(const arma::mat& Z, const arma::mat& gamma, const arma::mat& beta, arma::mat& running_mean, arma::mat& running_var);

    typedef Util::UStringMatMap BatchNormItem;
    std::vector<BatchNormItem> mBatchNorm;
    BatchNormItem* mLastBNI;
    std::stack<arma::mat> mBNCaches;
};

#endif // BATCH_NORM_H
