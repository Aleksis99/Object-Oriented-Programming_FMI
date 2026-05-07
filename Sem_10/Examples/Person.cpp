#include "Person.h"

void Person::free()
{
	delete[] name;
	name = nullptr;
}

void Person::copy(const Person& other)
{
	setName(other.name);
	setAge(other.age);
}

void Person::move(Person&& other)
{
	this->name = other.name;
	this->age = other.age;
	other.name = nullptr;
}

void Person::print(std::ostream& os) const
{
	os << name << " " << age;
}

Person::Person(const char* name, unsigned age)
{
	std::cout << "Const Person" << std::endl;
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	std::cout << "Copy Person" << std::endl;
	copy(other);
}

Person& Person::operator=(const Person& other)
{
	std::cout << "op= Person" << std::endl;
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Person::Person(Person&& other)
{
	std::cout << "move Person" << std::endl;
	move(std::move(other));
}

Person& Person::operator=(Person&& other)
{
	std::cout << "move op= Person" << std::endl;
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

Person::~Person()
{
	std::cout << "Dest Person" << std::endl;
	free();
}

void Person::setName(const char* name)
{
	if (name == nullptr || this->name == name)
		return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setAge(unsigned age)
{
	this->age = age;
}

const char* Person::getName() const
{
	return name;
}

unsigned Person::getAge() const
{
	return age;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	person.print(os);
	os << std::endl;

	return os;
}
