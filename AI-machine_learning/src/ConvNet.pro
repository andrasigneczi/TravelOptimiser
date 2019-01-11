#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T13:02:26
#
#-------------------------------------------------

system(rm -f libConvNet.so.1.0.0)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ConvNet
TEMPLATE = lib
CONFIG += shared

SOURCES += Util.cpp qcustomplot.cpp \
    convnet.cpp \
    convnet/conv_layer.cpp \
    convnet/pool_layer.cpp \
    convnet/activation_layer.cpp \
    convnet/fully_connected_layer.cpp \
    LeNet5.cpp \
    convnet/layerobserver.cpp
HEADERS  += Util.h  qcustomplot.h \
    convnet.h \
    convnet/conv_layer.h \
    convnet/forward_backward_if.h \
    convnet/pool_layer.h \
    convnet/activation_layer.h \
    convnet/fully_connected_layer.h \
    LeNet5.h \
    convnet/layerobserver.h

#FORMS    += mainwindow.ui

OBJECTS_DIR=Debug

win32 {

INCLUDEPATH += d:\armadillo-8.500.0\include
LIBS += d:/armadillo-8.500.0/Release/armadillo.lib d:/armadillo-8.500.0/examples/lib_win64/blas_win64_MT.lib
LIBS += d:/armadillo-8.500.0/examples/lib_win64/lapack_win64_MT.lib
DEFINES += QCUSTOMPLOT_COMPILE_LIBRARY

} else {

QMAKE_CXXFLAGS += -std=c++11 -O3 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native \ 
                   -I/usr/include/qt5 -DQCUSTOMPLOT_COMPILE_LIBRARY
#-I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtWidgets -I/usr/include/qt5/QtGui \
#                  -I/usr/include/qt5/QtPrintSupport
QMAKE_CXX = g++

}
