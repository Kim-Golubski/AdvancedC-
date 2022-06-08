#include "PhoneNumber.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

ostream& operator<<(std::ostream& output, const PhoneNumber& number)
{
	output << "Area code: " << number.areaCode <<
		"\nExchange: " << number.exchange <<
		"\nLine: " << number.line << "\n";
	output <<"Number: "<< number.phone;
	return output;
}

istream& operator>>(std::istream& input, PhoneNumber& number)
{	
	input.getline(number.phone, 15);
	
	if (cin.gcount() != 15)
	{
		input.setstate(ios::failbit);
	}

	else if (number.phone[1] == '0' || number.phone[1] == '1' || number.phone[6] == '0' || number.phone[6] == '1')
	{
		input.setstate(ios::failbit);
	}
	else
	{
		for (int i = 1; i < 4; i++)
		{
			number.areaCode[i -1] = number.phone[i];
		}
		number.areaCode[3] = 0;
		for (int j = 6; j < 9; j++)
		{
			number.exchange[j -6] = number.phone[j];
		}
		number.exchange[3] = 0;
		for (int k = 10; k < 14; k++)
		{
			number.line[k -10] = number.phone[k];
		}
		number.line[4] = 0;
	}
	return input;
	
}

