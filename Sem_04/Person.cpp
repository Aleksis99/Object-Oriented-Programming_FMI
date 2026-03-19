#include "Person.h"
#pragma warning (disable : 4996)
#include <cstring>
#include <iostream>

void Person::copy(const Person& other)
{
	setName(other.name);
	setAge(other.age);
}

void Person::move(Person&& other) noexcept
{
	this->name = other.name;
	this->age = other.age;
	other.name = nullptr;
}

void Person::free()
{
	delete[] name;
	name = nullptr;
}

Person::Person(const char* name, unsigned age)
{
	//std::cout << "Con" << std::endl;

	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	//std::cout << "Copy" << std::endl;

	copy(other);
}

Person& Person::operator=(const Person& other)
{
	//std::cout << "op=" << std::endl;

	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Person::~Person()
{
	//std::cout << "Dest" << std::endl;

	free();
}

Person& Person::operator=(Person&& other) noexcept
{
	//std::cout << "move op=" << std::endl;

	if (this != &other)
	{
		free();
		this->move(std::move(other));
	}

	return *this;
}

Person::Person(Person&& other) noexcept
{
	//std::cout << "move copy" << std::endl;

	this->move(std::move(other));
}

void Person::setAge(unsigned age)
{
	this->age = age <= 120 ? age : 0;
}

void Person::setName(const char* name)
{
	if (name == nullptr || name == this->name)
		return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Person::getName() const
{
	return this->name;
}

unsigned Person::getAge() const
{
	return this->age;
}
