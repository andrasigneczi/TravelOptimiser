#ifndef __POOLLAYER_H__
#define __POOLLAYER_H__

#include "forward_backward_if.h"

class PoolLayer : public ForwardBackwardIF
{
    friend class ConvLayerTest;
public:

    enum Mode {
        MAX,
        AVG
    };

    PoolLayer(int f_H, int f_W, int stride, Mode mode);
    PoolLayer(std::string prefix);

    std::vector<arma::cube> forward(std::vector<arma::cube> A_prev) override;
    std::vector<arma::cube> backward(std::vector<arma::cube> dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    int  mFH;
    int  mFW;
    int  mStride;
    Mode mMode;
    std::vector<arma::cube> mCache; //A_prev;
};

#endif // __POOLLAYER_H__
