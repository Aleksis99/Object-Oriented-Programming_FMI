#pragma once
#include <iostream>

class String
{
private:
	char* str;
	size_t size;

	void copy(const String& other);
	void free();
	void move(String&& other);
	void concat(const String& other);

public:

	String(const char* str = "");
	String(const String& other);
	String& operator=(const String& other);
	~String();

	const char* getStr() const;
	size_t getSize() const;

	char operator[](size_t index) const;
	char& operator[](size_t index);

	String(String&& other);
	String& operator=(String&& other);

	String& operator+=(const String& other);

	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& os, String& str);
	friend String operator+(const String& lhs, const String& rhs);
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator<(const String & lhs, const String & rhs);
	friend bool operator>(const String& lhs, const String& rhs);
	friend bool operator<=(const String& lhs, const String& rhs);
	friend bool operator>=(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);


};

