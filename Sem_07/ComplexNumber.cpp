#include "ComplexNumber.h"

double ComplexNumber::getReal() const
{
	return real;
}

double ComplexNumber::getIm() const
{
	return im;
}

void ComplexNumber::setReal(double real)
{
	this->real = real;
}

void ComplexNumber::setIm(double im)
{
	this->im = im;
}

ComplexNumber::ComplexNumber(double real, double im) : real(real), im(im)
{
}

bool ComplexNumber::operator==(const ComplexNumber &other)
{
	return this->real == other.real && this->im == other.im;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &other)
{
	this->real += other.real;
	this->im += other.im;

	return *this;
}

ComplexNumber ComplexNumber::operator-() const
{
	return ComplexNumber(-real, -im);
}

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &other)
{
	*this += (-other);

	return *this;
}

std::ostream &operator<<(std::ostream &os, const ComplexNumber &cn)
{
	os << "real: " << cn.real << " " << "im: " << cn.im;

	return os;
}

std::istream &operator>>(std::istream &is, ComplexNumber &cn)
{
	is >> cn.real >> cn.im;

	return is;
}

ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs)
{
	ComplexNumber result(lhs.real + rhs.real, lhs.im + rhs.im);

	return result;
}

ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs)
{
	return lhs + (-rhs);
}

ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs)
{
	double real = lhs.real * rhs.real - lhs.im * rhs.im;
	double im = lhs.real * rhs.im + rhs.real * lhs.im;

	return ComplexNumber(real, im);
}
