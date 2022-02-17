#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Customer.h"
#include "Order.h"
#include "Product.h"

using namespace std;

void getTime(std::string&);
void outputReport(vector<Customer*>, vector<Order*>, vector<Product*>);
int main() 
{
	char customer = 'n';
	cout << "Would you like to enter customer info?" << endl;
	cin >> customer;
	vector<Customer*> customerRecs;
	while (customer != 'n')
	{
		string name;
		string address;
		int orders;
		string time;

		cout << "Enter customer's first name:"<<endl;
		cin.ignore();
		getline(cin, name);
		cout << "Enter customer's address:" << endl;
		cin.ignore();
		getline(cin, address);
		cout << "Enter number of orders:" << endl;
		cin >> orders;
		Customer* c = new Customer{name};
		c->setCustAddress(address);
		getTime(time);
		c->setCustCreateTime(time);
		c->setOrderNums(orders);
		customerRecs.push_back(c);
		cout <<endl<< "Would you like to enter another customer?" << endl;
		cin >> customer;
	}
	char order = 'n';
	cout << endl<< "Would you like to enter order info?" << endl;
	cin >> order;
	vector<Order*> orderRecs;
	while (order != 'n')
	{
		int custID;
		int prodNum;
		string time;

		cout << "Enter in the customer ID:" << endl;
		cin >> custID;
		cout << "How many products in the order?" << endl;
		cin >> prodNum;
		Order * o = new Order{custID};
		o->setProductNums(prodNum);
		getTime(time);
		o->setOrderCreateTime(time);
		orderRecs.push_back(o);
		cout << "Would you like to enter another order?" << endl;
		cin >> order;
	}
	char product = 'n';
	cout << endl<< "Would you like to enter product info?" << endl;
	cin >> product;
	vector<Product*> productRecs;
	while (product != 'n')
	{
		string pName;
		string pDesc;
		string time;

		cout << "Enter product name: " << endl;;
		cin.ignore();
		getline(cin, pName);
		cout << "Enter product description: "<<endl;
		cin.ignore();
		getline(cin, pDesc);
		Product* p = new Product{ pName };
		p->setProductDesciption(pDesc);
		getTime(time);
		p->setProdCreationDate(time);
		productRecs.push_back(p);
		cout<<"Would you like to enter another product?"<<endl;
		cin >> product;
	}

	outputReport(customerRecs, orderRecs, productRecs);
}

void getTime(string& timestamp)
{
	time_t t = time(0);
	timestamp = ctime(&t);
}
void outputReport(vector<Customer*> customers, vector<Order*> orders, vector<Product*> products)
{
	cout << endl<<" ** CUSTOMER REPORT **"<<endl;
	for (auto& item : customers)
	{
		cout << "Customer ID: " << item->getCustID() << endl;;
		cout << "Customer name: " << item->getName() << endl;
		cout << "Customer address " << item->getCustAddress() << endl;
		cout << "Customer order numbers: ";
		vector<int> v;
		v = item->getOrderNums();
		for (auto num : v)
		{
			cout << num << ", ";
		}
		cout << endl << "Customer created: " << item->getCustCreateTime();
	}
	cout << endl << "** ORDER REPORT **"<<endl;
	for (auto& os : orders)
	{
		cout << "Order number: " << os->getOderNum() << endl;;
		cout << "Customer ID: " << os->getCustID()<<endl;
		cout << "Product numbers: ";
		vector<int>n;
		n = os->getProductNums();
		for (auto& ord : n)
		{
			cout << ord << ", ";
		}
		cout << endl<<"Order created: " << os->getOrderCreateTime();
	}
	cout <<endl<< " ** PRODUCT REPORT **"<<endl;
	for (auto& prods : products)
	{
		cout << "Product number: " << prods->getProductNum() << endl;;
		cout << "Product name: " << prods->getProductName()<<endl;
		cout << "Product description: " << prods->getProductDescription()<<endl;
		cout << "Product created : " << prods->getProdCreationDate() << endl; 
	}
}