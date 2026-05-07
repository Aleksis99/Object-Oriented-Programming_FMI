#include "Garage.h"

void Garage::copy(const Garage& other)
{
	totalParkingPrice = other.totalParkingPrice;

	for (size_t i = 0; i < other.vehicles.size(); i++)
	{
		vehicles.push_back(other.vehicles[i]->clone());
	}
}

void Garage::free()
{
	for (size_t i = 0; i < vehicles.size(); i++)
	{
		delete vehicles[i];
	}

	vehicles.clear();
}

unsigned Garage::getTotalParkingPrice() const
{
	return totalParkingPrice;
}

void Garage::addVehicle(const Vehicle * const vehicle)
{
	vehicles.push_back(vehicle->clone());
	totalParkingPrice += vehicle->getParkingPrice();
}

Garage::Garage(const Garage& other)
{
	copy(other);
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Garage::~Garage()
{
	free();
}
