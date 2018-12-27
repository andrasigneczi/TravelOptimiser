#ifndef __CONVLAYER_H__
#define __CONVLAYER_H__

#include "forward_backward_if.h"

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
public:
    ConvLayer(int pad, int stride);
    ConvLayer(std::string prefix);

    std::vector<arma::cube> forward(std::vector<arma::cube> A_prev) override;
    std::vector<arma::cube> backward(std::vector<arma::cube> dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    std::vector<arma::cube> zeroPad(const std::vector<arma::cube>& A_prev);
    double conv_single_step(arma::cube a_slice_prev, arma::cube W, arma::cube b);

    int mPad;
    int mStride;
    std::vector<arma::cube> mW; // Weights, kernel, array of shape (f_H, f_W, n_C_prev, n_C)
    std::vector<arma::cube> mB; // Biases, array of shape (1, 1, 1, n_C)
    std::vector<arma::cube> mCache; // A_prev
};

#endif // __CONVLAYER_H__
