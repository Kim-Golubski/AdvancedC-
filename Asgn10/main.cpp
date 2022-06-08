#include "asgn10.h"
#include <iostream>

using namespace std;

int main()
{
	char again = 'y';
	while (again != 'n')
	{
		int choice = algoCategory();
		switch (choice)
		{
		case 1:
			modAlgorithim();
			break;
		case 2:
			nonmodAlgorithim();
			break;
		case 3:
			sortAlgorithim();
			break;
		case 4:
			numAlgorithim();
			break;
		case 5:
			functionObject();
			break;
		default:
			break;
		}
		cout << "Press 'n' to quit: ";
		cin >> again;
	}
}