#include"List.h"
#include"ListNode.h"
#include<iostream>
using namespace std;

int main()
{
	List<int> intList;
	int choice;
	cout << "Choose your operation -\n" <<
		"1 to insert at beginning of list\n" <<
		"2 to insert at end of list\n" <<
		"3 to delete from beginning of list\n" <<
		"4 to delete from end of list\n" <<
		"5 to insert at a specified location\n" <<
		"6 to delete based on value\n" <<
		"7 to end processing: ";
	cin >> choice;

	char loop = 'y';
	while (loop != 'n')
	{
		switch (choice)
		{
		case 1:
		{
			//insert at beginning of list
			cout << "Enter an integer: ";
			int value;
			cin >> value;
			intList.insertAtFront(value);
			intList.print();
			cout << "? ";
			cin >> choice;
			break;
		}
		case 2:
		{
			//insert at end of list
			cout << "Enter an integer: ";
			int value;
			cin >> value;
			intList.insertAtBack(value);
			intList.print();
			cout << "? ";
			cin >> choice;
			break;
		}
		case 3:
		{
			//delete from beginning of list
			try
			{
				if (intList.isEmpty())
					throw "List is empty";
				int value;
				if (intList.removeFromFront(value))
				{
					cout << value << " removed\n";
				}
				intList.print();
			}
			catch (const char* emptyEx)
			{
				cout << "Empty stack\n\n";
			}
			cout << "? ";
			cin >> choice;
			break;
		}
		case 4:
		{
			//delete from end of list
			try
			{
				if (intList.isEmpty())
					throw "List is empty";
				int value;
				if (intList.removeFromBack(value))
				{
					cout << value << " removed\n";
				}
				intList.print();
			}
			catch (const char* emptyEx)
			{
				cout << "Empty stack\n\n";
			}
			cout << "? ";
			cin >> choice;
			break;
		}
		case 5:
		{
			//insert at a specified location
			cout << "Enter an integer: ";
			int value;
			cin >> value;
			cout << "Which position? ";
			int index;
			cin >> index;
			intList.insertAtLocation(value, index);
			intList.print();
			cout << "? ";
			cin >> choice;
			break;
		}
		case 6:
		{
			//delete based on value
			try
			{
				if (intList.isEmpty())
					throw "List is empty";
				cout << "Which value? ";
				int val;
				cin >> val;
				
				if (intList.removeValue(val))
				{
					cout << val << " has been removed\n";
				}
				intList.print();
			}
			catch (const char* emptyEx)
			{
				cout << "Empty stack\n\n";
			}
			cout << "? ";
			cin >> choice;
			break;
		}
		case 7:
		{
			loop = 'n';
			break;
		}
		default:
			break;
		}
	}

	cout << "Choose 1 for linear search, 2 binary search, 3 for for selection sort, 4 for merge sort or 5 to quit: ";
	int choice2;
	cin >> choice2;
	char loop2 = 'y';
	while (loop2 != 'n')
	{
		switch (choice2)
		{
		case 1:
		{
			cout << "Enter search value: ";
			int val;
			cin >> val;
			int valFound = intList.search(val);
			if (valFound != -1)
			{
				cout << "Value found at position "<<valFound << endl;
			}
			if (valFound == -1)
			{
				cout << "value not found" << endl;
			}
			cout << "\n? ";
			cin >> choice2;
			break;
		}
		case 2:
		{
			cout << "Enter search value: ";
			int val;
			cin >> val;
			ListNode<int>* a = intList.getFirstNode();
			if (intList.binarySearch(a, val) == NULL)
			{
				cout << "Value not found.\n";
			}
			else
			{
				cout << "Value found.\n";
			}
			cout << "\n? ";
			cin >> choice2;
			break;
		}
		case 3:
		{
			intList.selectionSort();
			intList.print();
			cout << "\n? ";
			cin >> choice2;
			break;
		}
		case 4:
		{
			ListNode<int>* a = intList.getFirstNode();
			intList.print();
			cout << endl;
			cout << "Sorted Merge: ";
			
			intList.mergeSort(&a);
			intList.print();
			cout << "\n? ";
			cin >> choice2;
			break;
		}
		case 5:
		{
			loop2 = 'n';
			break;
		}
		default:
			break;
		}
	}
}
