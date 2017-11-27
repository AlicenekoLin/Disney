# A simple makefile for CSE 100 PA4

CC=g++
CXXFLAGS=-std=c++11
LDFLAGS=

# if passed "type=opt" at command-line, compile with "-O3" flag (otherwise use "-g" for debugging)

ifeq ($(type),opt)
    CPPFLAGS += -O3
    LDFLAGS += -O3
else
    CPPFLAGS += -g
    LDFLAGS += -g
endif

all: pathfinder actorconnections extension
# Note: you do not have to include a *.cpp file if it aleady has a paired *.h file that is already included with class/method headers

# include what ever source code *.h files pathfinder relies on
pathfinder: ActorGraph.o DisjointSet.o Timer.o

# include what ever source code *.h files actorconnections relies on
actorconnections: ActorGraph.o DisjointSet.o Timer.o

# include what ever source code *.h files ActorGraph relies on
ActorGraph.o: ActorNode.h MovieEdge.h ActorGraph.h

# include what ever source code *.h files DisjointSet relies on
DisjointSet.o: DisjointSet.h

# include Timer class
Timer.o: Timer.h

extension: DisneyGraph.o

DisneyGraph.o: DisneyNode.h DisneyGraph.h

clean:
	rm -f pathfinder *.o core*
