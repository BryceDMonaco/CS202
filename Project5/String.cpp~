#include <iostream>

using namespace std;


class String
{
public:
	void initialize(char *);
	void deallocate();

	void copy(const String&);
	int length();
	void concat(const String&);
	int compare(const String&);

	void print();

private:
	char * buffer;
	int wordLength;
};

	void String::initialize (char *string)
	{
		//cout << "a" << endl; //Debug
		
		deallocate();
		
		//cout << "b" << endl; //Debug
		
		char *inputTrav = string;
		int length = 0;
		
		for (length = 0; (*inputTrav) != '\0'; length++)
		{	
			//cout << length << endl;
		
			//length++;
			inputTrav++;
		
		}
		
		//cout << "bb" << endl; //Debug
		
		//length = (length/2); //For some reason the length is doubled ¯\_(ツ)_/¯ (fixed, thanks, Eric)
		
		wordLength = length;
		
		//cout << "bbb" << endl; //Debug
		
		//cout << length << "Length: " << wordLength << endl; //Debug
		
		//cout << "bbbb" << endl; //Debug
		
		buffer = new char[length + 1];
		
		//cout << "c" << endl; //Debug
		
		inputTrav = string;
		char *buffTrav = buffer;
		
		for (int i = 0; i <= length; i++)
		{
			*buffTrav = *inputTrav;
			
			buffTrav++;
			inputTrav++;
		
		} 
		
		//cout << "d" << endl; //Debug
		
		buffTrav++;
		*buffTrav = '\0';
	
		//cout << "e" << endl; //Debug
		
		//cout << "Read in: " << buffer << endl;
		
		inputTrav = NULL;
		buffTrav = NULL;
		
		return;
		
	}
	
	void String::deallocate ()
	{
		//cout << "A" << endl; //Debug
		
		delete[] buffer;
		
		if (buffer != NULL)
		{
			buffer = NULL;
		
		}
		
		//cout << "B" << endl; //Debug
		
		return;
		
	}
	
	void String::copy (const String& location) //Copy location into caller
	{
		//cout << "ding" << endl;
		//cout << "-" << location.buffer << endl;
		
		//initialize(location.buffer);	
		
		deallocate();
		
		int length = 0;
		char *locPtr = location.buffer;
		
		for (int i = 0; *locPtr != '\0'; locPtr++)
		{
			length++;
		
		}
		
		wordLength = length;
		buffer = new char[wordLength + 1];
		char *buffPtr = buffer;
		locPtr = location.buffer;
		
		for (int i = 0; i < (length + 1); i++)
		{
			*buffPtr = *locPtr;
			
			buffPtr++;
			locPtr++;
			
		}
		
		buffPtr++;
		*buffPtr = '\0';
		
		buffPtr = NULL;
		locPtr = NULL;
		
		return;
		
	}
	
	int String::length ()
	{
		return wordLength;
	
	}
	
	void String::concat (const String& otherString)
	{
		int thisLength = length(), passedLength = 0;
		char *passedPtr = otherString.buffer;
		
		for (int i = 0; *passedPtr != '\0'; passedPtr++)
		{
			passedLength++;
		
		}
		
		//cout << "thisLength/passedLength: " << thisLength << "/" << passedLength << endl;
		
		int newLength = thisLength + passedLength;
		wordLength = newLength;
		
		//cout << "New length: " << newLength << endl;
		
		//cache the current buffer before it is deallocated
		char *oldBuff = new char[thisLength + 1];
		char *oldPtr = oldBuff;
		char *buffPtr = buffer;
		
		for (int i = 0; i < thisLength; i++)
		{
			*oldPtr = *buffPtr;
			
			oldPtr++;
			buffPtr++;
			
		}
		
		oldPtr++;
		*oldPtr = '\0';
		
		deallocate();
		
		buffer = new char[newLength + 1];
		buffPtr = buffer;
		oldPtr = oldBuff;
		passedPtr = otherString.buffer;
		
		//Copy in the original word
		for (int i = 0; i < thisLength; i++)
		{
			*buffPtr = *oldPtr;
			
			oldPtr++;
			buffPtr++;
			
		}
		
		//Copy in the second word
		for (int i = 0; i < passedLength; i++)
		{
			*buffPtr = *passedPtr;
			
			passedPtr++;
			buffPtr++;
			
		}
		
		buffPtr++;
		*buffPtr = '\0';
		
		delete[] oldBuff;
		oldBuff = NULL;
		buffPtr = NULL;
		passedPtr = NULL;
		
		return;
		
	}
	
	int String::compare (const String& otherString)
	{
		int thisLength = length(), passedLength = 0;
		char *passedPtr = otherString.buffer;
		
		for (int i = 0; *passedPtr != '\0'; passedPtr++)
		{
			passedLength++;
		
		}
		
		char *buffPtr = buffer;
		passedPtr = otherString.buffer;
			
		for (int i = 0; i < thisLength; i++)
		{
			if (*buffPtr != *passedPtr) //The are not the same
			{
				if (*buffPtr < *passedPtr)
				{
					buffPtr = NULL;
					passedPtr = NULL;
					
					return -1;
				
				} else if (*buffPtr > *passedPtr)
				{
					buffPtr = NULL;
					passedPtr = NULL;
					
					return 1;
				
				}
				
			}
			
			buffPtr++;
			passedPtr++;
			
		}
		
		buffPtr = NULL;
		passedPtr = NULL;
		
		return 0; //The loop was never broken, so they must be the same.
		
	}
	
	void String::print ()
	{
		cout << buffer << endl;
		
		return;
	} 
