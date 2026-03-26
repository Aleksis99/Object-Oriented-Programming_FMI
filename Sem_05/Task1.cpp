#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 1024;

int main()
{
    std::ifstream file("Task1.cpp");

    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return -1;
    }

    while (!file.eof())
    {
        char buff[MAX_SIZE];
        file.getline(buff, MAX_SIZE);
        std::cout << buff << std::endl;
    }

    file.close();
}