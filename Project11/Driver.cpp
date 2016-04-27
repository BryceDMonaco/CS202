#include <iostream>
#include <fstream>
#include <string>

#include "listnode.h"
#include "listarray.h"

using namespace std;

bool SearchList (ListArray<int> sentList, int amount, int searchFor);
ListArray<int> NodeToArray (ListNode sentList, int amount);
ListNode SortList (ListNode sentList, int amount);
int DoFib (int index);

int main ()
{
	ifstream data;

	cout << "Enter the data file name: ";

	char *fileName = new char[20];

	cin >> fileName;

	data.open(fileName);

	int amount, value;

	data >> amount; //Reads in the first number, which is the number of values

	ListNode initialList;

	for (int i = 0; i < amount; i++)
	{
		data >> value;

		initialList.insertAfter(value);

	}

	cout << "Data read in, list node is: ";
	cout << initialList << endl;

	ListNode sortedList;

	sortedList = SortList(initialList, amount);

	cout << "List sorted, sorted list is: " << sortedList << endl;

	ListArray<int> sortedListA;

	sortedListA = NodeToArray(sortedList, amount);

	cout << "Converted to array, array list is: " << sortedListA << endl;

	cout << "Enter value to search for: ";

	cin >> value;

	sortedListA.goToBeginning();

	if (SearchList (sortedListA, amount, value))
	{
		cout << "The value " << value << " was found in the list!" << endl;

	} else
	{
		cout << "The value " << value << " count not be found." << endl;

	}

	/*

	Fib stuff starts here

	*/

	cout << "What Fib value should be found: ";
	cin >> value;

	cout << "Fib " << value << " = " << DoFib(value) << endl;

	return 0;

}

int DoFib (int index)
{
	if (index == 1 || index == 2)
	{
		return 1;

	} else if (index > 2)
	{
		return (DoFib(index - 1) + DoFib(index - 2));

	} else if (index < 1)
	{
		cout << "Fib Err: Invalid Index" << endl;

		return 0;

	}
}

ListNode SortList (ListNode sentList, int amount)
{
	ListNode newList;

	int initialNums[amount];
	int sortedNums[amount]; //Should be sorted greatest to least since will be insert bef

	for (int i = 0; i < amount; i++)
	{
		int val;

		sentList.get(val);

		initialNums[i] = val;

		sentList.goToNext();

	}

	//Bubble sort, greatest to least
	for (int i = 0; i < amount; i++)
	{
		for (int ii = 0; ii < (amount - (i + 1)); ii++)
		{
			if (initialNums[ii] < initialNums[ii+1])
			{
				int leftNum = initialNums[ii];
				int rightNum = initialNums[ii+1];

				initialNums[ii] = rightNum;
				initialNums[ii+1] = leftNum;

			}

		}	

	}

	//cout << "Sorted Array: ";

	/*
	for (int i = 0; i < amount; i++)
	{
		cout << initialNums[i] << ", ";

	}
	*/

	cout << endl;

	for (int i = 0; i < amount; i++)
	{
		//cout << initialNums[i] << ", ";

		newList.insertBefore(initialNums[i]);

		newList.goToPrior();

		//cout << newList << endl;

	}

	//cout << endl;

	return newList;

}

ListArray<int> NodeToArray (ListNode sentList, int amount)
{
	ListArray<int> newLA;

	sentList.goToEnd();

	for (int i = 0; i < amount; i++)
	{
		int val;

		sentList.get(val);

		newLA.insertBefore(val);

		sentList.goToPrior();

	}
 
	return newLA;

}

bool SearchList (ListArray<int> sentList, int amount, int searchFor)
{
	int pivotVal = (amount/2);

	for (int i = 0; i < pivotVal; i++) //Move the cursor to the pivot
	{
		sentList.goToNext();

	}

	int val;

	sentList.get(val);

	if (searchFor != val && pivotVal == 0)
	{
		return false;

	} else if (searchFor < val) //Isolate to the left side
	{
		sentList.goToBeginning();

		return SearchList(sentList, pivotVal, searchFor);

	} else if (searchFor > val) //Isolate to the right side
	{
		return SearchList(sentList, pivotVal, searchFor);

	} else if (searchFor == val)
	{
		return true;

	}
}