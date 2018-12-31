#include "activation_layer.h"

arma::mat4D Sigmoid::forward(arma::mat4D Z) {
    return 1.0/(1.0+arma::exp(-Z));
}

std::vector<arma::mat4D> Sigmoid::backward(arma::mat4D gZ) {
    return {gZ % (1. - gZ)};
}

void Sigmoid::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Sigmoid::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D Relu::forward(arma::mat4D Z) {
    //Z.elem( arma::find(Z < 0.0) ).zeros();
    arma::Elem(Z, arma::find(Z < 0.0)).zeros();
    return Z;
}

std::vector<arma::mat4D> Relu::backward(arma::mat4D gZ) {
    //gZ.elem( arma::find(gZ > 0.0) ).ones();
    //gZ.elem( arma::find(gZ <= 0.0) ).zeros();
    arma::Elem(gZ, arma::find(gZ > 0.0)).ones();
    arma::Elem(gZ, arma::find(gZ <= 0.0)).zeros();
    return {gZ};
}

void Relu::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Relu::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D Tanh::forward(arma::mat4D Z) {
    const arma::mat4D pz = arma::exp(Z);
    const arma::mat4D nz = arma::exp(-Z);
    return (pz - nz)/(pz + nz);
}

std::vector<arma::mat4D> Tanh::backward(arma::mat4D gZ) {
    return {(1. - arma::pow(gZ,2))};
}

void Tanh::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Tanh::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D LeakyRelu::forward(arma::mat4D Z) {
    //Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    arma::Elem(Z, arma::find(Z <= 0.0)) *= 0.01;
    return Z;
}

std::vector<arma::mat4D> LeakyRelu::backward(arma::mat4D gZ) {
    //gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
    //gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
    arma::Elem(gZ, arma::find(gZ > 0.0)).fill(1.0);
    arma::Elem(gZ, arma::find(gZ < 0.0)).fill(0.01);
    return {gZ};
}

void LeakyRelu::saveState(std::ofstream& output) {
    UNUSED(output);
}

void LeakyRelu::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat Softmax::forward(arma::mat Z) {
    arma::mat exps = arma::exp(Util::minus(Z,arma::max(Z)));
    exps = Util::div(exps,arma::sum(exps, 1));
    return exps;
}

arma::mat Softmax::backward(arma::mat gZ) {
    size_t m = mY.n_cols;
    //gZ[Y.argmax(axis=0),range(m)] -= 1
    arma::mat maxS = arma::conv_to<arma::mat>::from(arma::index_max(mY,0));
    arma::mat dZ = gZ;
    for(size_t i = 0; i < m; ++i){
        //gZ[maxS(0,i), i] -= 1;
        dZ(maxS(0,i),i) -= 1;
    }
    dZ = dZ/(double)m;
    return dZ;
}

void Softmax::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Softmax::loadState(std::ifstream& input) {
    UNUSED(input);
}

Softmax::Softmax(arma::mat Y) : mY(Y) {

}
