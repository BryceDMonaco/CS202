#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

int main ()
{
	String *words = new String[12];
	String *wordsTrav = words;
	
	ifstream input;
	input.open("strings");
	
	for (int i = 0; i < 12; i++)
	{
		char *buffer = new char[20];
		
		input >> buffer;
		
		(*wordsTrav).initialize(buffer);
		(*wordsTrav).print();
		(*wordsTrav).deallocate();
		
		wordsTrav++;
		
	} 
		
	return 0;

}
