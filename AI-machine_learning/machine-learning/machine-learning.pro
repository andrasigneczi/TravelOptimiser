QT += core
QT -= gui

TARGET = machine-learning
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../src/CostAndGradient.cpp \
    ../src/datasetgenerator.cpp \
    ../src/fmincg.cpp \
    ../src/linear_regression.cpp \
    ../src/logistic_regression.cpp \
    ../src/neural_network.cpp \
    ../src/png2arma.cpp \
    ../src/Util.cpp \
    ../tests/machine-learning/main.cpp \
    ../tests/linear_regression.cpp \
    ../tests/logistic_regression.cpp \
    ../tests/main.cpp \
    ../tests/neural_network.cpp \
    ../tests/png2arma.cpp

HEADERS += \
    ../src/CostAndGradient.h \
    ../src/datasetgenerator.h \
    ../src/fmincg.h \
    ../src/linear_regression.h \
    ../src/logistic_regression.h \
    ../src/neural_network.h \
    ../src/png2arma.h \
    ../src/Util.h \
    ../tests/linear_regression.h \
    ../tests/logistic_regression.h \
    ../tests/neural_network.h \
    ../tests/png2arma.h

