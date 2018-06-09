#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T13:02:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MachineLearning
TEMPLATE = lib
CONFIG += shared

SOURCES += linear_regression.cpp logistic_regression.cpp fmincg.cpp neural_network.cpp CostAndGradient.cpp Util.cpp qcustomplot.cpp logistic_regression_v2.cpp anomaly_detection.cpp
HEADERS  += linear_regression.h logistic_regression.h fmincg.h neural_network.h CostAndGradient.h Util.h  qcustomplot.h logistic_regression_v2.h  anomaly_detection.h

SOURCES += kmean.cpp
HEADERS  += kmean.h

win32 {
SOURCES +=


HEADERS  += png2arma.h

} else {
SOURCES += png2arma.cpp datasetgenerator.cpp support_vector_machine.cpp


HEADERS  += png2arma.h datasetgenerator.h support_vector_machine.h

}

#FORMS    += mainwindow.ui

win32 {

INCLUDEPATH += d:\armadillo-8.500.0\include
SOURCES += ../src/neural_network.cpp ../src/fmincg.cpp
LIBS += d:/armadillo-8.500.0/Release/armadillo.lib d:/armadillo-8.500.0/examples/lib_win64/blas_win64_MT.lib
LIBS += d:/armadillo-8.500.0/examples/lib_win64/lapack_win64_MT.lib
DEFINES += QCUSTOMPLOT_COMPILE_LIBRARY
} else {
QMAKE_CXXFLAGS += -std=c++11 -O3 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native \ 
                   -I/usr/include/qt5 -DQCUSTOMPLOT_COMPILE_LIBRARY
#-I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui \
#                  -I/usr/include/qt5/QtPrintSupport
QMAKE_CXX = g++
INCLUDEPATH += ../libsvm-3.22


#unix:!macx: LIBS +=
}

#INCLUDEPATH += $$PWD/../src
#DEPENDPATH += $$PWD/../src
