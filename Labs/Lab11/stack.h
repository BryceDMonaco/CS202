#include <iostream>

using namespace std;

template<class T>
class Stack
{
        public:
                Stack(int = 10);
                Stack(const Stack<T>&);
                ~Stack();
                Stack& operator=(const Stack<T>&);
                bool push(T); //Inserts
                bool pop(T&); //Removes
                bool empty() const; //Checks if empty
                bool full() const; //Checks if full
                bool clear(); //clears data
		bool operator==(const Stack<T>&) const;
                
                template<typename U>
                friend ostream& operator<<(ostream&, const Stack<U>&);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                T* data;
                
};

//Constructors
template<typename T>
Stack<T>::Stack (int sentMax)
{
	max = sentMax;
	data = new T[max];
	top = 1;
	actual = 0;

}

template<typename T>
Stack<T>::Stack (const Stack<T>& sentStack)
{
	max = sentStack.max;
	top = sentStack.top;
	actual = sentStack.actual;
	
	data = new T[max];
	
	T *dataTrav = data;
	T *sentTrav = sentStack.data;
	
	for (int i = 0; i < max; i++)
	{
		*dataTrav = *sentTrav;
		
		dataTrav++;
		sentTrav++;
	
	}
	
	dataTrav = NULL;
	sentTrav = NULL;
	
}

template<typename T>
Stack<T>::~Stack ()
{
	delete[] data;
	data = NULL;

}

//Top should stay with the first value
//Replaces actual

template<typename T>
Stack<T>& Stack<T>::operator= (const Stack<T>& sentStack)
{
	Stack *tempStack = new Stack;
	
	(*tempStack).max = sentStack.max;
	(*tempStack).top = sentStack.top;
	(*tempStack).actual = sentStack.actual;
	
	delete[] (*tempStack).data;
	
	(*tempStack).data = new T[max];
	
	T *dataTrav = (*tempStack).data;
	T *sentTrav = sentStack.data;
	
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
template<typename T>
bool Stack<T>::push (T sentData) //Inserts
{
	
	if (top != max) //Stack is not full
	{
		T *dataTrav = data;
		T *nextTrav = data;
	
		nextTrav++;
	
		int onIndex = 0;	
	
		for (int i = 0; i < (top - 1); i++)
		{
			dataTrav++;
		
		}
	
		//dataTrav = data;
	
		*dataTrav = sentData;
		
		//cout << "Set: " << sentData << endl;
		
		top++;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
		
	} else if (top == max) //Stack is full
	{
		return false;
	
	}

}

template<typename T>
bool Stack<T>::pop (T& sentData) //Remove
{
	if (top != 0)
	{
		T *dataTrav = data;
		T *nextTrav = data;
		
		nextTrav++;
	
		int onIndex = 0;	
	
	
		//Position the pointers so that they can move backwards
		for (int i = 0; i < (top - 2); i++)
		{
			dataTrav++;
		
		}
		
		sentData = *dataTrav;
	
		top--;
	
		dataTrav = NULL;
		nextTrav = NULL;
		
		return true;
	
	} else if (top == 0)
	{
		return false;
	
	}

}

template<typename T>
bool Stack<T>::empty () const
{
	if (top == 0)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

template<typename T>
bool Stack<T>::full () const
{
	if (top == max)
	{
		return true;
	
	} else
	{
		return false;
	
	}

}

template<typename T>
bool Stack<T>::clear ()
{
	if (top == 0)
	{
		return false; //Stack is already clear
	
	} else
	{
		delete[] data;
		data = new T[max];
		
		top = 0;
		
		return true;
	
	}

}

template<typename T>
bool Stack<T>::operator== (const Stack<T>& sentStack) const
{
	if ((max == sentStack.max) && (actual == sentStack.actual) && (top == sentStack.top))
	{
		T *dataTrav = data;
		T *sentTrav = sentStack.data;
		
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

template<typename U>
ostream& operator<< (ostream& os, const Stack<U>& sentStack)
{
	os << "[";
	
	U *dataTrav = sentStack.data;
	
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

