/*

#include <iostream>
using namespace std;

class ListNode;

class Node {
private:
    Node(int, Node*);
    int data;
    Node *next;

    friend class ListNode;
    friend ostream& operator << (ostream&, const ListNode&);
};

class ListNode {
public:
    ListNode(int=10);
    ListNode(const ListNode&);
    ~ListNode();

    bool insertAfter(int);
    bool insertBefore(int);
    bool get(int&) const;
    bool remove(int&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListNode& operator = (const ListNode&);

    friend ostream& operator << (ostream&, const ListNode&);

private:
    Node *head;
    Node *cursor;
};

*/

#include <iostream>
#include "listnode.h"

using namespace std;

//Node Constructor
Node::Node (int sentValue, Node *nextNode)
{
	data = sentValue;

	next = nextNode;

}

//ListNode Constructors and Destructor
ListNode::ListNode (int size)
{
	//Size can be ignored
	head = NULL;
	cursor = NULL;

}

ListNode::ListNode (const ListNode& sentList)
{
	head = NULL;
	cursor = NULL;

	Node *sentTrav = sentList.head;

	if (sentTrav != NULL)
	{
		head = new Node((*sentTrav).data, NULL);

		Node *tempCursor = head;

		cursor = head;

		sentTrav = (*sentTrav).next;

		while (sentTrav != NULL)
		{
			(*tempCursor).next = new Node((*sentTrav).data, NULL);

			if (sentList.cursor == sentTrav)
			{
				cursor = (*tempCursor).next;

			}

			tempCursor = (*tempCursor).next;
			sentTrav = (*sentTrav).next;

		}

	}

	sentTrav = NULL;
	//cursor = head;

}

ListNode::~ListNode ()
{
	delete head;

	cursor = NULL;

}

bool ListNode::insertAfter (int sentValue)
{
	if ((*this).isEmpty())
	{
		head = new Node(sentValue, NULL);

		cursor = head;

		return true;

	} else
	{
		Node *currentNext = (*cursor).next;

		Node *newNext = new Node(sentValue, currentNext);

		(*cursor).next = newNext;

		currentNext = NULL;

		return true;

	}
}

bool ListNode::insertBefore (int sentValue)
{
	if ((*this).isEmpty())
	{
		head = new Node(sentValue, NULL);

		cursor = head;

		return true;

	} else if (cursor == head)
	{
		Node *newNode = new Node(sentValue, head);

		head = newNode;



		return true;

	} else
	{
		Node *cursorCache = cursor;

		goToPrior();

		Node *beforeNode = cursor; //The node originally before the cursor

		Node *newNode = new Node(sentValue, cursorCache);

		(*beforeNode).next = newNode;

		cursor = cursorCache; //Return the cursor to its original point

		return true;

	}

}

bool ListNode::get (int& returnVal) const
{
	if (cursor != NULL)
	{
		returnVal = (*cursor).data;

		return true;

	} else
	{
		return false;

	}
}

bool ListNode::remove (int& returnVal)
{
	if (cursor != NULL) //The list is not empty
	{
		returnVal = (*cursor).data;

		Node *nextNode = (*cursor).next;

		if (goToPrior()) //The cursor is not at the beginning
		{
			Node *prevNode = cursor;

			goToNext();

			(*prevNode).next = nextNode;

			(*cursor).next = NULL;

			delete cursor;

			cursor = prevNode;

			prevNode = NULL;
			nextNode = NULL;

		} else //The cursor is at the beginning
		{
			(*cursor).next = NULL;

			delete cursor;

			head = nextNode;
			cursor = head;

			nextNode = NULL;

		}

		return true;

	} else
	{
		return false;

	}
}

void ListNode::clear ()
{
	if (head != NULL)
	{
		delete head;

		head = NULL;

	}

	cursor = NULL;

}

bool ListNode::goToBeginning ()
{
	if (cursor != head)
	{
		cursor = head;

		return true;

	} else
	{
		return false; //The cursor is already at the beginning

	}
}

bool ListNode::goToEnd ()
{
	Node *nodeTrav = head;

	while ((*nodeTrav).next != NULL)
	{
		nodeTrav = (*nodeTrav).next;

	}

	if (cursor != nodeTrav)
	{
		cursor = nodeTrav;

		nodeTrav = NULL;

	} else
	{
		nodeTrav = NULL;

		return false; //cursor is already at the end

	}
}

bool ListNode::goToNext ()
{
	if ((*cursor).next != NULL)
	{
		cursor = (*cursor).next;

		return true;

	} else
	{
		return false;

	}
}

bool ListNode::goToPrior ()
{
	if (cursor != head)
	{
		Node *nextNode = head;

		while ((*nextNode).next != cursor)
		{
			nextNode = (*nextNode).next;

		}

		cursor = nextNode;

		nextNode = NULL;

		return true;

	} else
	{
		return false; //cursor already at head

	}

}

bool ListNode::isEmpty () const
{
	if (head == NULL)
	{
		return true;

	} else
	{
		return false;

	}
}

bool ListNode::isFull () const
{
	return false;

}

ListNode& ListNode::operator= (const ListNode& sentList)
{
	delete head;

	head = NULL;
	cursor = NULL;

	Node *sentTrav = sentList.head;

	if (sentTrav != NULL)
	{
		head = new Node((*sentTrav).data, NULL);

		Node *tempCursor = head;

		cursor = head;

		sentTrav = (*sentTrav).next;

		while (sentTrav != NULL)
		{
			(*tempCursor).next = new Node((*sentTrav).data, NULL);

			if (sentList.cursor == sentTrav)
			{
				cursor = (*tempCursor).next;

			}

			tempCursor = (*tempCursor).next;
			sentTrav = (*sentTrav).next;

		}

	}

	sentTrav = NULL;
	//cursor = head;

	return *this;

}

ostream& operator<< (ostream& os, const ListNode& sentList)
{
	os << "[";

	Node *nodeTrav = sentList.head;

	while (nodeTrav != NULL)
	{
		if (nodeTrav == sentList.cursor)
		{
			os << "(Cursor) ";

		}

		if ((*nodeTrav).next == NULL)
		{
			os << (*nodeTrav).data;

			nodeTrav = (*nodeTrav).next;

		} else
		{
			os << (*nodeTrav).data << ", ";

			nodeTrav = (*nodeTrav).next;

		}
	}

	os << "]";

	nodeTrav = NULL;

	return os;

}