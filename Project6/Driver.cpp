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
	
	cout << "Raw Agency Data (in the order it was read in): " << endl;
	thisAgency.print();
	
	
	
	thisAgency.sortByPrice();
	
	cout << endl << "Sorted by Price Agency Data: " << endl;
	thisAgency.print();
	
	
	
	int command;
	
	do
	{
		cout << "Agency Menu: " << endl;
		cout << "1. Sort Inventory by Make" << endl;
		cout << "2. Sort Inventory by Price" << endl;
		cout << "3. Rental Price Quote" << endl;
		cout << "4. Print Agency (prints in current sorted or unsorted state)" << endl;
		cout << "5. Search for a Car by Make" << endl;
		cout << "6. Find the Most Expensive Car" << endl;
		cout << "7. Print All Available Cars" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the number of an option: ";
		
		cin >> command;
		
		if (command == 1)
		{
			thisAgency.sortByMake();
	
			cout << endl << "Sorted by Make Agency Data: " << endl;
			thisAgency.print();
		
		} else if (command == 2)
		{
			thisAgency.sortByPrice();
	
			cout << endl << "Sorted by Price Agency Data: " << endl;
			thisAgency.print();
		
		} else if (command == 3)
		{
			int numDays;
			int choice;
			
			thisAgency.print();
			cout << "Enter the number for the corresponding car: ";
			
			cin >> choice;
			
			choice -= 1;
			
			cout << "Enter the duration of the rental period: ";
			
			cin >> numDays;
			
			float cost = thisAgency.estimateCost(choice, numDays);
			
			cout << "Renting this car for " << numDays << " days will cost $" << cost << endl;
		
		} else if (command == 4)
		{
			thisAgency.print();
		
		} else if (command == 5)
		{
			cout << endl << "Enter a car make to search for: " << endl;
	
			char *searchMake = new char[20];
	
			cin >> searchMake;
	
			thisAgency.searchByMake(searchMake);
			
			delete[] searchMake;
			searchMake = NULL;
			
		} else if (command == 6)
		{
			thisAgency.findMostExpensive();
		
		} else if (command == 7)
		{
			thisAgency.printAvailableCars();
		
		}
		
		cout << "----------------------------------------------------------------" << endl;
		
	} while (command != 0);
	
	cout << endl;
	
	thisAgency.print();
	
	delete[] fileName;
	fileName = NULL;
	
	return 0;

}
