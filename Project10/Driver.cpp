#include <iostream>
//#include "listnode.h"
#include "listarray.h"

using namespace std;

int main ()
{
	//ListNode testList;
	ListArray<int> testList;

	for (int i = 0; i < 10; i++)
	{
		cout << "Inserting " << i + 1 << endl;

		int val = i + 1;

		testList.insertAfter(val);

		//cout << "ding" << endl;

		cout << "List is: ";

		cout << testList << endl;

	}

	testList.clear();

	cout << "Cleared." << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Inserting " << i + 1 << endl;

		int val = i + 1;

		testList.insertBefore(val);

		//cout << "ding" << endl;

		cout << "List is: ";

		cout << testList << endl;

	}

	cout << "Testing Assignment." << endl;

	//ListNode testAssign(testList);

	ListArray<int> testAssign;
	testAssign = testList;

	cout << "Original List: \t" << testList << endl;
	cout << "Test List: \t" << testAssign << endl;

	cout << "Removing." << endl;

	for (int i = 0; i < 10; i++)
	{
		int val;

		testList.remove(val);

		//cout << "ding" << endl;

		cout << "Removed: " << val << endl;

		cout << "List is: ";

		cout << testList << endl;

	}

	return 0;

}