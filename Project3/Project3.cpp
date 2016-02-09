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
void ReadData (Agency *agencyList, char *fileName);
void CopyString (char *string1, char *string2);
void CharArrayToIntArray (char *charArr, int *intArr);

int main ()
{
	char inputFileName[MAX_STRING_SIZE];
		
	Agency agencyList[AGENCY_SIZE];
	
	cout << "Input the location data file name: ";
	cin >> inputFileName;
	
	char *finalChar = (inputFileName) + (MAX_STRING_SIZE - 1);
	//inputFileName[49] = '\0'; //Force a null character, just in case
	*finalChar = '\0'; //Should be the equiv. of line commented above
	
	ReadData(agencyList, inputFileName);
	
	return 0;
	
}

void ReadData (Agency *agencyList, char *fileName)
{
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
	
	char inputFileName[50];
	
	CopyString(fileName, inputFileName);
	
	cout << endl << inputFileName << endl;
	
	ifstream data;
	data.open(inputFileName);
	
	cout << "File opened" << endl;
	
	//for (int i = 0; i < AGENCY_SIZE; i++)
	//{
		Agency *thisAgency = (agencyList + 0);
		data >> (*thisAgency).name;
		
		char zipString[6];
		
		data >> zipString;
		
		//Debug Output
		cout << "Read in z string, converting to int array" << endl;
		
		CharArrayToIntArray(zipString, (*thisAgency).zip);
		
		//Debut Output
		cout << "Conversion complete. Outputting name." << endl;
		
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
		
		for (int i = 0; i < 5; i++)
		{
			int * zipPtr = (*thisAgency).zip;
			
			cout << *(zipPtr + i);
			
		}
		
		cout << endl;
		 
	//}
	
	return;
	
}

void CopyString (char *string1, char *string2) //Copy 1 into 2
{
	for (int i = 0; i < MAX_STRING_SIZE; i++)
	{	
		*(string2 + i) = *(string1 + i);
	
	}
	
	return;

}

void CharArrayToIntArray (char *charArr, int *intArr) //For zip
{
	for (int i = 0; i < 5; i++)
	{
		int thisChar = *(charArr + i) - '0';
		
		*(intArr + i) = thisChar;
	
	}
	
	return;

}
