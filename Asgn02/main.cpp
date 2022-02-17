#include "proj2h.h"
#include <iostream>
#include <algorithm>
using namespace std; 

int main()
{
	cout << "Function 1: Calculate discount price." << endl;
	double listPrice{0.0};
	double discountPercentage{0.0};
	double discountPrice{0.0};
	cout << "Please input the list price and discount percentage." << endl;
	cin >> listPrice >> discountPercentage;
	calculateDiscount(listPrice, discountPercentage, discountPrice);
	cout << "The discount price is: " << discountPrice << endl;

	cout << "Function 2: Determine the largest interger." << endl;
	int one;
	int two;
	int largest;
	cout << "Enter two integers:" << endl;
	cin >> one >> two;
	determineLarger(one, two, &largest);
	cout << largest << " is the larger number"<<endl<<endl;

	cout << "Function 3: Compare two arrays to determine if they contain matching data." << endl;
	const int arSize{3};
	string a1[arSize];
	string a2[arSize];
	int count1{ 0 };
	int count2{ 0 };
	int len1 = sizeof(a1)/sizeof(a1[0]);
	int len2 = sizeof(a2) / sizeof(a2[0]);
	bool compare;

	while (count1 < len1)
	{
		cout << "Enter a vegetable:" << endl;
		cin >> a1[count1];
		count1 += 1;
	}
	while (count2 < len2)
	{
		cout << "Enter a vegetable" << endl;
		cin >> a2[count2];
		count2 += 1;
	}
	compare = compareArrays(a1, a2, len1);
	cout << compare << endl<<endl;

	cout << "Function 4: Sort a class template array and a built in array." << endl;
	const int arraySize{ 3 };
	array<string, arraySize> a3 = { "yellow", "sit", "bye" };
	string a4[arraySize] = { "yes", "what", "app" };
	string* aPtr = &a3[0];
	sortArrays(aPtr, arraySize);
	sortArrays(a4, arraySize);

	cout<<"Function 5: Demo four ways to pass a pointer to a function."<<endl;
	cout << "This function is commented out because it throws errors.";
	/*int a{100};
	int* ptrA{ &a };
	int b{ 200 };
	const int* ptrB{ &b };
	int c{ 300 };
	int* const ptrC{ &c };
	const int d{ 400 };
	const int* const ptrD{ &d };

	demoPtrTechniques(ptrA, ptrB, ptrC, ptrD);*/
}
