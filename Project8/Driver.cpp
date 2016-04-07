#include "stackN.h"
#include <iostream>

using namespace std;

int main ()
{
	Stack testStack;
	
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter stack item " << i << ": ";
		
		char temp;
		
		cin >> temp;
		
		testStack.push(temp);
		
		if (!testStack.full())
		{
			cout << "Stack is still not full." << endl;
			cout << "Stack Data: " << testStack << endl;
		}
	}
	
	cout << "Empty: " << testStack.empty() << " Full: " << testStack.full() << endl;
	
	Stack tempStack(testStack);
	
	tempStack = testStack;
	
	cout << "Test: " << testStack << endl << "Temp: " << tempStack << endl;
	
	while (!tempStack.empty())
	{
		char temp;
		
		tempStack.pop(temp);
		
		cout << temp << " " << endl << "Now: " << tempStack << endl;
		
	}
	
	cout << testStack << endl;
	
	return 0;

}
