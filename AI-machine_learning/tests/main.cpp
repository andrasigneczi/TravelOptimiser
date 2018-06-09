#include "linear_regression.h"
#include "logistic_regression.h"
#include "neural_network.h"
#include "coc.h"
#include "support_vector_machine.h"
#include <iostream>
#include <chrono>
#include "png2arma.h"
#include <armadillo>
#include <QtWidgets/QApplication>
#include <QtCore/QSettings>
#include <QtCore/QDebug>
#include <QMainWindow>
#include "Util.h"
#include "anomaly_detection.h"

int main (int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    //QApplication app(argc, argv);

    QSettings settings("test.ini", QSettings::IniFormat);
    //settings.sync();
    settings.beginGroup("General");
    
    //settings.setValue("BuildingName1", settings.value("BuildingName1").toInt() + 1);
    //std::cout << settings.value("BuildingName1").toString().toUtf8().constData() << "\n";
    //std::cout << settings.value("BuildingName2").toString().toUtf8().constData() << "\n";
    //std::cout << settings.value("BuildingName3").toString().toUtf8().constData() << "\n";
    settings.endGroup();
    
    settings.beginGroup("Others");
    settings.setValue("other1","11");
    //std::cout << settings.value("other1").toString().toUtf8().constData() << "\n";
    settings.endGroup();
    //std::cout << values["BuildingName"].toUtf8().constData() << std::endl;
    //std::cout << values.size();

    //LinearRegression::gradientDescentCalc();
    //std::cout << std::string( 80, '-' ) << std::endl;
    //LogisticRegression_ns::runTests();

    //Png2Arma_ns::runTests();

    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //NeuralNetwork_ns::runTests();
    COC_ns::runTests();
    //SVM_ns::runTests();
    //AnomalyDetection_ns::runTests();
    //std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;


//  QMainWindow w;
//  w.show();

  //return 0;
    /*

    arma::mat ttt;
    ttt << 1 << 10 << 11 << 12 << arma::endr << 2 << 20 << 21 << 22 << arma::endr << 3 << 30 << 31 << 32 << arma::endr
        << 4 << 40 << 41 << 42 << arma::endr << 5 << 50 << 51 << 52;

    //std::cout << ttt << "\n\n";
    //ttt.elem( arma::find( ttt == 5 ) ).ones();
    //std::cout << ttt;
    //std::cout << arma::conv_to<arma::mat>::from(arma::all( (ttt == 5), 1 ));
    //std::cout << arma::any((ttt >= 30),1);

    std::cout << Util::mapFeature(ttt.cols(0,1), ttt.cols(2,3));

    arma::mat X,y,Xval,yval;
    X.load("ex8data1_X.txt");
    Xval.load("ex8data1_Xval.txt");
    yval.load("ex8data1_yval.txt");


    X.save("ex8data1_X.bin");
    Xval.save("ex8data1_Xval.bin");
    yval.save("ex8data1_yval.bin");

    //arma::mat X,y,Xval,yval;
    X.load("ex8data2_X.txt");
    Xval.load("ex8data2_Xval.txt");
    yval.load("ex8data2_yval.txt");


    X.save("ex8data2_X.bin");
    Xval.save("ex8data2_Xval.bin");
    yval.save("ex8data2_yval.bin");
*/
  //app.exec();
}
