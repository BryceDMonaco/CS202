#include <iostream>
#include <fstream>

using namespace std;

struct CarData
{
	char make[24];
	char model[24];
	int year;
	float price;
	bool available;	

};

struct Agency
{
	char name[24];
	int zip[5];
	CarData inventory[5];	

};

//Global Constants
const int MAX_STRING_SIZE = 50;
const int AGENCY_SIZE = 3;

//Prototypes
void PrintData (Agency *agencyList); //Prints all data
void PrintDataNumbered (Agency *agencyList); //Prints all data as a numbered list
void PrintDataAvailable (Agency *agencyList);
void ReadData (Agency *agencyList, char *fileName); //Reads data from a file
int PrintMenu (); //Prints the menu and returns choice, written to save space
void EstimateCost (int &dayAmount, float cost);
void FindMostExpensiveCar (Agency *agencyList);

void CopyString (char *string1, char *string2); //Copys one string to another
void CharArrayToIntArray (char *charArr, int *intArr); //Converts a char array to an int array

int main ()
{
	char inputFileName[MAX_STRING_SIZE];
		
	Agency agencyList[AGENCY_SIZE];
	
	Agency *agencyPtr = agencyList;
	
	cout << "Input the location data file name: ";
	cin >> inputFileName;
	
	char *finalChar = (inputFileName);
	
	for (int i = 0; i < (MAX_STRING_SIZE - 1); i++)
	{
		finalChar++;
	
	}
	
	//inputFileName[49] = '\0'; //Force a null character, just in case
	*finalChar = '\0'; //Should be the equiv. of line commented above
	
	ReadData(agencyPtr, inputFileName);
	
	//PrintDataNumbered(agencyPtr); Debug Output
	
	int choice;
	
	//For case 3, had to be declared out here to stop a compile error
	float thisCost = 0;
	Agency *chosenAgency = agencyList;
	CarData *thisCar;
	
	do
	{
		choice = PrintMenu();
		
		switch (choice)
		{
			case 1: //Read from new file
				cout << "Input the location data file name: ";
				cin >> inputFileName;
	
				finalChar = (inputFileName);
	
				for (int i = 0; i < (MAX_STRING_SIZE - 1); i++)
				{
					finalChar++;
	
				}
	
				//inputFileName[49] = '\0'; //Force a null character, just in case
				*finalChar = '\0'; //Should be the equiv. of line commented above
	
				ReadData(agencyPtr, inputFileName);
				
				break;
			
			case 2: //Print data
				PrintData(agencyPtr);
				
				break;
			
			case 3: //Cost quote
				PrintDataNumbered(agencyPtr);
				
				int car, agency, dayAmt;
				chosenAgency = agencyList;
				
				cout << "Enter the number corresponding to the agency: ";
				
				do
				{	
					cin >> agency;
					
					if (agency < 1 || agency > 3)
					{
						cout << "Invalid selection. Input a number between 1 and 3." << endl;
						cout << "Enter the number corresponding to the agency: ";
					
					}
				
				} while (agency < 1 || agency > 3);
				
				cout << "Enter the number corresponding to the car you want: ";
				
				do
				{
					cin >> car;
					
					if (agency < 1 || agency > 5)
					{
						cout << "Invalid selection. Input a number between 1 and 5." << endl;
						cout << "Enter the number corresponding to the agency: ";
					
					}
				
				} while (car < 1 || car > 5);
				
				/*
				float thisCost = 0;
				Agency *chosenAgency = agencyList;
				CarData *thisCar;
				*/
				
				for (int i = 0; i < (agency - 1); i++)
				{
					chosenAgency++;	
				
				}
				
				thisCar = (*chosenAgency).inventory;
				
				for (int i = 0; i < (car - 1); i++)
				{
					thisCar++;
				
				}
				
				thisCost = (*thisCar).price;
				
				cout << "Enter the amount of days you wish to use the car: ";
				cin >> dayAmt;
				
				cout <<"The " << (*thisCar).make << " " << (*thisCar).model << " will cost $";
				
				EstimateCost(dayAmt, thisCost);
				
				break;
				
			case 4: //Find expensive car
				FindMostExpensiveCar(agencyPtr);
				
				break;
				
			case 5: //Print available
				PrintDataAvailable(agencyPtr);
				
				break;
				
			case 6: //Terminate
				cout << "Terminating program..." << endl;
				
				break;
		}
	
	} while (choice != 6);
	
	return 0;
	
}

