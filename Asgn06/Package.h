#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
public:
	//constructor
	Package(const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, double = 0.0, double = 0.0);
	//sender setters & getters
	void setSenderName(std::string);
	std::string getSenderName();
	void setSenderAddress(std::string);
	std::string getSenderAddress();
	void setSenderCity(std::string);
	std::string getSenderCity();
	void setSenderState(std::string);
	std::string getSenderState();
	void setSenderZip(std::string);
	std::string getSenderZip();
	//receiver setters & getters
	void setReceiverName(std::string);
	std::string getReceiverName();
	void setReceiverAddress(std::string);
	std::string getReceiverAddress();
	void setReceiverCity(std::string);
	std::string getReceiverCity();
	void setReceiverState(std::string);
	std::string getReceiverState();
	void setReceiverZip(std::string);
	std::string getReceiverZip();
	//other setters & getters
	void setWeight(double);
	double getWeight();
	void setCostPerOunce(double);
	double getCostPerOunce();
	//member function
	virtual double calculateCost();
	virtual void report();
private:
	std::string senderName;
	std::string senderAddress;
	std::string senderCity;
	std::string senderState;
	std::string senderZip;
	std::string receiverName;
	std::string receiverAddress;
	std::string receiverCity;
	std::string receiverState;
	std::string receiverZip;
	double weight;
	double costPerOunce;
};

#endif