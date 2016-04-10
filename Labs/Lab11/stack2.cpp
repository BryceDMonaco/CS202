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
                bool push(char); //Inserts
                bool pop(char&); //Removes
                bool empty() const; //Checks if empty
                bool full() const; //Checks if full
                bool clear(); //clears data
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
Stack::Stack (int sentMax)
{
	max = sentMax;
	data = new char[max];
	top = 1;
	actual = 0;

}

Stack::Stack (const Stack& sentStack)
{
	max = sentStack.max;
	top = sentStack.top;
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

//Top should stay with the first value
//Replaces actual

Stack& Stack::operator= (const Stack& sentStack)
{
	Stack *tempStack = new Stack;
	
	(*tempStack).max = sentStack.max;
	(*tempStack).top = sentStack.top;
	(*tempStack).actual = sentStack.actual;
	
	delete[] (*tempStack).data;
	
	(*tempStack).data = new char[max];
	
	char *dataTrav = (*tempStack).data;
	char *sentTrav = sentStack.data;
	
	for (int i = 0; i < max; i++)
	{
		*dataTrav = *sentTrav;
		
		dataTrav++;
		sentTrav++;
	
	}
	
	dataTrav = NULL;
	sentTrav = NULL;
	
	return *tempStack;
	
}

//Functions
bool Stack::push (char sentChar) //Inserts
{
	
	if (top != max) //Stack is not full
	{
		char *dataTrav = data;
		char *nextTrav = data;
	
		nextTrav++;
	
		int onIndex = 0;	
	
		for (int i = 0; i < (top - 1); i++)
		{
			dataTrav++;
		
		}
	
		//dataTrav = data;
	
		*dataTrav = sentChar;
		
		cout << "Set: " << sentChar << endl;
		
		top++;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
		
	} else if (top == max) //Stack is full
	{
		return false;
	
	}

}

bool Stack::pop (char& sentChar) //Remove
{
	if (top != 0)
	{
		char *dataTrav = data;
		char *nextTrav = data;
		
		nextTrav++;
	
		int onIndex = 0;	
	
	
		//Position the pointers so that they can move backwards
		for (int i = 0; i < (top - 2); i++)
		{
			dataTrav++;
		
		}
		
		sentChar = *dataTrav;
	
		top--;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
	
	} else if (top == 0)
	{
		return false;
	
	}

}

bool Stack::empty () const
{
	if (top == 0)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

bool Stack::full () const
{
	if (top == max)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

bool Stack::clear ()
{
	if (top == 0)
	{
		return false; //Stack is already clear
	
	} else
	{
		delete[] data;
		data = new char[max];
		
		top = 0;
		
		return true;
	
	}

}

bool Stack::operator== (const Stack& sentStack) const
{
	if ((max == sentStack.max) && (actual == sentStack.actual) && (top == sentStack.top))
	{
		char *dataTrav = data;
		char *sentTrav = sentStack.data;
		
		for (int i = 0; i < top; i++)
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

ostream& operator<< (ostream& os, const Stack& sentStack)
{
	os << "[";
	
	char *dataTrav = sentStack.data;
	
	for (int i = 1; i <= (sentStack.top); i++)
	{
		if (i == (sentStack.top))
		{
			os << *dataTrav;
		
		} else
		{
			os << *dataTrav << ", ";
		
		}
		
		dataTrav++;
	
	}
	
	os << "]";
	
	os << " Top: " << sentStack.top;
	
	dataTrav = NULL;
	
	return os;	
	
}
