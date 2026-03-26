#include <iostream>
#include <fstream>

const size_t MAX_SIZE = 1000;

bool copyFile(const char *source, const char *dest)
{
    std::ifstream inputFile(source);
    std::ofstream outputFile(dest);

    if (!inputFile.is_open() || !outputFile.is_open())
        return false;

    while (!inputFile.eof())
    {
        char buff[MAX_SIZE];
        inputFile.getline(buff, MAX_SIZE);
        outputFile << buff << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return true;
}

int main()
{
    copyFile("Task2.cpp", "Task2Copy.cpp");
}
