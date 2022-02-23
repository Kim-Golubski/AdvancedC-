#include "OvernightPackage.h"
#include <iostream>
using namespace std;

OvernightPackage::OvernightPackage(const string& sName, const string& sAddy, const string& sCity, const string& sState,
	const string& sZip, const string& rName, const string& rAddy, const string& rCity,
	const string& rState, const string& rZip, double weight, double cost, double rate)
	: Package(sName, sAddy, sCity, sState, sZip, rName, rAddy, rCity, rState, rZip, weight, cost)
{

	setOvernightRate(rate);
}
void OvernightPackage::setOvernightRate(double rate)
{
	overnightRate = rate;
}
double OvernightPackage::getOvernightRate() { return overnightRate; }
double OvernightPackage::calculateCost()
{
	return { (getWeight() * getCostPerOunce()) + overnightRate };
}