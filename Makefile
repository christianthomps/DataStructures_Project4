FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

all: TreeDr

TreeDr: TreeDr.o QueType.o TreeType.o
	g++ $(FLAGS) BankSimulation.o QueType.o TreeType.o -o BankSimulation

QueType.o: QueType.cpp QueType.h
	g++ $(FLAGS) -c QueType.cpp

TreeType.o: TreeType.cpp TreeType.h
	g++ $(FLAGS) -c TreeType.cpp

TreeType.o: TreeType.cpp
	g++ $(FLAGS) -c TreeType.cpp

run: TreeType
	./TreeType

clean:
	rm -f *.o
	rm -f BankSimulation