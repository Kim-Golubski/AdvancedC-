#include "asgn10.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
#include <vector>
#include <array>
#include <numeric>
#include <functional>

using namespace std;

int algoCategory()
{
	int choice;
	cout << "Choose 1 for modifying sequence alogorithms, 2 for non-modifying sequence algorithms 3 for sorting and related algorithms" <<
		" 4 for numerical algorithims, or 5 for function objects: ";
	cin >> choice;
	return choice;
}
void modAlgorithim()
{
	char again = 'y';
	cout << endl << "Let's create a deque of integers with size 8" << endl << endl;
	int size{ 8 };
	deque<int> d;
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Enter an integer value:" << endl;
		int val;
		cin >> val;
		d.push_back(val);
	}
	cout << endl << "The deque created is: " << endl;
	ostream_iterator<int> output{ cout, " " };
	copy(d.cbegin(), d.cend(), output);
	while (again != 'n')
	{
		cout << endl << endl << "Now let's modify the deque" << endl;
		cout << "Choose 1 for replace, 2 for reverse, 3 for rotate, or 4 for remove: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << "If value 1 exists, it will be replaced with value 100" << endl;
			replace(d.begin(), d.end(), 1, 100);
			cout << "Deque after replacing 1 with 100:" << endl;
			copy(d.cbegin(), d.cend(), output);
			break;
		}
		case 2:
		{
			cout << "All values in the deque will be reversed" << endl;
			reverse(d.begin(), d.end());
			cout << endl << "Deque after reversing: " << endl;
			copy(d.cbegin(), d.cend(), output);
			break;
		}
		case 3:
		{
			cout << "The first 4 values will be rotated to the end" << endl;
			rotate(d.begin(), d.begin() + 4, d.end());
			cout << endl << "Deque after rotating first 4 numbers:" << endl;
			copy(d.cbegin(), d.cend(), output);
			break;
		}
		case 4:
		{
			cout << "The value 100 will be removed" << endl;
			auto newEnd = remove(d.begin(), d.end(), 100);
			cout << endl << "Deque after removing value 100:" << endl;
			copy(d.begin(), newEnd, output);
			break;
		}
		default:
			break;
		}
		cout << endl<<"Another modifying algorithim? 'n' to quit: ";
		cin >> again;
		cout << endl;
	}

}

