#include "Student.h"

void Student::print(std::ostream& os) const
{
	Person::print(os);
	os << " " << examsPassed;
}

Student::Student(const char* name, unsigned age, unsigned examsPassed)
	: Person(name, age), examsPassed(examsPassed)
{
}

void Student::setExamsPassed(unsigned examsPassed)
{
	this->examsPassed = examsPassed;
}

unsigned Student::getExamsPassed() const
{
	return examsPassed;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
	student.print(os);

	return os;
}
