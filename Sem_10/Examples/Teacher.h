#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	unsigned subjectsCount = 0;
	char** subjects = nullptr;
	void freeSubjects();
	void free();
	void copy(const Teacher& other);
	void move(Teacher&& other);
public:
	void print(std::ostream& os) const;

public:

	Teacher(const char* name, unsigned age, const char* const* subjects, unsigned count);
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other) ;
	Teacher(Teacher&& other);
	Teacher& operator=(Teacher&& other);
	~Teacher();
	unsigned getSubjectsCount() const;
	const char* const* getSubjects() const;
	void setSubjects(const char* const* subjects, unsigned count);

	friend std::ostream& operator<<(std::ostream& os, const Teacher& t);

};

