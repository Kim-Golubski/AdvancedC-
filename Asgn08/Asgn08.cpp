#include "asgn08.h"
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

void createFiles()
{
	ofstream outProdFile;
	ofstream outOrdFile;

	int inputChoice;
	cout << "Enter 1 to input product info or 2 to enter order info: ";
	cin >> inputChoice;
	switch (inputChoice)
	{
	case 1:
	{
		int ProductID;
		string Description;
		double Price;
		outProdFile.open("Products.txt", ios::app);
		if (outProdFile.is_open())
		{
			cout << "Enter product ID: ";
			cin >> ProductID;
			outProdFile << ProductID << "%";
			cout << "Enter product description: ";
			cin.ignore();
			getline(cin, Description);
			outProdFile << Description << "%";
			cout << "Enter product price: ";
			cin >> Price;
			outProdFile << Price << "\n";
			outProdFile.close();
		}
		break;
	}
	case 2:
	{
		int OrderID;
		int CustomerID;
		int ProdID;
		int Quantity;
		double OrderTotal;
		outOrdFile.open("Orders.txt", ios::app);
		if (outOrdFile.is_open())
		{
			cout << "Enter order ID: ";
			cin >> OrderID;
			outOrdFile << OrderID << "%";
			cout << "Enter customer ID: ";
			cin >> CustomerID;
			outOrdFile << CustomerID << "%";
			cout << "Enter product ID: ";
			cin >> ProdID;
			outOrdFile << ProdID << "%";
			cout << "Enter quantity: ";
			cin >> Quantity;
			outOrdFile << Quantity << "%";
			cout << "Enter order total: ";
			cin >> OrderTotal;
			outOrdFile << OrderTotal << "\n";
			outOrdFile.close();
		}
		break;
	default:
		cout << "No information being written to file." << endl;
	}
	}
}

