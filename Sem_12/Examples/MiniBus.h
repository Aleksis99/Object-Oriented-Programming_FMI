#pragma once
#include "Car.h"
#include "Truck.h"
class MiniBus : public Car, public Truck
{
	unsigned numDoors;

public:

	MiniBus(const std::string& regNum,
		unsigned loadCapacity,
		unsigned passengers,
		bool polite,
		unsigned numDoors);

	unsigned getParkingPrice() const override;
	Vehicle* clone() const override;

};

