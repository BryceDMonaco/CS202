#include "Polynomial.h"
#include <iostream>
#include <fstream>

using namespace std;

int PrintMenu ();
void PrintPolys (Polynomial* polys, int numPolys);

int main ()
{
	ifstream input;
	
	char *fileName = new char[20];
	
	cout << "Input the file name: ";
	cin >> fileName;
	
	input.open(fileName);
	
	int numPolys;
	
	input >> numPolys;
	
	Polynomial *polys = new Polynomial[numPolys];
	Polynomial *polyTrav = polys;
	
	//For each poly in the array
	for (int i = 0; i < numPolys; i++)
	{
		input >> (*polyTrav);
		
		polyTrav++;
		
	}

	input.close();

	polyTrav = polys;
	
	PrintPolys(polys, numPolys);
	
	int choice = PrintMenu();
	
	while (choice != 0)
	{
		if (choice == 1)
		{
			polyTrav = polys;
							
			int constant;
				
			cout << "Enter a number to solve for: ";
			cin >> constant;
				
			cout << "Solving each polynomial for x=" << constant << ":" << endl;
				
			for (int i = 0; i < numPolys; i++)
			{
				int result = (*polyTrav).solve(constant);
					
				cout << "\t"<< *polyTrav << " when x=" << constant << " Result: " << result << endl;
					
				polyTrav++;
				
			}
				
			polyTrav = polys;
			
		} else if (choice == 2)
		{
			Polynomial *firstPoly = polys;
			Polynomial *secondPoly = polys;
				
			PrintPolys(polys, numPolys);
				
			int choice1, choice2;
				
			do
			{
				cout << "Enter the number of the first polynomial to compare: ";
				cin >> choice1;
					
				cout << "Enter the number of the second polynomial to compare: ";
				cin >> choice2;
					
				if (choice1 > numPolys || choice2 > numPolys)
				{
					cout << "Error: one or more selection was out of range." << endl;
					
				}
				
			} while (choice1 > numPolys || choice2 > numPolys);
				
			for (int i = 0; i < (choice1 - 1); i++)
			{
				firstPoly++;
				
			}
				
			for (int i = 0; i < (choice2 - 1); i++)
			{
				secondPoly++;
				
			}
				
			cout << "Is " << *firstPoly << " = " << *secondPoly << " ?" << endl;
				
			if (*firstPoly == *secondPoly)
			{
				cout << "Result: True" << endl;
				
			} else if (*firstPoly != *secondPoly)
			{
				cout << "Result: False" << endl;
				
			}
				
			firstPoly = NULL;
			secondPoly = NULL;
			
		} else if (choice == 3)
		{
			Polynomial *firstPoly = polys;
			Polynomial *secondPoly = polys;
				
			PrintPolys(polys, numPolys);
				
			int choice1, choice2;
				
			do
			{
				cout << "Enter the number of the polynomial you wish to change: ";
				cin >> choice1;
					
				cout << "Enter the number of the polynomial to set equal to: ";
				cin >> choice2;
					
				if (choice1 > numPolys || choice2 > numPolys)
				{
					cout << "Error: one or more selection(s) out of range." << endl;
					
				}
				
			} while (choice1 > numPolys || choice2 > numPolys);
				
			for (int i = 0; i < (choice1 - 1); i++)
			{
				firstPoly++;
				
			}
				
			for (int i = 0; i < (choice2 - 1); i++)
			{
				secondPoly++;
				
			}
				
			cout << "Setting " << *firstPoly << " equal to " << *secondPoly << endl;
				
			(*firstPoly) = (*secondPoly);
				
			cout << "The polynomial was changed to equal " << *firstPoly << endl;
				
			firstPoly = NULL;
			secondPoly = NULL;
			
		} else if (choice == 4)
		{
			int constant;
				
			cout << "Enter a constant to multiply a polynomial by: ";
			cin >> constant;
				
			PrintPolys(polys, numPolys);
				
			int choice;
				
			do
			{
				cout << "Enter the number of the polynomial you wish to change: ";
				cin >> choice;
					
				if (choice > numPolys)
				{
					cout << "Error: selection out of range." << endl;
					
				}
				
			} while (choice > numPolys);
				
			Polynomial *thisPoly = polys;
				
			for (int i = 0; i < (choice - 1); i++)
			{
				thisPoly++;
				
			}
				
			Polynomial resultPoly = (*thisPoly);
			resultPoly = resultPoly * constant;
				
			cout << (*thisPoly) << " * " << constant << " = " << resultPoly << endl;
				
			thisPoly = NULL;
			
		} else if (choice == 5)
		{
			Polynomial *firstPoly = polys;
			Polynomial *secondPoly = polys;
				
			PrintPolys(polys, numPolys);
				
			int choice1, choice2;
				
			do
			{
				cout << "Enter the number of the first polynomial to multiply: ";
				cin >> choice1;
					
				cout << "Enter the number of the second polynomial to multiply: ";
				cin >> choice2;
					
				if (choice1 > numPolys || choice2 > numPolys)
				{
					cout << "Error: one or more selection(s) out of range." << endl;
					
				}
				
			} while (choice1 > numPolys || choice2 > numPolys);
				
			for (int i = 0; i < (choice1 - 1); i++)
			{
				firstPoly++;
				
			}
				
			for (int i = 0; i < (choice2 - 1); i++)
			{
				secondPoly++;
				
			}
				
			Polynomial resultPoly = (*firstPoly) * (*secondPoly);
				
			cout << "(" << (*firstPoly) << ") * (" << (*secondPoly) << ") = " << resultPoly << endl;
				
			firstPoly = NULL;
			secondPoly = NULL;
			
		} else if (choice == 6)
		{
			PrintPolys(polys, numPolys);
			
		} else if (choice == 7)
		{
			Polynomial *firstPoly = polys;
			Polynomial *secondPoly = polys;
				
			PrintPolys(polys, numPolys);
				
			int choice1, choice2;
				
			do
			{
				cout << "Enter the number of the first polynomial to add: ";
				cin >> choice1;
					
				cout << "Enter the number of the second polynomial to add: ";
				cin >> choice2;
					
				if (choice1 > numPolys || choice2 > numPolys)
				{
					cout << "Error: one or more selection(s) out of range." << endl;
					
				}
				
			} while (choice1 > numPolys || choice2 > numPolys);
				
			for (int i = 0; i < (choice1 - 1); i++)
			{
				firstPoly++;
				
			}
				
			for (int i = 0; i < (choice2 - 1); i++)
			{
				secondPoly++;
				
			}
				
			Polynomial sumPoly = (*firstPoly) + (*secondPoly);
				
			cout << "(" << (*firstPoly) << ") + (" << (*secondPoly) << ") = " << sumPoly << endl;
				
			firstPoly = NULL;
			secondPoly = NULL;
			
		} else if (choice == 8)
		{
			Polynomial *firstPoly = polys;
			Polynomial *secondPoly = polys;
				
			PrintPolys(polys, numPolys);
				
			int choice1, choice2;
				
			do
			{
				cout << "Enter the number of the first polynomial to subtract: ";
				cin >> choice1;
					
				cout << "Enter the number of the second polynomial to subtract: ";
				cin >> choice2;
					
				if (choice1 > numPolys || choice2 > numPolys)
				{
					cout << "Error: one or more selection(s) out of range." << endl;
					
				}
				
			} while (choice1 > numPolys || choice2 > numPolys);
				
			for (int i = 0; i < (choice1 - 1); i++)
			{
				firstPoly++;
				
			}
				
			for (int i = 0; i < (choice2 - 1); i++)
			{
				secondPoly++;
				
			}
				
			Polynomial diffPoly = (*firstPoly) - (*secondPoly);
				
			cout << "(" << (*firstPoly) << ") - (" << (*secondPoly) << ") = " << diffPoly << endl;
				
			firstPoly = NULL;
			secondPoly = NULL;
			
		} else
		{
				cout << "Error: Input not recognized, enter a number 0-8" << endl;
			
		}
		
		choice = PrintMenu();
	
	}
	
	delete[] polys;
	polys = NULL;
	
	delete[] fileName;
	fileName = NULL;
	
	return 0;

}

int PrintMenu ()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Polynomial Class Menu: " << endl;
	cout << "1. Solve each polynomial with a constant" << endl;
	cout << "2. Check if two polynomials are equal" << endl;
	cout << "3. Set one polynomial equal to another" << endl;
	cout << "4. Multiply a polynomial by a scalar constant" << endl;
	cout << "5. Multiply a polynomial by another polynomial" << endl;
	cout << "6. Print all polynomials to screen" << endl;
	cout << "7. Find the sum of two polynomials" << endl;
	cout << "8. Find the difference of two polynomials" << endl;
	cout << "0. Exit" << endl;
	
	int choice;
	
	cout << "Enter the number corresponding to an option: ";
	cin >> choice;
	
	return choice;

}

void PrintPolys (Polynomial* polys, int numPolys)
{
	Polynomial *polyTrav = polys;
	
	for (int i = 0; i < numPolys; i++)
	{
		cout << (i + 1) << ". " << *polyTrav << endl;
		
		polyTrav++;
		
	}
	
	polyTrav = NULL;
	
	return;

}
