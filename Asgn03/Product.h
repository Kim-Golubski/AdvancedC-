#ifndef PRODUCT_H
#define PRODUCT_h

#include <string>

class Product
{
public:
	explicit Product(std::string = "null");
	~Product();
	void setProductNum(unsigned int&);
	int getProductNum() const;
	void setProductName(std::string);
	std::string getProductName();
	void setProductDesciption(std::string);
	std::string getProductDescription() const;
	void setProdCreationDate(std::string&);
	std::string getProdCreationDate() const;
	static unsigned int getProductCount();

private:
	unsigned int productNum;
	std::string productName;
	std::string productDescription;
	std::string productCreationTime;
	static unsigned int productCount;

};

#endif
