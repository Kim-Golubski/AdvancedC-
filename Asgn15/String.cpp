#include "String.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void createStrings()
{
	cout<<"Demonstrating string creation:\n";
	cout << "Enter a color: ";
	string original;
	cin >> original;
	cout << "\nYou created string: " << original << endl;
	string copyOriginal = original;
	cout << copyOriginal << " has been copied to a new string. " << endl;
	string assignOriginal;
	assignOriginal.assign(original);
	cout << assignOriginal << " has been assigned to a new string." << endl<<endl;
}

void concatStrings()
{
	cout << "Demonstrating string concatenation:\n";
	string one = "car";
	string two = one + "bonation\n";
	cout << one << " + bonation = " << two;
	string three = "car";
	three += "pet";
	cout << one << " + pet = " << three<<endl<<endl;
}

void compareStrings()
{
	cout << "Let's compare two strings\n";
	string s1 = "What a beautiful day";
	string s2 = "What a terrible day";
	cout << "String 1: \"What a beautiful day\"\nString 2: \"What a terrible day\"\n";
	int s1start{0};
	int s2start{0};
	int sLength{0};
	cout << "Enter the length you want to compare: ";
	cin >> sLength;
	cout << "Enter the starting position in string 1: ";
	cin >> s1start;
	cout << "Enter the starting position in string 2: ";
	cin >> s2start;
	int result;
	result = s1.compare(s1start, sLength, s2, s2start, sLength);
	if (result == 0)
	{
		cout << "The strings are identical\n";
	}
	else if (result > 0)
	{
		cout << "String 1 is lexicographically greater.\n";
	}
	else
	{
		cout << "String 2 is lexicographically greater.\n";
	}
}

void demoIterators()
{
	cout << "\nDemonstrating iterators: " << endl;
	cout << "Enter a name: ";
	string demo;
	cin >> demo;
	string::const_iterator iterator1 = demo.begin();
	cout << "The string entered displayed using iterator: ";
	while (iterator1 != demo.end())
	{
		cout << *iterator1;
		++iterator1;
	}
	cout << "\nThe string entered displayed using iterator in reverse: ";
	string::const_reverse_iterator iterator2 = demo.rbegin();
	while (iterator2 != demo.rend())
	{
		cout << *iterator2;
		++iterator2;
	}
}

void demoIO()
{
	cout << "\n\nDemonstrating I/O streams: " << endl;
	cout << "Enter one word to demo standard I/O: ";
	string word;
	cin >> word;
	cout <<word<<endl<<endl;
	ofstream newFile;
	newFile.open("newFile.txt");
	if (newFile.is_open())
	{
		newFile << "Demonstrating file I/O.\n";
		newFile << "This text was written to newFile.\n";
		newFile.close();
	}
	else
	{
		cout << "Unable to open file.\n";
	}
	ifstream iNewFile("newFile.txt");
	string line;
	if (iNewFile.is_open())
	{
		while (getline(iNewFile, line))
		{
			cout << line << endl<<endl;
		}
	}
	else
	{
		cout << "Unable to open file.\n";
	}

	string input{ "string 550 25.2 K" };
	istringstream inputString{ input };
	string s1;
	int number;
	double decimal;
	char letter;
	inputString >> s1 >> number >> decimal >> letter;
	cout<<"Demonstrating string stream input: \n"
		<<s1<<endl << number <<endl<< decimal <<endl<< letter<<endl;

	ostringstream outputString;
	string string1{ "Demonstrating string stream output:\n" };
	string string2{ "Which can also display other data types.\n" };
	int num{ 13 };
	char c{ 'G' };
	outputString << string1 << string2 << num << '\n' << c;
	cout << outputString.str();
}