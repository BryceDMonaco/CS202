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

//void PrintData (RentalCar* carList);
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
	
	cout << carList[1].year << " " << carList[1].make << " " << carList[1].model << endl;
	
	//PrintData(carList);
	
	return 0;	

}
/*
void PrintData (RentalCar* carList)
{
	cout << "===========================================================" << endl;

	for (int i = 0; i < 10; i++)
	{	
		RentalCar thisCar = carList[i];
		
		cout << thisCar.year << " " << thisCar.make << " " << thisCar.model << endl;
		
		switch (thisCar.available)
		{
			case false:
				cout << "This car is not available. (Price: " << thisCar.price << ")" << endl;
				
				break;
			
			case true:
				cout << "This car is available for " << thisCar.price << " per day!" << endl;
				
				break;
			
			default:
				cout << "There was an error reading this car's availability." << endl;
				
				break;
		
		}
	
	}
	
	cout << "===========================================================" << endl;

}
*/
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
