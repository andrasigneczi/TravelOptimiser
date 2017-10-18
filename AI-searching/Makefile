CXX=g++
#CPPFLAGS=-g -std=c++11 -g -Wall -pedantic -D__LINUX__
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -pedantic -D__LINUX__
#LDFLAGS=-g
LDLIBS=
OBJDIR=Release

SRCS=main.cpp Astar.cpp Connection.cpp test.cpp Context.cpp Backtrack.cpp Duration.cpp ScenarioMaker.cpp ScenarioMaker2.cpp \
     Sorters.cpp testBarcelona.cpp testTimeZone.cpp Timetable.cpp
#SQLiteTest.cpp 
OBJS1=$(subst .cpp,.o,$(SRCS))
OBJS=$(addprefix $(OBJDIR)/, $(OBJS1))


all: DelBin Backtrack

Backtrack: $(OBJS)
	$(CXX) $(LDFLAGS) -o Backtrack $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
    
clean:
	$(RM) $(OBJS)
	$(RM) Backtrack

DelBin:
	$(RM) Backtrack