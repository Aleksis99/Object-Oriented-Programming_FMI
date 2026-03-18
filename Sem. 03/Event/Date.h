#pragma once

class Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;

	unsigned short MAX_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	mutable unsigned short dayOfWeek;
	mutable bool isModified = true;

	bool isLeapYear() const;
	void validateDateByChangedCalendars();

public:
	Date(unsigned short day, unsigned short month, unsigned short year);

	unsigned short getDay() const;
	unsigned short getMonth() const;
	unsigned short getYear() const;

	void setDay(unsigned short);
	void setMonth(unsigned short);
	void setYear(unsigned short);

	void print() const;
	void goToNextDay();

	bool areEqual(const Date &other) const;

	int getDayOfWeek() const;
};
