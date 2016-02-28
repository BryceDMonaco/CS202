#include <iostream>
#include "Agency.h"

using namespace std;

int main ()
{
	//Wow there is a lot going on here
	Agency thisAgency;
	
	cout << "Enter the data file name (max. 18 chars.): ";
	
	char *fileName = new char[20];
	
	cin >> fileName;
	
	thisAgency.readInData(fileName);
	
	thisAgency.print();
	
	delete[] fileName;
	fileName = NULL;
	
	return 0;

}
