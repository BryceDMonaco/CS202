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
			//I'm confused on these, still :/
		
	private:
		int *coeffs;
		int maxDegree;

};
