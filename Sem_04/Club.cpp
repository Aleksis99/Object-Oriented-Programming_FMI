#include "Club.h"
#pragma warning (disable : 4996)
#include <cstring>
#include <iostream>

void Club::setMembers(Person* members, size_t size)
{
	delete[] this->members;
	this->size = size;
	this->members = new Person[size];

	for (size_t i = 0; i < size; i++)
	{
		this->members[i] = members[i];
	}
}

void Club::copy(const Club& other)
{
	setName(other.name);
	setMembers(other.members, other.size);
	this->maxMembers = other.maxMembers;

}

void Club::free()
{
	delete[] name;
	delete[] members;
	members = nullptr;
	name = nullptr;
}

void Club::move(Club&& other)
{
	this->name = other.name;
	this->members = other.members;
	this->size = other.size;
	this->maxMembers = other.maxMembers;
	other.name = nullptr;
	other.members = nullptr;
}

Club::Club(const char* name, size_t maxMembers)
{
	if (maxMembers < 1)
		maxMembers = 1;

	setName(name);
	members = new Person[maxMembers];
	this->maxMembers = maxMembers;
}

Club::Club(const Club& other)
{
	copy(other);
}

Club& Club::operator=(const Club& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Club::~Club()
{
	free();
}

Club::Club(Club&& other)
{
	move(std::move(other));
}

Club& Club::operator=(Club&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

void Club::addMember(const Person& newMember)
{
	if (size < maxMembers)
	{
		members[size] = newMember;
		size++;
	}
}

void Club::deleteMember(size_t index)
{
	if (index < size)
	{
		for (size_t i = index; i < size - 1; i++)
		{
			this->members[i] = this->members[i + 1];
		}

		size--;
	}
}

void Club::increasemaxMembers(size_t newMaxMembers)
{
	if (newMaxMembers <= this->maxMembers)
		return;

	Person* newMemebers = new Person[newMaxMembers];

	for (size_t i = 0; i < this->size; i++)
	{
		newMemebers[i] = this->members[i];
	}

	delete[] this->members;
	this->members = newMemebers;
	this->maxMembers = newMaxMembers;
}

void Club::setName(const char* name)
{
	if (name == nullptr || name == this->name)
		return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Club::getName() const
{
	return this->name;
}

void Club::printClub() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << this->members[i].getName()
			<< " " << this->members[i].getAge() << std::endl;
	}
}
