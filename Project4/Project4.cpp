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
//Set to either 0 or 1 and recompile
const int DEBUG = 1;

void CrackTheCode (Pieces *pieces, int *keys, int onKey, int wordAmt, char *output);
void ReadDataInitial (ifstream &input, int &wordAmt, int &keyAmt);
void ReadData (ifstream &input, Pieces *pieces, int *keys, int wordAmt, int keyAmt);

//Utility Functions
int GetStringLength(char *str);
void CombineStrings (char *string1, char *string2); //Fufills the strConcat requirement
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
	int *keys = new int[keyAmount];
	
	ReadData(inputFile, cipherArray, keys, wordAmount, keyAmount);
	
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
	
	char *finalOutput = new char[1];
	
	for (int i = 0; i < keyAmount; i++)
	{
		CrackTheCode(cipherArray, keys, i, wordAmount, finalOutput);
	
	}
	
	cout << endl << finalOutput << endl;
	
	//Clear the heap below
	delete[] fileName;
	fileName = NULL;
	
	delete[] cipherArray;
	cipherArray = NULL;
	
	return 0;
	
}

void CrackTheCode (Pieces *pieces, int *keys, int onKey, int wordAmt, char *output)
{
	int *keyPtr = keys;
	int boundTracker = 0; //Cannot be greater than (wordAmt - 1)
	
	for (int i = 0; i < onKey; i++)
	{
		keyPtr++;
	
	}
	
	int keyValue = *keyPtr;
	
	Pieces *piecePtr = pieces;
	
	for (int i = 0; i < keyValue; i++)
	{
		piecePtr++;
		boundTracker++;
		
	}
	
	while ((*piecePtr).jump != 0)
	{
		int jumpVal = (*piecePtr).jump;
		
		if ((jumpVal + boundTracker) >= wordAmt) //Pointer goes out of bounds
		{
			int tempJump = (wordAmt - 1) - boundTracker;
			jumpVal -= tempJump;
			
			for (int i = 0; i < tempJump; i++)
			{
				piecePtr++;
			
			}
			
			piecePtr = pieces;
			boundTracker = 0;
			
			for (int i = 0; i < (jumpVal + 1); i++)
			{
				piecePtr++;
				boundTracker++;
			}
		
		} else
		{
			for (int i = 0; i < jumpVal; i++)
			{
				piecePtr++;
				boundTracker++;	
			}
		}
	}
	
	cout << (*piecePtr).word << " ";
	
	if (onKey == 0)
	{
		output = new char[GetStringLength((*piecePtr).word)];
		CopyString((*piecePtr).word, output, GetStringLength((*piecePtr).word));
		
	} else
	{
		CombineStrings(output, (*piecePtr).word);
		
	}
	
	return;

}

void ReadDataInitial (ifstream &input, int &wordAmt, int &keyAmt)
{
	input >> wordAmt;
	input >> keyAmt;
	
	return;
	
}

void ReadData (ifstream &input, Pieces *pieces, int *keys, int wordAmt, int keyAmt)
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
	
	for (int i = 0; i < keyAmt; i++)
	{
		input >> (*keys);
		
		keys++;
	
	}
	
	delete[] buffer;
	buffer = NULL;
	
	return;

}


//Utility Functions
int GetStringLength(char *str) //Fufills the strLen requirement
{
	int length = 0;
	
	for (length = 0; *str != '\0'; length++)
	{
		str++;
	
	}
	
	return (length + 1);

}

//puts all of 2 at the end of 1, so 1 should be the output string
void CombineStrings (char *string1, char *string2) //Fufills the strConcat requirement
{
	//Crying here
	
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
