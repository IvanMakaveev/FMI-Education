#pragma once
#include "RentableCar.h"

class CarRentalService
{
public:
	CarRentalService(size_t capacity);
	CarRentalService(const CarRentalService& other);
	CarRentalService& operator=(const CarRentalService& other);
	~CarRentalService();

	void addCar(const RentableCar& car);
	void removeCar(unsigned id);
	const RentableCar& findCar(unsigned id) const;
	RentableCar& findCar(unsigned id);
	void returnCar(unsigned id);
	void rentCar(unsigned id, const User* user);

	void writeToStream(std::ostream& os) const;
	void readFromStream(std::istream& is);
private:
	RentableCar* data;
	size_t size;
	size_t capacity;

	unsigned earnings = 0;

	void freeDynamic();
	void copyDynamic(const CarRentalService& other);
};