void nonmodAlgorithim()
{
	cout << "Let's create a vector of integers with size 10" << endl;
	int size{ 10 };
	vector<int> v;
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Enter an integer value:" << endl;
		int val;
		cin >> val;
		v.push_back(val);
	}
	cout << "The vector created is: " << endl;
	ostream_iterator<int> output{ cout, " " };
	copy(v.cbegin(), v.cend(), output);
	vector<int> v2;
	cout <<endl<< "Create a second vector: ";
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Enter an integer value:" << endl;
		int val;
		cin >> val;
		v2.push_back(val);
	}
	char again = 'y';
	while (again != 'n')
	{
		cout << endl<<endl << "Choose 1 to check equality, 2 for mismatch, 3 for count, or 4 for for_each: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << "Are the two vectors equal?" << endl;
			bool result{ equal(v.cbegin(),v.cend(), v2.cbegin(), v2.cend()) };
			cout << "Vector 1 " << (result ? "is" : "is not") << " equal to vector 2" << endl;
			break;
		}
		case 2:
		{
			cout << "Let's find the first mismatch between the two vectors" << endl;
			auto location = mismatch(v.cbegin(), v.cend(), v2.cbegin(), v2.cend());
			if (location.first == v.end())
			{
				cout << "There are no mismatches" << endl;
			}
			else
			{
				cout << "The first mismatch occurance is at location " << (location.first - v.begin()) << " where vector1 contains " <<
					*location.first << " and vector2 contains " << *location.second << endl;
			}
			break;
		}
		case 3:
		{
			cout << endl << "How many times does the value 10 appear in vector2? ";
			int myCount = count(v2.cbegin(), v2.cend(), 10);
			cout << myCount << endl;
			break;
		}
		case 4:
		{
			cout << "Sum of each element in vector1: ";
			int sum{ 0 };
			for_each(v.cbegin(), v.cend(), [&sum](auto i) {sum += i; });
			cout << sum << endl;
		}
		default:
			break;
		}
		cout << endl << "Another nonmodifying algorithim? 'n' to quit: ";
		cin >> again;
		cout << endl;
	}
}
void sortAlgorithim()
{
	cout << endl<<"Let's create an vector of doubles with size 5" << endl;
	int size{ 5 };
	vector <double> a;
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Enter a double value: ";
		double val;
		cin >> val;
		a.push_back(val);
	}
	cout << endl<<"The vector created is: ";
	ostream_iterator<double> output{ cout, " " };
	copy(a.cbegin(), a.cend(), output);
	char again = 'y';
	while (again != 'n')
	{
		cout << endl << endl << "Choose 1 for sort, 2 for min, 3 for max, 4 for minmax, 5 for merge, or 6 for includes: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << endl << "The vector sorted is: " << endl;
			sort(a.begin(), a.end());
			copy(a.cbegin(), a.cend(), output);
			break;
		}
		case 2:
		{
			cout << endl << "the minimum value is: ";
			double minimum = *min_element(a.begin(), a.end());
			cout << minimum;
			break;
		}
		case 3:
		{
			cout << endl << "the max value is: ";
			double maximum = *max_element(a.begin(), a.end());
			cout << maximum;
			break;
		}
		case 4:
		{
			auto result = minmax_element(a.cbegin(), a.cend());
			cout << endl << "the min value is: " << *result.first <<
				" the max value is: " << *result.second;
			break;
		}
		case 5:
		{
			cout << endl << "The created vector merged with a second vector {1.1,10.1,100.1}: " << endl;
			vector <double> v2{ 1.1,10.1,100.1 };
			vector <double>v3(a.size() + v2.size());
			sort(a.begin(), a.end());
			sort(v2.begin(), v2.end());
			merge(a.begin(), a.end(), v2.begin(), v2.end(), v3.begin());
			copy(v3.cbegin(), v3.cend(), output);
			break;
		}
		case 6:
		{
			vector <double> v2{ 1.1,10.1,100.1 };
			cout << "Does the created vector {";
			copy(a.cbegin(), a.cend(), output);
			cout<<"} include{1.1 10.1 100.1} ? " << endl;
			if (includes(a.cbegin(), a.cend(), v2.cbegin(), v2.cend()))
			{
				cout << endl << "The vector does include {1.1,10.1,100.1}" << endl;
			}
			else
			{
				cout << endl << "The vector does not include {1.1,10.1,100.1}" << endl;
			}
			break;
		}
		default:
			break;
		}
		cout << endl << "Another sorting algorithim? 'n' to quit: ";
		cin >> again;
		cout << endl;
	}
}
void numAlgorithim()
{
	cout<<"Let's create an array of consecutive integers with size 10"<<endl;
	array<int, 10> a;
	cout << "Which number would you like to start with? ";
	int startVal;
	cin >> startVal;
	iota(a.begin(), a.end(), startVal);
	cout << endl<<"The array created is: ";
	ostream_iterator<double> output{ cout, " " };
	copy(a.cbegin(), a.cend(), output);
	cout << endl << endl << "The sum of this array is: ";
	int sum = accumulate(a.begin(), a.end(), 0);
	cout << sum<<endl<<endl;
}
void functionObject()
{
	vector <int> v;
	cout << endl << "Create a vector of size 3:" << endl;
	for (int i{ 0 }; i < 3; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	cout << endl << "The vector created is: ";
	ostream_iterator<int> output{ cout, " " };
	copy(v.begin(), v.end(), output);
	char again = 'y';
	while (again != 'n')
	{
		cout << endl << endl << "Choose 1 to sort a vector in descending order, 2 for adding two vectors, 3 to negate a vector, or 4 to mulptily 2 vectors: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			//sort vector descending
			sort(v.begin(), v.end(), greater<int>());
			cout << endl << "Vector sorted in descending order: ";
			copy(v.cbegin(), v.cend(), output);
			break;
		}
		case 2:
		{
			//plus - add two vectors
			vector<int> two{ 10,10,10 };
			ostream_iterator<int> output{ cout, " " };
			cout << endl << "Vector one ";
			copy(v.begin(), v.end(), output);
			cout << "plus vector two ";
			copy(two.begin(), two.end(), output);
			cout << "creates new vector one values: ";
			transform(v.begin(), v.end(), two.begin(), v.begin(), plus<int>());
			copy(v.begin(), v.end(), output);
			break;
		}
		case 3:
		{
			//negate
			transform(v.begin(), v.end(), v.begin(), negate<int>());
			cout << "Vector after negating: ";
			copy(v.begin(), v.end(), output);
			break;
		}
		case 4:
		{
			//multiplies
			for (int i{ 0 }; i < v.size(); i++)
			{
				if (i + 1 < v.size())
				{
					cout << v[i] << " x ";
				}
				else
				{
					cout << v[i] << " = ";
				}
			}
			int p = accumulate(v.begin(), v.end(), 1, multiplies<int>());
			cout << p;
			break;
		}
		default:
			break;
		}
		cout <<endl<<"Another function object algorithim? ";
		cin >> again;
	}
}
