#include "stack.h"
#include <iostream>

using namespace std;

/*
	#include <iostream>

using namespace std;

class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack&);
                ~Stack();
                Stack& operator=(const Stack&);
                bool push(char); //Insert
                bool pop(char&); //Remove
                bool empty() const;
                bool full() const;
                bool clear();
		bool operator==(const Stack&) const;
                friend ostream& operator<<(ostream&, const Stack&);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                char* data;
};

*/

//Constructors
Stack::Stack (int sentMax = 10)
{
	max = sentMax;
	data = new char[max];
	top = 0;
	actual = 0;

}

Stack::Stack (const Stack& sentStack)
{
	max = sentStack.max;
	top = 0;
	actual = sentStack.actual;
	
	data = new char[max];
	
	char *dataTrav = data;
	char *sentTrav = sentStack.data;
	
	for (int i = 0; i < max; i++)
	{
		*dataTrav = *sentTrav;
		
		dataTrav++;
		sentTrav++;
	
	}
	
	dataTrav = NULL;
	sentTrav = NULL;
	
}

Stack::~Stack ()
{
	delete[] data;
	data = NULL;

}

Stack& Stack::operator= (const Stack& sentStack)
{
	Stack tempStack;
	
	tempStack.max = sentStack.max;
	tempStack.top = 0;
	tempStack.actual = sentStack.actual;
	
	delete[] tempStack.data;
	
	tempStack.data = new char[max];
	
	char *dataTrav = tempStack.data;
	char *sentTrav = sentStack.data;
	
	for (int i = 0; i < max; i++)
	{
		*dataTrav = *sentTrav;
		
		dataTrav++;
		sentTrav++;
	
	}
	
	dataTrav = NULL;
	sentTrav = NULL;
	
	return tempStack;
	
}

//Functions
bool Stack::push (char sentChar) //Inserts
{
	if (actual != max) //Stack is not full
	{
		char *dataTrav = data;
		char *nextTrav = data;
	
		nextTrav++;
	
		int onIndex = 0;	
	
	
		//Position the pointers so that they can move backwards
		for (int i = 0; i < (actual - 1); i++)
		{
			dataTrav++;
			nextTrav++;
		
		}
	
		//Copies values down an array so that 123XX becomes 1123X (X is garbage)
		for (int i = 0; i < (actual - 1); i++)
		{
			*nextTrav = *dataTrav;
		
			dataTrav--;
			nextTrav--;
	
		}
	
		dataTrav = data;
	
		*dataTrav = sentChar;
	
		actual++;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
		
	} else if (actual == max) //Stack is full
	{
		return false;
	
	}	
}

bool Stack::pop (char& sentChar) //Remove
{
	if (actual != 0)
	{
		char *dataTrav = data;
		char *nextTrav = data;
		
		sentChar = *dataTrav;
		
		nextTrav++;
	
		int onIndex = 0;	
	
	
		//Position the pointers so that they can move backwards
		for (int i = 0; i < (actual - 1); i++)
		{
			dataTrav++;
			nextTrav++;
		
		}
	
		//Copies values down an array so that 123XX becomes 1123X (X is garbage)
		for (int i = 0; i < (actual - 1); i++)
		{
			*dataTrav = *nextTrav;
		
			dataTrav--;
			nextTrav--;
	
		}
	
		dataTrav = data;
	
		actual++;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
	
	} else if (actual == 0)
	{
		return false;
	
	}

}

bool Stack::empty () const
{
	if (actual == 0)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

bool Stack::full () const
{
	if (actual == max)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

bool Stack::clear ()
{
	if (actual == 0)
	{
		return false; //Stack is already clear
	
	} else
	{
		delete[] data;
		data = new char[max];
		
		actual = 0;
		
		return true;
	
	}

}

bool Stack::operator== (const Stack& sentStack) const
{
	if ((max == sentStack.max) && (actual == sentStack.max) && (top == sentStack.top))
	{
		char *dataTrav = data;
		char *sentTrav = sentStack.data;
		
		for (int i = 0; i < actual; i++)
		{
			if (*dataTrav != *sentTrav)
			{
				dataTrav = NULL;
				sentTrav = NULL;
				
				return false;
			
			}
			
			dataTrav++;
			sentTrav++;
		
		}
		
		dataTrav = NULL;
		sentTrav = NULL;	
			
		return true;
	
	} else
	{
		return false;
	
	}
}

friend ostream& operator<< (ostream& os, const Stack& sentStack)
{
	os << "[";
	
	char *dataTrav = data;
	
	for (int i = 0; i < actual; i++)
	{
		if (i == (actual - 1))
		{
			os << *dataTrav;
		
		} else
		{
			os << *dataTrav << ", ";
		
		}
	
	}
	
	os << "]";
	
	dataTrav = NULL;
	
	return os;	
	
}
