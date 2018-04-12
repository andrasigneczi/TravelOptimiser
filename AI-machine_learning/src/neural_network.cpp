#include "neural_network.h"

CostAndGradient::RetVal& NeuralNetwork::calc( const arma::mat& nn_params ) {
    //CostAndGradient::RetVal rv;
    
    int input_layer_size  = mLayerSizes(0,0); // 400
    int hidden_layer_size = mLayerSizes(0,1); // 25
    int num_labels        = mLayerSizes(0,2); // 10
    double m = mX.n_rows;
    
    arma::mat Theta1 = arma::reshape( nn_params.rows(0,hidden_layer_size * (input_layer_size + 1)-1), 
                     hidden_layer_size, (input_layer_size + 1));
    
    arma::mat Theta2 = arma::reshape(nn_params.rows((hidden_layer_size * (input_layer_size + 1)), nn_params.n_rows-1), 
                     num_labels, (hidden_layer_size + 1));
    
    arma::mat a1 = arma::ones(m, 1);
    a1.insert_cols( a1.n_cols, mX);
    arma::mat a2 = sigmoid(a1,Theta1.t());
    a2.insert_cols( 0, arma::ones(a2.n_rows, 1));
    arma::mat a3 = sigmoid(a2,Theta2.t());
    arma::mat& h = a3; // 5000 x 10
    
    arma::mat yy = arma::zeros(m,num_labels); // 5000 x 10
    
    for( int i=0; i < m; ++i ) {
        if( mY(i,0) == 0 ) {
            yy(i,9) = 1;
        } else {
            yy(i,mY(i,0)-1) = 1;
        }
    }
    
    double J = 0;
    for( int k=0; k < num_labels; ++k ) {
        J += as_scalar( 1/m*(-yy.col(k).t()*arma::log(h.col(k))-(1-yy.col(k)).t()*arma::log(1-h.col(k))));
    }

    J += mLambda/2/m*( sum(vectorise(arma::pow(Theta1.cols(1,Theta1.n_cols-1),2)))
        + sum(vectorise(arma::pow(Theta2.cols(1,Theta2.n_cols-1),2))));
    
    arma::mat d3 = a3 - yy;
    //     T2:10x26  d3:5000x10 a2:5000x26
    arma::mat d2 = (d3*Theta2)%a2%(1-a2);

    // d2: 5000x26 a1: 5000x401 d3: 5000x10
    d2=d2.cols(1,d2.n_cols-1);
    arma::mat Theta1_grad = d2.t()*a1/m; // 25x401
    arma::mat Theta2_grad = d3.t()*a2/m; // 10x26
    
    for( size_t j=1; j < Theta1_grad.n_cols; ++j ) {
        Theta1_grad.col(j) = Theta1_grad.col(j) + mLambda/m*Theta1.col(j);
    }
    
    for( size_t j=1; j < Theta2_grad.n_cols; ++j ) {
        Theta2_grad.col(j) = Theta2_grad.col(j) + mLambda/m*Theta2.col(j);
    }
    
    mRetVal.grad = arma::join_cols( arma::vectorise(Theta1_grad), arma::vectorise(Theta2_grad));
    mRetVal.cost = J;
    
    return mRetVal;
}

arma::mat NeuralNetwork::predict( const arma::mat& X, const arma::mat& theta1, const arma::mat& theta2 ) {
    size_t m = X.n_rows;
    arma::mat p = arma::zeros(m, 1);
    arma::mat XX = arma::ones(m, 1);
    XX.insert_cols(1,X);
    arma::mat s=sigmoid(XX,theta1.t());
    s.insert_cols(0,arma::ones(s.n_rows,1));
    arma::mat s2=sigmoid(s,theta2.t());
    arma::mat M = arma::max(s2,1);
    for( size_t i=0; i < m; ++i ) {
        p(i,0) = as_scalar(arma::find( s2.row(i)==M(i,0) )) + 1; // +1 because y is 1 based.
    }
    //std::cout << M.rows(1000,1200);
    return p;
}

