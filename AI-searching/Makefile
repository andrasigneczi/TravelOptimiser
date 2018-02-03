CXX=g++
CC=gcc
CPPFLAGS= -g -std=c++11 -Wall -Wextra -pedantic -D__LINUX__  -pthread -fPIC -Dsprintf_s=sprintf
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -Wall -Wextra -pedantic -D__LINUX__ -pthread -Dsprintf_s=sprintf
#CPPFLAGS= -O2 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread \
# -Wall -Wextra -Wcast-align -Wcast-qual -Wdiv-by-zero -Wendif-labels -Wformat-extra-args -Wformat-nonliteral -Wformat-security \
# -Wdisabled-optimization  -Wformat-y2k -Wimport -Winit-self -Winvalid-pch -Wlogical-op \
# -Werror=missing-braces -Wno-missing-format-attribute -Wmissing-include-dirs -Wmultichar -Wpacked -Wpointer-arith \
# -Wreturn-type -Wsequence-point -Wsign-compare -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wswitch-default -Werror=undef -Wno-unused \
# -Wvariadic-macros -Wwrite-strings -Werror=declaration-after-statement -Werror=implicit-function-declaration \
# -Werror=nested-externs -Werror=old-style-definition -Werror=strict-prototypes 
 
 # OK
 # -Waggregate-return -Winline -Wmissing-declarations 
 
LDFLAGS=-g -shared -fPIC
CFLAGS= -O2 -s -DNDEBUG -std=c++11 -pedantic -D__LINUX__ -pthread -Wall -Wextra -fPIC -Dsprintf_s=sprintf

LDLIBS=-lpthread -ldl
OBJDIR=Debug

SRCS1=main.cpp Astar.cpp Connection.cpp test.cpp Context.cpp Backtrack.cpp Duration.cpp ScenarioMaker.cpp ScenarioMaker2.cpp \
     Sorters.cpp testBarcelona.cpp testTimeZone.cpp Timetable.cpp SQLiteTest.cpp TimeHelper.cpp Date.cpp

SRCS2=sqlite/sqlite3.c

OBJS1=$(subst .cpp,.o,$(SRCS1))
OBJS2=$(subst .c,.o,$(SRCS2))

OBJS11=$(addprefix $(OBJDIR)/, $(OBJS1))
OBJS12=$(addprefix $(OBJDIR)/, $(OBJS2))

OBJS=$(OBJS11) $(OBJS12)
TARGET=libBacktrack.so

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