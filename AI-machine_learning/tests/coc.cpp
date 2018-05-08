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
void logistic_regression_fmincg();
void full_paramtest_logitic_regression();

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
    //logistic_regression_fmincg();
    full_paramtest_logitic_regression();
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

// 3800, 0.003
// 3850, 10

//5378
//0.1
//0.264999
void coc_th11_train_params_searching() {
    arma::mat X, y, thetaSizes;
    X.load("TH11_plus_BG_trainingset.bin");
    y.load("TH11_plus_BG_trainingset_result.bin");

    thetaSizes << 24*24 << 0 << 2; // input, hidden, output
    COCYMappper2 yMapper;
    NeuralNetwork* nn = new NeuralNetwork(thetaSizes, X, y, 1, yMapper);
    NeuralNetwork::TrainParams tp = nn->searchTrainParams(1000,8000,200);
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

    nn = new NeuralNetwork(thetaSizes, Xtraining, Ytraining, tp.lambda, yMapper);
    arma::mat trainedThetas = nn->train(1000);

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

void coc_th11_train() {
    std::cout << "Loading data...\n" << std::flush;

    arma::mat Xtraining, Ytraining, Xval, Yval,thetaSizes;
    thetaSizes.load("TH11_plus_BG_thetasizes.bin");
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    COCYMappper2 yMapper;
    NeuralNetwork* nn = new NeuralNetwork(thetaSizes, Xtraining, Ytraining, 0.1, yMapper);
    arma::mat trainedThetas = nn->train(100);

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
    LogisticRegression lr(Xtraining, Ytraining,lambda, true);
    arma::mat lcv = lr.learningCurve(Xval, Yval, lambda, iteration,10);
    Util::plotMatrix(new QCustomPlot, lcv);
    std::cout << "\n" << lcv << "\n" << std::flush;
    std::cout << "Validation curve...\n";
    arma::mat lcv2 = lr.validationCurve(Xval, Yval, iteration);
    Util::plotMatrix(new QCustomPlot, lcv2);
    std::cout << "\n" << lcv2 << "\n" << std::flush;
}

void logistic_regression_fmincg() {
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

    double lambda = 3.0e-6;
    long long iteration = 2e+2;
    //std::cout << "Calculating gradient descent...\n";
    //arma::mat theta = lr.gradientDescentWithReguralization( Xtraining, Ytraining, initial_theta, alpha, lambda, iteration );
    LogisticRegression lr(Xtraining, Ytraining, lambda, true );
    fmincgRetVal frv = fmincg(lr, initial_theta, iteration, true);
    arma::mat& theta = frv.m_NNPparams;

    arma::mat p = lr.predict(Xtraining,theta);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    p = lr.predict(Xval,theta);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";
}

void full_paramtest_logitic_regression() {
    arma::mat X, y, Xtraining, Ytraining, Xval, Yval;

    std::cout << "Reading data set...\n";
    /*
    X.load("TH11_plus_BG_trainingset.bin");
    y.load("TH11_plus_BG_trainingset_result.bin");

    std::cout << "Data set size: " << X.n_rows << "\n";
    std::cout << "Prepare training and validation set...\n";
    Util::prepareTrainingAndValidationSet(X, y, Xtraining, Ytraining, Xval, Yval);
    std::cout << "Training set size: " << Xtraining.n_rows << "\n";
    std::cout << "Validation set size: " << Xval.n_rows << "\n";
*/
    Xtraining.load("trainParams_X.bin");
    Ytraining.load("trainParams_y.bin");
    Xval.load("trainParams_Xval.bin");
    Yval.load("trainParams_Yval.bin");

    double n = Xtraining.n_cols;
    double m = Ytraining.n_rows;
    int small_image_width = (int)sqrt(Xval.n_cols);

    // let's insert a column filled with ones
    Xtraining.insert_cols(0, arma::ones<arma::mat>(m,1));
    Xval.insert_cols(0, arma::ones<arma::mat>(Yval.n_rows,1));

    // Initialize fitting parameters
    arma::mat initial_theta = arma::zeros(n + 1, 1);

    double lambda = 0;
    long long iteration = 2e+2;
    LogisticRegression lr(Xtraining, Ytraining, lambda, true );
    fmincgRetVal frv = fmincg(lr, initial_theta, iteration, true);
    arma::mat& theta = frv.m_NNPparams;

    arma::mat p = lr.predict(Xtraining,theta);
    std::cout << "\nTraining Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Ytraining)) * 100 << "\n";
    p = lr.predict(Xval,theta);
    std::cout << "Validation Set Accuracy: " << arma::mean(arma::conv_to<arma::colvec>::from(p == Yval)) * 100 << "\n";

    QImage img(small_image_width,small_image_width, QImage::Format_RGB32);

    for( size_t i = 0; i < p.n_rows; ++i) {
        if( p(i,0) != Yval(i,0)) {
            std::cout << "Expected: " << Yval(i,0) << "; Predicted: " << p(i,0) << "\n" << std::flush;

            char name[100];
            for( size_t j = 1; j < Xval.n_cols; ++j ) {
                img.setPixel((j-1)%small_image_width,(j-1)/small_image_width, Xval(i, j));
            }
            sprintf(name, "tmp2/wrong_%lu_e%i_p%i.png", i, (int)Yval(i,0), (int)p(i,0));
            img.save(name);
        }
    }
}

} // COC_ns
