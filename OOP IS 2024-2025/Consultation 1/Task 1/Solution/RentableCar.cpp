#include "RentableCar.h"
#include <stdexcept>

size_t RentableCar::idCounter = 0;

RentableCar::RentableCar() : RentableCar(150, 50)
{

}


RentableCar::RentableCar(unsigned horsePowers, unsigned fuelCapacity)
	:id(idCounter++), horsePowers(horsePowers), fuelCapacity(fuelCapacity)
{
}

unsigned RentableCar::getHorsePowers() const
{
	return horsePowers;
}

unsigned RentableCar::getFuelCapacity() const
{
	return fuelCapacity;
}
const User* RentableCar::getRenter() const
{
	return renter;
}

void RentableCar::setHorsePowers(unsigned horsePowers)
{
	this->horsePowers = horsePowers;
}

void RentableCar::setFuelCapacity(unsigned fuelCapacity)
{
	this->fuelCapacity = fuelCapacity;
}

unsigned RentableCar::getId() const
{
	return id;
}

bool RentableCar::isRented() const
{
	return renter != nullptr;
}

void RentableCar::rent(const User* renter)
{
	if (!renter)
	{
		throw std::invalid_argument("Renter cannot be nullptr");
	}

	if (isRented())
	{
		throw std::logic_error("Cannot rent already rented car");
	}

	this->renter = renter;
}

unsigned RentableCar::returnToDealer()
{
	if (!isRented())
	{
		throw std::logic_error("Cannot return unrented car");
	}

	unsigned result = 10 * horsePowers 
		+ 5 * fuelCapacity 
		+ 2 * renter->getAge();
	renter = nullptr;
	return result;
}

void RentableCar::writeToStream(std::ostream& os) const
{
	os << id << ' ' << horsePowers << ' ' << fuelCapacity << std::endl;
}

void RentableCar::readFromStream(std::istream& is)
{
	is >> id >> horsePowers >> fuelCapacity;
	
	// We are not deserializing the aggregated user 
	// If we did, it would become composition
	// A more complex architecture is required for deserialization of aggregated data
	renter = nullptr;
}
