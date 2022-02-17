#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Order.h"

using namespace std;

Order::Order(int cID)
{
	++orderCount;
	setOrderNum(orderCount);
	setCustID(cID);
}
Order::~Order()
{
	orderCount--;
}

void Order::setOrderNum(unsigned int& oNum) 
{
	orderNum = orderCount;
}

int Order::getOderNum() const { return orderNum; }
	
void Order::setCustID(unsigned int cID)
{
	if (cID > 0 && cID <= 1000)
	{
		custID = cID;

	}
}

int Order::getCustID() const { return custID; }

void Order::setProductNums(int prods)
{
	for (int i = 0; i < prods; i++)
	{	
		int num;
		cout << "Enter product number:" << endl;
		cin >> num;
		productNums.push_back(num);
	}
}

vector<int> Order::getProductNums() 
{
	vector<int> nums;
	for (int item : productNums)
	{
		nums.push_back(item);
	}
	return nums;
}

void Order::setOrderCreateTime(string& timestamp)
{
	orderCreationTime = timestamp;
}

string Order::getOrderCreateTime() const { return orderCreationTime; }

unsigned int Order::orderCount{ 0 };
unsigned int Order::getOrderCount() { return orderCount; }


//void Order::orderReport()
//{
//	for (int i = 1; i <= orderCount; i++)
//	{
//		cout << "Order number: " << getOderNum()<<endl;
//		cout << "Customer ID: " << getCustID() << endl;
//		cout << "Product numbers: ";
//		vector<int> v = getProductNums();
//		for (int item : v)
//		{
//			cout << item << " ";
//		}
//		cout << endl<< "Creation time: " << getOrderCreateTime()<<endl<<endl;
//	}
//}