CXX=g++
CC=gcc
CPPFLAGS= -O3 -std=c++11 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native -I/usr/include/qt5 -I/usr/include/qt5/QtWidgets \
          -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets \
          -I/usr/include/x86_64-linux-gnu/qt5/QtCore
#   -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -Wextra -pedantic -D__LINUX__ -pthread -Dsprintf_s=sprintf -I../..

LDFLAGS=-fPIC -O3 -L../src -march=native -L/usr/lib/x86_64-linux-gnu -L../libsvm-3.22
CFLAGS= -O3 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread -Wall -Wextra

LDLIBS=-lMachineLearning -lpthread -ldl -larmadillo -lQt5Gui -lQt5Core -lQt5Widgets -lQt5PrintSupport -lsvm
OBJDIR=Debug

SRCS1=main.cpp linear_regression.cpp logistic_regression.cpp neural_network.cpp png2arma.cpp coc.cpp support_vector_machine.cpp

OBJS1=$(subst .cpp,.o,$(SRCS1))
OBJS11=$(addprefix $(OBJDIR)/, $(OBJS1))

OBJS=$(OBJS11) $(OBJS12)
TARGET=test

all: DelBin $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)
	strip -s $(TARGET)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
    
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

DelBin:
	$(RM) $(TARGET)