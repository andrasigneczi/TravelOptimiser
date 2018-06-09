#include <armadillo>
#include "neural_network.h"
#include <neural_network.h>
#include <fmincg.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QtGui/QImage>
#include <png2arma.h>
#include "qcustomplot.h"
#include <logistic_regression.h>
#include <logistic_regression_v2.h>
#include <support_vector_machine.h>
#include "Util.h"

namespace COC_ns {
    
void test4();
void coc_prediction_test();
void coc_one_TH_test();
void coc_TH9_test();
void coc_background_training_set_generator();
void coc_learningCurve();
void coc_validationCurve();
void coc_th11_train_params_searching();
void coc_th11_train();
void logistic_regression();
void learning_validation_curve();
void logistic_regression_class();
void logistic_regression_one_vs_all();
void learning_validation_curve_OneVsAll();
void support_vector_machine_one_vs_all();
void logistic_regression_kinda_minibatch();
void logistic_regression_v2();
void logistic_regression_v2_continue();
void logistic_regression_v2_onevsall();
void logistic_regression_v2_onevsall_continue();

void runTests() {
    //test4(); // coc training test
    //coc_prediction_test();
    //coc_one_TH_test();
    //coc_TH9_test();
    //coc_learningCurve();
    //coc_validationCurve();
    //coc_th11_train_params_searching();
    //coc_th11_train();
    //logistic_regression();
    //learning_validation_curve();
    //logistic_regression_class();
    //logistic_regression_one_vs_all();
    //learning_validation_curve_OneVsAll();
    //support_vector_machine_one_vs_all();
    //logistic_regression_kinda_minibatch();
    //logistic_regression_v2();
    //logistic_regression_v2_continue();
    //logistic_regression_v2_onevsall();
    logistic_regression_v2_onevsall_continue();
}


class COCYMappper : public NeuralNetwork::YMappperIF {
public:
    double fromYtoYY(double y) override {
        return y;
    }
    
    double fromYYtoY( size_t index ) override {
        return index;
    }
};

double coc( const arma::mat& X, const arma::mat& y, const arma::mat& Xt, const arma::mat& yt, double layerSize, double lambda );
void test4() {
    arma::mat X, y, Xt, yt;
    
    std::cout << "Loading training set and test set\n";
    X.load("coc_trainingset.bin");
    y.load("coc_trainingset_result.bin");
    Xt.load("coc_testset.bin");
    yt.load("coc_testset_result.bin");

    // multiply the training set: totally useless!!!!
  /*  
    for( int i = 0; i < 3; ++i ) {
        X = join_cols( X, X );
        y = join_cols( y, y );
    }
    std::cout << "New size: " << size(X) << size(y);
*/
    std::cout << "Training...\n";
    coc( X, y, Xt, yt, 880, 1.0e-3 );
    if( 0 ) {
     double lastAccuracy = 0;
        int accuracyIndex = 0;
        for( int i = 20; i < 1000; i += 100 ) {
            std::cout << "layer size: " << i << "\n";
            double accuracy = coc( X, y, Xt, yt, (double)i, 3.0e-2 );  
            if( accuracy > lastAccuracy ) {
                lastAccuracy = accuracy;
                accuracyIndex = i;
            }
        }
        std::cout << "Best accuracy: " << lastAccuracy << "; layer size: " << accuracyIndex << "\n";
    }
    
    
}

double coc( const arma::mat& X, const arma::mat& y, const arma::mat& Xt, const arma::mat& yt, double layerSize, double lambda ) {
    
    // input, hidden1, ..., hddenN, output
    arma::mat thetaSizes{(double)X.n_cols, layerSize,11 };
    //double lambda = 1e-1;
    int iteration = 50;
    
    //thetaSizes << input_layer_size << hidden_layer_size1 << num_labels; // input, hidden, output
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);

    //std::cout << "dbg1\n";
    arma::mat initial_nn_params;
    srand (time(NULL));
    for( size_t i = 0; i <= thetaSizes.n_cols-2; ++i ) {
        // Randomly initialize the weights to small values
        arma::mat initial_Theta = nn.randInitializeWeights(thetaSizes(0,i), thetaSizes(0,i+1));
    
        // Unroll parameters
        //initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];
        if( i == 0 )
            initial_nn_params = arma::vectorise( initial_Theta );
        else
            initial_nn_params = join_cols( initial_nn_params, arma::vectorise( initial_Theta ));
    }
    //std::cout << "dbg2\n";
    
/*    
    std::cout << "\nChecking Backpropagation (w/ Regularization) ... \n";
    
    //  Check gradients by running checkNNGradients
    nn.setLambda(3);
    nn.checkNNGradients(3);
    std::cout << "Press enter to continue\n";
    std::cin.get();
    nn.setLambda( lambda );
*/    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //std::cout << "dbg3\n";

