all: ShapeTest
ShapeTest: Driver.cpp inheritance.o
	g++ Driver.cpp inheritance.o -o ShapeTest
inheritance.o: inheritance.cpp
	g++ -c inheritance.cpp
clean:
	rm -rf *.o ShapeTest
