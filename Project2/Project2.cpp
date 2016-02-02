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

void PrintData (RentalCar* carList, int mode);
void CalculateCost (int &dayAmount, float cost); 
void GetMostExpensive (RentalCar* carList);
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
	
	int option;
	
	do
	{
		option = PrintMenu();
		
		if (option == 6)
		{
			cout << "Terminating program... " << endl;
			
			return 0;
			
		}
		
		switch (option)
		{
			case 1:
				//Read new file
				
				cout << "Enter the car data file name: ";
				cin >> inputFile;
				
				inputFile[49] = '\0';		
				
				ReadData(&carList[0], inputFile);
				
				PrintData(&carList[0], 0);
				
				break;
				
			case 2:
				//Print data
				
				PrintData(&carList[0], 0);
				
				break;
			
			case 3:
				//Estimate Cost
				
				PrintData(&carList[0], 1);
				
				cout << "Please select a car: ";
				
				int car;
				
				do
				{
					cin >> car;
					
					if ((car < 1) || (car > 10))
					{
						cout << "Please enter a number between 1 and 10." << endl;
						cout << "Please select a car: ";
						
					}
				
				} while ((car < 1) || (car > 10));
				
				cout << "Enter the number of days you want the car: ";
				
				int days;
				
				cin >> days;
				
				cout << "The " << carList[car - 1].make << " " << carList[car - 1].model;
				cout << " will cost $";
				
				CalculateCost(days, carList[car - 1].price);
				
				break;
				
			case 4:
				//Find most expensive car
				GetMostExpensive(&carList[0]);
				
				break;
				
			case 5:
				//Print available
				
				PrintData(&carList[0], 2);
				
				break;
				
			default:
				cout << "Unrecognized input, terminating program. " << endl;
				
				return 0;
				break;
		}
	
	} while (option != 6);
	
	return 0;	

}

void PrintData (RentalCar* carList, int mode)
{
	if (mode == 0) //Just print the data
	{
		for (int i = 0; i < 10; i++)
		{
			cout << carList[i].year << " " << carList[i].make;
			cout << " " << carList[i].model << " (Cost/Day: $" << carList[i].price;
			cout << ")";
			
			if (carList[i].available)
			{
				cout << " (Available)" << endl;
			
			} else
			{
				cout << " (Not Available)" << endl;
			
			}
					
		}
	
	} else if (mode == 1) //Print the data as a numbered list
	{
		for (int i = 0; i < 10; i++)
		{
			cout << (i + 1) << ". " << carList[i].year << " " << carList[i].make;
			cout << " " << carList[i].model << " (Cost/Day: $" << carList[i].price;
			cout << ")" << endl;
					
		}
	
	} else if (mode == 2) //Print only the available cars
	{
		for (int i = 0; i < 10; i++)
		{
			if (carList[i].available)
			{
				cout << carList[i].year << " " << carList[i].make;
				cout << " " << carList[i].model << " (Cost/Day: $" << carList[i].price;
				cout << ")" << endl;
			
			}
		
		}
	
	}
	
	return;

}


//This function fufills the pass by reference rerquirement
void CalculateCost (int &dayAmount, float cost)
{
	float total = (float) dayAmount * cost;
	
	cout << total << " for " << dayAmount << " days." << endl;
	
	return;
	
}

void GetMostExpensive (RentalCar* carList)
{
	int top = 0;
	float highPrice = 0.0;
	
	for (int i = 0; i < 10; i++)
	{
		if (carList[i].price > highPrice)
		{
			highPrice = carList[i].price;
			
			top = i;
			
		}
	
	}
	
	cout << "The most expensive car is the " << carList[top].make << " " << carList[top].model;
	cout << " at " << carList[top].price << " per day. " << endl;
	
	return;
	
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
		
		//cout << "Read in: " << carList[i].year << carList[i].make << carList[i].model << carList[i].price << endl;
	}
	
	data.close();
	
	return;
	
}
