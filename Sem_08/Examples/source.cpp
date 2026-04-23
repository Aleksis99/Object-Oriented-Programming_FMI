#include <iostream>
#include <fstream>
#include "Teacher.h"

int main()
{
    char** sub = new char* [1];
    sub[0] = new char[4] {"OOP"};
    const char* name = "Ivan";

    Teacher t1("Ivan", 42, sub, 1);
    Teacher t2 = t1;

    t1 = t2;

    std::cout << t2;
}