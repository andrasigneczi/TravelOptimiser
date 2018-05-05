#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <armadillo>
#include <vector>
#include "CostAndGradient.h"

class QCustomPlot;

class NeuralNetwork : public CostAndGradient {
public:
    struct TrainParams {
        int layerSize;
        double lambda;
        double cost;
    };

    using CostAndGradient::CostAndGradient;

    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override;
    // special return value std::numeric_limits<double>::max(); means not found
    arma::mat predict( const arma::mat& X, const std::vector<arma::mat>& thetas );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
    arma::mat sigmoidGradient( const arma::mat& z );
    arma::mat randInitializeWeights( int L_in, int L_out );
    void checkNNGradients( double lambda = 0 );
    arma::mat debugInitializeWeights( int fan_out, int fan_in );
    arma::mat computeNumericalGradient( const arma::mat& nn_params );
    std::vector<arma::mat> extractThetas( const arma::mat& nn_params );
    arma::mat train(int iteration, bool verbose = true);
    void plotLearningCurve(QCustomPlot* customPlot);
    void plotValidationCurve(QCustomPlot* customPlot,int iteration);
    TrainParams searchTrainParams( int minLayerSize, int maxLayerSize, int stepSize );
    TrainParams searchTrainParams2( int minLayerSize, int maxLayerSize, int stepSize );
    void prepareTrainingAndValidationSet(arma::mat& X, arma::mat& y, arma::mat& Xval, arma::mat& Yval);
    void removeDuplication(arma::mat& dataset);

private:
    arma::mat learningCurve(arma::mat& Xval, arma::mat& yval);
    arma::mat validationCurve(arma::mat& Xval, arma::mat& yval, int iteration);
    static void plotMatrix( QCustomPlot* customPlot, const arma::mat& matrix );
};

template<typename T>
T mod(T a, int n)
{
    return a - floor(a/n)*n;
}

#endif // __NEURAL_NETWORK_H__