    fmincgRetVal frv = fmincg(nn, initial_nn_params, iteration);

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << std::endl;

    thetaSizes.save( "coc_trained_theta_sizes.bin" );
    frv.m_NNPparams.save( "coc_trained_thetas.bin" );

   // Obtain Theta1 and Theta2 back from nn_params
   std::vector<arma::mat> thetas = nn.extractThetas(frv.m_NNPparams);
 
   arma::mat pred = nn.predict(X,thetas);
   arma::mat pred2 = nn.predict(Xt,thetas);
 
   double accuracy = arma::mean(arma::conv_to<arma::colvec>::from(pred == y))*100;
   double accuracy2 = arma::mean(arma::conv_to<arma::colvec>::from(pred2 == yt))*100;
   //std::cout << "Training y:\n";
   //std::cout << join_rows(y, pred) << std::endl;
   /*
   for( size_t i = 0; i < y.n_rows; ++i )
       if( y(i,0) != pred(i,0))
           std::cout << y(i,0) << " " << pred(i,0) << std::endl;
   */
   //std::cout << "Test y:\n";
   //std::cout << join_rows(yt, pred2) << std::endl;
   /*
   for( size_t i = 0; i < yt.n_rows; ++i )
        if( yt(i,0) != pred2(i,0))
            std::cout << i + 1 << ". " << yt(i,0) << " " << pred2(i,0) << std::endl;
    */
    std::cout << "Training Set Accuracy: " << accuracy << "%\n";
    std::cout << "Test Set Accuracy: " << accuracy2 << "%\n";
    std::cout << "thetaSizes: " << thetaSizes << "\nlambda: " << lambda << "\n";
 
 
    NeuralNetwork nn2(thetaSizes, Xt, yt, lambda, yMapper);
    CostAndGradient::RetVal& rv = nn.calc(frv.m_NNPparams);
 
    std::cout << "Cost with training data: " << frv.mCost << "\niteration: " << frv.mI <<"\n";
    std::cout << "\nCost with test data: " << rv.cost <<"\n";
    std::cout << std::string(80,'-') << "\n";
 
    return accuracy;
}

void coc_prediction_test() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y, Xt,yt;
    double lambda = 0;
    
    //thetaSizes.load( "./theta_99.88/coc_trained_theta_sizes.bin" );
    //theta.load( "./theta_99.88/coc_trained_thetas.bin" );
    thetaSizes.load( "coc_trained_theta_sizes.bin" );
    theta.load( "coc_trained_thetas.bin" );
    Xt.load("coc_testset.bin");
    yt.load("coc_testset_result.bin");
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};
    arma::mat pred2 = nn.predict(Xt,thetas);
    double accuracy2 = arma::mean(arma::conv_to<arma::colvec>::from(pred2 == yt))*100;
    std::cout << "Test Set Accuracy: " << accuracy2 << "%\n";

    QImage testmap;
    char images[][300] = { "../COC/processed/BlueStacks_ScreenShot1.jpg",
			    "../COC/processed/BlueStacks_ScreenShot2.jpg",
			    "../COC/processed/BlueStacks_ScreenShot3.jpg",
			    "../COC/processed/BlueStacks_ScreenShot4.jpg",
			    "../COC/processed/BlueStacks_ScreenShot5.jpg",
			    "../COC/processed/BlueStacks_ScreenShot6.jpg",
			    "../COC/processed/BlueStacks_ScreenShot7.jpg",
			    "../COC/processed/BlueStacks_ScreenShot8.jpg",
			    "../COC/processed/BlueStacks_ScreenShot9.jpg",
			    "../COC/processed/BlueStacks_ScreenShot10.jpg",
			    "../COC/processed/BlueStacks_ScreenShot11.jpg",
			    "../COC/processed/BlueStacks_ScreenShot12.jpg",
			    "../COC/processed/BlueStacks_ScreenShot13.jpg",
			    "../COC/processed/BlueStacks_ScreenShot14.jpg",
			    "../COC/processed/BlueStacks_ScreenShot15.jpg"};
    for( int imgI = 0; imgI < 15; ++imgI ) {
        if( testmap.load( images[imgI])) {
            std::cout << images[imgI] << " size: " << testmap.width() << " x " << testmap.height() << "\n";
        }

        const double width = 24;
        int mul = 1; // 3 if rgb
        const double bigImageScale = 100.;
        testmap = testmap.scaledToWidth(testmap.width()*width/bigImageScale);
        std::cout << "new size: " << testmap.width() << " x " << testmap.height() << "\n";
        arma::mat retVal = arma::zeros( 1, width*width*mul );
        for( size_t yp = 0; yp  + width < testmap.height(); yp += 1) {
            //std::cout << "yp: " << yp << "\n";
            for( size_t xp = 0; xp  + width < testmap.width(); xp += 1) {
                for( size_t i = 0; i < width; ++i ) {
                    for( size_t j = 0; j < width; ++j ) {
                        QRgb rgb = testmap.pixel( xp+j, yp+i );
                        if( mul == 1 ) {
                                retVal(0, i * width + j ) = 0.2126*qRed(rgb)+0.7152*qRed(rgb)+0.0722*qBlue(rgb);
                        } else  {
                            retVal(0, (i * width + j)*mul ) = qRed(rgb);
                            retVal(0, (i * width + j)*mul + 1) = qGreen(rgb);
                            retVal(0, (i * width + j)*mul + 2) = qBlue(rgb);
                        }
                    }
                }
                arma::mat pred = nn.predict(retVal,thetas);
            //std::cout << pred;
            if( pred(0,0) != 1.0 )
                std::cout << "position: " << xp*bigImageScale/width << ";" << yp*bigImageScale/width << " TH" << pred(0,0) << "\n";
            }
        }
    }
}

