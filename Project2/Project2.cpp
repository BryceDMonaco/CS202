/*
	Bryce Monaco
	CS202-1102
	
	Project 2
*/

#include <iostream>
#include <fstream>

using namespace std;

struct RentalCar
{
	char make[50];
	char model[50];
	int year;
	float price;
	bool available;

};

int PrintMenu ();
void ReadData (RentalCar* carList, char fileName[50]);

int main ()
{
	char inputFile[50];
	
	cout << "Enter the car data file name: ";
	cin >> inputFile;
	
	inputFile[49] = '\0';
	
	//ifstream carData;
	//carData.open(inputFile);
	
	RentalCar carList[10];
	
	ReadData(&carList[0], inputFile);
	
	//Debug Output
	cout << carList[1].year << " " << carList[1].make << " " << carList[1].model << endl;
	
	do
	{
		int option = PrintMenu();
		
		if (option == 6)
		{
			cout << "Terminating program... " << endl;
			
			return 0;
			
		}
		
		switch (option)
		{
			case 1:
				cout << "Enter the car data file name: ";
				cin >> inputFile;
				
				inputFile[49] = '\0';		
				
				ReadData(&carList[0], inputFile);
				
				break;
				
			case 2:
				//Print data
				
				break;
			
			case 3:
				//Estimate Cost
				
				break;
				
			case 4:
				//Expensive Car
				
				break;
				
			case 5:
				//Print available
				
				break;
				
			default:
				cout << "Unrecognized input, terminating program. " << endl;
				
				return 0;
				break;
		}
	
	} while (option != 6);
	//PrintData(carList);
	
	return 0;	

}

int PrintMenu ()
{
	cout << "======================================================" << endl;
	cout <<	"Enter the number to a corresponding menu optin below: " << endl;
	cout << "1. Use a different car data file. " << endl;
	cout << "2. Print all car data to screen. " << endl;
	cout << "3. Estimate car rental cost. " << endl;
	cout << "4. Print the most expensive car's data to screen. " << endl;
	cout << "5. Print only the available cars to screen. " << endl;
	cout << "6. Exit. " << endl;
	cout << "======================================================" << endl;
	cout << "Option: ";
	
	int option;
	
	do
	{
		cin >> option;
		
		if ((option < 1) || (option > 6))
		{
			cout << endl << "INVALID OPTION, CHOOSE A NUMBER FROM 1 TO 6!" << endl;
			cout << "Option: ";
		}
		
	} while ((option <1) || (option > 6));
	
	return option;
}

void ReadData (RentalCar* carList, char fileName[50])
{
	ifstream data;
	data.open(fileName);
	
	for (int i = 0; i < 10; i++)
	{
		
		data >> carList[i].year;
		data >> carList[i].make;
		data >> carList[i].model;
		data >> carList[i].price;
		
		int tempCondition;
		
		data >> tempCondition;
		
		switch (tempCondition)
		{
			case 0:
				carList[i].available = false;
				
				break;
			
			case 1:
				carList[i].available = true;
				
				break;
			
			default:
				//If the input is incorretly formatted, assume unavailable
				carList[i].available = false;
				
				break;
		
		}
		
		cout << "Read in: " << carList[i].year << carList[i].make << carList[i].model << carList[i].price << endl;
	}
	
	data.close();
	
	return;
	
}
