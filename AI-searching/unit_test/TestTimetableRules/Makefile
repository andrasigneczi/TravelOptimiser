CXX=g++
CC=gcc
CPPFLAGS= -g -std=c++11 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -Dsprintf_s=sprintf -I../..
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -Wextra -pedantic -D__LINUX__ -pthread -Dsprintf_s=sprintf -I../..

LDFLAGS=-g -fPIC -L../.. -lBacktrack
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread -Wall -Wextra -Dsprintf_s=sprintf

LDLIBS=-lpthread -ldl
OBJDIR=Debug

SRCS1=main.cpp testTimetable.cpp

OBJS1=$(subst .cpp,.o,$(SRCS1))
OBJS11=$(addprefix $(OBJDIR)/, $(OBJS1))

OBJS=$(OBJS11) $(OBJS12)

all: DelBin test

test: $(OBJS)
	$(CXX) $(LDFLAGS) -o test $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
    
clean:
	$(RM) $(OBJS)
	$(RM) test

DelBin:
	$(RM) test