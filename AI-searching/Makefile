CXX=g++
CC=gcc
#CPPFLAGS=-g -std=c++11 -g -Wall -pedantic -D__LINUX__
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -pedantic -D__LINUX__ -pthread
#LDFLAGS=-g
LDLIBS=-lpthread -ldl
OBJDIR=Release

SRCS1=main.cpp Astar.cpp Connection.cpp test.cpp Context.cpp Backtrack.cpp Duration.cpp ScenarioMaker.cpp ScenarioMaker2.cpp \
     Sorters.cpp testBarcelona.cpp testTimeZone.cpp Timetable.cpp SQLiteTest.cpp

SRCS2=sqlite/sqlite3.c

OBJS1=$(subst .cpp,.o,$(SRCS1))
OBJS2=$(subst .c,.o,$(SRCS2))

OBJS11=$(addprefix $(OBJDIR)/, $(OBJS1))
OBJS12=$(addprefix $(OBJDIR)/, $(OBJS2))

OBJS=$(OBJS11) $(OBJS12)

all: DelBin Backtrack

Backtrack: $(OBJS)
	$(CXX) $(LDFLAGS) -o Backtrack $(OBJS) $(LDLIBS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
    
clean:
	$(RM) $(OBJS)
	$(RM) Backtrack

DelBin:
	$(RM) Backtrack