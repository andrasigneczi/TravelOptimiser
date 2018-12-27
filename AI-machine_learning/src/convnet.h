#ifndef CONVNET_H
#define CONVNET_H

/*
 * Layer types
 *  - Convolution
 *  - Pooling
 *  - Fully connected
 *
 * Conv:
 *  number of filters: fc
 *  img: n x n x nc,
 *  filter: f x f x (nc * fc),
 *  padding: p,
 *  stride: s,
 *  utput size: floor((n + 2p - f) / s + 1) x floor((n + 2p - f) / s + 1) x fc
 *
 * Pool: max, avarage
 *  img: nh x nw x nc,
 *  filer: f x f x (nc * fc),
 *  stride: s,
 *  output: floor((nh - f) / s + 1) x floor((nw - f) / s + 1) x (nc * fc)
 *
 * FC:
 *  input: flattened conv layer's
 *
 * Model:
 *  Conv << Relu << MaxPool << Conv << Relu << MaxPool << Fc << Sigmoid << Fc << Sigmoid << Softmax
 *
 * Every step must be an Object, which stores its own cache. So, the backward step will be easy.
 * arma::cube 3D matrix
 * 4D: vector<arma::cube>
 */

class ConvNet
{
public:
    ConvNet();
};

#endif // CONVNET_H
