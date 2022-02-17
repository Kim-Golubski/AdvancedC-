#include <iomanip>
#include <string>
#include <ctime>
#include <iostream>
#include "Product.h"

using namespace std;
Product::Product(string name)
{
	++productCount;
	setProductNum(productCount);
	setProductName(name);
}
Product::~Product(){}
void Product::setProductNum(unsigned int& pNum)
{
	productNum = pNum;
}
int Product::getProductNum() const { return productNum; }

void Product::setProductName(std::string pName)
{
	productName = pName;
}
std::string Product::getProductName() { return productName; }

void Product::setProductDesciption(string pDescrip)
{
	productDescription = pDescrip;
}
string Product::getProductDescription() const { return productDescription; }

void Product::setProdCreationDate(std::string& timestamp)
{
	productCreationTime = timestamp;
}
std::string Product::getProdCreationDate() const { return productCreationTime; };

unsigned int Product::productCount{ 0 };
unsigned int Product::getProductCount() { return productCount; }
