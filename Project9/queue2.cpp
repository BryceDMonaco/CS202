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
	front = -1;
	rear = 0;

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

