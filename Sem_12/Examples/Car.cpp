#include "Car.h"

Car::Car(const std::string& regNum, unsigned passengers, bool polite) :
	Vehicle(regNum), passengers(passengers), polite(polite)
{
}

unsigned Car::getParkingPrice() const
{
	if (polite)
		return 1;

	return rand() % 9 + 2;
}

Vehicle* Car::clone() const
{
	return new Car(*this);
}
