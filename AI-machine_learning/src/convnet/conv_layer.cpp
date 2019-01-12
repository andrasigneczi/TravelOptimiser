#include "conv_layer.h"

ConvLayer::ConvLayer(int f_H, int f_W, int n_C_prev, int n_C, int pad, int stride, CNOptimizerType optimizerType)
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

    // -0.5x = -f
    // x = 2f
    // (a - 0.5) * 2f
    for(int i = 0; i < f_H; ++i) {
        mW.push_back(arma::randu(f_W, n_C_prev, n_C));
    }
    mB.push_back(arma::randu(1, 1, n_C));
    mOptimizer.reset(new CNOptimizer<arma::mat4D>(optimizerType, mW, mB, mdW, mdb));
}

ConvLayer::ConvLayer(std::string prefix) {
    UNUSED(prefix);
}

arma::mat4D ConvLayer::zeroPad(const arma::mat4D& A_prev) {
    arma::mat4D retV(A_prev.size(), arma::zeros(A_prev[0].n_rows + 2 * mPad, A_prev[0].n_cols + 2 * mPad, A_prev[0].n_slices));
    for(size_t i = 0; i < A_prev.size(); ++i) {
        arma::cube& c = retV[i];
        c.subcube(mPad, mPad, 0, c.n_rows - mPad - 1, c.n_cols - mPad - 1, c.n_slices - 1) = A_prev[i];
    }
    return retV;
}

double ConvLayer::convSingleStep(arma::cube a_slice_prev, arma::cube W, arma::cube b) {
    arma::cube s = a_slice_prev % W;
    double Z = arma::accu(s);
    Z += arma::accu(b);
    return Z;
}

arma::cube ConvLayer::copyBySlice(const arma::mat4D& W, size_t s) {
    // W[:,:,:,s]
    arma::cube retV(W.size(), W[0].n_rows, W[0].n_cols);
    for(size_t i = 0; i < W.size(); ++i) {
        retV(arma::span(i),arma::span::all, arma::span::all) = W[i].slice(s);
    }
    return retV;
}

void ConvLayer::addSlice(arma::mat4D& dW, size_t s, arma::cube val) {
    // std::cerr << __FUNCTION__ << ": dbg1\n";
    // std::cerr << __FUNCTION__ << ": val: "<< size(val) << "\n";
    // std::cerr << __FUNCTION__ << ": W: "<< size(W) << "\n";
    //dW[:,:,:,c] += A_slice_prev * dZ[i](h, w, c);

    for(size_t i = 0; i < dW.size(); ++i) {
        dW[i].slice(s) += val(i);
    }
}

void ConvLayer::addSlice(arma::mat4D& dB, size_t s, double val) {
    //std::cerr << __FUNCTION__ << ": dbg1\n";
    for(size_t i = 0; i < dB.size(); ++i) {
        dB[i].slice(s) += val;
    }
}

/*
 * Parameters:
 *    A_prev -- output activations of the previous layer, array of shape (m, n_H_prev, n_W_prev, n_C_prev)
 * Return:
 *    Z -- conv output, array of shape (m, n_H, n_W, n_C)
 */
arma::mat4D ConvLayer::forward(arma::mat4D A_prev) {
    size_t m = A_prev.size();
    size_t n_H_prev = A_prev[0].n_rows;
    size_t n_W_prev = A_prev[0].n_cols;
    //size_t n_C_prev = A_prev[0].n_slices;

    size_t f_H = mW.size();
    size_t f_W = mW[0].n_rows;
    //size_t n_C_prev = mW[0].n_cols;
    size_t n_C = mW[0].n_slices;

    // Compute the dimensions of the CONV output volume.
    int n_H = (n_H_prev - f_H + 2 * mPad)/mStride + 1;
    int n_W = (n_W_prev - f_W + 2 * mPad)/mStride + 1;

    // Initialize the output volume Z with zeros.
    arma::mat4D Z(m, arma::zeros(n_H, n_W, n_C));

    std::cerr << __FUNCTION__ << ": dbg1\n";
    // Create A_prev_pad by padding A_prev
    arma::mat4D A_prev_pad = zeroPad(A_prev);

    std::cerr << __FUNCTION__ << ": dbg2\n";
    for(size_t i = 0; i < m; ++i) {
        const arma::cube& a_prev_pad_i = A_prev_pad[i];
        for(int h = 0; h < n_H; ++h) {
            for(int w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + f_H;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + f_W;

                    // a_slice_prev = a_prev_pad[vert_start:vert_end,horiz_start:horiz_end,:]
                    // std::cerr << __FUNCTION__ << ": dbg3\n";
                    //arma::cube A_slice_prev = a_prev_pad_i.subcube(vert_start, horiz_start, 0, vert_end, horiz_end, a_prev_pad_i.n_slices - 1);
                    arma::cube A_slice_prev = a_prev_pad_i.subcube(arma::span(vert_start, vert_end - 1),
                                                                   arma::span(horiz_start, horiz_end - 1),
                                                                   arma::span::all);
                    // Z[i, h, w, c] = conv_single_step(a_slice_prev,W[:,:,:,c],b[:,:,:,c])
                    // std::cerr << __FUNCTION__ << ": dbg4\n";
                    // std::cerr << __FUNCTION__ << ": A_prev: " << size(A_prev) << "\n";
                    // std::cerr << __FUNCTION__ << ": A_prev_pad: " << size(A_prev_pad) << "\n";
                    // std::cerr << __FUNCTION__ << ": a_prev_pad_i: " << size(a_prev_pad_i) << "\n";
                    // std::cerr << __FUNCTION__ << ": A_slice_prev: " << size(A_slice_prev) << "\n";
                    // std::cerr << __FUNCTION__ << ": mW: " << size(mW) << "\n";
                    // std::cerr << __FUNCTION__ << ": mB: " << size(mB) << "\n";
                    // std::cerr << __FUNCTION__ << ": copyBySlice(mW, c): " << size(copyBySlice(mW, c)) << "\n";
                    // std::cerr << __FUNCTION__ << ": copyBySlice(mB, c): " << size(copyBySlice(mB, c)) << "\n";
                    Z[i](h, w, c) = convSingleStep(A_slice_prev, copyBySlice(mW, c), copyBySlice(mB, c));
                    // std::cerr << __FUNCTION__ << ": dbg5\n";
                }
            }
        }
    }
    mCache = A_prev;
    return Z;
}