void PrintData (Agency *agencyList)
{
	Agency *thisAgency = agencyList;
	
	for (int i = 0; i < AGENCY_SIZE; i++)
	{
		cout << "Agency: " << (*thisAgency).name << " | ZIP: ";
		
		int *zipPtr = (*thisAgency).zip;
		
		for (int ii = 0; ii < 5; ii++)
		{
			cout << *zipPtr;
			
			zipPtr++;
			
		}
		
		cout << endl;
		
		CarData *thisCar = (*thisAgency).inventory;
		
		for (int ii = 0; ii < 5; ii++)
		{
			cout << "\t" << (*thisCar).year << " " << (*thisCar).make << " " << (*thisCar).model;
			cout << " (Price/Day: $" << (*thisCar).price << ") Avaiable: ";
			
			if ((*thisCar).available)
			{
				cout << "True" << endl;
			
			} else
			{
				cout << "False" << endl;
			
			}
			
			thisCar++;
			
		}
		
		cout << endl;
		
		thisAgency++;
		
	}
	
	return;

}

void PrintDataNumbered (Agency *agencyList)
{
	Agency *thisAgency = agencyList;
	
	for (int i = 0; i < AGENCY_SIZE; i++)
	{
		cout << "(";
		
		cout << (i + 1) << ". Agency: " << (*thisAgency).name << " | ZIP: ";
		
		int *zipPtr = (*thisAgency).zip;
		
		for (int ii = 0; ii < 5; ii++)
		{
			cout << *zipPtr;
			
			zipPtr++;
			
		}
		
		cout << ")"<< endl;
		
		CarData *thisCar = (*thisAgency).inventory;
		
		for (int ii = 0; ii < 5; ii++)
		{
			cout << "\t" << (ii +1) << ". ";
			cout << (*thisCar).year << " " << (*thisCar).make << " " << (*thisCar).model;
			cout << " (Price/Day: $" << (*thisCar).price << ") Avaiable: ";
			
			if ((*thisCar).available)
			{
				cout << "True" << endl;
			
			} else
			{
				cout << "False" << endl;
			
			}
			
			thisCar++;
			
		}
		
		cout << endl;
		
		thisAgency++;
	}
	
	return;

}

void PrintDataAvailable (Agency *agencyList)
{
	Agency *thisAgency = agencyList;
	
	for (int i = 0; i < AGENCY_SIZE; i++)
	{
		cout << "Agency: " << (*thisAgency).name << " | ZIP: ";
		
		int *zipPtr = (*thisAgency).zip;
		
		for (int ii = 0; ii < 5; ii++)
		{
			cout << *zipPtr;
			
			zipPtr++;
			
		}
		
		cout << endl;
		
		CarData *thisCar = (*thisAgency).inventory;
		
		for (int ii = 0; ii < 5; ii++)
		{	
			if ((*thisCar).available)
			{
				cout << "\t" << (*thisCar).year << " " << (*thisCar).make << " " << (*thisCar).model;
				cout << " (Price/Day: $" << (*thisCar).price << ") Avaiable: ";
				cout << "True" << endl;
			
			}
			
			thisCar++;
			
		}
		
		cout << endl;
		
		thisAgency++;
		
	}
	
	return;

}

