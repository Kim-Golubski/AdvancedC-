#include "Package.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor 
Package::Package(const string& sName, const string& sAddy, const string& sCity, const string& sState,
	const string& sZip, const string& rName, const string& rAddy, const string& rCity,
	const string& rState, const string& rZip, double weight, double cost)
{
	senderName = sName;
	senderAddress = sAddy;
	senderCity = sCity;
	senderState = sState;
	senderZip = sZip;
	receiverName = rName;
	receiverAddress = rAddy;
	receiverCity = rCity;
	receiverState = rState;
	receiverZip = rZip;
	setWeight(weight);
	setCostPerOunce(cost);
}
//sender setters & getters
void Package::setSenderName(string n)
{
	senderName = n;
}
string Package::getSenderName() { return senderName; }
void Package::setSenderAddress(string a)
{
	senderAddress = a;
}
string Package::getSenderAddress() { return senderAddress; }
void Package::setSenderCity(string c)
{
	senderCity = c;
}
string Package::getSenderCity() { return senderCity; }
void Package::setSenderState(string s)
{
	senderState = s;
}
string Package::getSenderState() { return senderState; }
void Package::setSenderZip(string z)
{

	senderZip = z;
}
string Package::getSenderZip() { return senderZip; }

//receiver setters & getters
void Package::setReceiverName(string n)
{
	receiverName = n;
}
string Package::getReceiverName() { return receiverName; }
void Package::setReceiverAddress(string a)
{
	receiverAddress = a;
}
string Package::getReceiverAddress() { return receiverAddress; }
void Package::setReceiverCity(string c)
{
	receiverCity = c;
}
string Package::getReceiverCity() { return receiverCity; }
void Package::setReceiverState(string s)
{
	receiverState = s;
}
string Package::getReceiverState() { return receiverState; }
void Package::setReceiverZip(string z)
{
	receiverZip = z;
}
string Package::getReceiverZip() { return receiverZip; }

//other setters & getters
void Package::setWeight(double w)
{
	if (w < 0.0)
	{
		throw invalid_argument("Weight must be greater than 0.0");
	}
	weight = w;
}
double Package::getWeight() { return weight; }
void Package::setCostPerOunce(double o)
{
	if (o < 0.0)
	{
		throw invalid_argument("Cost must be greater than 0.0");
	}
	costPerOunce = o;
}
double Package::getCostPerOunce() { return costPerOunce; }

//member function
double Package::calculateCost()
{
	return weight * costPerOunce;
}

void Package::report()
{
	cout << "Sender's information:" << endl;
	cout << getSenderName() << endl << getSenderAddress() << endl << getSenderCity() << ", " << getSenderState() << endl << getSenderZip()<<endl;
	cout << "Receiver's information:" << endl;
	cout << getReceiverName() << endl << getReceiverAddress() << endl << getReceiverCity() << ", " << getReceiverState() << endl << getReceiverZip() << endl;
	cout << "Package shipping cost: " << calculateCost();
}