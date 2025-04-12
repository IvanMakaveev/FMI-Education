#pragma once
#include "User.h"

class RentableCar
{
public:
	RentableCar();
	RentableCar(unsigned horesPowers, unsigned fuelCapacity);

	unsigned getId() const;
	unsigned getHorsePowers() const;
	unsigned getFuelCapacity() const;
	const User* getRenter() const;

	void setHorsePowers(unsigned horsePowers);
	void setFuelCapacity(unsigned fuelCapacity);

	bool isRented() const;
	void rent(const User* renter);
	unsigned returnToDealer();

	void writeToStream(std::ostream& os) const;
	void readFromStream(std::istream& is);
private:
	static size_t idCounter;

	unsigned id;
	unsigned horsePowers;
	unsigned fuelCapacity;
	User* renter = nullptr;
};

