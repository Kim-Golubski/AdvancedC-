#include "stackTemplate.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Choose 1 for a stack of integers, 2 for doubles, or 3 for strings: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: 
	{
		Stack<int> intStack;
		const size_t intStackSize{ 6 };
		int intValue{ 5 };
		cout <<endl<< "Let's build a stack of 6 integers :"<<endl;
		for (size_t i{ 0 }; i < intStackSize; i++)
		{
			intStack.push(intValue);
			cout << intValue << ' ';
			intValue += 5;
		}
	
		char loop = 'y';
		while (loop != 'n')
		{
			cout << endl << "Choose 1 to remove one element, 2 to clear the stack, or 3 to verify the first element: ";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
			{
				try
				{
					if (intStack.isEmpty())
						throw "Stack is empty";
					cout << "The element removed was: " << intStack.pop();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			case 2:
			{
				intStack.clear();
				break;
			}
			case 3:
			{
				try
				{
					if (intStack.isEmpty())
						throw "Stack is empty";
					cout << "The first element is: " << intStack.top();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			default:
				break;
			}
			cout << endl<<"Enter 'n' to quit: ";
			cin >> loop;
		}



		break;
	}
	case 2:
	{
		Stack<double> dStack;
		const size_t dStackSize{ 6 };
		double dValue{ 5.6 };
		cout <<endl<< "Let's build a stack of 5 doubles:" << endl;
		for (size_t i{ 0 }; i < dStackSize; i++)
		{
			dStack.push(dValue);
			cout << dValue << ' ';
			dValue += 1.1;
		}
		char loop = 'y';
		while (loop != 'n')
		{
			cout << endl << "Choose 1 to remove one element, 2 to clear the stack, or 3 to verify the first element: ";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
			{
				try
				{
					if (dStack.isEmpty())
						throw "Stack is empty";
					cout << "The element removed was: " << dStack.pop();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			case 2:
			{
				dStack.clear();
				break;
			}
			case 3:
			{
				try
				{
					if (dStack.isEmpty())
						throw "Stack is empty";
					cout << "The first element is: " << dStack.top();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			default:
				break;
			}
			cout << endl << "Enter 'n' to quit: ";
			cin >> loop;
		}
		break;
	}
	case 3:
	{
		Stack<string> sStack;
		const size_t sStackSize{ 4 };
		cout <<endl<< "Let's build a stack of 4 strings:" << endl;
		for (size_t i{ 0 }; i < sStackSize; i++)
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			sStack.push(word);
		}
		char loop = 'y';
		while (loop != 'n')
		{
			cout << endl << "Choose 1 to remove one element, 2 to clear the stack, or 3 to verify the first element: ";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
			{
				try
				{
					if (sStack.isEmpty())
						throw "Stack is empty";
					cout << "The element removed was: " << sStack.pop();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			case 2:
			{
				sStack.clear();
				break;
			}
			case 3:
			{
				try
				{
					if (sStack.isEmpty())
						throw "Stack is empty";
					cout << "The first element is: " << sStack.top();
				}
				catch (const char* emptyEx)
				{
					cout << "Empty stack";
				}
				break;
			}
			default:
				break;
			}
			cout << endl <<endl<< "Enter 'n' to quit: ";
			cin >> loop;
		}
		break;
	}
	default:
		break;
	}
}
