all: StackTest
StackTest: Driver.cpp stack3.o
	g++ Driver.cpp stack3.o -o StackTest
stack3.o: stack3.cpp
	g++ -c stack3.cpp
clean:
	rm -rf *.o StackTest
