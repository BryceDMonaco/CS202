#include <iostream>

using namespace std;

class Polynomial
{
	public:
		//Constructors and Destructor
		Polynomial();
		Polynomial(int sentDeg, int *sentCoeffs);
		Polynomial(const Polynomial& sentPoly);
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
