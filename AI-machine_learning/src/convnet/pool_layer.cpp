#include "pool_layer.h"
#include "Util.h"

PoolLayer::PoolLayer(int f_H, int f_W, int stride, PoolLayer::Mode mode)
    : mFH(f_H)
    , mFW(f_W)
    , mStride(stride)
    , mMode(mode)
{

}

PoolLayer::PoolLayer(std::string prefix)
{
    UNUSED(prefix);
}

arma::mat4D PoolLayer::forward(arma::mat4D A_prev) {
    size_t m = A_prev.size();
    size_t n_H_prev = A_prev[0].n_rows;
    size_t n_W_prev = A_prev[0].n_cols;
    size_t n_C_prev = A_prev[0].n_slices;

    int n_H = int(1 + (n_H_prev - mFH) / mStride);
    int n_W = int(1 + (n_W_prev - mFW) / mStride);
    size_t n_C = n_C_prev;

    arma::mat4D A = arma::zeros(m, n_H, n_W, n_C);

    for(size_t i = 0; i < m; ++i) {
        for(int h = 0; h < n_H; ++h) {
            for(int w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + mFH;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + mFW;

                    arma::cube A_slice_prev = A_prev[i].subcube(arma::span(vert_start, vert_end - 1),
                                                                   arma::span(horiz_start, horiz_end - 1),
                                                                   arma::span(c));
                    if(mMode == MAX) {
                        A[i](h, w, c) = A_slice_prev.max();
                    } else if(mMode == AVG) {
                        A[i](h, w, c) = arma::accu(A_slice_prev)/(double)A_slice_prev.size();
                    }
                }
            }
        }
    }
    mCache = A_prev;
    return A;
}

arma::mat4D PoolLayer::backward(arma::mat4D dA) {
    arma::mat4D& A_prev = mCache;
    size_t m = A_prev.size();
    //size_t n_H_prev = A_prev[0].n_rows;
    //size_t n_W_prev = A_prev[0].n_cols;
    //size_t n_C_prev = A_prev[0].n_slices;

    size_t n_H = dA[0].n_rows;
    size_t n_W = dA[0].n_cols;
    size_t n_C = dA[0].n_slices;

    arma::mat4D dA_prev = arma::zeros(A_prev.size(), A_prev[0].n_rows, A_prev[0].n_cols, A_prev[0].n_slices);
    for(size_t i = 0; i < m; ++i) {
        arma::cube a_prev_i = A_prev[i];
        for(size_t h = 0; h < n_H; ++h) {
            for(size_t w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + mFH;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + mFW;
                    if(mMode == MAX) {
                        arma::cube a_prev_slice = a_prev_i.subcube(arma::span(vert_start, vert_end - 1),
                                                                       arma::span(horiz_start, horiz_end - 1),
                                                                       arma::span(c));
                        arma::mat mask = createMaskFromWindow(a_prev_slice);
                        dA_prev[i](arma::span(vert_start, vert_end - 1),
                                arma::span(horiz_start, horiz_end - 1),
                                arma::span(c)) += mask * dA[i](h,w,c);

                    } else if(mMode == AVG) {
                        double da = dA[i](h,w,c);
                        dA_prev[i](arma::span(vert_start, vert_end - 1),
                                arma::span(horiz_start, horiz_end - 1),
                                arma::span(c)) += distributeValue(da, mFH, mFW);
                    }
                }
            }
        }
    }
    return dA_prev;
}

void PoolLayer::saveState(std::ofstream& output) {
    UNUSED(output);
}

void PoolLayer::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat PoolLayer::createMaskFromWindow(arma::mat x) {
    // mask = (x == np.max(x))
    return arma::conv_to<arma::mat>::from(x == x.max());
}

arma::mat PoolLayer::distributeValue(double dZ, int n_H, int n_W) {
    double average = dZ/((double)(n_H * n_W));
    return arma::ones(n_H, n_W) * average;
}

void PoolLayer::updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) {
    UNUSED(learning_rate);
    UNUSED(beta);
    UNUSED(beta1);
    UNUSED(beta2);
    UNUSED(epsilon);
    UNUSED(batch_size);
}
