#pragma once
#include "Event.h"

Event::Event(const char *name, const Time &begin, const Date &date) : begin(begin), date(date)
{
	setName(name);
}

Event::Event(const char *name, unsigned short hours, unsigned short mins, unsigned short seconds, unsigned short day, unsigned short month, unsigned short year) : begin(hours, mins, seconds), date(day, month, year)
{
	setName(name);
}

void Event::setName(const char *name)
{
	if (strlen(name) > 19)
		strcpy(this->name, "Unknown");
	else
		strcpy(this->name, name);
}

const Time &Event::getTime() const
{
	return begin;
}
const Date &Event::getDate() const
{
	return date;
}

const char *Event::getName() const
{
	return name;
}

int Event::getEventsDayOfWeek() const
{
	return date.getDayOfWeek();
}

void Event::print() const
{
	std::cout << "Event: " << name << ", date: ";
	date.print();
	std::cout << ", time: ";
	begin.print(true);
	std::cout << std::endl;
}