#include "TwoDayPackage.h"
#include <iostream>
using namespace std;

TwoDayPackage::TwoDayPackage(const string& sName, const string& sAddy, const string& sCity, const string& sState,
	const string& sZip, const string& rName, const string& rAddy, const string& rCity,
	const string& rState, const string& rZip, double weight, double cost, double fee)
	: Package (sName, sAddy, sCity, sState, sZip, rName, rAddy, rCity, rState, rZip, weight, cost)
{

	setTwoDayFee(fee);
}

void TwoDayPackage::setTwoDayFee(double fee)
{
	twoDayFee = fee;
}
double TwoDayPackage::getTwoDayFee() { return twoDayFee; }
double TwoDayPackage::calculateCost()
{
	return { (getWeight() * getCostPerOunce()) + twoDayFee };
}