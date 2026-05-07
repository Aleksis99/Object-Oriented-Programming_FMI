#include "MiniBus.h"

MiniBus::MiniBus(const std::string& regNum, unsigned loadCapacity, unsigned passengers, bool polite, unsigned numDoors) 
	: Vehicle(regNum), Truck(regNum, loadCapacity), Car(regNum, passengers, polite), numDoors(numDoors)
{
}

unsigned MiniBus::getParkingPrice() const
{
	return (Car::getParkingPrice() + Truck::getParkingPrice()) / 2;
}

Vehicle* MiniBus::clone() const
{
	return new MiniBus(*this);
}
