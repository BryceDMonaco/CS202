/*
#include <iostream>

using namespace std;

class Queue
{
	public:
		Queue(int = 10);
		Queue(const Queue&);
		~Queue();
		Queue& operator=(const Queue&);
		bool enqueue(int); //add
		bool dequeue(int&); //remove
		bool empty() const;
		bool full() const;
		bool clear();
		bool operator==(const Queue&) const;
		friend ostream& operator<<(ostream&, const Queue&);
	private:
		int max;
		int front;
		int rear;
		int *data;
		
};
*/

#include <iostream>
#include "queue.h"

using namespace std;

//Constructors and Destructor
Queue::Queue (int size)
{
	max = size;
	front = 0;
	rear= -1;
	data = new int[max];

}

Queue::Queue (const Queue& sentQueue)
{
	max = sentQueue.max;
	front = sentQueue.front;
	rear = sentQueue.rear;

	data = new int[max];

	int *thisTrav = data;
	int *sentTrav = sentQueue.data;

	for (int i = 0; i < max; i++)
	{
		*thisTrav = *sentTrav;

		thisTrav++;
		sentTrav++;

	}

	thisTrav = NULL;
	sentTrav = NULL;

}

Queue::~Queue ()
{
	delete[] data;
	data = NULL;

}

//Functions
Queue& Queue::operator=(const Queue& sentQueue)
{
	max = sentQueue.max;
	front = sentQueue.front;
	rear = sentQueue.rear;

	delete[] data;

	data = new int[max];

	int *thisTrav = data;
	int *sentTrav = sentQueue.data;

	for (int i = 0; i < max; i++)
	{
		*thisTrav = *sentTrav; //Will also copy in garbage

		thisTrav++;
		sentTrav++;

	}

	thisTrav = NULL;
	sentTrav = NULL;

	return *this;

}

bool Queue::enqueue(int sentValue) //Insert
{
	if (rear != (max - 1))
	{
		rear++:

		int *thisTrav = data;

		for (int i = 0; i < rear; i++)
		{
			thisTrav++;

		}

		*thisTrav = sentValue;

		thisTrav = NULL;

		return true;

	} else
	{
		return false;

	}
}

bool Queue::dequeue(int& returnValue) //Remove, front is always at zero
{
	if (rear != -1)
	{
		int *thisTrav = data;
		int *nextTrav = data;

		nextTrav++;

		returnValue = *thisTrav;

		rear--;

		for (int i = 0; i < rear; i++)
		{
			*thisTrav = *nextTrav;

			*thisTrav++;
			*nextTrav++;

		}

		thisTrav = NULL;
		nextTrav = NULL;

		return true;

	} else
	{
		return false;

	}
}

bool Queue::empty() const
{
	if (rear == -1)
	{
		return true;

	} else
	{
		return false;

	}
}

bool Queue::full() const
{
	if (rear == 9)
	{
		return true;

	} else
	{
		return false;

	}

}

bool Queue::clear()
{
	delete[] data;

	data = new int[max];

	return true;

}

bool Queue::operator==(const Queue& sentQueue) const
{
	if (max == sentQueue.max && top == sentQueue.top && rear == sentQueue.rear)
	{
		int *thisTrav = data;
		int *sentTrav = sentTrav.data;

		for (int i = 0; i < max; i++)
		{
			if (*thisTrav != *sentTrav)
			{
				thisTrav = NULL;
				sentTrav = NULL;

				return false;

			}

			thisTrav++;
			sentTrav++;

		}

		thisTrav = NULL;
		sentTrav = NULL;

		return true;

	} else
	{
		return false;

	}
}

ostream& operator<< (ostream& os, const Queue& sentQueue)
{
	os << "[";
	
	int *thisTrav = sentQueue.data;
	
	for (int i = 0; i < (sentQueue.rear + 1); i++)
	{
		if (i == sentQueue.rear)
		{
			os << *thisTrav;

		} else
		{
			os << *thisTrav << ", ";

		}
		
		thisTrav++;
	
	}
	
	os << "]";
	
	thisTrav = NULL;
	
	return os;	
	
}

