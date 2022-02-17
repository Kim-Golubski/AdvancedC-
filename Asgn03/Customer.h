#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer
{
	/*friend void customerReport(Customer&);*/
public:
	explicit Customer(std::string = "null");
	~Customer();
	void setCustID(unsigned int&);
	int getCustID() const;
	void setName(std::string);
	std::string getName() const;
	void setCustAddress(std::string);
	std::string getCustAddress();
	void setOrderNums(int);
	std::vector<int> getOrderNums();
	void setCustCreateTime(std::string&);
	std::string getCustCreateTime() const;
	static unsigned int getCustCount();
private:
	unsigned int custID;
	std::string name;
	std::string address;
	std::vector<int> orderNums;
	std::string customerCreationTime;
	static unsigned int customerCount;

	
};

//void customerReport(Customer& c)
//{
//	for (int i= 1; i <= c.customerCount; i++)
//	{
//		std::cout << "ID: "<<c.getCustID() << endl;
//		std::cout << "Name: "<<c.getName() << endl;
//		std::cout << "Address: "<<c.getCustAddress() << endl;
//		std::cout << "Order Numbers: ";
//		std::vector<int> v = c.getOrderNums();
//		for (int item : v)
//		{
//			std::cout << item << " ";
//		}
//		std::cout <<endl<< "Creation time: "<<c.getCustCreateTime() << endl << endl;
//
//	}
//}





#endif