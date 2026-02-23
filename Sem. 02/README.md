# Класове. Член-функции. Модификатори за достъп. Капсулация. Разделна компилация.

```c++
struct DynamicArray
{
	int* data;
	size_t used;
	size_t allocated;
};

void initialise(DynamicArray& da)
{
	da.data = nullptr;
	da.used = 0;
	da.allocated = 0;
}
void free(DynamicArray& da)
{
	delete[] da.data;
	da.data = nullptr;
	da.used = 0;
	da.allocated = 0;
}
void allocate(DynamicArray& da, size_t size)
{
	da.data = new int[size];
	da.used = 0;
	da.allocated = size;
}

int& at(DynamicArray& da, size_t index)
{
	return da.data[index];
}

int main()
{
	DynamicArray da;
	initialise(da);
}
```
Горният програмен фрагмент е напълно валиден.  
Но всички написани функции се отнасят за структурата DynamicArray. Не можем ли да ги "групираме" по някакъв начин?  

## Член-функции

- Функции, които **не съществуват глобално**.
- Имената им са от вида **\<StructName\>::\<memberFunctionName\>**
- **Работят с член-данните на инстанцията/обекта** от дадена структура/клас.
- **Извикват се с инстанция/обект** на структурата/класа.
- Компилаторът преобразува всяка член-функция на дадена структура/клас в обикновена функция с уникално име и един допълнителен параметър –**указател към инстанцията/обекта**.

**Константни член-функции**:

- **Не променят член-данните** на структурата/класа.
- Обозначават се чрез записване на ключовата дума **const**  в декларацията и в края на заглавието в дефиницията им.
- Могат да се извикват от **константни обекти**.

```c++
struct DynamicArray
{
	int* data;
	size_t used;
	size_t allocated;

	void initialise() // inline function
	{
		data = nullptr;
		used = 0;
		allocated = 0;
	}
	void free()
	{
		delete[] data;
		data = nullptr;
		used = 0;
		allocated = 0;
	}
	void allocate(size_t size)
	{
		data = new int[size];
		used = 0;
		allocated = size;
	}

	int& at(size_t index)
	{
		return data[index];
	}
};

int main()
{
	DynamicArray da;
	da.initialise();
	da.allocate(100);
	da.at(5) = 22;
}
```

:bangbang: Инстанция на структурата DynamicArray заема място в паметта колкото за три променливи (data, used, allocated) :bangbang:  
Функциите живеят като глобални (**само на едно място**).  

Всяка член-функция, скрито от нас, получава като аргумент специална променлива (**this**) - **пойнтър към текущия обект, с който функцията работи**.  
Можем да си мислим, че нещата изглеждат така:  
(Долният програмен фрагмент няма да се компилира! Той е за нашата интуиция !!)  
```c++
{
	// ...
	void initialise(DynamicArray* this)
	{
		this->data = nullptr;
		this->used = 0;
		this->allocated = 0;
	}
	// ...
};
	
int main()
{
	DynamicArray da;
	DynamicArray::initialise(&da);
	// ...
}
```

Сега, искаме "външният свят" да **няма достъп до всички член-данни и методи на даден клас**. Това е така, защото тяхната промяна може да доведе до неочаквано поведение на нашата програма. Как можем да го постигнем?  

## Конструктори и деструктор.

**Жизнен цикъл на обект**:
 - Създаване на обект в даден scope – заделя се памет и член-данните се инициализират.
 - Достига се до края на скоупа(област).
 - Обектът и паметта, която е асоциирана с него се разрушава.

**Конструктор**:
 - Извиква се веднъж - при създаването на обекта.
 - Не се оказва експлицитно тип на връщане (връща констатна референция).
 - Има същото име като класа.
 
 **Деструктор**:
 - Извиква се веднъж - при изтриването на обекта.
 - Не се оказва експлицитно тип на връщане.
 - Има същото име като класа със симовла '~' в началото.

 ```c++

#include <iostream>

using namespace std;


struct Test 
{
  Test()
  {
  	cout << "Object is created" <<endl;
  }
  
 ~Test()
  {
  	cout << "Object is destroyed" <<endl;
  }
  int a;
  int b;
};

int main()
{
	while ()
	{
		Test t;// Object is created 
		if ()
		{
			Test t2; // Object is created 

		}// Object is destroyed (t2)

	}//Object is destroyed (t)
}

 ```

 ## Конструктори и деструктор при влагане на обекти.
 
  ```c++
#include <iostream>
#include <iomanip>

using namespace std;

struct A
{
	A()
	{
		std::cout << "Constructor(default) of A" << std::endl;
	}

	~A()
	{
		std::cout << "Destructor of A" << std::endl;
	}
};

struct B
{
	B()
	{
		std::cout << "Constructor(default) of B" << std::endl;
	}

	~B()
	{
		std::cout << "Destructor of B" << std::endl;
	}
};

struct C
{
	C()
	{
		std::cout << "Constructor(default) of C" << std::endl;
	}

	~C()
	{
		std::cout << "Destructor of C" << std::endl;
	}
};

struct X
{
	A first;
	B second;
	C obejectsArray[3];

	X()
	{ //calls Constructor(default) of A, Constructor(default) of B, Constructor(default) of C" (x3)
		std::cout << "Constructor of X" << std::endl;
	}
	~X()
	{
		std::cout << "Destructor of X" << std::endl;
	} //calls Destructor of C" (x3) , Destructor of B, Destructor of A

};

int main()
{
	X  obj; //Constructor of X
} // Destructor of X
```
 ## Капсулация (encapsulation).
