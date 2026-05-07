#pragma once
#include "Person.h"

class Student : public Person
{
private:
	unsigned examsPassed;

protected:
	void print(std::ostream& os) const;

public:

	Student(const char* name, unsigned age, unsigned examsPassed);

	void setExamsPassed(unsigned examsPassed);
	unsigned getExamsPassed() const;

	friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

