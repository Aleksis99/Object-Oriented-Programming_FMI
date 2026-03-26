#include <iostream>
#include <fstream>

void replace(std::fstream& file, char toReplace, char replaceWith)
{
    while (!file.eof())
    {
        char ch;
        file.get(ch);

        if (ch == toReplace)
        {
            file.seekp(-1, std::ios::cur);
            file.put(replaceWith);
            file.flush();
        }
    }
}

int main()
{
    std::fstream file("MyFile.txt", std::ios::in | std::ios::out);

    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return -1;
    }

    replace(file, 'e', 'a');

    file.close();
}

