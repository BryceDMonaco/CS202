#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int GetStringLength(char *str);
void CopyString (char *string1, char *string2, int size); //Copy 1 into 2

int main ()
{
	String firstString;
	String secondString;
	String *words = new String[12];
	String *wordsTrav = words;
	
	int fileLength = 0;
	char *fileName, *tempName = new char[20];
	
	cout << "Enter the file name: ";
	cin >> tempName;
	
	fileLength = GetStringLength(tempName) + 1;
	
	cout << "boop" << tempName << endl;
	
	fileName = new char[fileLength];
	
	CopyString(tempName, fileName, fileLength);
	
	cout << "bop" << fileName << endl;
	
	ifstream input;
	input.open(fileName);
	
	cout << "bang" << endl;
	
	for (int i = 0; i < 12; i++)
	{
		char *buffer = new char[20];
		
		input >> buffer;
		
		if (i == 0)
		{
			cout << "First Instance: " << endl;
		
			wordsTrav = firstString;
			
			(*wordsTrav).initialize(buffer);
			(*wordsTrav).print();
			(*wordsTrav).deallocate();
		
		} else if (i == 1)
		{
			cout << "Second Instance: " << endl;
			
			wordsTrav = secondString;
			
			(*wordsTrav).initialize(buffer);
			(*wordsTrav).print();
			(*wordsTrav).deallocate();
		
		} else if (i > 1)
		{
			if (i == 2)
			{
				wordsTrav = words;
			
			}
			
			cout << "Array Instance " << (i - 2) << ": " << endl;
			
			(*wordsTrav).initialize(buffer);
			(*wordsTrav).print();
			(*wordsTrav).deallocate();
		
			wordsTrav++;
			
		}
		
		delete[] buffer;
		
	}
	
	cout << "Copying first to second" << endl;
	
	wordsTrav = secondString;
	
	(firstString).copy(secondString); 
	
	(firstString).print();
	(secondString).print();
	
	delete[] tempName;
	tempName = NULL;
	
	delete[] fileName;
	fileName = NULL;
	
	delete[] words;
	words = NULL;
	
	//delete firstString;
	//firstString = NULL;
	
	//delete secondString;
	//secondString = NULL;
	
	return 0;

}

//Utility Functions (Only for the file name)
int GetStringLength(char *str) //Fufills the strLen requirement
{
	int length = 0;
	
	for (length = 0; *str != '\0'; length++)
	{
		str++;
	
	}
	
	return length;

}


void CopyString (char *string1, char *string2, int size) //Copy 1 into 2
{
	for (int i = 0; i < size; i++)
	{	
		*(string2) = *(string1);
		
		string2++;
		string1++;
	}
	
	return;

}
