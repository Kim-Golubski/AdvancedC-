#include "proj10.h"
#include <iostream>

using namespace std;


int main()
{
	char loop = 'y';
	while (loop != 'n')
	{
		cout << "Which exception would you like to try? " << endl;
		cout << "Choose 1 for division by 0, 2 for rethrowing exceptions, 3 for stack unwindng, 4 for bad_alloc exception, or 5 for set_new_handler: ";
		int choice;
		cin >> choice;
		cout << endl << endl;
		switch (choice)
		{
		case 1:
			divideBy0();
			break;
		case 2:
			rethrowEx();
			break;
		case 3:
			stackUnwind();
			break;
		case 4:
			badAlloc();
			break;
		case 5:
			newHand();
			break;
		default:
			break;
		}
		cout << endl << "Press 'n' to quit: ";
		cin >> loop;
	}
}