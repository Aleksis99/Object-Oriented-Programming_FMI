#pragma once
#include <string>

class Vehicle
{
	std::string regNum;

public: 

	Vehicle(const std::string& regNum);
	virtual unsigned getParkingPrice() const = 0;
	virtual Vehicle* clone() const = 0;
	virtual ~Vehicle();
};

