#include <iostream>
#include "queue.h"

using namespace std;

int main ()
{
	cout << "Driver started" << endl;

	Queue testQueue;

	cout << "Enqueuing:" << endl;

	for (int i = 0; i < 10; i++)
	{
		testQueue.enqueue(i + 1);

		cout << "\tInserted: " << i + 1 << endl;
		cout << "\tQueue is: " << testQueue << endl;

	}

	cout << "After Enqueuing Queue is: " << testQueue << endl;
	cout << "Dequeuing:" << endl;

	for (int i = 0; i < 10; i++)
	{
		int out;

		testQueue.dequeue(out);

		cout << "\tDequeued: " << out << endl;
		cout << "\tQueue is now: " << testQueue << endl;

	}

	cout << "Done." << endl;

	return 0;

}