all: TreeDr
TreeDr: TreeDr.o
	g++ -g -o TreeDr TreeDr.o
TreeDr.o: TreeDr.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c TreeDr.cpp
clear:
	rm -f TreeDr
	rm -f *.o