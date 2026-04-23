#pragma once
#include <iostream>
#pragma warning (disable : 4996)
#include <cstring>

class Person
{
private:
	char* name = nullptr;
	unsigned age = 0;

	void free();
	void copy(const Person& other);
	void move(Person&& other);

protected:
	void print(std::ostream& os) const;

public:

	Person(const char* name, unsigned age);
	Person(const Person& other);
	Person& operator=(const Person& other) ;
	Person(Person&& other);
	Person& operator=(Person&& other);
	~Person();

	void setName(const char* name);
	void setAge(unsigned age);


	const char* getName() const;
	unsigned getAge() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

