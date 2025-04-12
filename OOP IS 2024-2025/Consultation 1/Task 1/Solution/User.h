#pragma once
#include <iostream>

namespace Constants
{
	const size_t LICENSE_SIZE = 10;
}

class User
{
public:
	User(const char* username, const char* license, unsigned age);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	const char* getUsername() const;
	const char* getLicense() const;
	unsigned getAge() const;

	void setUsername(const char* name);
	void setLicense(const char* license);
	void setAge(unsigned age);

	void writeToStream(std::ostream& os) const;
	void readFromStream(std::istream& is);
private:
	char* username = nullptr;
	char license[Constants::LICENSE_SIZE + 1];
	unsigned age;

	void freeDynamic();
	void copyDynamic(const User& other);
};

