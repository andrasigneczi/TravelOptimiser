#include "conv_layer.h"

ConvLayer::ConvLayer(int pad, int stride)
    : mPad(pad)
    , mStride(stride)
{
    // Inicialization of mW and mB

    //Input:
    //    layer_size: tuple consisting (depth, height, width)
    //    kernel_size: tuple consisting (number_of_kernels, inp_depth, inp_height, inp_width)
    //    fan: tuple of number of nodes in previous layer and this layer
    //    params: directory consists of pad_len and stride,
    //            filename (to load weights from file)

    // f = np.sqrt(6)/np.sqrt(fan[0] + fan[1])
    // epsilon = 1e-6
    // self.kernel = np.random.uniform(-f, f + epsilon, kernel_size)
    // self.bias = np.random.uniform(-f, f + epsilon, kernel_size[0])

    // arma::randu(kernel_size)

}

ConvLayer::ConvLayer(std::string prefix)
{

}

std::vector<arma::cube> ConvLayer::zeroPad(const std::vector<arma::cube>& A_prev) {
    std::vector<arma::cube> retV(A_prev.size(), arma::zeros(A_prev[0].n_rows + 2 * mPad, A_prev[0].n_cols + 2 * mPad, A_prev[0].n_slices));
    for(size_t i = 0; i < A_prev.size(); ++i) {
        arma::cube& c = retV[i];
        c.subcube(mPad, mPad, 0, c.n_rows - mPad - 1, c.n_cols - mPad - 1, c.n_slices - 1) = A_prev[i];
    }
    return retV;
}

double ConvLayer::conv_single_step(arma::cube a_slice_prev, arma::cube W, arma::cube b) {
    arma::cube s = a_slice_prev % W;
    double Z = arma::accu(s);
    Z += arma::accu(b);
    return Z;
}

/*
 * Parameters:
 *    A_prev -- output activations of the previous layer, array of shape (m, n_H_prev, n_W_prev, n_C_prev)
 * Return:
 *    Z -- conv output, array of shape (m, n_H, n_W, n_C)
 */
std::vector<arma::cube> ConvLayer::forward(std::vector<arma::cube> A_prev) {
    size_t m = A_prev.size();
    size_t n_H_prev = A_prev[0].n_rows;
    size_t n_W_prev = A_prev[0].n_cols;
    size_t n_C_prev = A_prev[0].n_slices;

    size_t f_H = mW.size();
    size_t f_W = mW[0].n_rows;
    //size_t n_C_prev = mW[0].n_cols;
    size_t n_C = mW[0].n_slices;

    // Compute the dimensions of the CONV output volume.
    int n_H = (int)(n_H_prev - f_H + 2 * mPad)/mStride + 1;
    int n_W = (int)(n_W_prev - f_W + 2 * mPad)/mStride + 1;

    // Initialize the output volume Z with zeros.
    std::vector<arma::cube> Z(m, arma::zeros(n_H, n_W, n_C));

    // Create A_prev_pad by padding A_prev
    std::vector<arma::cube> A_prev_pad = zeroPad(A_prev);
    for(size_t i = 0; i < m; ++i) {
        arma::cube& a_prev_pad_i = A_prev_pad[i];
        for(size_t h = 0; h < n_H; ++h) {
            for(size_t w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + f_H;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + f_W;

                    arma::cube A_slice_prev = a_prev_pad_i.subcube(vert_start, horiz_start, 0, vert_end, horiz_end, a_prev_pad_i.n_slices - 1);
                    // Z[i](h, w, c) = conv_single_step(A_slice_prev, mW[:,:,:,c], mB[:,:,:,c]);
                }
            }
        }
    }
}

std::vector<arma::cube> ConvLayer::backward(std::vector<arma::cube> dZ) {

}

void ConvLayer::saveState(std::ofstream& output) {

}

void ConvLayer::loadState(std::ifstream& input) {

}
