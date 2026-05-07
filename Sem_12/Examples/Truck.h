#pragma once
#include "Vehicle.h"
class Truck : virtual public Vehicle
{
	unsigned loadCapacity;

public:

	Truck(const std::string& regNum, unsigned loadCapacity);
	unsigned getParkingPrice() const override;
	Vehicle* clone() const override;
};

