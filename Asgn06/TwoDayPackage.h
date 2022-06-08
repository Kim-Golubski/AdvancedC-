#ifndef TWO_DAY_PACKAGE_H
#define TWO_DAY_PACKAGE_H

#include "Package.h"
#include <sstream>

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);
	void setTwoDayFee(double);
	double getTwoDayFee();
	virtual double calculateCost() override;
	virtual void report() override;
private:
	double twoDayFee;
};

#endif