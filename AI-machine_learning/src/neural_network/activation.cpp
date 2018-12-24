#include "activation.h"
#include "Util.h"

namespace Activation
{
arma::mat sigmoid( const arma::mat& Z ) {
    return 1.0/(1.0+arma::exp(-Z));
}

arma::mat tanh( const arma::mat& Z ) {
    const arma::mat pz = arma::exp(Z);
    const arma::mat nz = arma::exp(-Z);
    return (pz - nz)/(pz + nz);
}

arma::mat relu( arma::mat Z ) {
    // A = np.maximum(0,Z)
    Z.elem( arma::find(Z < 0.0) ).zeros();
    return Z;
}

arma::mat leaky_relu( arma::mat Z ) {
    //const arma::mat Z2 = Z * 0.01;
    //arma::uvec u = arma::find(Z < Z2);
    //for( size_t i = 0; i < u.size(); ++i ) {
    //    if( Z2[u[i]] > Z[u[i]] ) {
    //        Z[u[i]] = Z2[u[i]];
    //    }
    //}
    Z.elem( arma::find(Z <= 0.0) ) *= 0.01;
    return Z;
}

arma::mat softmax( arma::mat Z ) {
    // exps = np.exp(Z - np.max(Z))
    // A = exps / np.sum(exps, axis=1, keepdims=True)
    arma::mat exps = arma::exp(Util::minus(Z,arma::max(Z)));
    //arma::mat exps = arma::exp(Z-Z.max()));
    exps = Util::div(exps,arma::sum(exps, 1));

    //arma::mat exps = arma::exp(Z);
    //exps = Util::div(exps,arma::sum(exps, 1));

    return exps;
}

arma::mat sigmoid_backward( const arma::mat& gZ ) {
    return gZ % (1. - gZ);
}

arma::mat tanh_backward( const arma::mat& gZ ) {
    return (1. - arma::pow(gZ,2));
}

arma::mat relu_backward( arma::mat gZ ) {
    gZ.elem( arma::find(gZ > 0.0) ).ones();
    gZ.elem( arma::find(gZ <= 0.0) ).zeros();
    return gZ;
}

arma::mat leaky_relu_backward( arma::mat gZ ) {
    gZ.elem( arma::find(gZ > 0.0) ).fill(1.);
    gZ.elem( arma::find(gZ < 0.0) ).fill(0.01);
    return gZ;
}

arma::mat softmax_backward( const arma::mat& Y, const arma::mat& gZ ) {
    size_t m = Y.n_cols;
    //gZ[Y.argmax(axis=0),range(m)] -= 1
    arma::mat maxS = arma::conv_to<arma::mat>::from(arma::index_max(Y,0));
    arma::mat dZ = gZ;
    for(size_t i = 0; i < m; ++i){
        //gZ[maxS(0,i), i] -= 1;
        dZ(maxS(0,i),i) -= 1;
    }
    dZ = dZ/(double)m;
    return dZ;
}

} // namespace Activation
