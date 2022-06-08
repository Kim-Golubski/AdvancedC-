#include"List.h"
#include"ListNode.h"

#include<iostream>
using namespace std;

int main()
{
	List<int> intList;
	int choice;
	cout << "Choose your operation -\n"<<
		"1 to insert at beginning of list\n"<<
		"2 to insert at end of list\n"<<
		"3 to delete from beginning of list\n"<<
		"4 to delete from end of list\n" <<
		"5 to insert at a specified location\n"<<
		"6 to delete based on value\n"<<
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
}
