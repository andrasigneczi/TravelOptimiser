#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T13:02:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleNNTrainer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screencopy.cpp

HEADERS  += mainwindow.h \
    screencopy.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -O3 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native \ 
                  -I/usr/include/qt5/QtWidgets

QMAKE_CXX = g++

unix:!macx: LIBS += -L$$PWD/../src/ -lMachineLearning

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
