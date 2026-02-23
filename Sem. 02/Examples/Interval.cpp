#include "Interval.h"

bool Interval::isPalindrome(int n) const
{
	n = std::abs(n);
	int rev = 0;
	int copyN = n;

	while (copyN > 0)
	{
		rev *= 10;
		rev += copyN % 10;
		copyN /= 10;
	}

	return rev == n;
}

bool Interval::isPowerOf2(int n) const
{
	if (n < 1)
		return false;

	while (n > 1)
	{
		if (n % 2 == 1)
			return false;

		n /= 2;
	}

	return true;
}

Interval::Interval()
{

}

Interval::Interval(int a, int b)
{
	if (a <= b)
	{
		this->a = a;
		this->b = b;
	}
}

int Interval::lenght() const
{
	return b - a;
}

bool Interval::isIn(int num) const
{
	return (a <= num && num <= b);
}

int Interval::countPalindromes() const
{
	int count = 0;

	for (size_t i = a; i <= b; i++)
	{
		if (isPalindrome(i))
			count++;
	}

	return count;
}

bool Interval::arePowers2() const
{
	return isPowerOf2(a) && isPowerOf2(b);
}

int Interval::getStart() const
{
	return a;
}

int Interval::getEnd() const
{
	return b;
}

void Interval::setStart(int start)
{
	if (start <= b)
	{
		a = start;
	}
}

void Interval::setEnd(int end)
{
	if (a <= end)
	{
		b = end;
	}
}

Interval Interval::intersection(const Interval& other) const
{
	int start = std::max(this->a, other.a);
	int end = std::min(this->b, other.b);

	return Interval(start, end);
}

bool Interval::isSuperInterval(const Interval& other) const
{
	return (this->a <= other.a && this->b >= other.b);
}
