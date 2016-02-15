//Quote: I do not fear computers, I fear the lack of them.

/*
	Bryce Monaco
	CS202-1102

*/

#include <iostream>
#include <fstream>

using namespace std;

struct Pieces
{
	char *word;
	int jump;

};

//A constant variable to enable/disable debug statements through the code
const int DEBUG = 1;

void ReadDataInitial (ifstream &input, int &wordAmt, int &keyAmt);
void ReadData (ifstream &input, Pieces *pieces, int wordAmt, int keyAmt);

//Utility Functions
int GetStringLength(char *str);
void CombineStrings (); //Fufills the strConcat requirement
void CopyString (char *string1, char *string2, int size); //Copy 1 into 2

int main ()
{
	ifstream inputFile;
	int wordAmount, keyAmount;
	
	char *fileName = new char[50];
	char *strPtr;
	
	cout << "Enter the cipher file name: ";
	cin >> fileName;
	
	strPtr = fileName;
	
	for (int i = 0; i < 50; i++)
	{
		strPtr++;
	}
	
	*strPtr = '\0';
	
	if (DEBUG)
	{
		cout << "Name: " << fileName << "(EOF MARKER)" << endl;
		
	}
	
	inputFile.open(fileName);
	
	//Read in the data from the file
	ReadDataInitial(inputFile, wordAmount, keyAmount);
	
	//***Cipher array declaration here***
	Pieces *cipherArray = new Pieces[wordAmount];
	
	ReadData(inputFile, cipherArray, wordAmount, keyAmount);
	
	inputFile.close();
	
	Pieces *piecePtr = cipherArray; 
	
	if (DEBUG)
	{
		for (int i = 0; i < wordAmount; i++)
		{
			cout << "Piece " << i << ": " << endl;
			cout << "\t" << (*piecePtr).word << " Jump: " << (*piecePtr).jump << endl;
		
			piecePtr++;
		
		}
	}
	
	//Clear the heap below
	delete[] fileName;
	fileName = NULL;
	
	delete[] cipherArray;
	cipherArray = NULL;
	
	return 0;
	
}

void ReadDataInitial (ifstream &input, int &wordAmt, int &keyAmt)
{
	input >> wordAmt;
	input >> keyAmt;
	
	return;
	
}

void ReadData (ifstream &input, Pieces *pieces, int wordAmt, int keyAmt)
{
	/*
	//trash is meant to clear the key and word amount
	int trash;
	
	input >> trash;
	input >> trash;
	*/
	
	char *buffer = new char[20];	
	
	for (int i = 0; i < wordAmt; i++)
	{
		input >> buffer;
		
		int buffLength = GetStringLength(buffer);
		
		if (DEBUG)
		{
			cout << "Read: " << buffer << endl;	
		
		}
		
		(*pieces).word = new char[buffLength]; //Dynamically size the word
		
		CopyString(buffer, (*pieces).word, buffLength); //Copy the buffer into the piece
		
		input >> (*pieces).jump; //Read in the jump value
		
		pieces++;
		
	}
	
	delete[] buffer;
	buffer = NULL;
	
	return;

}


//Utility Functions
int GetStringLength(char *str)
{
	int length = 0;
	
	for (length = 0; *str != '\0'; length++)
	{
		str++;
	
	}
	
	return (length + 1);

}

void CombineStrings () //Fufills the strConcat requirement
{

	return;
	
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