void allCustomerCities()
{
	ifstream inCustomerFile;
	int custID;
	string fName;
	string lName;
	string addy;
	string city;
	string state;
	string zip;

	inCustomerFile.open("CustomerMaster.txt", ios::in);
	if (inCustomerFile.is_open())
	{
		while (inCustomerFile >> custID)
		{
			inCustomerFile.ignore();
			getline(inCustomerFile >> ws, fName, '%');
			getline(inCustomerFile >> ws, lName, '%');
			getline(inCustomerFile >> ws, addy, '%');
			getline(inCustomerFile >> ws, city, '%');
			getline(inCustomerFile >> ws, state, '%');
			getline(inCustomerFile >> ws, zip);

			cout << city << ", ";
		}
		inCustomerFile.close();
	}
	else
	{
		"ERROR READING FILE";
	}
}
void allCustomerStates()
{
	ifstream inCustomerFile;
	int custID;
	string fName;
	string lName;
	string addy;
	string city;
	string state;
	string zip;

	inCustomerFile.open("CustomerMaster.txt", ios::in);
	if (inCustomerFile.is_open())
	{
		while (inCustomerFile >> custID)
		{
			inCustomerFile.ignore();
			getline(inCustomerFile >> ws, fName, '%');
			getline(inCustomerFile >> ws, lName, '%');
			getline(inCustomerFile >> ws, addy, '%');
			getline(inCustomerFile >> ws, city, '%');
			getline(inCustomerFile >> ws, state, '%');
			getline(inCustomerFile >> ws, zip);

			cout << state << ", ";
		}
		inCustomerFile.close();
	}
	else
	{
		"ERROR READING FILE";
	}
}
void customersInCity(string c)
{
	ifstream inCustomerFile;
	int custID;
	string fName;
	string lName;
	string addy;
	string city;
	string state;
	string zip;

	inCustomerFile.open("CustomerMaster.txt", ios::in);
	if (inCustomerFile.is_open())
	{
		while (inCustomerFile >> custID)
		{
			inCustomerFile.ignore();
			getline(inCustomerFile >> ws, fName, '%');
			getline(inCustomerFile >> ws, lName, '%');
			getline(inCustomerFile >> ws, addy, '%');
			getline(inCustomerFile >> ws, city, '%');
			getline(inCustomerFile >> ws, state, '%');
			getline(inCustomerFile >> ws, zip);

			if (city == c)
			{
				cout << fName << " " << lName << endl;
			}
		}
		inCustomerFile.close();
	}
	else
	{
		"ERROR READING FILE";
	}
}
void custoemrsInState(string s)
{
	ifstream inCustomerFile;
	int custID;
	string fName;
	string lName;
	string addy;
	string city;
	string state;
	string zip;

	inCustomerFile.open("CustomerMaster.txt", ios::in);
	if (inCustomerFile.is_open())
	{
		while (inCustomerFile >> custID)
		{
			inCustomerFile.ignore();
			getline(inCustomerFile >> ws, fName, '%');
			getline(inCustomerFile >> ws, lName, '%');
			getline(inCustomerFile >> ws, addy, '%');
			getline(inCustomerFile >> ws, city, '%');
			getline(inCustomerFile >> ws, state, '%');
			getline(inCustomerFile >> ws, zip);

			if (state == s)
			{
				cout << fName << " " << lName << endl;
			}
		}
		inCustomerFile.close();
	}
	else
	{
		"ERROR READING FILE";
	}
}
void customerIdOrders(string id)
{
	ifstream inOrdersFile;
	int orderID;
	string customerID;
	string productID;
	string quantity;
	string orderTotal;

	inOrdersFile.open("Orders.txt", ios::in);
	if (inOrdersFile.is_open())
	{
		while (inOrdersFile >> orderID)
		{
			inOrdersFile.ignore();
			getline(inOrdersFile >> ws, customerID, '%');
			getline(inOrdersFile >> ws, productID, '%');
			getline(inOrdersFile >> ws, quantity, '%');
			getline(inOrdersFile >> ws, orderTotal);

			if (customerID == id)
			{
				cout << orderID << ", ";
			}
		}
	}
	inOrdersFile.close();
}
void customerZipOrders(string zipcode)
{
	ifstream inCustomerFile;
	string custID;
	string fName;
	string lName;
	string addy;
	string city;
	string state;
	string zip;

	inCustomerFile.open("CustomerMaster.txt", ios::in);
	if (inCustomerFile.is_open())
	{
		while (getline(inCustomerFile >> ws, custID, '%'))
		{
			/*inCustomerFile.ignore();*/
			getline(inCustomerFile >> ws, fName, '%');
			getline(inCustomerFile >> ws, lName, '%');
			getline(inCustomerFile >> ws, addy, '%');
			getline(inCustomerFile >> ws, city, '%');
			getline(inCustomerFile >> ws, state, '%');
			getline(inCustomerFile >> ws, zip);

			if (zipcode == zip)
			{
				ifstream inOrdersFile;
				int orderID;
				string customerID;
				string productID;
				string quantity;
				string orderTotal;

				inOrdersFile.open("Orders.txt", ios::in);
				if (inOrdersFile.is_open())
				{
					while (inOrdersFile >> orderID)
					{
						inOrdersFile.ignore();
						getline(inOrdersFile >> ws, customerID, '%');
						getline(inOrdersFile >> ws, productID, '%');
						getline(inOrdersFile >> ws, quantity, '%');
						getline(inOrdersFile >> ws, orderTotal);

						if (customerID == custID)
						{
							cout << orderID << ", " << lName << endl;
						}
					}
				}
				inOrdersFile.close();
			}
		}
		inCustomerFile.close();
	}
	else
	{
		"ERROR READING FILE";
	}
}

void runReports()
{
	int choice3;
	cout << "Which report would you like to run?" << endl
		<< "1: List of cities in Customer file" << endl
		<< "2: List of states in Customer file" << endl
		<< "3: All customer records in a specific city" << endl
		<< "4: All custoemr records in a specific sate" << endl
		<< "5: All orders by a specific customer ID" << endl
		<< "6: All orders for a customer by zip code" << endl;
	cin >> choice3;
	switch (choice3)
	{
	case 1:
	{
		allCustomerCities();
		cout << endl << endl;
		break;
	}
	case 2:
	{
		allCustomerStates();
		cout << endl << endl;
		break;
	}
	case 3:
	{
		string city;
		cout << "Which city? ";
		cin.ignore();
		getline(cin, city);
		customersInCity(city);
		cout << endl << endl;
		break;
	}
	case 4:
	{
		string state;
		cout << "Which state? ";
		cin >> state;
		custoemrsInState(state);
		cout << endl << endl;
		break;
	}
	case 5:
	{
		string ID;
		cout << "Which ID? ";
		cin >> ID;
		customerIdOrders(ID);
		cout << endl << endl;
		break;
	}
	case 6:
	{
		string zipcode;
		cout << "Which zipcode? ";
		cin >> zipcode;
		customerZipOrders(zipcode);
		break;
	}
	default:
		cout << "No matching report";
	}
}
