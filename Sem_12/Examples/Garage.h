#pragma once
#include "MiniBus.h"
#include <vector>
class Garage
{
	std::vector<Vehicle*> vehicles;
	unsigned totalParkingPrice = 0;

	void copy(const Garage& other);
	void free();

public:

	unsigned getTotalParkingPrice() const;
	void addVehicle(const Vehicle * const vehicle);

	Garage() = default;
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();
};

