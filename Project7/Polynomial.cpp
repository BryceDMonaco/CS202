/*
class Polynomial
{
	public:
		//Constructors and Destructor
		Polynomial();
		Polynomial(int sentDeg, int *sentCoeffs);
		Polynomail(const Polynomial& sentPoly);
		~Polynomial();
		
		//Member Function
		int solve (int plugin);
		
		//Operator Overloads
		void operator=(const Polynomial& sentPoly);
		bool operator==(const Polynomial& sentPoly);
		bool operator!=(const Polynomial& sentPoly);
		Polynomial operator*(const Polynomial& sentPoly);
		Polynomial operator*(const int scalar);
		
		//Friend Functions
			//I'm confused on these, still :/
		
	private:
		int *coeffs;
		int maxDegree;

};
*/

#include "Polynomial.h"
#include <iostream>

using namespace std;

//Default Constructor
Polynomial::Polynomial ()
{
	maxDegree = 3;
	
	coeffs = new int[maxDegree + 1]; //+1 to account for the constant

}

//Param Constructor
Polynomial::Polynomial (int sentDeg, int *sentCoeffs)
{
	maxDegree = sentDeg;
	
	coeffs = new int[maxDegree + 1];
	
	int *coeffTrav = coeffs;
	int *sentTrav = sentCoeffs;
		
	for (int i = 0; i < maxDegree + 1; i++)
	{
		*coeffTrav = *sentTrav;
		
		coeffTrav++;
		sentTrav++;
	
	}

}

//Copy Constructory
Polynomial::Polynomial (const Polynomial& sentPoly)
{
	maxDegree = sentPoly.maxDegree;
	
	coeffs = new int[maxDegree + 1];
	
	int *coeffTrav = coeffs;
	int *sentTrav = sentPoly.coeffs;
		
	for (int i = 0; i <= maxDegree; i++)
	{
		*coeffTrav = *sentTrav;
		
		coeffTrav++;
		sentTrav++;
	
	}

}

//Destructor
Polynomial::~Polynomial ()
{
	delete[] coeffs;
	coeffs = NULL;

}

int Polynomial::solve (int plugin)
{
	int sum = 0;
	int currentDegree = maxDegree;
	int *currentCoeff = coeffs;
	
	for (int i = 0; i < maxDegree; i++) 
	{
		int currentValue = plugin;
		int base = plugin;
		//cout << "Current value (Start): " << currentValue << endl;
		//cout << "Current coeff: " << *currentCoeff << endl;
		//cout << "Taking the input to power " << currentDegree << endl; 
		
		//Bring the value to the power
		for (int ii = 1; ii < currentDegree; ii++)
		{
			currentValue *= base;
			
		}
		
		//cout << "Current value (after exp.): " << currentValue << endl;
		
		//Multiply the powered value by the coeff
		currentValue *= *currentCoeff;
		
		//cout << "Current value (after mult.): " << currentValue << endl;
		
		sum += currentValue;
		
		//cout << "Current sum: " << sum << endl;
		
		currentCoeff++;
		currentDegree--;
	
	}
	
	//cout << "Final constant = " << (*currentCoeff) << endl;
	
	sum += (*currentCoeff); //Add the final constant
	
	//cout << "Final sum: " << sum << endl;
	
	currentCoeff = NULL;
	
	return sum;
	
}

void Polynomial::operator=(const Polynomial& sentPoly)
{
	maxDegree = sentPoly.maxDegree;
	
	coeffs = new int[maxDegree + 1];
	
	int *coeffTrav = coeffs;
	int *sentTrav = sentPoly.coeffs;
		
	for (int i = 0; i <= maxDegree; i++)
	{
		*coeffTrav = *sentTrav;
		
		coeffTrav++;
		sentTrav++;
	
	}
	
	return;

}
