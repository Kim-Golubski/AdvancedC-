#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer(string name)
{
	++customerCount;
	setCustID(customerCount);
	setName(name);
}
Customer::~Customer()
{
	customerCount--;
}

void Customer::setCustID(unsigned int& id)
{
	custID = id;
} 
int Customer::getCustID() const {return custID;}

void Customer::setName(std::string n)
{
	name = n;
}
std::string Customer::getName() const {return name;}

void Customer::setCustAddress(std::string addy)
{
	address = addy;
}
std::string Customer::getCustAddress() { return address; }

void Customer::setOrderNums(int orders)
{
	for (int i = 1; i <= orders; i++)
	{
		orderNums.push_back(i);
	}
}
vector<int> Customer::getOrderNums()
{
	vector<int> orders;
	for (int item : orderNums)
	{
		orders.push_back(item);
	}
	return orders;
}

void Customer::setCustCreateTime(string& timestamp)
{
	customerCreationTime = timestamp;
}

string Customer::getCustCreateTime() const { return customerCreationTime; }

unsigned int Customer::customerCount{ 0 };

unsigned int Customer::getCustCount() {return customerCount; }



