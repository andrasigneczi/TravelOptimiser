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

    arma::mat4D forward(arma::mat4D A_prev) override;
    std::vector<arma::mat4D> backward(arma::mat4D dZ) override;

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;

private:
    arma::mat createMaskFromWindow(arma::mat x);
    arma::mat distributeValue(double dZ, int n_H, int n_W);

    int  mFH;
    int  mFW;
    int  mStride;
    Mode mMode;
    arma::mat4D mCache; //A_prev;
};

#endif // __POOLLAYER_H__
