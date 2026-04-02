## Двоични файлове.
"Разбираеми" за компютъра, "неразбираеми" за нас.  

- Отваряне на двоичен файл за **четене**  
```c++
#include <iostream>
#include <fstream>

int main()
{
    // ..
    std::ifstream file("myFile.dat", std::ios::binary);
    // ..
}
```

- Отваряне на двоичен файл за **писане**  
```c++
#include <iostream>
#include <fstream>

int main()
{
    // ..
    std::ofstream file("myFile.dat", std::ios::binary);
    // ..
}
```

- **Записване** на число в двоичен файл  
```c++
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("myFile.dat", std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return -1;
    }

    int num = 1000;
    file.write((const char*)&num, sizeof(num));

    file.close();
}
```
Как изглежда файлът?  

![alt_text](https://i.ibb.co/2nkCysZ/binFile.png)

Как да го прочетем?  

![alt_text](https://i.ibb.co/nnSQz2v/bin-File-Content.png)
Съдържанието на файла (числото 1000) в шестнайсетична бройна система.  
Байтовете се записват в **обратен ред**. Най- старшият байт е последен. Шестнайсетичното представяне на 1000_(10) е **00 00 03 E8_(16)**, което записано наобратно е точно **E8 03 00 00**.  

- **Прочитане** на число от двоичен файл  
```c++
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("myFile.dat", std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return -1;
    }

    int toRead;
    file.read((char*)&toRead, sizeof(num));

    file.close();
}
```

- **Записване** на структура, **която НЕ използва динамична памет**, в двоичен файл  

В текстовите файлове структура се записва като последователно запишем елементите й. В двоичните файлове можем да я запишем "наведнъж".  
```c++
#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 1024;
struct Test
{
    bool b;
    int i;
    char str[MAX_SIZE];
};

int main()
{
    std::ofstream file("myFile.dat", std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return -1;
    }

    Test test{ true, 2022, "Test" };
    file.write((const char*)&test, sizeof(test));

    file.close();
}
```

Как изглежда файлът?  

![alt_text](https://i.ibb.co/jvQGrbL/binFile2.png)

"Разчетен:"  

![alt_text](https://i.ibb.co/m8hRsfY/bin-File2-Content2.png)

- **Записване** на структура, **която използва динамична памет**, в двоичен файл  

## Задачи

**Задача 1:** Да се напише програма, която:  
- записва колекция от студенти в двоичен файл,
- чете колекция от студенти от двоичен файл.  

Всеки студент има **име - низ с произволна дължина**, **години** и **факултетен номер**.  
