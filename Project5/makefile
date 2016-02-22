all: StringTest
StringTest: Driver.cpp String.o
	g++ Driver.cpp String.o -o StringTest
String.o: String.cpp
	g++ -c String.cpp
clean:
	rm -rf *.o StringTest
	
