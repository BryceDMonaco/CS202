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
		cout << "a" << endl;
		
		deallocate();
		
		cout << "b" << endl;
		
		char *inputTrav = string;
		int length = 0;
		
		for (length = 0; (*inputTrav) != '\0'; length++)
		{	
			length++;
			inputTrav++;
		
		}
		
		length = (length/2);
		
		wordLength = length;
		
		cout << length << "Length: " << wordLength << endl;
		
		buffer = new char[length + 1];
		
		cout << "c" << endl;
		
		inputTrav = string;
		char *buffTrav = buffer;
		
		for (int i = 0; i <= length; i++)
		{
			*buffTrav = *inputTrav;
			
			buffTrav++;
			inputTrav++;
		
		} 
		
		cout << "d" << endl;
		
		buffTrav++;
		*buffTrav = '\0';
	
		cout << "e" << endl;
	
		inputTrav = NULL;
		buffTrav = NULL;
		
		return;
		
	}
	
	void String::deallocate ()
	{
		cout << "A" << endl;
		
		//delete buffer;
		
		if (buffer != NULL)
		{
			buffer = NULL;
		
		}
		
		cout << "B" << endl;
		
		return;
		
	}
	
	void String::copy (const String& location)
	{
	
	
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
	
	} 
