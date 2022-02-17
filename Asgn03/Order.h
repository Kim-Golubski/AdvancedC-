#ifndef ORDER_H
#define ORDER_H

#include <vector>
class Order
{
public:
	explicit Order( int = 0);
	~Order();

	void setOrderNum(unsigned int&);
	int getOderNum() const;
	void setCustID(unsigned int);
	int getCustID() const;
	void setProductNums(int);
	std::vector<int> getProductNums();
	void setOrderCreateTime(std::string&);
	std::string getOrderCreateTime() const;
	static unsigned int getOrderCount();
	/*void orderReport();*/

private:
	unsigned int orderNum;
	unsigned int custID;
	std::vector<int> productNums;
	std::string orderCreationTime;
	static unsigned int orderCount;

};



#endif