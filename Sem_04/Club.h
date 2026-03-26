#pragma once
#include "Person.h"
class Club
{
private:
	char* name = nullptr;
	Person* members = nullptr;
	size_t maxMembers;
	size_t size = 0;

	void setMembers(Person* members, size_t size);
	void copy(const Club& other);
	void free();
	void move(Club&& other);

public:

	Club(const char* name, size_t maxMembers);
	Club(const Club& other);
	Club& operator=(const Club& other);
	~Club();

	Club(Club&& other);
	Club& operator=(Club&& other);

	void addMember(const Person& newMember);
	void deleteMember(size_t index);

	void increasemaxMembers(size_t newMaxMembers);

	void setName(const char* name);
	const char* getName() const;

	void printClub() const;


};

