#include "Shape.h"

void Shape::copyFrom(const Shape& other)
{
    count = other.count;
    points = new Point[count];

    for (int i = 0; i < count; i++)
    {
        points[i] = other.points[i];
    }
}

void Shape::free()
{
    delete[] points;
}

const Point& Shape::getPointAtIndex(int index) const
{
    if (index < 0 || index >= count)
    {
        throw "Index out of bound";
    }

    return points[index];
}

void Shape::setPointAtIndex(const Point& p, int index)
{
    if (index < 0 || index >= count)
    {
        return;
    }

    points[index] = p;
}

Shape::Shape(int count)
{
    this->count = count;
    points = new Point[count];
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Shape::~Shape()
{
    free();
}
