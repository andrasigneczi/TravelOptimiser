CXX=g++
CC=gcc
CPPFLAGS= -g -O2 -std=c++11 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -Wextra -pedantic -D__LINUX__ -pthread -Dsprintf_s=sprintf -I../..

LDFLAGS=-g -fPIC -O2 -shared
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread -Wall -Wextra

LDLIBS=-lpthread -ldl -larmadillo
OBJDIR=Debug

SRCS1=gradient_descent.cpp

OBJS1=$(subst .cpp,.o,$(SRCS1))
OBJS11=$(addprefix $(OBJDIR)/, $(OBJS1))

OBJS=$(OBJS11) $(OBJS12)
TARGET=libMachineLearning.so

all: DelBin $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
    
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

DelBin:
	$(RM) $(TARGET)