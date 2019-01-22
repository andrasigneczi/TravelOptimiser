#ifndef __DROPOUT_LAYER_H__
#define __DROPOUT_LAYER_H__

#include "forward_backward_if.h"
#include "layerobserver.h"

class Dropout : public ForwardBackwardIF, public LayerSubject {
    friend class DropoutTest;
public:
    arma::mat4D forward(arma::mat4D A_prev) override { UNUSED(A_prev); return arma::mat4D(); };
    arma::mat4D backward(arma::mat4D dZ) override { UNUSED(dZ); return {arma::mat4D()}; };

    arma::mat forward(arma::mat X) override;
    arma::mat backward(arma::mat dX) override;
    
    bool is4D() { return false; }
    void updateParameters(double learning_rate, double beta, double beta1, double beta2,  double epsilon, int batch_size) override;

    void accept(Visitor& visitor) override { visitor.visit(this); }

    void saveState(std::ofstream& output) override;
    void loadState(std::ifstream& input) override;
    
    void setKeepProb(double keepProb) {mKeepProb = keepProb;}
private:
    double mKeepProb;
    arma::mat mCache;
};

#endif // __DROPOUT_LAYER_H__
