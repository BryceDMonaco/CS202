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
		int tempDegree;
		
		input >> tempDegree;
		
		//cout << "Read tempDegree" << endl;
		
		int *coeffs = new int[tempDegree + 1];
		int *coeffTrav = coeffs;
		
		//cout << "Coeff array made" << endl;
		
		cout << "DEBUG: \tDEG: " << tempDegree << "COEFFS: ";
		
		for (int ii = 0; ii <= tempDegree; ii++)
		{
			//cout << "On Coeff #" << ii
			input >> *coeffTrav;
			
			cout << *coeffTrav << " ";
			
			coeffTrav++;
		
		}
		
		cout << endl;
		
		//cout << endl << "Coeffs read in" << endl;
		
		Polynomial tempPoly(tempDegree, coeffs);
		
		(*polyTrav) = tempPoly; //Should call the parameterized constructor
		
		//cout << "Set the poly equal to" << endl;
		
		polyTrav++;
		
		delete[] coeffs;
		
		coeffTrav = NULL;
		
	}
	
	//cout << "Done reading..." << endl;
	
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
	
	input.close();
	
	delete[] polys;
	polys = NULL;
	
	delete[] fileName;
	fileName = NULL;
	
	return 0;

}