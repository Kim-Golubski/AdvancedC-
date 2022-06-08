#include "proj16.h"
#include <iostream>
#include<iomanip>
#include <cstring>

using namespace std;

void bitwise()
{
	unsigned num;
	cout << "Enter an integer: ";
	cin >> num;
	displayBits(num);
	cout << "\nEnter a second integer: ";
	unsigned num2;
	cin >> num2;
	displayBits(num2);
	cout << "\nNum1 and Num2 bitwise & = \n";
	displayBits(num & num2);
	cout << "\nThe complement of num 1 is: \n";
	displayBits(~num);
}

void displayBits(unsigned number)
{
	const unsigned SHIFT{ 8 * sizeof(unsigned) - 1 };
	const unsigned MASK{ static_cast<const unsigned>(1 << SHIFT) };

	cout << std::setw(10) << number << " = ";

	for (unsigned i{ 1 }; i <= SHIFT + 1; ++i)
	{
		cout << (number & MASK ? '1' : '0');
		number <<= 1;

		if (i % 8 == 0)
		{
			std::cout << ' ';
		}
	}
	cout << endl;
}

void characterHandling()
{
	cout << "Testing is digit:\n"
		<< (isdigit('a') ? "a is a" : "a is not a") << " digit.\n"
		<< (isdigit('<') ? "< is a" : "< is not a") << " digit.\n"
		<< (isdigit('2') ? "2 is a" : "2 is not a") << " digit.\n\n";

	cout << "Testing is aplha:\n"
		<< (isalpha('a') ? "a is an" : "a is not an") << " alpha.\n"
		<< (isalpha('<') ? "< is an" : "< is not an") << " alpha.\n"
		<< (isalpha('2') ? "2 is an" : "2 is not an") << " alpha.\n\n";

	cout << "Changing case:\n"
		<< (isupper('P') ? "P is an" : "P is not an") << " uppercase letter.\n"
		<< "The opposite case is: " << static_cast<char>(tolower('P'));
	cout<<endl<<(islower('x') ? "x is a" : "x is not a") << " lowercase letter.\n"
		<< "The opposite case is: " << static_cast<char>(toupper('x'));
}

void cStringManip()
{
	char s1[13] {"Howdy folks!"};
	cout << "String array one contains: " << s1;
	cout << "\nString one length: " << strlen(s1);
	char s2[15];
	cout << "\nString array two contains: " << s2;
	cout << "\nString two length: " << strlen(s2);
#pragma warning(suppress : 4996)
	strcpy(s2,s1);
	cout << "\nAfter copying string array one in to string array two, string array two now contains: " << s2;
	char s3[7];
#pragma warning(suppress : 4996)
	strncpy(s3, s1, 5);
	s3[5] = '\0';
	cout << "\nAfter copying the first six characters from string array one in to string array three, string array three contains: " << s3;
	cout << "\nString three length: " << strlen(s3);
	char character{ 'o' };
	char character2{ 'q' };
	if (strchr(s1, character) != NULL)
	{
		cout << "\nThe letter " << character << " was found in " << s1;
	}
	else
	{
		cout << "\nThe letter " << character << " was not found in " << s1;
	}
	if (strchr(s1, character2) != NULL)
	{
		cout << "\nThe letter " << character2 << " was found in " << s1;
	}
	else
	{
		cout << "\nThe letter " << character2 << " was not found in " << s1;
	}
	int i{ atoi("8") };
	cout << "\nThe string \"8\" converted to an integer is " << i << "\n8 + 8 = " << i + 8;
}