Понякога искаме потребителите да **нямат достъп до всички член-данни и методи на даден клас**.
Това е така, защото тяхната промяна може да доведе до **неочаквано поведение** на нашата програма. Принципът за **капсулация** ни помага като позволява да определим кои методи и атрибути може да използват потребителите на нашия клас.

|Модификатор за достъп|Предназначение|  
|--|--|  
|private|Атрибутите, попадащи в обхвата на този модификатор, са вътрешни за съответния клас (не могат да се използват от "външния свят").|  
|protected|Като private + съответните атрибути могат да се използват и от наследниците на класа.|  
|public|Атрибутите, попадащи в обхвата на този модификатор, са видими и за "външния свят").|  

:bangbang: **Разлика между структура и клас**  
По подразбиране всички член данни и методи **на структурата са public-елементи**, а тези **на класа - private-елементи**.  

## Accessors and mutators (getters and setters)
**Get-ъри** - функции, които използваме за **достъп** до "скрити" данни (попадащи в обхвата на модификатора private (protected)).  
**Set-ъри** - функции, които използваме за **промяна** на "скрити" данни. В тях задължително правим валидация на подадените данни (ако такава е необходима)! 

**Пример за get-ъри и set-ъри**

 ```c++

#include <iostream>

using namespace std;


struct Student 
{
private:
	int grade;
	int age;
public:
	Student(int grade, int age)
	{
		setGrade(grade);
		setAge(age);
	}
	int getGrade()
	{
		return grade;
	}
	int getAge()
	{
		return age;
	}
	void setGrade(int grade)
	{
		if(grade >= 2 && grade <= 6)
			this->grade = grade;
	}
	int setAge(int age)
	{
		if(age >= 0)
			this->age = age;
	}
};

int main()
{
	while ()
	{
		Test t;// Object is created 
		if ()
		{
			Test t2; // Object is created 

		}// Object is destroyed (t2)

	}//Object is destroyed (t)
}

 ```
# Разделна компилация

![alt_text](https://i.ibb.co/KsfDr85/h-cpp.png)

![alt_text](https://i.ibb.co/fD6XLJM/Compilation.png)

Какви грешки ще получим, изпълнявайки следните програмни фрагменти?  

1. 
```c++
int main()
{
	f();
	return 0;
}

int f()
{
	return 5;
}
```
**Компилаторът** дава грешка!  

2. 
```c++
int f();

int main()
{
	f();
	return 0;
}
```
**Линкерът** дава грешка!  

---

Всеки .cpp файл се обработва самостоятелно, без "да знае" за съществуването на останалите :bangbang:  

Ако имаме два .cpp файла, единият с код:
```c++
int f()
{
	return 5;
}
```
а другият:
```c++
int main()
{
	f();
	return 0;
}
```
отново ще получим **грешка на компилатора** по причината, спомената по- горе.  

---
Нека отново имаме два .cpp файла (first.cpp, second.cpp), единият с код:
```c++
int f()
{
	return 5;
}
```
а другият:
```c++
int f();

int main()
{
	f();
	return 0;
}
```
Какво ще се случи? Успешна компилация. :heavy_check_mark:

![alt_text](https://i.ibb.co/Gcywtts/Linking.png)

---

![alt_text](https://i.ibb.co/7kxRV1K/Compilation-2.png)

Една програма на С++ може да бъде разбита в множество файлове, които **се компилират независимо един от друг**, т.е. се осъществява **разделна компилация**. В резултат на компилацията се получават няколко **обектни файла** (файлове с разширение **.obj**). Изпълнимият код на програмата (файл с разширение **.ехе**) се получава след свързване (**linking**) на обектните файлове.  

За да се възполваме максимално от разделната компилация, разделяме класовете на **.h** и **.cpp** файлове. Навсякъде, където работим с класа, ще включваме **само .h файла**. По този начин, ако променим реализацията на някоя от функциите на класа, ще се  **прекомпилира само този файл**.  


## Задачи

**Задача 1:**
Реализирайте клас/структура интервал, който представлява интервал  [a,b]  (задължително а <= b) от реалната права. Нашият интервал ще бъде дискретен - началото и краят му ще бъдат цели числа и ще разглеждаме само точки, които са цели числа. Релизирайте следният интерфейс:

 - Подразбиращ се контруктор, който създава интервала **[0,0]**.
 - Конструктор, който приема двата параметъра. Ако a<=b, то създава интервала **[a,b]**. В противен случай, създава **[0,0]**.
 - Член-функция, която връща **дължината на интервала**.
 - Член-функция, която приема число и проверява **дали е част от интервала**.
 - Член-функция, която връща **броя на числата в интервала**, които са палиндорми.
 - Член-функция, която връща дали началото и края на интервала са **степени на 2-ката**. ([2,16] - истина) 
 - Член-функция, която приема интервал и връща **сечението на текущия интервал с подадения**.  (Сечението на [1, 5]  [3, 7]  e [3, 5]).
 - Член-функция, която приема интервал и връща дали подадения (като параметър) интервал е **подинтервал на текущия**(обектът, от който се извиква функцията).

  **Пример за работа с класа:**
 ```c++

int main()
{
     Interval t1(3,10); // [3, 10]
     Interval t2(4,14); // [4, 14]
     Interval t3; // [0, 0]

     Interval result = t1.intersect(t2); // [4, 10]
     
     t2.isSuperInterval(result); //true
     
     result.calcPrimeNumbersInTheInterval() // 2 (only 5 and 7)
}
 ```


