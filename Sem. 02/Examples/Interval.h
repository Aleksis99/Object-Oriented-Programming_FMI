#pragma once
#include <iostream>

class Interval
{
private:
	int a = 0;
	int b = 0;

	bool isPalindrome(int n) const;
	bool isPowerOf2(int n) const;

public:

	Interval();
	Interval(int a, int b);
	int lenght() const;
	bool isIn(int num) const;
	int countPalindromes() const;
	bool arePowers2() const;

	int getStart() const;
	int getEnd() const;

	void setStart(int start);
	void setEnd(int end);

	Interval intersection(const Interval& other) const;
	bool isSuperInterval(const Interval& other) const;

};