void coc_one_TH_test() {
    arma::mat thetaSizes;
    arma::mat theta;
    arma::mat X, y;
    double lambda = 0;

    //thetaSizes.load( "./theta_99.88/coc_trained_theta_sizes.bin" );
    //theta.load( "./theta_99.88/coc_trained_thetas.bin" );
    thetaSizes.load( "coc_trained_theta_sizes.bin" );
    theta.load( "coc_trained_thetas.bin" );
    COCYMappper yMapper;
    NeuralNetwork nn(thetaSizes, X, y, lambda, yMapper);
    std::vector<arma::mat> thetas {nn.extractThetas(theta)};

    QImage testmap;
    const char* filename = "../COC/processed/BlueStacks_ScreenShot3.jpg";
    if( testmap.load( filename )) {
        std::cout << filename << " size: " << testmap.width() << " x " << testmap.height() << "\n";
    }

    testmap = testmap.copy(676,320,70,70);
    const double width = 24;
    //const double bigImageScale = 100.;
    //testmap = testmap.scaledToWidth(testmap.width()*width/bigImageScale);
    testmap = testmap.scaledToWidth(24);
    testmap.save("ez_az_a_hely.png");

    int xp = 0;
    int yp = 0;
    arma::mat retVal = arma::zeros( 1, width*width );
    for( size_t i = 0; i < width; ++i ) {
        for( size_t j = 0; j < width; ++j ) {
            QRgb rgb = testmap.pixel( xp+j, yp+i );
            retVal(0, i * width + j ) = 0.2126*qRed(rgb)+0.7152*qRed(rgb)+0.0722*qBlue(rgb);
        }
    }
    arma::mat pred = nn.predict(retVal,thetas);

    /*
    Png2Arma pa;
    pa.read_png_file( "ez_az_a_hely.png" );
    arma::mat ts = pa.process_file(24,24,true);
    arma::mat pred = nn.predict(ts,thetas);
    */

    std::cout << pred;

}

void coc_TH9_test() {
    QImage testmap;
    const char* filename = "../COC/processed/BlueStacks_ScreenShot4.jpg";
    if( testmap.load( filename )) {
        std::cout << filename << " size: " << testmap.width() << " x " << testmap.height() << "\n";
    }

    QImage pattern;
    pattern.load("th9_pattern.png");

    for( int x = 0; x + pattern.width() < testmap.width(); ++x ) {
        for( int y = 0; y + pattern.height() < testmap.height(); ++y ) {
            int matches = 0;
            for( int i = 0; i < pattern.width(); ++i ) {
                for( int j = 0; j < pattern.height(); ++j ) {
                    QRgb rgb1 = pattern.pixel(i,j);
                    QRgb rgb2 = testmap.pixel(x+i,y+j);

                    //if( pattern.pixel(i,j) != testmap.pixel(x+i,y+j)) {
                    if(( abs(qRed(rgb1) - qRed(rgb2)) < 10 ) &&
                        ( abs(qGreen(rgb1) - qGreen(rgb2)) < 10 ) &&
                        ( abs(qBlue(rgb1) - qBlue(rgb2)) < 10 ))
                    {
                        ++matches;
                    }
                }
            }
            if( pattern.width()*pattern.height()*.7 <= (double)matches ) {
                QImage cp = testmap.copy( x - 30, y- 15, 75, 90 );
                cp.save("th9_copied.png");
                std::cout << "TH9 saved\n";
                break;
            }
        }
    }
}

void coc_background_training_set_generator() {
}

class COCYMappper2 : public NeuralNetwork::YMappperIF {
public:
    double fromYtoYY(double y ) override {
        return y;
    }

    double fromYYtoY( size_t index ) override {
        return index;
    }
};

