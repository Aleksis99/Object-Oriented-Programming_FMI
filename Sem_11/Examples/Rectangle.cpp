#include "Rectangle.h"

Rectangle::Rectangle(const Point& p, double width, double height) 
	: Shape(1), width(width), height(height)
{
	setPointAtIndex(p, 0);
}

const Point& Rectangle::getBottomLeftPoint() const
{
	return getPointAtIndex(0);
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getHeight() const
{
	return height;
}

double Rectangle::getArea() const
{
	return width * height;
}

double Rectangle::getPerimeter() const
{
	return 2 * (width + height);
}
