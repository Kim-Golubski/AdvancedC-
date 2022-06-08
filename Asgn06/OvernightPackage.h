#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H

#include "Package.h"

class OvernightPackage : public Package
{
public:
	OvernightPackage(const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);
	void setOvernightRate(double);
	double getOvernightRate();
	virtual double calculateCost() override;
	virtual void report() override;
private:
	double overnightRate;
};

#endif