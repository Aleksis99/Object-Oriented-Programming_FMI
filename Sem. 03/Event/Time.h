#pragma once
class Time
{
private:
	unsigned short seconds;
	unsigned short minutes;
	unsigned short hours;

	unsigned convertToSeconds() const;

public:

	Time();
	Time(unsigned seconds);
	Time(unsigned short seconds, unsigned short minutes, unsigned short hours);
	void setSeconds(unsigned short seconds);
	void setMinutes(unsigned short minutes);
	void setHours(unsigned short minutes);

	unsigned short getSeconds() const;
	unsigned short getMinutes() const;
	unsigned short getHours() const;

	void addSeconds(unsigned short seconds);
	void addMinutes(unsigned short minutes);
	void addHours(unsigned short hours);

	int compare(const Time& other) const;
	Time timeDiff(const Time& other) const;
	Time timeToMidnight() const;
	bool isDinnerTime() const;
	bool isPartyTime() const;


};

