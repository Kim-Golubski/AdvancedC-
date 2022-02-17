#include "Proj2h.h"
#include <iostream>
#include <algorithm>

using namespace std;

void calculateDiscount(double price, double percent, double& discount)
{
	percent /= 100;
	discount = price * percent;
}

void determineLarger(int one, int two, int* larger)
{
	if (one > two)
	{
		*larger = one;
	}
	else
	{
		*larger = two;
	}
}

bool compareArrays(const string veg1[], const string veg2[],const int asize)
{
	for (int i{ 0 }; i < asize; i++)
	{
		if (veg1[i] != veg2[i])
		{
			return false;
		}
		return true;
	}
}
void sortArrays(string a1[], int arSize)
{
	cout << "Unsorted array: " << endl;
	for (int j{ 0 }; j < arSize; j++)
	{
		cout << a1[j] << endl;
	}
	sort(a1, a1+ arSize);
	cout << "Sorted array: " << endl;
	for (int j{ 0 }; j < arSize; j++)
	{
		cout << a1[j] << endl;
	}
	
}

//void demoPtrTechniques(int* ptr1, const int* ptr2, const int* ptr3, const int* ptr4)
//{
//	cout << "1) non-const pointer to non-const data"<< endl<<"old: "<<*ptr1;
//	*ptr1 = 50;
//	cout << endl<< "new: " << *ptr1 << endl;
//	cout << "2) non-const pointer to const data" << endl<<"old: "<<*ptr2;
//	*ptr2 = 75;
//	cout <<endl<<"new: "<< * ptr2 << endl;
//	cout << "3) const pointer to non-const data" << endl<<"old: "<<*ptr3;
//	*ptr3 = &ptr1;
//	cout << endl<<"new: "<< * ptr3 << endl;
//	cout << "4) const pointer to const data" << endl<<"old: "<<*ptr4;
//	*ptr4 = 150;
//	cout << endl << "new: " << *ptr4;
//}