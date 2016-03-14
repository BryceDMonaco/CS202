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
		friend ostream& operator<<(ostream& os, const Polynomial& sentPoly);
		friend istream& operator>>(istream& is, Polynomial& sentPoly);
		friend Polynomial operator+(Polynomial poly1, Polynomial poly2);
		friend Polynomial operator-(Polynomial poly1, Polynomial poly2);
		
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
	
	delete[] coeffs;
	
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

bool Polynomial::operator==(const Polynomial& sentPoly)
{
	if (maxDegree == sentPoly.maxDegree)
	{
		int *coeffTrav = coeffs;
		int *sentTrav = sentPoly.coeffs;
		
		for (int i = 0; i <= maxDegree; i++)
		{
			if (*coeffTrav != *sentTrav)
			{
				coeffTrav = NULL;
				sentTrav = NULL;
				
				return false;
			
			}
			
			coeffTrav++;
			sentTrav++;
		
		}
	
	} else
	{
		return false;
	
	}
	
	return true;

}

bool Polynomial::operator!=(const Polynomial& sentPoly)
{
	if (maxDegree == sentPoly.maxDegree)
	{
		int *coeffTrav = coeffs;
		int *sentTrav = sentPoly.coeffs;
		
		for (int i = 0; i <= maxDegree; i++)
		{
			if (*coeffTrav != *sentTrav)
			{
				coeffTrav = NULL;
				sentTrav = NULL;
				
				return true;
			
			}
			
			coeffTrav++;
			sentTrav++;
		
		}
		
		coeffTrav = NULL;
		sentTrav = NULL;
		
	} else
	{
		return true;
	
	}
	
	
	
	return false;

}

Polynomial Polynomial::operator*(const Polynomial& sentPoly)
{


}

Polynomial Polynomial::operator*(const int scalar)
{
	int *coeffTrav = coeffs;
	
	for (int i = 0; i <= maxDegree; i++)
	{
		(*coeffTrav) *= scalar;
		
		coeffTrav++;
	
	}
	
	coeffTrav = NULL;
	
	Polynomial tempPoly(maxDegree, coeffs);
	
	return tempPoly;

}

//Output
ostream& operator<<(ostream& os, const Polynomial& sentPoly)
{

	int thisMaxDegree = sentPoly.maxDegree;
	
	int *coeffTrav = sentPoly.coeffs;
	
	for (int i = thisMaxDegree; i >= 0; i--)
	{
		if (i == thisMaxDegree)
		{
			if (*coeffTrav != 0 && *coeffTrav != 1)
			{
				os << *coeffTrav << "x^" << i; //First term in the poly
			
			} else if (*coeffTrav != 0 && *coeffTrav == 1)
			{
				os << "x^" << i; //First term in the poly
			
			} else if (*coeffTrav == 0)
			{
				os << "0";
			
			}
			
		} else if (i != thisMaxDegree && i != 0 && *coeffTrav != 0)
		{
			if (i != 1)
			{
				if (*coeffTrav > 0)
				{
					os << " + " << *coeffTrav << "x^" << i;
				
				} else if (*coeffTrav < 0)
				{
					os << " - " << ((*coeffTrav) * -1) << "x^" << i;
				
				}
				
			} else if (i == 1)
			{
				if (*coeffTrav > 0)
				{
					os << " + " << *coeffTrav << "x";
				
				} else if (*coeffTrav < 0)
				{
					os << " - " << ((*coeffTrav) * -1) << "x";
				
				}
			
			}
			
		} else if (i == 0 && *coeffTrav != 0)
		{
			if (*coeffTrav > 0)
				{
					os << " + " << *coeffTrav;
				
				} else if (*coeffTrav < 0)
				{
					os << " - " << ((*coeffTrav) * -1);
				
				}
		
		}
		
		coeffTrav++;
	
	}
	
	coeffTrav = NULL;
	
	return os;

}

istream& operator>>(istream& is, Polynomial& sentPoly)
{
	is >> sentPoly.maxDegree;
	
	delete[] sentPoly.coeffs;
	
	sentPoly.coeffs = new int[sentPoly.maxDegree + 1];
	int *coeffTrav = sentPoly.coeffs;
	
	for (int i = 0; i <= sentPoly.maxDegree; i++)
	{
		is >> *coeffTrav;
			
		coeffTrav++;
	
	}
	
	coeffTrav = NULL;
	
	return is;

}

