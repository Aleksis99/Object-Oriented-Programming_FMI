#include <iostream>
#include "ComplexNumber.h"
#include <string>
#include "String.h"
#pragma warning (disable : 4996)

void print(const String& str)
{
	for (size_t i = 0; i < str.getSize(); i++)
	{
		std::cout << str[i];
	}
}

int main()
{
	String s1 = "Hello";
	String s2;


	std::cin >> s1 >> s2;


	std::cout << (s1 + " " + s2);
}