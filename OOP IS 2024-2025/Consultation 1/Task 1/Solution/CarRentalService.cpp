#include "CarRentalService.h"
#include <stdexcept>

void CarRentalService::freeDynamic()
{
	delete[] data;
	data = nullptr;
}

void CarRentalService::copyDynamic(const CarRentalService& other)
{
	data = new RentableCar[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}
}

CarRentalService::CarRentalService(size_t capacity) :capacity(capacity), size(0), earnings(0)
{
	data = new RentableCar[capacity];
}

CarRentalService::CarRentalService(const CarRentalService& other) : size(other.size), capacity(other.capacity), earnings(other.earnings)
{
	copyDynamic(other);
}

CarRentalService& CarRentalService::operator=(const CarRentalService& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);

		size = other.size;
		capacity = other.capacity;
		earnings = other.earnings;
	}

	return *this;
}

CarRentalService::~CarRentalService()
{
	freeDynamic();
}

void CarRentalService::addCar(const RentableCar& car)
{
	if (size > capacity)
	{
		throw std::logic_error("Not enough space");
	}

	data[size++] = car;
}

void CarRentalService::removeCar(unsigned id)
{
	int index = -1;
	for (size_t i = 0; i < size; i++)
	{
		if (data[i].getId() == id)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		throw std::invalid_argument("Car not found");
	}

	// In our task it is stated that before removing we return the car
	earnings += data[index].returnToDealer();
	size--;
	std::swap(data[index], data[size]);
}

const RentableCar& CarRentalService::findCar(unsigned id) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i].getId() == id)
		{
			return data[i];
		}
	}

	throw std::invalid_argument("No car found");
}

RentableCar& CarRentalService::findCar(unsigned id)
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i].getId() == id)
		{
			return data[i];
		}
	}

	throw std::invalid_argument("No car found");
}

void CarRentalService::returnCar(unsigned id)
{
	RentableCar& target = findCar(id);
	earnings += target.returnToDealer();
}

void CarRentalService::rentCar(unsigned id, const User* user)
{
	RentableCar& target = findCar(id);
	target.rent(user);
}

void CarRentalService::writeToStream(std::ostream& os) const
{
	os << size << ' ' << capacity << ' ' << earnings << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		data[i].writeToStream(os);
	}
}

void CarRentalService::readFromStream(std::istream& is)
{
	is >> size >> capacity >> earnings;
	for (size_t i = 0; i < size; i++)
	{
		data[i].readFromStream(is);
	}
}
