all: AgencyTest
AgencyTest: Driver.cpp Agency.o
	g++ Driver.cpp Agency.o -o AgencyTest
Agency.o: Agency.cpp
	g++ -c Agency.cpp
clean:
	rm -rf *.o AgencyTest
