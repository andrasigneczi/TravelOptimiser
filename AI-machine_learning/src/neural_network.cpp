#include "neural_network.h"
#include <vector>
#include <limits.h>
#include "fmincg.h"
#include <QCryptographicHash>
#include <set>
#include <string>
#include "Util.h"

NeuralNetwork::NeuralNetwork( const arma::mat& layerSizes, const arma::mat& X, const arma::mat& y, double lambda, YMappperIF& yMappper, bool featureScaling )
    : CostAndGradient(X, y, lambda)
    , mLayerSizes(layerSizes)
    , mYMappper(yMappper)
{
    if(featureScaling) {
        mX = this->featureScaling(X, true);
    }
}

CostAndGradient::RetVal& NeuralNetwork::calc( const arma::mat& nn_params, bool costOnly ) {
    
    // Reshape nn_params back into the parameters Theta1-ThetaN, the weight matrices
    // for our n layer neural network

    int num_labels        = mLayerSizes(0,mLayerSizes.n_cols-1); // 10
    double m = mX.n_rows;

    //std::cout << "dbgX 1 " << nn_params.n_rows << "\n";
    std::vector<arma::mat> thetas = extractThetas(nn_params);
    //std::cout << "dbgX 2\n";
    // ------------------------------
    // Back propagation algorithm
    // ------------------------------
    // 1. Compute the activation unit vector
    std::vector<arma::mat> aVec;
    
    for( size_t i = 0; i < thetas.size(); ++i ) {
        if( i == 0 ) {
            // a1 = x; (add ones to the first column)
            aVec.push_back( join_rows( arma::ones(m, 1), mX ));
        }
        // a2 = g(a1 * theta1')
        arma::mat a = sigmoid(aVec[i],thetas[i].t());
        if( i == thetas.size() - 1 ) {
            // we have finished
            aVec.push_back( a );
        } else {
            // add ones to the first column, if there are more hidden layer
            aVec.push_back( join_rows( arma::ones(a.n_rows, 1), a ));
        }
    }
    
    //std::cout << "dbgX 3 " << m << "\n" << std::flush;

    // the last 'a' is the 'h'
    arma::mat& h = aVec[aVec.size()-1]; // 5000 x 10

    //std::cout << "dbgX 3.1 " << m << "\n" << std::flush;

    // extract the 'y' to 'binary' format
    arma::mat yy = arma::zeros(m,num_labels); // 5000 x 10

    //std::cout << "dbgX 3.2 " << m << "\n" << std::flush;

    for( int i=0; i < m; ++i ) {
        //std::cout << "before mapper " << i << "\n" << std::flush;
        yy(i, mYMappper.fromYtoYY( mY(i,0))) = 1;
    }
    
    //std::cout << "dbgX 4\n";
    
    // cost calculation
    mRetVal.cost = 0;
    for( int k=0; k < num_labels; ++k ) {
        mRetVal.cost += as_scalar( 1./m*(-yy.col(k).t()*arma::log(h.col(k))-(1.-yy.col(k)).t()*arma::log(1.-h.col(k))));
    }

    // reguralization of the cost
    for( size_t i = 0; i < thetas.size(); ++i ) {
        mRetVal.cost += mLambda/2./m*sum(vectorise(arma::pow(thetas[i].cols(1,thetas[i].n_cols-1),2)));
    }
    
    if( costOnly ) {
        return mRetVal;
    }

    //std::cout << "dbgX 5\n";
    
    // compute deltas
    std::vector<arma::mat> deltas;
    // delta(L) = a(L) -y, where L=aVec.size()-1
    //arma::mat d3 =  aVec[aVec.size()-1] - yy;
    deltas.push_back( aVec[aVec.size()-1] - yy );
    for( size_t l = aVec.size()-2; l >= 1; --l ) {
        //     T2:10x26  d3:5000x10 a2:5000x26
        //arma::mat d2 = (d3*thetas[1])% aVec[aVec.size()-2]%(1- aVec[aVec.size()-2]);
        //arma::mat d2 = (d3*Theta2)%a2%(1-a2);
        //std::cout << "l: " << l << "\n" << size(deltas[deltas.size()-1]) << size( thetas[l] ) << size( aVec[l] ) << "\n";
        deltas.push_back( (deltas[deltas.size()-1]*thetas[l])% aVec[l]%(1- aVec[l]) );
    
        // d2: 5000x26 a1: 5000x401 d3: 5000x10
        // d2=d2.cols(1,d2.n_cols-1);
        arma::mat& d = deltas[deltas.size()-1];
        d=d.cols(1,d.n_cols-1);
    }

    //std::cout << "dbgX 6\n";
    

    // New Theta calculation
    std::vector<arma::mat> newThetas;
    for( int i = (int)deltas.size() - 1; i >=0; --i ) {
        newThetas.push_back( (deltas[i].t()*aVec[aVec.size() - i - 2] )/m );
    }
    //arma::mat Theta1_grad = d2.t()*a1/m; // 25x401
    //arma::mat Theta2_grad = d3.t()*a2/m; // 10x26
    
    //std::cout << "dbgX 7\n";
    // Theta reguralization
    mRetVal.grad.clear();
    for( size_t i = 0; i < newThetas.size(); ++i ) {
        for( size_t j = 1; j < newThetas[i].n_cols; ++j ) {
            newThetas[i].col(j) = newThetas[i].col(j) + mLambda/m*thetas[i].col(j);
        }
        if( i == 0 ) {
            mRetVal.grad = arma::vectorise(newThetas[i]);
        } else {
            mRetVal.grad = arma::join_cols( mRetVal.grad, arma::vectorise(newThetas[i]));
        }
    }
    //std::cout << "dbgX 8\n";
    
    return mRetVal;
}

