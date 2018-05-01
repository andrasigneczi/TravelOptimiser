#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T13:02:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MachineLearning
TEMPLATE = lib
CONFIG += shared

SOURCES += linear_regression.cpp logistic_regression.cpp fmincg.cpp neural_network.cpp png2arma.cpp CostAndGradient.cpp \
      datasetgenerator.cpp Util.cpp qcustomplot.cpp


HEADERS  += linear_regression.h logistic_regression.h fmincg.cpp neural_network.h png2arma.h CostAndGradient.h \
      datasetgenerator.h Util.h qcustomplot.h


#FORMS    += mainwindow.ui

win32 {

INCLUDEPATH += d:\armadillo-8.500.0\include
SOURCES += ../src/neural_network.cpp ../src/fmincg.cpp
LIBS += d:/armadillo-8.500.0/Release/armadillo.lib d:/armadillo-8.500.0/examples/lib_win64/blas_win64_MT.lib
LIBS += d:/armadillo-8.500.0/examples/lib_win64/lapack_win64_MT.lib
} else {
QMAKE_CXXFLAGS += -std=c++11 -O3 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native \ 
                   -I/usr/include/qt5 -DQCUSTOMPLOT_COMPILE_LIBRARY
#-I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui \
                  -I/usr/include/qt5/QtPrintSupport
QMAKE_CXX = g++


#unix:!macx: LIBS +=
}

#INCLUDEPATH += $$PWD/../src
#DEPENDPATH += $$PWD/../src
