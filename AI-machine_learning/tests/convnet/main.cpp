#include "convnet.h"
#include <iostream>
#include "Util.h"
#include <QtWidgets/QApplication>
#include <QtCore/QSettings>
#include <QtCore/QDebug>

int main (int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    //QApplication app(argc, argv);

    //QSettings settings("LeNet5.ini", QSettings::IniFormat);
    //settings.sync();
    //settings.beginGroup("General");
    
    //settings.setValue("BuildingName1", settings.value("BuildingName1").toInt() + 1);
    //std::cout << settings.value("BuildingName1").toString().toUtf8().constData() << "\n";
    //std::cout << settings.value("BuildingName2").toString().toUtf8().constData() << "\n";
    //std::cout << settings.value("BuildingName3").toString().toUtf8().constData() << "\n";
    //settings.endGroup();
    
    //settings.beginGroup("MNIST");
    //settings.setValue("alpha","0.001");
    //settings.setValue("beta","0.9");
    //settings.setValue("beta1","0.9");
    //settings.setValue("beta2","0.999");
    //settings.setValue("lambda","0.001");
    //settings.setValue("epoc_num","4");
    //settings.setValue("batch_size","128");
    //settings.setValue("keep_prob","1.0");
    //settings.setValue("optimization","adam");
    //settings.setValue("batch_norm","0");
    //settings.setValue("feature_scaling","1");
    //settings.setValue("output_labels","10");



    //std::cout << settings.value("other1").toString().toUtf8().constData() << "\n";
    //settings.endGroup();
    //std::cout << values["BuildingName"].toUtf8().constData() << std::endl;
    //std::cout << values.size();

    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    try {
        convLayerTest();
    } catch(const char* str) {
        std::cerr << str;
    }
    //std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;
}
