#include <iostream>
#include "Interval.h"
#pragma warning (disable : 4996)

struct DynamicArray
{
	int* data;
	int used;
	int allocated;

	DynamicArray()
	{
		std::cout << "Def Constructor" << std::endl;

		initialise();
	}

	DynamicArray(size_t size = 0)
	{
		std::cout << "Size Constructor" << std::endl;
		allocate(size);
	}

	~DynamicArray()
	{
		std::cout << "Dest" << std::endl;

		free();
	}

	void initialise()
	{
		this->data = nullptr;
		this->used = 0;
		this->allocated = 0;
	}

	void free()
	{
		delete[] this->data;
		this->data = nullptr;
		this->used = 0;
		this->allocated = 0;
	}

	void allocate(size_t size)
	{
		this->data = new int[size];
		this->used = 0;
		this->allocated = size;
	}

	int& at(size_t index)
	{
		return this->data[index];
	}
};

struct Test
{
	Test()
	{
		std::cout << "Object is created" << std::endl;
	}

	~Test()
	{
		std::cout << "Object is destroyed" << std::endl;
	}
	int a;
	int b;
};

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
	int a;
	A first;
	int obejectsArray;
	B second;

	X() : a(42)
	{ //calls Constructor(default) of A, Constructor(default) of B, Constructor(default) of C" (x3)
		std::cout << a << std::endl;
		std::cout << "Constructor of X" << std::endl;
	}
	~X()
	{
		std::cout << "Destructor of X" << std::endl;
	}

};

class Person
{
private:
	int age = 0;
	char* name = nullptr;

public:

	Person(int age, const char* name)
	{
		setAge(age);
		setName(name);
	}

	void setName(const char* name)
	{
		if (name == nullptr)
			return;

		delete[] this->name;

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setAge(int age)
	{
		if (age >= 0)
		{
			this->age = age;
		}
	}

	const int& getAge() const
	{
		return this->age;
	}

	const char* getName() const
	{
		return this->name;
	}

	~Person()
	{
		delete[] name;
		name = nullptr;
	}

};

void printPerson(const Person& p)
{
	std::cout << p.getAge() << std::endl;
	std::cout << p.getName() << std::endl;
}
int f();

int main()
{
	Person p(5, "Pesho");

	const int& age = p.getAge();

	printPerson(p);
	std::cout << age << std::endl;
	std::cout<< f() << std::endl;

	Interval it1(1, 5);
	Interval it2(3, 7);
	Interval it3 = it1.intersection(it2);

	std::cout << it3.isIn(2) << std::endl;
	std::cout << it3.isIn(5) << std::endl;
	std::cout << it3.isIn(6) << std::endl;

	return 0;
}