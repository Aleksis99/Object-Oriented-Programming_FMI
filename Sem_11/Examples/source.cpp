#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"


void getPerimeters(const Shape* const* shapes, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout<< shapes[i]->getPerimeter() << std::endl;
	}
}

void getAreas(const Shape* const* shapes, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << shapes[i]->getArea() << std::endl;
	}
}

void deleteColection(Shape** shapes, int count)
{
	for (int i = 0; i < count; i++)
	{
		delete shapes[i];
	}

	delete[] shapes;
}

int main()
{
	Shape** shapes = new Shape * [3];

	shapes[0] = new Rectangle({ 0, 0 }, 5, 5);
	shapes[1] = new Triangle({ 0, 0 }, { 0, 4 }, { 3, 0 });
	shapes[2] = new Triangle({ 0, 0 }, { 0, 10 }, { 10, 0 });

	getAreas(shapes, 3);
	getPerimeters(shapes, 3);
	deleteColection(shapes, 3);
}