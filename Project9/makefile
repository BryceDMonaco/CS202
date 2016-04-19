all: QueueTest
QueueTest: Driver.cpp queue2.o
	g++ Driver.cpp queue2.o -o QueueTest
queue2.o: queue2.cpp
	g++ -c queue2.cpp
clean:
	rm -rf *.o QueueTest
