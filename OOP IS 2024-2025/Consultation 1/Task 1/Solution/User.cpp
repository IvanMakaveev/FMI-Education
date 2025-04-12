#pragma warning(disable:4996)

#include "User.h"
#include <cstring>
#include <stdexcept>

static bool isAlphanumeric(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

static bool isWhitespace(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\n';
}

void User::freeDynamic()
{
	delete[] username;
	username = nullptr;
}

void User::copyDynamic(const User& other)
{
	username = new char[std::strlen(other.username) + 1];
	std::strcpy(username, other.username);
}

User::User(const User& other) : age(other.age)
{
	strcpy(license, other.license);
	copyDynamic(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		freeDynamic();
		copyDynamic(other);

		strcpy(license, other.license);
		age = other.age;
	}

	return *this;
}

User::User(const char* username, const char* license, unsigned age)
{
	setAge(age);
	setLicense(license);
 	setUsername(username);
}

User::~User()
{
	freeDynamic();
}

void User::setAge(unsigned age)
{
	if (age < 18)
	{
		throw std::invalid_argument("The age should be at least 18");
	}

	this->age = age;
}

void User::writeToStream(std::ostream& os) const
{
	os << std::strlen(username) << ' ' << username << ' '
		<< license << ' ' << age << std::endl;
}

void User::readFromStream(std::istream& is)
{
	size_t size = 0;
	is >> size;
	username = new char[size + 1];
	is >> username;
	is >> license;
	is >> age;
}

void User::setLicense(const char* license)
{
	if (!license || std::strlen(license) > Constants::LICENSE_SIZE)
	{
		throw std::invalid_argument("License number is invalid");
	}

	const char* iter = license;
	while (*iter)
	{
		if (!isAlphanumeric(*iter))
		{
			throw std::invalid_argument("License number is invalid");
		}
		iter++;
	}

	strcpy(this->license, license);
}

void User::setUsername(const char* username)
{
	if (!username)
	{
		throw std::invalid_argument("Username is invalid");
	}

	const char* iter = username;
	while (*iter)
	{
		if (isWhitespace(*iter))
		{
			throw std::invalid_argument("Username cannot be whitespace");
		}
		iter++;
	}

	delete[] this->username;
	size_t size = std::strlen(username);
	this->username = new char[size + 1];
	std::strcpy(this->username, username);
}

const char* User::getUsername() const
{
	return username;
}

const char* User::getLicense() const
{
	return license;
}

unsigned User::getAge() const
{
	return age;
}