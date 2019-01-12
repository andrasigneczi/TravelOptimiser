#ifndef __POOLLAYER_H__
#define __POOLLAYER_H__

#include "forward_backward_if.h"

class PoolLayer : public ForwardBackwardIF
{
    friend class PoolLayerTest;
public:

    enum Mode {
        MAX,
        AVG
    };

    PoolLayer(int f_H, int f_W, int stride, Mode mode);
    PoolLayer(std::string prefix);

    arma::mat4D forward(arma::mat4D A_prev) override;
    arma::mat4D backward(arma::mat4D dZ) override;

    arma::mat forward(arma::mat X) override { UNUSED(X); return arma::mat(); }
    arma::mat backward(arma::mat dX) override  { UNUSED(dX); return arma::mat(); }
    
    bool is4D() { return true; }
    void updateParameters(double learning_rate = 0.01, double beta = 0.9,
                          double beta1 = 0.9, double beta2 = 0.999,  double epsilon = 1e-8) override { UNUSED(learning_rate); };
    void accept(Visitor& visitor) override { visitor.visit(this); }

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
