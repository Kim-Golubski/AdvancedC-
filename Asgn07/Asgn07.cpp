#include "PhoneNumber.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	PhoneNumber number;
	char redo = 'y';

	while (redo == 'y')
	{
		cout << endl << "Enter a phone number in format (555) 555-5555" << endl;
		cin >> number;
		redo = 'n';
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
			cout << "Invalid phone number. Type y to try again: " << endl;
			cin >> redo;
			cin.ignore();
			cin.clear();
		}
		cout << endl;
	}
	cout << number<<endl;


	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	cout << "\n\n<ENTER> to exit: ";
	cin.get();
}
