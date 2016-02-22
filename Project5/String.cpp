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
		cout << "a" << endl; //Debug
		
		deallocate();
		
		cout << "b" << endl; //Debug
		
		char *inputTrav = string;
		int length = 0;
		
		for (length = 0; (*inputTrav) != '\0'; length++)
		{	
			cout << length << endl;
		
			length++;
			inputTrav++;
		
		}
		
		cout << "bb" << endl; //Debug
		
		length = (length/2); //For some reason the length is doubled ¯\_(ツ)_/¯
		
		wordLength = length;
		
		cout << "bbb" << endl; //Debug
		
		cout << length << "Length: " << wordLength << endl; //Debug
		
		cout << "bbbb" << endl; //Debug
		
		buffer = new char[length + 1];
		
		cout << "c" << endl; //Debug
		
		inputTrav = string;
		char *buffTrav = buffer;
		
		for (int i = 0; i <= length; i++)
		{
			*buffTrav = *inputTrav;
			
			buffTrav++;
			inputTrav++;
		
		} 
		
		cout << "d" << endl; //Debug
		
		buffTrav++;
		*buffTrav = '\0';
	
		cout << "e" << endl; //Debug
	
		inputTrav = NULL;
		buffTrav = NULL;
		
		return;
		
	}
	
	void String::deallocate ()
	{
		cout << "A" << endl; //Debug
		
		delete[] buffer;
		
		if (buffer != NULL)
		{
			buffer = NULL;
		
		}
		
		cout << "B" << endl; //Debug
		
		return;
		
	}
	
	void String::copy (const String& location) //Copy location into caller
	{
		//char *otherStr = *location;
		//int otherLength = (*otherStr).length();
		//int thisLength = wordLength;
		
		//char *str = location.buffer;
		cout << "ding" << endl;
		//location.print();
		cout << "-" << location.buffer << endl;
		
		initialize(location.buffer);	
		
		return;
		
	}
	
	int String::length ()
	{
		return wordLength;
	
	}
	
	void String::concat (const String& otherString)
	{
	
	
	}
	
	int String::compare (const String& otherString)
	{
		
	
	}
	
	void String::print ()
	{
		cout << buffer << endl;
		
		return;
	} 
