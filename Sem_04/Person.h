#pragma once

class Person
{

private:
	char* name = nullptr;
	unsigned age = 0;

	void copy(const Person& other);
	void move(Person&& other) noexcept;
	void free();
	
public:

	Person(const char* name = "No name", unsigned age = 0);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	Person(Person&& other) noexcept;
	Person& operator=(Person&& other) noexcept;


	void setAge(unsigned age);
	void setName(const char* name);

	const char* getName() const;
	unsigned getAge() const;

};