void coc_learningCurve() {
    arma::mat X, y, thetaSizes;
    X.load("TH11_plus_BG_trainingset.bin");
    y.load("TH11_plus_BG_trainingset_result.bin");

    thetaSizes << 40*40 << 3800 << 2; // input, hidden, output
    COCYMappper2 yMapper;
    NeuralNetwork nn(thetaSizes, X, y, 1, yMapper);
    nn.plotLearningCurve(new QCustomPlot);
}

void coc_validationCurve() {
    arma::mat X, y, thetaSizes;
    X.load("/src/TravelOptimizer/AI-machine_learning/SimpleNNTrainer/training_sets/TH11_plus_BG_trainingset.bin");
    y.load("/src/TravelOptimizer/AI-machine_learning/SimpleNNTrainer/training_sets/TH11_plus_BG_trainingset_result.bin");

    thetaSizes << 40*40 << 4000 << 1000 << 200 << 2; // input, hidden, output
    COCYMappper2 yMapper;
    NeuralNetwork nn(thetaSizes, X, y, 1, yMapper);
    nn.plotValidationCurve(new QCustomPlot,10);
}

//2986
//0.3
//-nan
void coc_th11_train_params_searching() {
    arma::mat X, y, thetaSizes;
    X.load("TH11_plus_BG_trainingset.bin");
    y.load("TH11_plus_BG_trainingset_result.bin");

    thetaSizes << 24*24 << 0 << 2; // input, hidden, output
    COCYMappper2 yMapper;
    NeuralNetwork* nn = new NeuralNetwork(thetaSizes, X, y, 1, yMapper);
    NeuralNetwork::TrainParams tp = nn->searchTrainParams(500,5000,200);
    std::cout << "Cost: " << tp.cost << "\nLayer size: " << tp.layerSize << "\nLambda: " << tp.lambda << "\n";
    tp = nn->searchTrainParams2(tp.layerSize-150,tp.layerSize+150,50);
    std::cout << "Cost: " << tp.cost << "\nLayer size: " << tp.layerSize << "\nLambda: " << tp.lambda << "\n";
    tp = nn->searchTrainParams2(tp.layerSize-40,tp.layerSize+40,10);
    std::cout << "Cost: " << tp.cost << "\nLayer size: " << tp.layerSize << "\nLambda: " << tp.lambda << "\n";
    tp = nn->searchTrainParams2(tp.layerSize-5,tp.layerSize+5,1);
    std::cout << "Cost: " << tp.cost << "\nLayer size: " << tp.layerSize << "\nLambda: " << tp.lambda << "\n";

    delete nn;
    thetaSizes.clear();
    X.clear();
    y.clear();
    thetaSizes << 24*24 << tp.layerSize << 2; // input, hidden, output
    thetaSizes.save("TH11_plus_BG_thetasizes.bin");

    std::cout << "Loading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    nn = new NeuralNetwork(thetaSizes, Xtraining, Ytraining, tp.lambda, yMapper, true);
    arma::mat trainedThetas = nn->train(300);

    thetaSizes.save( "coc_trained_theta_sizes.bin" );
    trainedThetas.save( "coc_trained_thetas.bin" );

    std::vector<arma::mat> thetas = nn->extractThetas(trainedThetas);

    std::cout << "\nPrediction test...\n";

    arma::mat pred1 = nn->predict(Xtraining,thetas);
    arma::mat pred2 = nn->predict(Xval,thetas);

    double accuracy1 = arma::mean(arma::conv_to<arma::colvec>::from(pred1 == Ytraining))*100;
    double accuracy2 = arma::mean(arma::conv_to<arma::colvec>::from(pred2 == Yval))*100;

    std::cout << "Training Set Accuracy: " << accuracy1 << "%\n";
    std::cout << "Validation Set Accuracy: " << accuracy2 << "%\n";
    std::cout << "thetaSizes: " << thetaSizes << "\n";
    delete nn;
}

void coc_th11_train() {
    std::cout << "Loading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval,thetaSizes;
    thetaSizes.load("TH11_plus_BG_thetasizes.bin");
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    COCYMappper2 yMapper;
    NeuralNetwork* nn = new NeuralNetwork(thetaSizes, Xtraining, Ytraining, 0.1, yMapper, true);
    arma::mat trainedThetas = nn->train(20);

    thetaSizes.save( "coc_trained_theta_sizes.bin" );
    trainedThetas.save( "coc_trained_thetas.bin" );

    std::vector<arma::mat> thetas = nn->extractThetas(trainedThetas);

    std::cout << "\nPrediction test...\n";

    arma::mat pred = nn->predict(Xval,thetas);

    double accuracy = arma::mean(arma::conv_to<arma::colvec>::from(pred == Yval))*100;

    std::cout << "Validation Set Accuracy: " << accuracy << "%\n";
    std::cout << "thetaSizes: " << thetaSizes << "\n";
    delete nn;
}

