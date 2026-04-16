#pragma once
#include <iostream>

class ComplexNumber
{
private:
	double real;
	double im;

public:
	double getReal() const;
	double getIm() const;

	void setReal(double real);
	void setIm(double im);

	ComplexNumber(double real = 0, double im = 0);
	bool operator==(const ComplexNumber &other);
	ComplexNumber &operator+=(const ComplexNumber &other);
	ComplexNumber operator-() const;
	ComplexNumber &operator-=(const ComplexNumber &other);

	friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &cn);
	friend std::istream &operator>>(std::istream &is, ComplexNumber &cn);

	friend ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs);
	friend ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs);
	friend ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs);
};
