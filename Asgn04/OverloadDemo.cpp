#include <string>
#include "OverloadDemo.h"

using namespace std;

void OverloadDemo::setIntOne(int integer)
{
	intOne = integer;
}
int OverloadDemo::getIntOne()
{
	return intOne;
}


void OverloadDemo::setDoubleOne(double d)
{
	doubleOne = d;
}
double OverloadDemo::getDoubleOne()
{
	return doubleOne;
}


void OverloadDemo::setStringOne(string s) 
{
	stringOne = s;
}
string OverloadDemo::getStringOne()
{
	return stringOne;
}

/*Overload functions*/
int OverloadDemo::operator+(int o)
{
	int sum;
	sum = intOne + o;
	return sum;
}
double OverloadDemo::operator+(double d)
{
	double sum;
	sum = doubleOne + d;
	return sum;
}
string OverloadDemo::operator+(string s)
{
	string result;
	result = stringOne + s;
	return result;
}
int OverloadDemo::operator-(int i)
{
	int minus;
	minus = intOne - i;
	return minus;
}
double OverloadDemo::operator-(double d)
{
	double minus;
	minus = doubleOne - d;
	return minus;
}
string OverloadDemo::operator-(string s)
{
	string string1;
	string1 = stringOne + "-" + s;
	return string1;
}
int OverloadDemo::operator*(int m)
{
	int multiply;
	multiply = intOne * m;
	return multiply;
}
double OverloadDemo::operator*(double m)
{
	double multiply;
	multiply = doubleOne * m;
	return multiply;
}
string OverloadDemo::operator*(string m)
{
	string s;
	s = stringOne + "*" + m;
	return s;
}
int OverloadDemo::operator/(int d )
{
	int div;
	div = intOne / d;
	return div;
}
double OverloadDemo::operator/(double d)
{
	double div;
	div = doubleOne / d;
	return div;
}
string OverloadDemo::operator/(string d)
{
	string div;
	div = stringOne + "/" + d;
	return div;
}
void OverloadDemo::operator++()
{
	intOne += 10;
	doubleOne += 1.35;
}
void OverloadDemo::operator--()
{
	intOne -= 5;
	doubleOne -+ 2.5;
}
void OverloadDemo::operator++(int i)
{
	intOne += 18;
	doubleOne += 3,75;
}
void OverloadDemo::operator--(int i)
{
	intOne -= 3;
	doubleOne -= .25;
}