// *******************************************************************************************************-
// *******************************************************************************************************-
// ********************************** LOGISTIC REGRESSION ************************************************-
// *******************************************************************************************************-
// *******************************************************************************************************-
void logistic_regression() {
    std::cout << "Loading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    double n = Xtraining.n_cols;
    double m = Ytraining.n_rows;

    // let's insert a column filled with ones
    Xtraining.insert_cols(0, arma::ones<arma::mat>(m,1));
    Xval.insert_cols(0, arma::ones<arma::mat>(Yval.n_rows,1));

    // Initialize fitting parameters
    arma::mat initial_theta = arma::zeros(n + 1, 1);

    LogisticRegression lr;
    Xtraining = lr.featureScaling(Xtraining,true);
    //lr.featurScaling(Xval);
    double alpha = 0.3;
    double lambda = 1.0e-11;
    long long iteration = 1e+5;
    std::cout << "Calculating gradient descent...\n";
    arma::mat theta = lr.gradientDescentWithReguralization( Xtraining, Ytraining, initial_theta, alpha, lambda, iteration );
    arma::mat p = lr.predict(Xtraining,theta);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    p = lr.predict(Xval,theta);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
}

void learning_validation_curve() {
    std::cout << "Loading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    std::cout << "Training set size: " << Xtraining.n_rows << "\n";
    //std::cout << "Feature scaling...\n";
    //Xtraining = lr.featureScaling(Xtraining);
    //Xval = lr.featureScaling(Xval);

    double lambda = 1.0e-0;
    long long iteration = 1;

    std::cout << "Learning curve...\n";
    LogisticRegression lr(Xtraining, Ytraining,lambda, true,0);
    arma::mat lcv = lr.learningCurve(Xval, Yval, lambda, iteration,10);
    Util::plotMatrix(new QCustomPlot, lcv);
    std::cout << "\n" << lcv << "\n" << std::flush;
    std::cout << "Validation curve...\n";
    arma::mat lcv2 = lr.validationCurve(Xval, Yval, iteration);
    Util::plotMatrix(new QCustomPlot, lcv2);
    std::cout << "\n" << lcv2 << "\n" << std::flush;
}

/*
 * y 0: bg; 1: TH11
lambda = 1.e-2;
iteration = 8e+2;
degree: 5
Iteration 800 | Cost: 0.00134053
Training Set Accuracy: 100
Validation Set Accuracy: 99.3437
-----------------------------------
lambda = 1.e-1;
degree: 5
Iteration 667 | Cost: 0.00521039
Training Set Accuracy: 99.9602
Validation Set Accuracy: 99.3901
----------------------------------
lambda = 1.e-1;
degree: 4
Iteration 800 | Cost: 0.00523354
Training Set Accuracy: 99.9602
Validation Set Accuracy: 99.3901
---------------------------------
lambda = 1.e-2;
degree: 3
X size after feature mapping: 40169x1800
Iteration 800 | Cost: 0.00140252
Training Set Accuracy: 100
Validation Set Accuracy: 99.3379
---------------------------------
lambda = 5.e-2;
degree: 3
Iteration 800 | Cost: 0.00370337
Training Set Accuracy: 100
Validation Set Accuracy: 99.3495
---------------------------------
lambda = 1.e-1;
degree: 3
Iteration 692 | Cost: 0.00536877
Training Set Accuracy: 99.9577
Validation Set Accuracy: 99.3553
---------------------------------
lambda = 3.e-1;
degree: 3
X size after feature mapping: 40169x1800
Iteration 548 | Cost: 0.00897353
Training Set Accuracy: 99.9228
Validation Set Accuracy: 99.3669
---------------------------------
lambda = 2.e-1;
degree: 2
X size after feature mapping: 40169x1000
Iteration 641 | Cost: 0.00829155
Training Set Accuracy: 99.9228
Validation Set Accuracy: 99.3379


y 0: bg; 1: TH8
---------------------------------
lambda = 2.e-1;
degree: 4
Iteration 800 | Cost: 0.0390943
Training Set Accuracy: 99.3628
Validation Set Accuracy: 96.7212
---------------------------------
lambda = 1.e-2;
degree: 3
X size after feature mapping: 42056x1800
Iteration 800 | Cost: 0.0172917
Threshold: 0.82
Training Set Accuracy: 99.3247
Validation Set Accuracy: 97.3537
*/
void logistic_regression_class(double lambda,int degree,const char* prefix,std::set<double> ignore_list,double test_th);
void logistic_regression_class() {

    double lambda = 1.e-2;
    int degree = 3;
    std::set<double> ignore_list{2,3,4,5};
    double test_th = 1;
    const char* prefix = "th11";
    logistic_regression_class(lambda,degree,prefix,ignore_list,test_th);

    std::cout << "\n====================================\n\n";

    lambda = 1.e-2;
    degree = 3;
    ignore_list = {1,3,4,5};
    test_th = 2;
    prefix = "th8";
    logistic_regression_class(lambda,degree,prefix,ignore_list,test_th);

    std::cout << "\n====================================\n\n";
/*
    lambda = 1.e-2;
    degree = 3;
    ignore_list = {1,2,4,5};
    test_th = 3;
    prefix = "th9";
    logistic_regression_class(lambda,degree,prefix,ignore_list,test_th);

    lambda = 1.e-2;
    degree = 3;
    ignore_list = {1,2,3,5};
    test_th = 4;
    prefix = "th7";
    logistic_regression_class(lambda,degree,prefix,ignore_list,test_th);
    */

    lambda = 1.e-2;
    degree = 3;
    ignore_list = {1,2,3,4};
    test_th = 5;
    prefix = "th10";
    logistic_regression_class(lambda,degree,prefix,ignore_list,test_th);
}

