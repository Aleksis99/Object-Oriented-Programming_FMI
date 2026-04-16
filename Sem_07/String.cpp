#include "String.h"
#include <cstring>
#pragma warning (disable : 4996)
const size_t MAX_SIZE = 1000;

void String::copy(const String& other)
{
	this->size = other.size;
	this->str = new char[size + 1];
	strcpy(this->str, other.str);
}

void String::free()
{
	delete[] str;
}

void String::move(String&& other)
{
	this->str = other.str;
	this->size = other.size;

	other.str = nullptr;
}

void String::concat(const String& other)
{
	this->size = this->size + other.size;
	char* newStr = new char[this->size + 1];

	strcpy(newStr, this->str);
	strcat(newStr, other.str);
	delete[] this->str;

	this->str = newStr;
}

String::String(const char* str)
{
	this->size = strlen(str);

	this->str = new char[size + 1];
	strcpy(this->str, str);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

String::~String()
{
	free();
}

const char* String::getStr() const
{
	return this->str;
}

size_t String::getSize() const
{
	return size;
}

char String::operator[](size_t index) const
{
	if (index >= size)
		throw "Index out of bound";

	return str[index];
}

char& String::operator[](size_t index)
{
	if (index >= size)
		throw "Index out of bound";

	return str[index];
}

String::String(String&& other)
{
	move(std::move(other));
}

String& String::operator=(String&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

String& String::operator+=(const String& other)
{
	this->concat(other);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buff[MAX_SIZE];

	is >> buff;
	str = buff;

	return is;
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs);
	result.concat(rhs);

	return result;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.str, rhs.str) == 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.str, rhs.str) > 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return  !(lhs < rhs);
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}
