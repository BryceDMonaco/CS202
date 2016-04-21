all: ListTest
ListTest: Driver.cpp listnode.o
	g++ Driver.cpp listnode.o -o ListTest
listnode.o: listnode.cpp
	g++ -c listnode.cpp
clean:
	rm -rf *.o ListTest
