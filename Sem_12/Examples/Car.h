#pragma once
#include "Vehicle.h"

class Car : virtual public Vehicle
{
	unsigned passengers;
	bool polite;

public:

	Car(const std::string& regNum, unsigned passengers, bool polite);
	unsigned getParkingPrice() const override;
	Vehicle* clone() const override;
};

