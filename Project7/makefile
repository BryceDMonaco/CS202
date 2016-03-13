all: PolyTest
PolyTest: Driver.cpp Polynomial.o
	g++ Driver.cpp Polynomial.o -o PolyTest
Polynomial.o: Polynomial.cpp
	g++ -c Polynomial.cpp
clean:
	rm -rf *.o PolyTest
	
