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
Stack::Stack (int sentMax)
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
	//actual = sentStack.actual;
	actual = 0;
	
	data = new char[max];
	
	char *sentTrav = sentStack.data;
	
	for (int i = 0; i < sentStack.actual; i++)
	{	
		//push(*sentTrav);
		
		sentTrav++;
		
	}
	
		sentTrav--;
	
	for (int i = 0; i <= (sentStack.actual + 1); i++)
	{
		push(*sentTrav);
		
		sentTrav--;
	
	}
	
	//dataTrav = NULL;
	sentTrav = NULL;
	
}

Stack::~Stack ()
{
	delete[] data;
	data = NULL;

}

Stack& Stack::operator= (const Stack& sentStack)
{
	Stack *tempStack = new Stack(sentStack);
	
	/*
	max = sentStack.max;
	top = 0;
	//actual = sentStack.actual;
	actual = 0;
	
	data = new char[max];
	
	char *sentTrav = sentStack.data;
	
	for (int i = 0; i < sentStack.actual; i++)
	{	
		//push(*sentTrav);
		
		sentTrav++;
		
	}
	
		sentTrav--;
	
	for (int i = 0; i <= (sentStack.actual + 1); i++)
	{
		push(*sentTrav);
		
		sentTrav--;
	
	}
	
	//dataTrav = NULL;
	sentTrav = NULL;
	*/
	return *tempStack;
	
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
	
		cout << "Actual: " << actual << endl;
	
		//Position the pointers so that they can move backwards
		for (int i = 0; i < (actual); i++)
		{
			dataTrav++;
			nextTrav++;
		
		}
	
		//Copies values down an array so that 123XX becomes 1123X (X is garbage)
		for (int i = 0; i <= (actual); i++)
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
	
		for (int i = 0; i <= actual; i++)
		{
			*dataTrav = *nextTrav;
			
			dataTrav++;
			nextTrav++;
		
		}
	
		dataTrav = data;
	
		actual--;
	
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
	if ((max == sentStack.max) && (actual == sentStack.actual) && (top == sentStack.top))
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

ostream& operator<< (ostream& os, const Stack& sentStack)
{
	os << "[";
	
	char *dataTrav = sentStack.data;
	
	for (int i = 0; i < sentStack.actual; i++)
	{
		if (i == (sentStack.actual - 1))
		{
			os << *dataTrav;
		
		} else
		{
			os << *dataTrav << ", ";
		
		}
		
		dataTrav++;
	
	}
	
	os << "]";
	
	dataTrav = NULL;
	
	return os;	
	
}
