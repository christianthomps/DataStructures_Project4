FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

all: TreeDr

TreeDr: TreeDr.o QueType.o TreeType.o
	g++ $(FLAGS) TreeDr.o QueType.o TreeType.o -o TreeDr

QueType.o: QueType.cpp QueType.h
	g++ $(FLAGS) -c QueType.cpp

TreeType.o: TreeType.cpp TreeType.h
	g++ $(FLAGS) -c TreeType.cpp

TreeDr.o: TreeDr.cpp
	g++ $(FLAGS) -c TreeDr.cpp

run: TreeDr
	./TreeDr

clean:
	rm -f *.o
	rm -f TreeDr