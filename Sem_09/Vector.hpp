#pragma once
#include <iostream>

const size_t INIT_SIZE = 4;

template <class T>
class Vector
{
private:

	T* arr = nullptr;
	size_t size = 0;
	size_t capacity = INIT_SIZE;

	void copy(const Vector& other);
	void move(Vector&& other);
	void free();

public:

	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	Vector(Vector&& other);
	Vector& operator=(Vector&& other);

	const size_t& getSize() const;
	const T& operator[](const size_t& index) const;
	T& operator[](const size_t& index);
	void resize(const size_t& capacity);

	void push_back(const T& el);
	void deleteAt(const size_t& index);
	void insertAt(const T& el, const size_t& index);
	bool removeEl(const T& el);
	void pop_back();
};

template<class T>
void Vector<T>::copy(const Vector& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<class T>
void Vector<T>::move(Vector&& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = other.arr;
	other.arr = nullptr;

}

template<class T>
void Vector<T>::free()
{
	delete[] arr;
}

template<class T>
Vector<T>::Vector()
{
	arr = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector& other)
{
	copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	free();
}

template<class T>
Vector<T>::Vector(Vector&& other)
{
	move(std::move(other));
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

template<class T>
const size_t& Vector<T>::getSize() const
{
	return size;
}

template<class T>
const T& Vector<T>::operator[](const size_t& index) const
{
	if (index >= size)
		throw "Index out of bound";

	return arr[index];
}

template<class T>
T& Vector<T>::operator[](const size_t& index)
{
	if (index >= size)
		throw "Index out of bound";

	return arr[index];
}

template<class T>
void Vector<T>::resize(const size_t& capacity)
{
	if (capacity < size)
		throw "Capacity too small";

	this->capacity = capacity;
	T* newArr = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	arr = newArr;
}

template<class T>
void Vector<T>::push_back(const T& el)
{
	if (size == capacity)
		resize(capacity * 2);

	arr[size] = el;
	size++;
}

template<class T>
void Vector<T>::deleteAt(const size_t& index)
{
	if (index >= size)
		throw "Invalid index";

	for (size_t i = index; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
}

template<class T>
void Vector<T>::insertAt(const T& el, const size_t& index)
{
	if (index > size)
		throw "Invalid index";

	if (size == capacity)
		resize(capacity * 2);

	for (int i = size; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[index] = el;

	size++;
}

template<class T>
bool Vector<T>::removeEl(const T& el)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == el)
		{
			this->deleteAt(i);
			return true;
		}
	}

	return false;
}

template<class T>
void Vector<T>::pop_back()
{
	if (size <= 0)
		throw "Empty arr";

	size--;
}
