#include <iostream>
#pragma warning (disable : 4996)
#include "Person.h"
#include "Club.h"

void printPerson(const Person& p)
{
	std::cout << p.getName() << " " << p.getAge() << std::endl;
}

Person getPerson()
{
	Person p;

	return p;
}

int main()
{
	Club fmiClub("Fmi FSS", 4);

	Person p1("Ivan", 21);
	Person p2("Petar", 21);
	Person p3("Simo", 47);
	Person p4("Minko", 50);

	for (size_t i = 0; i < 20; i++)
	{
		fmiClub.addMember(p1);
		fmiClub.addMember(p2);
		fmiClub.addMember(p3);
		fmiClub.addMember(p4);
	}

	fmiClub.printClub();
	fmiClub.increasemaxMembers(2);
	fmiClub.increasemaxMembers(6);

	Person p5("Ivan2", 21);
	Person p6("Petar2", 21);
	fmiClub.addMember(p5);
	fmiClub.addMember(p6);

	fmiClub.printClub();
}