void ReadData (Agency *agencyList, char *fileName)
{
	/*
	for (int i = 0; i < MAX_STRING_SIZE; i++)
	{
		if (*(fileName + i) != '\0')
		{	
			cout << *(fileName + i);
		
		} else //the char is a null
		{
			break;
		
		}
	}
	*/
	
	char inputFileName[50];
	
	CopyString(fileName, inputFileName);
	
	//cout << endl << inputFileName << endl; Debug output
	
	ifstream data;
	data.open(inputFileName);
	
	Agency *thisAgency = agencyList;
	
	//Reading in the data, this loop runs once per agency
	for (int i = 0; i < AGENCY_SIZE; i++)
	{
		data >> (*thisAgency).name;
		
		//Dummy array to temp. store the zip and a null char
		char zipString[6];
		
		//Reading in the zip as a string
		data >> zipString;
		
		//Debug Output
		//cout << "Read in z string, converting to int array" << endl;
		
		//Convert the zip string to an int array
		CharArrayToIntArray(zipString, (*thisAgency).zip);
		
		//Debut Output
		//cout << "Conversion complete. Outputting name." << endl;
		
		//Just a debug loop to output the name
		/*
		for (int i = 0; i < MAX_STRING_SIZE; i++)
		{
			char *namePtr = (*thisAgency).name;
			
			if (*(namePtr + i) != '\0')
			{	
				cout << *(namePtr + i);
			
			} else //the char is a null
			{
				break;
		
			}
		}
		*/
		
		/*
		//A loop to output the zip, debug
		for (int i = 0; i < 5; i++)
		{
			int * zipPtr = (*thisAgency).zip;
			
			cout << *(zipPtr + i);
			
		}
		 */
		 
		CarData *thisCar = (*thisAgency).inventory;
		
		//Read in the car data
		for (int i = 0; i < 5; i++)
		{
			data >> (*thisCar).year;
			data >> (*thisCar).make;
			data >> (*thisCar).model;
			data >> (*thisCar).price;
			
			int availableCheck;
			
			data >> availableCheck;
			
			if (availableCheck)
			{
				(*thisCar).available = true;
			
			} else
			{
				(*thisCar).available = false;
			
			}
			
			thisCar++;
			
		} 
		
		thisAgency++;
		
	}
	
	return;
	
}

int PrintMenu ()
{
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Please input the number for an option below: " << endl;
	cout << "1. Read in data from a new file (will overwrite all data). " << endl;
	cout << "2. Print all stored data. " << endl;
	cout << "3. Give rental cost quote for a specific car. " << endl;
	cout << "4. Find the most expensive car (across all agencies). " << endl;
	cout << "5. Print the data for all available cars. " << endl;
	cout << "6. Exit Program." << endl;
	cout << "Selection: ";
	
	int choice;
	
	cin >> choice;
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	
	while (choice < 1 || choice > 6)
	{
		cout << "Invalid option. Please enter a number 1-6." << endl;
		cout << "Selection: ";
		
		cin >> choice;
		
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
		
	}
	
	return choice;
	
}

void EstimateCost (int &dayAmount, float cost)
{
	float total = ((float) dayAmount) * cost;
	
	cout << total << " for " << dayAmount << " days." << endl;
	
	return;
	
}

void FindMostExpensiveCar (Agency *agencyList)
{
	int highAgency = 0, highCar = 0;
	float highPrice = 0.0;
	
	Agency *thisAgency = agencyList;
	CarData *thisCar;
	
	for (int i = 0; i < AGENCY_SIZE; i++)
	{
		thisCar = (*thisAgency).inventory;
		
		for (int ii = 0; ii < 5; ii++)
		{
			if ((*thisCar).price > highPrice)
			{
				highPrice = (*thisCar).price;
				highCar = ii;
				highAgency = i;
			}
			
			thisCar++;
			
		}
		
		thisAgency++;
		
	}
	
	cout << "The most expensive car is the ";
	
	thisAgency = agencyList;
	
	for (int i = 0; i < highAgency; i++)
	{
		thisAgency++;
	
	}
	
	thisCar = (*thisAgency).inventory;
	
	for (int i = 0; i < highCar; i++)
	{
		thisCar++;
	
	}
	
	cout << (*thisCar).make << " " << (*thisCar).model << " at $";
	cout << (*thisCar).price << "/day." << endl;
	
	return;

}

//Utility Functions
void CopyString (char *string1, char *string2) //Copy 1 into 2
{
	for (int i = 0; i < MAX_STRING_SIZE; i++)
	{	
		*(string2) = *(string1);
		
		string2++;
		string1++;
	}
	
	return;

}

void CharArrayToIntArray (char *charArr, int *intArr) //For zip
{
	for (int i = 0; i < 5; i++)
	{
		int thisChar = *(charArr) - '0';
		
		*(intArr) = thisChar;
		
		charArr++;
		intArr++;
		
	}
	
	return;

}
