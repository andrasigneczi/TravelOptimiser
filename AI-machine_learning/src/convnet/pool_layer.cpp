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

}

std::vector<arma::cube> PoolLayer::forward(std::vector<arma::cube> A_prev) {
    size_t m = A_prev.size();
    size_t n_H_prev = A_prev[0].n_rows;
    size_t n_W_prev = A_prev[0].n_cols;
    size_t n_C_prev = A_prev[0].n_slices;

    int n_H = int(1 + (n_H_prev - mFH) / mStride);
    int n_W = int(1 + (n_W_prev - mFW) / mStride);
    size_t n_C = n_C_prev;

    std::vector<arma::cube> A = std::vector<arma::cube>(m, arma::zeros(n_H, n_W, n_C));

    for(size_t i = 0; i < m; ++i) {
        for(size_t h = 0; h < n_H; ++h) {
            for(size_t w = 0; w < n_W; ++w) {
                for(size_t c = 0; c < n_C; ++c) {
                    size_t vert_start = h * mStride;
                    size_t vert_end = vert_start + mFH;
                    size_t horiz_start = w * mStride;
                    size_t horiz_end = horiz_start + mFW;

                    arma::cube A_slice_prev = A_prev[i].subcube(arma::span(vert_start, vert_end - 1),
                                                                   arma::span(horiz_start, horiz_end - 1),
                                                                   arma::span::all);
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

std::vector<arma::cube> PoolLayer::backward(std::vector<arma::cube> dZ) {

}

void PoolLayer::saveState(std::ofstream& output) {

}

void PoolLayer::loadState(std::ifstream& input) {

}
