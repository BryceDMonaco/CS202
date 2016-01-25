/*

	Bryce Monaco
	CS202-1102
	
	Project 1

*/

#include <iostream>
#include <iomanip> //Might end up not being used
#include <fstream>

using namespace std;

int main ()
{
	int nameAmount;
	
	char inputFileName[24];
	
	cout << "Input the name of the file to be read (Include the extension, ";
	cout << "must be less than 22 characters): ";
	
	cin >> inputFileName;
	
	inputFileName[23] = '\0'; //To ensure null terminator
	
	cout << "Input the number of names: ";
	
	cin >> nameAmount;
	
	char namesUnsorted[nameAmount][24];
	char namesSorted[nameAmount][24];
	
	ifstream inputFile;
	
	inputFile.open(inputFileName);
	
	for (int i = 0; i < nameAmount; i++)
	{
	
		inputFile.getline(namesUnsorted[i], 24, '\n');
		
		namesUnsorted[i][23] = '\0';
		
	}
	
	inputFile.close();
	
	cout << "Found the following entries in " << inputFileName << ":" << endl;
	
	for (int i = 0; i < nameAmount; i++)
	{
	
		cout << namesUnsorted[i] << endl;
	
	}
	
	/*
		
		For loop to run once for every spot in the sorted list
			For loop to run through every letter of the alphabet, starting at the next character
			(So if the last iteration found a name starting with C then the next would start
			at D) Should compare the first char of each array entry to its current char and
			increment a number to count the number of matches (in case multiple names with
			the same letter are found)
				(If multiple matches are found) For loop to compare the next letters in a match
				to sort, and should increment the main for loop for the amount of entries that
				were added to prevent overwriting
	
	*/
	
	char lastLetter = 'A'; 	//Char values A-Z = [65, 90], a-z = [97, 122]
							//To go from lower to upper, subtract 32
	
	return 0;
	
}

void CopyString (char string1[24], char string2[24])
{
	for (int i = 0; i < 24; i++)
	{
		string2[i] = string1[i];
	
	}

	return;
	
}


