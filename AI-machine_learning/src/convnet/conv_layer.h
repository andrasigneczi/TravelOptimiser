#ifndef __CONVLAYER_H__
#define __CONVLAYER_H__

#include "forward_backward_if.h"
#include "cnoptimizer.h"
#include <memory>

/*
 * Convolutional layer parameters
 * ------------------------------
 *  number of filters: fc
 *  number of channels: nc
 *  img: n_H x n_W x nc,
 *  filter: f_H x f_W x (nc * fc),
 *  padding: p,
 *  stride: s,
 *  output size: floor((n_H + 2p - f_H) / s + 1) x floor((n_W + 2p - f_W) / s + 1) x fc
 *
 *  layer_size: tuple consisting (depth, height, width)
 *  kernel_size: tuple consisting (number_of_kernels, inp_depth, inp_height, inp_width)
 *  fan: tuple of number of nodes in previous layer and this layer
 */

class ConvLayer : public ForwardBackwardIF
{
    friend class ConvLayerTest;
public:
    ConvLayer(int f_H, int f_W, int n_C_prev, int n_C, int pad, int stride, CNOptimizerType optimizerType);
    ConvLayer(std::string prefix);

    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;
    
    arma::mat forward(arma::mat X) override { UNUSED(X); return arma::mat(); }
    arma::mat backward(arma::mat dX) override  { UNUSED(dX); return arma::mat(); }
    
    bool is4D() { return true; }
    void updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) override;
    void accept(Visitor& visitor) override { visitor.visit(this); }
    double getWeightSquareSum() override { return arma::accu(arma::square(mW)); }

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat4D zeroPad(const arma::mat4D& A_prev);
    double convSingleStep(arma::cube a_slice_prev, arma::cube W, arma::cube b);
    arma::cube copyBySlice(const arma::mat4D& W, size_t s);
    void addSlice(arma::mat4D& W, size_t s, arma::cube val);
    void addSlice(arma::mat4D& W, size_t s, double val);

    int mPad;
    int mStride;
    arma::mat4D mW; // Weights, kernel, array of shape (f_H, f_W, n_C_prev, n_C)
    arma::mat4D mB; // Biases, array of shape (1, 1, 1, n_C)
    arma::mat4D mCache; // A_prev
    arma::mat4D mdA_prev;
    arma::mat4D mdW;
    arma::mat4D mdb;

    std::unique_ptr<CNOptimizer<arma::mat4D>> mOptimizer;
};

#endif // __CONVLAYER_H__
