#include "Time.h"

unsigned Time::convertToSeconds() const
{
	return this->seconds + this->minutes * 60 + this->hours * 3600;
}

Time::Time() : seconds(0), minutes(0), hours(0)
{
}

Time::Time(unsigned seconds)
{
	this->seconds = seconds % 60;
	this->minutes = (seconds / 60) % 60;
	this->hours = (seconds / 3600) % 24;
}

void Time::setSeconds(unsigned short seconds)
{
	if (seconds > 59)
		seconds = 0;

	this->seconds = seconds;

}

void Time::setMinutes(unsigned short minutes)
{
	if (minutes > 59)
		minutes = 0;

	this->minutes = minutes;
}

void Time::setHours(unsigned short hours)
{
	if (hours > 23)
		hours = 0;

	this->hours = hours;
}

unsigned short Time::getSeconds() const
{
	return seconds;
}

unsigned short Time::getMinutes() const
{
	return minutes;
}

unsigned short Time::getHours() const
{
	return hours;
}

void Time::addSeconds(unsigned short seconds)
{
	this->seconds += seconds;

	if (this->seconds >= 60)
	{
		unsigned short minutesToAdd = this->seconds / 60;
		this->seconds = this->seconds % 60;
		addMinutes(minutesToAdd);
	}
}

void Time::addMinutes(unsigned short minutes)
{
	this->minutes += minutes;

	if (this->minutes >= 60)
	{
		unsigned short hoursToAdd = this->minutes / 60;
		this->minutes = this->minutes % 60;
		addHours(hoursToAdd);
	}
}

void Time::addHours(unsigned short hours)
{
	this->hours += hours;
	this->hours = this->hours % 24;
}

int Time::compare(const Time& other) const
{
	unsigned thisSeconds = this->convertToSeconds();
	unsigned otherSeconds = other.convertToSeconds();
	
	if (thisSeconds == otherSeconds)
		return 0;
	else if (thisSeconds < otherSeconds)
		return -1;

	return 1;
}

Time Time::timeDiff(const Time& other) const
{
	unsigned currSeconds = this->convertToSeconds();
	unsigned otherSeconds = other.convertToSeconds();
	unsigned diff;

	if (currSeconds > otherSeconds)
	{
		diff = currSeconds - otherSeconds;
	}
	else
	{
		diff = otherSeconds - currSeconds;
	}

	return Time(diff);
}

Time Time::timeToMidnight() const
{
	Time midnight(23, 59, 59);
	Time result = this->timeDiff(midnight);
	result.addSeconds(1);

	return result;
}

bool Time::isDinnerTime() const
{
	Time dinnerStart(20, 30, 00);
	Time dinnerEnd(22, 00, 00);

	return (this->compare(dinnerStart) >= 0 
		&& this->compare(dinnerEnd) <= 0);
}

bool Time::isPartyTime() const
{
	Time partyStart(23, 00, 00);
	Time partyEnd(6, 00, 00);

	return (this->compare(partyStart) >= 0
		|| this->compare(partyEnd) <= 0);
}
