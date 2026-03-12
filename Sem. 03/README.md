
# Абстракция. Копиращ конструктор и оператор=

## Абстракция
Пример за **лоша абстракция**:

```c++
struct Triangle
{
	int x1;
	int y1;
	
	int x2;
	int y2;

	int x3;
	int y3;
};

int getPer(const Triangle& t)
{
	return
	 sqrt( (t.x1-t.x2)*(t.x1-t.x2) + (t.y1-t.y2)*(t.y1-t.y2) + 
	 sqrt( (t.x2-t.x3)*(t.x2-t.x3) + (t.y2-t.y3)*(t.y2-t.y3) + 
	 sqrt( (t.x3-t.x1)*(t.x3-t.x1) + (t.y3-t.y1)*(t.y3-t.y1); 
}
 ```
 Пример за **по-добра абстракция**:
 ```c++
struct Point
{
	int x;
	int y
	
	double getDistTo(const Point& other)
	{
		return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
	}
};

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
};

int getPer(const Triangle& t)
{
	return t.p1.getDistTo(t.p2) + t.p2.getDistTo(t.p3) + t.p3.getDistTo(t.p1);
}
 ```

## Копиращ конструктор и оператор =
Заедно с конструктора по подразбиране и деструктора във всеки клас се дефинират и следните член-функции:
 -  Копиращ конструктор - конструктор, който приема обект от същия клас и създава новият обект като негово копие.
 - Оператор= - функция/оператор, който приема  обект от същия клас и променя данните на съществуващ обект от същия клас (обектът от който извикваме функцията.

**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

 ```c++

#include <iostream>

using namespace std;

struct Test
{

    Test()
    {
        cout << "Default constructor" << endl;
    }

    Test(const Test& other)
    {
        cout << "Copy constructor" << endl;
    }

    Test& operator=(const Test& other)
    {
        cout << "operator=" << endl;

        return *this;
    }

    ~Test()
    {
        cout << "Destructor" << endl;
    }
};

void f(Test object)
{
    //do Stuff
}


void g(Test& object)
{
    //do Stuff
}
int main()
{
    Test t; //Default constructor;

    Test t2(t);  // Copy constructor
    Test t3(t2); // Copy constructor	
    t2 = t3; // operator=
    t3 = t; //  operator=

    Test newTest = t; //Copy constructor !!!!!!!

    f(t); // Copy constructor	
    g(t); // nothing. We are passing it as a reference. We are not copying it!

    Test* ptr = new Test();  // Default constructor // we create a new object in the dynamic memory. The destructor must be invoked explicitly  (with delete)

    delete ptr; // Destructor	

} //Destructor Destructor Destructor Destructor

 ```
 
## Задачи

## Задача 1:
Реализирайте клас **Time**, който ще се използва за работа с часове (13:05:45).
Вашият клас трябва да има следния интерфейс:

 - Подразбиращ се контруктор, който създава часа на **00:00:00**.
 - Конструктор, който приема три параметъра - **час, минути и секунди**.
 - Член-функция, която **добавя/изважда** часове.
 - Член-функция, която **добавя/изважда** минути.
 - Член-функция, която **добавя/изважда** секунди.
 - Член-функция, която връща оставащото време до **полунощ**.
 - Член-функция, която връща дали е **време за вечеря**. В рамките на задачата време за вечеря е между **20:30** и **22:00**.
 - Член-функция, която връща дали е **време за парти**. В рамките на задачата време за парти е между **23:00** и **06:00**.
  - Член-функция, която приема друг обект от тип **Time** и връща обект от тип **Time**, което е разликата между двете времена. 
  - Член-функция, която която приема друг обект от тип **Time**  и сравнява двата обекта (по-къснен/по-ранен)

  

 ```c++

int main()
{
     Time t(12,30,45); //12:30:45
     Time t2; //00:00:00

     t.addSeconds(15); //12:31:00
     t.addMinutes(29); // 13:00:00;

     t.isPartyTime(); // false		
     
     Time result = t.timeToMidnight(); // 11:00:00

     t2.compareTo(t); //some value that indicates that t2 < t	
}
 ```
---
## Задача 2
Да се реализира **class Date** за работа с дати.  
Класът трябва да съдържа поне следните методи:

- *Конструктор, който приема три параметъра* - година, месец и ден.

- *Гетъри* и *сетъри* за всички член-данни.  

- Член-функция, която приема друг обект от тип Date и *връща дали двата обекта са равни*.

- Член-функция, която *връща кой ден от седмицата е* (понеделник-неделя).

- Член-функция, която *връща следващата дата*.

- Член-функция за *принтиране на датата*.
 ```c++

int main()
{
	Date date(2023, 3, 14);

	date.print();

	std::cout << date.getDayOfWeek(); // 2
}
```

## Задача 3
Да се реализира **class Event** за работа със събития.  
Класът трябва да съдържа поне следните методи:

- *Конструктор, който приема три параметъра* - име на събитието, дата на провеждане и начален час.

- *Гетъри* за всички член-данни.  

- Член-функция, която *връща през кой ден от седмицата се провежда събитието* (понеделник-неделя).

- Член-функция за *принтиране на събитието*.

 ```c++

int main()
{
    Time time(12, 30, 45);

    Date date(2023, 3, 14);

    Event myEvent("My event", date, time);

    std::cout << myEvent.getDayOfWeek() << std::endl; // 2
    
    myEvent.print();   
}
```
