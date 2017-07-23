CXX=g++
CPPFLAGS=-g -std=c++11 -g -Wall -pedantic
LDFLAGS=-g
LDLIBS=

SRCS=main.cpp Astar.cpp Connection.cpp test.cpp Context.cpp Backtrack.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: DelBin Astar

Astar: $(OBJS)
	$(CXX) $(LDFLAGS) -o Astar $(OBJS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	$(RM) Astar

DelBin:
	$(RM) Astar