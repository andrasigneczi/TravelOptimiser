CXX=g++
CC=gcc
CPPFLAGS= -O3 -std=c++11 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -I ../src -DARMA_USE_CXX11 -march=native
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -Wextra -pedantic -D__LINUX__ -pthread -Dsprintf_s=sprintf -I../..

LDFLAGS=-fPIC -O3 -L../src -march=native
CFLAGS= -O3 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread -Wall -Wextra

LDLIBS=-lMachineLearning -lpthread -ldl -larmadillo -lpng
OBJDIR=Debug

SRCS1=matrix_test.cpp linear_regression.cpp logistic_regression.cpp neural_network.cpp png2arma.cpp

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