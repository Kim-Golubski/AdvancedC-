#pragma once

#include <string>

class OverloadDemo
{
public:
	/*Setters/Getters*/
	void setIntOne(int);
	int getIntOne();
	void setDoubleOne(double);
	double getDoubleOne();
	void setStringOne(std::string);
	std::string getStringOne();
	/*Overloaded functions*/
	int operator+(int);
	double operator+(double);
	std::string operator+(std::string);
	int operator-(int);
	double operator-(double);
	std::string operator-(std::string);
	int operator*(int);
	double operator*(double);
	std::string operator*(std::string);
	int operator/(int);
	double operator/(double);
	std::string operator/(std::string);
	//prefix overloads
	void operator++();
	void operator--();
	//postfix overloads
	void operator++(int);
	void operator--(int);
private:
	int intOne;
	double doubleOne;
	std::string stringOne;

};