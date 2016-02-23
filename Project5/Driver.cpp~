//THE MAKEFILE WILL GIVE A COMPILE WARNING ABOUT A C-STYLE STRING, PLEASE IGNORE

#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int GetStringLength(char *str);
void CopyString (char *string1, char *string2, int size); //Copy 1 into 2

int main ()
{
	String *firstString = new String;
	String *secondString = new String;
	String *words = new String[12];
	String *wordsTrav = words;
	
	int fileLength = 0;
	char *fileName, *tempName = new char[20];
	
	cout << "Enter the file name: ";
	cin >> tempName;
	
	fileLength = GetStringLength(tempName) + 1;
	
	//cout << "boop" << tempName << endl;
	
	fileName = new char[fileLength];
	
	CopyString(tempName, fileName, fileLength);
	
	//cout << "bop" << fileName << endl;
	
	ifstream input;
	input.open(fileName);
	
	//cout << "bang" << endl;
	
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
			//(*wordsTrav).deallocate();
		
		} else if (i == 1)
		{
			cout << "Second Instance: " << endl;
			
			wordsTrav = secondString;
			
			(*wordsTrav).initialize(buffer);
			(*wordsTrav).print();
			//(*wordsTrav).deallocate();
		
		} else if (i > 1)
		{
			if (i == 2)
			{
				wordsTrav = words;
			
			}
			
			cout << "Array Instance " << (i - 2) << ": " << endl;
			
			(*wordsTrav).initialize(buffer);
			(*wordsTrav).print();
			//(*wordsTrav).deallocate();
		
			wordsTrav++;
			
		}
		
		delete[] buffer;
		
	}
	
	wordsTrav = words;
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Copy Function: " << endl;
	cout << "Copying the second instance to the first..." << endl;
	
	cout << "The calling string's buffer is: ";
	(*firstString).print();
	
	cout << "The argument string's buffer is: ";
	(*secondString).print();
	
	//wordsTrav = secondString;
	
	(*firstString).copy(*secondString); 
	
	cout << "After copy(): " << endl;
	
	cout << "The calling string's buffer is now: ";
	(*firstString).print();
	
	cout << "The argument string's buffer is now: ";
	(*secondString).print();
	
	cout << endl << "Now the second array entry will be copied to the first instance..." << endl;
	
	for (int i = 0; i < 2; i++)
	{
		wordsTrav++;
	
	}
	
	cout << "The calling string's buffer is: ";
	(*firstString).print();
	
	cout << "The argument string's buffer is: ";
	(*wordsTrav).print();
	
	//wordsTrav = secondString;
	
	(*firstString).copy(*wordsTrav); 
	
	cout << "After copy(): " << endl;
	
	cout << "The calling string's buffer is now: ";
	(*firstString).print();
	
	cout << "The argument string's buffer is now: ";
	(*wordsTrav).print();
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Concat Function: " << endl;
	
	cout << "The second instance will be concated to the first instance..." << endl;
	cout << "Before concat, the first instance buffer was: ";
	(*firstString).print();
	cout << "And the second instance buffer is: ";
	(*secondString).print();
	
	(*firstString).concat(*secondString);
	
	cout << "The first instance buffer is now: ";
	(*firstString).print();
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Compare Function: " << endl;
	cout << "Comparing the second instance to the second array entry..." << endl;
	
	cout << "The second instance is: ";
	(*secondString).print();
	
	wordsTrav = words;
	wordsTrav++;
	
	cout << "The second array entry is: ";
	(*wordsTrav).print();
	
	cout << "Comparing..." << endl;
	
	int compReturn = (*wordsTrav).compare(*secondString);
	
	cout << "The compare() function returned " << compReturn << " so ";
	
	if (compReturn == -1)
	{
		cout << "the second array entry is less than the second instance." << endl;
	
	} else if (compReturn == 0)
	{
		cout << "the second array entry and the second instance are equal." << endl;
	
	} else if (compReturn == 1)
	{
		cout << "the second array entry is greater than the second instance." << endl;
	
	} else
	{
		cout << "(Error comparing)" << endl;
	
	}
	
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "Deallocating..." << endl;
	
	//Complete deallocation
	(*firstString).deallocate();
	(*secondString).deallocate();
	
	wordsTrav = words;
	
	for (int i = 0; i < 10; i++)
	{
		(*wordsTrav).deallocate();
		
		wordsTrav++;
	
	}
	
	delete[] tempName;
	tempName = NULL;
	
	delete[] fileName;
	fileName = NULL;
	
	delete[] words;
	words = NULL;
	
	delete firstString;
	firstString = NULL;
	
	delete secondString;
	secondString = NULL;
	
	cout << "All strings and pointers successfully deallocated!" << endl;
	
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
