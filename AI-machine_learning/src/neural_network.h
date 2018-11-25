#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <armadillo>
#include <vector>
#include "CostAndGradient.h"

class QCustomPlot;

class NeuralNetwork final : public CostAndGradient {
public:
    struct TrainParams {
        int layerSize;
        double lambda;
        double cost;
    };

    class YMappperIF {
    public:
        virtual double fromYtoYY(double y ) = 0;
        virtual double fromYYtoY( size_t index ) = 0;
    };

    enum ActivationFunction {
        SIGMOID,
        RELU,
        TANH,
        LRELU
    };
    
    //using CostAndGradient::CostAndGradient;
    NeuralNetwork( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda, YMappperIF& yMappper, 
                   bool featureScaling = false, ActivationFunction af = SIGMOID );

    RetVal& calc( const arma::mat& nn_params, bool costOnly = false ) override;
    std::vector<arma::mat> calc2( const std::vector<arma::mat>& thetas, bool costOnly );
    // special return value std::numeric_limits<double>::max(); means not found
    arma::mat predict( const arma::mat& X, const std::vector<arma::mat>& thetas );
    arma::mat sigmoid( const arma::mat& X, const arma::mat& theta );
    arma::mat tanh( const arma::mat& X, const arma::mat& theta );
    arma::mat relu( const arma::mat& X, const arma::mat& theta );
    arma::mat leaky_relu( const arma::mat& X, const arma::mat& theta );

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
    void removeDuplication(arma::mat& dataset);
    
    
    std::vector<arma::mat> miniBatchGradientDescent( bool initTheta, long long iteration, size_t batchSize, double learning_rate, bool verbose );
    double accuracy(const std::vector<arma::mat>& thetas);

    //arma::mat featureScaling( const arma::mat& X, bool saveFactors );
    // feature mapping
    //void saveCurrentStatus(std::string fileNamePrefix);
    //void loadCurrentStatus(std::string fileNamePrefix);


private:
    void displayActivationFunction();
    arma::mat learningCurve(arma::mat& Xval, arma::mat& yval);
    arma::mat validationCurve(arma::mat& Xval, arma::mat& yval, int iteration);
    const arma::mat& mLayerSizes; // input layer, hidden1, hidden2, ..., output
    YMappperIF& mYMappper;
    const ActivationFunction mActivationFunction;
    typedef arma::mat (NeuralNetwork::*ActivationFunctionP)( const arma::mat& X, const arma::mat& theta );
    ActivationFunctionP mAF;
};

template<typename T>
T mod(T a, double n)
{
    return a - floor(a/n)*n;
}

#endif // __NEURAL_NETWORK_H__