arma::mat NeuralNetwork::sigmoid( const arma::mat& X, const arma::mat& theta ) {
    const arma::mat z = -X*theta;
    return 1.0/(1.0+arma::exp(z));
}

arma::mat NeuralNetwork::sigmoidGradient( const arma::mat& z ) {
    arma::mat s = 1.0/(1.0+arma::exp(z));
    return s % ( 1 - s );
}

arma::mat NeuralNetwork::randInitializeWeights( int L_in, int L_out ) {
    const double epsilon_init = 0.12;
    return arma::randu(L_out, 1 + L_in) * 2 * epsilon_init - epsilon_init;
}

arma::mat NeuralNetwork::debugInitializeWeights( int fan_out, int fan_in ) {
    arma::mat W = arma::zeros(fan_out, 1 + fan_in);
    
    // Initialize W using "sin", this ensures that W is always of the same
    // values and will be useful for debugging
    arma::mat A(1,numel(W));
    return arma::reshape(arma::sin( A ), W.n_rows, W.n_cols) / 10.;
}

arma::mat NeuralNetwork::computeNumericalGradient( const arma::mat& theta ) {
    arma::mat numgrad = arma::zeros(theta.n_rows,theta.n_cols);
    arma::mat perturb = arma::zeros(theta.n_rows,theta.n_cols);
    double e = 1e-4;
    for( size_t p = 0; p < theta.n_elem; ++p ) {
        // Set perturbation vector
        perturb(p) = e;
        calc(theta - perturb);
        double lossCost1 = mRetVal.cost;
        calc(theta + perturb);
        double lossCost2 = mRetVal.cost;
        // Compute Numerical Gradient
        numgrad(p) = (lossCost2 - lossCost1) / (2.*e);
        perturb(p) = 0;
    }
    return numgrad;
}

void NeuralNetwork::checkNNGradients( double lambda /*= 0*/ ) {
    int input_layer_size = 3;
    int hidden_layer_size = 5;
    int num_labels = 3;
    double m = 5;

    // We generate some 'random' test data
    arma::mat Theta1 = debugInitializeWeights(hidden_layer_size, input_layer_size);
    arma::mat Theta2 = debugInitializeWeights(num_labels, hidden_layer_size);
    // Reusing debugInitializeWeights to generate X
    arma::mat X  = debugInitializeWeights(m, input_layer_size - 1);
    arma::mat y  = 1 + mod(arma::mat(1,m), num_labels).t();

    // Unroll parameters
    arma::mat nn_params = arma::join_cols(vectorise(Theta1), vectorise(Theta2));
    
    // Short hand for cost function
    //costFunc = @(p) nnCostFunction(p, input_layer_size, hidden_layer_size, ...
    //                               num_labels, X, y, lambda);
    
    //[cost, grad] = costFunc(nn_params);
    arma::mat thetaSizes;
    thetaSizes << input_layer_size << hidden_layer_size << num_labels; // input, hidden, output
    NeuralNetwork nn(thetaSizes, X, y, lambda);
    RetVal& rv = nn.calc(nn_params);
    arma::mat rvGrad {std::move(rv.grad )};
    
    arma::mat numgrad = nn.computeNumericalGradient(nn_params);
    
    // Visually examine the two gradient computations.  The two columns
    // you get should be very similar. 
    std::cout << arma::join_rows( numgrad, rvGrad );

    std::cout << "The above two columns you get should be very similar.\n" <<
             "(Left-Your Numerical Gradient, Right-Analytical Gradient)\n\n";

    // Evaluate the norm of the difference between two solutions.  
    // If you have a correct implementation, and assuming you used EPSILON = 0.0001 
    // in computeNumericalGradient.m, then diff below should be less than 1e-9
    double diff = norm(numgrad-rvGrad)/norm(numgrad+rvGrad);
    
    std::cout << "If your backpropagation implementation is correct, then \n"
             "the relative difference will be small (less than 1e-9). \n"
             "\nRelative Difference: " << diff << std::endl;
}