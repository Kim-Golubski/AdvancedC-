#include "proj10.h"
#include "DivideByZeroException.h"
#include <iostream>
#include <new>
#include <cstdlib>


using namespace std;


void divideBy0()
{
	int num1;
	int num2;

	cout << "Enter an integer: ";
	cin >> num1;
	cout << "Enter a second integer: ";
	cin >> num2;

	try
	{
		double result{ quotient(num1, num2) };
		cout << endl<<"The quotient is: " << result << endl;
	}
	catch (const DivideByZeroException& DivideByZeroException)
	{
		cout << "Exception occurred: " << DivideByZeroException.what() << endl;
	}
}

void rethrowEx()
{
	try
	{
		cout << "call exception function"<<endl;
		throwException();
	}
	catch (const exception&)
	{
		cout << "main handled exception"<<endl;
	}
}

void stackUnwind()
{
	try
	{
		cout << "call function 1" << endl;
		func1();
	}
	catch (const runtime_error& error)
	{
		cout << "exception: " << error.what()<<endl;
		cout << "main handled exception" << endl;
	}
}

void badAlloc()
{
	double* ptr[100];
	try
	{
		for (auto i{ 0 }; i < 100; i++)
		{
			ptr[i] = new double[100'000'000]{};
			cout << "ptr[" << i << "] points to 100,000,000 new doubles" << endl;
		}
	}
	catch (bad_alloc& memoryAllocationException)
	{
		cerr << "Exception occurred: " << memoryAllocationException.what() << endl;
	}
}

void newHand()
{
	double* ptr[100];
	set_new_handler(customNewHandler);
	for (auto i{ 0 }; i < 100; i++)
	{
		ptr[i] = new double[100'000'000]{};
		cout << "ptr[" << i << "] points to 100,000,000 new doubles" << endl;
	}

}

double quotient(int one, int two)
{
	if (two == 0)
	{
		throw DivideByZeroException{};
	}

	return static_cast<double> (one) / two;
}

void throwException()
{
	try
	{
		cout << "exception thrown by function"<<endl;
		throw exception{};
	}
	catch (const exception&)
	{
		cout << "function exception handled in function"<<endl;
		throw;
		cout << "another exception is thrown"<<endl;
	}
}

void func1()
{
	cout << "calling function 2" << endl;
	func2();
}
void func2()
{
	cout << "calling function 3" << endl;
	func3();
}
void func3()
{
	cout << "throwing runtime error in function 3" << endl;
	throw runtime_error{ "runtime_error thrown" };
}

void customNewHandler()
{
	cerr << "customNewHandler called" << endl;
	exit(EXIT_FAILURE);
}
