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
	rear = -1;

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

	//Will also collect garbage
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

	front = -1;	//Unneeded, but why not
	rear = -1;	//^

}

Queue& Queue::operator=(const Queue& sentQueue)
{
	max = sentQueue.max;
	front = sentQueue.front;
	rear = sentQueue.rear;

	data = new int[max];

	int *thisTrav = data;
	int *sentTrav = sentQueue.data;


	//Will also collect garbage
	for (int i = 0; i < max; i++)
	{
		*thisTrav = *sentTrav;

		thisTrav++;
		sentTrav++;

	}

	thisTrav = NULL;
	sentTrav = NULL;

	return *this;

}

bool Queue::enqueue(int sentValue) //add
{
		if (full())
		{
			rear++;
			front++;
			
		} else
		{
			rear++;

		}

		int rearPos = rear % max;

		int *thisTrav = data;

		for (int i = 0; i < rearPos; i++)
		{
			thisTrav++;

		}

		*thisTrav = sentValue;

		thisTrav = NULL;

		return true;



}

bool Queue::dequeue(int& returnValue) //remove
{
	if (!empty())
	{
		int *thisTrav = data;
		int frontPos = front % max;

		for (int i = 0; i < frontPos; i++)
		{
			thisTrav++;

		}

		returnValue = *thisTrav;

		front++;

		thisTrav = NULL;

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
	int frontPos = front % max;
	int rearPos = rear % max;

	if ((rear - front) + 1 == max)
	{
		return true;

	} else
	{
		return false;

	}

}

bool Queue::clear()
{
	if (!empty())
	{
		front = 0;
		rear = -1;

		return true;

	} else
	{
		return false; //Already empty

	}

}

bool Queue::operator==(const Queue& sentQueue) const
{
	int thisFrontPos = front % max;
	int thisRearPos = rear % max;

	int thisDistance = 0;

	if (thisFrontPos > thisRearPos) //Front is ahead of rear
	{
		thisDistance = (thisRearPos + thisFrontPos) - 1;

	} else if (thisRearPos >= thisFrontPos) //Rear is ahead of front
	{
		thisDistance = (thisRearPos + thisFrontPos) + 1;

	}

	int sentFrontPos = sentQueue.front % sentQueue.max;
	int sentRearPos = sentQueue.rear % sentQueue.max;

	int sentDistance;

	if (sentFrontPos > sentRearPos) //Front is ahead of rear
	{
		sentDistance = (sentRearPos + sentFrontPos) - 1;

	} else if (sentRearPos >= sentFrontPos) //Rear is ahead of front
	{
		sentDistance = (sentRearPos + sentFrontPos) + 1;

	}

	if (thisDistance != sentDistance)
	{
		return false;

	} else //They are the same length
	{
		int *thisTrav = data;
		int *sentTrav = sentQueue.data;

		int thisOnSpot = front;
		int sentOnSpot = sentQueue.front;

		for (int i = 0; i < thisDistance; i++)
		{
			if (*thisTrav != *sentTrav) //Check
			{
				thisTrav = NULL;
				sentTrav = NULL;

				return false;

			}

			//Check pos for this queue
			if (thisOnSpot < (max - 1)) //In range
			{
				thisTrav++;
				thisOnSpot++;

			} else if (thisOnSpot == (max - 1)) //Final value, must wrap
			{
				thisTrav = data;
				thisOnSpot = 0;

			}

			//Check pos for sent queue
			if (sentOnSpot < (sentQueue.max - 1)) //In range
			{
				sentTrav++;
				sentOnSpot++;

			} else if (sentOnSpot == (sentQueue.max - 1)) //Final value, must wrap
			{
				sentTrav = sentQueue.data;
				sentOnSpot = 0;

			}

		}

		thisTrav = NULL;
		sentTrav = NULL;

		return true;

	}

}

ostream& operator<< (ostream& os, const Queue& sentQueue)
{
	int frontPos = sentQueue.front % sentQueue.max;
	int rearPos = sentQueue.rear % sentQueue.max;

	int distance = 0;

	if (frontPos > rearPos) //Front is ahead of rear
	{
		distance = (rearPos + frontPos) - 1;

	} else if (rearPos >= frontPos) //Rear is ahead of front
	{
		distance = (rearPos + frontPos) - 1;

	}

	int *thisTrav = sentQueue.data;

	for (int i = 0; i < frontPos; i++)
	{
		thisTrav++;

	}

	int onSpot = frontPos;

	os << "D(f/r): " << distance << " " << frontPos << "/" << rearPos << " [";

	for (int i = sentQueue.front; i <= sentQueue.rear; i++)
	{
		if (i == (sentQueue.rear)) //Final value
		{
			os << *thisTrav;

		} else
		{
			if (onSpot < (sentQueue.max - 1)) //In range
			{
				os << *thisTrav << ", ";

				thisTrav++;

				onSpot++;

			} else if (onSpot == (sentQueue.max - 1)) //Final value, must wrap
			{
				os << *thisTrav << ", ";

				thisTrav = sentQueue.data;

				onSpot = 0;

			}
		}
	}

	os << "]";

	return os;

}
