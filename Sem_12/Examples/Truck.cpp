#include "Truck.h"

Truck::Truck(const std::string& regNum, unsigned loadCapacity):
	Vehicle(regNum), loadCapacity(loadCapacity)
{
}

unsigned Truck::getParkingPrice() const
{
	return loadCapacity / 100;
}

Vehicle* Truck::clone() const
{
	return new Truck(*this);
}