// special return value std::numeric_limits<double>::max(); means not found
arma::mat NeuralNetwork::predict( const arma::mat& X, const std::vector<arma::mat>& thetas ) {
    size_t m = X.n_rows;
    arma::mat p = arma::zeros(m, 1);
    arma::mat s = X;

    if( mFCData.n_rows > 0 ) {
        for( size_t i = 0; i < s.n_cols; ++i ) {
            if( mFCData(i,0) != 0)
                s.col(i) = (s.col(i) - mFCData(i,1))/(mFCData(i,0));
        }
    }

    for( size_t i = 0; i < thetas.size(); ++i ) {
        s = std::move(join_rows( arma::ones(m, 1), s));
        s=std::move(sigmoid(s,thetas[i].t()));
    }
    arma::mat M = arma::max(s,1);
    for( size_t i=0; i < m; ++i ) {
        //p(i,0) = as_scalar(arma::find( s.row(i)==M(i,0) )) + 1; // +1 because y is 1 based.
        arma::uvec result = arma::find( s.row(i)==M(i,0) );
        //if( result.n_cols == 0 || result.n_rows == 0 )
        //    p(i,0) = NOT_FOUND;
        //else
            p(i,0) = mYMappper.fromYYtoY( result(0,0));
    }
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
    int input_layer_size = mLayerSizes(0,0);
    //int hidden_layer_size = 5;
    int num_labels = mLayerSizes(0,mLayerSizes.n_cols-1);
    double m = 5;

    // We generate some 'random' test data
    //arma::mat Theta1 = debugInitializeWeights(hidden_layer_size, input_layer_size);
    //arma::mat Theta2 = debugInitializeWeights(num_labels, hidden_layer_size);
    
    arma::mat nn_params;
    for( size_t i = 0; i <= mLayerSizes.n_cols-2; ++i ) {
        arma::mat Theta = debugInitializeWeights(mLayerSizes(0,i+1), mLayerSizes(0,i));
        if( i == 0 ) {
            // Unroll parameters
            nn_params = vectorise(Theta);
        } else {
            nn_params = arma::join_cols(nn_params, arma::vectorise(Theta));
        }
    }
    // Reusing debugInitializeWeights to generate X
    arma::mat X  = debugInitializeWeights(m, input_layer_size - 1);
    arma::mat y  = 1 + mod(arma::mat(1,m), num_labels).t();

    // Short hand for cost function
    //costFunc = @(p) nnCostFunction(p, input_layer_size, hidden_layer_size, ...
    //                               num_labels, X, y, lambda);
    
    //[cost, grad] = costFunc(nn_params);
    class DummyMapper : public YMappperIF {
    public:
        double fromYtoYY(double y) override {
            return y;
        }
        
        double fromYYtoY( size_t index ) override {
            return index;
        }
    };
    DummyMapper dm;
    NeuralNetwork nn(mLayerSizes, X, y, lambda, dm);
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

std::vector<arma::mat> NeuralNetwork::extractThetas( const arma::mat& nn_params ) {
    int hiddenLayerCount = mLayerSizes.n_cols - 2;
    std::vector<arma::mat> thetas(mLayerSizes.n_cols-1);
    int num_labels        = mLayerSizes(0,mLayerSizes.n_cols-1); // 10

    size_t pos = 0;
    for( int i = 1; i <= hiddenLayerCount; ++i ) {
        int act_layer_size = mLayerSizes(0,i);
        int prev_layer_size  = mLayerSizes(0,i-1);
        thetas[i-1] = arma::reshape( nn_params.rows(pos, pos + act_layer_size * (prev_layer_size + 1)-1), 
                         act_layer_size, (prev_layer_size + 1));
        pos += act_layer_size * (prev_layer_size + 1);
    }
    
    int act_layer_size = mLayerSizes(0,hiddenLayerCount);
    thetas[hiddenLayerCount] = arma::reshape(nn_params.rows(pos, nn_params.n_rows-1), 
                     num_labels, (act_layer_size + 1));
    return thetas;
}

arma::mat NeuralNetwork::train(int iteration, bool verbose) {
    arma::mat initial_nn_params;
    srand (time(NULL));
    for( size_t i = 0; i <= mLayerSizes.n_cols-2; ++i ) {
        arma::mat initial_Theta = randInitializeWeights(mLayerSizes(0,i), mLayerSizes(0,i+1));

        if( i == 0 )
            initial_nn_params = arma::vectorise( initial_Theta );
        else
            initial_nn_params = join_cols( initial_nn_params, arma::vectorise( initial_Theta ));
    }

    fmincgRetVal frv = fmincg(*this, initial_nn_params, iteration, verbose);
    return frv.m_NNPparams;
}

arma::mat NeuralNetwork::learningCurve(arma::mat& Xval, arma::mat& yval) {
    arma::mat retv = arma::zeros(mX.n_rows, 3);
    NeuralNetwork nn2(mLayerSizes, Xval, yval, 0, mYMappper);

    for( size_t m = 0; m < mX.n_rows; ++m ) {
        std::cout << "Lerarning curve step number " << m << "\r" << std::flush;
        arma::mat X = mX.rows(0,m);
        arma::mat Y = mY.rows(0,m);
        NeuralNetwork nn(mLayerSizes, X, Y, mLambda, mYMappper);
        arma::mat thetas = nn.train(1,false);
        nn.setLambda(0);
        retv(m,0) = m;
        retv(m,1) = nn.calc( thetas, true ).cost;
        retv(m,2) = nn2.calc( thetas, true ).cost;
    }
    return retv;
}

arma::mat NeuralNetwork::validationCurve(arma::mat& Xval, arma::mat& yval, int iteration) {
    std::vector<double> lambda_vec{0, 0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 1, 3, 10};
    arma::mat retv = arma::zeros(lambda_vec.size(), 3);
    NeuralNetwork nn2(mLayerSizes, Xval, yval, 0, mYMappper, true);

    for( size_t i = 0; i < lambda_vec.size(); ++i ) {
        std::cout << "Validation curve step number " << i << "\r" << std::flush;
        setLambda(lambda_vec[i]);
        arma::mat thetas = train(iteration,false);

        setLambda(0);
        retv(i,0) = lambda_vec[i];
        retv(i,1) = calc( thetas, true ).cost;
        retv(i,2) = nn2.calc( thetas, true ).cost;
    }
    return retv;
}

void NeuralNetwork::plotLearningCurve(QCustomPlot* customPlot) {
    arma::mat X, y, thetaSizes, Xval, Yval;

    Util::prepareTrainingAndValidationSet(mX, mY, X, y, Xval, Yval);

    NeuralNetwork nn(mLayerSizes, X, y, 1, mYMappper);
    //std::cout << "dbg2.5\n" << std::flush;
    arma::mat lcv = nn.learningCurve(Xval, Yval);
    //std::cout << "dbg3\n" << std::flush;

    Util::plotMatrix(customPlot, lcv);
}

void NeuralNetwork::plotValidationCurve(QCustomPlot* customPlot, int iteration) {
    arma::mat X, y, thetaSizes, Xval, Yval;

    Util::prepareTrainingAndValidationSet(mX, mY, X, y, Xval, Yval);

    NeuralNetwork nn(mLayerSizes, X, y, 1, mYMappper);
    //std::cout << "dbg2.5\n" << std::flush;
    arma::mat lcv = nn.validationCurve(Xval, Yval, iteration);
    //std::cout << "dbg3\n" << std::flush;

    Util::plotMatrix(customPlot, lcv);
    std::cout << "\n" << lcv << "\n" << std::flush;
}


NeuralNetwork::TrainParams NeuralNetwork::searchTrainParams( int minLayerSize, int maxLayerSize, int stepSize ) {
    TrainParams retVal {0,0,1.0e+10};
    arma::mat X, y, thetaSizes = mLayerSizes, Xval, Yval;

    Util::prepareTrainingAndValidationSet(mX, mY, X, y, Xval, Yval);

    X.save("trainParams_X.bin");
    y.save("trainParams_y.bin");
    Xval.save("trainParams_Xval.bin");
    Yval.save("trainParams_Yval.bin");

    for( int layerSize = minLayerSize; layerSize <= maxLayerSize; layerSize += stepSize ) {
        std::cout << "\nLayer size: " << layerSize << "\n" << std::flush;
        thetaSizes(0,1) = layerSize;
        NeuralNetwork nn(thetaSizes, X, y, 1, mYMappper, true);
        //std::cout << "dbg2.5\n" << std::flush;
        arma::mat lcv = nn.validationCurve(Xval, Yval, 5);
        for( size_t i = 0; i < lcv.n_rows; ++i ) {
            if( lcv(i,2) < retVal.cost ) {
                retVal.lambda = lcv(i,0);
                retVal.cost = lcv(i,2);
                retVal.layerSize = layerSize;
            }
        }
    }
    return retVal;
}

NeuralNetwork::TrainParams NeuralNetwork::searchTrainParams2( int minLayerSize, int maxLayerSize, int stepSize ) {
    TrainParams retVal {0,0,1.0e+10};
    arma::mat X, y, thetaSizes = mLayerSizes, Xval, Yval;

    X.load("trainParams_X.bin");
    y.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    for( int layerSize = minLayerSize; layerSize <= maxLayerSize; layerSize += stepSize ) {
        std::cout << "Layer size: " << layerSize << "\n" << std::flush;
        thetaSizes(0,1) = layerSize;
        NeuralNetwork nn(thetaSizes, X, y, 1, mYMappper, true);
        //std::cout << "dbg2.5\n" << std::flush;
        arma::mat lcv = nn.validationCurve(Xval, Yval, 5);
        for( size_t i = 0; i < lcv.n_rows; ++i ) {
            if( lcv(i,2) < retVal.cost ) {
                retVal.lambda = lcv(i,0);
                retVal.cost = lcv(i,2);
                retVal.layerSize = layerSize;
            }
        }
    }
    return retVal;
}
