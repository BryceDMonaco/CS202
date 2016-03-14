#include "Polynomial.h"
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	ifstream input;
	
	char *fileName = new char[20];
	
	cout << "Input the file name: ";
	cin >> fileName;
	
	input.open(fileName);
	
	int numPolys;
	
	//cout << "Opened" << endl;
	
	input >> numPolys;
	
	Polynomial *polys = new Polynomial[numPolys];
	Polynomial *polyTrav = polys;
	
	//cout << "Reading in..." << endl;
	
	//For each poly in the array
	for (int i = 0; i < numPolys; i++)
	{
		input >> (*polyTrav);
		
		polyTrav++;
		
	}
	
	//cout << "Done reading..." << endl;

	input.close();

	polyTrav = polys;
	
	for (int i = 0; i < numPolys; i++)
	{
		int result = (*polyTrav).solve(5);
		cout << "Poly result " << i << " is: " << result << endl;
		
		polyTrav++;
		
	}
	
	polyTrav = polys;
	
	cout <<"TestTestTest: " << endl;
	
	for (int i = 0; i < numPolys; i++)
	{
		cout << *polyTrav << endl;
		
		polyTrav++;
	
	}
	
	Polynomial *addPoly = polys;
	
	polyTrav = polys;
	polyTrav++;
	
	*addPoly = (*addPoly) + (*polyTrav);
	
	cout << *addPoly << endl;
	
	*addPoly = (*addPoly) - (*polyTrav);
	
	cout << *addPoly << endl;
	
	delete[] polys;
	polys = NULL;
	
	delete[] fileName;
	fileName = NULL;
	
	return 0;

}
