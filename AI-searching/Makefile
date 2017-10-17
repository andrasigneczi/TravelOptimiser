CXX=g++
#CPPFLAGS=-g -std=c++11 -g -Wall -pedantic -D__LINUX__
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -pedantic -D__LINUX__
LDFLAGS=-g
LDLIBS=

SRCS=main.cpp Astar.cpp Connection.cpp test.cpp Context.cpp Backtrack.cpp Duration.cpp ScenarioMaker.cpp ScenarioMaker2.cpp \
     Sorters.cpp testBarcelona.cpp testTimeZone.cpp Timetable.cpp
#SQLiteTest.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

all: DelBin Backtrack

Backtrack: $(OBJS)
	$(CXX) $(LDFLAGS) -o Backtrack $(OBJS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	$(RM) Astar

DelBin:
	$(RM) Backtrack