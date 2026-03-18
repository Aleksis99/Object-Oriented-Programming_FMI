#pragma once
#include "Date.h"
#include "Time.h"
class Event
{
	char name[20];
	Time begin;
	Date date;

	void setName(const char *name);

public:
	Event(const char *name, const Time &begin, const Date &date);
	Event(const char *name, unsigned short hours, unsigned short mins, unsigned short seconds, unsigned short day, unsigned short month, unsigned short year);

	const Time &getTime() const;
	const Date &getDate() const;
	const char *getName() const;

	void print() const;

	int getEventsDayOfWeek() const;
};
