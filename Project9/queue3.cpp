/*
#include <iostream>

using namespace std;

class Queue;

class Node{
	private:
		Node(int, Node*);
		int data;
		Node* next;
		friend class Queue;
		friend ostream& operator<<(ostream&, const Queue&);
};

class Queue{
	public:
		Queue(int = 0);
		Queue(const Queue&);
  		~Queue();
		Queue& operator=(const Queue&);
		bool enqueue(int);
		bool dequeue(int&);
		bool empty() const;
		bool full() const;
		bool clear();
		bool operator==(const Queue&) const;
		friend ostream& operator<<(ostream&, const Queue&);
	private:
		Node* front;
		Node* rear;
};
*/

#include <iostream>
#include "queueN.h"

using namespace std;

Node::Node (int value, Node *nextNode)
{
	data = value;

	next = nextNode;

}

Queue::Queue (int size)
{
	//Size is theoretically infinite, so it can be ignored

	front = NULL;
	rear = NULL;

}

Queue::Queue (const Queue& sentQueue)
{
	front = NULL;
	rear = NULL;

	Node *sentNode = sentQueue.front;
	Node *thisNode = front;
	//Node *lastNode = front;


	if (sentNode != NULL)
	{

		*thisNode = new Node((*sentNode).data, NULL);

		while (sentNode != NULL)
		{
			sentNode = (*sentNode).next;

			thisNode = (*thisNode).next;

			*thisNode = new Node((*sentNode).data, NULL);

		}
	}

	sentNode = NULL;
	thisNode = NULL;
}

Queue::~Queue ()
{
	delete front;
	front = NULL;
	rear = NULL;
}

Queue& Queue::operator= (const Queue& sentQueue)
{
	delete front;

	front = NULL;
	rear = NULL;

	Node *sentNode = sentQueue.front;
	Node *thisNode = front;
	//Node *lastNode = front;


	if (sentNode != NULL)
	{

		*thisNode = new Node((*sentNode).data, NULL);

		while (sentNode != NULL)
		{
			sentNode = (*sentNode).next;

			thisNode = (*thisNode).next;

			*thisNode = new Node((*sentNode).data, NULL);

		}
	}

	sentNode = NULL;
	thisNode = NULL;

	return *this;

}

bool Queue::enqueue(int value)
{
	Node *nodeTrav = front;

	while (nodeTrav != NULL)
	{
		nodeTrav = (*nodeTrav).next;

	} //When it's done, node trav should be at a null pointer

	nodeTrav = new Node(value, NULL);

	return true;

}

bool dequeue(int& sentValue)
{
	sentValue = (*front).data;

	Node *thisNode = front.next;
	Node *nextNode = (*thisNode).next;

	while (nextNode != NULL)
	{
		thisNode = nextNode;

		nextNode = thisNode.next;

	}

	return true;

}

bool Queue::empty () const
{
	return false;

}

bool Queue::full () const
{
	return false;

}

bool clear()
{
	if (front != NULL)
	{
		delete front;

		front = NULL;

		return true;

	} else
	{
		return false; //Already clear

	}

}

bool operator==(const Queue& sentQueue) const
{
	Node *thisNode = front;
	Node *sentNode = sentQueue.front;

	if (thisNode != NULL && sentNode != NULL)
	{
		do
		{
			if ((*thisNode).data != (*sentNode).data)
			{
				thisNode = NULL;
				sentNode = NULL;

				return false;

			}

		} while (thisNode != NULL || sentNode != NULL);

		return true;

	} else if (thisNode == NULL && sentNode == NULL)
	{
		thisNode = NULL;
		sentNode = NULL;

		return true;

	} else
	{
		thisNode = NULL;
		sentNode = NULL;

		return false;

	}
}

ostream& operator<<(ostream& os, const Queue& sentQueue)
{
	os << "[";

	Node *thisNode = front;

	while (thisNode != NULL)
	{
		if ((*thisNode).next == NULL)
		{
			os << (*thisNode).data;

		} else
		{
			os << (*thisNode).data << ", ";

		}
	}

	os << "]";

	return os;

}