void logistic_regression_class(double lambda,int degree,const char* prefix,std::set<double> ignore_list,double test_th) {

    long long iteration = 8e+2;
    std::cout << "logistic_regression_class " << prefix << "\nLoading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH_plus_BG_trainingset.bin");
        y.load("TH_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        //y = arma::conv_to<arma::mat>::from(arma::all( (y != 0), 1 ));
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval, ignore_list);

        Ytraining = arma::conv_to<arma::mat>::from(arma::all( (Ytraining == test_th), 1 ));
        Yval = arma::conv_to<arma::mat>::from(arma::all( (Yval == test_th), 1 ));

        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    }

    LogisticRegression lr(Xtraining, Ytraining, lambda, true, degree );
    arma::mat theta = lr.train(iteration,true);
    //lr.miniBatchGradientDescent(0.00001,600);
    //lr.stochasticGradientDescent(0.00001,600);
    lr.saveThetaAndFeatureScaling(prefix);
    double threshold = 0.5; //lr.searchThreshold(Xval, Yval);
    std::cout << "Threshold: " << threshold << std::endl;
    arma::mat p = lr.predict(Xtraining,threshold);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    p = lr.predict(Xval,threshold);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
}

void logistic_regression_one_vs_all() {
    arma::mat Xtraining, Ytraining, Xval, Yval;

    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH_plus_BG_trainingset.bin");
        y.load("TH_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);
        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    } else if(scenario==3){
        Xtraining.load("TH11_plus_BG_trainingset.bin");
        Ytraining.load("TH11_plus_BG_trainingset_result.bin");
    }

    std::cout << size(Xtraining) << "\n" << size(Ytraining) << "\n";

    double lambda = 1e-2;
    LogisticRegression lr(Xtraining, Ytraining, lambda, true, 3 );

    std::cout << "contructor finished...\n";

    lr.trainOneVsAll(400,true);
    //lr.trainOneVsAll(4,800,true);
    lr.saveThetaAndFeatureScaling("th_onevsall2");

    arma::mat p = lr.predictOneVsAll(Xtraining,false);
    //p = p + arma::ones(p.n_rows,1);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    if(scenario!=3) {
        p = lr.predictOneVsAll(Xval,false);
        //p = p + arma::ones(p.n_rows,1);
        std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
    }
}