Polynomial operator+(Polynomial poly1, Polynomial poly2)
{
	int highDegree, lowDegree;
	int poly1Deg = poly1.maxDegree;
	int poly2Deg = poly2.maxDegree;
	
	if (poly1Deg > poly2Deg || poly1Deg == poly2Deg)
	{
		highDegree = poly1Deg;
		
	} else
	{
		highDegree = poly2Deg;
	
	}
	
	int *temp1Coeffs = new int[highDegree + 1];
	int *temp2Coeffs = new int[highDegree + 1];
	int *coeff1Trav = temp1Coeffs;
	int *coeff2Trav = temp2Coeffs;
	int *sent1Trav = poly1.coeffs;
	int *sent2Trav = poly2.coeffs;
	
	for (int i = 0; i <= highDegree; i++)
	{
		if (poly1Deg == highDegree)
		{
			*coeff1Trav = *sent1Trav;
			*coeff2Trav = 0;
			
			if (i >= (highDegree - poly2Deg))
			{
				*coeff2Trav = *sent2Trav;
				
				sent2Trav++;
				
			}
			
			sent1Trav++;
			
		
		} else if (poly2Deg == highDegree)
		{
			*coeff2Trav = *sent2Trav;
			*coeff1Trav = 0;
			
			if (i >= (highDegree - poly1Deg))
			{
				*coeff1Trav = *sent1Trav;
				
				sent1Trav++;
				
			}
			
			sent2Trav++;
		}
		
		coeff1Trav++;
		coeff2Trav++;
	
	}
	
	coeff1Trav = temp1Coeffs;
	coeff2Trav = temp2Coeffs;
	int *finalCoeffs = new int[highDegree + 1];
	int *finalTrav = finalCoeffs;
	
	for (int i = 0; i <= highDegree; i++)
	{
		*finalTrav = (*coeff1Trav) + (*coeff2Trav);
		
		coeff1Trav++;
		coeff2Trav++;
		finalTrav++;
	
	}
	
	delete[] temp1Coeffs;
	temp1Coeffs = NULL;
	
	delete[] temp2Coeffs;
	temp2Coeffs = NULL;
	
	coeff1Trav = NULL;
	
	coeff2Trav = NULL;
	
	sent1Trav = NULL;
	
	sent2Trav = NULL;
	
	Polynomial sumPoly(highDegree, finalCoeffs);
	
	delete[] finalCoeffs;
	finalCoeffs = NULL;
	
	finalTrav = NULL;
	
	return sumPoly;
	
}

Polynomial operator-(Polynomial poly1, Polynomial poly2)
{
	int highDegree, lowDegree;
	int poly1Deg = poly1.maxDegree;
	int poly2Deg = poly2.maxDegree;
	
	if (poly1Deg > poly2Deg || poly1Deg == poly2Deg)
	{
		highDegree = poly1Deg;
		
	} else
	{
		highDegree = poly2Deg;
	
	}
	
	int *temp1Coeffs = new int[highDegree + 1];
	int *temp2Coeffs = new int[highDegree + 1];
	int *coeff1Trav = temp1Coeffs;
	int *coeff2Trav = temp2Coeffs;
	int *sent1Trav = poly1.coeffs;
	int *sent2Trav = poly2.coeffs;
	
	for (int i = 0; i <= highDegree; i++)
	{
		if (poly1Deg == highDegree)
		{
			*coeff1Trav = *sent1Trav;
			*coeff2Trav = 0;
			
			if (i >= (highDegree - poly2Deg))
			{
				*coeff2Trav = *sent2Trav;
				
				sent2Trav++;
				
			}
			
			sent1Trav++;
			
		
		} else if (poly2Deg == highDegree)
		{
			*coeff2Trav = *sent2Trav;
			*coeff1Trav = 0;
			
			if (i >= (highDegree - poly1Deg))
			{
				*coeff1Trav = *sent1Trav;
				
				sent1Trav++;
				
			}
			
			sent2Trav++;
		}
		
		coeff1Trav++;
		coeff2Trav++;
	
	}
	
	coeff1Trav = temp1Coeffs;
	coeff2Trav = temp2Coeffs;
	int *finalCoeffs = new int[highDegree + 1];
	int *finalTrav = finalCoeffs;
	
	for (int i = 0; i <= highDegree; i++)
	{
		*finalTrav = (*coeff1Trav) - (*coeff2Trav);
		
		coeff1Trav++;
		coeff2Trav++;
		finalTrav++;
	
	}
	
	delete[] temp1Coeffs;
	temp1Coeffs = NULL;
	
	delete[] temp2Coeffs;
	temp2Coeffs = NULL;
	
	coeff1Trav = NULL;
	
	coeff2Trav = NULL;
	
	sent1Trav = NULL;
	
	sent2Trav = NULL;
	
	Polynomial sumPoly(highDegree, finalCoeffs);
	
	delete[] finalCoeffs;
	finalCoeffs = NULL;
	
	finalTrav = NULL;
	
	return sumPoly;
	
}
