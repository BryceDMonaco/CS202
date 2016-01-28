#include <iostream>

using namespace std;

int main ()
{

	int selection;
	
	do
	{
		cout << "Computer Science Registration Menu" << endl;
		cout << "**********************************" << endl;
		cout << "1. Welcome to Computer Programming in C++" << endl;
		cout << "2. Welcome to Computer Programming in Java" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your selection (1-3): ";
		
		cin >> selection;
		
		switch (selection)
		{
			case 1:
				cout << "Computer Programming in C++" << endl << endl;
				break;
				
			case 2:
				cout << "Computer Programming in Java" << endl << endl;
				break;
				
			case 3:
				cout << "Goodbye!" << endl << endl;
				break;
				
			default:
				cout << "Input not recognized, please enter a number (1-3)" << endl << endl;
				break;
		
		}
	
	} while (selection != 3);
	
	return 0;
	
}