void learning_validation_curve_OneVsAll() {
    std::cout << "Loading data...\n" << std::flush;

    arma::mat X, y, Xtraining, Ytraining, Xval, Yval;

    int scenario = 1;
    if(scenario==1){
        X.load("TH11_plus_BG_trainingset.bin");
        y.load("TH11_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);
        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    } else if(scenario==3){
        Xtraining.load("TH11_plus_BG_trainingset.bin");
        Ytraining.load("TH11_plus_BG_trainingset_result.bin");
    }

    std::cout << "Training set size: " << Xtraining.n_rows << "\n";
    //std::cout << "Feature scaling...\n";
    //Xtraining = lr.featureScaling(Xtraining);
    //Xval = lr.featureScaling(Xval);

    double lambda = 1.0e-0;
    long long iteration = 10;
    double test_y = 2;

    std::cout << "Learning curve...\n";
    LogisticRegression lr(Xtraining, Ytraining,lambda, true,3);
    arma::mat lcv = lr.learningCurveOne(test_y, Xval, Yval, lambda, iteration,500);
    Util::plotMatrix(new QCustomPlot, lcv);
    std::cout << "\n" << lcv << "\n" << std::flush;
    std::cout << "Validation curve...\n";
    arma::mat lcv2 = lr.validationCurveOne(test_y, Xval, Yval, iteration);
    Util::plotMatrix(new QCustomPlot, lcv2);
    std::cout << "\n" << lcv2 << "\n" << std::flush;
}

void support_vector_machine_one_vs_all() {
    arma::mat Xtraining, Ytraining, Xval, Yval;

    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH11_plus_BG_trainingset.bin");
        y.load("TH11_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval, std::set<double>(), 2000);
        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    } else if(scenario==3){
        Xtraining.load("coc_trainingset.bin");
        Ytraining.load("coc_trainingset_result.bin");
        Xval.load("coc_testset.bin");
        Yval.load("coc_testset_result.bin");
    }
    
    std::cout << "svm starting...\n";
    support_vector_machine svm(Xtraining, Ytraining, true, 0 );
    struct svm_parameter& spa = svm.getParameter();
    spa.C = 100;
    //spa.svm_type = NU_SVC;
    spa.gamma = 0.0001;
    spa.eps = 1;
    spa.shrinking = 0;
    
    std::cout << "contructor finished...\n";
    std::cout << "training starting...\n";

    auto* model = svm.train();
    svm_save_model("coc_svm_model.bin",model);
    svm.saveFeatureScaling("coc_");
    
    std::cout << "training finished...\n";
    std::cout << "prediction starting...\n";

    arma::mat p = svm.predict(Xtraining,model);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    //if(scenario!=3) {
        p = svm.predict(Xval,model);
        std::cout << "\nValidation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
    //}
}

void logistic_regression_kinda_minibatch() {
    const long long iteration = 8e+3;
    const double alpha = 1e-2;
    const double lambda = 1e-3;
    const int degree = 4;
    const char* prefix = "th11_batch";
    const size_t orig_batch_size = 5000;

    std::cout << "logistic_regression_kinda_minibatch\nLoading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH_plus_BG_trainingset.bin");
        y.load("TH_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        y = arma::conv_to<arma::mat>::from(arma::all( (y == 1), 1 ));
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);

        //Ytraining = arma::conv_to<arma::mat>::from(arma::all( (Ytraining == test_th), 1 ));
        //Yval = arma::conv_to<arma::mat>::from(arma::all( (Yval == test_th), 1 ));

        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    }

    {
        LogisticRegression lr;
        lr.featureScaling(Xtraining, true);
        lr.saveThetaAndFeatureScaling(prefix);
    }

    size_t batch_size = orig_batch_size;
    if( batch_size > Xtraining.n_rows ) {
        batch_size = Xtraining.n_rows;
    }

    arma::mat theta;
    for( size_t i = 0; i < Xtraining.n_rows; ) {
        std::cout << "Train range: " << i << "-" << i + batch_size - 1 << "\n";
        arma::mat XT = Xtraining.rows(i,i+batch_size-1);
        arma::mat YT = Ytraining.rows(i,i+batch_size-1);

        LogisticRegression l;
        l.loadThetaAndFeatureScaling(prefix);
        XT = l.applyFeatureScalingValues(XT);

        LogisticRegression lr(XT, YT, lambda, false, degree );
        lr.loadThetaAndFeatureScaling(prefix);

        if( i == 0 ){
            theta = lr.gradientDescentWithReguralization(alpha, iteration);
        } else {
            theta = lr.gradientDescentWithReguralization(theta, alpha, lambda, iteration);
        }
        lr.saveThetaAndFeatureScaling(prefix);

        i += batch_size;

        if( batch_size == orig_batch_size && i + batch_size > Xtraining.n_rows ) {
            batch_size = Xtraining.n_rows - i;
        }
    }

    LogisticRegression lr;
    lr.loadThetaAndFeatureScaling(prefix);
    lr.setFeatureMappingDegree(degree);

    arma::mat p(0,1);
    batch_size = orig_batch_size;
    if( batch_size > Xtraining.n_rows ) {
        batch_size = Xtraining.n_rows;
    }

    for( size_t i = 0; i < Xtraining.n_rows; ) {
        std::cout << "Prediction range: " << i << "-" << i + batch_size - 1 << "\n";
        arma::mat XT = Xtraining.rows(i,i+batch_size - 1);
        arma::mat p2 = lr.predict(XT);
        p.insert_rows(p.n_rows,p2);

        i += batch_size;

        if( batch_size == orig_batch_size && i + batch_size > Xtraining.n_rows ) {
            batch_size = Xtraining.n_rows - i;
        }
    }
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    p = arma::mat(0,1);
    batch_size = orig_batch_size;
    if( batch_size > Xval.n_rows ) {
        batch_size = Xval.n_rows;
    }

    for( size_t i = 0; i < Xval.n_rows; ) {
        std::cout << "Prediction range: " << i << "-" << i + batch_size - 1 << "\n";
        arma::mat XT = Xval.rows(i,i+batch_size - 1);
        arma::mat p2 = lr.predict(XT);
        p.insert_rows(p.n_rows,p2);

        i += batch_size;

        if( batch_size == orig_batch_size && i + batch_size > Xval.n_rows ) {
            batch_size = Xval.n_rows - i;
        }
    }
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";

    /*
        double threshold = 0.5; //lr.searchThreshold(Xval, Yval);
        std::cout << "Threshold: " << threshold << std::endl;
        arma::mat p = lr.predict(Xtraining,threshold);
        std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
        p = lr.predict(Xval,threshold);
        std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
     */
}

