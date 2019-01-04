#include "activation_layer.h"

arma::mat4D Sigmoid::forward(arma::mat4D Z) {
    mCache = 1.0/(1.0+arma::exp(-Z));
    return mCache;
}

arma::mat4D Sigmoid::backward(arma::mat4D dA) {
    return dA % mCache % (1. - mCache);
}

arma::mat Sigmoid::forward(arma::mat Z) {
    mCache2 = 1.0/(1.0+arma::exp(-Z));
    return mCache2;
}

arma::mat Sigmoid::backward(arma::mat dA) {
    return dA % mCache2 % (1. - mCache2);
}

void Sigmoid::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Sigmoid::loadState(std::ifstream& input) {
    UNUSED(input);
}

arma::mat4D Relu::forward(arma::mat4D Z) {
    mCache = Z;
    //Z.elem( arma::find(Z < 0.0) ).zeros();
    arma::Elem(Z, arma::find(Z < 0.0)).zeros();
    return Z;
}

arma::mat4D Relu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).ones();
    //gZ.elem( arma::find(gZ <= 0.0) ).zeros();
    arma::Elem(mCache, arma::find(mCache > 0.0)).ones();
    arma::Elem(mCache, arma::find(mCache <= 0.0)).zeros();
    return dA % mCache;
}

arma::mat Relu::forward(arma::mat Z) {
    mCache2 = Z;
    Z.elem( arma::find(Z < 0.0) ).zeros();
    return Z;
}

arma::mat Relu::backward(arma::mat dA) {
    mCache2.elem( arma::find(mCache2 > 0.0) ).ones();
    mCache2.elem( arma::find(mCache2 <= 0.0) ).zeros();
    return dA % mCache2;
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

arma::mat4D Tanh::backward(arma::mat4D dA) {
    return dA % (1. - arma::pow(mCache,2));
}

arma::mat Tanh::forward(arma::mat Z) {
    const arma::mat pz = arma::exp(Z);
    const arma::mat nz = arma::exp(-Z);
    mCache2 = (pz - nz)/(pz + nz);
    return mCache2;
}

arma::mat Tanh::backward(arma::mat dA) {
    return dA % (1. - arma::pow(mCache2,2));
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

arma::mat4D LeakyRelu::backward(arma::mat4D dA) {
    //gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
    //gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
    arma::Elem(dA, arma::find(mCache > 0.0)).fill(1.0);
    arma::Elem(dA, arma::find(mCache < 0.0)).fill(0.01);
    return dA%mCache;
}

arma::mat LeakyRelu::forward(arma::mat Z) {
    mCache2 = Z;
    Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    return Z;
}

arma::mat LeakyRelu::backward(arma::mat dA) {
    mCache2.elem( arma::find(mCache2 > 0.0) ).fill(1.);
    mCache2.elem( arma::find(mCache2 < 0.0) ).fill(0.01);
    return dA % mCache2;
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
    std::cerr << "Softmax::" << __FUNCTION__ << ": size(gZ): " << size(gZ) << "\n";
    std::cerr << "Softmax::" << __FUNCTION__ << ": size(mCache): " << size(mCache) << "\n";
    size_t m = mCache.n_cols;
    //gZ[Y.argmax(axis=0),range(m)] -= 1
    arma::mat maxS = arma::conv_to<arma::mat>::from(arma::index_max(mCache,0));
    std::cerr << "Softmax::" << __FUNCTION__ << ": size(maxS): " << size(maxS) << "\n";
    arma::mat dZ = gZ;
    for(size_t i = 0; i < m; ++i){
        //gZ[maxS(0,i), i] -= 1;
        dZ(maxS(0,i),i) -= 1;
    }
    dZ = dZ/(double)m;
    std::cerr << "Softmax::" << __FUNCTION__ << ": end\n";
    return dZ;
}

void Softmax::saveState(std::ofstream& output) {
    UNUSED(output);
}

void Softmax::loadState(std::ifstream& input) {
    UNUSED(input);
}