arma::mat4D ConvLayer::backward(arma::mat4D dZ) {
    std::cerr << __FUNCTION__ << ": dbg0\n";

    arma::mat4D& A_prev = mCache;
    size_t m = A_prev.size();
    std::cerr << __FUNCTION__ << ": A_prev.size(): " << A_prev.size() << "\n";
    size_t n_H_prev = A_prev[0].n_rows;
    size_t n_W_prev = A_prev[0].n_cols;
    size_t n_C_prev = A_prev[0].n_slices;

    std::cerr << __FUNCTION__ << ": dbg01\n";

    size_t f_H = mW.size();
    size_t f_W = mW[0].n_rows;
    //size_t n_C_prev = mW[0].n_cols;
    size_t n_C = mW[0].n_slices;

    std::cerr << __FUNCTION__ << ": dbg02\n";

    //size_t m = dZ.size();
    size_t n_H = dZ[0].n_rows;
    size_t n_W = dZ[0].n_cols;
    //size_t n_C = dZ[0].n_slices;

    std::cerr << __FUNCTION__ << ": dbg1\n";
    mdA_prev = arma::zeros(m, n_H_prev, n_W_prev, n_C_prev);
    mdW = arma::zeros(f_H, f_W, n_C_prev, n_C);
    mdb = arma::zeros(1,1,1,n_C);

    arma::mat4D A_prev_pad = zeroPad(A_prev);
    arma::mat4D dA_prev_pad = arma::zeros(A_prev_pad.size(), A_prev_pad[0].n_rows, A_prev_pad[0].n_cols, A_prev_pad[0].n_slices);

    std::cerr << __FUNCTION__ << ": dbg2\n";
    for(size_t i = 0; i < m; ++i) {
        arma::cube a_prev_pad_i = A_prev_pad[i];
        arma::cube da_prev_pad_i = dA_prev_pad[i];
        for(size_t h = 0; h < n_H; ++h) {
            for(size_t w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + f_H;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + f_W;

                    // std::cerr << __FUNCTION__ << ": dbg3\n";
                    arma::cube A_slice_prev = a_prev_pad_i.subcube(arma::span(vert_start, vert_end - 1),
                                                                   arma::span(horiz_start, horiz_end - 1),
                                                                   arma::span::all);
                    // std::cerr << __FUNCTION__ << ": dbg4\n";
                    da_prev_pad_i.subcube(arma::span(vert_start, vert_end - 1),
                                        arma::span(horiz_start, horiz_end - 1),
                                        arma::span::all) += copyBySlice(mW, c) * dZ[i](h, w, c);
                    // std::cerr << __FUNCTION__ << ": dbg5\n";
                    //dW[:,:,:,c] += A_slice_prev * dZ[i](h, w, c);
                    //db[:,:,:,c] += dZ[i](h, w, c);
                    addSlice(mdW, c, A_slice_prev * dZ[i](h, w, c));
                    // std::cerr << __FUNCTION__ << ": dbg6\n";
                    addSlice(mdb, c, dZ[i](h, w, c));
                    // std::cerr << __FUNCTION__ << ": dbg7\n";
                }

            }
        }
        mdA_prev[i] = da_prev_pad_i.subcube(arma::span(mPad,da_prev_pad_i.n_rows - mPad - 1),
                                         arma::span(mPad,da_prev_pad_i.n_cols - mPad - 1),
                                         arma::span::all);
        //std::cerr << __FUNCTION__ << ": dbg8\n";
    }
    return mdA_prev;
    // return dA_prev, dW, db
}

void ConvLayer::saveState(std::ofstream& output) {
    UNUSED(output);
}

void ConvLayer::loadState(std::ifstream& input) {
    UNUSED(input);
}

void ConvLayer::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon) {
    mOptimizer->updateParameters(learning_rate, beta, beta1, beta2,  epsilon);
}