void logistic_regression_v2() {
    const long long iteration = 8e+0;
    const double alpha = 1e-2;
    const int degree = 3;
    const char* prefix = "lrv2_th11_minibatch";
    const size_t batch_size = 5000;
    const double lambda = 1e-3;

    std::cout << "logistic_regression_v2\nLoading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH_plus_BG_trainingset.bin");
        y.load("TH_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        y = arma::conv_to<arma::mat>::from(arma::all( (y == 1), 1 ));
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);

        //Ytraining = arma::conv_to<arma::mat>::from(arma::all( (Ytraining == test_th), 1 ));
        //Yval = arma::conv_to<arma::mat>::from(arma::all( (Yval == test_th), 1 ));

        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
        Xval.save(std::string(prefix) + "_Xval.bin");
        Yval.save(std::string(prefix) + "_Yval.bin");
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    }

    LogisticRegressionV2 lr(Xtraining,Ytraining,true,degree,batch_size);
    lr.miniBatchGradientDescent(true,alpha,lambda,iteration);
    lr.saveCurrentStatus(prefix);
}

void logistic_regression_v2_continue() {
    std::cout << "logistic_regression_v2_continue" << std::endl;

    const long long iteration = 2e+0;
    const double alpha = 1e-1;
    const char* prefix = "lrv2_th11_minibatch";
    const double lambda = 1e-3;

    LogisticRegressionV2 lr;
    lr.loadCurrentStatus(prefix);
    lr.miniBatchGradientDescent(false,alpha,lambda,iteration);
    lr.saveCurrentStatus(prefix);
    std::cout << "\nTraining Set Accuracy: " << lr.accuracy() << "\n";

    arma::mat Xval, Yval;
    Xval.load(std::string(prefix) + "_Xval.bin");
    Yval.load(std::string(prefix) + "_Yval.bin");

    arma::mat p = lr.predict(Xval);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
}

void logistic_regression_v2_onevsall() {
    std::cout << "logistic_regression_v2_onevsall" << std::flush;

    const long long iteration = 8e+0;
    const double alpha = 1e-2;
    const int degree = 4;
    const char* prefix = "lrv2_minibatch_onevsall";
    const size_t batch_size = 5000;
    const double lambda = 1e-3;

    std::cout << "logistic_regression_v2\nLoading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval;
    int scenario = 1;
    if(scenario==1){
        arma::mat X, y;
        X.load("TH_plus_BG_trainingset.bin");
        y.load("TH_plus_BG_trainingset_result.bin");

        std::cout << "Data set size: " << X.n_rows << "\n";
        std::cout << "Prepare training and validation set...\n";
        //y = arma::conv_to<arma::mat>::from(arma::all( (y == 1), 1 ));
        Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);

        //Ytraining = arma::conv_to<arma::mat>::from(arma::all( (Ytraining == test_th), 1 ));
        //Yval = arma::conv_to<arma::mat>::from(arma::all( (Yval == test_th), 1 ));

        std::cout << "Training set size: " << Xtraining.n_rows << "\n";
        std::cout << "Validation set size: " << Xval.n_rows << "\n";
        Xval.save(std::string(prefix) + "_Xval.bin");
        Yval.save(std::string(prefix) + "_Yval.bin");
    } else if(scenario==2){
        Xtraining.load("trainParams_X.bin");
        Ytraining.load("trainParams_y.bin");
        Xval.load("trainParams_Xval.bin");
        Yval.load("trainParams_Yval.bin");
    }

    LogisticRegressionV2 lr(Xtraining,Ytraining,true,degree,batch_size);
    lr.miniBatchGradientDescentOneVsAll(true,alpha,lambda,iteration);
    lr.saveCurrentStatus(prefix);
}

void logistic_regression_v2_onevsall_continue() {
    std::cout << "logistic_regression_v2_onevsall_continue\n";
    const long long iteration = 8e+2;
    const double alpha = .85;
    const char* prefix = "lrv2_minibatch_onevsall";
    const double lambda = 1e-55;

    LogisticRegressionV2 lr;
    lr.loadCurrentStatus(prefix);
    lr.miniBatchGradientDescentOneVsAll(false,alpha,lambda,iteration);
    lr.saveCurrentStatus(prefix);
    std::cout << "\nTraining Set Accuracy: " << lr.accuracyOneVsAll(false) << "\n";

    arma::mat Xval, Yval;
    Xval.load(std::string(prefix) + "_Xval.bin");
    Yval.load(std::string(prefix) + "_Yval.bin");

    arma::mat p = lr.predictOneVsAll(Xval);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
}

} // COC_ns

