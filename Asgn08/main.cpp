#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "asgn08.h"
using namespace std;

int main()
{
	char choice1;
	cout << "Type 'y' to write product or order information to a txt file: ";
	cin >> choice1;
	while (choice1 == 'y')
	{
		createFiles();
		cout<< "Type 'y' to write product or order information to a txt file: ";
		cin >> choice1;
	}

	char choice2;
	cout << "Type 'y' to run a report: ";
	cin >> choice2;
	while (choice2 == 'y')
	{
		runReports();
		cout << "Type 'y' for another report: "<<endl;
		cin >> choice2;
	}
}