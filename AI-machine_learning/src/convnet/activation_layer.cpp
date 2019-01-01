#include "activation_layer.h"

arma::mat4D Sigmoid::forward(arma::mat4D Z) {
    mCache = 1.0/(1.0+arma::exp(-Z));
    return mCache;
}

std::vector<arma::mat4D> Sigmoid::backward(arma::mat4D dA) {
    return {dA % mCache % (1. - mCache)};
}

void Sigmoid::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Sigmoid::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D Relu::forward(arma::mat4D Z) {
    //Z.elem( arma::find(Z < 0.0) ).zeros();
    mCache = Z;
    arma::Elem(mCache, arma::find(mCache < 0.0)).zeros();
    return mCache;
}

std::vector<arma::mat4D> Relu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).ones();
    //gZ.elem( arma::find(gZ <= 0.0) ).zeros();
    arma::Elem(mCache, arma::find(mCache > 0.0)).ones();
    arma::Elem(mCache, arma::find(mCache <= 0.0)).zeros();
    return {dA % mCache};
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
    mCache = (pz - nz)/(pz + nz);
    return mCache;
}

std::vector<arma::mat4D> Tanh::backward(arma::mat4D dA) {
    return {dA % (1. - arma::pow(mCache,2))};
}

void Tanh::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Tanh::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D LeakyRelu::forward(arma::mat4D Z) {
    //Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    mCache = Z;
    arma::Elem(Z, arma::find(Z <= 0.0)) *= 0.01;
    return Z;
}

std::vector<arma::mat4D> LeakyRelu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
    //gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
    arma::Elem(dA, arma::find(mCache > 0.0)).fill(1.0);
    arma::Elem(dA, arma::find(mCache < 0.0)).fill(0.01);
    return {dA};
}

void LeakyRelu::saveState(std::ofstream& output) {
    UNUSED(output);
}

void LeakyRelu::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat Softmax::forward(arma::mat Z) {
    arma::mat exps = arma::exp(Util::minus(Z,arma::max(Z)));
    mCache = Util::div(exps,arma::sum(exps, 1));
    return mCache;
}

// Actually we don't need this function
arma::mat Softmax::backward(arma::mat gZ) {
    size_t m = mCache.n_cols;
    //gZ[Y.argmax(axis=0),range(m)] -= 1
    arma::mat maxS = arma::conv_to<arma::mat>::from(arma::index_max(mCache,0));
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
